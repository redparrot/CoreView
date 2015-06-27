// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "CVPointWindowTest.h"
#include "c:\CoreView_src\FuncSrc\CVMimicSrc\include\cvmimictrenddisplaycomm.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define WM_NEW_POINTWINDOW		WM_USER + 100 //�����㴰����Ϣ

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
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	// ����һ����ͼ��ռ�ÿ�ܵĹ�����
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("δ�ܴ�����ͼ����\n");
		return -1;
	}
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}

	// TODO: �������Ҫ��������ͣ������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}


// CMainFrame ���

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


// CMainFrame ��Ϣ�������

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// ������ǰ�Ƶ���ͼ����
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// ����ͼ��һ�γ��Ը�����
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// ����ִ��Ĭ�ϴ���
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void CMainFrame::OnStartPointWindow()
{
	// TODO: �ڴ���������������
	ShellExecute(m_hWnd, "open", "CVPointWindow_Im.exe", "8388609,0,0,50,25",
		"c:\\CoreView\\FuncExec\\exe\\", SW_SHOWNORMAL);
}

void CMainFrame::OnNewPointWindow()
{
	// TODO: �ڴ���������������
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
