// SystemLoadingGeneratorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SystemLoadingGenerator.h"
#include "SystemLoadingGeneratorDlg.h"
#include <complex>
#include <Psapi.h>
#pragma   comment(lib,"psapi.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

const DWORD HANDLE_MAX = 256 * 256 * 256;
int CpuLoadRunFlag[CORE_MAX];
CWinThread* CpuLoadThread[CORE_MAX];
int MemLoadRunFlag;
CWinThread* MemLoadThread;
double RATE = 0.5;
CSystemLoadingGeneratorDlg* pDlg;
HANDLE MyHandle[HANDLE_MAX];
DWORD MyHandleCnt = 0;
int HandleLoadRunFlag;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
const double SPLIT = 0.01;
const int COUNT = 200;
const double PI = 3.14159265;
const int INTERVAL = 300;
unsigned CpuThreadProcess(void* pParam)
{
	int idx = *((int*)pParam);
	CString s;
	s.Format("CPU负荷线程%d开始\n", idx);
	TRACE(s);

	//HANDLE m_hThread = CpuLoadThread[idx]->m_hThread;
	//::SetProcessAffinityMask(m_hThread, idx + 1); 
	if (pDlg->LoadingType == 0)//固定使用率
	{
		int busyTime = int(RATE * 1000);
		int idleTime = 1000 - busyTime;
		__int64 startTime = 0;
		while(CpuLoadRunFlag[idx] == 1)
		{
			startTime = GetTickCount();
			while((GetTickCount() - startTime) <= busyTime)
			{
				;
			}
			Sleep(idleTime);
		}
	} 
	else//变化使用率
	{
		DWORD busySpan[COUNT];
		DWORD idleSpan[COUNT];
		int half = INTERVAL / 2;
		double radian = 0.0;
		for(int i = 0; i < COUNT; i++)
		{
			busySpan[i] = (DWORD)(half + (sin(PI * radian) * half));
			idleSpan[i] = INTERVAL - busySpan[i];
			radian += SPLIT;
		}

		DWORD startTime = 0;       
		int j = 0;
		while (CpuLoadRunFlag[idx] == 1)
		{
			j = j % COUNT;
			startTime = GetTickCount();
			while ((GetTickCount() - startTime) <= busySpan[j]) ;
			Sleep(idleSpan[j]);
			j++;
		}
	}

	s.Format("CPU负荷线程%d结束\n", idx);
	TRACE(s);
	return (idx + 1) * 100;//线程结束码
}

unsigned MemThreadProcess(void* pParam)
{
	//int idx = *((int*)pParam);
	CString s;
	s.Format("Memory负荷线程开始\n");
	TRACE(s);

	char CH;
	DWORD HalfSize = 0;
	HalfSize = pDlg->MemSize / 2;
	while(MemLoadRunFlag == 1)
	{
		CH = 'W';
		memset(pDlg->pDstMem, CH, pDlg->MemSize);

		Sleep(5000);
	}

	s.Format("Memory负荷线程结束\n");
	TRACE(s);
	return 300;//线程结束码
}

unsigned HandleThreadProcess(void* pParam)
{
	while(HandleLoadRunFlag == 1)
	{
		for (int i = 0; i < 1000; i++)
		{
			HANDLE hEvent = CreateEvent(NULL, FALSE, FALSE, "HandleTest");
			MyHandle[MyHandleCnt++] = hEvent;
			if (MyHandleCnt == 0xff8000)
			{
				return 400;
			}
		}
	}

	return 400;
}

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

// CSystemLoadingGeneratorDlg 对话框

CSystemLoadingGeneratorDlg::CSystemLoadingGeneratorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSystemLoadingGeneratorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	pDstMem = NULL;
 
}

void CSystemLoadingGeneratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_CpuLoad);
	DDX_Control(pDX, IDC_CPU_RATE, m_CpuRate);
	DDX_Control(pDX, IDC_SPIN1, m_MemIncre);
	DDX_Control(pDX, IDC_COMBO1, m_Priority);
}

