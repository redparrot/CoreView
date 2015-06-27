// CVPrintManagerTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CVPrintManagerTest.h"
#include "CVPrintManagerTestDlg.h"

#include "C:\CoreView_Src\Include\CVFilePrintDllComm.h"
#include "C:\CoreView_Src\Include\CVExcelManagerComm.h"
#include "Dll.h"
#include <vector>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

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

// CCVPrintManagerTestDlg �Ի���

CCVPrintManagerTestDlg::CCVPrintManagerTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCVPrintManagerTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCVPrintManagerTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCVPrintManagerTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CCVPrintManagerTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCVPrintManagerTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCVPrintManagerTestDlg::OnBnClickedButton3)
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON4, &CCVPrintManagerTestDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCVPrintManagerTestDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCVPrintManagerTestDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCVPrintManagerTestDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCVPrintManagerTestDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCVPrintManagerTestDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CCVPrintManagerTestDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON12, &CCVPrintManagerTestDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON15, &CCVPrintManagerTestDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON13, &CCVPrintManagerTestDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CCVPrintManagerTestDlg::OnBnClickedButton14)
	//ON_BN_CLICKED(IDC_BUTTON11, &CCVPrintManagerTestDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON16, &CCVPrintManagerTestDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CCVPrintManagerTestDlg::OnBnClickedButton17)
END_MESSAGE_MAP()


// CCVPrintManagerTestDlg ��Ϣ�������

BOOL CCVPrintManagerTestDlg::OnInitDialog()
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
	//DllFileName.Format("C:\\CoreView\\Progfiles\\Bin\\CVPrinterDiagnose.dll");
	//VERIFY(hModule=::LoadLibrary(DllFileName));
	//PrinterDiagnose=(pPrinterDiagnose)::GetProcAddress(hModule, "PrinterDiagnose");

	//::FreeLibrary(hModule);

	char buf[100] = {0};
	ExePath = GetExePath() + "CVPrintManagerTest.ini";
	GetPrivateProfileString("CVPrintManagerTest", "PrnName", NULL, buf, sizeof(buf), ExePath);
	SetDlgItemText(IDC_PRN_NAME, buf);

	GetPrivateProfileString("CVPrintManagerTest", "DataFile", NULL, buf, sizeof(buf), ExePath);
	SetDlgItemText(IDC_EDIT1, buf);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCVPrintManagerTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCVPrintManagerTestDlg::OnPaint()
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
HCURSOR CCVPrintManagerTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCVPrintManagerTestDlg::OnBnClickedButton1()
{
	//CallOutputExcel();
}

void CCVPrintManagerTestDlg::OnBnClickedButton2()
{
	WORD Taskid = 14;

	PrintExcelFile(Taskid, 
		"C:\\coreview\\funcexec\\CVLogExec\\Configure\\��׼����һ�����ģ��.xls", 
		TRUE, FALSE);
}

void CCVPrintManagerTestDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	CString PrnName;
	GetDlgItemText(IDC_PRN_NAME, PrnName);
	WritePrivateProfileString("CVPrintManagerTest", "PrnName", PrnName, ExePath);

	SetTimer(1, 1000, NULL);
}

void CCVPrintManagerTestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == 1)
	{
		static DWORD Count = 0;
		CString pPrinter;
		GetDlgItemText(IDC_PRN_NAME, pPrinter);
		if (pPrinter.IsEmpty())
			pPrinter = "HP LaserJet 4250 PCL6 Class Driver";

		SDiagnose Dia = PrinterDiagnose(pPrinter);

		CString s;
		Count ++;
		s.Format("��ӡ����Դ״̬��%d, ״̬�룺%d����������%d", Dia.Power, Dia.Status, Count);
		SetDlgItemText(IDC_STATIC1, s);
	}

	if (nIDEvent == 2)//����ת������
	{
		LoopCnt++;
		int LoopMax = 10;
		if (LoopCnt > LoopMax)
		{
			LoopCnt = 0;
			KillTimer(2);
			CString Msg;
			Msg.Format("%d��ѭ������", LoopMax);
			MessageBox(Msg, "��ʾ��", MB_OK | MB_TOPMOST);
			return;
		}
		OnBnClickedButton12();
	}

	if (nIDEvent == 3)
	{
		static DWORD Count = 0;

		int Cnt = GetPrinterNums();
		PrntSts* pPrntSts = NULL;
		int Ok = 0;
		vector<PrntSts> list;

		//Cnt = 0;
		if (Cnt >= 0)
		{
			pPrntSts = new PrntSts[Cnt];
			Ok = GetPrinterStsList(50, Cnt, pPrntSts);
			for (int i = 0; i < Cnt; i++)
			{
				list.push_back(pPrntSts[i]);
			}

			delete[] pPrntSts;

			Count ++;
			CString Msg;
			Msg.Format("����ֵ=%d, ��������%d", Ok, Count);
			SetDlgItemText(IDC_STATIC2, Msg);
		}
	}

	if (nIDEvent == 4)//���ڴ�ӡ����
	{
		LoopCnt++;
		int LoopMax = 10;
		if (LoopCnt > LoopMax)
		{
			LoopCnt = 0;
			KillTimer(4);
			CString Msg;
			Msg.Format("%d��ѭ������", LoopMax);
			MessageBox(Msg, "��ʾ��", MB_OK | MB_TOPMOST);
			return;
		}

		WORD Taskid = 14;
		PrintExcelFile(Taskid, 
			"C:\\coreview\\funcexec\\CVLogExec\\Configure\\��׼����һ�����ģ��.xls", 
			FALSE, FALSE);
	}

	if (nIDEvent == 5)//���������������
	{
		LoopCnt++;
		int LoopMax = 10;
		if (LoopCnt > LoopMax)
		{
			LoopCnt = 0;
			KillTimer(5);
			CString Msg;
			Msg.Format("%d��ѭ������", LoopMax);
			MessageBox(Msg, "��ʾ��", MB_OK | MB_TOPMOST);
			return;
		}

		OnBnClickedButton6();
	}

	CDialog::OnTimer(nIDEvent);
}

void CCVPrintManagerTestDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	//FreeLibrary(hModule);

	CDialog::OnClose();
}

void CCVPrintManagerTestDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetTimer(3, 1000, NULL);
}

void CCVPrintManagerTestDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//HMODULE  hModule;
	//typedef BOOL (*pReportConvert)(CString&, CString&);
	//pReportConvert ReportConvert;

	//CString DllFileName;
	//DllFileName.Format("C:\\CoreView\\Progfiles\\Bin\\CVExcelManager.dll");
	//VERIFY(hModule=::LoadLibrary(DllFileName));
	//ReportConvert=(pReportConvert)::GetProcAddress(hModule, "ReportConvert");

	//CString pOutputExcel = "C:\\CoreView\\Record data\\Report\\Lgtmp\\�¼�����.xls";
	CString DataName;

	DataName = GetDataFileName();

	BOOL ret = ReportConvert(DataName);

	//::FreeLibrary(hModule);
}

//�����¼�����ת��
void CCVPrintManagerTestDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStringArray StrArray;
	StrArray.Add("����");
	StrArray.Add("ʱ��");
	StrArray.Add("PID");
	StrArray.Add("KKS");
	StrArray.Add("����");
	StrArray.Add("ֵ");
	StrArray.Add("״̬");
	StrArray.Add("��λ");

	for (int i = 0; i < 1000; i++)
	{
		StrArray.Add("1");
		StrArray.Add("2014-9-25 00:00:00");
		StrArray.Add("A0001");
		StrArray.Add("KKS0001");
		StrArray.Add("����XXXX");
		StrArray.Add("0.01");
		StrArray.Add("OK");
		StrArray.Add("Pa");
	}

	BOOL ret = OutputExcel(CString("c:\\CoreView\\FuncExec\\CVDataListExec\\Configure\\Standard Review Display Template.xls"), CString("C:\\Temp\\һ�����.xls"), CString("AAA"), CString(""), StrArray, 8);

}

//�ձ�ת��
void CCVPrintManagerTestDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString DataName;

	DataName = GetDataFileName();

	BOOL ret = ReportConvert(DataName);
}

//�±�ת��
void CCVPrintManagerTestDlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString DataName;

	DataName = GetDataFileName();
	BOOL ret = ReportConvert(DataName);
}

//�걨ת��
void CCVPrintManagerTestDlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString DataName;

	DataName = GetDataFileName();
	BOOL ret = ReportConvert(DataName);
}

//�౨ת��
void CCVPrintManagerTestDlg::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString DataName;

	DataName = GetDataFileName();
	BOOL ret = ReportConvert(DataName);
}

CString CCVPrintManagerTestDlg::GetDataFileName()
{
	CString Name;
	CString DataFileName;

	GetDlgItemText(IDC_EDIT1, Name);
	//if (Name.IsEmpty())
	//{
	//	Name = "C140416101100lg001.dat";//���Բο�������ָ��ֳ�������
	//}
	//if (Name.IsEmpty())
	//{
	//	return "";
	//}
	//DataFileName.Format("C:\\CoreView\\FuncExec\\CVLogExec\\Data\\LgTmp\\%s", Name);

	DataFileName = Name;

	WritePrivateProfileString("CVPrintManagerTest", "DataFile", Name, ExePath);

	return DataFileName;
}

//��ť��ת��
void CCVPrintManagerTestDlg::OnBnClickedButton12()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CString DataName;
	DataName = GetDataFileName();
	BOOL ret = ReportConvert(DataName);
}

//��ť��ֹͣ����Timer
void CCVPrintManagerTestDlg::OnBnClickedButton15()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	KillTimer(2);
}

//
void CCVPrintManagerTestDlg::OnBnClickedButton13()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString DataName = "C:\\temp.xls";

	//BOOL ret = OpenAndRestore(DataName);

}

//��ť������ת��
void CCVPrintManagerTestDlg::OnBnClickedButton14()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	LoopCnt = 0;
	SetTimer(2, 5000, NULL);
	OnTimer(2);
}

//��ʷ�����¼�����
void CCVPrintManagerTestDlg::OnBnClickedButton11()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString DataName;

	DataName = GetDataFileName();

	BOOL ret = ReportConvert(DataName);

}

CString CCVPrintManagerTestDlg::GetExePath()
{
	CString PathStr;

	GetModuleFileName(NULL, PathStr.GetBuffer(MAX_PATH), MAX_PATH);
	PathStr.ReleaseBuffer();

	int Pos = PathStr.ReverseFind('\\');

	if(Pos != -1)
		PathStr = PathStr.Left(Pos + 1);
	else
		PathStr.Empty();

	return PathStr;
}


void CCVPrintManagerTestDlg::OnBnClickedButton16()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	LoopCnt = 0;
	SetTimer(4, 1000, NULL);
	OnTimer(4);
}

void CCVPrintManagerTestDlg::OnBnClickedButton17()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	LoopCnt = 0;
	SetTimer(5, 1000, NULL);
	OnTimer(5);
}
