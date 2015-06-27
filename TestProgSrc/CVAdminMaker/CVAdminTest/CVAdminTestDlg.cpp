// CVAdminTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CVAdminTest.h"
#include "CVAdminTestDlg.h"
#include "Winnetwk.h"
#pragma comment(lib, "Mpr.lib")
#include "CVAdminComm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

typedef struct T_DiskInfo
{
    ULONGLONG TotalBytes;
    ULONGLONG FreeBytes;
} T_DiskInfo;

CString POCName = "CIS1_MDA";
CString User_Name = "CoreView$";
CString Password = "buk3Y8+iYE0*v^UsqTvhDvz2#OFXENgA)bC(7VwNuTa!wlL~AM";

//单机链接测试
unsigned HostConnectProcess(void *pParam)
{
    CCVAdminTestDlg	*p = (CCVAdminTestDlg *) pParam;
    p->HostTest();

    return 2;
}

//循环链接测试
unsigned ConnectProcess(void *pParam)
{
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    CCVAdminTestDlg	*p = (CCVAdminTestDlg *) pParam;
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    p->ConnectThreadEvent = CreateEvent(NULL, FALSE, FALSE, "ConnectProcessFun");
    p->ConnectProcessFun();

    TRACE("ConnectProcessFun正常结束\n");
    SetEvent(p->ConnectThreadEvent);
    return 1;
}

unsigned PocListProcess(void *pParam)
{
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    CCVAdminTestDlg	*p = (CCVAdminTestDlg *) pParam;
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    p->bProcessing = TRUE;

    //p->GetPOCNameList(p->NameList);

    p->bProcessing = FALSE;

    return 1;
}

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
BOOL GetDiskInfo(char* Driver, T_DiskInfo& DiskInfo)
{
    BOOL Ret = FALSE;
    if (strlen(Driver) < 3)
    {
        DiskInfo.TotalBytes = 0;
        DiskInfo.FreeBytes = 0;
        return -1;
    }

    memset(&DiskInfo, 0, sizeof(T_DiskInfo));

    ULARGE_INTEGER FreeBytesAvailable;
    ULARGE_INTEGER TotalNumberOfBytes;
    ULARGE_INTEGER TotalNumberOfFreeBytes;

    Ret = GetDiskFreeSpaceEx(Driver, &FreeBytesAvailable, &TotalNumberOfBytes, &TotalNumberOfFreeBytes);
    if (Ret == TRUE)
    {
        DiskInfo.TotalBytes = TotalNumberOfBytes.QuadPart;
        DiskInfo.FreeBytes = TotalNumberOfFreeBytes.QuadPart;
    }

    return TRUE;
}


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

// CCVAdminTestDlg 对话框

CCVAdminTestDlg::CCVAdminTestDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CCVAdminTestDlg::IDD, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCVAdminTestDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //DDX_Control(pDX, IDC_LIST1, m_List);
    //DDX_Control(pDX, IDC_PROGRESS1, m_Progress);
    DDX_Control(pDX, IDC_LIST1, m_MsgList);
    DDX_Control(pDX, IDC_COMBO1, m_LangList);
    DDX_Control(pDX, IDOK12, m_BlankPwSet);
}

BEGIN_MESSAGE_MAP(CCVAdminTestDlg, CDialog)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    //}}AFX_MSG_MAP
    ON_BN_CLICKED(IDOK, &CCVAdminTestDlg::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CCVAdminTestDlg::OnBnClickedCancel)
    ON_BN_CLICKED(IDOK2, &CCVAdminTestDlg::OnBnClickedOk2)
    ON_BN_CLICKED(IDOK3, &CCVAdminTestDlg::OnBnClickedOk3)
    ON_BN_CLICKED(IDOK4, &CCVAdminTestDlg::OnBnClickedOk4)
    ON_BN_CLICKED(IDOK5, &CCVAdminTestDlg::OnBnClickedOk5)
    ON_BN_CLICKED(IDC_BUTTON1, &CCVAdminTestDlg::OnBnClickedButton1)
    ON_BN_CLICKED(IDOK6, &CCVAdminTestDlg::OnBnClickedOk6)
    ON_BN_CLICKED(IDOK7, &CCVAdminTestDlg::OnBnClickedOk7)
    ON_BN_CLICKED(IDOK8, &CCVAdminTestDlg::OnBnClickedOk8)
    ON_BN_CLICKED(IDOK9, &CCVAdminTestDlg::OnBnClickedOk9)
    ON_BN_CLICKED(IDOK10, &CCVAdminTestDlg::OnBnClickedOk10)
    ON_WM_TIMER()
    ON_BN_CLICKED(IDOK11, &CCVAdminTestDlg::OnBnClickedOk11)
    ON_BN_CLICKED(IDOK12, &CCVAdminTestDlg::OnBnClickedOk12)
    ON_BN_CLICKED(IDOK13, &CCVAdminTestDlg::OnBnClickedOk13)
    ON_BN_CLICKED(IDOK14, &CCVAdminTestDlg::OnBnClickedOk14)
    ON_BN_CLICKED(IDOK15, &CCVAdminTestDlg::OnBnClickedOk15)
    ON_CBN_SELCHANGE(IDC_COMBO1, &CCVAdminTestDlg::OnLangChange)
END_MESSAGE_MAP()


// CCVAdminTestDlg 消息处理程序

BOOL CCVAdminTestDlg::OnInitDialog()
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
    hIcon = AfxGetApp()->LoadIcon(IDI_POC);

    char buf[100] = {0};
    ExePath = GetExePath() + "CVAdminMaker.ini";
    GetPrivateProfileString("CVAdminManager", "POC", NULL, buf, sizeof(buf), ExePath);
    SetDlgItemText(IDC_EDIT1, buf);

    //判断本机是否存在超级用户
    BOOL b = ExistCVAdmin(User_Name.GetBuffer());
    User_Name.ReleaseBuffer();
    if (b == FALSE)//不存在就自动创建
    {
        BOOL b = CreateCVAdmin(User_Name.GetBuffer(), Password.GetBuffer());
        User_Name.ReleaseBuffer();
        Password.ReleaseBuffer();
    }

    //获取当前的会话数
    //int Cnt = GetWinXPUserSessionCount();

    //设置语言下拉框内容
    m_LangList.AddString("中文");
    m_LangList.AddString("English");
    m_LangList.SetCurSel(0);

    //显示默认的语言
    m_BlankPwSet.GetWindowRect(BlankPwSetCtrl);
    ScreenToClient(BlankPwSetCtrl);
    OnLangChange();

    return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCVAdminTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCVAdminTestDlg::OnPaint()
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
HCURSOR CCVAdminTestDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

BOOL CCVAdminTestDlg::ConnIPC (char *RemoteName,
                               char *RemoteUser, char *RemotePass)
{
    NETRESOURCE nr;
    char RN[50] = "\\\\";

    strncat_s(RN, RemoteName, strlen(RemoteName));
    strcat_s(RN, "\\IPC$");

    nr.dwType = RESOURCETYPE_ANY;
    nr.lpLocalName = NULL;
    nr.lpRemoteName = RN;
    nr.lpProvider = NULL;

    int ret = WNetAddConnection2(&nr, RemotePass, RemoteUser, FALSE);
    if (ret == ERROR_SESSION_CREDENTIAL_CONFLICT || ret == 0)
    {
        return TRUE;
    }
    else
        return FALSE;

    return FALSE;
}

BOOL CCVAdminTestDlg::DisIpcConnect (char *RemoteName)
{
    char RN[50] = "\\\\";

    strncat_s(RN, RemoteName, sizeof(RN) - 11);
    strcat_s(RN, "\\C$\\");

    DWORD ret = WNetCancelConnection2(RN, CONNECT_UPDATE_PROFILE, TRUE);

    if (ret == 0)
        return TRUE;
    else
        return FALSE;
}

void CCVAdminTestDlg::OnBnClickedCancel()
{
    // TODO: 在此添加控件通知处理程序代码
    if (RunFlag)
    {
        RunFlag = FALSE;
        WaitForSingleObject(ConnectThreadEvent, 200);
    }

    OnCancel();
}

