// MyList.cpp : ʵ���ļ�
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



// CMyList ��Ϣ�������



BOOL CMyList::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	return TRUE;
	//return CListCtrl::OnEraseBkgnd(pDC);
}
