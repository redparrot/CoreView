// CVPLCs10CommDrvDllTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CVPLCs10CommDrvDllTest.h"
#include "CVPLCs10CommDrvDllTestDlg.h"
#include "C:\CoreView_src\Include\CVPLCs10DrvBuilder.h"

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


// CCVPLCs10CommDrvDllTestDlg �Ի���




CCVPLCs10CommDrvDllTestDlg::CCVPLCs10CommDrvDllTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCVPLCs10CommDrvDllTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCVPLCs10CommDrvDllTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCVPLCs10CommDrvDllTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CCVPLCs10CommDrvDllTestDlg::OnBnClickedOk)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDOK2, &CCVPLCs10CommDrvDllTestDlg::OnBnClickedOk2)
	ON_BN_CLICKED(IDOK3, &CCVPLCs10CommDrvDllTestDlg::OnBnClickedOk3)
END_MESSAGE_MAP()


// CCVPLCs10CommDrvDllTestDlg ��Ϣ�������

BOOL CCVPLCs10CommDrvDllTestDlg::OnInitDialog()
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

	BOOL b = FALSE;

	hMenu = ::LoadMenu(NULL, MAKEINTRESOURCE(IDR_MENU1));         //IDR_MENU1Ϊ��Դ�в˵���ID   
	b = ::SetMenu(m_hWnd, hMenu);   

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	DisDrvConfDlg();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCVPLCs10CommDrvDllTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCVPLCs10CommDrvDllTestDlg::OnPaint()
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
HCURSOR CCVPLCs10CommDrvDllTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCVPLCs10CommDrvDllTestDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnOK();
}

void CCVPLCs10CommDrvDllTestDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDialog::OnClose();
}

void CCVPLCs10CommDrvDllTestDlg::OnBnClickedOk2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	list<long> OnlineUsedSysTagList;
	int Cnt = 0;

	time_t t1, t2;
	CString s;

	t1 = GetTickCount();
	Cnt = GetOnlineUsedSysTagCnt();
	OnlineUsedSysTagList.resize(Cnt);
	int Ret = GetOnlineUsedSysTagList(OnlineUsedSysTagList);
	t2 = GetTickCount();
	s.Format("��ʱ%d", t2 - t1);
	MessageBox(s);
}

//��ȡ�ܵ�������
void CCVPLCs10CommDrvDllTestDlg::OnBnClickedOk3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int Cnt = 0;

	int Ret = GetOnlineUsedSysTagCnt();
}
