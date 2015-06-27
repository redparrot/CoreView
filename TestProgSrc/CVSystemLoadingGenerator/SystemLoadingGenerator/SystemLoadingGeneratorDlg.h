// SystemLoadingGeneratorDlg.h : 头文件
//

#pragma once
//#include "MyTimer.h"
#include "afxcmn.h"
#include "afxwin.h"

const int CORE_MAX = 10;

//系统内存信息
struct SysMemInfo
{
	DWORD HandleCnt;
	DWORD ThreadCnt;
	DWORD ProcessCnt;
	DWORD PhysicalTotal;//物理内存总数
	float PhysicalMem;//使用了的物理内存，单位GB，与OS显示一致
	float PhysicalUsage;
	int	  CPUUsage;
	DWORD CommitLimit;//虚存最大值
	float CommitUsage;//已用虚存百分比
};

// CSystemLoadingGeneratorDlg 对话框
class CSystemLoadingGeneratorDlg : public CDialog
{
// 构造
public:
	CSystemLoadingGeneratorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SYSTEMLOADINGGENERATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	int CoreNums;//当前系统Cpu核心数目
	int CpuLoadThreadIdx[CORE_MAX];


	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	int GetSystemCoreNums();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedStop();
public:
	afx_msg void OnBnClickedButton1();
public:
	afx_msg void OnBnClickedButton2();
public:
	CSliderCtrl m_CpuLoad;
public:
	afx_msg void OnBnClickedCpuLoad();
public:
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
public:
	CStatic m_CpuRate;

public:
	int LoadingType;//使用率的类型，0表示固定使用率，1表示变化使用率
	SysMemInfo Smi;
	char *pDstMem;//加载的内存
	int MemSize;//加载的内存字节数

public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void GetSysLoadInfo(SysMemInfo& Spi);
public:
	afx_msg void OnBnMemLoad();
public:
	afx_msg void OnBnMemStop();
public:
	CSpinButtonCtrl m_MemIncre;
public:
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
public:
	afx_msg void OnBnClickedHandleLoad();
public:
	afx_msg void OnBnHandleStop();
public:
	CComboBox m_Priority;
};
