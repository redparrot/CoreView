// CVEnumPocInNetTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CVEnumPocInNetTest.h"
#include "CVEnumPocInNetTestDlg.h"
#include "EnumPocInNetComm.h"
#include "CVDeviceCommdll.h"
#include <list>
using namespace std ;

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


// CCVEnumPocInNetTestDlg �Ի���




CCVEnumPocInNetTestDlg::CCVEnumPocInNetTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCVEnumPocInNetTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCVEnumPocInNetTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
}

BEGIN_MESSAGE_MAP(CCVEnumPocInNetTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CCVEnumPocInNetTestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL2, &CCVEnumPocInNetTestDlg::OnBnClickedCancel2)
	ON_BN_CLICKED(IDCANCEL3, &CCVEnumPocInNetTestDlg::OnBnClickedCancel3)
	ON_BN_CLICKED(IDCANCEL4, &CCVEnumPocInNetTestDlg::OnBnClickedCancel4)
	ON_BN_CLICKED(IDCANCEL5, &CCVEnumPocInNetTestDlg::OnBnClickedCancel5)
END_MESSAGE_MAP()


// CCVEnumPocInNetTestDlg ��Ϣ�������

BOOL CCVEnumPocInNetTestDlg::OnInitDialog()
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
	m_List.InsertColumn(0, _T("���"), LVCFMT_LEFT, 40, -1);
	m_List.InsertColumn(1, _T("��������"), LVCFMT_LEFT, 150, -1);
	m_List.InsertColumn(2, _T("IP"), LVCFMT_LEFT, 150, -1);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCVEnumPocInNetTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCVEnumPocInNetTestDlg::OnPaint()
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
HCURSOR CCVEnumPocInNetTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCVEnumPocInNetTestDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//OnOK();
	int count = 0;
	CStringArray csArray;
	vector<CString> List;

	int PocNums = GetPocNums();
	csArray.SetSize(PocNums);
	count = PocInNet(csArray, TRUE);

	CString s;
	m_List.DeleteAllItems();
	for (int i = 0; i < count; i++)
	{
		s.Format("%d", i + 1);
		m_List.InsertItem(i, s);
		s = csArray.GetAt(i);
		StrToken(s.GetBuffer(), ":", List);
		m_List.SetItemText(i, 1, List[0]);
		m_List.SetItemText(i, 2, List[1]);
	}
	s.ReleaseBuffer();
}
#define DEVNAMELEN 17

void CCVEnumPocInNetTestDlg::OnBnClickedCancel2()
{
	// TODO: Add your control notification handler code here
	POCInfoOnline* PocInfo;
	PrntInfoOnline PrinterInfo[32];
	memset(PrinterInfo, 0, sizeof(PrntInfoOnline) * 32);

	PocInfo = new POCInfoOnline[10];
	memset(PocInfo, 0, sizeof(POCInfoOnline) * 10);

	GetPOCInfoList(PocInfo);

	GetPrntInfoList(PrinterInfo);
}

void CCVEnumPocInNetTestDlg::OnBnClickedCancel3()
{
	// TODO: Add your control notification handler code here
	int count = 0;
	CStringArray csArray;

	int PocNums = GetPocNums();
	csArray.SetSize(PocNums);
	count = PocInNet(csArray, FALSE);

	CString s;
	m_List.DeleteAllItems();
	for (int i = 0; i < count; i++)
	{
		s.Format("%d", i + 1);
		m_List.InsertItem(i, s);
		s = csArray.GetAt(i);
		m_List.SetItemText(i, 1, s);
	}
}

void CCVEnumPocInNetTestDlg::OnBnClickedCancel4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int count = 0;
	PC_INFO * pPCInfo = NULL;
	PC_INFO PC_INFO_t;

	m_List.DeleteAllItems();

	count = EnumPC(pPCInfo, 0);

	pPCInfo = new PC_INFO[count];

	count = EnumPC(pPCInfo, 0);

	CString s;
	for (int i = 0; i < count; i++)
	{
		PC_INFO_t = pPCInfo[i];
		s.Format("%d", i + 1);
		m_List.InsertItem(i, s);
		m_List.SetItemText(i, 1, PC_INFO_t.PCName);
		m_List.SetItemText(i, 2, PC_INFO_t.IP);
	}

	delete[] pPCInfo;
}

void CCVEnumPocInNetTestDlg::OnBnClickedCancel5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int count = 0;
	PC_INFO * pPCInfo = NULL;
	PC_INFO PC_INFO_t;

	m_List.DeleteAllItems();

	count = EnumPC(pPCInfo, 0);

	pPCInfo = new PC_INFO[count];

	count = EnumPC(pPCInfo, 1);

	CString s;
	for (int i = 0; i < count; i++)
	{
		PC_INFO_t = pPCInfo[i];
		s.Format("%d", i + 1);
		m_List.InsertItem(i, s);
		m_List.SetItemText(i, 1, PC_INFO_t.PCName);
		m_List.SetItemText(i, 2, PC_INFO_t.IP);
	}

	delete[] pPCInfo;
}

void CCVEnumPocInNetTestDlg::StrToken(char* buf, char* seps, vector<CString>& List)
{
	char* pToken = NULL;
	char* next_token;
	CString s;

	List.clear();
	pToken = strtok_s(buf, seps, &next_token);
	if (pToken != NULL)
	{
		s = pToken;
		List.push_back(s);
		while (pToken != NULL)
		{
			pToken = strtok_s(NULL, seps, &next_token);
			s = pToken;
			s.TrimRight();
			List.push_back(s);
		}
	}
}

