#pragma once
#include "afxwin.h"
#include "MyList.h"


// CSnapshotDlg �Ի���

class CSnapshotDlg : public CDialog
{
	DECLARE_DYNAMIC(CSnapshotDlg)

public:
	CSnapshotDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSnapshotDlg();

// �Ի�������
	enum { IDD = IDD_SNAPSHOT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
