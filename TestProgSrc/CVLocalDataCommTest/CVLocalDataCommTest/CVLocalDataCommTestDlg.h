// CVLocalDataCommTestDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CCVLocalDataCommTestDlg �Ի���
class CCVLocalDataCommTestDlg : public CDialog
{
// ����
public:
	CCVLocalDataCommTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CVLOCALDATACOMMTEST_DIALOG };

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
