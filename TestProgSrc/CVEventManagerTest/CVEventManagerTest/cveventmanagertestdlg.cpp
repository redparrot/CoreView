// CVEventManagerTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CVEventManagerTest.h"
#include "CVEventManagerTestDlg.h"
#include "CVPasswordDlgComm.h"
#include "CVSpeech.h"
#include "CVCommondllcommon.h"
#include <vector>
#include <ipexport.h>
#include <winsock.h>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define WM_SYS_MSG				WM_USER + 5100
#define WM_CLOSE_PROG			WM_USER + 5000
#define WM_ALARM_CHANGE			WM_USER + 5000
#define	WM_OPERKEY_SHOW			6134			//小窗口专用键盘下拉显示消息
#define	WM_OPERKEY_SOUND		6135			//小窗口专用键盘声音确认消息
#define	WM_OPERKEY_SYS_MSG_SHOW	6136			//系统消息小窗口专用键盘下拉显示消息
#define WM_TOOLMANAGE_NOTIFY_MSG	WM_USER + 4044 //给ToolManage发送消息通知其启动内存管理程序或者启动系统,第一个参数为1时表示重新启动内存管理，为2时，启动系统
#define	WM_OPERKEY_ALL_OK			WM_USER + 5113//专用键盘消息--系统消息全部确认
#define WM_MINIMIZE					WM_USER + 111 //收到管理程序发送的最小化消息，通常是在CV8刚启动的时候

const int AlarmMax = 10;
vector<CEnumDesktopWindow> gEnumDesktopWindowList;

BOOL CALLBACK MyEnumProc(HWND hwnd, LPARAM lParam)  
{
	static int First = 1; 
	char ClassName[100]; 
	HWND hChildWnd = NULL;
	if (First == 1)
	{
		First = 0;
		hChildWnd = GetWindow(hwnd, GW_HWNDFIRST);   
	}
	else
	{
		hChildWnd = GetWindow(hwnd, GW_HWNDNEXT);   
	}
	char WinTitle[100];
	CEnumDesktopWindow _EnumDesktopWindow;

	_EnumDesktopWindow.hWnd = hChildWnd;
	if (_EnumDesktopWindow.hWnd != NULL)
	{
		::GetWindowText(hChildWnd, WinTitle, 100);
		_EnumDesktopWindow.Title = WinTitle;
		GetClassName(hChildWnd, ClassName, 100);
		_EnumDesktopWindow.ClassName = ClassName;
		GetWindowRect(hChildWnd, _EnumDesktopWindow.Rect);
		_EnumDesktopWindow.Rect;
		gEnumDesktopWindowList.push_back(_EnumDesktopWindow);
	}

	return true;  
}   

unsigned SyncVoiceThreadProcess(void* pParam)
{
	char buf[100] = {0};
	int ret = 0;

	ret = SpeechSync("宠辱不惊,看庭前花开花落,去留无意,望天上云卷云舒", -1);

	return 0;
}

unsigned VoiceThreadProcess(void* pParam)
{
	int ret = Speech("语音测试", -1);

	return 0;
}

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


// CCVEventManagerTestDlg 对话框

CCVEventManagerTestDlg::CCVEventManagerTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCVEventManagerTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAlarmMap = NULL;
	m_hAlarmMap = NULL;
}

void CCVEventManagerTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCVEventManagerTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CCVEventManagerTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK37, &CCVEventManagerTestDlg::OnBnClickedOk37)
	ON_BN_CLICKED(IDOK38, &CCVEventManagerTestDlg::OnBnClickedOk38)
	ON_BN_CLICKED(IDOK39, &CCVEventManagerTestDlg::OnBnClickedOk39)
	ON_BN_CLICKED(IDOK40, &CCVEventManagerTestDlg::OnBnClickedOk40)
	ON_BN_CLICKED(IDOK41, &CCVEventManagerTestDlg::OnBnClickedOk41)
	ON_BN_CLICKED(IDOK42, &CCVEventManagerTestDlg::OnBnClickedOk42)
	ON_BN_CLICKED(IDOK43, &CCVEventManagerTestDlg::OnBnClickedOk43)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDOK44, &CCVEventManagerTestDlg::OnBnClickedOk44)
	ON_BN_CLICKED(IDOK45, &CCVEventManagerTestDlg::OnBnClickedOk45)
	ON_BN_CLICKED(IDOK46, &CCVEventManagerTestDlg::OnBnClickedOk46)
	ON_BN_CLICKED(IDOK47, &CCVEventManagerTestDlg::OnBnClickedOk47)
	ON_BN_CLICKED(IDOK48, &CCVEventManagerTestDlg::OnBnClickedOk48)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDOK49, &CCVEventManagerTestDlg::OnBnClickedOk49)
	ON_BN_CLICKED(IDOK50, &CCVEventManagerTestDlg::OnBnClickedOk50)
	ON_BN_CLICKED(IDOK51, &CCVEventManagerTestDlg::OnBnClickedOk51)
	ON_BN_CLICKED(IDOK52, &CCVEventManagerTestDlg::OnBnClickedOk52)
	ON_BN_CLICKED(IDOK53, &CCVEventManagerTestDlg::OnBnClickedOk53)
	ON_BN_CLICKED(IDOK54, &CCVEventManagerTestDlg::OnBnClickedOk54)
	ON_BN_CLICKED(IDOK55, &CCVEventManagerTestDlg::OnBnClickedOk55)
	ON_BN_CLICKED(IDOK56, &CCVEventManagerTestDlg::OnBnClickedOk56)
	ON_BN_CLICKED(IDOK57, &CCVEventManagerTestDlg::OnBnClickedOk57)
	ON_BN_CLICKED(IDOK58, &CCVEventManagerTestDlg::OnBnClickedOk58)
	ON_BN_CLICKED(IDOK59, &CCVEventManagerTestDlg::OnBnClickedOk59)
	ON_BN_CLICKED(IDOK60, &CCVEventManagerTestDlg::OnBnClickedOk60)
	ON_BN_CLICKED(IDCANCEL, &CCVEventManagerTestDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CCVEventManagerTestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &CCVEventManagerTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCVEventManagerTestDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDOK61, &CCVEventManagerTestDlg::OnBnClickedOk61)
	ON_BN_CLICKED(IDC_BUTTON4, &CCVEventManagerTestDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCVEventManagerTestDlg::OnTopmostCore)
	ON_BN_CLICKED(IDOK62, &CCVEventManagerTestDlg::OnMinimizeToolManager)
	ON_BN_CLICKED(IDOK63, &CCVEventManagerTestDlg::OnStartMultCrtop)
	ON_BN_CLICKED(IDOK64, &CCVEventManagerTestDlg::OnCloseCrtop)
	ON_BN_CLICKED(IDC_BUTTON6, &CCVEventManagerTestDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCVEventManagerTestDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCVEventManagerTestDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDOK65, &CCVEventManagerTestDlg::OnBnClickedOk65)
	ON_BN_CLICKED(IDC_BUTTON9, &CCVEventManagerTestDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CCVEventManagerTestDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDOK66, &CCVEventManagerTestDlg::OnBnClickedOk66)
	ON_BN_CLICKED(IDOK67, &CCVEventManagerTestDlg::OnBnClickedOk67)
	ON_BN_CLICKED(IDOK68, &CCVEventManagerTestDlg::OnBnClickedOk68)
	ON_BN_CLICKED(IDOK69, &CCVEventManagerTestDlg::OnBnClickedOk69)
	ON_BN_CLICKED(IDOK70, &CCVEventManagerTestDlg::OnBnClickedOk70)
END_MESSAGE_MAP()


// CCVEventManagerTestDlg 消息处理程序

BOOL CCVEventManagerTestDlg::OnInitDialog()
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
	//SpeechInitialize();

	//OnBnClickedOk43();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCVEventManagerTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCVEventManagerTestDlg::OnPaint()
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
HCURSOR CCVEventManagerTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCVEventManagerTestDlg::OnBnClickedButton1()
{
	char buf[1024] = "CVMemoryMonitor";
	BOOL ret = VerifyPassword(buf);
	
	if (ret == TRUE)
	{
		SetDlgItemText(IDC_STATIC1, "密码通过验证");
	}
    else if (ret == -1)
    {
        SetDlgItemText(IDC_STATIC1, "用户取消");
    }
	else
	{
		SetDlgItemText(IDC_STATIC1, "密码错误！");
	}
}

void CCVEventManagerTestDlg::OnBnClickedOk37()
{
	// TODO: 在此添加控件通知处理程序代码
	SetTimer(3, 10, NULL);
}

void CCVEventManagerTestDlg::OnBnClickedOk38()
{
	// TODO: 在此添加控件通知处理程序代码
	HWND hwnd = ::FindWindow("CVSystemMsg", NULL);

	::SendMessage(hwnd, WM_CLOSE, 0, 0);
}

//运行SOE报警小窗口
void CCVEventManagerTestDlg::OnBnClickedOk39()
{
	// TODO: 在此添加控件通知处理程序代码
	LONG IID = 0;
	GetIID("C0001", IID);
	CString szIID;
	szIID.Format("%d", IID);
	ShellExecute(m_hWnd,
		_T("open"), _T("CVSoeMsg.exe"), szIID,
		"C:\\CoreView\\DriverExec\\Exe", SW_SHOWNORMAL);
}

