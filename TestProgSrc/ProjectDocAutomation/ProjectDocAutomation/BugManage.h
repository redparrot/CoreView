#pragma once
#include <vector>
using namespace std;
#include "excel.h"
#include <io.h>


// CBugManage 对话框
const CString META_FILE = "ProjectDocAutomation.ini";
typedef struct SExcel
{
	_Application	app;
	LPDISPATCH		lpDisp;
	_Workbook		book;
	_Worksheet		sheet;
	Workbooks		books;
	Worksheets		sheets;
	Range			range;
} SExcel;

typedef struct Cell_T
{
	int r;
	int c;
}Cell_T;

class CBugManage : public CDialog
{
	DECLARE_DYNAMIC(CBugManage)

public:
	CBugManage(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBugManage();

// 对话框数据
	enum { IDD = IDD_BUG_MANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDropFiles(HDROP hDropInfo);
	int GetDropFiles(IN OUT vector<CString>& FileList, IN HDROP& hDropInfo);
public:
	afx_msg void OnBnClickedOk();

	void ExcelOper();

	void SaveDevType( vector<CString> &Type );

	void GetDevType(vector<CString> &Type);

	CString GetCellText( Cell_T Cell );

	void MyGetUsedRang(int& Row, int& Col);

	void SaveBugManageFile();

	CString GetMetaFile();

	string GetPathInFileName( char * LogFileName );

private:
	CString m_BugManageFile;//修改管理表全路径名称
	CString m_MetaFile;//元数据全路径名称
	virtual BOOL OnInitDialog();
	int OpenExcelFile(SExcel &Ole, CString& FileName);
	BOOL IsFileExist(CString ExistingFileName, _finddata32_t &fileinfo);
	void ReleaseDispatch(SExcel &Ole);
	int SelectSheet(short SheetIndex);
	CString GetColLetter(int ColNo);
	void Unique(vector<CString>& vList);
	void SetCellText(Cell_T Cell, LPCSTR Text);
	void GetTokenString( CString Full, OUT vector<CString>& RetQue );
	void SaveLastDevType();
public:
	SExcel Excel;
	int UsedRow;//已用的行数
	int UsedCol;//已用的列数

	//RangePtr ExcelUsedRange;
	//_ApplicationPtr pApplication;
	//_WorkbookPtr pThisWorkbook;
	//_WorksheetPtr pThisWorksheet;
	//SheetsPtr pThisSheets;
	//RangePtr pThisRange;
	//CommandBarPtr pCommandBar;
	//PageSetupPtr pPageSetup;
	//Excel::FontPtr pThisFont;
	//Excel::XlFileFormat vFileFormat ;
	//Excel::XlSaveAsAccessMode vSaveAsAccessMode ;
	//Excel::XlSaveConflictResolution vSaveConflictResolution ;
	//Excel::XlSearchOrder vByRows;
	//Excel::XlSearchDirection vDirection;
	//Excel::XlCalculation vCalculation;
	//Excel::XlEnableSelection vEnableSelection;
	//RangePtr			ExcelUsedRange;
public:
	afx_msg void OnCbnSelchangeType();
	void GetUsedVer(vector<CString>& Ver);
	void GetDevKind(vector<CString> &Kind );
	void SaveLastKind();
	void GetProjectName(vector<CString> &ProjectName );
	void SaveLastProjectName();
	void SaveLastCoder();
};
