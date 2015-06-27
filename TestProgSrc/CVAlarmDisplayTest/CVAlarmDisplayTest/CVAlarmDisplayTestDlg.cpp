// CVAlarmDisplayTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CVAlarmDisplayTest.h"
#include "CVAlarmDisplayTestDlg.h"
#include "C:\CoreView_Src\Include\CVCommonDllCommon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
#define WM_ALARM_CHANGE		WM_USER + 5000
#define ALARM_AFFIRM			0x01
#define ALARM_RESTORATION		0x02

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


// CCVAlarmDisplayTestDlg 对话框




CCVAlarmDisplayTestDlg::CCVAlarmDisplayTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCVAlarmDisplayTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAlarmMap = NULL;
	m_hAlarmMap = NULL;
}

void CCVAlarmDisplayTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCVAlarmDisplayTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK2, &CCVAlarmDisplayTestDlg::OnBnClickedOk2)
	ON_BN_CLICKED(IDOK, &CCVAlarmDisplayTestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CCVAlarmDisplayTestDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK3, &CCVAlarmDisplayTestDlg::OnBnClickedOk3)
	ON_BN_CLICKED(IDOK4, &CCVAlarmDisplayTestDlg::OnBnClickedOk4)
	ON_BN_CLICKED(IDOK5, &CCVAlarmDisplayTestDlg::OnBnClickedOk5)
	ON_BN_CLICKED(IDOK6, &CCVAlarmDisplayTestDlg::OnBnClickedOk6)
	ON_BN_CLICKED(IDOK7, &CCVAlarmDisplayTestDlg::OnBnClickedOk7)
	ON_BN_CLICKED(IDOK8, &CCVAlarmDisplayTestDlg::OnBnClickedOk8)
	ON_BN_CLICKED(IDOK10, &CCVAlarmDisplayTestDlg::OnBnClickedOk10)
	ON_BN_CLICKED(IDOK9, &CCVAlarmDisplayTestDlg::OnBnClickedOk9)
	ON_BN_CLICKED(IDOK17, &CCVAlarmDisplayTestDlg::OnBnClickedOk17)
	ON_BN_CLICKED(IDOK18, &CCVAlarmDisplayTestDlg::OnBnClickedOk18)
	ON_BN_CLICKED(IDOK11, &CCVAlarmDisplayTestDlg::OnBnClickedOk11)
	ON_BN_CLICKED(IDOK12, &CCVAlarmDisplayTestDlg::OnBnClickedOk12)
	ON_BN_CLICKED(IDOK13, &CCVAlarmDisplayTestDlg::OnBnClickedOk13)
	ON_BN_CLICKED(IDOK14, &CCVAlarmDisplayTestDlg::OnBnClickedOk14)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDOK15, &CCVAlarmDisplayTestDlg::OnBnClickedOk15)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDOK19, &CCVAlarmDisplayTestDlg::OnBnClickedOk19)
	ON_BN_CLICKED(IDOK20, &CCVAlarmDisplayTestDlg::OnBnClickedOk20)
	ON_BN_CLICKED(IDOK21, &CCVAlarmDisplayTestDlg::OnBnClickedOk21)
	ON_BN_CLICKED(IDOK22, &CCVAlarmDisplayTestDlg::OnBnClickedOk22)
	ON_BN_CLICKED(IDOK23, &CCVAlarmDisplayTestDlg::OnBnClickedOk23)
	ON_BN_CLICKED(IDOK24, &CCVAlarmDisplayTestDlg::OnBnClickedOk24)
	ON_BN_CLICKED(IDOK25, &CCVAlarmDisplayTestDlg::OnBnClickedOk25)
	ON_BN_CLICKED(IDOK26, &CCVAlarmDisplayTestDlg::OnBnClickedOk26)
	ON_BN_CLICKED(IDOK27, &CCVAlarmDisplayTestDlg::OnBnClickedOk27)
	ON_BN_CLICKED(IDOK30, &CCVAlarmDisplayTestDlg::OnBnClickedOk30)
	ON_BN_CLICKED(IDOK28, &CCVAlarmDisplayTestDlg::OnBnClickedOk28)
	ON_BN_CLICKED(IDOK29, &CCVAlarmDisplayTestDlg::OnBnClickedOk29)
END_MESSAGE_MAP()


// CCVAlarmDisplayTestDlg 消息处理程序

