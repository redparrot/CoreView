// CVMimicDefineCommdll_ImTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CVMimicDefineCommdll_ImTest.h"
#include "CVMimicDefineCommdll_ImTestDlg.h"
#include "c:\coreview_src\funcsrc\cvmimicsrc\include\CVMimicDefineCommondll.h"
#include <io.h>
//#include "sys/types.h"
#include "sys/stat.h"
#include <memoryapi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
#define WM_ONE_FILE_CONVERT				WM_USER + 1006
#define WM_ONE_FILE_CONVERT_END			WM_USER + 1004
#define WM_ONE_FILE_OUTPUT				WM_USER + 1007
#define WM_ONE_FILE_OUTPUT_END			WM_USER + 1005
#define WM_ONE_FILE_PID_LIST			WM_USER + 1008
#define WM_ONE_FILE_CALL_LIST			WM_USER + 1009
#define WM_ONE_FILE_REPLACE_PID			WM_USER + 1010
#define WM_ALL_USED_MIMIC_LIST			WM_USER + 1011
#define WM_ALL_USED_MIMIC_PID_LIST		WM_USER + 1012 //
#define WM_ONE_FILE_CALL_AND_PID_LIST	WM_USER + 1013 //��������ͬʱ��Ҫ����ϵͳͼ��һ����ͼ�б��PID�б�

CString FileName = "c:\\Drawings\\GR200400.GRB";
const int LOOP_MAX = 100000;

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


// CCVMimicDefineCommdll_ImTestDlg �Ի���




CCVMimicDefineCommdll_ImTestDlg::CCVMimicDefineCommdll_ImTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCVMimicDefineCommdll_ImTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCVMimicDefineCommdll_ImTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
}

BEGIN_MESSAGE_MAP(CCVMimicDefineCommdll_ImTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDOK2, &CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk2)
	ON_BN_CLICKED(IDOK3, &CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk3)
	ON_BN_CLICKED(IDOK4, &CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk4)
	ON_BN_CLICKED(IDOK6, &CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk6)
	ON_BN_CLICKED(IDOK5, &CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk5)
	ON_BN_CLICKED(IDOK8, &CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk8)
	ON_BN_CLICKED(IDOK7, &CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk7)
	ON_BN_CLICKED(IDOK9, &CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk9)
	ON_BN_CLICKED(IDOK10, &CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk10)
	ON_BN_CLICKED(IDOK11, &CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk11)
END_MESSAGE_MAP()


// CCVMimicDefineCommdll_ImTestDlg ��Ϣ�������

BOOL CCVMimicDefineCommdll_ImTestDlg::OnInitDialog()
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

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCVMimicDefineCommdll_ImTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCVMimicDefineCommdll_ImTestDlg::OnPaint()
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
HCURSOR CCVMimicDefineCommdll_ImTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//OnOK();
	DWORD t1 = GetTickCount();

	//��ȡ
	CString csMimicPID;
	GetDlgItemText(IDC_EDIT1, csMimicPID);
	if (csMimicPID.IsEmpty())
	{
		csMimicPID = "A0001";
	}
	
	CString Msg;
	Msg.Format("��ȡ %s ������ϵͳͼ��", csMimicPID);
	//m_List.ResetContent();
	m_List.AddString(Msg);

	MimiNOAndName* pMimiList = NULL;
	int Cnt = GetMimicCountByPID_Im(csMimicPID);
	if (Cnt > 0)
	{
		pMimiList = new MimiNOAndName[Cnt];
		if (pMimiList != NULL)
		{
			bool b = GetMimicByPID_Im(csMimicPID, pMimiList);
		}

		for (int i = 0; i < Cnt; i++)
		{
			Msg.Format("%s, %s\n", pMimiList[i].MimNO, pMimiList[i].MimName);
			m_List.AddString(Msg);
		}

		delete[] pMimiList;
	}

	DWORD t2 = GetTickCount();
	Msg.Format("��ʱ = %d ms", t2 - t1);
	m_List.AddString(Msg);
}

void CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_List.ResetContent();
}

//CVMimicDisplay_Im.exe���һ����ͼ�����б�
void CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	GetMimicFileNameList();

	DWORD t1 = GetTickCount();

	int Cnt = (int)MimicFileNameList.size();
	//Cnt = 1;
	HWND hServerWnd;
	for (int i = 0; i < Cnt; i++)
	{
		hServerWnd = StartServer_MimicDisplay();
		CString GrNo = MimicFileNameList[i];

		int No = atoi(GrNo.Right(6)/*ȡ���ֲ���*/);
		LRESULT Ret = ::SendMessage(hServerWnd, WM_ONE_FILE_CALL_LIST, No, NULL);
	}

	StopServer_MimicDisplay(hServerWnd);

	DWORD t2 = GetTickCount();
	CString Msg;
	Msg.Format("CVMimicDisplay_Im�������һ����ͼ��ʱ=%d ms", t2 - t1);
	m_List.AddString(Msg);
}

