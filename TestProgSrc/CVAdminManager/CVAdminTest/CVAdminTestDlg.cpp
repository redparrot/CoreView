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
}T_DiskInfo;

CString POCName = "CIS1_MDA";
CString User_Name = "CoreView$";
CString Password = "buk3Y8+iYE0*v^UsqTvhDvz2#OFXENgA)bC(7VwNuTa!wlL~AM";

unsigned ConnectProcess(void *pParam)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	CCVAdminTestDlg	*p = (CCVAdminTestDlg *) pParam;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	BOOL b = FALSE;
	CString Msg;
	CString FileName, DstName;
	static int Count = 0;
	char Name[30] = {0};
	char PW[64] = {0};
	int iRet = 0;
	int OKCnt = 0, ErrCnt = 0;

	p->GetDlgItemText(IDC_EDIT1, POCName);
	WritePrivateProfileString("CVAdminManager", "POC", POCName, p->ExePath);

	GetCVAdminInfo(Name, sizeof(Name), PW, sizeof(PW));

	p->RunFlag = TRUE;
	while (p->RunFlag)
	{
		b = CVConnDriver(POCName, "C");
		if (b <= 0)
		{
			TRACE("�����룺%d\n", b);
			ErrCnt++;
			Msg.Format("%d", ErrCnt);
			p->SetDlgItemText(IDC_STATIC_ERR, Msg);
		}
		else
		{
			OKCnt++;
			Msg.Format("%d", OKCnt);
			p->SetDlgItemText(IDC_STATIC_OK, Msg);
		}
		CVDisConnDriver(POCName, "C");
	}

	return 1;
}

unsigned PocListProcess(void *pParam)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	CCVAdminTestDlg	*p = (CCVAdminTestDlg *) pParam;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	p->bProcessing = TRUE;

	p->GetPOCNameList(p->NameList);

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
		DiskInfo.TotalBytes=TotalNumberOfBytes.QuadPart;
		DiskInfo.FreeBytes=TotalNumberOfFreeBytes.QuadPart;
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
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_PROGRESS1, m_Progress);
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
	DWORD	dwNewStyle = LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES;
	m_List.SetExtendedStyle(dwNewStyle);
	m_List.InsertColumn(0, "ע��POC����", LVCFMT_LEFT, 100, -1);
	m_List.InsertColumn(1, "Ping E1", LVCFMT_LEFT, 70, -1);
	m_List.InsertColumn(2, "Ping E2", LVCFMT_LEFT, 70, -1);
	m_List.InsertColumn(3, "Write RC1", LVCFMT_LEFT, 100, -1);
	m_List.InsertColumn(4, "Write RC2", LVCFMT_LEFT, 100, -1);
	m_List.InsertColumn(5, "Զ��C������(G)", LVCFMT_CENTER, 120, -1);
	m_List.InsertColumn(6, "Զ��C��ʣ������(G)", LVCFMT_CENTER, 150, -1);

	hIcon = AfxGetApp()->LoadIcon(IDI_POC);
	m_Image.Create(32, 32, ILC_COLOR32, 1, 1);
	int a = m_Image.Add(hIcon);
	m_List.SetImageList(&m_Image, LVSIL_SMALL);

	m_Progress.SetRange(0, 100);
	m_Progress.SetPos(0);

	char buf[100] = {0};
	ExePath = GetExePath() + "CVAdminManager.ini";
	GetPrivateProfileString("CVAdminManager", "POC", NULL, buf, sizeof(buf), ExePath);
	SetDlgItemText(IDC_EDIT1, buf);

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

	DWORD ret=WNetCancelConnection2(RN, CONNECT_UPDATE_PROFILE, TRUE);

	if (ret==0)
		return TRUE;
	else
		return FALSE;
}

void CCVAdminTestDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DisIpcConnect (POCName.GetBuffer());

	POCName.ReleaseBuffer();

	OnCancel();
}

void CCVAdminTestDlg::OnBnClickedOk2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BOOL b = ExistCVAdmin(User_Name.GetBuffer());
	User_Name.ReleaseBuffer();

	if (b)
	{
		MessageBox("�����û�����", "�����");
	}
	else
	{
		MessageBox("�����û�������", "�����");
	}
}