BOOL CCVAlarmDisplayTestDlg::OnInitDialog()
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
	OnBnClickedOk2();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCVAlarmDisplayTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCVAlarmDisplayTestDlg::OnPaint()
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
HCURSOR CCVAlarmDisplayTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCVAlarmDisplayTestDlg::OnBnClickedOk2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_hAlarmMap = CreateFileMapping(INVALID_HANDLE_VALUE,
		NULL,PAGE_READWRITE|SEC_COMMIT,
		0,
		sizeof(SAlarmShareMem) * AlarmMax,
		MemName);

	if (m_hAlarmMap != NULL)
	{
		m_pAlarmMap = (SAlarmShareMem*)MapViewOfFile(m_hAlarmMap, FILE_MAP_WRITE, 0, 0, 0);
		if (m_pAlarmMap == NULL)
		{
			CloseHandle(m_hAlarmMap);
			m_hAlarmMap = NULL;
		}
		else
		{
			memset(m_pAlarmMap, -1, sizeof(SAlarmShareMem) * AlarmMax);
		}
	}
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk()//L3报警
{
	// TODO: 在此添加控件通知处理程序代码
	//OnOK();
	time_t osBinaryTime = 0;
	LONG bRet = 0;
	AnalogAlmDef_T AnalogAlmDef;
	
	LONG IID = 0;
	GetIID("C0008", IID);

	bRet = GetAnalogAlmDef(IID, &AnalogAlmDef);

	for (int i = 0; i < AlarmMax + 1; i++)//L3
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = 1;
		m_AlarmInfo.state = L3ALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));

		if (i == AlarmMax)
		{
			m_AlarmInfo.time = -1;
			memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
		}
	}
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk4()//L2报警
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG IID = 0;
	GetIID("C0008", IID);

	for (int i = 0; i < AlarmMax + 1; i++)//L2
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = (float)-0.1;
		m_AlarmInfo.state = L2ALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));

		if (i == AlarmMax)
		{
			m_AlarmInfo.time = -1;
			memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
		}
	}
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk5()//L1报警
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG IID = 0;
	GetIID("C0008", IID);

	for (int i = 0; i < AlarmMax + 1; i++)//L2
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = 3;
		m_AlarmInfo.state = L1ALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));

		if (i == AlarmMax)
		{
			m_AlarmInfo.time = -1;
			memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
		}
	}
}

void CCVAlarmDisplayTestDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	UnmapViewOfFile(m_pAlarmMap);

	CloseHandle(m_hAlarmMap);

	OnCancel();
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk3()
{
	// TODO: 在此添加控件通知处理程序代码
	HWND hWnd;

	hWnd = ::FindWindow(NULL, "报警显示");
	::PostMessage(hWnd, WM_ALARM_CHANGE, 0, 0);

}

void CCVAlarmDisplayTestDlg::OnBnClickedOk7()//H3报警
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG IID = 0;
	GetIID("C0002", IID);


	for (int i = 0; i < AlarmMax + 1; i++)
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = 100;
		m_AlarmInfo.state = H3ALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));

		if (i == AlarmMax)
		{
			m_AlarmInfo.time = -1;
			memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
		}
	}
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk8()//H2报警
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG IID = 0;
	GetIID("C0002", IID);

	for (int i = 0; i < AlarmMax + 1; i++)
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = 100;
		m_AlarmInfo.state = H2ALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));

		if (i == AlarmMax)
		{
			m_AlarmInfo.time = -1;
			memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
		}
	}
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk10()//H1报警
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG IID = 0;
	GetIID("C0002", IID);


	for (int i = 0; i < AlarmMax + 1; i++)
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = 100;
		m_AlarmInfo.state = H1ALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));

		if (i == AlarmMax)
		{
			m_AlarmInfo.time = -1;
			memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
		}
	}
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk6()//报警恢复
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < AlarmMax; i++)
	{
		memcpy(&m_AlarmInfo, m_pAlarmMap + i, sizeof(SAlarmShareMem));
		m_AlarmInfo.CurAlmChgFlg |= 0x02;
		m_AlarmInfo.value = 50;
		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
	}

	OnBnClickedOk3();
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk9()//报警确认
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < AlarmMax; i++)
	{
		memcpy(&m_AlarmInfo, m_pAlarmMap + i, sizeof(SAlarmShareMem));
		m_AlarmInfo.CurAlmChgFlg |= 0x01;
		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
	}

	OnBnClickedOk3();
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk17()//模拟量突变报警
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG IID = 0;
	GetIID("C0008", IID);

	for (int i = 0; i < AlarmMax + 1; i++)
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = 100;
		m_AlarmInfo.state = DEVIATIONALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;
		m_AlarmInfo.Limit = 200;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));

		if (i == AlarmMax)
		{
			m_AlarmInfo.time = -1;
			memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
		}
	}
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk18()
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG IID = 0;
	GetIID("A0010", IID);

	for (int i = 0; i < AlarmMax + 1; i++)
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = 100;
		m_AlarmInfo.state = BADALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));

		if (i == AlarmMax)
		{
			m_AlarmInfo.time = -1;
			memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
		}
	}
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk11()//0->1报警
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	char PID[8] = {0};
	LONG Ret = 0;
	LONG IID = 0;
	Ret = GetIID("Z0001", IID);
	//Ret = GetPID(IID, PID);

	for (int i = 0; i < AlarmMax + 1; i++)
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = 1;
		m_AlarmInfo.state = AESCENDALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));

		if (i == AlarmMax)
		{
			m_AlarmInfo.time = -1;
			memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
		}
	}
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk12()//1->0报警
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG IID = 0;
	GetIID("Z0001", IID);

	for (int i = 0; i < AlarmMax + 1; i++)
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = 0;
		m_AlarmInfo.state = DESCENDALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));

		if (i == AlarmMax)
		{
			m_AlarmInfo.time = -1;
			memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
		}
	}
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk13()//数字量双向报警
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG IID = 0;
	GetIID("B0001", IID);

	for (int i = 0; i < AlarmMax + 1; i++)
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = 0;
		m_AlarmInfo.state = DOUBLEALARRM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));

		if (i == AlarmMax)
		{
			m_AlarmInfo.time = -1;
			memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
		}
	}
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk14()//数字量坏点报警
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG IID = 0;
	GetIID("B0001", IID);

	for (int i = 0; i < AlarmMax + 1; i++)
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = 0;
		m_AlarmInfo.state = BADALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));

		if (i == AlarmMax)
		{
			m_AlarmInfo.time = -1;
			memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
		}
	}
}

void CCVAlarmDisplayTestDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//UnmapViewOfFile(m_pAlarmMap);

	//CloseHandle(m_hAlarmMap);

	CDialog::OnClose();
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk15()
{
	// TODO: 在此添加控件通知处理程序代码

	SetTimer(1, 1000, NULL);
}

void CCVAlarmDisplayTestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	time_t osBinaryTime = 0;
	LONG bRet = 0;
	static LONG IID = 0;
	static int i = 0;
	static int First = 0;
	HWND hWnd;

	if (First == 0)
	{
		GetIID("A0002", IID);
		First = 1;
	}

	CTime t(2006, 2, 11, 23, 10, 1); 
	osBinaryTime = (time_t)t.GetTime(); 
	m_AlarmInfo.time = osBinaryTime;
	m_AlarmInfo.IID = IID++;
	m_AlarmInfo.value = 1;
	m_AlarmInfo.state = L3ALARM;
	m_AlarmInfo.CurAlmChgFlg = 0;
	m_AlarmInfo.EscTime = 0;

	if (i == AlarmMax - 1)
	{
		KillTimer(1);

		return;
	}

	memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));

	i++;

	hWnd = ::FindWindow(NULL, "报警显示");
	::PostMessage(hWnd, WM_ALARM_CHANGE, 0, 0);

	CDialog::OnTimer(nIDEvent);
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk19()
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG bRet = 0;
	int Index = 0;
	int Count = 2;

	LONG IID = 0;
	GetIID("A0001", IID);

	for (int i = 0; i < Count; i++)//L3
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = 1;
		m_AlarmInfo.state = L3ALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + Index, &m_AlarmInfo, sizeof(SAlarmShareMem));
		Index++;
	}

	for (int i = 0; i < Count; i++)//L3
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID + 1;
		m_AlarmInfo.value = 1;
		m_AlarmInfo.state = L2ALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + Index, &m_AlarmInfo, sizeof(SAlarmShareMem));
		Index++;
	}

	for (int i = 0; i < Count; i++)//L3
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID + 2;
		m_AlarmInfo.value = 1;
		m_AlarmInfo.state = L1ALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + Index, &m_AlarmInfo, sizeof(SAlarmShareMem));
		Index++;
	}

	for (int i = 0; i < Count; i++)//H3
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID + 3;
		m_AlarmInfo.value = 1;
		m_AlarmInfo.state = H3ALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + Index, &m_AlarmInfo, sizeof(SAlarmShareMem));
		Index++;
	}

	for (int i = 0; i < Count; i++)//H2
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID + 4;
		m_AlarmInfo.value = 1;
		m_AlarmInfo.state = H2ALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + Index, &m_AlarmInfo, sizeof(SAlarmShareMem));
		Index++;
	}

	for (int i = 0; i < Count; i++)//H1
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID + 5;
		m_AlarmInfo.value = 1;
		m_AlarmInfo.state = H1ALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + Index, &m_AlarmInfo, sizeof(SAlarmShareMem));
		Index++;
	}

	for (int i = 0; i < Count; i++)//突变
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID + 6;
		m_AlarmInfo.value = 1;
		m_AlarmInfo.state = DEVIATIONALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + Index, &m_AlarmInfo, sizeof(SAlarmShareMem));
		Index++;
	}

	for (int i = 0; i < Count; i++)//坏点
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID + 7;
		m_AlarmInfo.value = 1;
		m_AlarmInfo.state = BADALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + Index, &m_AlarmInfo, sizeof(SAlarmShareMem));
		Index++;
	}

	GetIID("M0001", IID);
	for (int i = 0; i < Count; i++)//0到1
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = 1;
		m_AlarmInfo.state = AESCENDALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + Index, &m_AlarmInfo, sizeof(SAlarmShareMem));
		Index++;
	}

	for (int i = 0; i < Count; i++)//1到0
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID + 1;
		m_AlarmInfo.value = 1;
		m_AlarmInfo.state = DESCENDALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + Index, &m_AlarmInfo, sizeof(SAlarmShareMem));
		Index++;
	}

	for (int i = 0; i < Count; i++)//双向
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID + 2;
		m_AlarmInfo.value = 1;
		m_AlarmInfo.state = DOUBLEALARRM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + Index, &m_AlarmInfo, sizeof(SAlarmShareMem));
		Index++;
	}

	for (int i = 0; i < Count; i++)//坏点
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID + 3;
		m_AlarmInfo.value = 1;
		m_AlarmInfo.state = BADALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + Index, &m_AlarmInfo, sizeof(SAlarmShareMem));
		Index++;
	}

	for (int i = 0; i < Count; i++)//报警恢复
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID + 3;
		m_AlarmInfo.value = 1;
		m_AlarmInfo.state = ALARM_REVERT;
		m_AlarmInfo.CurAlmChgFlg |= 0x02;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + Index, &m_AlarmInfo, sizeof(SAlarmShareMem));
		Index++;
	}
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk20()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < 2000; i++)
	{
		m_AlarmInfo.time = -1;
		m_AlarmInfo.IID = 0;
		m_AlarmInfo.value = 0;
		m_AlarmInfo.state = 0;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
	}
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk21()
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG bRet = 0;
	int Index = 0;

	LONG IID = 0;
	GetIID("A0002", IID);

	for (int i = 0; i < 25; i++)//L3
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = 1;
		m_AlarmInfo.state = L3ALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
	}
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk22()
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG bRet = 0;
	int Index = 0;

	LONG IID = 0;
	GetIID("A0002", IID);

	for (int i = 0; i < 10; i++)//L3
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID++;
		m_AlarmInfo.value = 1;
		m_AlarmInfo.state = L3ALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
	}

	m_AlarmInfo.time = -1;
	memcpy(m_pAlarmMap + 10, &m_AlarmInfo, sizeof(SAlarmShareMem));
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk23()
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG bRet = 0;
	int Index = 0;
	int ItemCount = 0;
	char PID[8] = {0};

	LONG IID = 0;
	GetIID("C0001", IID);
	GetPID(IID, PID);

	ItemCount = GetAlarmCount(m_pAlarmMap);

	CTime t = CTime::GetCurrentTime(); 
	for (int i = 0; i < 3; i++)//L3
	{
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID + i;
		m_AlarmInfo.value = 1;
		m_AlarmInfo.state = L3ALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + ItemCount, &m_AlarmInfo, sizeof(SAlarmShareMem));
		ItemCount++;
	}

	m_AlarmInfo.time = -1;
	memcpy(m_pAlarmMap + ItemCount, &m_AlarmInfo, sizeof(SAlarmShareMem));
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk24()
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG bRet = 0;
	int Index = 0;
	int ItemCount = 0;

	ItemCount = GetAlarmCount(m_pAlarmMap);
	if (ItemCount > 0)
	{
		for (int i = ItemCount - 1; i >= ItemCount - 3; i--)//L3
		{
			m_AlarmInfo.time = -1;
			memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
		}
	}
}

