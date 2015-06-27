// CVMimicDefineCommdll_ImTestDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include <vector>
using namespace std;

// CCVMimicDefineCommdll_ImTestDlg 对话框
class CCVMimicDefineCommdll_ImTestDlg : public CDialog
{
// 构造
public:
	CCVMimicDefineCommdll_ImTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CVMIMICDEFINECOMMDLL_IMTEST_DIALOG };

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
	CListBox m_List;
public:
	afx_msg void OnBnClickedOk2();
public:
	afx_msg void OnBnClickedOk3();
	int GetMimicFileNameList();
public:
	afx_msg void OnBnClickedOk4();
	vector<CString> MimicFileNameList;
	char SrcfilePath[255];
	afx_msg void OnBnClickedOk6();
	afx_msg void OnBnClickedOk5();
	afx_msg void OnBnClickedOk8();
	afx_msg void OnBnClickedOk7();
	afx_msg void OnBnClickedOk9();

	int GetFileLen_MFC(CString FileName, time_t& ModifyTime);

	int GetFileLen_C(CString FileName, time_t& ModifyTime);
	afx_msg void OnBnClickedOk10();
	afx_msg void OnBnClickedOk11();
};
