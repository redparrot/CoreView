// CVPrecordDspTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CVPrecordDspTest.h"
#include "CVPrecordDspTestDlg.h"
#include "C:\CoreView_Src\Include\CVCommonDllCommon.h"
#include "C:\CoreView_Src\Include\CVDeviceCommdll.h"
#include "C:\CoreView_Src\Include\CVPrdCommon.h"
#include "afxmt.h"
#include "TimeOper.h"
#include "shlobj.h"
#pragma comment(lib, "shell32.lib")
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

const CString IniFileName = "C:\\coreview\\funcexec\\cvprecordexec\\Configure\\CVPrdConf.cyt";
const CString PrdColMem = "PrdColMem";
const CString MAP_NAME = "C:\\CoreView\\Configure data\\Convert data\\IniBuilder\\PrdColMemInitinalData.mem";
CMutex gMutex(FALSE, "PrdColMemWtRdMutex", NULL);
typedef struct ShareMemHead_T
{
	long	lMemChgCnt;		//内存变化计数器
	long	lMemMsgCnt;		//内存中的记录数
	long	lDelPathTmName;	//待删除的路径
	int		nFileBufCount;	//文件列表的长度
	int		nFileBufWtPt;	//写指针的位置
}ShareMemHead_T;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
const int SimCount = 10;
const int SimMemCount = 2;
void CCVPrecordDspTestDlg::SetSimFile(CString File, DWORD Time)//仿真文件
{
	CFile f;
	time_t lTime = 0;
	Precord_T Precord_t;
	char buf[19 * SimCount] = {0};
	char *p = buf;
	LONG IID = 0;
	char FileName[200] = {0};
	CTimeOper m_Time;
	CString DirPath;

	GetIID("C0001", IID);

	if(f.Open(File, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate, NULL) == TRUE)
	{
		for (int i = 0; i < SimCount; i++)
		{
			Precord_t.Type[0] = 1;
			Precord_t.Type[1] = 1;
			Precord_t.RecdTime = Time;
			Precord_t.RecdIID = IID;
			Precord_t.Value1 = 100;
			Precord_t.Value2 = 200;
			Precord_t.Flag = 0;
			memcpy(p, &Precord_t, sizeof(Precord_T));
			p += sizeof(Precord_T);
		}

		//for (int i = 0; i < 1000; i++)
		//{
		//	Precord_t.Type[0] = 1;
		//	Precord_t.Type[1] = 11;
		//	memcpy(p, &Precord_t, sizeof(Precord_T));
		//	p += sizeof(Precord_T);
		//}

		//for (int i = 0; i < 1000; i++)
		//{
		//	Precord_t.Type[0] = 2;
		//	Precord_t.Type[1] = 1;
		//	memcpy(p, &Precord_t, sizeof(Precord_T));
		//	p += sizeof(Precord_T);
		//}

		//for (int i = 0; i < 1000; i++)
		//{
		//	Precord_t.Type[0] = 3;
		//	Precord_t.Type[1] = 1;
		//	memcpy(p, &Precord_t, sizeof(Precord_T));
		//	p += sizeof(Precord_T);
		//}
		
		f.SeekToEnd();
		f.Write(buf, 19 * SimCount);

		f.Close();
	}
}

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CCVPrecordDspTestDlg 对话框

CCVPrecordDspTestDlg::CCVPrecordDspTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCVPrecordDspTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hMap = NULL;
	m_DelDate = 0;
	m_ChgFileTime = 0;
}

void CCVPrecordDspTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCVPrecordDspTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CCVPrecordDspTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDCANCEL, &CCVPrecordDspTestDlg::OnBnClickedCancel)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, &CCVPrecordDspTestDlg::OnBnClickedButton2)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON3, &CCVPrecordDspTestDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCVPrecordDspTestDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCVPrecordDspTestDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCVPrecordDspTestDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCVPrecordDspTestDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCVPrecordDspTestDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCVPrecordDspTestDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CCVPrecordDspTestDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CCVPrecordDspTestDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CCVPrecordDspTestDlg::OnBnClickedButton12)
END_MESSAGE_MAP()

// CCVPrecordDspTestDlg 消息处理程序

