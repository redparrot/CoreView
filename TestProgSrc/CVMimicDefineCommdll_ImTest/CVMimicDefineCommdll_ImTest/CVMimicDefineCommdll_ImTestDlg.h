// CVMimicDefineCommdll_ImTestDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include <vector>
using namespace std;

// CCVMimicDefineCommdll_ImTestDlg �Ի���
class CCVMimicDefineCommdll_ImTestDlg : public CDialog
{
// ����
public:
	CCVMimicDefineCommdll_ImTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CVMIMICDEFINECOMMDLL_IMTEST_DIALOG };

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
	CListBox m_List;
public:
	afx_msg void OnBnClickedOk2();
public:
	afx_msg void OnBnClickedOk3();
	int GetMimicFileNameList();
public:
	afx_msg void OnBnClickedOk4();
	vector<CString> MimicFileNameList;
	char SrcfilePath[255];
	afx_msg void OnBnClickedOk6();
	afx_msg void OnBnClickedOk5();
	afx_msg void OnBnClickedOk8();
	afx_msg void OnBnClickedOk7();
	afx_msg void OnBnClickedOk9();

	int GetFileLen_MFC(CString FileName, time_t& ModifyTime);

	int GetFileLen_C(CString FileName, time_t& ModifyTime);
	afx_msg void OnBnClickedOk10();
	afx_msg void OnBnClickedOk11();
};
