// WriteEventLogTestDlg.h : ͷ�ļ�
//

#pragma once


// CWriteEventLogTestDlg �Ի���
class CWriteEventLogTestDlg : public CDialog
{
// ����
public:
	CWriteEventLogTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_WRITEEVENTLOGTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;
	HMODULE  hModule;
public:
	BOOL ThreadRunFlag;

	typedef BOOL (*DllFunction)(char*, char*);
	//DllFunction WriteEventLogWithAutoTime;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedButton1();//����Timer1������д�벻��ʱ��ļ�¼
	afx_msg void OnBnClickedButton2();//ֹͣTimer1
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();//�߳�����д���ʱ���log
	afx_msg void OnBnClickedButton10();//��ֹд���߳�
	afx_msg void OnBnClickedButton8();//����Timer2������д���ʱ��ļ�¼
	afx_msg void OnBnClickedButton9();//ֹͣTimer2
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
public:
	afx_msg void OnBnClickedButton11();
public:
	afx_msg void OnBnClickedButton12();
public:
	afx_msg void OnBnClickedButton13();
public:
	afx_msg void OnBnClickedButton14();
};