short CCVAlarmDisplayTestDlg::GetAlarmCount(SAlarmShareMem* m_pDataMap)
{
	SAlarmShareMem m_AlarmInfo;
	int Count = 0;

	for (int i = 0; i < AlarmMax; i++)
	{
		memcpy(&m_AlarmInfo, m_pDataMap + i, sizeof(SAlarmShareMem));
		if (m_AlarmInfo.time != -1)
		{
			Count++;
		}
		else
		{
			break;
		}
	}

	return Count;
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk25()
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG IID = 0;
	GetIID("C0001", IID);
	int ItemIndex = 0;

	for (int i = 0; i < 3; i++)//L3
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = 1;
		m_AlarmInfo.state = L3ALARM;
		m_AlarmInfo.CurAlmChgFlg = 0;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + ItemIndex, &m_AlarmInfo, sizeof(SAlarmShareMem));
		ItemIndex++;
	}

	GetIID("C0002", IID);

	for (int i = 0; i < 3; i++)//L2
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = (float)-0.1;
		m_AlarmInfo.state = L2ALARM;
		m_AlarmInfo.CurAlmChgFlg = 0x02;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + ItemIndex, &m_AlarmInfo, sizeof(SAlarmShareMem));
		ItemIndex++;
	}

	GetIID("C0003", IID);

	for (int i = 0; i < 3; i++)//L2
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = (float)-0.1;
		m_AlarmInfo.state = L1ALARM;
		m_AlarmInfo.CurAlmChgFlg = 0x01;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + ItemIndex, &m_AlarmInfo, sizeof(SAlarmShareMem));
		ItemIndex++;
	}

	GetIID("C0004", IID);

	for (int i = 0; i < 3; i++)//L1
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = (float)-0.1;
		m_AlarmInfo.state = L1ALARM;
		m_AlarmInfo.CurAlmChgFlg = 0x01 | 0x02;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + ItemIndex, &m_AlarmInfo, sizeof(SAlarmShareMem));
		ItemIndex++;
	}
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk26()//报警复归
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG IID = 0;
	GetIID("C0008", IID);

	for (int i = 0; i < AlarmMax + 1; i++)
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = 100;
		m_AlarmInfo.state = ALARM_REVERT;
		m_AlarmInfo.CurAlmChgFlg = ALARM_RESTORATION;
		m_AlarmInfo.EscTime = 0;
		m_AlarmInfo.Limit = 200;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));

		if (i == AlarmMax)
		{
			m_AlarmInfo.time = -1;
			memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
		}
	}
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk27()//突变报警复归
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG IID = 0;
	GetIID("C0008", IID);

	for (int i = 0; i < AlarmMax + 1; i++)
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = 100;
		m_AlarmInfo.state = DEVALARM_REVERT;
		m_AlarmInfo.CurAlmChgFlg = ALARM_RESTORATION;
		m_AlarmInfo.EscTime = 0;
		m_AlarmInfo.Limit = 200;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));

		if (i == AlarmMax)
		{
			m_AlarmInfo.time = -1;
			memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
		}
	}
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk30()
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG IID = 0;
	GetIID("B0001", IID);

	for (int i = 0; i < AlarmMax + 1; i++)
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = 100;
		m_AlarmInfo.state = DOUBLEALARRM_REVERT;
		m_AlarmInfo.CurAlmChgFlg = ALARM_RESTORATION;
		m_AlarmInfo.EscTime = 0;
		m_AlarmInfo.Limit = 200;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));

		if (i == AlarmMax)
		{
			m_AlarmInfo.time = -1;
			memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
		}
	}
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk28()
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG IID = 0;
	GetIID("C0008", IID);

	for (int i = 0; i < AlarmMax + 1; i++)
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = 100;
		m_AlarmInfo.state = ALARM_CHGBAD_REVERT;
		m_AlarmInfo.CurAlmChgFlg = ALARM_RESTORATION;
		m_AlarmInfo.EscTime = 0;
		m_AlarmInfo.Limit = 200;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));

		if (i == AlarmMax)
		{
			m_AlarmInfo.time = -1;
			memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
		}
	}
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk29()
{
	// TODO: 在此添加控件通知处理程序代码
	time_t osBinaryTime = 0;
	LONG IID = 0;
	GetIID("B0001", IID);

	for (int i = 0; i < AlarmMax + 1; i++)
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.time = osBinaryTime;
		m_AlarmInfo.IID = IID;
		m_AlarmInfo.value = 0;
		m_AlarmInfo.state = ALARM_CHGBAD_REVERT;
		m_AlarmInfo.CurAlmChgFlg = ALARM_RESTORATION;
		m_AlarmInfo.EscTime = 0;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));

		if (i == AlarmMax)
		{
			m_AlarmInfo.time = -1;
			memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
		}
	}
}
