// ProgRedistributeDlg.h : ͷ�ļ�
//

#pragma once
#include "io.h"
#include "afxwin.h"

// CProgRedistributeDlg �Ի���
class CProgRedistributeDlg : public CDialog
{
// ����
public:
	CProgRedistributeDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PROGREDISTRIBUTE_DIALOG };

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
	BOOL IsFileExist(char* ExistingFileName, _finddata32_t &fileinfo);
public:
	CListBox m_List;
};
