// MultiStartTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MultiStartTest.h"
#include "MultiStartTestDlg.h"

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


// CMultiStartTestDlg �Ի���




CMultiStartTestDlg::CMultiStartTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMultiStartTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMultiStartTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMultiStartTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CMultiStartTestDlg::OnBnClickedOk)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDCANCEL2, &CMultiStartTestDlg::OnBnClickedCancel2)
	ON_BN_CLICKED(IDCANCEL, &CMultiStartTestDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK2, &CMultiStartTestDlg::OnBnClickedOk2)
END_MESSAGE_MAP()


// CMultiStartTestDlg ��Ϣ�������

BOOL CMultiStartTestDlg::OnInitDialog()
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
	//��ȡ���ڼ��
	Time = GetDlgItemInt(IDC_TIME);
	if (Time == 0)
	{
		Time = 10000;
		SetDlgItemInt(IDC_TIME, Time);
	}

	//��ȡ����ʵ���ĸ���
	ProcessNums = GetDlgItemInt(IDC_NUMS);
	if (ProcessNums == 0)
	{
		ProcessNums = 10;
		SetDlgItemInt(IDC_NUMS, ProcessNums);
	}

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMultiStartTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMultiStartTestDlg::OnPaint()
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
HCURSOR CMultiStartTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMultiStartTestDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//OnOK();
	OnBnClickedOk2();
	SetTimer(WM_TIMER + 1, Time, NULL);
}

void CMultiStartTestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	OnBnClickedOk2();

	CDialog::OnTimer(nIDEvent);
}

void CMultiStartTestDlg::OnBnClickedCancel2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	KillTimer(WM_TIMER + 1);
}

void CMultiStartTestDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	KillTimer(WM_TIMER + 1);
	OnCancel();
}

void CMultiStartTestDlg::OnBnClickedOk2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//��ȡ���ڼ��
	Time = GetDlgItemInt(IDC_TIME);
	if (Time == 0)
	{
		Time = 10000;
		SetDlgItemInt(IDC_TIME, Time);
	}

	//��ȡ����ʵ���ĸ���
	ProcessNums = GetDlgItemInt(IDC_NUMS);
	if (ProcessNums == 0)
	{
		ProcessNums = 10;
		SetDlgItemInt(IDC_NUMS, ProcessNums);
	}

	//��ȡ��ִ�г�������Ƽ�·��
	GetDlgItemText(IDC_EXEPATH, ExePathName);

	//��ȡ��ִ�г���������в���
	GetDlgItemText(IDC_CMDLINE, CmdLine);

	for (int i = 0; i < ProcessNums; i++)
	{
		ShellExecute(NULL, "open", ExePathName, CmdLine, NULL, SW_SHOW);
	}
}
