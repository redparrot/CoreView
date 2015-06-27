// CVMimicDisplayTestDlg.h : ͷ�ļ�
//

#pragma once
#include "MinicLoop.h"

// CCVMimicDisplayTestDlg �Ի���
class CCVMimicDisplayTestDlg : public CDialog
{
// ����
public:
	CCVMimicDisplayTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CVMIMICDISPLAYTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	CString IniFileName;
	CMimicLoop MimicLoop;
	vector<CString> TotalFileList;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk3();

	void GetGrNoRange();

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedOk4();
	afx_msg void OnBnClickedOk5();
	afx_msg void OnBnClickedOk7();
	afx_msg void OnBnClickedOk8();
public:
	afx_msg void OnBnClickedNext();

	void ShowGrName();

public:
	afx_msg void OnBnClickedPrev();
public:
	afx_msg void OnFileListRefresh();
};
