// MultiStartTestDlg.h : ͷ�ļ�
//

#pragma once


// CMultiStartTestDlg �Ի���
class CMultiStartTestDlg : public CDialog
{
// ����
public:
	CMultiStartTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MULTISTARTTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	int Time;//���ڼ��
	int ProcessNums;//����ʵ���ĸ���
	CString ExePathName;//��ִ�г�������Ƽ�·��
	CString CmdLine;//��ִ�г���������в���

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
public:
	afx_msg void OnBnClickedCancel2();
public:
	afx_msg void OnBnClickedCancel();
public:
	afx_msg void OnBnClickedOk2();
};
