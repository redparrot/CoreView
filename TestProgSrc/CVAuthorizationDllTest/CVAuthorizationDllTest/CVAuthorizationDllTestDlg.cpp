// CVAuthorizationDllTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CVAuthorizationDllTest.h"
#include "CVAuthorizationDllTestDlg.h"
#include "c:\CoreView_src\Include\CVAuthorizationComm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

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


// CCVAuthorizationDllTestDlg �Ի���




CCVAuthorizationDllTestDlg::CCVAuthorizationDllTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCVAuthorizationDllTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCVAuthorizationDllTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCVAuthorizationDllTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CCVAuthorizationDllTestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDOK2, &CCVAuthorizationDllTestDlg::OnBnClickedOk2)
END_MESSAGE_MAP()


// CCVAuthorizationDllTestDlg ��Ϣ�������

BOOL CCVAuthorizationDllTestDlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCVAuthorizationDllTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCVAuthorizationDllTestDlg::OnPaint()
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
HCURSOR CCVAuthorizationDllTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//IsAuthorizedStation��ť
void CCVAuthorizationDllTestDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//OnOK();
	DWORD t1, t2;
	t1 = GetTickCount();
	BOOL b = IsAuthorizedStation();
	t2 = GetTickCount();

	CString Msg;
	Msg.Format("IsAuthorizedStation��ʱ:%dms, ����ֵ = %d", t2 - t1, b);
	TRACE(Msg);
	MessageBox(Msg, "��ʾ:", MB_OK);
}

//GetPOCAuthorizeInfo��ť
void CCVAuthorizationDllTestDlg::OnBnClickedOk2()
{
	// TODO: Add your control notification handler code here
	DWORD t1, t2;
	t1 = GetTickCount();
	POCAuthorizeInfo POCInfo;
	memset(&POCInfo, 0, sizeof(POCAuthorizeInfo));
	int Ret = GetPOCAuthorizeInfo(POCInfo);
	t2 = GetTickCount();

	CString Msg;
	Msg.Format("GetPOCAuthorizeInfo��ʱ:%dms\n\
HISTMax = %d\n\
UnauthorizedMaxWorkingDay = %d\n\
UnauthorizedNormalWorkingDay = %d\n\
UnauthorizedAlarmCycle = %d\n\n\
AIMax = %d\nDIMax = %d\nAOMax = %d\nDOMax = %d\nCAMax = %d\nCDMax = %d\n\
OneGrpMax = %d\n\
FourInOne = %d\n",
		t2 - t1, 
		POCInfo.HISTMax, POCInfo.UnauthorizedMaxWorkingDay, POCInfo.UnauthorizedNormalWorkingDay, POCInfo.UnauthorizedAlarmCycle, 
		POCInfo.AIMax, POCInfo.DIMax, POCInfo.AOMax, POCInfo.DOMax, POCInfo.CAMax, POCInfo.CDMax,
		POCInfo.OneGrpMax,
		POCInfo.FourInOne);
	TRACE(Msg);
	MessageBox(Msg, "��ʾ:", MB_OK);
}