void CCVEventManagerTestDlg::OnBnClickedOk40()
{
	// TODO: 在此添加控件通知处理程序代码
	HWND hwnd = ::FindWindowW(L"CVSoeMsg", L"SOE");

	::SendMessage(hwnd, WM_CLOSE, 0, 0);
}

//运行报警小窗口
void CCVEventManagerTestDlg::OnBnClickedOk41()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(m_hWnd,
		_T("open"), _T("CVAlarmMsg.exe"), "2",
		"C:\\CoreView\\FuncExec\\exe", SW_SHOWNORMAL);
}

void CCVEventManagerTestDlg::OnBnClickedOk42()
{
	// TODO: 在此添加控件通知处理程序代码
	HWND hwnd = ::FindWindowW(L"CVAlarmMsg", NULL);
	::SendMessage(hwnd, WM_CLOSE, 0, 0);
}

void CCVEventManagerTestDlg::OnBnClickedOk43()
{
	// TODO: 在此添加控件通知处理程序代码
	m_hAlarmMap = CreateFileMapping(INVALID_HANDLE_VALUE,
		NULL,PAGE_READWRITE|SEC_COMMIT,
		0,
		sizeof(InstantAlmRecd_T) * AlarmMax,
		G_INSTANTALMMEM);

	if (m_hAlarmMap != NULL)
	{
		m_pAlarmMap = (InstantAlmRecd_T*)MapViewOfFile(m_hAlarmMap, FILE_MAP_WRITE, 0, 0, 0);
		if (m_pAlarmMap == NULL)
		{
			CloseHandle(m_hAlarmMap);
			m_hAlarmMap = NULL;
		}
		else
		{
			memset(m_pAlarmMap, 0, 	sizeof(InstantAlmRecd_T) * AlarmMax);
		}
	}

	time_t osBinaryTime = 0;
	LONG IID = 0;
	GetIID("C0001", IID);

	for (int i = 0; i < AlarmMax; i++)//产生模拟的九条报警
	{
		CTime t(2006, 2, 11, 23, 10, 1); 
		osBinaryTime = (time_t)t.GetTime(); 
		m_AlarmInfo.AlmTime = osBinaryTime;
		m_AlarmInfo.IID = IID + i;

		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(InstantAlmRecd_T));
	}
}

void CCVEventManagerTestDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_pAlarmMap != NULL)
	{
		//delete m_pAlarmMap;
		//CloseHandle(m_hAlarmMap);
	}

	OnBnClickedOk60();

	CDialog::OnClose();
}

BOOL CALLBACK EnumFunc(HWND hwnd, DWORD lParam) 
{ 
	return TRUE;
}

void CCVEventManagerTestDlg::OnBnClickedOk44()
{
	// TODO: 在此添加控件通知处理程序代码
	//SetTimer(1, 1000, NULL);
	HWND hWnd = ::FindWindow("CVAlarmMsg", "报警");
	::PostMessage(hWnd, WM_ALARM_CHANGE, 0, 0);
}

void CCVEventManagerTestDlg::OnBnClickedOk45()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(m_hWnd,
		_T("open"), _T("CVSystemMsg.exe"), "",
		"C:\\coreview\\SystemExec\\EXE", SW_SHOWNORMAL);
}

void CCVEventManagerTestDlg::OnBnClickedOk46()
{
	// TODO: 在此添加控件通知处理程序代码
	HWND hwnd = ::FindWindowW(NULL, L"事件触发");

	::SendMessage(hwnd, WM_CLOSE, NULL, NULL);
}

void CCVEventManagerTestDlg::OnBnClickedOk47()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(m_hWnd,
		_T("open"), _T("CVEventTrigger.exe"), "",
		"C:\\coreview\\funcexec\\CVEventExec\\EXE", SW_SHOWNORMAL);
}

//语音测试
void CCVEventManagerTestDlg::OnBnClickedOk48()
{
	AfxBeginThread((AFX_THREADPROC)VoiceThreadProcess, NULL, THREAD_PRIORITY_NORMAL);
}