void CCVAdminTestDlg::OnBnClickedOk3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BOOL b = CreateCVAdmin(User_Name.GetBuffer(), Password.GetBuffer());
	User_Name.ReleaseBuffer();
	Password.ReleaseBuffer();
	if (b)
	{
		MessageBox("���������û��ɹ�", "�����");
	}
	else
	{
		MessageBox("���������û�ʧ��", "�����");
	}
}

void CCVAdminTestDlg::OnBnClickedOk4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemText(IDC_EDIT1, POCName);

	BOOL b = DeleteCVAdmin(User_Name.GetBuffer());
	User_Name.ReleaseBuffer();
	DisIpcConnect(POCName.GetBuffer());
	POCName.ReleaseBuffer();
	if (b)
	{
		MessageBox("ɾ�������û��ɹ�", "�����");
	}
	else
	{
		MessageBox("ɾ�������û�ʧ��", "�����");
	}
}

void CCVAdminTestDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BOOL b = FALSE;
	CString Msg;
	CString FileName, DstName;
	static int Count = 0;
	char Name[30] = {0};
	char PW[64] = {0};
	int iRet = 0;

	GetDlgItemText(IDC_EDIT1, POCName);
	WritePrivateProfileString("CVAdminManager", "POC", POCName, ExePath);

	GetCVAdminInfo(Name, sizeof(Name), PW, sizeof(PW));
	b = CVConnIPC (POCName.GetBuffer());
	if (b)
	{
		SetDlgItemText(IDC_STATIC5, "Զ�̻������ӣ��ɹ�");
	}
	else
	{
		iRet = GetLastError();
		SetDlgItemText(IDC_STATIC5, "Զ�̻������ӣ�ʧ��");
	}

	CVDisConnIPC(POCName.GetBuffer());
	POCName.ReleaseBuffer();

	b = CVConnDriver(POCName, "C");
	if (b)
	{
		SetDlgItemText(IDC_STATIC6, "Զ��C�����ӣ��ɹ�");
	}
	else
	{
		iRet = GetLastError();
		SetDlgItemText(IDC_STATIC6, "Զ��C�����ӣ�ʧ��");
	}

	T_DiskInfo DiskInfo;
	char Driver[256] = {0};
	sprintf_s(Driver, sizeof(Driver), "\\\\%s\\C$\\", POCName);
	GetDiskInfo(Driver, DiskInfo);

	FileName.Format("\\\\%s\\C$\\WINDOWS\\explorer.exe", POCName);
	DstName.Format("\\\\%s\\C$\\explorer.exe", POCName);
	b = CopyFile(FileName, DstName, FALSE);
	if (b)
	{
		SetDlgItemText(IDC_STATIC4, "Զ�̻����ļ��������ɹ�");
		DeleteFile(DstName);
	}
	else
	{
		int iRet = 0;
		iRet = GetLastError();
		SetDlgItemText(IDC_STATIC4, "Զ�̻����ļ�������ʧ��");
	}

	CString s;
	s.Format("C����������%d G", DiskInfo.TotalBytes / (1024 * 1024 * 1024));
	SetDlgItemText(IDC_STATIC2, s);
	s.Format("C��ʣ��������%d G", DiskInfo.FreeBytes / (1024 * 1024 * 1024));
	SetDlgItemText(IDC_STATIC3, s);

	CVDisConnDriver(POCName, "C");
}

void CCVAdminTestDlg::OnBnClickedOk5()
{
	char Name[100] = {0};

	CVGetCurUserName(Name, 100);
	SetDlgItemText(IDC_EDIT2, Name);
}

