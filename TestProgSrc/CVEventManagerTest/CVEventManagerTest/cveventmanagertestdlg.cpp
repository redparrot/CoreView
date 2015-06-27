// CVEventManagerTestDlg.cpp : ʵ���ļ�
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
#define	WM_OPERKEY_SHOW			6134			//С����ר�ü���������ʾ��Ϣ
#define	WM_OPERKEY_SOUND		6135			//С����ר�ü�������ȷ����Ϣ
#define	WM_OPERKEY_SYS_MSG_SHOW	6136			//ϵͳ��ϢС����ר�ü���������ʾ��Ϣ
#define WM_TOOLMANAGE_NOTIFY_MSG	WM_USER + 4044 //��ToolManage������Ϣ֪ͨ�������ڴ��������������ϵͳ,��һ������Ϊ1ʱ��ʾ���������ڴ����Ϊ2ʱ������ϵͳ
#define	WM_OPERKEY_ALL_OK			WM_USER + 5113//ר�ü�����Ϣ--ϵͳ��Ϣȫ��ȷ��
#define WM_MINIMIZE					WM_USER + 111 //�յ���������͵���С����Ϣ��ͨ������CV8��������ʱ��

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

	ret = SpeechSync("���費��,��ͥǰ��������,ȥ������,�������ƾ�����", -1);

	return 0;
}

unsigned VoiceThreadProcess(void* pParam)
{
	int ret = Speech("��������", -1);

	return 0;
}

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


// CCVEventManagerTestDlg �Ի���

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


// CCVEventManagerTestDlg ��Ϣ�������

BOOL CCVEventManagerTestDlg::OnInitDialog()
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
	//SpeechInitialize();

	//OnBnClickedOk43();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCVEventManagerTestDlg::OnPaint()
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
		SetDlgItemText(IDC_STATIC1, "����ͨ����֤");
	}
    else if (ret == -1)
    {
        SetDlgItemText(IDC_STATIC1, "�û�ȡ��");
    }
	else
	{
		SetDlgItemText(IDC_STATIC1, "�������");
	}
}

void CCVEventManagerTestDlg::OnBnClickedOk37()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetTimer(3, 10, NULL);
}

void CCVEventManagerTestDlg::OnBnClickedOk38()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hwnd = ::FindWindow("CVSystemMsg", NULL);

	::SendMessage(hwnd, WM_CLOSE, 0, 0);
}

//����SOE����С����
void CCVEventManagerTestDlg::OnBnClickedOk39()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hwnd = ::FindWindowW(L"CVSoeMsg", L"SOE");

	::SendMessage(hwnd, WM_CLOSE, 0, 0);
}

//���б���С����
void CCVEventManagerTestDlg::OnBnClickedOk41()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(m_hWnd,
		_T("open"), _T("CVAlarmMsg.exe"), "2",
		"C:\\CoreView\\FuncExec\\exe", SW_SHOWNORMAL);
}

void CCVEventManagerTestDlg::OnBnClickedOk42()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hwnd = ::FindWindowW(L"CVAlarmMsg", NULL);
	::SendMessage(hwnd, WM_CLOSE, 0, 0);
}

void CCVEventManagerTestDlg::OnBnClickedOk43()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

	for (int i = 0; i < AlarmMax; i++)//����ģ��ľ�������
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//SetTimer(1, 1000, NULL);
	HWND hWnd = ::FindWindow("CVAlarmMsg", "����");
	::PostMessage(hWnd, WM_ALARM_CHANGE, 0, 0);
}

void CCVEventManagerTestDlg::OnBnClickedOk45()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(m_hWnd,
		_T("open"), _T("CVSystemMsg.exe"), "",
		"C:\\coreview\\SystemExec\\EXE", SW_SHOWNORMAL);
}

void CCVEventManagerTestDlg::OnBnClickedOk46()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hwnd = ::FindWindowW(NULL, L"�¼�����");

	::SendMessage(hwnd, WM_CLOSE, NULL, NULL);
}

void CCVEventManagerTestDlg::OnBnClickedOk47()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(m_hWnd,
		_T("open"), _T("CVEventTrigger.exe"), "",
		"C:\\coreview\\funcexec\\CVEventExec\\EXE", SW_SHOWNORMAL);
}

