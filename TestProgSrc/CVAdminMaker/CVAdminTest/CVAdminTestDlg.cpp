// CVAdminTestDlg.cpp : ʵ���ļ�
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

//�������Ӳ���
unsigned HostConnectProcess(void *pParam)
{
    CCVAdminTestDlg	*p = (CCVAdminTestDlg *) pParam;
    p->HostTest();

    return 2;
}

//ѭ�����Ӳ���
unsigned ConnectProcess(void *pParam)
{
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    CCVAdminTestDlg	*p = (CCVAdminTestDlg *) pParam;
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    p->ConnectThreadEvent = CreateEvent(NULL, FALSE, FALSE, "ConnectProcessFun");
    p->ConnectProcessFun();

    TRACE("ConnectProcessFun��������\n");
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
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

// CCVAdminTestDlg �Ի���

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


// CCVAdminTestDlg ��Ϣ�������

BOOL CCVAdminTestDlg::OnInitDialog()
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
    hIcon = AfxGetApp()->LoadIcon(IDI_POC);

    char buf[100] = {0};
    ExePath = GetExePath() + "CVAdminMaker.ini";
    GetPrivateProfileString("CVAdminManager", "POC", NULL, buf, sizeof(buf), ExePath);
    SetDlgItemText(IDC_EDIT1, buf);

    //�жϱ����Ƿ���ڳ����û�
    BOOL b = ExistCVAdmin(User_Name.GetBuffer());
    User_Name.ReleaseBuffer();
    if (b == FALSE)//�����ھ��Զ�����
    {
        BOOL b = CreateCVAdmin(User_Name.GetBuffer(), Password.GetBuffer());
        User_Name.ReleaseBuffer();
        Password.ReleaseBuffer();
    }

    //��ȡ��ǰ�ĻỰ��
    //int Cnt = GetWinXPUserSessionCount();

    //������������������
    m_LangList.AddString("����");
    m_LangList.AddString("English");
    m_LangList.SetCurSel(0);

    //��ʾĬ�ϵ�����
    m_BlankPwSet.GetWindowRect(BlankPwSetCtrl);
    ScreenToClient(BlankPwSetCtrl);
    OnLangChange();

    return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCVAdminTestDlg::OnPaint()
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
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    if (RunFlag)
    {
        RunFlag = FALSE;
        WaitForSingleObject(ConnectThreadEvent, 200);
    }

    OnCancel();
}

void CCVAdminTestDlg::OnBnClickedOk2()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    SetMsg("Find CoreView$...", TRUE);

    BOOL b = ExistCVAdmin(User_Name.GetBuffer());
    User_Name.ReleaseBuffer();

    if (b)
    {
        //MessageBox("�����û�����", "�����");
        SetMsg("Success.", FALSE);
    }
    else
    {
        //MessageBox("�����û�������", "�����");
        SetMsg("Failed.", FALSE);
    }
}

void CCVAdminTestDlg::OnBnClickedOk3()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    SetMsg("Create CoreView$...", TRUE);

    BOOL b = CreateCVAdmin(User_Name.GetBuffer(), Password.GetBuffer());
    User_Name.ReleaseBuffer();
    Password.ReleaseBuffer();
    if (b)
    {
        //MessageBox("���������û��ɹ�", "�����");
        SetMsg("Success.", FALSE);
    }
    else
    {
        //MessageBox("���������û�ʧ��", "�����");
        SetMsg("Failed.", FALSE);
    }
}

void CCVAdminTestDlg::OnBnClickedOk4()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    SetMsg("Delete CoreView$...", TRUE);

    GetDlgItemText(IDC_EDIT1, POCName);

    BOOL b = DeleteCVAdmin(User_Name.GetBuffer());
    User_Name.ReleaseBuffer();
    DisIpcConnect(POCName.GetBuffer());
    POCName.ReleaseBuffer();
    if (b)
    {
        //MessageBox("ɾ�������û��ɹ�", "�����");
        SetMsg("Success.", FALSE);
    }
    else
    {
        //MessageBox("ɾ�������û�ʧ��", "�����");
        SetMsg("Failed.", FALSE);
    }
}

