// CVPrecordDspTestDlg.h : ͷ�ļ�
//

#pragma once

typedef struct Precord_T
{
	BYTE	 Type[2];
	time_t	 RecdTime;
	long	 RecdIID;
	FLOAT	 Value1;
	FLOAT	 Value2;
	BYTE	 Flag;
}Precord_T;
// CCVPrecordDspTestDlg �Ի���
class CCVPrecordDspTestDlg : public CDialog
{
// ����
public:
	CCVPrecordDspTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CVPRECORDDSPTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	HANDLE	m_hMap;				//�����ڴ���
	char *	m_pMap;				//�����ڴ�ָ��
	time_t	m_ChgFileTime;		//�仯���ļ�����
	time_t  m_DelDate;			//��Ҫɾ��������
	int		ChgFileMax;			//���仯�ļ�����
	CStringArray DirList;		//�ļ����б�

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
public:
	afx_msg void OnBnClickedCancel();
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
protected:
//	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
	afx_msg void OnBnClickedButton2();
public://�Զ��庯��
	void CCVPrecordDspTestDlg::SetSimFile(CString File, DWORD Time);//�����ļ�
	CString CCVPrecordDspTestDlg::GetDataFileList();
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
public:
	afx_msg void OnBnClickedButton3();
public:
	afx_msg void OnBnClickedButton4();
public:
	afx_msg void OnBnClickedButton5();
public:
	afx_msg void OnBnClickedButton6();
public:
	afx_msg void OnBnClickedButton7();
public:
	afx_msg void OnBnClickedButton8();
public:
	afx_msg void OnBnClickedButton9();
public:
	afx_msg void OnBnClickedButton10();
public:
	afx_msg void OnBnClickedButton11();
public:
	afx_msg void OnBnClickedButton12();
};