//��������
void CCVEventManagerTestDlg::OnBnClickedOk48()
{
	AfxBeginThread((AFX_THREADPROC)VoiceThreadProcess, NULL, THREAD_PRIORITY_NORMAL);
}

vector<LONG> List;
vector<LONG>::iterator It;
void CCVEventManagerTestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
		//Msg.Format(_T("Message %d���泤�ޱ�YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY!--15--0"), Count);
		Msg.Format(_T("Message %d���泤�ޱ�YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY!"), Count);
		cpd.cbData = Msg.GetLength() + 1;
		cpd.lpData = Msg.GetBuffer();
		Msg.ReleaseBuffer();

		::SendMessage(hwnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
	}
	CDialog::OnTimer(nIDEvent);
}

void CCVEventManagerTestDlg::OnBnClickedOk49()//ר�ü�����ʾť����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hWnd;

	hWnd = ::FindWindow("CVAlarmMsg", "����");
	::PostMessage(hWnd, WM_OPERKEY_SHOW, 0, 0);
}

void CCVEventManagerTestDlg::OnBnClickedOk50()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hWnd;

	hWnd = ::FindWindow("CVAlarmMsg", "����");
	::PostMessage(hWnd, WM_OPERKEY_SOUND, 0, 0);
}

void CCVEventManagerTestDlg::OnBnClickedOk51()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//Play("C:\\coreview\\funcexec\\CVEventExec\\Configure\\Sound\\tada.wav");
	AfxBeginThread((AFX_THREADPROC)PlayThreadProcess, NULL, THREAD_PRIORITY_NORMAL);
}

void CCVEventManagerTestDlg::OnBnClickedOk52()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Stop(0);
}

void CCVEventManagerTestDlg::OnBnClickedOk53()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char buf[100] = {0};
	int ret = 0;

	AfxBeginThread((AFX_THREADPROC)SyncVoiceThreadProcess, NULL, THREAD_PRIORITY_NORMAL);
	//ret = SpeechSync("���費��,��ͥǰ��������,ȥ������,�������ƾ�����", -1);
	//for (int i = 0; i < 10; i++)
	//{
	//	sprintf_s(buf, sizeof(buf), "��������%d", i + 1);
	//	ret = SpeechSync(buf, 2);
	//}
}

void CCVEventManagerTestDlg::OnBnClickedOk54()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hWnd = NULL;

	hWnd = ::FindWindow("CVAlarmMsg", "����");
	::PostMessage(hWnd, WM_ALARM_CHANGE, 0, 1);

	hWnd = ::FindWindow("CVAlarmMsg", "����");

}

void CCVEventManagerTestDlg::OnBnClickedOk55()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hwnd = ::FindWindowW(L"CVSystemMsg", NULL);

	::PostMessage(hwnd, WM_USER + 1304, NULL, NULL);
}

void CCVEventManagerTestDlg::OnBnClickedOk56()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hWnd;

	hWnd = ::FindWindow("CVSystemMsg", "ϵͳ��Ϣ");
	::PostMessage(hWnd, WM_OPERKEY_SYS_MSG_SHOW, 0, 0);
}

//�����ڴ�
void CCVEventManagerTestDlg::OnBnClickedOk57()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hWnd;

	hWnd = ::FindWindow("CVToolManager", NULL);
	::PostMessage(hWnd, WM_TOOLMANAGE_NOTIFY_MSG, 1, 0);
}

//����CoreView
void CCVEventManagerTestDlg::OnBnClickedOk58()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hWnd;

	hWnd = ::FindWindow("#CVToolManager", NULL);
	::PostMessage(hWnd, WM_TOOLMANAGE_NOTIFY_MSG, 2, 0);
}

//����/��������
void CCVEventManagerTestDlg::OnBnClickedOk59()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	bRun = TRUE;

	SetTimer(2, 3000, NULL);
}

void CCVEventManagerTestDlg::OnBnClickedOk60()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	KillTimer(2);
}

void CCVEventManagerTestDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedOk60();
	OnCancel();
}

void CCVEventManagerTestDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedOk60();
	OnOK();
}

void CCVEventManagerTestDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	static int Count = 0;
	HWND hwnd = ::FindWindowW(L"CVSystemMsg", NULL);

	CString Msg;
	COPYDATASTRUCT cpd;
	cpd.dwData = 0;
	Count++;
	Msg = L"�쳣:Net Abnormal";
	cpd.cbData = Msg.GetLength() + 1;
	cpd.lpData = Msg.GetBuffer();
	Msg.ReleaseBuffer();

	::SendMessage(hwnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
}

void CCVEventManagerTestDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	static int Count = 0;
	HWND hwnd = ::FindWindowW(L"CVSystemMsg", NULL);

	CString Msg;
	COPYDATASTRUCT cpd;
	cpd.dwData = 0;
	Count++;
	Msg = L"�ָ�:Net Abnormal";
	cpd.cbData = Msg.GetLength() + 1;
	cpd.lpData = Msg.GetBuffer();
	Msg.ReleaseBuffer();

	::SendMessage(hwnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
}

void CCVEventManagerTestDlg::OnBnClickedOk61()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hWnd;

	hWnd = ::FindWindow("CVSystemMsg", "ϵͳ��Ϣ");
	::PostMessage(hWnd, WM_OPERKEY_ALL_OK, 0, 0);
}

void CCVEventManagerTestDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	static int Count = 0;
	HWND hwnd = ::FindWindowW(L"CVSystemMsg", L"ϵͳ��Ϣ");

	CString Msg;
	COPYDATASTRUCT cpd;
	cpd.dwData = 1;//���ָ���ؼ��ֵ���Ϣ
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
	//��ȡ���洰���б�
	vector<CEnumDesktopWindow> Winlist;
	int WinCnt = 0;
	WinCnt = EnumDesktopWindow(Winlist);
	TRACE("������������ = %d\n", WinCnt);

	int cxScreen = 0, cyScreen = 0; 
	HWND hCore = NULL;
	CEnumDesktopWindow _struct;
	cxScreen = GetSystemMetrics(SM_CXSCREEN);
	cyScreen = GetSystemMetrics(SM_CYSCREEN);
	CRect DstRect(0, 0, cxScreen, int(cyScreen * 0.0625));//0.0625��CV8�������ϲ������ĳ����
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
	if(hlWnd != NULL)//���Ѿ�������CRTOP
	{
		//���͹ر���Ϣ
		::PostMessage(hlWnd, WM_CLOSE, 0, 0);
	}
}

void CCVEventManagerTestDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	Msg.Format(_T("�쳣:�泤�ޱ���Ϣ�ı��泤�ޱ���Ϣ�ı��泤�ޱ���Ϣ�ı��泤�ޱ���Ϣ�ı��泤�ޱ���Ϣ�ı�End!--0--%d"), Color);
	cpd.cbData = Msg.GetLength() + 1;
	cpd.lpData = Msg.GetBuffer();
	Msg.ReleaseBuffer();

	::SendMessage(hwnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
}

void CCVEventManagerTestDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	Msg.Format(_T("�泤�ޱ���Ϣ�ı���Ϣ�ı���Ϣ�ı���Ϣ�ı���Ϣ�ı���Ϣ�ı���Ϣ�ı���Ϣ�ı���Ϣ�ı�End!--5--%d"), Color);
	cpd.cbData = Msg.GetLength() + 1;
	cpd.lpData = Msg.GetBuffer();
	Msg.ReleaseBuffer();

	::SendMessage(hwnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
}

void CCVEventManagerTestDlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	Msg.Format(_T("�ָ�:�泤�ޱ���Ϣ�ı��泤�ޱ���Ϣ�ı��泤�ޱ���Ϣ�ı��泤�ޱ���Ϣ�ı��泤�ޱ���Ϣ�ı�End!--0--%d"), Color);
	cpd.cbData = Msg.GetLength() + 1;
	cpd.lpData = Msg.GetBuffer();
	Msg.ReleaseBuffer();

	::SendMessage(hwnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
}

unsigned PlayThreadProcess(void* pParam)
{
	//int ret = Speech("��������", -1);
	Play("C:\\coreview\\funcexec\\CVEventExec\\Configure\\Sound\\tada.wav");

	return 0;
}

