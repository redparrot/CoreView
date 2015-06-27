// CVEnumPocInNetTestDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include <vector>
using namespace std;


// CCVEnumPocInNetTestDlg 对话框
class CCVEnumPocInNetTestDlg : public CDialog
{
// 构造
public:
	CCVEnumPocInNetTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CVENUMPOCINNETTEST_DIALOG };

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
	CListCtrl m_List;
public:
	afx_msg void OnBnClickedCancel2();
public:
	afx_msg void OnBnClickedCancel3();
	afx_msg void OnBnClickedCancel4();
	afx_msg void OnBnClickedCancel5();
	void StrToken(char* buf, char* seps, vector<CString>& List);
};
