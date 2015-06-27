// CVCV7ToCV8UpdateTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CVCV7ToCV8UpdateTest.h"
#include "CVCV7ToCV8UpdateTestDlg.h"
#include "c:\CoreView_src\Include\CVCV7ToCV8UpdateDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

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


// CCVCV7ToCV8UpdateTestDlg 对话框

CCVCV7ToCV8UpdateTestDlg::CCVCV7ToCV8UpdateTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCVCV7ToCV8UpdateTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCVCV7ToCV8UpdateTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_ProgressCtrl);
}

BEGIN_MESSAGE_MAP(CCVCV7ToCV8UpdateTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CCVCV7ToCV8UpdateTestDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CCVCV7ToCV8UpdateTestDlg 消息处理程序

BOOL CCVCV7ToCV8UpdateTestDlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCVCV7ToCV8UpdateTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCVCV7ToCV8UpdateTestDlg::OnPaint()
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
HCURSOR CCVCV7ToCV8UpdateTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCVCV7ToCV8UpdateTestDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CStatic ctlPrompt;
	int nRet = 0;
	nRet = UserConfigureUpdate(
		"D:\\现场系统备份--勿删\\嘉兴\\CV7\\POC1\\",	//CV7十个路径所在路径或者CV7组态备份所在路径
		2,		//CV7数据路径的类型：1-表示csCV7DataPath指定的十个路径所在路径；2：表示csCV7DataPath指定的是CV7组态备份所在的路径
		"",		//CV7历史数据所在路径
		"D:\\现场系统备份--勿删\\嘉兴\\CV7\\POC1\\CV7PID_IID.dat",		//CV7IID-PID索引文件所在路径
		2,		//2报表升级;4PLC升级;3趋势升级;1事件触发升级
		"c:\\CoreView\\Record data\\log\\CV7ToCV8.txt",		//log文件名称。要求各个DLL用追加的方式打开文件
		ctlPrompt,
		m_ProgressCtrl);
}