void CCVEventManagerTestDlg::OnBnClickedOk65()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ULONG Buf[10] = {0};
	COPYDATASTRUCT cpd;
	cpd.dwData = 10001;//Զ�������ڴ����ı�־
	cpd.cbData = sizeof(ULONG) * 2;
	Buf[0] = 1;//��ҪԶ�̻����ĸ���
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

//��ʾ��Ϣ����
void CCVEventManagerTestDlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	Msg.Format(_T("��ʾ����!--0--%d"), Color);
	cpd.cbData = Msg.GetLength() + 1;
	cpd.lpData = Msg.GetBuffer();
	Msg.ReleaseBuffer();

	::SendMessage(hwnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
}

//�رվ�ʾ��Ϣ����
void CCVEventManagerTestDlg::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	Msg.Format(_T("��ʾ����!--0--%d"), Color);
	cpd.cbData = Msg.GetLength() + 1;
	cpd.lpData = Msg.GetBuffer();
	Msg.ReleaseBuffer();

	::SendMessage(hwnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
}

//��ť��ת��ϵͳͼ��Ϣ
void CCVEventManagerTestDlg::OnBnClickedOk66()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hwnd = ::FindWindow("~Grab_Im", NULL);
	if (hwnd)
	{
		int GrNo = 1;
		::PostMessage(hwnd, WM_USER + 1006, GrNo, NULL);
	}
}

//��ť��ɨ��ϵͳͼ��Ϣ
void CCVEventManagerTestDlg::OnBnClickedOk67()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hwnd = ::FindWindow("~Grab_Im", NULL);
	if (hwnd)
	{
		int GrNo = 1;
		::PostMessage(hwnd, WM_USER + 1007, GrNo, NULL);
	}
}

void CCVEventManagerTestDlg::OnBnClickedOk68()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TRACE("StartServer");
	//StartServer();

	int MimicCnt = GetMimicFileNameList();

	for (int i = 0; i < MimicCnt; i++)
	{
		vector<CString> PIDList;

		CString FileName = MimicFileNameList[i];
		TRACE("��ȡ%s��PID�б�\n", FileName);

		//���Һ�̨������̲����͹�����Ϣ...
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
	//������̨������Grab_Im����...
	HWND hwnd = ::FindWindowW(L"~Grab_Im", NULL);
	if (hwnd)
	{
		::PostMessage(hwnd, WM_CLOSE, NULL, NULL);
	}
}

//ϵͳͼ�б�
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
	TRACE("����int GetMimicList()\n");
	DWORD t1 = GetTickCount();
	char				SrcfilePathFile[255];
	char SrcfilePath[255];
	WIN32_FIND_DATA     FindFileData;
	HANDLE				handle;
	MimicFileNameList.clear();

	//�ж�·���Ƿ����
	//��ȡϵͳͼ���·��
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

			//���ͼ�Ƿ�Ϸ���ͼ
			if(CheckGrbValid(csGrb) == TRUE)
			{
				MimicFileNameList.push_back(csGrb);

				//�޸��ļ���Ϊȫ��д
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
	Msg.Format("GetMimicFileNameList()��ʱ=%dms", t2 - t1);
	TRACE(Msg);

	return (int)MimicFileNameList.size();
}

//ϵͳͼ���ƺϷ��Լ��
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

//��ť����ȡ����ͼ�б�
void CCVEventManagerTestDlg::OnBnClickedOk69()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TRACE("StartServer");
	//StartServer();

	int MimicCnt = GetMimicFileNameList();

	for (int i = 0; i < MimicCnt; i++)
	{
		vector<CString> MimicList;

		CString FileName = MimicFileNameList[i];
		TRACE("��ȡ%s�ĵ���ͼ�б�\n", FileName);

		//���Һ�̨������̲����͹�����Ϣ...
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

//��ť���滻PID
void CCVEventManagerTestDlg::OnBnClickedOk70()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TRACE("StartServer");
	//StartServer();

	int MimicCnt = GetMimicFileNameList();

	for (int i = 0; i < MimicCnt; i++)
	{
		//vector<CString> MimicList;

		CString FileName = MimicFileNameList[i];
		TRACE("��ȡ%s�ĵ���ͼ�б�\n", FileName);

		//���Һ�̨������̲����͹�����Ϣ...
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