BOOL CCVPrecordDspTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_SHOW);

	// TODO: 在此添加额外的初始化代码
	ChgFileMax = GetPrivateProfileInt("PrdDataFile_Field", "DelayMsg_InsFileCnt", NULL, IniFileName);

	//OnBnClickedButton1();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCVPrecordDspTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCVPrecordDspTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR CCVPrecordDspTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCVPrecordDspTestDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	int Size = 0;

	CFile f;
	ULONGLONG FileSize = 0;
	if(f.Open(MAP_NAME, CFile::modeRead, NULL) == TRUE)
	{
		FileSize = f.GetLength();
	}

	m_hMap = OpenFileMapping(FILE_MAP_ALL_ACCESS, TRUE, PrdColMem);               

	if (m_hMap != NULL)
	{
		m_pMap = (char*)MapViewOfFile(m_hMap, FILE_MAP_WRITE | FILE_MAP_READ, 0, 0, 0);
		if (m_pMap == NULL)
		{
			CloseHandle(m_hMap);
			m_hMap = NULL;
		}
		else
		{
			memset(m_pMap, 0, (size_t)FileSize);
		}
	}
}

void CCVPrecordDspTestDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	KillTimer(1);

	UnmapViewOfFile(m_pMap);

	if (m_hMap != NULL)
	{
		CloseHandle(m_hMap);
	}

	OnCancel();
}

void CCVPrecordDspTestDlg::OnTimer(UINT_PTR nIDEvent)
{
	char * p = NULL;
	CString szTime;
	time_t Time = 0;
	static int Count = 0;
	CFile f;
	static CString File;
	static time_t lTime = 0;
	Precord_T Precord_t;
	char buf[100] = {0};
	LONG IID = 0;
	CTimeOper m_Time;
	CString DirPath;
	CString Dir, Path, FileName;
	static CString OldDir;

	{//本机是POC站时每周期添加一条记录到最后一个文件中
		//time(&Time);
		//Dir = m_Time.GetYMD(Time, 1);
		//if (Dir != OldDir)
		//{
		//	OldDir = Dir;
		//	Path.Format("C:\\coreview\\funcexec\\cvprecordexec\\Data\\%s\\", Dir);
		//	SHCreateDirectoryEx(m_hWnd, Path, NULL);
		//	File.Format("%sPrd%d.dat", Path, Time); 
		//	FileName.Format("Prd%d.dat", Time);
		//	szTime = FileName.Mid(3, FileName.GetLength() - 7);
		//	lTime = atoi(szTime);
		//}
		//GetIID("C0001", IID);

		//if(f.Open(File, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate, NULL) == TRUE)
		//{
		//	Precord_t.Type[0] = 1;
		//	Precord_t.Type[1] = 1;
		//	Precord_t.RecdTime = Time;
		//	Precord_t.RecdIID = IID;
		//	Precord_t.Value1 = 100;
		//	Precord_t.Value2 = 200;
		//	Precord_t.Flag = 0;
		//	memcpy(buf, &Precord_t, sizeof(Precord_T));

		//	f.SeekToEnd();
		//	f.Write(&Precord_t, sizeof(Precord_T));
		//	f.Close();
		//}

		////修改共享内存中的文件列表
		//p = m_pMap + sizeof(ShareMemHead_T);
		//*(time_t*)p = lTime;
	}


	{//本机是历史站时每周期添加一条记录到最后一个文件中
		//每周期添加一条记录到最后一个文件中
		time(&Time);
		Dir = m_Time.GetYMD(Time, 1);
		if (Dir != OldDir)
		{
			OldDir = Dir;
			Path.Format("D:\\CoreView\\Precord\\%s\\", Dir);
			SHCreateDirectoryEx(m_hWnd, Path, NULL);
			File.Format("%sPrd%d.dat", Path, Time); 
			FileName.Format("Prd%d.dat", Time);
			szTime = FileName.Mid(3, FileName.GetLength() - 7);
			lTime = atoi(szTime);
		}
		GetIID("C0001", IID);

		if(f.Open(File, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate, NULL) == TRUE)
		{
			Precord_t.Type[0] = 1;
			Precord_t.Type[1] = 1;
			Precord_t.RecdTime = Time;
			Precord_t.RecdIID = IID;
			Precord_t.Value1 = 100;
			Precord_t.Value2 = 200;
			Precord_t.Flag = 0;
			memcpy(buf, &Precord_t, sizeof(Precord_T));

			f.SeekToEnd();
			f.Write(&Precord_t, sizeof(Precord_T));
			f.Close();
		}

		//修改共享内存中的文件列表
		p = m_pMap + sizeof(ShareMemHead_T);
		*(time_t*)p = lTime;
	}

	CDialog::OnTimer(nIDEvent);
}

//BOOL CCVPrecordDspTestDlg::PreCreateWindow(CREATESTRUCT& cs)
//{
//	// TODO: 在此添加专用代码和/或调用基类
//	int xsize = ::GetSystemMetrics(SM_CXSCREEN);
//	int ysize = ::GetSystemMetrics(SM_CYSCREEN);
//	cs.cx = xsize;
//	cs.cy = ysize * 92 / 100;
//	cs.x = (xsize - cs.cx) / 2;
//	cs.y = (ysize - cs.cy) / 2; 
//
//	return CDialog::PreCreateWindow(cs);
//}

void CCVPrecordDspTestDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}

BOOL CCVPrecordDspTestDlg::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此添加专用代码和/或调用基类

	return CDialog::PreCreateWindow(cs);
}

int CCVPrecordDspTestDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	int xsize = ::GetSystemMetrics(SM_CXSCREEN);
	int ysize = ::GetSystemMetrics(SM_CYSCREEN);
	lpCreateStruct->x = (xsize - lpCreateStruct->cx) / 2;
	lpCreateStruct->y = (ysize - lpCreateStruct->cy) / 2; 

	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	return 0;
}

void CCVPrecordDspTestDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	char * p = NULL;
	CString File;
	static int Time = 1190765141;

	File.Format("C:\\coreview\\funcexec\\cvprecordexec\\Data\\070926\\Prd%d.dat", Time); 
	SetSimFile(File, Time);
	ShareMemHead_T ShareMemHead_t;
	ShareMemHead_t.nFileBufCount = 1;
	p = m_pMap + sizeof(ShareMemHead_T);
	*(DWORD*)p = Time;
	Time++;
}

void CCVPrecordDspTestDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	char PID[8] = {"A0003"};
	struct tm LocalTime;
	CTimeOper m_Time;
	int Month = 10;
	int Date = 1;

	LocalTime.tm_year = 2006 - 1900;
	LocalTime.tm_mon = Month - 1;
	LocalTime.tm_mday = Date;
	LocalTime.tm_hour = 0;
	LocalTime.tm_min = 0;
	LocalTime.tm_sec = 0;
	m_DelDate = m_Time.GetTime_T(LocalTime);

	*(time_t*)(m_pMap + 2 * sizeof(LONG)) = m_DelDate;
}

CString CCVPrecordDspTestDlg::GetDataFileList()
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	int Count = 0;
	int FileCount = 0;
	CString FileName;
	CString Dir;
	CString Name;
	time_t Time = 0;
	CHAR szTime[30] = {0};
	CString s;
	CString strTime;
	int FileNameLen = 0;
	int ItemCount = 0;
	int ItemTotal = 0;
	//FileInfo_T FileInfo_t;
	CStringArray FileList;

	//获取所有符合条件的日期文件夹
	FileName = "C:\\CoreView\\Record data\\Precord\\*.*";
	hFind = FindFirstFile(FileName, &FindFileData);
	if(hFind != INVALID_HANDLE_VALUE) 
	{
		while(FindNextFile(hFind, &FindFileData))
		{
			if ((FILE_ATTRIBUTE_DIRECTORY & FindFileData.dwFileAttributes))
			{
				if (FindFileData.cFileName[0] == '.')
				{
					continue;
				}
				else
				{
					if (strlen(FindFileData.cFileName) == 6)
					{
						DirList.Add(FindFileData.cFileName);
						Count++;
					}
				}
			}
		}
	} 

	FindClose(hFind);

	//获取文件夹中的文件名称列表
	Dir = DirList.GetAt(Count - 1);
	FileName.Format("C:\\CoreView\\Record data\\Precord\\%s\\*.dat", Dir);
	hFind = FindFirstFile(FileName, &FindFileData);
	if(hFind != INVALID_HANDLE_VALUE) 
	{
		//FileNameLen = (int)strlen(FindFileData.cFileName);
		FileList.Add(FindFileData.cFileName);
		//strncpy_s(szTime,  sizeof(szTime), FindFileData.cFileName + 3, FileNameLen - 7); 
		//Time = atoi(szTime);
		//ItemCount = GetRecordCount(Time);
		//if (ItemCount)
		//{
		//	FileInfo_t.RecdTime.Add((DWORD)Time);
		//	FileInfo_t.RecdCount.Add(ItemCount);
		//	ItemTotal += ItemCount;
		//	FileCount++;
		//}
		while(FindNextFile(hFind, &FindFileData))
		{
			FileList.Add(FindFileData.cFileName);
			//FileNameLen = (int)strlen(FindFileData.cFileName);
			//strncpy_s(szTime,  sizeof(szTime), FindFileData.cFileName + 3, FileNameLen - 7); 
			//Time = atoi(szTime);
			//ItemCount = GetRecordCount(Time);
			//if (ItemCount)
			//{
			//	FileInfo_t.RecdTime.Add((DWORD)Time);
			//	FileInfo_t.RecdCount.Add(ItemCount);
			//	ItemTotal += ItemCount;
			//	FileCount++;
			//}
		}
	} 

	FindClose(hFind);

	//sort(FileList.begin(), FileList.end());

	Count = (int)FileList.GetCount();
	CString EndFileName = FileList.GetAt(Count - 1);

	return EndFileName;
}

