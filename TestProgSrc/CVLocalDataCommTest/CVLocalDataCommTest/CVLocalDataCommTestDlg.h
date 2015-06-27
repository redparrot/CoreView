// CVLocalDataCommTestDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CCVLocalDataCommTestDlg 对话框
class CCVLocalDataCommTestDlg : public CDialog
{
// 构造
public:
	CCVLocalDataCommTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CVLOCALDATACOMMTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnAddPidToTrend();
public:
	CListBox m_AList;
public:
	CListBox m_DList;
public:
	afx_msg void OnBnClickedOk3();
public:
	afx_msg void OnBnClickedOk4();
public:
	afx_msg void OnBnClickedOk5();
public:
	afx_msg void OnBnClickedOk6();
};
