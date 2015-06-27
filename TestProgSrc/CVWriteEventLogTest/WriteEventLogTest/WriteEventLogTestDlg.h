// WriteEventLogTestDlg.h : 头文件
//

#pragma once


// CWriteEventLogTestDlg 对话框
class CWriteEventLogTestDlg : public CDialog
{
// 构造
public:
	CWriteEventLogTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_WRITEEVENTLOGTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;
	HMODULE  hModule;
public:
	BOOL ThreadRunFlag;

	typedef BOOL (*DllFunction)(char*, char*);
	//DllFunction WriteEventLogWithAutoTime;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedButton1();//启动Timer1，周期写入不带时间的记录
	afx_msg void OnBnClickedButton2();//停止Timer1
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();//线程周期写入带时间的log
	afx_msg void OnBnClickedButton10();//终止写入线程
	afx_msg void OnBnClickedButton8();//启动Timer2，周期写入带时间的记录
	afx_msg void OnBnClickedButton9();//停止Timer2
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
public:
	afx_msg void OnBnClickedButton11();
public:
	afx_msg void OnBnClickedButton12();
public:
	afx_msg void OnBnClickedButton13();
public:
	afx_msg void OnBnClickedButton14();
};
