// CVPLCs10CommDrvDllTestDlg.h : ͷ�ļ�
//

#pragma once
#include "Afxdao.h"


// CCVPLCs10CommDrvDllTestDlg �Ի���
class CCVPLCs10CommDrvDllTestDlg : public CDialog
{
// ����
public:
	CCVPLCs10CommDrvDllTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CVPLCS10COMMDRVDLLTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	HMENU hMenu;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnClose();
public:
	afx_msg void OnBnClickedOk2();
public:
	afx_msg void OnBnClickedOk3();
};
