// CVMimicDLLTestDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include <vector>
using namespace std;

// CCVMimicDLLTestDlg 对话框
class CCVMimicDLLTestDlg : public CDialog
{
// 构造
public:
	CCVMimicDLLTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CVMIMICDLLTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMimicgrpdef();
	afx_msg void OnBnClickedGetmimiclist();
	afx_msg void OnBnClickedGetGroupList();
	afx_msg void OnBnClickedGetUnGroupedMimicList();
	afx_msg void OnBnClickedGetGroupInfo();
	afx_msg void OnBnClickedSelectGroupDialog();
	afx_msg void OnBnClickedSetNewGroup();
	afx_msg void OnBnClickedSetNewMimicToGroup();
	afx_msg void OnBnClickedSelectMimicDialog();
	afx_msg void OnBnClickedGetTrendDefineInfo();
	CListBox m_trendpidlist;
	CListBox m_TagList;
	afx_msg void OnBnClickedButton10();
	afx_msg void OnLbnDblclkList2();
	afx_msg void OnBnClickedGetGroupListMem();
	afx_msg void OnBnClickedGetUnGroupedMimicListMem();
	afx_msg void OnBnClickedGetUnGroupedMimicListMemNoName();
	afx_msg void OnBnClickedGetMimicInfoListMem();
	afx_msg void OnBnClickedGetMimicListMem();
	afx_msg void OnBnClickedGetGroupInfoMem();
	afx_msg void OnBnClickedGetMimicGroupMem();
	CListBox m_GroupList;
	CListBox m_UnGroupList;
	CEdit m_InputText;
	CEdit m_MimicName;
	afx_msg void OnBnClickedButton19();
	afx_msg void GetParentNamebyGroupName();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton22();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButton24();
	afx_msg void OnBnClickedGetrf();
	afx_msg void OnBnClickedButton26();
	afx_msg void OnBnClickedButton27();
	BOOL OpenGrasDocument(LPCTSTR lpszPathName);
	void LoadFromStorage(LPSTORAGE& lpStorage);
	virtual void Serialize(CArchive& ar);
	afx_msg void OnBnClickedButton30();
	afx_msg void OnBnClickedButton28();
	afx_msg void OnBnClickedButton31();
	afx_msg void OnBnClickedButton29();
	afx_msg void OnBnClickedButton32();
	CString GetOsTempPath();
	afx_msg void OnBnClickedButton33();
	int GetCallListFileCnt(OUT vector<CString>& CallList);
	int GetPIDListFileCnt(OUT vector<CString>& PIDList);
public:
	afx_msg void OnBnClickedButton34();
};