vector<LONG> List;
vector<LONG>::iterator It;
void CCVEventManagerTestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 1)
	{
		HWND hWnd;
		static int Cnt = 0;

		time_t osBinaryTime = 0;
		LONG IID = 0;
		GetIID("A0001", IID);

		time(&osBinaryTime);
		List.push_back(osBinaryTime);
		Cnt++;
		//if (Cnt > 10)
		//{
		//	It = List.begin();
		//	List.erase(It);
		//}

		for (int i = 0; i < 10; i++)
		{
			m_AlarmInfo.AlmTime = osBinaryTime;
			m_AlarmInfo.IID = IID;
			memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(InstantAlmRecd_T));
		}
		//if (Cnt <= 9)
		//{
		//	time(&osBinaryTime);
		//	Cnt++;
		//} 
		//else
		//{
		//	Cnt = 0;
		//	memset(m_pAlarmMap, 0, sizeof(InstantAlmRecd_T) * 10);
		//}

		hWnd = ::FindWindow("CVAlarmMsg", NULL);
		//EnumWindows((WNDENUMPROC)EnumFunc, 0); 
		::PostMessage(hWnd, WM_ALARM_CHANGE, 0, 0);
	}

	if (nIDEvent == 2)
	{
		Play("C:\\coreview\\funcexec\\CVEventExec\\Configure\\Sound\\tada.wav");
		AfxBeginThread((AFX_THREADPROC)VoiceThreadProcess, NULL, THREAD_PRIORITY_NORMAL);
	}

	if (nIDEvent == 3)
	{
		static int Count = 0;
		HWND hwnd = ::FindWindowW(L"CVSystemMsg", NULL);

		CString Msg;
		COPYDATASTRUCT cpd;
		cpd.dwData = 0;
		Count++;
		if (Count >= 1000)
		{
			Count = 1;
		}
		//Msg.Format(_T("Message %d，奇长无比YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY!--15--0"), Count);
		Msg.Format(_T("Message %d，奇长无比YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY!"), Count);
		cpd.cbData = Msg.GetLength() + 1;
		cpd.lpData = Msg.GetBuffer();
		Msg.ReleaseBuffer();

		::SendMessage(hwnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
	}
	CDialog::OnTimer(nIDEvent);
}

void CCVEventManagerTestDlg::OnBnClickedOk49()//专用键盘显示钮测试
{
	// TODO: 在此添加控件通知处理程序代码
	HWND hWnd;

	hWnd = ::FindWindow("CVAlarmMsg", "报警");
	::PostMessage(hWnd, WM_OPERKEY_SHOW, 0, 0);
}

void CCVEventManagerTestDlg::OnBnClickedOk50()
{
	// TODO: 在此添加控件通知处理程序代码
	HWND hWnd;

	hWnd = ::FindWindow("CVAlarmMsg", "报警");
	::PostMessage(hWnd, WM_OPERKEY_SOUND, 0, 0);
}

void CCVEventManagerTestDlg::OnBnClickedOk51()
{
	// TODO: 在此添加控件通知处理程序代码
	//Play("C:\\coreview\\funcexec\\CVEventExec\\Configure\\Sound\\tada.wav");
	AfxBeginThread((AFX_THREADPROC)PlayThreadProcess, NULL, THREAD_PRIORITY_NORMAL);
}

void CCVEventManagerTestDlg::OnBnClickedOk52()
{
	// TODO: 在此添加控件通知处理程序代码
	Stop(0);
}

void CCVEventManagerTestDlg::OnBnClickedOk53()
{
	// TODO: 在此添加控件通知处理程序代码
	char buf[100] = {0};
	int ret = 0;

	AfxBeginThread((AFX_THREADPROC)SyncVoiceThreadProcess, NULL, THREAD_PRIORITY_NORMAL);
	//ret = SpeechSync("宠辱不惊,看庭前花开花落,去留无意,望天上云卷云舒", -1);
	//for (int i = 0; i < 10; i++)
	//{
	//	sprintf_s(buf, sizeof(buf), "测试语音%d", i + 1);
	//	ret = SpeechSync(buf, 2);
	//}
}

void CCVEventManagerTestDlg::OnBnClickedOk54()
{
	// TODO: 在此添加控件通知处理程序代码
	HWND hWnd = NULL;

	hWnd = ::FindWindow("CVAlarmMsg", "报警");
	::PostMessage(hWnd, WM_ALARM_CHANGE, 0, 1);

	hWnd = ::FindWindow("CVAlarmMsg", "报警");

}

void CCVEventManagerTestDlg::OnBnClickedOk55()
{
	// TODO: 在此添加控件通知处理程序代码
	HWND hwnd = ::FindWindowW(L"CVSystemMsg", NULL);

	::PostMessage(hwnd, WM_USER + 1304, NULL, NULL);
}

void CCVEventManagerTestDlg::OnBnClickedOk56()
{
	// TODO: 在此添加控件通知处理程序代码
	HWND hWnd;

	hWnd = ::FindWindow("CVSystemMsg", "系统消息");
	::PostMessage(hWnd, WM_OPERKEY_SYS_MSG_SHOW, 0, 0);
}

//重启内存
void CCVEventManagerTestDlg::OnBnClickedOk57()
{
	// TODO: 在此添加控件通知处理程序代码
	HWND hWnd;

	hWnd = ::FindWindow("CVToolManager", NULL);
	::PostMessage(hWnd, WM_TOOLMANAGE_NOTIFY_MSG, 1, 0);
}