void CCVAdminTestDlg::OnBnClickedOk2()
{
    // TODO: 在此添加控件通知处理程序代码
    SetMsg("Find CoreView$...", TRUE);

    BOOL b = ExistCVAdmin(User_Name.GetBuffer());
    User_Name.ReleaseBuffer();

    if (b)
    {
        //MessageBox("超级用户存在", "结果：");
        SetMsg("Success.", FALSE);
    }
    else
    {
        //MessageBox("超级用户不存在", "结果：");
        SetMsg("Failed.", FALSE);
    }
}

void CCVAdminTestDlg::OnBnClickedOk3()
{
    // TODO: 在此添加控件通知处理程序代码
    SetMsg("Create CoreView$...", TRUE);

    BOOL b = CreateCVAdmin(User_Name.GetBuffer(), Password.GetBuffer());
    User_Name.ReleaseBuffer();
    Password.ReleaseBuffer();
    if (b)
    {
        //MessageBox("产生超级用户成功", "结果：");
        SetMsg("Success.", FALSE);
    }
    else
    {
        //MessageBox("产生超级用户失败", "结果：");
        SetMsg("Failed.", FALSE);
    }
}

void CCVAdminTestDlg::OnBnClickedOk4()
{
    // TODO: 在此添加控件通知处理程序代码
    SetMsg("Delete CoreView$...", TRUE);

    GetDlgItemText(IDC_EDIT1, POCName);

    BOOL b = DeleteCVAdmin(User_Name.GetBuffer());
    User_Name.ReleaseBuffer();
    DisIpcConnect(POCName.GetBuffer());
    POCName.ReleaseBuffer();
    if (b)
    {
        //MessageBox("删除超级用户成功", "结果：");
        SetMsg("Success.", FALSE);
    }
    else
    {
        //MessageBox("删除超级用户失败", "结果：");
        SetMsg("Failed.", FALSE);
    }
}

void CCVAdminTestDlg::OnBnClickedOk()
{
    // TODO: 在此添加控件通知处理程序代码
    CString Msg;

    GetDlgItemText(IDC_EDIT1, POCName);
    if (POCName.IsEmpty() == TRUE)
    {
        SetMsg("Not Define IP", TRUE);
        return;
    }
    Msg.Format("Access %s Test...", POCName);
    SetMsg(Msg, TRUE);

    AfxBeginThread((AFX_THREADPROC) HostConnectProcess, this);
}

void CCVAdminTestDlg::HostTest()
{
    BOOL b = FALSE;
    CString Msg;
    CString FileName, DstName;
    static int Count = 0;
    char Name[30] = {0};
    char PW[64] = {0};
    int iRet = 0;

    WritePrivateProfileString("CVAdminManager", "POC", POCName, ExePath);

    GetCVAdminInfo(Name, sizeof(Name), PW, sizeof(PW));
    b = CVConnIPC(POCName.GetBuffer());
    if (b)
    {
        //SetDlgItemText(IDC_STATIC5, "远程机器链接：成功");
        SetMsg("Remote Access Success.");
    }
    else
    {
        iRet = GetLastError();
        //SetDlgItemText(IDC_STATIC5, "远程机器链接：失败");
        SetMsg("Remote Access Failed.");
    }

    //CVDisConnIPC(POCName.GetBuffer());
    //POCName.ReleaseBuffer();

    b = CVConnDriver(POCName, "C");
    if (b)
    {
        //SetDlgItemText(IDC_STATIC6, "远程C盘链接：成功");
        SetMsg("Remote C$ Access Success.");
    }
    else
    {
        iRet = GetLastError();
        //SetDlgItemText(IDC_STATIC6, "远程C盘链接：失败");
        SetMsg("Remote C$ Access Failed.");
    }

    T_DiskInfo DiskInfo;
    char Driver[256] = {0};
    sprintf_s(Driver, sizeof(Driver), "\\\\%s\\C$\\", POCName);
    GetDiskInfo(Driver, DiskInfo);

    FileName.Format("\\\\%s\\C$\\test", POCName);
    CFile f;
    b = f.Open(FileName, CFile::modeReadWrite);
    if (b)
    {
        f.Close();
        //SetDlgItemText(IDC_STATIC4, "远程机器文件操作：成功");
        SetMsg("Remote File Access Success.");
    }
    else
    {
        int iRet = 0;
        iRet = GetLastError();
        //SetDlgItemText(IDC_STATIC4, "远程机器文件操作：失败");
        SetMsg("Remote File Access Failed.");
    }

    CString s;
    s.Format("C: Total Size:%d G", DiskInfo.TotalBytes / (1024 * 1024 * 1024));
    //SetDlgItemText(IDC_STATIC2, s);
    SetMsg(s);
    s.Format("C: Free Space:%d G", DiskInfo.FreeBytes / (1024 * 1024 * 1024));
    //SetDlgItemText(IDC_STATIC3, s);
    SetMsg(s);

    SetMsg("Test Finish.");

    //CVDisConnDriver(POCName, "C");
}

