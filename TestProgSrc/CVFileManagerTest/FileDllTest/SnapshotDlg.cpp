// SnapshotDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FileDllTest.h"
#include "SnapshotDlg.h"
#include "c:\CoreView_src\Include\CVMultiFuncDll.h"

typedef int(*fCVSnapshot)(SysPerformanceInfo*, CVProcessInfo*, int, int);
fCVSnapshot pCVSnapshot;
typedef BOOL(*fOpenSnapshotLog)(char*);
fOpenSnapshotLog pOpenSnapshotLog;
typedef void(*fCloseSnapshotLog)();
fCloseSnapshotLog pCloseSnapshotLog;

//BOOL OpenSnapshotLog(char * LogFileName)

HMODULE hModule;
SysPerformanceInfo sysPerformanceInfo;
const int ListSize = 200;
CVProcessInfo ProcessInfo[ListSize];

// CSnapshotDlg �Ի���

IMPLEMENT_DYNAMIC(CSnapshotDlg, CDialog)

CSnapshotDlg::CSnapshotDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSnapshotDlg::IDD, pParent)
{
	Log = NULL;
}

CSnapshotDlg::~CSnapshotDlg()
{
}

void CSnapshotDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ProcessList);
}


BEGIN_MESSAGE_MAP(CSnapshotDlg, CDialog)
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CSnapshotDlg ��Ϣ�������

void CSnapshotDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nIDEvent == 1)
	{
		TimerOper();
	}

	CDialog::OnTimer(nIDEvent);
}

BOOL CSnapshotDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	hModule = ::LoadLibrary("C:\\CoreView\\SystemExec\\Bin\\CVMultiFuncDll.dll");
	pCVSnapshot = (fCVSnapshot)::GetProcAddress(hModule, "CVSnapshot");
	pOpenSnapshotLog = (fOpenSnapshotLog)::GetProcAddress(hModule, "OpenSnapshotLog");
	pCloseSnapshotLog = (fCloseSnapshotLog)::GetProcAddress(hModule, "CloseSnapshotLog");

	//��ʼ���б�ؼ�
	DWORD dwNewStyle = LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES;
	m_ProcessList.SetExtendedStyle(dwNewStyle);
	m_ProcessList.InsertColumn(0, "No", LVCFMT_LEFT, 30, -1);
	m_ProcessList.InsertColumn(1, "Name", LVCFMT_LEFT, 120, -1);
	m_ProcessList.InsertColumn(2, "PID", LVCFMT_LEFT, 50, -1);
	m_ProcessList.InsertColumn(3, "CPU", LVCFMT_CENTER, 40, -1);
	m_ProcessList.InsertColumn(4, "WorkingSet", LVCFMT_CENTER, 70, -1);
	m_ProcessList.InsertColumn(5, "PrivateBytes", LVCFMT_LEFT, 80, -1);
	m_ProcessList.InsertColumn(6, "Handles", LVCFMT_LEFT, 60, -1);
	m_ProcessList.InsertColumn(7, "GDI", LVCFMT_LEFT, 60, -1);
	m_ProcessList.InsertColumn(8, "Threads", LVCFMT_LEFT, 60, -1);
	m_ProcessList.SetItemCount(ListSize);
	for (int i = 0; i < ListSize; i++)
	{
		m_ProcessList.InsertItem(i, "");
	}

	//����log�ļ�
	CString LogPath = "C:\\CoreView\\Record data\\log\\CVSystemSnapshot\\";
	::SHCreateDirectoryEx(NULL, LogPath, NULL);
	CString LogFile = LogPath + "CVSnapshotTest.csv";
	pOpenSnapshotLog(LogFile.GetBuffer());
	LogFile.ReleaseBuffer();

	//���ڴ���
	TimerOper();
	SetTimer(1, 500, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CSnapshotDlg::TimerOper()
{
	int Cnt = 0;
	Cnt = pCVSnapshot(&sysPerformanceInfo, ProcessInfo, ListSize, Routine);

	//���ý�����ʾ��ϵͳ��Ϣ����
	CString s;
	SetDlgItemInt(IDC_EDIT4, sysPerformanceInfo.HandleCnt);
	SetDlgItemInt(IDC_EDIT5, sysPerformanceInfo.ThreadCnt);
	SetDlgItemInt(IDC_EDIT1, sysPerformanceInfo.ProcessCnt);
	s.Format("%.2f", sysPerformanceInfo.CPUUsage);
	SetDlgItemText(IDC_EDIT2, s);
	s.Format("%.2f", sysPerformanceInfo.PhysicalUsage);
	SetDlgItemText(IDC_EDIT3, s);
	s.Format("%.2f", sysPerformanceInfo.CommitUsage);
	SetDlgItemText(IDC_EDIT6, s);

	//���ý�����ʾ��������Ϣ����
	if (Cnt > 0)
	{
		CVProcessInfo pi;
		for (int i = 0; i < Cnt; i++)
		{
			s.Format("%d", i + 1);
			m_ProcessList.SetItemText(i, 0, s);//No.
			pi = ProcessInfo[i];
			m_ProcessList.SetItemText(i, 1, pi.Name);//name
			s.Format("%d", pi.PID);
			m_ProcessList.SetItemText(i, 2, s);//PID
			s.Format("%.2f", pi.Cpu);
			m_ProcessList.SetItemText(i, 3, s);//CPU
			s.Format("%d", pi.WorkingSetSize);
			m_ProcessList.SetItemText(i, 4, s);//Workset
			s.Format("%d", pi.PagefileUsage);
			m_ProcessList.SetItemText(i, 5, s);//PagefileUsage
			s.Format("%d", pi.HandleCnt);
			m_ProcessList.SetItemText(i, 6, s);//Handles
			s.Format("%d", pi.GdiCnt);
			m_ProcessList.SetItemText(i, 7, s);//GdiCnt
			s.Format("%d", pi.ThreadCnt);
			m_ProcessList.SetItemText(i, 8, s);//ThreadCnt
		}
	}
}

void CSnapshotDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	KillTimer(1);

	pCloseSnapshotLog();

	FreeLibrary(hModule);

	CDialog::OnClose();
}