//重启CoreView
void CCVEventManagerTestDlg::OnBnClickedOk58()
{
	// TODO: 在此添加控件通知处理程序代码
	HWND hWnd;

	hWnd = ::FindWindow("#CVToolManager", NULL);
	::PostMessage(hWnd, WM_TOOLMANAGE_NOTIFY_MSG, 2, 0);
}

//声音/语音测试
void CCVEventManagerTestDlg::OnBnClickedOk59()
{
	// TODO: 在此添加控件通知处理程序代码
	bRun = TRUE;

	SetTimer(2, 3000, NULL);
}

void CCVEventManagerTestDlg::OnBnClickedOk60()
{
	// TODO: 在此添加控件通知处理程序代码
	KillTimer(2);
}

void CCVEventManagerTestDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedOk60();
	OnCancel();
}

void CCVEventManagerTestDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedOk60();
	OnOK();
}

void CCVEventManagerTestDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	static int Count = 0;
	HWND hwnd = ::FindWindowW(L"CVSystemMsg", NULL);

	CString Msg;
	COPYDATASTRUCT cpd;
	cpd.dwData = 0;
	Count++;
	Msg = L"异常:Net Abnormal";
	cpd.cbData = Msg.GetLength() + 1;
	cpd.lpData = Msg.GetBuffer();
	Msg.ReleaseBuffer();

	::SendMessage(hwnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
}

void CCVEventManagerTestDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	static int Count = 0;
	HWND hwnd = ::FindWindowW(L"CVSystemMsg", NULL);

	CString Msg;
	COPYDATASTRUCT cpd;
	cpd.dwData = 0;
	Count++;
	Msg = L"恢复:Net Abnormal";
	cpd.cbData = Msg.GetLength() + 1;
	cpd.lpData = Msg.GetBuffer();
	Msg.ReleaseBuffer();

	::SendMessage(hwnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
}

void CCVEventManagerTestDlg::OnBnClickedOk61()
{
	// TODO: 在此添加控件通知处理程序代码
	HWND hWnd;

	hWnd = ::FindWindow("CVSystemMsg", "系统消息");
	::PostMessage(hWnd, WM_OPERKEY_ALL_OK, 0, 0);
}

void CCVEventManagerTestDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	static int Count = 0;
	HWND hwnd = ::FindWindowW(L"CVSystemMsg", L"系统消息");

	CString Msg;
	COPYDATASTRUCT cpd;
	cpd.dwData = 1;//清除指定关键字的信息
	Count++;
	Msg = L"Net";
	cpd.cbData = Msg.GetLength() + 1;
	cpd.lpData = Msg.GetBuffer();
	Msg.ReleaseBuffer();

	::SendMessage(hwnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
}

void CCVEventManagerTestDlg::OnTopmostCore()
{
	// TODO: Add your control notification handler code here
	//获取桌面窗口列表
	vector<CEnumDesktopWindow> Winlist;
	int WinCnt = 0;
	WinCnt = EnumDesktopWindow(Winlist);
	TRACE("遍历窗口数量 = %d\n", WinCnt);

	int cxScreen = 0, cyScreen = 0; 
	HWND hCore = NULL;
	CEnumDesktopWindow _struct;
	cxScreen = GetSystemMetrics(SM_CXSCREEN);
	cyScreen = GetSystemMetrics(SM_CYSCREEN);
	CRect DstRect(0, 0, cxScreen, int(cyScreen * 0.0625));//0.0625是CV8在线是上部黑条的长宽比
	for (int i = 0; i < WinCnt; i++)
	{
		_struct = Winlist[i];
		if (_struct.Rect == DstRect)
		{
			hCore = _struct.hWnd;
			break;
		}
	}

	if (hCore != NULL)
	{
		//CRect Rect;
		//::GetWindowRect(m_hWnd, &Rect);
		::SetWindowPos(hCore, HWND_TOPMOST, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE);
	}
}

int CCVEventManagerTestDlg::EnumDesktopWindow(vector<CEnumDesktopWindow>& EnumDesktopWindowList)
{
	int EnumCnt = 0;
	CWnd *pChildWnd = NULL;

	EnumDesktopWindowList.clear();
	gEnumDesktopWindowList = EnumDesktopWindowList;
	pChildWnd = CWnd::GetDesktopWindow();   
	::EnumChildWindows(pChildWnd->GetSafeHwnd(), (WNDENUMPROC)MyEnumProc, 0);
	EnumDesktopWindowList = gEnumDesktopWindowList;

	return EnumCnt = (int)EnumDesktopWindowList.size();
}

