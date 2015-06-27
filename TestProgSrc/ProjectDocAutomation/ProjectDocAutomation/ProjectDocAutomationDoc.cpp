// ProjectDocAutomationDoc.cpp : CProjectDocAutomationDoc 类的实现
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


// CProjectDocAutomationDoc 构造/析构

CProjectDocAutomationDoc::CProjectDocAutomationDoc()
{
	// TODO: 在此添加一次性构造代码

}

CProjectDocAutomationDoc::~CProjectDocAutomationDoc()
{
}

BOOL CProjectDocAutomationDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CProjectDocAutomationDoc 序列化

void CProjectDocAutomationDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CProjectDocAutomationDoc 诊断

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


// CProjectDocAutomationDoc 命令
