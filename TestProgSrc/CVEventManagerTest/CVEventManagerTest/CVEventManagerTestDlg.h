// CVEventManagerTestDlg.h : ͷ�ļ�
//

#pragma once
#include <vector>
using namespace std;

// CCVEventManagerTestDlg �Ի���
typedef struct InstantAlmRecd_T{
	time_t       AlmTime;
	long         IID;	
	char         AlmType;	
}InstantAlmRecd_T;//��ʱ���������ڴ��¼�ṹ
#define      G_INSTANTALMMEM    "InstantAlmMem"//��ʱ�����ڴ���

struct CEnumDesktopWindow
{
	HWND hWnd;
	CString Title;
	CString ClassName;
	CRect Rect;
};

class CCVEventManagerTestDlg : public CDialog
{
// ����
public:
	CCVEventManagerTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CVEVENTMANAGERTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	HANDLE	m_hAlarmMap;							//�����ڴ���
	InstantAlmRecd_T*	m_pAlarmMap;				//�����ڴ�ָ��
	InstantAlmRecd_T m_AlarmInfo;					//�����ڴ���һ������������
	BOOL bRun;
	vector<CString> MimicFileNameList;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk37();
	afx_msg void OnBnClickedOk38();
	afx_msg void OnBnClickedOk39();
	afx_msg void OnBnClickedOk40();
	afx_msg void OnBnClickedOk41();
	afx_msg void OnBnClickedOk42();
	afx_msg void OnBnClickedOk43();
	afx_msg void OnClose();
	afx_msg void OnBnClickedOk44();
	afx_msg void OnBnClickedOk45();
	afx_msg void OnBnClickedOk46();
	afx_msg void OnBnClickedOk47();
	afx_msg void OnBnClickedOk48();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedOk49();
	afx_msg void OnBnClickedOk50();
	afx_msg void OnBnClickedOk51();
	afx_msg void OnBnClickedOk52();
	afx_msg void OnBnClickedOk53();
	afx_msg void OnBnClickedOk54();
	afx_msg void OnBnClickedOk55();
	afx_msg void OnBnClickedOk56();
	afx_msg void OnBnClickedOk57();
	afx_msg void OnBnClickedOk58();
	afx_msg void OnBnClickedOk59();
	afx_msg void OnBnClickedOk60();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedOk61();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnTopmostCore();
	int EnumDesktopWindow(vector<CEnumDesktopWindow>& EnumDesktopWindowList);
	afx_msg void OnMinimizeToolManager();
	afx_msg void OnStartMultCrtop();//˲���������Crtopʵ��
	afx_msg void OnCloseCrtop();//�ر�Crtop����
public:
	afx_msg void OnBnClickedButton6();
public:
	afx_msg void OnBnClickedButton7();
public:
	afx_msg void OnBnClickedButton8();
public:
	afx_msg void OnBnClickedOk65();
public:
	afx_msg void OnBnClickedButton9();
public:
	afx_msg void OnBnClickedButton10();
public:
	afx_msg void OnBnClickedOk66();
public:
	afx_msg void OnBnClickedOk67();
public:
	afx_msg void OnBnClickedOk68();

	void StopServer();

	void StartServer();
	int GetMimicFileNameList();
	BOOL CheckGrbValid(CString Grbiid);
public:
	afx_msg void OnBnClickedOk69();
public:
	afx_msg void OnBnClickedOk70();
};
unsigned PlayThreadProcess(void* pParam);
ULONG GetULONGIP(CString IP);