void CCVAdminTestDlg::OnBnClickedOk5()
{
    char Name[100] = {0};
    CString s;

    SetMsg("Get Current User Name...", TRUE);
    CVGetCurUserName(Name, 100);
    //SetDlgItemText(IDC_EDIT2, Name);
    s.Format("User Name：%s", Name);
    SetMsg(s, FALSE);
}

/*
=======================================================================================================================
获取在线POC列表
=======================================================================================================================
*/
//void CCVAdminTestDlg::GetPOCNameList(OUT vector<PocNetSts> &NameList)
//{
//	int				Count = 0;
//	CString			IP[2];
//	BOOL			ret1 = FALSE;
//	BOOL			ret2 = FALSE;
//	POCInfoOnline * pPocList = NULL;
//	CString			Message;
//	int				POCCnt = 0;
//	CStringArray	DisConnetPOCList;
//	CString			POCName;
//	BOOL			b1 = FALSE, b2 = FALSE;
//
//	m_List.DeleteAllItems();
//	NameList.clear();
//	SetDlgItemText(IDC_OK, "正常：0 台");
//	SetDlgItemText(IDC_ERR, "异常：0 台");
//
//	Count = GetPOCCount();
//	if (Count > 0)
//	{
//		Message.Format("注册POC总数：%d 台", Count);
//		SetDlgItemText(IDC_TOTAL, Message);
//		pPocList = new POCInfoOnline[Count];
//		memset(pPocList, 0, sizeof(POCInfoOnline) * Count);
//
//		GetPOCInfoList(pPocList);
//
//		time_t t1 = GetTickCount();
//		for(int i = 0; i < Count; i++)
//		{
//			POCName = pPocList[i].POCName;
//
//			IP[0] = GetIP(pPocList[i].LanboxIP);
//			IP[1] = GetIP(pPocList[i].EtherIP1);
//			ret1 = Ping(IP[0], 5);
//			ret2 = Ping(IP[1], 5);
//			m_List.InsertItem(i, pPocList[i].POCName, 0);
//			m_List.EnsureVisible(i, TRUE);
//
//			if (ret1 == TRUE)
//			{
//				m_List.SetItemText(i, 1, "成功");
//			}
//			else
//			{
//				m_List.SetItemText(i, 1, "失败");
//			}
//
//			if (ret2 == TRUE)
//			{
//				m_List.SetItemText(i, 2, "成功");
//			}
//			else
//			{
//				m_List.SetItemText(i, 2, "失败");
//			}
//
//			b1 = FALSE;
//			if (ret1)
//			{
//				b1 = CVConnDriver(IP[0].GetBuffer(), "C");
//				IP[0].ReleaseBuffer();
//			}
//			if (b1 == TRUE)
//			{
//				m_List.SetItemText(i, 3, "成功");
//			}
//			else
//			{
//				m_List.SetItemText(i, 3, "失败");
//			}
//
//			b2 = FALSE;
//			if (ret2)
//			{
//				b2 = CVConnDriver(IP[1].GetBuffer(), "C");
//				IP[1].ReleaseBuffer();
//			}
//			if (b2 == TRUE)
//			{
//				m_List.SetItemText(i, 4, "成功");
//			}
//			else
//			{
//				m_List.SetItemText(i, 4, "失败");
//			}
//
//			char Driver[256] = "";
//			T_DiskInfo DiskInfo;
//			memset(&DiskInfo, 0, sizeof(T_DiskInfo));
//			if (b1 || b2)
//			{
//				if (b1)
//				{
//					sprintf_s(Driver, sizeof(Driver), "\\\\%s\\C$\\", IP[0]);
//				}
//				if (b2)
//				{
//					sprintf_s(Driver, sizeof(Driver), "\\\\%s\\C$\\", IP[1]);
//				}
//				GetDiskInfo(Driver, DiskInfo);
//			}
//
//			CString s;
//			s.Format("%d", DiskInfo.TotalBytes / (1024 * 1024 * 1024));
//			m_List.SetItemText(i, 5, s);
//			s.Format("%d", DiskInfo.FreeBytes / (1024 * 1024 * 1024));
//			m_List.SetItemText(i, 6, s);
//
//			int pos = int(FLOAT(i + 1) / Count * 100);
//			m_Progress.SetPos(pos);
//			s.Format("%d%%", pos);
//			SetDlgItemText(IDC_100, s);
//
//			if (b1 || b2)
//			{
//				POCCnt++;
//			}
//			else
//			{
//				DisConnetPOCList.Add(pPocList[i].POCName);
//			}
//		}
//		delete[] pPocList;
//
//		time_t t2 = GetTickCount();
//
//		Message.Format("耗时: %d 毫秒\n", t2 - t1);
//		SetDlgItemText(IDC_ERR2, Message);
//
//		Message.Format("正常：%d 台", POCCnt);
//		SetDlgItemText(IDC_OK, Message);
//
//		POCCnt = (int)DisConnetPOCList.GetCount();
//		Message.Format("异常：%d 台", POCCnt);
//		SetDlgItemText(IDC_ERR, Message);
//	}
//
//	return;
//}
//
/*
=======================================================================================================================
PING给定的机器，先尝试网1，再尝试网2，如果两个网都不通则认为脱网
=======================================================================================================================
*/
//int CCVAdminTestDlg::PingHost(CString IP1, CString IP2)
//{
//	BOOL ret = FALSE;
//
//	ret = Ping(IP2, 5);
//	if (ret)
//	{
//		return 2;
//	}
//	else
//	{
//		ret = Ping(IP1, 5);
//		if (ret)
//		{
//			return 1;
//		}
//	}
//
//	return 0;
//}