void CCVEventManagerTestDlg::OnMinimizeToolManager()
{
	// TODO: Add your control notification handler code here
	HWND hwnd = ::FindWindow("CVToolManager", NULL);
	::SendMessage(hwnd, WM_MINIMIZE, 0, 0);
}

void CCVEventManagerTestDlg::OnStartMultCrtop()
{
	int Loop = 12;
	for (int i = 0; i < Loop; i++)
	{
		ShellExecute(m_hWnd,
			_T("open"), _T("crtop.exe"), "1,1",
			"C:\\coreview\\FuncExec\\EXE", SW_SHOWNORMAL);	
	}
}

void CCVEventManagerTestDlg::OnCloseCrtop()
{
	// TODO: Add your control notification handler code here
	HWND hlWnd = NULL;
	hlWnd = ::FindWindow("CRTOP", NULL);
	if(hlWnd != NULL)//有已经启动的CRTOP
	{
		//发送关闭消息
		::PostMessage(hlWnd, WM_CLOSE, 0, 0);
	}
}

void CCVEventManagerTestDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	static int Color = 0;
	HWND hwnd = ::FindWindowW(L"CVSystemMsg", NULL);

	CString Msg;
	COPYDATASTRUCT cpd;
	cpd.dwData = 0;
	Color++;
	if (Color > 3)
	{
		Color = 0;
	}
	Msg.Format(_T("异常:奇长无比消息文本奇长无比消息文本奇长无比消息文本奇长无比消息文本奇长无比消息文本End!--0--%d"), Color);
	cpd.cbData = Msg.GetLength() + 1;
	cpd.lpData = Msg.GetBuffer();
	Msg.ReleaseBuffer();

	::SendMessage(hwnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
}

void CCVEventManagerTestDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	static int Color = 0;
	HWND hwnd = ::FindWindowW(L"CVSystemMsg", NULL);

	CString Msg;
	COPYDATASTRUCT cpd;
	cpd.dwData = 0;
	Color++;
	if (Color > 2)
	{
		Color = 0;
	}
	Msg.Format(_T("奇长无比消息文本消息文本消息文本消息文本消息文本消息文本消息文本消息文本消息文本End!--5--%d"), Color);
	cpd.cbData = Msg.GetLength() + 1;
	cpd.lpData = Msg.GetBuffer();
	Msg.ReleaseBuffer();

	::SendMessage(hwnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
}

void CCVEventManagerTestDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	static int Color = 0;
	HWND hwnd = ::FindWindowW(L"CVSystemMsg", NULL);

	CString Msg;
	COPYDATASTRUCT cpd;
	cpd.dwData = 0;
	Color++;
	if (Color > 2)
	{
		Color = 0;
	}
	Msg.Format(_T("恢复:奇长无比消息文本奇长无比消息文本奇长无比消息文本奇长无比消息文本奇长无比消息文本End!--0--%d"), Color);
	cpd.cbData = Msg.GetLength() + 1;
	cpd.lpData = Msg.GetBuffer();
	Msg.ReleaseBuffer();

	::SendMessage(hwnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
}

unsigned PlayThreadProcess(void* pParam)
{
	//int ret = Speech("语音测试", -1);
	Play("C:\\coreview\\funcexec\\CVEventExec\\Configure\\Sound\\tada.wav");

	return 0;
}

