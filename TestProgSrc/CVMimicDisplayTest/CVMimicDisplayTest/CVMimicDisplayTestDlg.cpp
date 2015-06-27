// CVMimicDisplayTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CVMimicDisplayTest.h"
#include "CVMimicDisplayTestDlg.h"
#include "Mimic.h"
#include "MimicFile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
BOOL QueWnd = 0;
CString GrNo = "GR000002";

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CCVMimicDisplayTestDlg 对话框




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


// CCVMimicDisplayTestDlg 消息处理程序

BOOL CCVMimicDisplayTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCVMimicDisplayTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR CCVMimicDisplayTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCVMimicDisplayTestDlg::OnBnClickedOk3()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == WM_TIMER + 1)//循环切换系统图
	{
		MimicLoop.LoopDisplay(MimicLoop.NEXT);

		//回显当前图号
		ShowGrName();
	}

	CDialog::OnTimer(nIDEvent);
}

void CCVMimicDisplayTestDlg::OnBnClickedOk4()
{
	// TODO: 在此添加控件通知处理程序代码
	KillTimer(WM_TIMER + 1);
}

//瞬间启动4幅系统图
void CCVMimicDisplayTestDlg::OnBnClickedOk5()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(NULL, "open", "CVMimicDisplay_Im.exe", "gr200400,4,0,0,0,0", "c:\\CoreView\\FuncExec\\exe\\", SW_SHOW);	
	ShellExecute(NULL, "open", "CVMimicDisplay_Im.exe", "gr102102,4,960,0,0,0", "c:\\CoreView\\FuncExec\\exe\\", SW_SHOW);	
	ShellExecute(NULL, "open", "CVMimicDisplay_Im.exe", "gr102114,4,0,540,0,0", "c:\\CoreView\\FuncExec\\exe\\", SW_SHOW);	
	ShellExecute(NULL, "open", "CVMimicDisplay_Im.exe", "gr102116,4,960,540,0,0", "c:\\CoreView\\FuncExec\\exe\\", SW_SHOW);	
}

void CCVMimicDisplayTestDlg::OnBnClickedOk7()
{
	// TODO: 在此添加控件通知处理程序代码
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
	////给管理程序发消息，试图关闭本系统图
	CString GrName;
	GetDlgItemText(IDC_EDIT5, GrName);
	GrName = "GR" + GrName;

	CMimic Mimic;
	Mimic.Close(GrName);
}

void CCVMimicDisplayTestDlg::OnBnClickedNext()
{
	// TODO: 在此添加控件通知处理程序代码
	GetGrNoRange();

	MimicLoop.LoopDisplay(MimicLoop.NEXT);

	//回显当前图号
	ShowGrName();
}

void CCVMimicDisplayTestDlg::OnBnClickedPrev()
{
	// TODO: 在此添加控件通知处理程序代码
	GetGrNoRange();

	MimicLoop.LoopDisplay(MimicLoop.PREV);

	//回显当前图号
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
	// TODO: 在此添加控件通知处理程序代码
	CMimicFile MimicFile;
	MimicFile.GetMimicList(TotalFileList);
}
