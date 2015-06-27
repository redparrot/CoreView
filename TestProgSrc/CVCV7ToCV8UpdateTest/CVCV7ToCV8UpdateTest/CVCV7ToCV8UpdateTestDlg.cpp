// CVCV7ToCV8UpdateTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CVCV7ToCV8UpdateTest.h"
#include "CVCV7ToCV8UpdateTestDlg.h"
#include "c:\CoreView_src\Include\CVCV7ToCV8UpdateDll.h"

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


// CCVCV7ToCV8UpdateTestDlg �Ի���

CCVCV7ToCV8UpdateTestDlg::CCVCV7ToCV8UpdateTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCVCV7ToCV8UpdateTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCVCV7ToCV8UpdateTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_ProgressCtrl);
}

BEGIN_MESSAGE_MAP(CCVCV7ToCV8UpdateTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CCVCV7ToCV8UpdateTestDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CCVCV7ToCV8UpdateTestDlg ��Ϣ�������

BOOL CCVCV7ToCV8UpdateTestDlg::OnInitDialog()
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

void CCVCV7ToCV8UpdateTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCVCV7ToCV8UpdateTestDlg::OnPaint()
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
HCURSOR CCVCV7ToCV8UpdateTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCVCV7ToCV8UpdateTestDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStatic ctlPrompt;
	int nRet = 0;
	nRet = UserConfigureUpdate(
		"D:\\�ֳ�ϵͳ����--��ɾ\\����\\CV7\\POC1\\",	//CV7ʮ��·������·������CV7��̬��������·��
		2,		//CV7����·�������ͣ�1-��ʾcsCV7DataPathָ����ʮ��·������·����2����ʾcsCV7DataPathָ������CV7��̬�������ڵ�·��
		"",		//CV7��ʷ��������·��
		"D:\\�ֳ�ϵͳ����--��ɾ\\����\\CV7\\POC1\\CV7PID_IID.dat",		//CV7IID-PID�����ļ�����·��
		2,		//2��������;4PLC����;3��������;1�¼���������
		"c:\\CoreView\\Record data\\log\\CV7ToCV8.txt",		//log�ļ����ơ�Ҫ�����DLL��׷�ӵķ�ʽ���ļ�
		ctlPrompt,
		m_ProgressCtrl);
}