void CCVAdminTestDlg::OnBnClickedButton1()
{
    // TODO: 在此添加控件通知处理程序代码
    AfxBeginThread((AFX_THREADPROC) PocListProcess, this);
}

void CCVAdminTestDlg::OnBnClickedOk6()
{
    // TODO: 在此添加控件通知处理程序代码
    AfxBeginThread((AFX_THREADPROC) ConnectProcess, this);
}

void CCVAdminTestDlg::OnBnClickedOk7()
{
    // TODO: 在此添加控件通知处理程序代码
    RunFlag = FALSE;
}

CString CCVAdminTestDlg::GetExePath()
{
    /*~~~~~~~~~~~~*/
    CString PathStr;
    /*~~~~~~~~~~~~*/

    GetModuleFileName(NULL, PathStr.GetBuffer(MAX_PATH), MAX_PATH);
    PathStr.ReleaseBuffer();

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    int Pos = PathStr.ReverseFind('\\');
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    if(Pos != -1)
        PathStr = PathStr.Left(Pos + 1);
    else
        PathStr.Empty();

    return PathStr;
}

CString CCVAdminTestDlg::GetTimeStr()
{
    CString s;
    SYSTEMTIME MyTime;
    GetLocalTime(&MyTime);
    s.Format("%d/%02d/%02d %02d:%02d:%02d.%03d", MyTime.wYear, MyTime.wMonth, MyTime.wDay, MyTime.wHour, MyTime.wMinute, MyTime.wSecond, MyTime.wMilliseconds);

    return s;
}

void CCVAdminTestDlg::SetMsg(CString Text, BOOL Reset)
{
    if (Reset)
    {
        m_MsgList.ResetContent();
    }

    CString rTime = GetTimeStr();

    Text = rTime + " " + Text;
    m_MsgList.AddString(Text);
    int Cnt = m_MsgList.GetCount();
    m_MsgList.SetTopIndex(Cnt - 1);

    theApp.Log.Write(Text);
}

