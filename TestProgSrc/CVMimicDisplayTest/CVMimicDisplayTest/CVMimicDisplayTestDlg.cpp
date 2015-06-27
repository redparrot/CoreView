// CVMimicDisplayTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CVMimicDisplayTest.h"
#include "CVMimicDisplayTestDlg.h"
#include "Mimic.h"
#include "MimicFile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
BOOL QueWnd = 0;
CString GrNo = "GR000002";

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


// CCVMimicDisplayTestDlg �Ի���




CCVMimicDisplayTestDlg::CCVMimicDisplayTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCVMimicDisplayTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCVMimicDisplayTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCVMimicDisplayTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK3, &CCVMimicDisplayTestDlg::OnBnClickedOk3)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDOK4, &CCVMimicDisplayTestDlg::OnBnClickedOk4)
	ON_BN_CLICKED(IDOK7, &CCVMimicDisplayTestDlg::OnBnClickedOk7)
	ON_BN_CLICKED(IDOK8, &CCVMimicDisplayTestDlg::OnBnClickedOk8)
	ON_BN_CLICKED(IDC_NEXT, &CCVMimicDisplayTestDlg::OnBnClickedNext)
	ON_BN_CLICKED(IDC_PREV, &CCVMimicDisplayTestDlg::OnBnClickedPrev)
	ON_BN_CLICKED(IDC_BUTTON1, &CCVMimicDisplayTestDlg::OnFileListRefresh)
END_MESSAGE_MAP()


// CCVMimicDisplayTestDlg ��Ϣ�������

BOOL CCVMimicDisplayTestDlg::OnInitDialog()
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

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	char buf[100] = {0};
	IniFileName = theApp.GetExePath() + "CVMimicDisplayTest.ini";
	GetPrivateProfileString("CVMimicDisplayTest", "GrName", NULL, buf, sizeof(buf), IniFileName);
	CString GrName = buf;
	if (GrName.IsEmpty() == FALSE)
	{
		CMimic Mimic;
		CString GrNum = Mimic.GetGrNum(GrName);
		SetDlgItemText(IDC_EDIT5, GrNum);
	}

	GetPrivateProfileString("CVMimicDisplayTest", "Interval", NULL, buf, sizeof(buf), IniFileName);
	SetDlgItemText(IDC_EDIT2, buf);

	GetPrivateProfileString("CVMimicDisplayTest", "BeginGrName", NULL, buf, sizeof(buf), IniFileName);
	GrName = buf;
	if (GrName.IsEmpty() == FALSE)
	{
		CMimic Mimic;
		CString GrNum = Mimic.GetGrNum(GrName);
		SetDlgItemText(IDC_EDIT6, GrNum);
	}

	GetPrivateProfileString("CVMimicDisplayTest", "EndGrName", NULL, buf, sizeof(buf), IniFileName);
	GrName = buf;
	if (GrName.IsEmpty() == FALSE)
	{
		CMimic Mimic;
		CString GrNum = Mimic.GetGrNum(GrName);
		SetDlgItemText(IDC_EDIT7, GrNum);
	}

	OnFileListRefresh();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCVMimicDisplayTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCVMimicDisplayTestDlg::OnPaint()
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
HCURSOR CCVMimicDisplayTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCVMimicDisplayTestDlg::OnBnClickedOk3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int Cyc = GetDlgItemInt(IDC_EDIT2);
	if (Cyc < 1000)
	{
		Cyc = 1000;
		SetDlgItemInt(IDC_EDIT2, Cyc);
	}
	CString CycStr;
	CycStr.Format("%d", Cyc);
	WritePrivateProfileString("CVMimicDisplayTest", "Interval", CycStr, IniFileName);

	GetGrNoRange();

	SetTimer(WM_TIMER + 1, Cyc, NULL);
}

void CCVMimicDisplayTestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nIDEvent == WM_TIMER + 1)//ѭ���л�ϵͳͼ
	{
		MimicLoop.LoopDisplay(MimicLoop.NEXT);

		//���Ե�ǰͼ��
		ShowGrName();
	}

	CDialog::OnTimer(nIDEvent);
}

void CCVMimicDisplayTestDlg::OnBnClickedOk4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	KillTimer(WM_TIMER + 1);
}

//˲������4��ϵͳͼ
void CCVMimicDisplayTestDlg::OnBnClickedOk5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(NULL, "open", "CVMimicDisplay_Im.exe", "gr200400,4,0,0,0,0", "c:\\CoreView\\FuncExec\\exe\\", SW_SHOW);	
	ShellExecute(NULL, "open", "CVMimicDisplay_Im.exe", "gr102102,4,960,0,0,0", "c:\\CoreView\\FuncExec\\exe\\", SW_SHOW);	
	ShellExecute(NULL, "open", "CVMimicDisplay_Im.exe", "gr102114,4,0,540,0,0", "c:\\CoreView\\FuncExec\\exe\\", SW_SHOW);	
	ShellExecute(NULL, "open", "CVMimicDisplay_Im.exe", "gr102116,4,960,540,0,0", "c:\\CoreView\\FuncExec\\exe\\", SW_SHOW);	
}

void CCVMimicDisplayTestDlg::OnBnClickedOk7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString OpenGrno;
	GetDlgItemText(IDC_EDIT5, OpenGrno);
	CString GrName;
	CString CmdLine;
	GrName.Format("GR%s", OpenGrno);
	CMimic Mimic;
	Mimic.Start(GrName);

	WritePrivateProfileString("CVMimicDisplayTest", "GrName", GrName, IniFileName);
}

void CCVMimicDisplayTestDlg::OnBnClickedOk8()
{
	////�����������Ϣ����ͼ�رձ�ϵͳͼ
	CString GrName;
	GetDlgItemText(IDC_EDIT5, GrName);
	GrName = "GR" + GrName;

	CMimic Mimic;
	Mimic.Close(GrName);
}

void CCVMimicDisplayTestDlg::OnBnClickedNext()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetGrNoRange();

	MimicLoop.LoopDisplay(MimicLoop.NEXT);

	//���Ե�ǰͼ��
	ShowGrName();
}

void CCVMimicDisplayTestDlg::OnBnClickedPrev()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetGrNoRange();

	MimicLoop.LoopDisplay(MimicLoop.PREV);

	//���Ե�ǰͼ��
	ShowGrName();
}

void CCVMimicDisplayTestDlg::GetGrNoRange()
{
	CString GrName;
	GetDlgItemText(IDC_EDIT6, GrName);
	MimicLoop.SetBeginGrNo(atoi(GrName));
	GrName = "GR" + GrName;
	WritePrivateProfileString("CVMimicDisplayTest", "BeginGrName", GrName, IniFileName);
	GetDlgItemText(IDC_EDIT7, GrName);
	MimicLoop.SetEndGrNo(atoi(GrName));
	GrName = "GR" + GrName;
	WritePrivateProfileString("CVMimicDisplayTest", "EndGrName", GrName, IniFileName);

	MimicLoop.GetFileList(TotalFileList);
}

void CCVMimicDisplayTestDlg::ShowGrName()
{
	CString GrName = MimicLoop.GetShowGrName();
	CMimic Mimic;
	SetDlgItemText(IDC_STATIC_CUR, GrName);
}

void CCVMimicDisplayTestDlg::OnFileListRefresh()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMimicFile MimicFile;
	MimicFile.GetMimicList(TotalFileList);
}
