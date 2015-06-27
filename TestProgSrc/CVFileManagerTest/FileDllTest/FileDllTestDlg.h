// FileDllTestDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "Test.h"
#include <list>
#include <algorithm>
using namespace std;
#include "afxdao.h"
#pragma warning(disable:4995)
#include <vector>
using namespace std;

//typedef struct T_DiskInfo
//{
//	ULONGLONG TotalBytes;
//	ULONGLONG FreeBytes;
//}T_DiskInfo;
// CFileDllTestDlg 对话框
class CFileDllTestDlg : public CDialog
{
// 构造
public:
	CFileDllTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_FILEDLLTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;
	HMODULE  hModule1;
public:
	CDaoDatabase m_DB;
	BOOL bOnKey;
	CListCtrl m_List;
	CTest m_Test;
	BOOL StopFlag;
	list<long> input_list;

	// 生成的消息映射函数
	void CFileDllTestDlg::CreateDB();
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk5();
	//afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk6();
	afx_msg void OnBnClickedOk8();
	afx_msg void OnBnClickedOk9();
	afx_msg void OnBnClickedOk10();
	afx_msg void OnBnClickedOk11();
	afx_msg void OnBnClickedOk7();
	afx_msg void OnBnClickedOk12();
	afx_msg void OnBnClickedOk16();
	afx_msg void OnBnClickedOk17();
	afx_msg void OnBnClickedOk21();
	afx_msg void OnBnClickedOk18();
	afx_msg void OnBnClickedOk14();
	afx_msg void OnBnClickedOk13();
	afx_msg void OnBnClickedOk19();
	afx_msg void OnBnClickedOk20();
	afx_msg void OnBnClickedOk25();
	afx_msg void OnBnClickedOk26();
	afx_msg void OnBnClickedOk27();
	afx_msg void OnBnClickedOk28();
	afx_msg void OnBnClickedOk29();
	afx_msg void OnBnClickedOk30();
	afx_msg void OnBnClickedOk31();
	afx_msg void OnBnClickedOk32();
	afx_msg void OnBnClickedOk33();
	afx_msg void OnClose();
#ifdef _DEBUG
	CMemoryState oldMemState, newMemState, diffMemState;
#endif

public:
	//afx_msg void OnBnClickedCancel2();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk22();
	afx_msg void OnBnClickedOk34();
	afx_msg void OnBnClickedOk35();
	afx_msg void OnBnClickedOk36();
	afx_msg void OnBnClickedOk23();
	afx_msg void OnBnClickedOk24();
	afx_msg void OnBnClickedOk37();
	afx_msg void OnBnClickedOk38();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedOk15();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	BOOL GetReg(HKEY hMainKey, char *SubKey, char *KeyName, BYTE Type, char *KeyVal);
	BOOL SetReg(HKEY hMainKey, char *SubKey, char *KeyName, BYTE Type, char *KeyVal);
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton19();
	CString CreateNtrightsFile();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton22();
	//afx_msg void OnBnClickedButton23();
	//afx_msg void OnBnClickedButton24();
	//afx_msg void OnBnClickedButton25();
	//afx_msg void OnBnClickedButton26();
	//afx_msg void OnBnClickedButton27();
	//afx_msg void OnBnClickedButton28();
	//afx_msg void OnBnClickedButton29();
	//afx_msg void OnBnClickedButton30();
	//afx_msg void OnBnClickedButton32();
	//afx_msg void OnBnClickedButton33();
	//afx_msg void OnBnClickedButton34();
	//afx_msg void OnBnClickedButton31();
	//afx_msg void OnBnClickedButton35();
	//afx_msg void OnBnClickedButton36();
	//afx_msg void OnBnClickedButton37();
	afx_msg void OnBnClickedButton38();
	//afx_msg void OnBnClickedButton39();
	//afx_msg void OnBnClickedButton40();
	//afx_msg void OnBnClickedButton41();
	//afx_msg void OnBnClickedButton42();
	//afx_msg void OnBnClickedButton45();
	//afx_msg void OnBnClickedButton46();
	//afx_msg void OnBnClickedButton47();
	//afx_msg void OnBnClickedButton48();
	//afx_msg void OnBnClickedButton49();
	//afx_msg void OnBnClickedButton50();
	//afx_msg void OnBnClickedButton51();
	//afx_msg void OnBnClickedButton52();
	//afx_msg void OnBnClickedButton53();
	//afx_msg void OnBnClickedButton54();
	afx_msg void OnBnClickedButton56();
	void SetXPVisual();
	afx_msg void OnBnClickedButton55();
	afx_msg void OnBnClickedButton57();
	//afx_msg void OnBnClickedButton43();
	//afx_msg void OnBnClickedButton58();
	//afx_msg void OnBnClickedButton59();
	afx_msg void OnBnClickedButton44();
	afx_msg void OnBnClickedButton60();
    afx_msg void OnBnClickedButton61();
    afx_msg void OnBnClickedButton62();
	afx_msg void OnBnClickedButton63();
	afx_msg void OnBnClickedButton64();
	afx_msg void OnBnClickedButton65();
	afx_msg void OnBnClickedButton66();
	afx_msg void OnBnClickedButton67();
	void FileDiff( vector<CString> &OfflineFileList, CString Remote );
	void GetOfflineFileList( vector<CString> &OfflineFileList );
	BOOL GetFileAttribute( int& FileSize, __time32_t& ModifyTime, IN CString& PathName );
	bool IsOneFile( CString& LocalFile );
	int GetFileList(IN CString Path, OUT vector<CString> &FileList);
	void GetWildcardPathFile( OUT CString &PathFile, CString GrName );
	afx_msg void OnBnClickedButton68();
public:
	afx_msg void OnBnClickedButton69();
public:
	afx_msg void OnBnClickedButton70();
public:
	afx_msg void OnBnClickedButton71();
};

BOOL DBEncrypt1(CDaoDatabase& m_DB, LPCSTR DBFileName);
BOOL DeleteDBPassword1(CDaoDatabase& m_DB, LPCSTR DBFileName);
CString GetCmdOutput(CString CmdLine);
void TurnOnService(CString ServiceName);
HWND MyFindWindow(CString Title, int Wait = 2000);
void WindowTop(HWND h);
void ShortKey(int Key1, int Key2);
void MySleep(int time);
void BnClick(HWND h, CString Find);
HWND FindCtrlByText(HWND h, CString Text);