void CCVAdminTestDlg::OnBnClickedOk()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
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
        //SetDlgItemText(IDC_STATIC5, "Զ�̻������ӣ��ɹ�");
        SetMsg("Remote Access Success.");
    }
    else
    {
        iRet = GetLastError();
        //SetDlgItemText(IDC_STATIC5, "Զ�̻������ӣ�ʧ��");
        SetMsg("Remote Access Failed.");
    }

    //CVDisConnIPC(POCName.GetBuffer());
    //POCName.ReleaseBuffer();

    b = CVConnDriver(POCName, "C");
    if (b)
    {
        //SetDlgItemText(IDC_STATIC6, "Զ��C�����ӣ��ɹ�");
        SetMsg("Remote C$ Access Success.");
    }
    else
    {
        iRet = GetLastError();
        //SetDlgItemText(IDC_STATIC6, "Զ��C�����ӣ�ʧ��");
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
        //SetDlgItemText(IDC_STATIC4, "Զ�̻����ļ��������ɹ�");
        SetMsg("Remote File Access Success.");
    }
    else
    {
        int iRet = 0;
        iRet = GetLastError();
        //SetDlgItemText(IDC_STATIC4, "Զ�̻����ļ�������ʧ��");
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
    s.Format("User Name��%s", Name);
    SetMsg(s, FALSE);
}

