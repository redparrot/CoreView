// CVAlarmDisplayTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CVAlarmDisplayTest.h"
#include "CVAlarmDisplayTestDlg.h"
#include "C:\CoreView_Src\Include\CVCommonDllCommon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
#define WM_ALARM_CHANGE		WM_USER + 5000
#define ALARM_AFFIRM			0x01
#define ALARM_RESTORATION		0x02

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


// CCVAlarmDisplayTestDlg �Ի���




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


// CCVAlarmDisplayTestDlg ��Ϣ�������

BOOL CCVAlarmDisplayTestDlg::OnInitDialog()
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
	OnBnClickedOk2();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCVAlarmDisplayTestDlg::OnPaint()
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
HCURSOR CCVAlarmDisplayTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCVAlarmDisplayTestDlg::OnBnClickedOk2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

void CCVAlarmDisplayTestDlg::OnBnClickedOk()//L3����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

void CCVAlarmDisplayTestDlg::OnBnClickedOk4()//L2����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

void CCVAlarmDisplayTestDlg::OnBnClickedOk5()//L1����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UnmapViewOfFile(m_pAlarmMap);

	CloseHandle(m_hAlarmMap);

	OnCancel();
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hWnd;

	hWnd = ::FindWindow(NULL, "������ʾ");
	::PostMessage(hWnd, WM_ALARM_CHANGE, 0, 0);

}

void CCVAlarmDisplayTestDlg::OnBnClickedOk7()//H3����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

void CCVAlarmDisplayTestDlg::OnBnClickedOk8()//H2����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

void CCVAlarmDisplayTestDlg::OnBnClickedOk10()//H1����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

void CCVAlarmDisplayTestDlg::OnBnClickedOk6()//�����ָ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for (int i = 0; i < AlarmMax; i++)
	{
		memcpy(&m_AlarmInfo, m_pAlarmMap + i, sizeof(SAlarmShareMem));
		m_AlarmInfo.CurAlmChgFlg |= 0x02;
		m_AlarmInfo.value = 50;
		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
	}

	OnBnClickedOk3();
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk9()//����ȷ��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for (int i = 0; i < AlarmMax; i++)
	{
		memcpy(&m_AlarmInfo, m_pAlarmMap + i, sizeof(SAlarmShareMem));
		m_AlarmInfo.CurAlmChgFlg |= 0x01;
		memcpy(m_pAlarmMap + i, &m_AlarmInfo, sizeof(SAlarmShareMem));
	}

	OnBnClickedOk3();
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk17()//ģ����ͻ�䱨��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

void CCVAlarmDisplayTestDlg::OnBnClickedOk11()//0->1����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

void CCVAlarmDisplayTestDlg::OnBnClickedOk12()//1->0����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

void CCVAlarmDisplayTestDlg::OnBnClickedOk13()//������˫�򱨾�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

void CCVAlarmDisplayTestDlg::OnBnClickedOk14()//���������㱨��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//UnmapViewOfFile(m_pAlarmMap);

	//CloseHandle(m_hAlarmMap);

	CDialog::OnClose();
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk15()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	SetTimer(1, 1000, NULL);
}

void CCVAlarmDisplayTestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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

	hWnd = ::FindWindow(NULL, "������ʾ");
	::PostMessage(hWnd, WM_ALARM_CHANGE, 0, 0);

	CDialog::OnTimer(nIDEvent);
}

void CCVAlarmDisplayTestDlg::OnBnClickedOk19()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

	for (int i = 0; i < Count; i++)//ͻ��
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

	for (int i = 0; i < Count; i++)//����
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
	for (int i = 0; i < Count; i++)//0��1
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

	for (int i = 0; i < Count; i++)//1��0
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

	for (int i = 0; i < Count; i++)//˫��
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

	for (int i = 0; i < Count; i++)//����
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

	for (int i = 0; i < Count; i++)//�����ָ�
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

void CCVAlarmDisplayTestDlg::OnBnClickedOk26()//��������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

void CCVAlarmDisplayTestDlg::OnBnClickedOk27()//ͻ�䱨������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
