// CVEnumPocInNetTestDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include <vector>
using namespace std;


// CCVEnumPocInNetTestDlg �Ի���
class CCVEnumPocInNetTestDlg : public CDialog
{
// ����
public:
	CCVEnumPocInNetTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CVENUMPOCINNETTEST_DIALOG };

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
	CListCtrl m_List;
public:
	afx_msg void OnBnClickedCancel2();
public:
	afx_msg void OnBnClickedCancel3();
	afx_msg void OnBnClickedCancel4();
	afx_msg void OnBnClickedCancel5();
	void StrToken(char* buf, char* seps, vector<CString>& List);
};
