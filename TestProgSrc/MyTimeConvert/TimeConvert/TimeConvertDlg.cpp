// TimeConvertDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TimeConvert.h"
#include "TimeConvertDlg.h"

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


// CTimeConvertDlg 对话框




CTimeConvertDlg::CTimeConvertDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimeConvertDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTimeConvertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTimeConvertDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK2, &CTimeConvertDlg::OnBnClickedOk2)
	ON_BN_CLICKED(IDOK3, &CTimeConvertDlg::OnBnClickedOk3)
	ON_BN_CLICKED(IDOK4, &CTimeConvertDlg::OnBnClickedOk4)
END_MESSAGE_MAP()


// CTimeConvertDlg 消息处理程序

BOOL CTimeConvertDlg::OnInitDialog()
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

void CTimeConvertDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTimeConvertDlg::OnPaint()
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
HCURSOR CTimeConvertDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTimeConvertDlg::OnBnClickedOk2()
{
	// TODO: 在此添加控件通知处理程序代码
	time_t timer;
	CString s;

	time(&timer);

	s.Format("%d", timer);

	SetDlgItemText(IDC_EDIT1, s);
}

void CTimeConvertDlg::OnBnClickedOk3()
{
	// TODO: 在此添加控件通知处理程序代码
	time_t timer = (time_t)GetDlgItemInt(IDC_EDIT2);

	struct tm LocalTime;
	CString s;

	localtime_s(&LocalTime, &timer);

	s.Format("%d/%02d/%02d %02d:%02d:%02d", LocalTime.tm_year + 1900, LocalTime.tm_mon + 1, LocalTime.tm_mday,
		LocalTime.tm_hour, LocalTime.tm_min, LocalTime.tm_sec);

	SetDlgItemText(IDC_EDIT3, s);
}

void CTimeConvertDlg::OnBnClickedOk4()
{
	// TODO: 在此添加控件通知处理程序代码
	struct tm LocalTime;

	LocalTime.tm_year = GetDlgItemInt(IDC_EDIT4) - 1900;
	LocalTime.tm_mon = GetDlgItemInt(IDC_EDIT6) - 1;
	LocalTime.tm_mday = GetDlgItemInt(IDC_EDIT7);
	LocalTime.tm_hour = GetDlgItemInt(IDC_EDIT8);
	LocalTime.tm_min = GetDlgItemInt(IDC_EDIT9);
	LocalTime.tm_sec = GetDlgItemInt(IDC_EDIT10);

	time_t time = mktime(&LocalTime);

	CString s;
	s.Format("%d", time);
	SetDlgItemText(IDC_EDIT5, s);
}