/*
=======================================================================================================================
��ȡ����POC�б�
=======================================================================================================================
*/
void CCVAdminTestDlg::GetPOCNameList(OUT vector<PocNetSts> &NameList)
{
	int				Count = 0;
	CString			IP[2];
	BOOL			ret1 = FALSE;
	BOOL			ret2 = FALSE;
	POCInfoOnline * pPocList = NULL;
	CString			Message;
	int				POCCnt = 0;
	CStringArray	DisConnetPOCList;
	CString			POCName;
	BOOL			b1 = FALSE, b2 = FALSE;

	m_List.DeleteAllItems();
	NameList.clear();
	SetDlgItemText(IDC_OK, "������0 ̨");
	SetDlgItemText(IDC_ERR, "�쳣��0 ̨");

	Count = GetPOCCount();
	if (Count > 0)
	{
		Message.Format("ע��POC������%d ̨", Count);
		SetDlgItemText(IDC_TOTAL, Message);
		pPocList = new POCInfoOnline[Count];
		memset(pPocList, 0, sizeof(POCInfoOnline) * Count);

		GetPOCInfoList(pPocList);

		time_t t1 = GetTickCount();
		for(int i = 0; i < Count; i++)
		{
			POCName = pPocList[i].POCName;

			IP[0] = GetIP(pPocList[i].LanboxIP);
			IP[1] = GetIP(pPocList[i].EtherIP1);
			ret1 = Ping(IP[0], 5);
			ret2 = Ping(IP[1], 5);
			m_List.InsertItem(i, pPocList[i].POCName, 0);
			m_List.EnsureVisible(i, TRUE);
			
			if (ret1 == TRUE)
			{
				m_List.SetItemText(i, 1, "�ɹ�");
			} 
			else
			{
				m_List.SetItemText(i, 1, "ʧ��");
			}

			if (ret2 == TRUE)
			{
				m_List.SetItemText(i, 2, "�ɹ�");
			} 
			else
			{
				m_List.SetItemText(i, 2, "ʧ��");
			}

			b1 = FALSE;
			if (ret1)
			{
				b1 = CVConnDriver(IP[0].GetBuffer(), "C");
				IP[0].ReleaseBuffer();
			}
			if (b1 == TRUE)
			{
				m_List.SetItemText(i, 3, "�ɹ�");
			} 
			else
			{
				m_List.SetItemText(i, 3, "ʧ��");
			}

			b2 = FALSE;
			if (ret2)
			{
				b2 = CVConnDriver(IP[1].GetBuffer(), "C");
				IP[1].ReleaseBuffer();
			}
			if (b2 == TRUE)
			{
				m_List.SetItemText(i, 4, "�ɹ�");
			} 
			else
			{
				m_List.SetItemText(i, 4, "ʧ��");
			}

			char Driver[256] = "";
			T_DiskInfo DiskInfo;
			memset(&DiskInfo, 0, sizeof(T_DiskInfo));
			if (b1 || b2)
			{
				if (b1)
				{
					sprintf_s(Driver, sizeof(Driver), "\\\\%s\\C$\\", IP[0]);
				} 
				if (b2)
				{
					sprintf_s(Driver, sizeof(Driver), "\\\\%s\\C$\\", IP[1]);
				}
				GetDiskInfo(Driver, DiskInfo);
			}

			CString s;
			s.Format("%d", DiskInfo.TotalBytes / (1024 * 1024 * 1024));
			m_List.SetItemText(i, 5, s);
			s.Format("%d", DiskInfo.FreeBytes / (1024 * 1024 * 1024));
			m_List.SetItemText(i, 6, s);

			int pos = int(FLOAT(i + 1) / Count * 100);
			m_Progress.SetPos(pos);
			s.Format("%d%%", pos);
			SetDlgItemText(IDC_100, s);

			if (b1 || b2)
			{
				POCCnt++;
			} 
			else
			{
				DisConnetPOCList.Add(pPocList[i].POCName);
			}
		}
		delete[] pPocList;

		time_t t2 = GetTickCount();
		
		Message.Format("��ʱ: %d ����\n", t2 - t1);
		SetDlgItemText(IDC_ERR2, Message);

		Message.Format("������%d ̨", POCCnt);
		SetDlgItemText(IDC_OK, Message);

		POCCnt = (int)DisConnetPOCList.GetCount();
		Message.Format("�쳣��%d ̨", POCCnt);
		SetDlgItemText(IDC_ERR, Message);
	}

	return;
}

/*
=======================================================================================================================
PING�����Ļ������ȳ�����1���ٳ�����2���������������ͨ����Ϊ����
=======================================================================================================================
*/
int CCVAdminTestDlg::PingHost(CString IP1, CString IP2)
{
	BOOL ret = FALSE;

	ret = Ping(IP2, 5);
	if (ret)
	{
		return 2;
	}
	else
	{
		ret = Ping(IP1, 5);
		if (ret)
		{
			return 1;
		}
	}

	return 0;
}

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