BEGIN_MESSAGE_MAP(CSystemLoadingGeneratorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CSystemLoadingGeneratorDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CSystemLoadingGeneratorDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK2, &CSystemLoadingGeneratorDlg::OnBnClickedStop)
	//ON_BN_CLICKED(IDC_BUTTON1, &CSystemLoadingGeneratorDlg::OnBnClickedButton1)
	//ON_BN_CLICKED(IDC_BUTTON2, &CSystemLoadingGeneratorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_CPU_LOAD, &CSystemLoadingGeneratorDlg::OnBnClickedCpuLoad)
	ON_WM_HSCROLL()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_MEM_LOAD, &CSystemLoadingGeneratorDlg::OnBnMemLoad)
	ON_BN_CLICKED(IDOK4, &CSystemLoadingGeneratorDlg::OnBnMemStop)
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_HANDLE_LOAD, &CSystemLoadingGeneratorDlg::OnBnClickedHandleLoad)
	ON_BN_CLICKED(IDOK5, &CSystemLoadingGeneratorDlg::OnBnHandleStop)
END_MESSAGE_MAP()


// CSystemLoadingGeneratorDlg 消息处理程序

BOOL CSystemLoadingGeneratorDlg::OnInitDialog()
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
	CoreNums = GetSystemCoreNums();
	pDlg = this;
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);
	m_CpuLoad.SetRange(0, 100);
	m_CpuLoad.SetPos(50);
	SetTimer(1, 1000, NULL);

	m_MemIncre.SetRange(1, 20);
	m_MemIncre.SetPos(2);
	SetDlgItemInt(IDC_MEM_INCRE, 10);

	m_Priority.AddString("Real Time");
	m_Priority.AddString("High");
	m_Priority.AddString("Above Normal");
	m_Priority.AddString("Normal");
	m_Priority.AddString("Below Normal");
	m_Priority.AddString("Low");
	m_Priority.AddString("Idle");
	m_Priority.SetCurSel(3);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSystemLoadingGeneratorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSystemLoadingGeneratorDlg::OnPaint()
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
HCURSOR CSystemLoadingGeneratorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int CSystemLoadingGeneratorDlg::GetSystemCoreNums()
{
	SYSTEM_INFO info;
	GetSystemInfo(&info);
	return info.dwNumberOfProcessors;
}

void CSystemLoadingGeneratorDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CoreNums = 1;
	for (int i = 0; i < CoreNums; i++)
	{
		CpuLoadThreadIdx[i] = i;
		CpuLoadRunFlag[i] = 1;
		CpuLoadThread[i] = AfxBeginThread((AFX_THREADPROC)CpuThreadProcess, &(CpuLoadThreadIdx[i]), THREAD_PRIORITY_HIGHEST);
		Sleep(10);
	}

	//Timer.Create(TimerCyc);
}

void CSystemLoadingGeneratorDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
}

void CSystemLoadingGeneratorDlg::OnBnClickedStop()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < CoreNums; i++)
	{
		CpuLoadRunFlag[i] = 0;
		Sleep(10);
	}

	GetDlgItem(IDC_CPU_LOAD)->EnableWindow(TRUE);
	GetDlgItem(IDCANCEL)->EnableWindow(TRUE);
}

void CSystemLoadingGeneratorDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	::SetProcessAffinityMask(::GetCurrentProcess(), 0x00000001 ); 
	int busyTime = 900;
	int idleTime = 100;
	__int64 startTime = 0;
	while(1)
	{
		startTime = GetTickCount();
		while((GetTickCount() - startTime) <= busyTime)
		{
			;
		}
		Sleep(idleTime);
	}
}

void CSystemLoadingGeneratorDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	::SetProcessAffinityMask(::GetCurrentProcess(), 0x00000001 );  
	DWORD busySpan[COUNT];  //array of busy times
	DWORD idleSpan[COUNT];  //array of idle times
	int half = INTERVAL / 2;
	double radian = 0.0;
	for(int i = 0; i < COUNT; i++)
	{
		busySpan[i] = (DWORD)(half + (sin(PI * radian) * half));
		idleSpan[i] = INTERVAL - busySpan[i];
		radian += SPLIT;
	}

	DWORD startTime = 0;       
	int j = 0;
	while (true)
	{
		j = j % COUNT;
		startTime = GetTickCount();
		while ((GetTickCount() - startTime) <= busySpan[j]) ;
		Sleep(idleSpan[j]);
		j++;
	}
}

