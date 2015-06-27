// CVLocalDataCommTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CVLocalDataCommTest.h"
#include "CVLocalDataCommTestDlg.h"
#include "C:\CoreView_src\include\CVLocalDateDllComm.h"
#include "C:\CoreView_Src\Include\CVCommonDllCommon.h"

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


// CCVLocalDataCommTestDlg 对话框




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


// CCVLocalDataCommTestDlg 消息处理程序

BOOL CCVLocalDataCommTestDlg::OnInitDialog()
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

	//ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCVLocalDataCommTestDlg::OnPaint()
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
HCURSOR CCVLocalDataCommTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCVLocalDataCommTestDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//OnOK();
	int nACount = 0;
	int nDCount = 0;
	LONG IID = 0;
	char PID[8] = {0};
	LONG ret = 0;

	GetDataCount(nACount, nDCount);

	CString s;
	s.Format("模拟量点：%d, 数字量点：%d", nACount, nDCount);
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
	// TODO: 在此添加控件通知处理程序代码
	long IIDList[800] = {0};
	int IIDCnt = 0;
	long IID = 0;

	//为IID列表赋值
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
	// TODO: 在此添加控件通知处理程序代码
	int Cnt = GetUnusedGroupCnt();
	CString Msg;
	Msg.Format("GetUnusedGroupCnt = %d", Cnt);
	MessageBox(Msg);
}

void CCVLocalDataCommTestDlg::OnBnClickedOk4()
{
	// TODO: 在此添加控件通知处理程序代码
	int Cnt = GetUnusedGroupCnt();

	int* GroupList = new int[Cnt];
	GetUnusedGroupList(GroupList);
	CString Msg;
	Msg.Format("GroupListCnt = %d", Cnt);
	MessageBox(Msg);

}

void CCVLocalDataCommTestDlg::OnBnClickedOk5()
{
	// TODO: 在此添加控件通知处理程序代码
	TREND_GROUP CurGroupInfo;
	for (int i = 0; i < 100; i++)
	{
		GetGroupInfo(i + 1, CurGroupInfo);
	}
}

void CCVLocalDataCommTestDlg::OnBnClickedOk6()
{
	// TODO: 在此添加控件通知处理程序代码
	char* PIDList = new char[PIDLEN * 8];
	memcpy(PIDList, "B5005", PIDLEN);
	memcpy(PIDList + PIDLEN, "B5006", PIDLEN);
	SetPlanCurveGroupData(100, "充电计划曲线", PIDList, 2);
}
