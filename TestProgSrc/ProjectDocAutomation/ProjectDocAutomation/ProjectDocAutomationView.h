// ProjectDocAutomationView.h : CProjectDocAutomationView ��Ľӿ�
//


#pragma once


class CProjectDocAutomationView : public CView
{
protected: // �������л�����
	CProjectDocAutomationView();
	DECLARE_DYNCREATE(CProjectDocAutomationView)

// ����
public:
	CProjectDocAutomationDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CProjectDocAutomationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ProjectDocAutomationView.cpp �еĵ��԰汾
inline CProjectDocAutomationDoc* CProjectDocAutomationView::GetDocument() const
   { return reinterpret_cast<CProjectDocAutomationDoc*>(m_pDocument); }
#endif

