// CVEncryptDllTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CVEncryptDllTest.h"
#include "CVEncryptDllTestDlg.h"
#include "c:\CoreView_src\Include\cvencryptcomm.h"

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


// CCVEncryptDllTestDlg �Ի���




CCVEncryptDllTestDlg::CCVEncryptDllTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCVEncryptDllTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCVEncryptDllTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCVEncryptDllTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CCVEncryptDllTestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDOK2, &CCVEncryptDllTestDlg::OnBnClickedOk2)
	ON_BN_CLICKED(IDOK3, &CCVEncryptDllTestDlg::OnBnClickedOk3)
    ON_BN_CLICKED(IDOK4, &CCVEncryptDllTestDlg::OnBnClickedOk4)
    ON_BN_CLICKED(IDOK5, &CCVEncryptDllTestDlg::OnBnClickedOk5)
END_MESSAGE_MAP()


// CCVEncryptDllTestDlg ��Ϣ�������

BOOL CCVEncryptDllTestDlg::OnInitDialog()
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

void CCVEncryptDllTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCVEncryptDllTestDlg::OnPaint()
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
HCURSOR CCVEncryptDllTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCVEncryptDllTestDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//OnOK();
	HMODULE  hModule;
	typedef BOOL (*DllFunction)(PCHAR, PCHAR, PCHAR);
	DllFunction Func;

	CString DllFileName;
	DllFileName.Format("C:\\CoreView\\Systemexec\\Bin\\CVEncryptDecrypt.dll");
	VERIFY(hModule=::LoadLibrary(DllFileName));
	Func=(DllFunction)::GetProcAddress(hModule, "CVEncryptFile");

    DWORD t1, t2;
    t1 = GetTickCount();
    int Times = 100;
    int ret = 0;
    for (int i = 0; i < Times; i++)
    {
        ret = Func("c:\\CoreView\\SystemExec\\Configure\\CVSAPCommdef.cyt", 
            "c:\\CoreView\\SystemExec\\Configure\\CVSAPCommdef.cv8", 
            "qwe456ujk*@%");
    }
    t2 = GetTickCount();
    TRACE("�����ļ�%d�κ�ʱ%dms\n", Times, t2 - t1);

	FreeLibrary(hModule);
}

void CCVEncryptDllTestDlg::OnBnClickedOk2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HMODULE  hModule;
	typedef BOOL (*DllFunction)(PCHAR, PCHAR, PCHAR);
	DllFunction Func;

	CString DllFileName;
	DllFileName.Format("C:\\CoreView\\Progfiles\\Bin\\CVEncryptDecrypt.dll");
	VERIFY(hModule=::LoadLibrary(DllFileName));
	Func=(DllFunction)::GetProcAddress(hModule, "CVDecryptFile");

	int ret = Func("C:\\CoreView\\Progfiles\\Bin\\CVSAPCommdef.cv8", 
		"C:\\CoreView\\Progfiles\\Bin\\CVSAPCommdef1.ini", 
		"qwe456ujk*@%");

	FreeLibrary(hModule);
}
void CCVEncryptDllTestDlg::OnBnClickedOk3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HMODULE  hModule;
	typedef BOOL (*DllFunction)();
	DllFunction Func;

	CString DllFileName;
	DllFileName.Format("C:\\CoreView\\Progfiles\\Bin\\CVEncryptDecrypt.dll");
	VERIFY(hModule=::LoadLibrary(DllFileName));
	Func=(DllFunction)::GetProcAddress(hModule, "RegOcx");

	int ret = Func();

	FreeLibrary(hModule);
}

int Times = 5000;
void CCVEncryptDllTestDlg::OnBnClickedOk4()
{
    // TODO: Add your control notification handler code here
    DWORD t1, t2;
    t1 = GetTickCount();
    CFile f;
    char szLog[1024];
    BOOL b = f.Open("C:\\Temp\\Test.log", CFile::modeCreate | CFile::modeReadWrite | CFile::typeBinary);
    if (b)
    {
        int Len = 0;
        for (int i = 0; i < Times; i++)
        {
            sprintf_s(szLog, sizeof(szLog), "���ܵĲ����ı����ܵĲ����ı����ܵĲ����ı����ܵĲ����ı����ܵĲ����ı����ܵĲ����ı����ܵĲ����ı����ܵĲ����ı�%03d", i + 1);
            Len = strlen(szLog);
            b = CVEncryptBuff(szLog, Len);
            f.Write(szLog, Len);
            f.Write("\r\n", 2);
        }
        f.Close();
    }

     t2 = GetTickCount();
     int Time = t2 - t1;
     double sec = double(t2 - t1) / 1000;
     int Items = Times / sec;
     CString s;
     s.Format("��������LOG��ʱ��%dms, ��%d����ƽ��%d��/��\n", Time, Times, Items);
     MessageBox(s);
}

void CCVEncryptDllTestDlg::OnBnClickedOk5()
{
    // TODO: Add your control notification handler code here
    CStdioFile f1, f2;
    char szLog[1024];
    BOOL b = f1.Open("C:\\Temp\\Test.log", CFile::modeRead | CFile::typeBinary);
    b = f2.Open("C:\\Temp\\Test_de.log", CFile::modeCreate | CFile::modeReadWrite);
    if (b)
    {
        int Len = 0;
        for (int i = 0; i < Times; i++)
        {
            memset(szLog, 0, sizeof(szLog));
            f1.ReadString(szLog, sizeof(szLog));
            Len = strlen(szLog) - 2;
            b = CVDecryptBuff(szLog, Len);
            f2.WriteString(szLog);
        }
        f1.Close();
        f2.Close();
    }
}
