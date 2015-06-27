// CVPrintManagerTestDlg.h : 头文件
//

#pragma once

// CCVPrintManagerTestDlg 对话框
class CCVPrintManagerTestDlg : public CDialog
{
// 构造
public:
	CCVPrintManagerTestDlg(CWnd* pParent = NULL);	// 标准构造函数


// 对话框数据
	enum { IDD = IDD_CVPRINTMANAGERTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	HMODULE  hModule;
	CString DllFileName;
	CString ExePath;
	int LoopCnt;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
public:
	afx_msg void OnBnClickedButton2();
public:
	afx_msg void OnBnClickedButton3();
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
public:
	afx_msg void OnClose();
public:
	afx_msg void OnBnClickedButton4();
public:
	afx_msg void OnBnClickedButton5();
public:
	afx_msg void OnBnClickedButton6();
public:
	afx_msg void OnBnClickedButton7();
public:
	afx_msg void OnBnClickedButton8();
public:
	afx_msg void OnBnClickedButton9();
public:
	afx_msg void OnBnClickedButton10();

public:
	CString CCVPrintManagerTestDlg::GetDataFileName();
public:
	afx_msg void OnBnClickedButton12();
public:
	afx_msg void OnBnClickedButton15();
public:
	afx_msg void OnBnClickedButton13();
public:
	afx_msg void OnBnClickedButton14();
public:
	afx_msg void OnBnClickedButton11();
	CString GetExePath();
public:
	afx_msg void OnBnClickedButton16();
public:
	afx_msg void OnBnClickedButton17();
};
