// CVPrecordDspTestDlg.h : 头文件
//

#pragma once

typedef struct Precord_T
{
	BYTE	 Type[2];
	time_t	 RecdTime;
	long	 RecdIID;
	FLOAT	 Value1;
	FLOAT	 Value2;
	BYTE	 Flag;
}Precord_T;
// CCVPrecordDspTestDlg 对话框
class CCVPrecordDspTestDlg : public CDialog
{
// 构造
public:
	CCVPrecordDspTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CVPRECORDDSPTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	HANDLE	m_hMap;				//共享内存句柄
	char *	m_pMap;				//共享内存指针
	time_t	m_ChgFileTime;		//变化的文件名称
	time_t  m_DelDate;			//需要删除的日期
	int		ChgFileMax;			//最大变化文件个数
	CStringArray DirList;		//文件夹列表

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
public:
	afx_msg void OnBnClickedCancel();
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
protected:
//	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
	afx_msg void OnBnClickedButton2();
public://自定义函数
	void CCVPrecordDspTestDlg::SetSimFile(CString File, DWORD Time);//仿真文件
	CString CCVPrecordDspTestDlg::GetDataFileList();
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
public:
	afx_msg void OnBnClickedButton3();
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
	afx_msg void OnBnClickedButton11();
public:
	afx_msg void OnBnClickedButton12();
};