//修改最后一个文件的记录数
void CCVPrecordDspTestDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	OnTimer(1);
}

//新增内存记录
void CCVPrecordDspTestDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	BOOL b = FALSE;
	int OldMsgCount = 0;
	int MsgCount = 0;
	Precord_T Precord_t;
	CTimeOper m_Time;
	LONG IID = 0;
	time_t lTime = m_Time.GetCurTime();
	char PID[8] = {"L0001"};
	GetIID(PID, IID);

	b = gMutex.Lock(5000);

	int ChgCount = *((LONG*)m_pMap);
	ChgCount++;
	*((LONG*)m_pMap) = ChgCount;

	OldMsgCount = *((LONG*)m_pMap + 1);
	MsgCount = OldMsgCount + 3;
	*((LONG*)m_pMap + 1) = MsgCount;

	Precord_T* p = (Precord_T*)(m_pMap + 5 * 4 + ChgFileMax * 4);
	p += OldMsgCount;

	for (int i = 0; i < 3; i++)
	{
		Precord_t.Type[0] = 1;
		Precord_t.Type[1] = 1;
		Precord_t.RecdTime = lTime;
		Precord_t.RecdIID = IID;
		Precord_t.Value1 = 100;
		Precord_t.Value2 = 200;
		Precord_t.Flag = 0;

		memcpy(p, &Precord_t, sizeof(Precord_T));
		p++;
	}

	gMutex.Unlock();
}

//清空内存记录
void CCVPrecordDspTestDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	BOOL b = FALSE;
	int OldMsgCount = 0;
	int MsgCount = 0;
	char PID[8] = {"A0001"};
	CTimeOper m_Time;
	LONG IID = 0;
	time_t lTime = m_Time.GetCurTime();
	GetIID(PID, IID);

	b = gMutex.Lock(5000);

	int ChgCount = *((LONG*)m_pMap);
	ChgCount++;
	*((LONG*)m_pMap) = ChgCount;

	OldMsgCount = *((LONG*)m_pMap + 1);
	*((LONG*)m_pMap + 1) = 0;

	Precord_T* p = (Precord_T*)(m_pMap + 5 * 4 + ChgFileMax * 4);
	memset(p, 0, sizeof(Precord_T) * OldMsgCount);

	gMutex.Unlock();
}

//产生混合记录文件
void CCVPrecordDspTestDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	//char PID[8] = {"A0005"};
	BYTE Type[2] = {1, 1};


}

//产生混合内存记录
void CCVPrecordDspTestDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	BOOL b = FALSE;
	int OldMsgCount = 0;
	int MsgCount = 0;
	Precord_T Precord_t;
	CTimeOper m_Time;
	LONG IID = 0;
	LONG IID_D = 0;
	time_t lTime = m_Time.GetCurTime();
	char PID[8] = {"C0021"};
	char PID_D[8] = {"B0001"};
	GetIID(PID, IID);
	GetIID(PID_D, IID_D);

	b = gMutex.Lock(5000);

	int ChgCount = *((LONG*)m_pMap);
	ChgCount++;
	*((LONG*)m_pMap) = ChgCount;

	//OldMsgCount = *((LONG*)m_pMap + 1);
	//MsgCount = OldMsgCount + 3;

	Precord_T* p = (Precord_T*)(m_pMap + 5 * 4 + ChgFileMax * 4);
	p += OldMsgCount;

	//报警
	for (int i = 0; i < 1; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			Precord_t.Type[0] = 1;
			Precord_t.Type[1] = j;
			Precord_t.RecdTime = lTime;
			Precord_t.RecdIID = IID;
			Precord_t.Value1 = 100;
			Precord_t.Value2 = 200;
			Precord_t.Flag = 0;

			memcpy(p, &Precord_t, sizeof(Precord_T));
			p++;
			MsgCount++;
		}
	}

	//报警(数字量)
	for (int i = 0; i < 1; i++)
	{
		for (int j = 8; j <= 9; j++)
		{
			Precord_t.Type[0] = 1;
			Precord_t.Type[1] = j;
			Precord_t.RecdTime = lTime;
			Precord_t.RecdIID = IID_D;
			Precord_t.Value1 = 0;
			Precord_t.Value2 = 1;
			Precord_t.Flag = 0;

			memcpy(p, &Precord_t, sizeof(Precord_T));
			p++;
			MsgCount++;
		}
	}

	//数字量双向报警恢复
	Precord_t.Type[0] = 1;
	Precord_t.Type[1] = 13;
	Precord_t.RecdTime = lTime;
	Precord_t.RecdIID = IID_D;
	Precord_t.Value1 = 0;
	Precord_t.Value2 = 1;
	Precord_t.Flag = 0;

	memcpy(p, &Precord_t, sizeof(Precord_T));
	p++;
	MsgCount++;

	//人工置数
	for (int i = 0; i < 1; i++)
	{
		for (int j = 1; j <= 12; j++)
		{
			Precord_t.Type[0] = 2;
			Precord_t.Type[1] = j;
			Precord_t.RecdTime = lTime;
			Precord_t.RecdIID = IID + 2;
			Precord_t.Value1 = 100;
			Precord_t.Value2 = 200;
			Precord_t.Flag = 1;

			memcpy(p, &Precord_t, sizeof(Precord_T));
			p++;
			MsgCount++;
		}
	}

	//状态变位
	for (int i = 0; i < 1; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			Precord_t.Type[0] = 3;
			Precord_t.Type[1] = j;
			Precord_t.RecdTime = lTime;
			Precord_t.RecdIID = IID + 3;
			Precord_t.Value1 = 100;
			Precord_t.Value2 = 200;
			Precord_t.Flag = 1;

			memcpy(p, &Precord_t, sizeof(Precord_T));
			p++;
			MsgCount++;
		}
	}

	*((LONG*)m_pMap + 1) = MsgCount;

	gMutex.Unlock();
}

void SetSimFile(int Date)	/* 仿真文件 */
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	CFile		f;
	struct tm	LocalTime;
	time_t		lTime = 0;
	Precord_T	Precord_t;
	char		buf[19 * SimCount] = { 0 };
	char		*p = buf;
	LONG		IID = 0;
	char		PID[8] = { 0 };
	char		FileName[200] = { 0 };
	CTimeOper	m_Time;
	BYTE Type[2] = {1, 11};
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	strcpy_s(PID, "C0002");
	GetIID(PID, IID);

	for(int min = 0; min < 2; min++)
	{
		LocalTime.tm_year = 2007 - 1900;
		LocalTime.tm_mon = 6;
		LocalTime.tm_mday = Date;
		LocalTime.tm_hour = 12;
		LocalTime.tm_min = min;
		LocalTime.tm_sec = 0;

		for(int FileNum = 0; FileNum < 60; FileNum++)
		{
			LocalTime.tm_sec = FileNum;
			lTime = m_Time.GetTime_T(LocalTime);
			p = buf;

			sprintf_s(FileName,
				sizeof(FileName),
				"C:\\CoreView\\Record data\\Precord\\0707%02d\\Prd%d.dat",
				Date,
				lTime);
			if(f.Open(FileName, CFile::modeCreate | CFile::modeWrite, NULL) == TRUE)
			{
				for(int i = 0; i < SimCount; i++)
				{
					Precord_t.Type[0] = 1;
					Precord_t.Type[1] = 11;
					Precord_t.RecdTime = lTime;
					Precord_t.RecdIID = IID;
					Precord_t.Value1 = 100;
					Precord_t.Value2 = 200;
					Precord_t.Flag = 0;

					memcpy(p, &Precord_t, sizeof(Precord_T));
					p += sizeof(Precord_T);
				}

				f.Write(buf, 19 * SimCount);

				f.Close();
			}
		}
	}
}

void CCVPrecordDspTestDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	for(int i = 22; i <= 28; i++)
	{
		//SetSimFile(i);
	}
}

//周期任务
void CCVPrecordDspTestDlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	CString File;

	//File.Format("C:\\coreview\\funcexec\\cvprecordexec\\Data\\070926\\Prd%d.dat", FileName); 
	//DeleteFile(File);

	SetTimer(1, 2000, NULL);
}

void CCVPrecordDspTestDlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	KillTimer(1);
}