/*
=======================================================================================================================
��ȡ����POC�б�
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
//	SetDlgItemText(IDC_OK, "������0 ̨");
//	SetDlgItemText(IDC_ERR, "�쳣��0 ̨");
//
//	Count = GetPOCCount();
//	if (Count > 0)
//	{
//		Message.Format("ע��POC������%d ̨", Count);
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
//				m_List.SetItemText(i, 1, "�ɹ�");
//			}
//			else
//			{
//				m_List.SetItemText(i, 1, "ʧ��");
//			}
//
//			if (ret2 == TRUE)
//			{
//				m_List.SetItemText(i, 2, "�ɹ�");
//			}
//			else
//			{
//				m_List.SetItemText(i, 2, "ʧ��");
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
//				m_List.SetItemText(i, 3, "�ɹ�");
//			}
//			else
//			{
//				m_List.SetItemText(i, 3, "ʧ��");
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
//				m_List.SetItemText(i, 4, "�ɹ�");
//			}
//			else
//			{
//				m_List.SetItemText(i, 4, "ʧ��");
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
//		Message.Format("��ʱ: %d ����\n", t2 - t1);
//		SetDlgItemText(IDC_ERR2, Message);
//
//		Message.Format("������%d ̨", POCCnt);
//		SetDlgItemText(IDC_OK, Message);
//
//		POCCnt = (int)DisConnetPOCList.GetCount();
//		Message.Format("�쳣��%d ̨", POCCnt);
//		SetDlgItemText(IDC_ERR, Message);
//	}
//
//	return;
//}
//
/*
=======================================================================================================================
PING�����Ļ������ȳ�����1���ٳ�����2���������������ͨ����Ϊ����
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
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    AfxBeginThread((AFX_THREADPROC) PocListProcess, this);
}

void CCVAdminTestDlg::OnBnClickedOk6()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    AfxBeginThread((AFX_THREADPROC) ConnectProcess, this);
}

void CCVAdminTestDlg::OnBnClickedOk7()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
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
            TRACE("�����룺%d\n", b);
            ErrCnt++;
            Msg.Format("Loop Test OK��%d��Error��%d", OKCnt, ErrCnt);
            SetMsg(Msg, TRUE);
        }
        else
        {
            OKCnt++;
            Msg.Format("Loop Test OK��%d��Error��%d", OKCnt, ErrCnt);
            SetMsg(Msg, TRUE);
        }
        Sleep(1);
    }
}

void CCVAdminTestDlg::OnBnClickedOk8()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    int Cnt = GetWinXPUserSessionCount();

    CString Msg;
    Msg.Format("Current Session��%d", Cnt);
    SetMsg(Msg, TRUE);

    //Session List[16];
    //memset(&List, 0, sizeof(List));
    //Cnt = GetSession(List);
}

void CCVAdminTestDlg::OnBnClickedOk9()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    SetTimer(1, 5000, NULL);
    OnBnClickedOk8();
}

void CCVAdminTestDlg::OnBnClickedOk10()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    KillTimer(1);
}

void CCVAdminTestDlg::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    TRACE("OnTimer����\n");
    OnBnClickedOk8();
    CDialog::OnTimer(nIDEvent);
}

void CCVAdminTestDlg::OnBnClickedOk11()
{
    // TODO: Add your control notification handler code here
    SetMsg("Disable Sample File Share Mode...", TRUE);
    int Ret = DisableSampleFileShareMode();
    if (Ret == 0)//�ɹ�
    {
        SetMsg("Success.", FALSE);
    }
    else//ʧ��
    {
        SetMsg("Failed.", FALSE);
    }
}

void CCVAdminTestDlg::OnBnClickedOk12()
{
    // TODO: Add your control notification handler code here
    SetMsg("Enable Remote Access Use BlankPassword...", TRUE);
    int Ret = EnableRemoteAccessUseBlankPassword();
    if (Ret == 0)//�ɹ�
    {
        SetMsg("Success.", FALSE);
    }
    else//ʧ��
    {
        SetMsg("Failed.", FALSE);
    }
}

void CCVAdminTestDlg::OnBnClickedOk13()
{
    // TODO: Add your control notification handler code here
    SetMsg("Set Network Logon User Groups...", TRUE);
    int Ret = SetNetworkLogonUserGroup();
    if (Ret == 0)//�ɹ�
    {
        SetMsg("Success.", FALSE);
    }
    else//ʧ��
    {
        SetMsg("Failed.", FALSE);
    }
}

void CCVAdminTestDlg::OnBnClickedOk14()
{
    // TODO: Add your control notification handler code here
    SetMsg("Disable Guest Account...", TRUE);
    int Ret = AccountDisable("Guest");
    if (Ret == 1)//�ɹ�
    {
        SetMsg("Success.", FALSE);
    }
    else//ʧ��
    {
        SetMsg("Failed.", FALSE);
    }
}

void CCVAdminTestDlg::OnBnClickedOk15()
{
    // TODO: Add your control notification handler code here
    SetMsg("Deny Network Logon User Groups...", TRUE);
    int Ret = SetDenyNetworkLogonUserGroup();
    if (Ret == 0)//�ɹ�
    {
        SetMsg("Success.", FALSE);
    }
    else//ʧ��
    {
        SetMsg("Failed.", FALSE);
    }
}

//�������Ա��
void CCVAdminTestDlg::OnLangChange()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    int CurLang = m_LangList.GetCurSel();
    switch (CurLang)
    {
    case 0://��ʾ����
        Chinese();
        break;
    case 1://��ʾӢ��
        English();
        break;
    default:
        break;
    }
}

void CCVAdminTestDlg::Chinese()
{
    //�˻������鴦��
    SetDlgItemText(IDC_STATIC1, "�˻�����");
    SetDlgItemText(IDOK2, "����CoreView�����û�");
    SetDlgItemText(IDOK3, "����CoreView�����û�");
    SetDlgItemText(IDOK4, "ɾ��CoreView�����û�");
    SetDlgItemText(IDOK5, "��ȡ��ǰ��¼���û���");
    SetDlgItemText(IDOK14, "����Guest�˻�");

    //Զ�����Ӳ����鴦��
    SetDlgItemText(IDC_STATIC2, "Զ�����Ӳ���");
    SetDlgItemText(IDC_STATIC6, "Զ�̻�������/IP");
    SetDlgItemText(IDOK, "�������Ӳ���");
    SetDlgItemText(IDOK6, "ѭ������C$����");
    SetDlgItemText(IDOK7, "ѭ��ֹͣ");

    //�Ự�鴦��
    SetDlgItemText(IDC_STATIC3, "�Ự");
    SetDlgItemText(IDOK8, "��ȡ�����Ự��");
    SetDlgItemText(IDOK9, "ѭ������(5s)");
    SetDlgItemText(IDOK10, "ѭ��ֹͣ");

    //�����鴦��...
    SetDlgItemText(IDC_STATIC4, "����");
    SetDlgItemText(IDOK11, "����XP���ļ�����");

    SetDlgItemText(IDOK12, "����Զ�̿��������");
    //���ؼ��Ĵ�С����һ�£�Ŀ���������Ļ����¸�����
    CRect RefCtrl, NewCtrl;
    NewCtrl = BlankPwSetCtrl;
    GetDlgItem(IDOK11)->GetWindowRect(RefCtrl);
    ScreenToClient(RefCtrl);
    NewCtrl.right = NewCtrl.left + RefCtrl.Width();
    NewCtrl.bottom = NewCtrl.top + RefCtrl.Height();
    m_BlankPwSet.MoveWindow(NewCtrl);

    SetDlgItemText(IDOK13, "Զ�̷��������˺����趨");
    SetDlgItemText(IDOK15, "Զ�̷��ʽ�ֹ�˺����趨");

    //������Ϣ�鴦��
    SetDlgItemText(IDC_STATIC8, "������Ϣ");

    //����
    SetDlgItemText(IDC_STATIC5, "��������");
    SetDlgItemText(IDCANCEL, "�ر�");
}

void CCVAdminTestDlg::English()
{
    //�˻������鴦��
    SetDlgItemText(IDC_STATIC1, "Account Management");
    SetDlgItemText(IDOK2, "Find CoreView$");
    SetDlgItemText(IDOK3, "Create CoreView$");
    SetDlgItemText(IDOK4, "Delete CoreView$");
    SetDlgItemText(IDOK5, "Get Current User Name");
    SetDlgItemText(IDOK14, "Guest Account Disable");

    //Զ�����Ӳ����鴦��
    SetDlgItemText(IDC_STATIC2, "Remote Test");
    SetDlgItemText(IDC_STATIC6, "Remote Host/IP");
    SetDlgItemText(IDOK, "Access");
    SetDlgItemText(IDOK6, "Loop C$ Access");
    SetDlgItemText(IDOK7, "Loop Stop");

    //�Ự�鴦��
    SetDlgItemText(IDC_STATIC3, "Session");
    SetDlgItemText(IDOK8, "Get Session Count");
    SetDlgItemText(IDOK9, "Loop(5s)");
    SetDlgItemText(IDOK10, "Loop Stop");

    //�����鴦��
    SetDlgItemText(IDC_STATIC4, "Network");
    SetDlgItemText(IDOK11, "Disable Sample File Share");
    //Ӣ�Ļ���ʱ����ť�Ĵ�С��Ŀ������ʾȫ����Ӣ�ĵ���
    m_BlankPwSet.MoveWindow(BlankPwSetCtrl);
    SetDlgItemText(IDOK12, "Enable Remote BlankPassword Access");
    SetDlgItemText(IDOK13, "Set Network Logon Groups");
    SetDlgItemText(IDOK15, "Deny Network Logon Groups");

    //������Ϣ�鴦��
    SetDlgItemText(IDC_STATIC8, "Process Info:");

    //����
    SetDlgItemText(IDC_STATIC5, "Language");
    SetDlgItemText(IDCANCEL, "Close");
}