void CCVAdminTestDlg::ConnectProcessFun()
{
    BOOL b = FALSE;
    CString Msg;
    CString FileName, DstName;
    static int Count = 0;
    char Name[30] = {0};
    char PW[64] = {0};
    int iRet = 0;
    int OKCnt = 0, ErrCnt = 0;

    GetDlgItemText(IDC_EDIT1, POCName);
    WritePrivateProfileString("CVAdminManager", "POC", POCName, ExePath);

    GetCVAdminInfo(Name, sizeof(Name), PW, sizeof(PW));

    RunFlag = TRUE;
    while (RunFlag)
    {
        b = CVConnDriver(POCName, "C");
        if (b <= 0)
        {
            TRACE("错误码：%d\n", b);
            ErrCnt++;
            Msg.Format("Loop Test OK：%d，Error：%d", OKCnt, ErrCnt);
            SetMsg(Msg, TRUE);
        }
        else
        {
            OKCnt++;
            Msg.Format("Loop Test OK：%d，Error：%d", OKCnt, ErrCnt);
            SetMsg(Msg, TRUE);
        }
        Sleep(1);
    }
}

void CCVAdminTestDlg::OnBnClickedOk8()
{
    // TODO: 在此添加控件通知处理程序代码
    int Cnt = GetWinXPUserSessionCount();

    CString Msg;
    Msg.Format("Current Session：%d", Cnt);
    SetMsg(Msg, TRUE);

    //Session List[16];
    //memset(&List, 0, sizeof(List));
    //Cnt = GetSession(List);
}

void CCVAdminTestDlg::OnBnClickedOk9()
{
    // TODO: 在此添加控件通知处理程序代码
    SetTimer(1, 5000, NULL);
    OnBnClickedOk8();
}

void CCVAdminTestDlg::OnBnClickedOk10()
{
    // TODO: 在此添加控件通知处理程序代码
    KillTimer(1);
}

void CCVAdminTestDlg::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    TRACE("OnTimer处理\n");
    OnBnClickedOk8();
    CDialog::OnTimer(nIDEvent);
}

void CCVAdminTestDlg::OnBnClickedOk11()
{
    // TODO: Add your control notification handler code here
    SetMsg("Disable Sample File Share Mode...", TRUE);
    int Ret = DisableSampleFileShareMode();
    if (Ret == 0)//成功
    {
        SetMsg("Success.", FALSE);
    }
    else//失败
    {
        SetMsg("Failed.", FALSE);
    }
}

void CCVAdminTestDlg::OnBnClickedOk12()
{
    // TODO: Add your control notification handler code here
    SetMsg("Enable Remote Access Use BlankPassword...", TRUE);
    int Ret = EnableRemoteAccessUseBlankPassword();
    if (Ret == 0)//成功
    {
        SetMsg("Success.", FALSE);
    }
    else//失败
    {
        SetMsg("Failed.", FALSE);
    }
}

void CCVAdminTestDlg::OnBnClickedOk13()
{
    // TODO: Add your control notification handler code here
    SetMsg("Set Network Logon User Groups...", TRUE);
    int Ret = SetNetworkLogonUserGroup();
    if (Ret == 0)//成功
    {
        SetMsg("Success.", FALSE);
    }
    else//失败
    {
        SetMsg("Failed.", FALSE);
    }
}

void CCVAdminTestDlg::OnBnClickedOk14()
{
    // TODO: Add your control notification handler code here
    SetMsg("Disable Guest Account...", TRUE);
    int Ret = AccountDisable("Guest");
    if (Ret == 1)//成功
    {
        SetMsg("Success.", FALSE);
    }
    else//失败
    {
        SetMsg("Failed.", FALSE);
    }
}

void CCVAdminTestDlg::OnBnClickedOk15()
{
    // TODO: Add your control notification handler code here
    SetMsg("Deny Network Logon User Groups...", TRUE);
    int Ret = SetDenyNetworkLogonUserGroup();
    if (Ret == 0)//成功
    {
        SetMsg("Success.", FALSE);
    }
    else//失败
    {
        SetMsg("Failed.", FALSE);
    }
}

//界面语言变更
void CCVAdminTestDlg::OnLangChange()
{
    // TODO: 在此添加控件通知处理程序代码
    int CurLang = m_LangList.GetCurSel();
    switch (CurLang)
    {
    case 0://显示中文
        Chinese();
        break;
    case 1://显示英文
        English();
        break;
    default:
        break;
    }
}

