// CVEncryptDllTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CVEncryptDllTest.h"
#include "CVEncryptDllTestDlg.h"
#include "c:\CoreView_src\Include\cvencryptcomm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CCVEncryptDllTestDlg 对话框




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


// CCVEncryptDllTestDlg 消息处理程序

BOOL CCVEncryptDllTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCVEncryptDllTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR CCVEncryptDllTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCVEncryptDllTestDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
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
    TRACE("加密文件%d次耗时%dms\n", Times, t2 - t1);

	FreeLibrary(hModule);
}

void CCVEncryptDllTestDlg::OnBnClickedOk2()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
            sprintf_s(szLog, sizeof(szLog), "加密的测试文本加密的测试文本加密的测试文本加密的测试文本加密的测试文本加密的测试文本加密的测试文本加密的测试文本%03d", i + 1);
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
     s.Format("创建加密LOG耗时：%dms, 共%d条，平均%d条/秒\n", Time, Times, Items);
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
