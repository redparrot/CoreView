// MyList.cpp : 实现文件
//

#include "stdafx.h"
#include "FileDllTest.h"
#include "MyList.h"


// CMyList

IMPLEMENT_DYNAMIC(CMyList, CListCtrl)

CMyList::CMyList()
{

}

CMyList::~CMyList()
{
}


BEGIN_MESSAGE_MAP(CMyList, CListCtrl)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CMyList 消息处理程序



BOOL CMyList::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	return TRUE;
	//return CListCtrl::OnEraseBkgnd(pDC);
}