int CCVMimicDefineCommdll_ImTestDlg::GetMimicFileNameList()
{
	//TRACE("����int GetMimicList()\n");
	DWORD t1 = GetTickCount();
	char				SrcfilePathFile[255];
	WIN32_FIND_DATA     FindFileData;
	HANDLE				handle;
	MimicFileNameList.clear();

	//�ж�·���Ƿ����
	//��ȡϵͳͼ���·��
	GetPrivateProfileString("Drawings Dir", "MimicPath", MIMICDEFAULTPATH, SrcfilePath, 255, MIMICSYSCONFINI);

	if (_access(SrcfilePath, 0) == -1)
	{
		return -1;
	}
	sprintf_s(SrcfilePathFile, "%s\\*.grb", SrcfilePath);
	handle = FindFirstFile(SrcfilePathFile, &FindFileData);
	if (handle != INVALID_HANDLE_VALUE)
	{
		BOOL		bResult = TRUE;
		CString		csGrb;
		MimicInfo GrbInfo;
		memset(&GrbInfo, 0, sizeof(MimicInfo));

		while (bResult)
		{
			csGrb.Format("%s", FindFileData.cFileName);
			if (csGrb.GetLength() != 12)
			{
				bResult = FindNextFile(handle, &FindFileData);
				continue;
			}
			csGrb.MakeUpper();
			csGrb = csGrb.Left(8);

			//���ͼ�Ƿ�Ϸ���ͼ
			if (IsValidGrbName(csGrb) == TRUE)
			{
				MimicFileNameList.push_back(csGrb);

				//�޸��ļ���Ϊȫ��д
				CString OriFile = FindFileData.cFileName;
				CString DstFile = OriFile;
				if (OriFile != DstFile.MakeUpper())
				{
					CString PathFile;
					PathFile.Format("%s\\%s", SrcfilePath, DstFile);
					BOOL b = MoveFile(PathFile, PathFile);
				}
			}
			bResult = FindNextFile(handle, &FindFileData);
		}
	}
	FindClose(handle);

	return (int)MimicFileNameList.size();
}

//Grab_Im.exe���һ����ͼ�����б�
void CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetMimicFileNameList();

	DWORD t1 = GetTickCount();

	int Cnt = (int)MimicFileNameList.size();
	HWND hServerWnd;
	for (int i = 0; i < Cnt; i++)
	{
		hServerWnd = StartServer();

		CString GrNo = MimicFileNameList[i];

		int No = atoi(GrNo.Right(6)/*ȡ���ֲ���*/);
		LRESULT Ret = ::SendMessage(hServerWnd, WM_ONE_FILE_CALL_LIST, No, NULL);
	}

	StopServer(hServerWnd);

	DWORD t2 = GetTickCount();
	CString Msg;
	Msg.Format("Grab_Im�������һ����ͼ��ʱ=%d ms", t2 - t1);
	m_List.AddString(Msg);
}


void CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetMimicFileNameList();

	DWORD t1 = GetTickCount();

	int Cnt = (int)MimicFileNameList.size();
	HWND hServerWnd;
	for (int i = 0; i < Cnt; i++)
	{
		hServerWnd = StartServer();

		CString GrNo = MimicFileNameList[i];

		int No = atoi(GrNo.Right(6)/*ȡ���ֲ���*/);
		LRESULT Ret = ::SendMessage(hServerWnd, WM_ONE_FILE_PID_LIST, No, NULL);
	}

	StopServer(hServerWnd);

	DWORD t2 = GetTickCount();
	CString Msg;
	Msg.Format("Grab_Im�������PID��ʱ=%d ms", t2 - t1);
	m_List.AddString(Msg);
}


void CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetMimicFileNameList();

	DWORD t1 = GetTickCount();

	int Cnt = (int)MimicFileNameList.size();
	//Cnt = 1;
	HWND hServerWnd;
	for (int i = 0; i < Cnt; i++)
	{
		hServerWnd = StartServer_MimicDisplay();
		CString GrNo = MimicFileNameList[i];

		int No = atoi(GrNo.Right(6)/*ȡ���ֲ���*/);
		LRESULT Ret = ::SendMessage(hServerWnd, WM_ONE_FILE_PID_LIST, No, NULL);
	}

	StopServer_MimicDisplay(hServerWnd);

	DWORD t2 = GetTickCount();
	CString Msg;
	Msg.Format("CVMimicDisplay_Im�������PID��ʱ=%d ms", t2 - t1);
	m_List.AddString(Msg);
}


void CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk8()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetMimicFileNameList();

	DWORD t1 = GetTickCount();

	int Cnt = (int)MimicFileNameList.size();
	//Cnt = 1;
	HWND hServerWnd;
	for (int i = 0; i < Cnt; i++)
	{
		hServerWnd = StartServer();
		CString GrNo = MimicFileNameList[i];

		int No = atoi(GrNo.Right(6)/*ȡ���ֲ���*/);
		LRESULT Ret = ::SendMessage(hServerWnd, WM_ONE_FILE_CALL_AND_PID_LIST, No, NULL);
	}

	StopServer(hServerWnd);

	DWORD t2 = GetTickCount();
	CString Msg;
	Msg.Format("Grab_Im���������ͼ/PID��ʱ=%d ms", t2 - t1);
	m_List.AddString(Msg);

}


void CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetMimicFileNameList();

	DWORD t1 = GetTickCount();

	int Cnt = (int)MimicFileNameList.size();
	//Cnt = 1;
	HWND hServerWnd;
	for (int i = 0; i < Cnt; i++)
	{
		hServerWnd = StartServer_MimicDisplay();
		CString GrNo = MimicFileNameList[i];

		int No = atoi(GrNo.Right(6)/*ȡ���ֲ���*/);
		LRESULT Ret = ::SendMessage(hServerWnd, WM_ONE_FILE_CALL_AND_PID_LIST, No, NULL);
	}

	StopServer_MimicDisplay(hServerWnd);

	DWORD t2 = GetTickCount();
	CString Msg;
	Msg.Format("CVMimicDisplay_Im���������ͼ/PID��ʱ=%d ms", t2 - t1);
	m_List.AddString(Msg);

}

void CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk9()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int Len = 0;
	time_t ModifyTime = 0;
	DWORD t1 = GetTickCount();
	for (int i = 0; i < LOOP_MAX; i++)
	{
		Len = GetFileLen_MFC(FileName, ModifyTime);
	}
	DWORD t2 = GetTickCount();

	CString Msg;
	Msg.Format("ѭ��%d��GetFileLen_MFC()��ʱ=%d ms, Len=%d Bytes, Time=%d", LOOP_MAX, t2 - t1, Len, ModifyTime);
	MessageBox(Msg, "", MB_OK);
}

int CCVMimicDefineCommdll_ImTestDlg::GetFileLen_MFC(CString FileName, time_t& ModifyTime)
{
	CFileFind Find;
	int Len = 0;
	BOOL b = Find.FindFile(FileName);
	if (b)
	{
		Find.FindNextFile();
		Len = (int)Find.GetLength();
		CTime Time;
		Find.GetLastWriteTime(Time);
		ModifyTime = (__time32_t)Time.GetTime();
		Find.Close();
	}

	return Len;
}

int CCVMimicDefineCommdll_ImTestDlg::GetFileLen_C(CString FileName, time_t& ModifyTime)
{
	int Len = 0;
	struct _stat32 stat;
	_stat32(FileName, &stat);
	Len = stat.st_size;
	ModifyTime = stat.st_mtime;

	return Len;
}


void CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk10()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int Len = 0;
	time_t ModifyTime = 0;
	DWORD t1 = GetTickCount();
	for (int i = 0; i < LOOP_MAX; i++)
	{
		Len = GetFileLen_C(FileName, ModifyTime);
	}
	DWORD t2 = GetTickCount();

	CString Msg;
	Msg.Format("ѭ��%d��GetFileLen_C()��ʱ=%d ms, Len=%d Bytes, Time=%d", LOOP_MAX, t2 - t1, Len, ModifyTime);
	MessageBox(Msg, "", MB_OK);

}


void CCVMimicDefineCommdll_ImTestDlg::OnBnClickedOk11()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ULONG MinimumFileCacheSize = 0;
	ULONG MaximumFileCacheSize = 0;
	DWORD  Flags = 0;
	BOOL b = GetSystemFileCacheSize(&MinimumFileCacheSize, &MaximumFileCacheSize, &Flags);
	DWORD Err = GetLastError();
}
