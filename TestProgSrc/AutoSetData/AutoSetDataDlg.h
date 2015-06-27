// AutoSetDataDlg.h : header file
//

#if !defined(AFX_AUTOSETDATADLG_H__5BF5723F_9B3D_460C_9AE5_D2534FBC1BA4__INCLUDED_)
#define AFX_AUTOSETDATADLG_H__5BF5723F_9B3D_460C_9AE5_D2534FBC1BA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAutoSetDataDlg dialog
#include "GridCtrl_src/GridCtrl.h"
#include "afxwin.h"
#include <vector>
#include <list>
#include "c:\coreview_src\include\cvcommondllcommon.h"
using namespace std;

typedef struct IIDAndValueType
{
    long liid;
	float fDefault;
	float fLow;
	float fHigh;
	float fSetp;
    float fValue;
    bool  bValid;
} IIDAndValueType;

const BYTE NUM_TYPE = 6;

typedef vector<IIDAndValueType> IIDAndValueListType;

class CAutoSetDataDlg : public CDialog
{
// Construction
public:
    void InitializeData();
    CAutoSetDataDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
    //{{AFX_DATA(CAutoSetDataDlg)
    enum { IDD = IDD_AUTOSETDATA_DIALOG };
    // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CAutoSetDataDlg)
protected:
    virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
    //}}AFX_VIRTUAL
    CGridCtrl m_Grid;
    CFont font;
    int iPeriod;
	vector<long> IIDList;
	list<InPkDigitalVal_T> DDataSetLst;
	list<InPkAnalogVal_T> ADataSetLst;
	list<InPkDigitalVal_T>::iterator DDataIt;
	list<InPkAnalogVal_T>::iterator ADataIt;
	CString CfgFile;
	CString IniFileName;
	long PIDCnt[6];//6÷÷PID¿‡–Õ
	int MaxRowNums;

// Implementation
protected:
    HICON m_hIcon;

    // Generated message map functions
    //{{AFX_MSG(CAutoSetDataDlg)
    virtual BOOL OnInitDialog();
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
public:
    void ReadDefaultFormFile(void);
    void SaveToFile(void);
    afx_msg void OnClose();
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    CEdit m_EditPerid;
    afx_msg void OnBnClickedButtonBegin();
    UINT m_nTimer;
    DWORD m_tLastTime;
	list<long> TagList[NUM_TYPE];
    void SetData(void);

	void RefreshVisibleRow();

	void GetSetValues();

	void DataSet( IIDAndValueListType &m_IIDList );

	void MyExDataSet();

	void GetIIDStructList( vector<long>& IIDList, OUT IIDAndValueListType &m_IIDList );
    afx_msg void OnBnClickedButtonPause();
    CButton m_Sin;
    afx_msg void OnBnClickedButtonBegin3();
    afx_msg void OnBnClickedCancel();
    LRESULT OnAutoPIDInfo(WPARAM wParam, LPARAM lParam);
    void GetPIDLimitVal(CString PID, FLOAT& Min, FLOAT& Max);
    int GetAnalogOrDigital(long IID);
    int GetPIDList(OUT vector<long>& IIDList);
    afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	void GetTagList(int DataType);
	void GridClear();
	CString GetInstallPath();
public:
	afx_msg void OnBnClickedButton3();

	int GetGridValidCnt();

	double GetSin( double x );
	float GetUserRangeValue( float Y, IIDAndValueType& Data );
public:
	afx_msg void OnBnClickedButton4();
public:
	afx_msg void OnBnClickedButton5();
public:
	afx_msg void OnBnClickedButton6();
	CString GetTypeString(int i);
public:
	afx_msg void OnBnClickedButtonAi();
	void AddPID(int Cnt, int Type);
public:
	afx_msg void OnBnClickedButtonDi();
public:
	afx_msg void OnBnClickedButtonAo();
public:
	afx_msg void OnBnClickedButtonDo();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOSETDATADLG_H__5BF5723F_9B3D_460C_9AE5_D2534FBC1BA4__INCLUDED_)
