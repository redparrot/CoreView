// WriteEventLogTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "WriteEventLogTest.h"
#include "WriteEventLogTestDlg.h"
#include "C:\\CoreView_src\\Include\\CVWriteEventLogComm.h"
//#include "c:\CoreView_src\Include\cvfilemanagercomm.h"
#include "c:\CoreView_src\Include\cvencryptcomm.h"
#include <vector>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

unsigned Func(void* pParam)
{
	CWriteEventLogTestDlg* pParent = (CWriteEventLogTestDlg*)pParam;

	char EventText[1024];
	int ret = 0;
	char FileName[8][1024] = {"C:\\CV8TestLog1.txt", "C:\\CV8TestLog2.txt", "C:\\CV8TestLog3.txt", "C:\\CV8TestLog4.txt",
		"C:\\CV8TestLog5.txt", "C:\\CV8TestLog6.txt", "C:\\CV8TestLog7.txt", "C:\\CV8TestLog8.txt"};

	DWORD t1 = GetTickCount();
	pParent->ThreadRunFlag = TRUE;
	int i = 1;
	while (pParent->ThreadRunFlag)
	{
		sprintf_s(EventText, 1024, "测试文本%012d", i++);
		for (int j = 0; j < 8; j++)
		{
			ret = WriteEventLogWithAutoTime(FileName[j], EventText);
		}
		Sleep(1);
	}
	DWORD t2 = GetTickCount();
	CString s;
	//s.Format("耗时 %d ms，平均 1 秒往8个文件中每文件写入 %d 条记录", t2 - t1, Cnt / ((t2 - t1) / 1000));
	//MessageBox(s, "提示：", 0);

	return 100;
}

unsigned Func2(void* pParam)
{
	CWriteEventLogTestDlg* pParent = (CWriteEventLogTestDlg*)pParam;

	char EventText[1024];
	int ret = 0;
	char FileName[8][1024] = {"C:\\CV8TestLog1.txt", "C:\\CV8TestLog2.txt", "C:\\CV8TestLog3.txt", "C:\\CV8TestLog4.txt",
		"C:\\CV8TestLog5.txt", "C:\\CV8TestLog6.txt", "C:\\CV8TestLog7.txt", "C:\\CV8TestLog8.txt"};

	DWORD t1 = GetTickCount();
	pParent->ThreadRunFlag = TRUE;
	int i = 1;
	while (pParent->ThreadRunFlag)
	{
		sprintf_s(EventText, 1024, "测试文本%012d", i++);
		for (int j = 0; j < 8; j++)
		{
			ret = WriteEventLog(FileName[j], EventText);
		}
		Sleep(1);
	}
	DWORD t2 = GetTickCount();
	CString s;
	//s.Format("耗时 %d ms，平均 1 秒往8个文件中每文件写入 %d 条记录", t2 - t1, Cnt / ((t2 - t1) / 1000));
	//MessageBox(s, "提示：", 0);

	return 200;
}

unsigned ThreadWrite(void* pParam)
{
	CWriteEventLogTestDlg* pParent = (CWriteEventLogTestDlg*)pParam;

	char EventText[1024];
	int ret = 0;
	char FileName[1024] = {"C:\\CV8TestLog.txt"};

	DWORD t1 = GetTickCount();
	pParent->ThreadRunFlag = TRUE;
	int i = 1;
	while (pParent->ThreadRunFlag)
	{
		sprintf_s(EventText, 1024, "线程内带时间记录，次数 = %d", i++);
		ret = WriteEventLogWithAutoTime(FileName, EventText);
		Sleep(1);
	}
	DWORD t2 = GetTickCount();
	CString s;
	//s.Format("耗时 %d ms，平均 1 秒往8个文件中每文件写入 %d 条记录", t2 - t1, Cnt / ((t2 - t1) / 1000));
	//MessageBox(s, "提示：", 0);

	return 300;
}
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


// CWriteEventLogTestDlg 对话框




CWriteEventLogTestDlg::CWriteEventLogTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWriteEventLogTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWriteEventLogTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWriteEventLogTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CWriteEventLogTestDlg::OnBnClickedButton1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, &CWriteEventLogTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CWriteEventLogTestDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CWriteEventLogTestDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CWriteEventLogTestDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CWriteEventLogTestDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CWriteEventLogTestDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CWriteEventLogTestDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CWriteEventLogTestDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CWriteEventLogTestDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDCANCEL, &CWriteEventLogTestDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON11, &CWriteEventLogTestDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CWriteEventLogTestDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CWriteEventLogTestDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CWriteEventLogTestDlg::OnBnClickedButton14)
END_MESSAGE_MAP()


// CWriteEventLogTestDlg 消息处理程序

BOOL CWriteEventLogTestDlg::OnInitDialog()
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

void CWriteEventLogTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWriteEventLogTestDlg::OnPaint()
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
HCURSOR CWriteEventLogTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CWriteEventLogTestDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	
	SetTimer(WM_TIMER + 1, 10, NULL);
}

void CWriteEventLogTestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (WM_TIMER + 1 == nIDEvent)
	{
		//KillTimer(nIDEvent);

		static long Count = 1;
		char EventText[1024];
		char FileName[1024] = "C:\\CV8TestLog.txt";

		int ret = 0;
		sprintf_s(EventText, 1024, "主进程调用WriteEventLog函数测试, 次数 = %d", Count++);
		ret = WriteEventLog(FileName, EventText);
	}

	if (WM_TIMER + 2 == nIDEvent)
	{
		static long Count = 1;
		char EventText[1024];
		char FileName[1024] = "C:\\CV8TestLog.txt";

		int ret = 0;
		sprintf_s(EventText, 1024, "主进程调用WriteEventLogWithAutoTime函数测试, 次数 = %d", Count++);
		ret = WriteEventLogWithAutoTime(FileName, EventText);
	}

	CDialog::OnTimer(nIDEvent);
}

void CWriteEventLogTestDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	KillTimer(WM_TIMER + 1);
	CloseLogFile();

	//FreeLibrary(hModule);
}

void CWriteEventLogTestDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	AfxBeginThread((AFX_THREADPROC)Func, this, THREAD_PRIORITY_IDLE);
}

void CWriteEventLogTestDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CloseLogFile();
}

void CWriteEventLogTestDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxBeginThread((AFX_THREADPROC)Func2, this, THREAD_PRIORITY_IDLE);
}

void CWriteEventLogTestDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	ThreadRunFlag = FALSE;
}

void CWriteEventLogTestDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxBeginThread((AFX_THREADPROC)ThreadWrite, this, THREAD_PRIORITY_NORMAL);
}

void CWriteEventLogTestDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	SetTimer(WM_TIMER + 2, 10, NULL);
}

void CWriteEventLogTestDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	KillTimer(WM_TIMER + 2);
}

void CWriteEventLogTestDlg::OnBnClickedButton10()
{
	// TODO: Add your control notification handler code here
	ThreadRunFlag = FALSE;
}

void CWriteEventLogTestDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnBnClickedButton2();//停止Timer1
	OnBnClickedButton9();//停止Timer2
	OnBnClickedButton10();//终止写入线程

	OnCancel();
}

void CWriteEventLogTestDlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	CFile f;
	DWORD t1, t2;
	int Cnt = 10000 * 10;
	t1 = GetTickCount();
	BOOL b = f.Open("C:\\Temp\\Log.txt", CFile::modeCreate | CFile::modeReadWrite, NULL);
	if (b)
	{
		char buf[2048] = "12-08-03 11:33:48 实时表初始化完毕,向CVCommServerDrv发送“实时表初始化OK”的消息";
		//char buf[2048] = "abcdef";
		int BufSize = (int)strlen(buf);
		char CipherText[2048] = "";
		for (int i = 0; i < Cnt; i++)
		{
			RC4EncryptBuf(buf, BufSize, CipherText);
			f.Write(CipherText, BufSize);
			f.Write("\r\n", 2);
		}
		f.Close();
	}

	t2 = GetTickCount();
	CString Msg;
	Msg.Format("加密%d条记录，耗时：%dms，平均%d条/ms", Cnt, t2 - t1, Cnt / (t2 - t1));
	MessageBox(Msg, "提示：", MB_OK);
}

void CWriteEventLogTestDlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	DWORD t1, t2;
	t1 = GetTickCount();
	RC4LineEncryptFile("C:\\Temp\\Log.txt");

	//CStdioFile f;
	//CString s;
	//vector<CString> Dst;
	//BOOL b = f.Open("C:\\Temp\\Log.txt", CFile::modeRead | CFile::typeText, NULL);
	//if (b)
	//{
	//	char CipherText[2048] = "";
	//	int Len = 0;
	//	while(f.ReadString(s))
	//	{
	//		Len = s.GetLength();
	//		Encrypt(s.GetBuffer(), Len, CipherText);
	//		CipherText[Len] = 0;
	//		Dst.push_back(CipherText);

	//	}
	//	s.ReleaseBuffer();

	//	f.Close();

	//	BOOL b = f.Open("C:\\Temp\\Log.txt", CFile::modeCreate | CFile::modeReadWrite, NULL);
	//	if (b)
	//	{
	//		for (int i = 0; i < (int)Dst.size(); i++)
	//		{
	//			f.WriteString(Dst[i]);
	//			f.WriteString("\n");
	//		}
	//		f.Close();
	//	}
	//}
	t2 = GetTickCount();
	CString Msg;
	Msg.Format("解密耗时：%dms", t2 - t1);
	MessageBox(Msg, "提示：", MB_OK);

}

void CWriteEventLogTestDlg::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	DWORD t1, t2;
	t1 = GetTickCount();

	RC4EncryptFile("C:\\Temp\\Log.txt");

	t2 = GetTickCount();
	CString Msg;
	Msg.Format("整体加密耗时：%dms", t2 - t1);
	MessageBox(Msg, "提示：", MB_OK);

}

void CWriteEventLogTestDlg::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	DWORD t1, t2;
	t1 = GetTickCount();

	RC4EncryptFile("C:\\Temp\\Log.txt");

	t2 = GetTickCount();
	CString Msg;
	Msg.Format("整体解密耗时：%dms", t2 - t1);
	MessageBox(Msg, "提示：", MB_OK);
}
