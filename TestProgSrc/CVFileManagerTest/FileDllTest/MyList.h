#pragma once


// CMyList

class CMyList : public CListCtrl
{
	DECLARE_DYNAMIC(CMyList)

public:
	CMyList();
	virtual ~CMyList();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};


