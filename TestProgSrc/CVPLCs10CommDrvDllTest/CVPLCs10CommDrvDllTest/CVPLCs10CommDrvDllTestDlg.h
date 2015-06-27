// CVPLCs10CommDrvDllTestDlg.h : 头文件
//

#pragma once
#include "Afxdao.h"


// CCVPLCs10CommDrvDllTestDlg 对话框
class CCVPLCs10CommDrvDllTestDlg : public CDialog
{
// 构造
public:
	CCVPLCs10CommDrvDllTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CVPLCS10COMMDRVDLLTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	HMENU hMenu;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnClose();
public:
	afx_msg void OnBnClickedOk2();
public:
	afx_msg void OnBnClickedOk3();
};
