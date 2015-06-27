// ProjectDocAutomationView.cpp : CProjectDocAutomationView 类的实现
//

#include "stdafx.h"
#include "ProjectDocAutomation.h"

#include "ProjectDocAutomationDoc.h"
#include "ProjectDocAutomationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProjectDocAutomationView

IMPLEMENT_DYNCREATE(CProjectDocAutomationView, CView)

BEGIN_MESSAGE_MAP(CProjectDocAutomationView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CProjectDocAutomationView 构造/析构

CProjectDocAutomationView::CProjectDocAutomationView()
{
	// TODO: 在此处添加构造代码

}

CProjectDocAutomationView::~CProjectDocAutomationView()
{
}

BOOL CProjectDocAutomationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CProjectDocAutomationView 绘制

void CProjectDocAutomationView::OnDraw(CDC* /*pDC*/)
{
	CProjectDocAutomationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CProjectDocAutomationView 打印

BOOL CProjectDocAutomationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CProjectDocAutomationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CProjectDocAutomationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清除过程
}


// CProjectDocAutomationView 诊断

#ifdef _DEBUG
void CProjectDocAutomationView::AssertValid() const
{
	CView::AssertValid();
}

void CProjectDocAutomationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProjectDocAutomationDoc* CProjectDocAutomationView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProjectDocAutomationDoc)));
	return (CProjectDocAutomationDoc*)m_pDocument;
}
#endif //_DEBUG


// CProjectDocAutomationView 消息处理程序
