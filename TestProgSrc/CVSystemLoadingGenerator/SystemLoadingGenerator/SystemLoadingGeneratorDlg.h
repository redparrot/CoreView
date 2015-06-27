// SystemLoadingGeneratorDlg.h : ͷ�ļ�
//

#pragma once
//#include "MyTimer.h"
#include "afxcmn.h"
#include "afxwin.h"

const int CORE_MAX = 10;

//ϵͳ�ڴ���Ϣ
struct SysMemInfo
{
	DWORD HandleCnt;
	DWORD ThreadCnt;
	DWORD ProcessCnt;
	DWORD PhysicalTotal;//�����ڴ�����
	float PhysicalMem;//ʹ���˵������ڴ棬��λGB����OS��ʾһ��
	float PhysicalUsage;
	int	  CPUUsage;
	DWORD CommitLimit;//������ֵ
	float CommitUsage;//�������ٷֱ�
};

// CSystemLoadingGeneratorDlg �Ի���
class CSystemLoadingGeneratorDlg : public CDialog
{
// ����
public:
	CSystemLoadingGeneratorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SYSTEMLOADINGGENERATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	int CoreNums;//��ǰϵͳCpu������Ŀ
	int CpuLoadThreadIdx[CORE_MAX];


	// ���ɵ���Ϣӳ�亯��
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
	int LoadingType;//ʹ���ʵ����ͣ�0��ʾ�̶�ʹ���ʣ�1��ʾ�仯ʹ����
	SysMemInfo Smi;
	char *pDstMem;//���ص��ڴ�
	int MemSize;//���ص��ڴ��ֽ���

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