void CCVAdminTestDlg::Chinese()
{
    //账户管理组处理
    SetDlgItemText(IDC_STATIC1, "账户管理");
    SetDlgItemText(IDOK2, "查找CoreView超级用户");
    SetDlgItemText(IDOK3, "产生CoreView超级用户");
    SetDlgItemText(IDOK4, "删除CoreView超级用户");
    SetDlgItemText(IDOK5, "获取当前登录的用户名");
    SetDlgItemText(IDOK14, "禁用Guest账户");

    //远程链接测试组处理
    SetDlgItemText(IDC_STATIC2, "远程链接测试");
    SetDlgItemText(IDC_STATIC6, "远程机器名称/IP");
    SetDlgItemText(IDOK, "单机链接测试");
    SetDlgItemText(IDOK6, "循环链接C$测试");
    SetDlgItemText(IDOK7, "循环停止");

    //会话组处理
    SetDlgItemText(IDC_STATIC3, "会话");
    SetDlgItemText(IDOK8, "获取本机会话数");
    SetDlgItemText(IDOK9, "循环测试(5s)");
    SetDlgItemText(IDOK10, "循环停止");

    //网络组处理...
    SetDlgItemText(IDC_STATIC4, "网络");
    SetDlgItemText(IDOK11, "禁用XP简单文件共享");

    SetDlgItemText(IDOK12, "允许远程空密码访问");
    //将控件的大小调整一下，目的是在中文环境下更美观
    CRect RefCtrl, NewCtrl;
    NewCtrl = BlankPwSetCtrl;
    GetDlgItem(IDOK11)->GetWindowRect(RefCtrl);
    ScreenToClient(RefCtrl);
    NewCtrl.right = NewCtrl.left + RefCtrl.Width();
    NewCtrl.bottom = NewCtrl.top + RefCtrl.Height();
    m_BlankPwSet.MoveWindow(NewCtrl);

    SetDlgItemText(IDOK13, "远程访问允许账号组设定");
    SetDlgItemText(IDOK15, "远程访问禁止账号组设定");

    //过程信息组处理
    SetDlgItemText(IDC_STATIC8, "过程信息");

    //其它
    SetDlgItemText(IDC_STATIC5, "界面语言");
    SetDlgItemText(IDCANCEL, "关闭");
}

void CCVAdminTestDlg::English()
{
    //账户管理组处理
    SetDlgItemText(IDC_STATIC1, "Account Management");
    SetDlgItemText(IDOK2, "Find CoreView$");
    SetDlgItemText(IDOK3, "Create CoreView$");
    SetDlgItemText(IDOK4, "Delete CoreView$");
    SetDlgItemText(IDOK5, "Get Current User Name");
    SetDlgItemText(IDOK14, "Guest Account Disable");

    //远程链接测试组处理
    SetDlgItemText(IDC_STATIC2, "Remote Test");
    SetDlgItemText(IDC_STATIC6, "Remote Host/IP");
    SetDlgItemText(IDOK, "Access");
    SetDlgItemText(IDOK6, "Loop C$ Access");
    SetDlgItemText(IDOK7, "Loop Stop");

    //会话组处理
    SetDlgItemText(IDC_STATIC3, "Session");
    SetDlgItemText(IDOK8, "Get Session Count");
    SetDlgItemText(IDOK9, "Loop(5s)");
    SetDlgItemText(IDOK10, "Loop Stop");

    //网络组处理
    SetDlgItemText(IDC_STATIC4, "Network");
    SetDlgItemText(IDOK11, "Disable Sample File Share");
    //英文环境时扩大按钮的大小，目的是显示全所有英文单词
    m_BlankPwSet.MoveWindow(BlankPwSetCtrl);
    SetDlgItemText(IDOK12, "Enable Remote BlankPassword Access");
    SetDlgItemText(IDOK13, "Set Network Logon Groups");
    SetDlgItemText(IDOK15, "Deny Network Logon Groups");

    //过程信息组处理
    SetDlgItemText(IDC_STATIC8, "Process Info:");

    //其它
    SetDlgItemText(IDC_STATIC5, "Language");
    SetDlgItemText(IDCANCEL, "Close");
}
