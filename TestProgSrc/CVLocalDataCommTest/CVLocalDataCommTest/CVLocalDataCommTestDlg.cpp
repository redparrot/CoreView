// CVLocalDataCommTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CVLocalDataCommTest.h"
#include "CVLocalDataCommTestDlg.h"
#include "C:\CoreView_src\include\CVLocalDateDllComm.h"
#include "C:\CoreView_Src\Include\CVCommonDllCommon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CCVLocalDataCommTestDlg �Ի���




CCVLocalDataCommTestDlg::CCVLocalDataCommTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCVLocalDataCommTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCVLocalDataCommTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_AList);
	DDX_Control(pDX, IDC_LIST2, m_DList);
}

BEGIN_MESSAGE_MAP(CCVLocalDataCommTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CCVLocalDataCommTestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDOK2, &CCVLocalDataCommTestDlg::OnAddPidToTrend)
	ON_BN_CLICKED(IDOK3, &CCVLocalDataCommTestDlg::OnBnClickedOk3)
	ON_BN_CLICKED(IDOK4, &CCVLocalDataCommTestDlg::OnBnClickedOk4)
	ON_BN_CLICKED(IDOK5, &CCVLocalDataCommTestDlg::OnBnClickedOk5)
	ON_BN_CLICKED(IDOK6, &CCVLocalDataCommTestDlg::OnBnClickedOk6)
END_MESSAGE_MAP()


// CCVLocalDataCommTestDlg ��Ϣ�������

BOOL CCVLocalDataCommTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//ShowWindow(SW_MINIMIZE);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCVLocalDataCommTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCVLocalDataCommTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CCVLocalDataCommTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCVLocalDataCommTestDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//OnOK();
	int nACount = 0;
	int nDCount = 0;
	LONG IID = 0;
	char PID[8] = {0};
	LONG ret = 0;

	GetDataCount(nACount, nDCount);

	CString s;
	s.Format("ģ�����㣺%d, �������㣺%d", nACount, nDCount);
	SetDlgItemText(IDC_STATIC1, s);

	LONG* pADataList = NULL;
	LONG* pDDataList = NULL;
	if (nACount > 0)
	{
		pADataList = new LONG[nACount];
	}
	if (nDCount > 0)
	{
		pDDataList = new LONG[nDCount];
	}
	GetLocalDataList(pADataList, pDDataList);

	m_AList.ResetContent();
	m_DList.ResetContent();
	for (int i = 0; i < nACount; i++)
	{
		IID = *(pADataList + i);
		ret = GetPID(IID, PID);
		if (ret >= 0)
		{
			m_AList.AddString(PID);
		}
	}

	for (int i = 0; i < nDCount; i++)
	{
		IID = *(pDDataList + i);
		ret = GetPID(IID, PID);
		if (ret >= 0)
		{
			m_DList.AddString(PID);
		}
	}

	int a = m_AList.GetCount();
	int b = m_DList.GetCount();

	delete[] pDDataList;
	delete[] pADataList;
}

void CCVLocalDataCommTestDlg::OnAddPidToTrend()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	long IIDList[800] = {0};
	int IIDCnt = 0;
	long IID = 0;

	//ΪIID�б�ֵ
	//GetIID("C0001", IIDList[0]);
	//GetIID("C0002", IIDList[1]);
	//GetIID("C0003", IIDList[2]);
	//GetIID("C0004", IIDList[3]);
	//GetIID("C0005", IIDList[4]);
	//GetIID("C0006", IIDList[5]);
	//GetIID("C0007", IIDList[6]);
	//GetIID("C0008", IIDList[7]);
	//GetIID("C0009", IIDList[8]);
	//GetIID("C0010", IIDList[9]);

	GetIID("A0001", IIDList[0]);
	GetIID("A0002", IIDList[1]);
	GetIID("A0003", IIDList[2]);
	GetIID("A0004", IIDList[3]);
	GetIID("A0005", IIDList[4]);
	GetIID("A0006", IIDList[5]);
	GetIID("A0007", IIDList[6]);
	GetIID("A0008", IIDList[7]);
	GetIID("A0009", IIDList[8]);
	GetIID("A0010", IIDList[9]);
	GetIID("A0011", IIDList[10]);
	GetIID("A0012", IIDList[11]);
	GetIID("A0013", IIDList[12]);
	GetIID("A0014", IIDList[13]);
	GetIID("A0015", IIDList[14]);
	GetIID("A0016", IIDList[15]);

	IIDCnt = 16;

	AddPidToTrend(IIDList, IIDCnt);
}

void CCVLocalDataCommTestDlg::OnBnClickedOk3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int Cnt = GetUnusedGroupCnt();
	CString Msg;
	Msg.Format("GetUnusedGroupCnt = %d", Cnt);
	MessageBox(Msg);
}

void CCVLocalDataCommTestDlg::OnBnClickedOk4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int Cnt = GetUnusedGroupCnt();

	int* GroupList = new int[Cnt];
	GetUnusedGroupList(GroupList);
	CString Msg;
	Msg.Format("GroupListCnt = %d", Cnt);
	MessageBox(Msg);

}

void CCVLocalDataCommTestDlg::OnBnClickedOk5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TREND_GROUP CurGroupInfo;
	for (int i = 0; i < 100; i++)
	{
		GetGroupInfo(i + 1, CurGroupInfo);
	}
}

void CCVLocalDataCommTestDlg::OnBnClickedOk6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char* PIDList = new char[PIDLEN * 8];
	memcpy(PIDList, "B5005", PIDLEN);
	memcpy(PIDList + PIDLEN, "B5006", PIDLEN);
	SetPlanCurveGroupData(100, "���ƻ�����", PIDList, 2);
}
