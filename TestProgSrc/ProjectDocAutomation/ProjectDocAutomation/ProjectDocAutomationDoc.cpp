// ProjectDocAutomationDoc.cpp : CProjectDocAutomationDoc ���ʵ��
//

#include "stdafx.h"
#include "ProjectDocAutomation.h"

#include "ProjectDocAutomationDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProjectDocAutomationDoc

IMPLEMENT_DYNCREATE(CProjectDocAutomationDoc, CDocument)

BEGIN_MESSAGE_MAP(CProjectDocAutomationDoc, CDocument)
END_MESSAGE_MAP()


// CProjectDocAutomationDoc ����/����

CProjectDocAutomationDoc::CProjectDocAutomationDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CProjectDocAutomationDoc::~CProjectDocAutomationDoc()
{
}

BOOL CProjectDocAutomationDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CProjectDocAutomationDoc ���л�

void CProjectDocAutomationDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CProjectDocAutomationDoc ���

#ifdef _DEBUG
void CProjectDocAutomationDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CProjectDocAutomationDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CProjectDocAutomationDoc ����
