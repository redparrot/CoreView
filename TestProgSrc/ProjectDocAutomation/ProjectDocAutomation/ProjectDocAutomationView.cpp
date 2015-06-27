// ProjectDocAutomationView.cpp : CProjectDocAutomationView ���ʵ��
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CProjectDocAutomationView ����/����

CProjectDocAutomationView::CProjectDocAutomationView()
{
	// TODO: �ڴ˴���ӹ������

}

CProjectDocAutomationView::~CProjectDocAutomationView()
{
}

BOOL CProjectDocAutomationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CProjectDocAutomationView ����

void CProjectDocAutomationView::OnDraw(CDC* /*pDC*/)
{
	CProjectDocAutomationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CProjectDocAutomationView ��ӡ

BOOL CProjectDocAutomationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CProjectDocAutomationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CProjectDocAutomationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CProjectDocAutomationView ���

#ifdef _DEBUG
void CProjectDocAutomationView::AssertValid() const
{
	CView::AssertValid();
}

void CProjectDocAutomationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProjectDocAutomationDoc* CProjectDocAutomationView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProjectDocAutomationDoc)));
	return (CProjectDocAutomationDoc*)m_pDocument;
}
#endif //_DEBUG


// CProjectDocAutomationView ��Ϣ�������
