// BugManage.cpp : 实现文件
//

#include "stdafx.h"
#include "ProjectDocAutomation.h"
#include "BugManage.h"
#include <io.h>
#include <comutil.h>
#include "excel.h"
#include <algorithm>

// CBugManage 对话框


IMPLEMENT_DYNAMIC(CBugManage, CDialog)

unsigned ExcelProcess(CBugManage *pParam)
{
	pParam->ExcelOper();

	return 0;
}

CBugManage::CBugManage(CWnd* pParent /*=NULL*/)
	: CDialog(CBugManage::IDD, pParent)
{

}

CBugManage::~CBugManage()
{
}

void CBugManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBugManage, CDialog)
	ON_WM_DROPFILES()
	ON_BN_CLICKED(IDOK, &CBugManage::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_TYPE, &CBugManage::OnCbnSelchangeType)
END_MESSAGE_MAP()


// CBugManage 消息处理程序

void CBugManage::OnDropFiles(HDROP hDropInfo)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int FileCnt = 0;
	vector<CString> FileList;

	FileCnt = GetDropFiles(FileList, hDropInfo);
	if (FileCnt > 0)
	{
		CString BugManageFile;
		BugManageFile = FileList[0];//只取第一个作为有效输入
		TRACE("CV8修改管理表：%s\n", BugManageFile);

		//判断是否是EXCEL文件
		if (BugManageFile.Right(4).CompareNoCase(".xls") == 0)
		{
			//是EXCEL文件，显示在界面上
			m_BugManageFile = BugManageFile;
			SetDlgItemText(IDC_FILE, m_BugManageFile);
		}
	}

	CDialog::OnDropFiles(hDropInfo);
}

int CBugManage::GetDropFiles(IN OUT vector<CString>& FileList, IN HDROP& hDropInfo)
{
	int FileCnt = 0;

	UINT iFile = 0;
	char szFile[1024] = {0};

	UINT iRet = DragQueryFile(hDropInfo, 0xFFFFFFFF, NULL, 0);

	if (iRet > 0)
	{
		for(UINT i = 0; i< iRet; i++)
		{
			int pathLen = DragQueryFile(hDropInfo, i, szFile, sizeof(szFile));
			FileList.push_back(szFile);
		}
	}

	DragFinish(hDropInfo);

	FileCnt = (int)FileList.size();

	return FileCnt;
}

void CBugManage::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//记录当前的管理表名称和路径
	SaveBugManageFile();

	//记录当前开发类型
	SaveLastDevType();

	//记录填表人
	CString s;
	GetDlgItemText(IDC_NAME_RCD, s);
	WritePrivateProfileString("ProjectDocAutomation", "Recorder", s, m_MetaFile);

	//问题发现人
	GetDlgItemText(IDC_NAME_FIND, s);
	WritePrivateProfileString("ProjectDocAutomation", "Finder", s, m_MetaFile);

	//记录当前开发类型
	SaveLastKind();

	//记录当前项目名
	SaveLastProjectName();

	//记录担当
	SaveLastCoder();


	//AfxBeginThread((AFX_THREADPROC)ExcelProcess, this, THREAD_PRIORITY_NORMAL);

	//OnOK();
}

int CBugManage::SelectSheet(short SheetIndex)
{
	VARIANT Index = _variant_t(SheetIndex, VT_I2);
	Excel.sheet = Excel.sheets.GetItem(Index);
	Excel.sheet.Activate();

	return 0;
}

void CBugManage::ReleaseDispatch(SExcel &Ole)
{
	Ole.range.ReleaseDispatch();
	Ole.sheet.ReleaseDispatch();
	Ole.sheets.ReleaseDispatch();
	Ole.book.ReleaseDispatch();
	Ole.books.ReleaseDispatch();
	Ole.app.ReleaseDispatch();
}

void CBugManage::SaveBugManageFile()
{
	//throw std::exception("The method or operation is not implemented.");
	//获取EXE所在路径
	char szPath[1024] = "";
	GetModuleFileName(NULL, szPath, sizeof(szPath));

	string Path;
	Path = GetPathInFileName(szPath);

	m_MetaFile = GetMetaFile();
	WritePrivateProfileString("ProjectDocAutomation", "BugManageFilePath", m_BugManageFile, m_MetaFile);
}

//从给定的全路径文件名中获取路径字符串
string CBugManage::GetPathInFileName( char * LogFileName )
{
	string PathName = LogFileName;
	string Name;
	int pos = (int)PathName.find_last_of('\\');
	if (pos > 0)
	{
		Name = PathName.substr(0, pos + 1);
	}

	return Name;
}

BOOL CBugManage::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_MetaFile = GetMetaFile();

	//获取管理表全路径名称
	char buf[1024] = "";
	GetPrivateProfileString("ProjectDocAutomation", "BugManageFilePath", NULL, buf, sizeof(buf), m_MetaFile);
	if (buf[0] != 0)
	{
		m_BugManageFile = buf;
		SetDlgItemText(IDC_FILE, m_BugManageFile);
	}

	ExcelOper();

	////显示所有的开发类型
	//buf[0] = 0;
	//GetPrivateProfileString("ProjectDocAutomation", "DevType", NULL, buf, sizeof(buf), m_MetaFile);
	//if (buf[0] != 0)
	//{
	//	vector<CString> Kind;
	//	GetTokenString(buf, Kind);
	//	int TypeCnt = (int)Kind.size();
	//	CString s;
	//	for (int i = 0; i < TypeCnt; i++)
	//	{
	//		s = Kind[i];
	//		((CComboBox*)GetDlgItem(IDC_TYPE))->AddString(s);
	//	}
	//}


	//AfxBeginThread((AFX_THREADPROC)ExcelProcess, this, THREAD_PRIORITY_NORMAL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString CBugManage::GetMetaFile()
{
	//获取EXE所在路径
	char szPath[1024] = "";
	GetModuleFileName(NULL, szPath, sizeof(szPath));

	string Path;
	Path = GetPathInFileName(szPath);

	CString FileName, Ret;
	FileName = META_FILE;
	Ret.Format("%s%s", Path.c_str(), FileName);

	return Ret;
}

int CBugManage::OpenExcelFile(SExcel &Ole, CString& FileName)
{
	_finddata32_t fileinfo;
	BOOL b = FALSE;

	ASSERT(!FileName.IsEmpty());
	if (FileName.IsEmpty() == TRUE)
	{
		return -2;
	}
	b = IsFileExist(FileName, fileinfo);
	if (b)
	{
		CoInitialize(NULL);

		COleVariant covOptional((long) DISP_E_PARAMNOTFOUND, VT_ERROR);

		if(!Ole.app.CreateDispatch("Excel.Application"))
		{
			AfxMessageBox("Couldn't CreateDispatch on Excel");
			return -3;
		}

		Ole.lpDisp = Ole.app.GetWorkbooks();
		Ole.books.AttachDispatch(Ole.lpDisp);
		Ole.lpDisp = Ole.books.Open(FileName,
			covOptional,
			covOptional,
			covOptional,
			covOptional,
			covOptional,
			covOptional,
			covOptional,
			covOptional,
			covOptional,
			covOptional,
			covOptional,
			covOptional,
			covOptional,
			covOptional);	/* Excel 2000 has 13 parameters */
		Ole.book.AttachDispatch(Ole.lpDisp);
		Ole.lpDisp = Ole.book.GetSheets();
		Ole.sheets.AttachDispatch(Ole.lpDisp);
	}

	return 0;
}

BOOL CBugManage::IsFileExist(CString ExistingFileName, _finddata32_t &fileinfo)
{
	intptr_t handle = 0;
	intptr_t ret = 0;
	BOOL Ret = FALSE;
	memset(&fileinfo, 0, sizeof(_finddata32_t));

	handle = _findfirst32(ExistingFileName, &fileinfo);
	if (handle == -1)
	{
		Ret = FALSE;
	}
	else
	{
		Ret = TRUE;
	}

	ret = _findclose(handle);

	return Ret;
}

void CBugManage::ExcelOper()
{
	OpenExcelFile(Excel, m_BugManageFile);
	Excel.app.SetVisible(TRUE);

	//打开指定Sheet
	SelectSheet(1);//定位问题表

	//计算已用的横纵坐标
	MyGetUsedRang(UsedRow, UsedCol);

	//遍历所有的类型
	vector<CString> Type;
	GetDevType(Type);
	int TypeCnt = (int)Type.size();
	CString s;
	for (int i = 0; i < TypeCnt; i++)
	{
		s = Type[i];
		((CComboBox*)GetDlgItem(IDC_TYPE))->AddString(s);
	}

	//设置最后一次的开发类型
	char buf[1024] = "";
	GetPrivateProfileString("ProjectDocAutomation", "LastDevType", NULL, buf, sizeof(buf), m_MetaFile);
	if (buf[0] != 0)
	{
		((CComboBox*)GetDlgItem(IDC_TYPE))->SelectString(0, buf);
	}

	//获取类型的最大子序号
	OnCbnSelchangeType();

	//获取当前时间
	SYSTEMTIME SystemTime;
	GetLocalTime(&SystemTime);

	//显示当前时间
	s.Format("%4d", SystemTime.wYear);
	SetDlgItemText(IDC_YYYY, s);
	s.Format("%2d", SystemTime.wMonth);
	SetDlgItemText(IDC_MM, s);
	s.Format("%2d", SystemTime.wDay);
	SetDlgItemText(IDC_DD, s);

	//显示上次的填写人
	GetPrivateProfileString("ProjectDocAutomation", "Recorder", "", buf, sizeof(buf), m_MetaFile);
	SetDlgItemText(IDC_NAME_RCD, buf);

	//显示上次的发现人
	buf[0] = 0;
	GetPrivateProfileString("ProjectDocAutomation", "Finder", "", buf, sizeof(buf), m_MetaFile);
	SetDlgItemText(IDC_NAME_FIND, buf);

	//获取使用版本号
	vector<CString> Ver;
	GetUsedVer(Ver);
	int VerCnt = (int)Ver.size();
	for (int i = 0; i < VerCnt; i++)
	{
		s = Ver[i];
		((CComboBox*)GetDlgItem(IDC_VER))->AddString(s);
	}
	if (VerCnt > 0)
	{
		((CComboBox*)GetDlgItem(IDC_VER))->SetCurSel(VerCnt - 1);
	}

	//遍历所有的类别
	vector<CString> Kind;
	GetDevKind(Kind);
	int KindCnt = (int)Kind.size();
	for (int i = 0; i < KindCnt; i++)
	{
		s = Kind[i];
		((CComboBox*)GetDlgItem(IDC_KIND))->AddString(s);
	}

	//显示上一次的类别
	buf[0] = 0;
	GetPrivateProfileString("ProjectDocAutomation", "LastKind", "", buf, sizeof(buf), m_MetaFile);
	SetDlgItemText(IDC_KIND, buf);

	//遍历所有的项目名
	vector<CString> Project;
	GetProjectName(Project);
	int ProjectCnt = (int)Project.size();
	for (int i = 0; i < ProjectCnt; i++)
	{
		s = Project[i];
		((CComboBox*)GetDlgItem(IDC_PROJ))->AddString(s);
	}



	//写入提交内容


	//ReleaseDispatch(Excel);
}

void CBugManage::Unique(vector<CString>& vList)
{
	vector<CString>::iterator Iter;

	sort(vList.begin(), vList.end());
	Iter = unique(vList.begin(), vList.end()); 
	vList.erase(Iter, vList.end()); 
}

CString CBugManage::GetColLetter(int ColNo)
{
	CString s;
	static char	ch1 = 64; 
	char ch2 = 0;
	int a = ColNo / 27;

	if(ColNo > 26)
	{	
		ch1 = char(64 + (ColNo - 1) / 26);	
		ch2 = char((ColNo - ((ColNo + 25) / 26 - 1) * 26) + 64);
		s.Format("%c%c", ch1, ch2);
	}
	else
	{
		ch2 = char(ColNo + 64);
		s.Format("%c", ch2);
	}

	return s;
}

void CBugManage::MyGetUsedRang(int& Row, int& Col)
{
	Row = 0;
	Col = 0;
	Excel.range = Excel.sheet.GetUsedRange();
	Range tmpRange = Excel.range.GetRows();
	Row = tmpRange.GetCount();
	tmpRange = Excel.range.GetColumns();
	Col = tmpRange.GetCount();
}

CString CBugManage::GetCellText( Cell_T Cell )
{
	CString Ret;
	CString sCell;
	CString Letter;
	Letter = GetColLetter(Cell.c);
	sCell.Format("%s%d", Letter, Cell.r);
	VARIANT Cell1 = COleVariant(sCell);
	VARIANT Cell2 = COleVariant(sCell);
	Range tmpRange = Excel.sheet.GetRange(Cell1, Cell2);
	VARIANT txt = tmpRange.GetValue2();

	Ret = txt;

	return Ret;
}

void CBugManage::GetDevType(vector<CString> &Type )
{
	Cell_T Cell;
	CString Text;
	for (int i = 1; i <= UsedRow; i++)
	{
		Cell.r = i;
		Cell.c = 2;
		Text = GetCellText(Cell);
		if (Text.IsEmpty() == FALSE)
		{
			Type.push_back(Text);
		}
	}
	Unique(Type);
}

//在指定的单元格写入文本
void CBugManage::SetCellText(Cell_T Cell, LPCSTR Text)
{
	CString Letter;
	CString sCell;

	if(Cell.r != 0 && Cell.c != 0)
	{
		//Letter = GetColLetter(Cell.c);
		//sCell.Format("%s%d", Letter, Cell.r);
		//pThisRange = pThisWorksheet->GetRange(COleVariant(sCell), COleVariant(sCell));
		//pThisRange->PutValue2(COleVariant(Text));
	}
}

void CBugManage::SaveDevType( vector<CString> &Type )
{
	CString TypeList;
	int TypeCnt = (int)Type.size();
	for (int i = 0; i < TypeCnt; i++)
	{
		TypeList += Type[i] + ",";
	}

	WritePrivateProfileString("ProjectDocAutomation", "DevType", TypeList, m_MetaFile);
}

void CBugManage::GetTokenString( CString Full, OUT vector<CString>& RetQue )
{
	RetQue.clear();
	int curPos = 0;
	CString SubStr;
	do 
	{
		SubStr = Full.Tokenize(",", curPos);
		if (SubStr != "")
		{
			RetQue.push_back(SubStr);
		}	
	} while (SubStr != "");

	return;
}

void CBugManage::SaveLastDevType()
{
	CString s;
	GetDlgItemText(IDC_TYPE, s);
	WritePrivateProfileString("ProjectDocAutomation", "LastDevType", s, m_MetaFile);
}

//类型变化
void CBugManage::OnCbnSelchangeType()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveLastDevType();

	//获取当前选择的类型
	CString szType;
	GetDlgItemText(IDC_TYPE, szType);

	Cell_T Cell;
	CString Text, SubNoStr;
	vector<CString> SubNo;
	for (int i = 1; i <= UsedRow; i++)
	{
		Cell.r = i;
		Cell.c = 2;
		Text = GetCellText(Cell);
		if (Text == szType)
		{
			Cell.r = i;
			Cell.c = 3;
			SubNoStr = GetCellText(Cell);
			SubNo.push_back(SubNoStr);
		}
	}
	Unique(SubNo);

	//显示最大子序号
	int Max = (int)SubNo.size();
	int SubNoVal = atoi(SubNo[Max - 1]);
	SubNoVal++;
	SubNoStr.Format("%d", SubNoVal); 
	SetDlgItemText(IDC_SUB_NO, SubNoStr);
}

void CBugManage::GetUsedVer(vector<CString>& Ver)
{
	//throw std::exception("The method or operation is not implemented.");
	Cell_T Cell;
	CString Text;
	Ver.clear();
	for (int i = UsedRow; i >= 0; i--)
	{
		Cell.r = i;
		Cell.c = 10;
		Text = GetCellText(Cell);
		if (Text.IsEmpty() == FALSE)
		{
			Ver.push_back(Text);
		}

		if (Ver.size() >= 10)
		{
			break;
		}
	}
	Unique(Ver);
}

void CBugManage::GetDevKind(vector<CString> &Kind )
{
	Cell_T Cell;
	CString Text;
	for (int i = 1; i <= UsedRow; i++)
	{
		Cell.r = i;
		Cell.c = 12;
		Text = GetCellText(Cell);
		if (Text.IsEmpty() == FALSE)
		{
			Kind.push_back(Text);
		}
	}
	Unique(Kind);
}

void CBugManage::SaveLastKind()
{
	CString s;
	GetDlgItemText(IDC_KIND, s);
	WritePrivateProfileString("ProjectDocAutomation", "LastKind", s, m_MetaFile);
}

void CBugManage::GetProjectName(vector<CString> &ProjectName )
{
	Cell_T Cell;
	CString Text;
	for (int i = 1; i <= UsedRow; i++)
	{
		Cell.r = i;
		Cell.c = 13;
		Text = GetCellText(Cell);
		if (Text.IsEmpty() == FALSE)
		{
			Text.Trim();
			ProjectName.push_back(Text);
		}
	}
	Unique(ProjectName);
}

void CBugManage::SaveLastProjectName()
{
	CString s;
	GetDlgItemText(IDC_PROJ, s);
	WritePrivateProfileString("ProjectDocAutomation", "LastProjectName", s, m_MetaFile);
}

void CBugManage::SaveLastCoder()
{
	CString s;
	GetDlgItemText(IDC_NAME_CODER, s);
	WritePrivateProfileString("ProjectDocAutomation", "Coder", s, m_MetaFile);
}