void CSystemLoadingGeneratorDlg::OnBnClickedCpuLoad()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_CPU_LOAD)->EnableWindow(FALSE);
	GetDlgItem(IDCANCEL)->EnableWindow(FALSE);

	//获取负荷率
	int Pos = m_CpuLoad.GetPos();
	RATE = Pos * 0.01;

	//获取优先级
	int PrioritySel = m_Priority.GetCurSel();
	int nPriority = 0;
	switch (PrioritySel)
	{
	case 0:
		nPriority = THREAD_PRIORITY_TIME_CRITICAL;
		break;
	case 1:
		nPriority = THREAD_PRIORITY_HIGHEST;
		break;
	case 2:
		nPriority = THREAD_PRIORITY_ABOVE_NORMAL;
		break;
	case 3:
		nPriority = THREAD_PRIORITY_NORMAL;
		break;
	case 4:
		nPriority = THREAD_PRIORITY_BELOW_NORMAL;
		break;
	case 5:
		nPriority = THREAD_PRIORITY_LOWEST;
		break;
	case 6:
		nPriority = THREAD_PRIORITY_IDLE;
		break;
	default:
		break;
	}

	LoadingType = GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO2) - IDC_RADIO1;
	for (int i = 0; i < CoreNums; i++)
	{
		CpuLoadThreadIdx[i] = i;
		CpuLoadRunFlag[i] = 1;
		CpuLoadThread[i] = AfxBeginThread((AFX_THREADPROC)CpuThreadProcess, &(CpuLoadThreadIdx[i]), nPriority);
		HANDLE m_hThread = CpuLoadThread[i]->m_hThread;
		::SetProcessAffinityMask(m_hThread, i + 1); 
		Sleep(10);
	}
}

void CSystemLoadingGeneratorDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pScrollBar->GetDlgCtrlID() == IDC_SLIDER1)
	{
		int pos = m_CpuLoad.GetPos();
		if (pos == 100)
			pos = 99;

		CString s;
		s.Format("%d%%", pos);
		m_CpuRate.SetWindowText(s);
	}

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CSystemLoadingGeneratorDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 1)//周期获取物理内存使用率
	{
		GetSysLoadInfo(Smi);
		CString s; 
		s.Format("%d%%", (int)Smi.PhysicalUsage);
		SetDlgItemText(IDC_MEM, s);

		s.Format("%d", (int)Smi.HandleCnt);
		SetDlgItemText(IDC_HANDLE, s);
	}

	CDialog::OnTimer(nIDEvent);
}

void CSystemLoadingGeneratorDlg::GetSysLoadInfo(SysMemInfo& Smi)
{
	PERFORMANCE_INFORMATION PerformanceInformation;
	DWORD cb = sizeof(PERFORMANCE_INFORMATION);
	BOOL b = GetPerformanceInfo(&PerformanceInformation, cb);

	Smi.HandleCnt = PerformanceInformation.HandleCount;
	Smi.ThreadCnt = PerformanceInformation.ThreadCount;
	Smi.ProcessCnt = PerformanceInformation.ProcessCount;

	Smi.PhysicalTotal = DWORD(PerformanceInformation.PhysicalTotal * 4);
	Smi.PhysicalMem = ((float)PerformanceInformation.PhysicalTotal * 4 - PerformanceInformation.PhysicalAvailable * 4) / 1024 / 1024;
	Smi.PhysicalUsage = 1 - ((float)PerformanceInformation.PhysicalAvailable * 4) / (PerformanceInformation.PhysicalTotal * 4);
	Smi.PhysicalUsage = Smi.PhysicalUsage * 100;
	Smi.CommitLimit = DWORD(PerformanceInformation.CommitLimit * 4);
	Smi.CommitUsage = float((PerformanceInformation.CommitTotal * 4.0) / (PerformanceInformation.CommitLimit * 4));
	Smi.CommitUsage = Smi.CommitUsage * 100;

	char s[1024] = {0};
	sprintf_s(s, sizeof(s), 
		"CommitTotal=%d,CommitLimit=%d,CommitPeak=%d,\n\
		PhysicalTotal=%d,PhysicalAvailable=%d,SystemCache=%d,PhysicalMem=%fGB,PhysicalUsage=%f\n\
		PageSize=%d,\n\
		HandleCount=%d,\n\
		ThreadCount=%d,\n\
		ProcessCount=%d\n", 

		PerformanceInformation.CommitTotal * 4, //单位是KB
		PerformanceInformation.CommitLimit * 4, 
		PerformanceInformation.CommitPeak * 4,

		PerformanceInformation.PhysicalTotal * 4,
		PerformanceInformation.PhysicalAvailable * 4,
		PerformanceInformation.SystemCache * 4,
		Smi.PhysicalMem,
		Smi.PhysicalUsage,
		PerformanceInformation.PageSize,
		PerformanceInformation.HandleCount,
		PerformanceInformation.ThreadCount,
		PerformanceInformation.ProcessCount);

	//TRACE(s);
	return;
}

