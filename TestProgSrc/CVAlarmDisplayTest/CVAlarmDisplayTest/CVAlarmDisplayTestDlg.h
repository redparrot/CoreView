// CVAlarmDisplayTestDlg.h : ͷ�ļ�
//

#pragma once
#include "CVAlarmDisplayComm.h"


// CCVAlarmDisplayTestDlg �Ի���

class CCVAlarmDisplayTestDlg : public CDialog
{
// ����
public:
	CCVAlarmDisplayTestDlg(CWnd* pParent = NULL);	// ��׼���캯��
	HANDLE	m_hAlarmMap;						//�����ڴ���
	SAlarmShareMem*	m_pAlarmMap;				//�����ڴ�ָ��
	SAlarmShareMem m_AlarmInfo;					//�����ڴ���һ������������

// �Ի�������
	enum { IDD = IDD_CVALARMDISPLAYTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk2();
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnBnClickedCancel();
public:
	afx_msg void OnBnClickedOk3();
public:
	afx_msg void OnBnClickedOk4();
public:
	afx_msg void OnBnClickedOk5();
public:
	afx_msg void OnBnClickedOk6();
public:
	afx_msg void OnBnClickedOk7();
public:
	afx_msg void OnBnClickedOk8();
public:
	afx_msg void OnBnClickedOk10();
public:
	afx_msg void OnBnClickedOk9();
public:
	afx_msg void OnBnClickedOk17();
public:
	afx_msg void OnBnClickedOk18();
public:
	afx_msg void OnBnClickedOk11();
public:
	afx_msg void OnBnClickedOk12();
public:
	afx_msg void OnBnClickedOk13();
public:
	afx_msg void OnBnClickedOk14();
public:
	afx_msg void OnClose();
public:
	afx_msg void OnBnClickedOk15();
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
public:
	afx_msg void OnBnClickedOk19();
public:
	afx_msg void OnBnClickedOk20();
public:
	afx_msg void OnBnClickedOk21();
public:
	afx_msg void OnBnClickedOk22();
public:
	afx_msg void OnBnClickedOk23();
public:
	afx_msg void OnBnClickedOk24();
public:
	short CCVAlarmDisplayTestDlg::GetAlarmCount(SAlarmShareMem* m_pDataMap);
public:
	afx_msg void OnBnClickedOk25();
public:
	afx_msg void OnBnClickedOk26();
public:
	afx_msg void OnBnClickedOk27();
public:
	afx_msg void OnBnClickedOk30();
public:
	afx_msg void OnBnClickedOk28();
public:
	afx_msg void OnBnClickedOk29();
};
