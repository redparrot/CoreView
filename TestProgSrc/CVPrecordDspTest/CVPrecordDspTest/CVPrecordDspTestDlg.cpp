// CVPrecordDspTestDlg.cpp : ʵ���ļ�
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
	long	lMemChgCnt;		//�ڴ�仯������
	long	lMemMsgCnt;		//�ڴ��еļ�¼��
	long	lDelPathTmName;	//��ɾ����·��
	int		nFileBufCount;	//�ļ��б�ĳ���
	int		nFileBufWtPt;	//дָ���λ��
}ShareMemHead_T;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
const int SimCount = 10;
const int SimMemCount = 2;
void CCVPrecordDspTestDlg::SetSimFile(CString File, DWORD Time)//�����ļ�
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

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CCVPrecordDspTestDlg �Ի���

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

// CCVPrecordDspTestDlg ��Ϣ�������

BOOL CCVPrecordDspTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_SHOW);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	ChgFileMax = GetPrivateProfileInt("PrdDataFile_Field", "DelayMsg_InsFileCnt", NULL, IniFileName);

	//OnBnClickedButton1();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCVPrecordDspTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CCVPrecordDspTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCVPrecordDspTestDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

	{//������POCվʱÿ�������һ����¼�����һ���ļ���
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

		////�޸Ĺ����ڴ��е��ļ��б�
		//p = m_pMap + sizeof(ShareMemHead_T);
		//*(time_t*)p = lTime;
	}


	{//��������ʷվʱÿ�������һ����¼�����һ���ļ���
		//ÿ�������һ����¼�����һ���ļ���
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

		//�޸Ĺ����ڴ��е��ļ��б�
		p = m_pMap + sizeof(ShareMemHead_T);
		*(time_t*)p = lTime;
	}

	CDialog::OnTimer(nIDEvent);
}

//BOOL CCVPrecordDspTestDlg::PreCreateWindow(CREATESTRUCT& cs)
//{
//	// TODO: �ڴ����ר�ô����/����û���
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

BOOL CCVPrecordDspTestDlg::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ����ר�ô����/����û���

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

	// TODO:  �ڴ������ר�õĴ�������

	return 0;
}

void CCVPrecordDspTestDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

	//��ȡ���з��������������ļ���
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

	//��ȡ�ļ����е��ļ������б�
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

//�޸����һ���ļ��ļ�¼��
void CCVPrecordDspTestDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnTimer(1);
}

//�����ڴ��¼
void CCVPrecordDspTestDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

//����ڴ��¼
void CCVPrecordDspTestDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

//������ϼ�¼�ļ�
void CCVPrecordDspTestDlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//char PID[8] = {"A0005"};
	BYTE Type[2] = {1, 1};


}

//��������ڴ��¼
void CCVPrecordDspTestDlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

	//����
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

	//����(������)
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

	//������˫�򱨾��ָ�
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

	//�˹�����
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

	//״̬��λ
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

void SetSimFile(int Date)	/* �����ļ� */
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for(int i = 22; i <= 28; i++)
	{
		//SetSimFile(i);
	}
}

//��������
void CCVPrecordDspTestDlg::OnBnClickedButton11()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString File;

	//File.Format("C:\\coreview\\funcexec\\cvprecordexec\\Data\\070926\\Prd%d.dat", FileName); 
	//DeleteFile(File);

	SetTimer(1, 2000, NULL);
}

void CCVPrecordDspTestDlg::OnBnClickedButton12()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	KillTimer(1);
}