void CSystemLoadingGeneratorDlg::OnBnMemLoad()
{
	//获取物理内存的容量,计算加载内存大小,单位KB
	GetDlgItem(IDC_MEM_LOAD)->EnableWindow(FALSE);
	GetDlgItem(IDCANCEL)->EnableWindow(FALSE);

	int Incre = GetDlgItemInt(IDC_MEM_INCRE);

	DWORD DstMem = (DWORD)(Smi.PhysicalTotal * Incre * 0.01);

	//加入指定百分比的内存使用
	MemSize = DstMem * 1024;
	try
	{
		pDstMem = new char[MemSize];
	}
	catch (CMemoryException* e)
	{
		e;
		MessageBox("物理内存申请过多", "错误", MB_OK);
		GetDlgItem(IDC_MEM_LOAD)->EnableWindow(TRUE);
		GetDlgItem(IDCANCEL)->EnableWindow(TRUE);
		return;
	}

	MemLoadRunFlag = 1;
	MemLoadThread = AfxBeginThread((AFX_THREADPROC)MemThreadProcess, NULL, THREAD_PRIORITY_HIGHEST);
}

void CSystemLoadingGeneratorDlg::OnBnMemStop()
{
	// TODO: 在此添加控件通知处理程序代码
	MemLoadRunFlag = 0;

	if (pDstMem != NULL)
	{
		delete[] pDstMem;
		pDstMem = NULL;
	}
	GetDlgItem(IDC_MEM_LOAD)->EnableWindow(TRUE);
	GetDlgItem(IDCANCEL)->EnableWindow(TRUE);
}

void CSystemLoadingGeneratorDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(pScrollBar->GetDlgCtrlID() == IDC_SPIN1)
	{
		if (nSBCode == SB_ENDSCROLL || nSBCode == SB_THUMBPOSITION)
		{
			TRACE("nPos:%d\n", nPos);
			SetDlgItemInt(IDC_MEM_INCRE, nPos * 5);
		}
	}

	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CSystemLoadingGeneratorDlg::OnBnClickedHandleLoad()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_HANDLE_LOAD)->EnableWindow(FALSE);
	GetDlgItem(IDCANCEL)->EnableWindow(FALSE);

	HandleLoadRunFlag = 1;
	AfxBeginThread((AFX_THREADPROC)HandleThreadProcess, NULL, THREAD_PRIORITY_HIGHEST);


	//if (MyHandleCnt >= HANDLE_MAX)
	//{
	//	MessageBox("句柄创建过多", "错误", MB_OK);
	//	return;
	//}

	//for (int i = 0; i < 20000; i++)
	//{
	//	HANDLE hEvent = CreateEvent(NULL, FALSE, FALSE, "HandleTest");
	//	MyHandle[MyHandleCnt++] = hEvent;
	//}

	//TRACE("MyHandleCnt = %d\n", MyHandleCnt);
}

void CSystemLoadingGeneratorDlg::OnBnHandleStop()
{
	// TODO: 在此添加控件通知处理程序代码
	HandleLoadRunFlag = 0;

	for (DWORD i = 0; i < MyHandleCnt; i++)
	{
		CloseHandle(MyHandle[i]);
	}

	GetDlgItem(IDC_HANDLE_LOAD)->EnableWindow(TRUE);
	GetDlgItem(IDCANCEL)->EnableWindow(TRUE);

}
