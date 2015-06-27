#pragma once
#include "afxcmn.h"


// CAutoSetDlg dialog

class CAutoSetDlg : public CDialog
{
	DECLARE_DYNAMIC(CAutoSetDlg)

public:
	CAutoSetDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAutoSetDlg();
	int  nItem;
	int x;
// Dialog Data
	enum { IDD = IDD_AUTO_SET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_AutoSetList;
public:
	virtual BOOL OnInitDialog();
	void SetFuncNameList();
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnBnClickedCancel();
public:
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
public:
	afx_msg void OnBnClickedCancel2();
public:
	afx_msg void OnBnClickedCancel3();
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
