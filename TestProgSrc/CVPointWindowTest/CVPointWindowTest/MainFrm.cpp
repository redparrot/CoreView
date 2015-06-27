// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "CVPointWindowTest.h"
#include "c:\CoreView_src\FuncSrc\CVMimicSrc\include\cvmimictrenddisplaycomm.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define WM_NEW_POINTWINDOW		WM_USER + 100 //新增点窗口消息

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_COMMAND(ID_32771, &CMainFrame::OnStartPointWindow)
	ON_COMMAND(ID_32772, &CMainFrame::OnNewPointWindow)
	ON_COMMAND(ID_32773, &CMainFrame::On32773)
    ON_WM_PAINT()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	// 创建一个视图以占用框架的工作区
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("未能创建视图窗口\n");
		return -1;
	}
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}

	// TODO: 如果不需要工具栏可停靠，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}


// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame 消息处理程序

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// 将焦点前移到视图窗口
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// 让视图第一次尝试该命令
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// 否则，执行默认处理
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void CMainFrame::OnStartPointWindow()
{
	// TODO: 在此添加命令处理程序代码
	ShellExecute(m_hWnd, "open", "CVPointWindow_Im.exe", "8388609,0,0,50,25",
		"c:\\CoreView\\FuncExec\\exe\\", SW_SHOWNORMAL);
}

void CMainFrame::OnNewPointWindow()
{
	// TODO: 在此添加命令处理程序代码
	HWND hwnd = ::FindWindow("CVPointWindow_Im", NULL);

	LONG IID[5] = {0};
	COPYDATASTRUCT cpd;
	cpd.dwData = 0;
	IID[0] = 8388609;//8388609,0,0,50,25
	IID[1] = 0;
	IID[2] = 0;
	IID[3] = 400;
	IID[4] = 25;

	cpd.cbData = sizeof(IID);
	cpd.lpData = IID;

	::SendMessage(hwnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
}

void CMainFrame::On32773()
{
	// TODO: Add your command handler code here
	HDC hDC = NULL;
	BYTE Mode = 0;
	GT_TREND* pTrSpec = NULL;

    Ext_Input_Parameter ExtParameter;
	FgTrDisp(hDC, Mode, pTrSpec, ExtParameter);
}

void CMainFrame::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO: Add your message handler code here
    // Do not call CFrameWnd::OnPaint() for painting messages
}