void CCVEventManagerTestDlg::OnBnClickedOk65()
{
	// TODO: 在此添加控件通知处理程序代码
	ULONG Buf[10] = {0};
	COPYDATASTRUCT cpd;
	cpd.dwData = 10001;//远程重启内存管理的标志
	cpd.cbData = sizeof(ULONG) * 2;
	Buf[0] = 1;//需要远程机器的个数
	Buf[1] = GetULONGIP("192.168.0.156");
	cpd.lpData = Buf;

	HWND hWnd = NULL;
	hWnd = ::FindWindow("CVToolManager", NULL);
	if (hWnd != NULL)
	{
		::SendMessage(hWnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
	}
}

ULONG GetULONGIP(CString IP)
{
	ULONG ulIP = (IPAddr) inet_addr(IP);

	return ulIP;
}

//警示消息处理
void CCVEventManagerTestDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	static int Color = 0;
	HWND hwnd = ::FindWindowW(L"CVSystemMsg", NULL);

	CString Msg;
	COPYDATASTRUCT cpd;
	cpd.dwData = 2;
	Color++;
	if (Color > 3)
	{
		Color = 0;
	}
	Msg.Format(_T("警示文字!--0--%d"), Color);
	cpd.cbData = Msg.GetLength() + 1;
	cpd.lpData = Msg.GetBuffer();
	Msg.ReleaseBuffer();

	::SendMessage(hwnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
}

//关闭警示消息处理
void CCVEventManagerTestDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	static int Color = 0;
	HWND hwnd = ::FindWindowW(L"CVSystemMsg", NULL);

	CString Msg;
	COPYDATASTRUCT cpd;
	cpd.dwData = 3;
	Color++;
	if (Color > 3)
	{
		Color = 0;
	}
	Msg.Format(_T("警示文字!--0--%d"), Color);
	cpd.cbData = Msg.GetLength() + 1;
	cpd.lpData = Msg.GetBuffer();
	Msg.ReleaseBuffer();

	::SendMessage(hwnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
}

//按钮：转换系统图消息
void CCVEventManagerTestDlg::OnBnClickedOk66()
{
	// TODO: 在此添加控件通知处理程序代码
	HWND hwnd = ::FindWindow("~Grab_Im", NULL);
	if (hwnd)
	{
		int GrNo = 1;
		::PostMessage(hwnd, WM_USER + 1006, GrNo, NULL);
	}
}

//按钮：扫描系统图消息
void CCVEventManagerTestDlg::OnBnClickedOk67()
{
	// TODO: 在此添加控件通知处理程序代码
	HWND hwnd = ::FindWindow("~Grab_Im", NULL);
	if (hwnd)
	{
		int GrNo = 1;
		::PostMessage(hwnd, WM_USER + 1007, GrNo, NULL);
	}
}

void CCVEventManagerTestDlg::OnBnClickedOk68()
{
	// TODO: 在此添加控件通知处理程序代码
	TRACE("StartServer");
	//StartServer();

	int MimicCnt = GetMimicFileNameList();

	for (int i = 0; i < MimicCnt; i++)
	{
		vector<CString> PIDList;

		CString FileName = MimicFileNameList[i];
		TRACE("获取%s的PID列表\n", FileName);

		//查找后台服务进程并发送功能消息...
		HWND hwnd = ::FindWindow("~Grab_Im", NULL);
		if (hwnd == NULL)
		{
			//StartServer();
		}
		int GrNo = atoi(FileName.Right(6));
		LRESULT Ret = ::SendMessage(hwnd, WM_USER + 1008, GrNo, NULL);
		if (Ret == 0)
		{
			CStdioFile f;
			BOOL b = f.Open("C:\\CoreView\\FuncExec\\exe\\Grab_Im.txt", CFile::modeRead | CFile::typeText);
			if (b)
			{
				CString PID;
				while (f.ReadString(PID))
				{
					PIDList.push_back(PID);
				}

				f.Close();
			}
		}
	}

	TRACE("StopServer");
	//StopServer();
}

void CCVEventManagerTestDlg::StartServer()
{
	CString CmdLine = "-server";
	SHELLEXECUTEINFO ShExecInfo = {0};
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = "C:\\Coreview\\FuncExec\\exe\\Grab_Im.exe";
	ShExecInfo.lpParameters = CmdLine;
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;
	ShExecInfo.hInstApp = NULL;
	ShellExecuteEx(&ShExecInfo);
	WaitForInputIdle(ShExecInfo.hProcess, INFINITE);
}

void CCVEventManagerTestDlg::StopServer()
{
	//结束后台的所有Grab_Im进程...
	HWND hwnd = ::FindWindowW(L"~Grab_Im", NULL);
	if (hwnd)
	{
		::PostMessage(hwnd, WM_CLOSE, NULL, NULL);
	}
}

//系统图列表
struct MimicInfo 
{
	char	grbiid[8+1];
	char	grbname[40];
	BOOL operator == (const MimicInfo & other) const
	{
		return (stricmp(this->grbiid,other.grbiid) == 0);
	}
};
#define MIMICDEFAULTPATH "C:\\Drawings"
#define MIMICSYSCONFINI "C:\\CoreView\\FuncExec\\CVMimicExec\\Configure\\mimicsysconf.cyt"
int CCVEventManagerTestDlg::GetMimicFileNameList()
{
	TRACE("调用int GetMimicList()\n");
	DWORD t1 = GetTickCount();
	char				SrcfilePathFile[255];
	char SrcfilePath[255];
	WIN32_FIND_DATA     FindFileData;
	HANDLE				handle;
	MimicFileNameList.clear();

	//判断路径是否存在
	//获取系统图存放路径
	GetPrivateProfileString("Drawings Dir", "MimicPath", MIMICDEFAULTPATH, SrcfilePath, 255, MIMICSYSCONFINI);

	if (_access(SrcfilePath, 0) == -1)
	{
		return -1;
	}
	sprintf_s(SrcfilePathFile, "%s\\*.grb", SrcfilePath);
	handle = FindFirstFile(SrcfilePathFile, &FindFileData);
	if (handle != INVALID_HANDLE_VALUE)
	{
		BOOL		bResult = TRUE;
		CString		csGrb;
		MimicInfo GrbInfo;
		memset(&GrbInfo, 0, sizeof(MimicInfo));

		while (bResult)
		{
			csGrb.Format("%s", FindFileData.cFileName);
			if(csGrb.GetLength() != 12)
			{
				bResult = FindNextFile(handle, &FindFileData);
				continue;
			}
			csGrb.MakeUpper();
			csGrb = csGrb.Left(8);

			//检查图是否合法的图
			if(CheckGrbValid(csGrb) == TRUE)
			{
				MimicFileNameList.push_back(csGrb);

				//修改文件名为全大写
				CString OriFile = FindFileData.cFileName;
				CString DstFile = OriFile;
				if (OriFile != DstFile.MakeUpper())
				{
					CString PathFile;
					PathFile.Format("%s\\%s", SrcfilePath, DstFile);
					BOOL b = MoveFile(PathFile, PathFile);
				}
			}
			bResult = FindNextFile(handle, &FindFileData);
		}
	}
	FindClose(handle);

	DWORD t2 = GetTickCount();
	CString Msg;
	Msg.Format("GetMimicFileNameList()耗时=%dms", t2 - t1);
	TRACE(Msg);

	return (int)MimicFileNameList.size();
}

//系统图名称合法性检查
BOOL CCVEventManagerTestDlg::CheckGrbValid(CString Grbiid)
{
	CString Grbtmp;

	Grbtmp = Grbiid.MakeUpper().Trim();
	if(Grbtmp.Left(2) != "GR")
		return FALSE;
	if(Grbtmp.GetLength() != 8)
		return FALSE;

	for(int i = 2; i < 8; i++)
	{
		int Ret = isdigit(Grbtmp.GetAt(i));
		if( Ret == 0 )
		{
			return(FALSE);
		}
	}
	return TRUE;
}

//按钮：获取弹出图列表
void CCVEventManagerTestDlg::OnBnClickedOk69()
{
	// TODO: 在此添加控件通知处理程序代码
	TRACE("StartServer");
	//StartServer();

	int MimicCnt = GetMimicFileNameList();

	for (int i = 0; i < MimicCnt; i++)
	{
		vector<CString> MimicList;

		CString FileName = MimicFileNameList[i];
		TRACE("获取%s的弹出图列表\n", FileName);

		//查找后台服务进程并发送功能消息...
		HWND hwnd = ::FindWindow("~Grab_Im", NULL);
		if (hwnd == NULL)
		{
			//StartServer();
		}
		int GrNo = atoi(FileName.Right(6));
		LRESULT Ret = ::SendMessage(hwnd, WM_USER + 1009, GrNo, NULL);
		if (Ret == 0)
		{
			CStdioFile f;
			BOOL b = f.Open("C:\\CoreView\\FuncExec\\exe\\Grab_Im.txt", CFile::modeRead | CFile::typeText);
			if (b)
			{
				CString Mimic;
				while (f.ReadString(Mimic))
				{
					MimicList.push_back(Mimic);
				}

				f.Close();
			}
		}
	}

	TRACE("StopServer");
	//StopServer();
}

//按钮：替换PID
void CCVEventManagerTestDlg::OnBnClickedOk70()
{
	// TODO: 在此添加控件通知处理程序代码
	TRACE("StartServer");
	//StartServer();

	int MimicCnt = GetMimicFileNameList();

	for (int i = 0; i < MimicCnt; i++)
	{
		//vector<CString> MimicList;

		CString FileName = MimicFileNameList[i];
		TRACE("获取%s的弹出图列表\n", FileName);

		//查找后台服务进程并发送功能消息...
		HWND hwnd = ::FindWindow("~Grab_Im", NULL);
		if (hwnd == NULL)
		{
			//StartServer();
		}

		CString Msg;
		Msg.Format("%s,%s,%s", FileName, "A0001", "A0002");
		COPYDATASTRUCT cpd;
		cpd.dwData = 1;
		cpd.cbData = Msg.GetLength() + 1;
		cpd.lpData = Msg.GetBuffer();
		Msg.ReleaseBuffer();
		LRESULT Ret = ::SendMessage(hwnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
		if (Ret == 0)
		{
			CStdioFile f;
			BOOL b = f.Open("C:\\CoreView\\FuncExec\\exe\\Grab_Im.txt", CFile::modeRead | CFile::typeText);
			if (b)
			{
				//CString Mimic;
				//while (f.ReadString(Mimic))
				//{
				//	MimicList.push_back(Mimic);
				//}

				f.Close();
			}
		}
	}

	TRACE("StopServer");
	//StopServer();
}
