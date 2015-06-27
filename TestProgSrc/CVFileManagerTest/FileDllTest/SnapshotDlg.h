#pragma once
#include "afxwin.h"
#include "MyList.h"


// CSnapshotDlg 对话框

class CSnapshotDlg : public CDialog
{
	DECLARE_DYNAMIC(CSnapshotDlg)

public:
	CSnapshotDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSnapshotDlg();

// 对话框数据
	enum { IDD = IDD_SNAPSHOT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	void TimerOper();

public:
	virtual BOOL OnInitDialog();
public:
	CMyList m_ProcessList;
	FILE * Log;
public:
	afx_msg void OnClose();
};
