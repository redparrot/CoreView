// CVCV7ToCV8UpdateTestDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CCVCV7ToCV8UpdateTestDlg �Ի���
class CCVCV7ToCV8UpdateTestDlg : public CDialog
{
// ����
public:
	CCVCV7ToCV8UpdateTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CVCV7TOCV8UPDATETEST_DIALOG };

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
	CProgressCtrl m_ProgressCtrl;
};
