// CVAdminTestDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "c:\coreview_src\include\cvsapcommdef.h"
#include "c:\coreview_src\include\cvdevicecommdll.h"
#pragma comment(lib, "C:\\CoreView\\SystemExec\\bin\\CVDeviceCommDll.lib")
#include "C:\CoreView_src\Include\pingcomm.h"
#include <vector>
using namespace std;

typedef struct PocNetSts
{
	char	POCName[20];
	ULONG	IP;
}PocNetSts;

// CCVAdminTestDlg �Ի���
class CCVAdminTestDlg : public CDialog
{
// ����
public:
	CCVAdminTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CVADMINTEST_DIALOG };

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
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk2();
	afx_msg void OnBnClickedOk3();
	afx_msg void OnBnClickedOk4();
	afx_msg void OnBnClickedOk5();
	BOOL ConnIPC (char *RemoteName, char *RemoteUser, char *RemotePass);
	BOOL DisIpcConnect (char *RemoteName);
	void GetPOCNameList(OUT vector<PocNetSts> &NameList);
	int PingHost(CString IP1, CString IP2);
	CString GetExePath();

public:
	CListCtrl m_List;
	CImageList m_Image;	//����POCͼ��
	BOOL bProcessing;
	vector<PocNetSts> NameList;
	HICON	hIcon;
	BOOL RunFlag;
	CString ExePath;

public:
	afx_msg void OnBnClickedButton1();
public:
	CProgressCtrl m_Progress;
	afx_msg void OnBnClickedOk6();
	afx_msg void OnBnClickedOk7();
};
