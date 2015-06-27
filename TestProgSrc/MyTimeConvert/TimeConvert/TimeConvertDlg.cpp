// TimeConvertDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TimeConvert.h"
#include "TimeConvertDlg.h"

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


// CTimeConvertDlg �Ի���




CTimeConvertDlg::CTimeConvertDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimeConvertDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTimeConvertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTimeConvertDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK2, &CTimeConvertDlg::OnBnClickedOk2)
	ON_BN_CLICKED(IDOK3, &CTimeConvertDlg::OnBnClickedOk3)
	ON_BN_CLICKED(IDOK4, &CTimeConvertDlg::OnBnClickedOk4)
END_MESSAGE_MAP()


// CTimeConvertDlg ��Ϣ�������

BOOL CTimeConvertDlg::OnInitDialog()
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

void CTimeConvertDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTimeConvertDlg::OnPaint()
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
HCURSOR CTimeConvertDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTimeConvertDlg::OnBnClickedOk2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	time_t timer;
	CString s;

	time(&timer);

	s.Format("%d", timer);

	SetDlgItemText(IDC_EDIT1, s);
}

void CTimeConvertDlg::OnBnClickedOk3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	time_t timer = (time_t)GetDlgItemInt(IDC_EDIT2);

	struct tm LocalTime;
	CString s;

	localtime_s(&LocalTime, &timer);

	s.Format("%d/%02d/%02d %02d:%02d:%02d", LocalTime.tm_year + 1900, LocalTime.tm_mon + 1, LocalTime.tm_mday,
		LocalTime.tm_hour, LocalTime.tm_min, LocalTime.tm_sec);

	SetDlgItemText(IDC_EDIT3, s);
}

void CTimeConvertDlg::OnBnClickedOk4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	struct tm LocalTime;

	LocalTime.tm_year = GetDlgItemInt(IDC_EDIT4) - 1900;
	LocalTime.tm_mon = GetDlgItemInt(IDC_EDIT6) - 1;
	LocalTime.tm_mday = GetDlgItemInt(IDC_EDIT7);
	LocalTime.tm_hour = GetDlgItemInt(IDC_EDIT8);
	LocalTime.tm_min = GetDlgItemInt(IDC_EDIT9);
	LocalTime.tm_sec = GetDlgItemInt(IDC_EDIT10);

	time_t time = mktime(&LocalTime);

	CString s;
	s.Format("%d", time);
	SetDlgItemText(IDC_EDIT5, s);
}
