// AutoSetDataDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AutoSetData.h"
#include "AutoSetDataDlg.h"
#include <io.h>
#include <math.h>
#include <time.h>
#include "shlobj.h"
#include "C:\CoreView_src\Include\CVWriteEventLogComm.h"
#include "C:\CoreView_src\include\CVLocalDateDllComm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//#pragma comment(lib,"C:\\CoreView\\SystemExec\\bin\\CVCommonDll.lib")

#define _NIU_TITLE_BAK_COLOR   RGB(192,192,192)
#define _NIU_TITLE_TXT_COLOR   RGB(0,0,255)
#define ID_CORE_TIME ID_INDICATOR_SCRL + 1

#include <list>
#include <shlobj.h>
using namespace std;

extern CAutoSetDataApp theApp;

IIDAndValueListType m_IIDList;
//const int MaxRowNums = 20000 + 1;
const int MaxColWidth = 120;

typedef struct PidDataSetType
{
    char cPid[8];
    char cDeFaultValu[32];
    char cLowValue[32];
    char cHighValue[32];
    char cStep[32];
} PidDataSetType;

/////////////////////////////////////////////////////////////////////////////
// CAutoSetDataDlg dialog

CAutoSetDataDlg::CAutoSetDataDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CAutoSetDataDlg::IDD, pParent)
{
    //{{AFX_DATA_INIT(CAutoSetDataDlg)
    // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
    // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	IniFileName =  GetInstallPath() + "AutoSetData.ini";

}

void CAutoSetDataDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CAutoSetDataDlg)
    // NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Control(pDX, IDC_CUSTOM_GRID, m_Grid);
    //}}AFX_DATA_MAP
    DDX_Control(pDX, IDC_EDIT1, m_EditPerid);
    DDX_Control(pDX, IDC_CHECK1, m_Sin);
}

BEGIN_MESSAGE_MAP(CAutoSetDataDlg, CDialog)
    //{{AFX_MSG_MAP(CAutoSetDataDlg)
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    //}}AFX_MSG_MAP
    ON_WM_CLOSE()
    ON_WM_TIMER()
    ON_BN_CLICKED(IDC_BUTTON_BEGIN, &CAutoSetDataDlg::OnBnClickedButtonBegin)
    ON_BN_CLICKED(IDC_BUTTON_PAUSE, &CAutoSetDataDlg::OnBnClickedButtonPause)
    ON_BN_CLICKED(IDC_BUTTON_BEGIN3, &CAutoSetDataDlg::OnBnClickedButtonBegin3)
    ON_BN_CLICKED(IDCANCEL, &CAutoSetDataDlg::OnBnClickedCancel)
    ON_MESSAGE(WM_AUTO_PID_INFO, OnAutoPIDInfo)
    ON_BN_CLICKED(IDC_BUTTON1, &CAutoSetDataDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAutoSetDataDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CAutoSetDataDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CAutoSetDataDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CAutoSetDataDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CAutoSetDataDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_AI, &CAutoSetDataDlg::OnBnClickedButtonAi)
	ON_BN_CLICKED(IDC_BUTTON_DI, &CAutoSetDataDlg::OnBnClickedButtonDi)
	ON_BN_CLICKED(IDC_BUTTON_AO, &CAutoSetDataDlg::OnBnClickedButtonAo)
	ON_BN_CLICKED(IDC_BUTTON_DO, &CAutoSetDataDlg::OnBnClickedButtonDo)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoSetDataDlg message handlers
CString CAutoSetDataDlg::GetInstallPath()
{
	CString PathStr;
	char PathBuffer[MAX_PATH] = {0};

	GetModuleFileName(NULL, PathBuffer, MAX_PATH);
	PathStr = PathBuffer;

	PathStr.MakeUpper();
	int Pos = PathStr.ReverseFind('\\');
	if (Pos != -1)
	{
		PathStr = PathStr.Left(Pos + 1);
	}

	return PathStr;
}

BOOL CAutoSetDataDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // Set the icon for this dialog.  The framework does this automatically
    //  when the application's main window is not a dialog
    SetIcon(m_hIcon, TRUE);			// Set big icon
    SetIcon(m_hIcon, FALSE);		// Set small icon

    // TODO: Add extra initialization here
	theApp.Dlg = this;

    //产生路径
    //SHCreateDirectoryEx(NULL, "C:\\CoreView\\TestProgsExec\\Exe\\", NULL);

	//获取可执行文件路径
	CfgFile = GetInstallPath() + "AutoSetData.set";

    //初始化Grid
    InitializeData();

    ReadDefaultFormFile();

	//设置周期
	int Cyc = GetPrivateProfileInt("AutoSetData", "Cycle", 1000, IniFileName);
	if (Cyc < 1000)
	{
		Cyc = 1000;
	}
	SetDlgItemInt(IDC_EDIT1, Cyc);

	//设置正弦
	int Sin = GetPrivateProfileInt("AutoSetData", "Sin", 0, IniFileName);
	((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(Sin);

    return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAutoSetDataDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this); // device context for painting

        SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

        // Center icon in client rectangle
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // Draw the icon
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialog::OnPaint();
    }
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAutoSetDataDlg::OnQueryDragIcon()
{
    return (HCURSOR) m_hIcon;
}

void CAutoSetDataDlg::InitializeData()
{
    TRY
    {
		//获取所有的PID列表……
		for (int i = AITAG; i <= DOTAG; i++)
		{
			GetTagList(i);

			//写入各个类型的总点数……
			CString Nums;
			CString Type = GetTypeString(i);
			Nums.Format("%s:%d", Type, PIDCnt[i - 1]);
			SetDlgItemText(IDC_STATIC_AI + i - 1, Nums);
		}

		//计算MaxRowNums……
		MaxRowNums = PIDCnt[0]/*AI*/ + PIDCnt[2]/*AO*/ + 200/*DI+DO*/;

		m_IIDList.resize(MaxRowNums);
        m_Grid.SetRowCount(MaxRowNums);
        m_Grid.SetColumnCount(7);
        m_Grid.SetFixedRowCount(1);
        //m_Grid.SetFixedColumnCount(1);
        m_Grid.SetRowResize(FALSE);//禁止行宽的设定

        int row = 0;
        CString str;
        GV_ITEM Item;

        Item.mask = GVIF_TEXT | GVIF_FGCLR;
        Item.row = row;
        Item.col = 0;
        str.Format(_T("No."));
        Item.strText = str;
        Item.crFgClr = _NIU_TITLE_TXT_COLOR;    // or - m_Grid.SetItemFgColour(row, col, RGB(255,0,0));
        Item.align = DT_LEFT;
        m_Grid.SetItem(&Item);
        m_Grid.SetColumnWidth(Item.col, 40);

        Item.mask = GVIF_TEXT | GVIF_FGCLR;
        Item.row = row;
        Item.col = 1;
        str.Format(_T("PID"));
        Item.strText = str;
        Item.crFgClr = _NIU_TITLE_TXT_COLOR;    // or - m_Grid.SetItemFgColour(row, col, RGB(255,0,0));
        Item.align = DT_CENTER;
        m_Grid.SetItem(&Item);
        m_Grid.SetColumnWidth(Item.col, MaxColWidth);

        row = 0;
        Item.mask = GVIF_TEXT | GVIF_FGCLR;
        Item.row = row;
        Item.col = 2;
        str.Format(_T("默认值"));
        Item.strText = str;
        Item.crFgClr = _NIU_TITLE_TXT_COLOR;    // or - m_Grid.SetItemFgColour(row, col, RGB(255,0,0));
        Item.align = DT_CENTER;
        m_Grid.SetItem(&Item);
        m_Grid.SetColumnWidth(Item.col, MaxColWidth);

        row = 0;
        Item.mask = GVIF_TEXT | GVIF_FGCLR;
        Item.row = row;
        Item.col = 5;
        str.Format(_T("步长"));
        Item.strText = str;
        Item.crFgClr = _NIU_TITLE_TXT_COLOR;    // or - m_Grid.SetItemFgColour(row, col, RGB(255,0,0));
        Item.align = DT_CENTER;
        m_Grid.SetItem(&Item);
        m_Grid.SetColumnWidth(Item.col, MaxColWidth);

        row = 0;
        Item.mask = GVIF_TEXT | GVIF_FGCLR;
        Item.row = row;
        Item.col = 3;
        str.Format(_T("底限值"));
        Item.strText = str;
        Item.crFgClr = _NIU_TITLE_TXT_COLOR;    // or - m_Grid.SetItemFgColour(row, col, RGB(255,0,0));
        Item.align = DT_CENTER;
        m_Grid.SetItem(&Item);
        m_Grid.SetColumnWidth(Item.col, MaxColWidth);

        row = 0;
        Item.mask = GVIF_TEXT | GVIF_FGCLR;
        Item.row = row;
        Item.col = 4;
        str.Format(_T("高限值"));
        Item.strText = str;
        Item.align = DT_RIGHT;
        m_Grid.SetItem(&Item);
        m_Grid.SetColumnWidth(Item.col, MaxColWidth);

        row = 0;
        Item.mask = GVIF_TEXT | GVIF_FGCLR;
        Item.row = row;
        Item.col = 6;
        str.Format(_T("当前值"));
        Item.strText = str;
        Item.crFgClr = _NIU_TITLE_TXT_COLOR;    // or - m_Grid.SetItemFgColour(row, col, RGB(255,0,0));
        Item.align = DT_CENTER;
        m_Grid.SetItem(&Item);
        m_Grid.SetColumnWidth(Item.col, MaxColWidth);

        //设置行高
        for (int i = 0; i < MaxRowNums; i++)
        {
            m_Grid.SetRowHeight(i, 29);
        }

        //设置行号
        CString RowNo;
        for (int i = 1; i < MaxRowNums; i++)
        {
            RowNo.Format("%d", i);
            m_Grid.SetItemText(i, 0, RowNo);
        }
    }
    CATCH (CMemoryException, e)
    {
        e->ReportError();
        return;
    }
    END_CATCH
    {
    }

    return;
}

void CAutoSetDataDlg::ReadDefaultFormFile(void)
{
    FILE *fpSubMacro;
    int i;
    errno_t err;

    PidDataSetType *pPidData;//组合宏子表内存指针
    int  SubMacroRecCnt;//公式主表和子表的记录数

    if (0 != _access(CfgFile, 00))
    {
        return;
    }
    err = fopen_s(&fpSubMacro, CfgFile, "rb");

    char cPeriod[20];
    long lPriod;

    fseek(fpSubMacro, 0, SEEK_END);

    SubMacroRecCnt = (ftell(fpSubMacro) - sizeof(long)) / sizeof(PidDataSetType);

    //开辟内存
    pPidData = (PidDataSetType*)malloc(SubMacroRecCnt * sizeof(PidDataSetType));

    //开始往内存中写数据清空
    memset(pPidData, 0x00, SubMacroRecCnt * sizeof(PidDataSetType));

    //SubFormula
    fseek(fpSubMacro, 0, SEEK_SET);
    fread(&lPriod, sizeof(long), 1, fpSubMacro);
    if (lPriod <= 0)
    {
        lPriod = 2000;
    }
    fread(pPidData, sizeof(PidDataSetType), SubMacroRecCnt, fpSubMacro);

    //关闭文件指针
    fclose(fpSubMacro);

    memset(cPeriod, '\0', sizeof(cPeriod));
    sprintf_s(cPeriod, sizeof(cPeriod), "%ld", lPriod);
    m_EditPerid.SetWindowTextA(cPeriod);

    CString PID;
    long ret = 0;
    long IID = 0;
    for (i = 0; i < SubMacroRecCnt; i++)
    {
        PID = pPidData[i].cPid;
        m_Grid.SetItemText(i + 1, 1, PID.MakeUpper());
        ret = GetIID(PID.GetBuffer(), IID);
        if (ret == 0)
        {
            m_Grid.SetItemText(i + 1, 2, pPidData[i].cDeFaultValu);
            m_Grid.SetItemText(i + 1, 3, pPidData[i].cLowValue);
            m_Grid.SetItemText(i + 1, 4, pPidData[i].cHighValue);
            m_Grid.SetItemText(i + 1, 5, pPidData[i].cStep);
        }
        else
        {
            CString Value = "无效";
            m_Grid.SetItemText(i + 1, 2, Value);
            m_Grid.SetItemText(i + 1, 3, Value);
            m_Grid.SetItemText(i + 1, 4, Value);
            m_Grid.SetItemText(i + 1, 5, Value);
        }
    }
    PID.ReleaseBuffer();

    free(pPidData);
    //m_Grid.AutoSize();
}

void CAutoSetDataDlg::SaveToFile(void)
{
    char cPeriod[20];
    long lPriod;

    memset(cPeriod, '\0', sizeof(cPeriod));
    m_EditPerid.GetWindowTextA(cPeriod, sizeof(cPeriod));

    lPriod = atol(cPeriod);
    if (lPriod < 1000)
    {
        lPriod = 2000;
    }

    FILE *fpSubMacro;
    errno_t err;

    PidDataSetType *pPidData;//

    //计算有效行的数量
    int i;
    int iRowCnt = 0;
    int MaxRow = m_Grid.GetRowCount();
    CString csText;
    for (i = 1; i <= MaxRow - 1; i++)
    {
        csText.Empty();
        csText = m_Grid.GetItemText(i, 1);
        if (FALSE == csText.IsEmpty())
        {
            iRowCnt++;
        }
    }

    //开辟宏内存
    pPidData = (PidDataSetType*)malloc(iRowCnt * sizeof(PidDataSetType));

    //开始往内存中写数据清空
    memset(pPidData, 0x00, iRowCnt * sizeof(PidDataSetType));
    int BuffIdx = -1;
    long IID = 0;
    long Ret = 0;
    for (i = 1; i <= MaxRow - 1; i++)
    {
        csText = m_Grid.GetItemText(i, 1);
        if (csText.IsEmpty() == FALSE)
        {
            Ret = GetIID(csText.GetBuffer(), IID);
            if (Ret == 0)//有效PID
            {
                BuffIdx++;
                strcpy_s(pPidData[BuffIdx].cPid, sizeof(pPidData[BuffIdx].cPid), csText);
                m_Grid.SetItemText(i, 1, csText.MakeUpper());
                m_Grid.RedrawCell(i, 1);

                csText = m_Grid.GetItemText(i, 2);
                strcpy_s(pPidData[BuffIdx].cDeFaultValu, sizeof(pPidData[BuffIdx].cDeFaultValu), csText);

                csText = m_Grid.GetItemText(i, 3);
                strcpy_s(pPidData[BuffIdx].cLowValue, sizeof(pPidData[BuffIdx].cLowValue), csText);

                csText = m_Grid.GetItemText(i, 4);
                strcpy_s(pPidData[BuffIdx].cHighValue, sizeof(pPidData[BuffIdx].cHighValue), csText);

                csText = m_Grid.GetItemText(i, 5);
                strcpy_s(pPidData[BuffIdx].cStep, sizeof(pPidData[BuffIdx].cStep), csText);
            }
            else
            {
                BuffIdx++;
                strcpy_s(pPidData[BuffIdx].cPid, sizeof(pPidData[BuffIdx].cPid), csText);
            }
        }
    }
    csText.ReleaseBuffer();

    if (0 != _access(CfgFile, 00))
    {
        _unlink(CfgFile);
    }
    err = fopen_s(&fpSubMacro, CfgFile, "wb");

    //SubFormula
    fseek(fpSubMacro, 0, SEEK_SET);
    fwrite(&lPriod, sizeof(long), 1, fpSubMacro);
    fwrite(pPidData, sizeof(PidDataSetType), iRowCnt, fpSubMacro);

    //关闭文件指针
    fclose(fpSubMacro);
    free(pPidData);

    //重新顺一遍PID，去除空行
    //清空控件
    CCellRange Selection(1, 1, 200, 6);
    m_Grid.ClearCells(Selection);
    ReadDefaultFormFile();
}

void CAutoSetDataDlg::OnClose()
{
    // TODO: Add your message handler code here and/or call default
    KillTimer(m_nTimer);
    SaveToFile();
    CDialog::OnClose();
}

void CAutoSetDataDlg::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: Add your message handler code here and/or call default
    if (WM_TIMER + 1 == nIDEvent)
    {
        TRACE("TickCount：%d\n", GetTickCount());
        SetData();
    }

    CDialog::OnTimer(nIDEvent);
}

void CAutoSetDataDlg::OnBnClickedButtonBegin()
{
    // TODO: Add your control notification handler code here
    SaveToFile();

    if (m_nTimer != NULL)
    {
        KillTimer(m_nTimer);
    }
    char cGetTime[20];

    memset(cGetTime, '\0', sizeof(cGetTime));
    m_EditPerid.GetWindowTextA(cGetTime, sizeof(cGetTime));

    iPeriod = atoi(cGetTime);

	//获取有效PID个数
	int RowCnt = GetPIDList(IIDList);

	//构建m_IIDList
	GetIIDStructList(IIDList, m_IIDList);

	int ListSize = (int)IIDList.size();
	//计算模拟量的数量
	BYTE byIsDigital, byType;
	long lRtn = 0;
	int ACnt = 0;
	int DCnt = 0;
	for (int i = 0; i < ListSize; i++)
	{
		lRtn = IsDigital(IIDList[i], byIsDigital, byType);
		if (1 == byIsDigital)//数字量处理
		{
			DCnt++;
		}
		else
		{
			ACnt++;
		}
	}
	ADataSetLst.resize(ACnt);
	DDataSetLst.resize(DCnt);

    //启动等待时间
    m_nTimer = SetTimer(WM_TIMER + 1, iPeriod/*置数周期*/, 0);
    m_tLastTime = GetTickCount();
}

void CAutoSetDataDlg::SetData(void)
{
	float fDefault = 0.0;
	float fValue = 0.0;
	CString csItemText;

	//计算设定值
	GetSetValues();

	//置数
    DataSet(m_IIDList);

	//更新当前可见行的值显示
	RefreshVisibleRow();
}

void CAutoSetDataDlg::OnBnClickedButtonPause()
{
    // TODO: Add your control notification handler code here
    KillTimer(m_nTimer);
}

void CAutoSetDataDlg::OnBnClickedButtonBegin3()
{
    // TODO: 在此添加控件通知处理程序代码
    SaveToFile();

	//记录ini文件...
	//记录周期设置
	CString Str;
	GetDlgItemText(IDC_EDIT1, Str);
	int Check = ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck();
	WritePrivateProfileString("AutoSetData", "Cycle", Str, IniFileName);
	Str.Format("%d", Check);
	WritePrivateProfileString("AutoSetData", "Sin", Str, IniFileName);

	//记录正弦设置
}

void CAutoSetDataDlg::OnBnClickedCancel()
{
    // TODO: 在此添加控件通知处理程序代码
    OnClose();
    OnCancel();
}

LRESULT CAutoSetDataDlg::OnAutoPIDInfo(WPARAM wParam, LPARAM lParam)
{
    CString PID, Text, Value;
    FLOAT Min, Max;
    LONG IID = 0;
    long ret = 0;
    for (int i = 1; i <= MaxRowNums - 1; i++)
    {
        PID = m_Grid.GetItemText(i, 1);//PID
        if (PID.IsEmpty() == FALSE)
        {
            Text = m_Grid.GetItemText(i, 3);//下限
            if (Text.IsEmpty())//下限为空
            {
                //PID合法
                ret = GetIID(PID.GetBuffer(), IID);
                if (ret == 0)
                {
                    //获取当前PID的上下限
                    GetPIDLimitVal(PID, Min, Max);

					//取上限的80%作为合理的变化区域
					Max = Max * 0.8;

                    Value.Format("%d", (int)Min);
                    m_Grid.SetItemText(i, 2, Value);//默认值
                    m_Grid.RedrawCell(i, 2);

                    Value.Format("%d", (int)Min);
                    m_Grid.SetItemText(i, 3, Value);//下限
                    m_Grid.RedrawCell(i, 3);

                    Value.Format("%d", (int)Max);
                    m_Grid.SetItemText(i, 4, Value);//下限
                    m_Grid.RedrawCell(i, 4);

                    Value.Format("%d", (int)1.0);
                    m_Grid.SetItemText(i, 5, Value);//步长
                    m_Grid.RedrawCell(i, 5);
                }
                else
                {
                    Value = "无效";
                    m_Grid.SetItemText(i, 2, Value);//默认值
                    m_Grid.RedrawCell(i, 2);

                    m_Grid.SetItemText(i, 3, Value);//下限
                    m_Grid.RedrawCell(i, 3);

                    m_Grid.SetItemText(i, 4, Value);//下限
                    m_Grid.RedrawCell(i, 4);

                    m_Grid.SetItemText(i, 5, Value);//步长
                    m_Grid.RedrawCell(i, 5);
                }
            }
        }
    }
    Text.ReleaseBuffer();

    return 0;
}

//获取给定PID的上下限值
void CAutoSetDataDlg::GetPIDLimitVal(CString PID, FLOAT& Min, FLOAT& Max)
{
    LONG IID = 0;
    LONG Ret = 0;
    BYTE byDecimalPoint = 0;
    AIAOLmtDef_T AIAOLmtDef_t;

    Ret = GetIID(PID.GetBuffer(), IID);
    if (Ret == 0)
    {
        int Result = GetAnalogOrDigital(IID);
        if (Result >= 0)
        {
            if(Result == 1)//模拟量
            {
                Result = GetDecimalPoint(IID, byDecimalPoint);
                Result = GetAIAORange(IID, &AIAOLmtDef_t);
                if (Result >= 0)
                {
                    Min = AIAOLmtDef_t.fProcessRL;
                    Max = AIAOLmtDef_t.fProcessRH;
                }
            }
            else//数字量时
            {
                Min = 0;
                Max = 5;
            }
        }
    }
}

//判断给定IID是模拟量还是数字量，返回1表示数字量，返回0表示模拟量
int CAutoSetDataDlg::GetAnalogOrDigital(long IID)
{
    BYTE	byRet = 0;
    BYTE	byType = 0;
    LONG	Result = 0;

    Result = IsAnalog(IID, byRet, byType);
    if (Result >= 0)
    {
        if(byRet == 1)
        {
            return 1;		/* 模拟量 */
        }
        else
        {
            Result = IsDigital(IID, byRet, byType);
            if (Result >= 0)
            {
                if(byRet == 1)
                {
                    return 0;	/* 数字量 */
                }
                else
                {
                    return -1;	/* 类型不明 */
                }
            }
        }
    }

    return -1;
}

//计算Grid中有效PID的个数
int CAutoSetDataDlg::GetPIDList(OUT vector<long>& IIDList)
{
    IIDList.clear();
    long IID = 0;
    CString PID;
    int Cnt = 0;
    long ret = 0;
    int GridRowMax = m_Grid.GetRowCount() - 1;
    for (int i = 1; i <= GridRowMax; i++)
    {
        PID = m_Grid.GetItemText(i, 1);
        if (PID.IsEmpty() == FALSE)
        {
            ret = GetIID(PID.GetBuffer(), IID);
            if (ret == 0)
            {
                IIDList.push_back(IID);
            }
            else
            {
                IIDList.push_back(0);
            }
        }
    }
    PID.ReleaseBuffer();

    return (int)IIDList.size();
}

//获取界面中每个PID的参数设定，并记录到m_IIDList中
void CAutoSetDataDlg::GetIIDStructList(vector<long>& IIDList, OUT IIDAndValueListType &m_IIDList )
{
    float fLow;
    float fHigh;
    float fDefault;
    float fSetp;
    CString csItemText;
    IIDAndValueType SetData;
    char PID[PIDLEN] = {0};
    int RowCnt = (int)IIDList.size();
    for (int i = 0; i < RowCnt; i++)
    {
        memset(&SetData, '\0', sizeof(IIDAndValueType));

        SetData.liid = IIDList[i];
        GetPID(SetData.liid, PID);
        if (CString(PID) == "A0002")
        {
            int a = 0;
        }

        if (SetData.liid > 0)
        {
            fDefault = 0;
            csItemText = m_Grid.GetItemText(i + 1, 2);
            SetData.fDefault = (float)atof(csItemText);//获取默认值

            fLow = 0;
            csItemText = m_Grid.GetItemText(i + 1, 3);
            SetData.fLow = (float)atof(csItemText);//获取低限

            fHigh = 0;
            csItemText = m_Grid.GetItemText(i + 1, 4);
            SetData.fHigh = (float)atof(csItemText);//获取高限

            fSetp = 0;
            csItemText = m_Grid.GetItemText(i + 1, 5);
            SetData.fSetp = (float)atof(csItemText);//获取步长

            //Time = -1;
            //fValue = 0;
            //lRtn = IsDigital(SetData.liid, byIsDigital, byType);
            //if (1 == byIsDigital)//数字量处理
            //{
            //    lRtn = DGetStsVal(SetData.liid, wStsVal , Time);
            //    if (0 == (wStsVal & D_VALUE_MASK))
            //    {
            //        fValue = 1;
            //    }
            //    else
            //    {
            //        fValue = 0;
            //    }
            //}
            //else//模拟量处理
            //{
            //    int SinCheck = m_Sin.GetCheck();
            //    if(SinCheck == BST_CHECKED)//随机值处理
            //    {
            //        fValue = (float)rand();
            //        if (fValue > fHigh || fValue < fLow)
            //        {
            //            fValue = fValue / 10;
            //        }
            //    }
            //    else//匀速变化处理
            //    {
            //        fCurValue = m_IIDList[i].fValue;
            //        fValue = fSetp + fCurValue;
            //        if (fValue > fHigh || fValue < fLow)
            //        {
            //            fValue = fDefault;
            //        }
            //    }
            //}

            //更新值显示
            //csItemText.Format("%f", fValue);
            //m_Grid.SetItemText(i + 1, 6, csItemText);
            //m_Grid.RedrawCell(i + 1, 6);

            SetData.fValue = SetData.fDefault;
            SetData.bValid = true;

            m_IIDList[i] = SetData;
        }
    }
}

void CAutoSetDataDlg::DataSet( IIDAndValueListType &m_IIDList )
{
    //构建ExDataSet函数需要的参数
    int ListSize = (int)IIDList.size();
    IIDAndValueType element;
    BYTE byIsDigital, byType;
    long lRtn = 0;

	DWORD t1 = GetTickCount();
	//数据打包，构造ExDataSet函数的参数
	ADataIt = ADataSetLst.begin();
	DDataIt = DDataSetLst.begin();
    for (int i = 0; i < ListSize; i++)
    {
        element = m_IIDList[i];
		if (element.liid > 0)
		{
			lRtn = IsDigital(element.liid, byIsDigital, byType);
			if (1 == byIsDigital)//数字量处理
			{
				DDataIt->liid = element.liid;
				DDataIt->byVal = (BYTE)element.fValue;
				DDataIt++;
			}
			else//模拟量处理
			{
				ADataIt->liid = element.liid;
				ADataIt->fVal = element.fValue;
				ADataIt++;
			}
		}
    }
	DWORD t2 = GetTickCount();
	TRACE("循环赋值耗时：%d\n", t2 - t1);

	t1 = GetTickCount();
	MyExDataSet();
	t2 = GetTickCount();
	TRACE("ExDataSet()耗时：%d\n", t2 - t1);
}

//导入本地收集点
void CAutoSetDataDlg::OnBnClickedButton1()
{
    // TODO: 在此添加控件通知处理程序代码
    int nACount = 0;
    int nDCount = 0;

	//清除表格内容
	GridClear();

    BOOL b = GetDataCount(nACount, nDCount);
    if (b)
    {
        LONG* pADataList = NULL;
        LONG* pDDataList = NULL;
        pADataList = new LONG[nACount];
        pDDataList = new LONG[nDCount];
		b = GetLocalDataList(pADataList, pDDataList);
		if (b)
		{
			//控件内容填写
			long ret = 0;
			long IID = 0;
			char szPID[PIDLEN] = "";
			//模拟量处理
			for (int i = 0; i < nACount; i++)
			{
				IID = pADataList[i];
				ret = GetPID(IID, szPID);
				if (ret == 0)
				{
					m_Grid.SetItemText(i + 1, 1, szPID);
				}
				else
				{
					CString Value = "无效";
					m_Grid.SetItemText(i + 1, 2, Value);
					m_Grid.SetItemText(i + 1, 3, Value);
					m_Grid.SetItemText(i + 1, 4, Value);
					m_Grid.SetItemText(i + 1, 5, Value);
				}
			}

			//数字量处理
			for (int i = 0; i < nDCount; i++)
			{
				IID = pDDataList[i];
				ret = GetPID(IID, szPID);
				if (ret == 0)
				{
					m_Grid.SetItemText(i + nACount + 1, 1, szPID);
				}
				else
				{
					CString Value = "无效";
					m_Grid.SetItemText(i + nACount + 1, 2, Value);
					m_Grid.SetItemText(i + nACount + 1, 3, Value);
					m_Grid.SetItemText(i + nACount + 1, 4, Value);
					m_Grid.SetItemText(i + nACount + 1, 5, Value);
				}
			}

			m_Grid.Refresh();

			//自动填写相关内容
			OnAutoPIDInfo(NULL, NULL);
		}

		delete[] pDDataList;
		delete[] pADataList;
    }
}

//导入所有AI点
void CAutoSetDataDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	int Cnt = TagList[AITAG - 1].size();
	if (Cnt > 0)
	{
		//控件内容填写
		long ret = 0;
		long IID = 0;
		char szPID[PIDLEN] = "";
		list<long>::iterator TagListIter;
		int RowTotal = GetGridValidCnt();
		int idx = RowTotal;
		for (TagListIter = TagList[AITAG - 1].begin(); TagListIter != TagList[AITAG - 1].end(); TagListIter++)
		{
			IID = *TagListIter;
			if (IID > 0)
			{
				ret = GetPID(IID, szPID);
				if (ret == 0)
				{
					m_Grid.SetItemText(idx + 1, 1, szPID);
				}
				else
				{
					CString Value = "无效";
					m_Grid.SetItemText(idx + 1, 2, Value);
					m_Grid.SetItemText(idx + 1, 3, Value);
					m_Grid.SetItemText(idx + 1, 4, Value);
					m_Grid.SetItemText(idx + 1, 5, Value);
				}
				idx++;
			}
		}

		m_Grid.Refresh();

		//自动填写相关内容
		OnAutoPIDInfo(NULL, NULL);
	}
}

//获取在线表中的IID数据
void CAutoSetDataDlg::GetTagList(int DataType)
{
	long lListSize = 0;

	TagList[DataType - 1].clear();

	switch (DataType)
	{
	case AITAG:
		GetAIList_GetListSize(lListSize);
		TagList[DataType - 1].resize(lListSize);
		if (lListSize > 0)
		{
			GetAIList(TagList[DataType - 1], PIDCnt[0]);
		}
		break;
	case DITAG:
		GetDIList_GetListSize(lListSize);
		TagList[DataType - 1].resize(lListSize);
		if (lListSize > 0)
		{
			GetDIList(TagList[DataType - 1], PIDCnt[1]);
		}
		break;
	case AOTAG:
		GetAOList_GetListSize(lListSize);
		TagList[DataType - 1].resize(lListSize);
		if (lListSize > 0)
		{
			GetAOList(TagList[DataType - 1], PIDCnt[2]);
		}
		break;
	case DOTAG:
		GetDOList_GetListSize(lListSize);
		TagList[DataType - 1].resize(lListSize);
		if (lListSize > 0)
		{
			GetDOList(TagList[DataType - 1], PIDCnt[3]);
		}
		break;
	case CATAG:
		GetCAList_GetListSize(lListSize);
		TagList[DataType - 1].resize(lListSize);
		if (lListSize > 0)
		{
			GetCAList(TagList[DataType - 1], PIDCnt[4]);
		}
		break;
	case CDTAG:
		GetCDList_GetListSize(lListSize);
		TagList[DataType - 1].resize(lListSize);
		if (lListSize > 0)
		{
			GetCDList(TagList[DataType - 1], PIDCnt[5]);
		}
		break;
	}
}

void CAutoSetDataDlg::GetSetValues()
{
	long lRtn;
	time_t Time = 0;
	IIDAndValueType Data;
	BYTE byIsDigital, byType;
	float fCurValue;

	int RowCnt = (int)IIDList.size();
	for (int i = 0; i < RowCnt; i++)
	{
		//计算当前值
		Time = -1;
		Data = m_IIDList[i];
		lRtn = IsDigital(Data.liid, byIsDigital, byType);
		if (1 == byIsDigital)//数字量处理
		{
			//数字量就重复0/1切换
			fCurValue = m_IIDList[i].fValue;
			if (fCurValue == 1.0)
			{
				m_IIDList[i].fValue = 0.0;
			}
			else
			{
				m_IIDList[i].fValue = 1.0;
			}
		}
		else//模拟量处理
		{
			int SinCheck = m_Sin.GetCheck();
			if(SinCheck == BST_CHECKED)//正弦处理
			{
				//获取当前的实时表时间
				time_t lCurTime = 0;
				CVGetCurTime(lCurTime);

				float Y = GetSin(lCurTime);
				//TRACE("GetSin()=%f\n", Y);

				//变换到工程量程范围内
				float Val = GetUserRangeValue(Y, Data);
				TRACE("GetUserRangeValue()=%f\n", Val);

				m_IIDList[i].fValue = Val;
				if (m_IIDList[i].fValue > m_IIDList[i].fHigh || m_IIDList[i].fValue < m_IIDList[i].fLow)
				{
					m_IIDList[i].fValue = m_IIDList[i].fDefault;
				}
			}
			else//匀速变化处理
			{
				fCurValue = m_IIDList[i].fValue;
				m_IIDList[i].fValue = m_IIDList[i].fSetp + fCurValue;
				if (m_IIDList[i].fValue > m_IIDList[i].fHigh || m_IIDList[i].fValue < m_IIDList[i].fLow)
				{
					m_IIDList[i].fValue = m_IIDList[i].fDefault;
				}
			}
		}
	}
}

//正弦曲线
double CAutoSetDataDlg::GetSin( double x )
{
	double y = 0;
	double pi = 3.1415926535;
	x = (x * 0.1) / (2 * pi);
	y = sin(x);

	return y;
}

void CAutoSetDataDlg::RefreshVisibleRow()
{
	CCellRange Range;
	int RowTotal = (int)IIDList.size();
	Range = m_Grid.GetVisibleNonFixedCellRange();
	for (int i = Range.GetMinRow(); i <= Range.GetMaxRow(); i++)
	{
		if (i <= RowTotal)
		{
			CString csItemText;
			csItemText.Format("%f", m_IIDList[i - 1].fValue);
			m_Grid.SetItemText(i, 6, csItemText);
			m_Grid.RedrawCell(i, 6);
		}
	}
}

void CAutoSetDataDlg::GridClear()
{
	CCellRange Range;
	int ColCnt = m_Grid.GetColumnCount();
	Range.Set(1, 1, MaxRowNums - 1, ColCnt - 1);
	m_Grid.ClearCells(Range);
}

//导入1万点数字量，DI/DO各5000
void CAutoSetDataDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	int nACount = 0;
	int nDCount = 0;
	int Limit = 100;

	//统计现有的点数
	int RowTotal = GetGridValidCnt();

	//获取DI/DO的IID列表
	GetTagList(DITAG);

	int Cnt = TagList[DITAG - 1].size();
	if (Cnt > 0)
	{
		//控件内容填写
		long ret = 0;
		long IID = 0;
		char szPID[PIDLEN] = "";
		list<long>::iterator TagListIter;
		int i = RowTotal + 1;//行索引
		for (TagListIter = TagList[DITAG - 1].begin(); TagListIter != TagList[DITAG - 1].end(); TagListIter++)
		{
			IID = *TagListIter;
			if (IID > 0)
			{
				ret = GetPID(IID, szPID);
				if (ret == 0)
				{
					m_Grid.SetItemText(i, 1, szPID);
				}
				else
				{
					CString Value = "无效";
					m_Grid.SetItemText(i, 2, Value);
					m_Grid.SetItemText(i, 3, Value);
					m_Grid.SetItemText(i, 4, Value);
					m_Grid.SetItemText(i, 5, Value);
				}

				i++;
				if (i > RowTotal + Limit)
				{
					break;
				}
			}
		}

		m_Grid.Refresh();

		//自动填写相关内容
		OnAutoPIDInfo(NULL, NULL);
	}
}

void CAutoSetDataDlg::MyExDataSet()
{
	long lRtn = 0;
	lRtn = ExDataSet(ADataSetLst, DDataSetLst, 0);
}

float CAutoSetDataDlg::GetUserRangeValue( float Y, IIDAndValueType& Data )
{
	//[-1, +1]对应[Data.fLow, Data.fHigh]
	float Ret = 0.0;

	Ret = (Y + 1) / 2 * (Data.fHigh - Data.fLow) + Data.fLow;

	return Ret;
}

//导入所有的AO点
void CAutoSetDataDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	int nACount = 0;

	//GridClear();

	GetTagList(AOTAG);

	int Cnt = TagList[AOTAG - 1].size();
	if (Cnt > 0)
	{
		//控件内容填写
		long ret = 0;
		long IID = 0;
		char szPID[PIDLEN] = "";
		list<long>::iterator TagListIter;
		int RowTotal = GetGridValidCnt();
		int idx = RowTotal;
		for (TagListIter = TagList[AOTAG - 1].begin(); TagListIter != TagList[AOTAG - 1].end(); TagListIter++)
		{
			IID = *TagListIter;
			if (IID > 0)
			{
				ret = GetPID(IID, szPID);
				if (ret == 0)
				{
					m_Grid.SetItemText(idx + 1, 1, szPID);
				}
				else
				{
					CString Value = "无效";
					m_Grid.SetItemText(idx + 1, 2, Value);
					m_Grid.SetItemText(idx + 1, 3, Value);
					m_Grid.SetItemText(idx + 1, 4, Value);
					m_Grid.SetItemText(idx + 1, 5, Value);
				}
				idx++;
			}
		}

		m_Grid.Refresh();

		//自动填写相关内容
		OnAutoPIDInfo(NULL, NULL);
	}
}

int CAutoSetDataDlg::GetGridValidCnt()
{
	CString ItemText;
	int RowTotal = 0;
	for (int i = 1; i < MaxRowNums; i++)
	{
		ItemText = m_Grid.GetItemText(i, 1);
		if (ItemText.IsEmpty() == FALSE)
		{
			RowTotal++;
		}
	}

	return RowTotal;
}

void CAutoSetDataDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	GridClear();
}

void CAutoSetDataDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	int nACount = 0;
	int nDCount = 0;
	int Limit = 100;

	//统计现有的点数
	int RowTotal = GetGridValidCnt();

	//获取DI/DO的IID列表
	GetTagList(DOTAG);

	int Cnt = TagList[DOTAG - 1].size();
	if (Cnt > 0)
	{
		//控件内容填写
		long ret = 0;
		long IID = 0;
		char szPID[PIDLEN] = "";
		list<long>::iterator TagListIter;
		int i = RowTotal + 1;//行索引

		for (TagListIter = TagList[DOTAG - 1].begin(); TagListIter != TagList[DOTAG - 1].end(); TagListIter++)
		{
			IID = *TagListIter;
			if (IID > 0)
			{
				ret = GetPID(IID, szPID);
				if (ret == 0)
				{
					m_Grid.SetItemText(i, 1, szPID);
				}
				else
				{
					CString Value = "无效";
					m_Grid.SetItemText(i, 2, Value);
					m_Grid.SetItemText(i, 3, Value);
					m_Grid.SetItemText(i, 4, Value);
					m_Grid.SetItemText(i, 5, Value);
				}

				i++;
				if (i > RowTotal + Limit)
				{
					break;
				}	
			}
		}

		m_Grid.Refresh();

		//自动填写相关内容
		OnAutoPIDInfo(NULL, NULL);
	}
}

CString CAutoSetDataDlg::GetTypeString(int i)
{
	CString String;

	switch (i)
	{
	case AITAG:
		String = "AI";
		break;
	case DITAG:
		String = "DI";
		break;
	case AOTAG:
		String = "AO";
		break;
	case DOTAG:
		String = "DO";
		break;
	default:
		break;
	}

	return String;
}

void CAutoSetDataDlg::OnBnClickedButtonAi()
{
	// TODO: 在此添加控件通知处理程序代码
	int Cnt = GetDlgItemInt(IDC_EDIT_AI);
	if (Cnt > PIDCnt[0])
	{
		Cnt = PIDCnt[0];
	}

	if (Cnt > 0)
	{
		//控件内容填写
		AddPID(Cnt, AITAG);

		//自动填写相关内容
		OnAutoPIDInfo(NULL, NULL);
	}
}

void CAutoSetDataDlg::AddPID(int Cnt, int Type)
{
	long ret = 0;
	long IID = 0;
	char szPID[PIDLEN] = "";
	list<long>::iterator TagListIter;
	int RowTotal = GetGridValidCnt();
	int idx = RowTotal;
	int TypeIdx = Type - 1;
	int Count = 0;
	for (TagListIter = TagList[TypeIdx].begin(); TagListIter != TagList[TypeIdx].end(); TagListIter++)
	{
		IID = *TagListIter;
		if (IID > 0)
		{
			ret = GetPID(IID, szPID);
			if (ret == 0)
			{
				m_Grid.SetItemText(idx + 1, 1, szPID);
			}
			else
			{
				CString Value = "无效";
				m_Grid.SetItemText(idx + 1, 2, Value);
				m_Grid.SetItemText(idx + 1, 3, Value);
				m_Grid.SetItemText(idx + 1, 4, Value);
				m_Grid.SetItemText(idx + 1, 5, Value);
			}
			idx++;
		}

		Count++;
		if (Count == Cnt)
		{
			break;
		}
	}

	m_Grid.Refresh();
}

void CAutoSetDataDlg::OnBnClickedButtonDi()
{
	// TODO: 在此添加控件通知处理程序代码
	int Cnt = GetDlgItemInt(IDC_EDIT_DI);
	if (Cnt > 100)
	{
		Cnt = 100;
	}

	if (Cnt > 0)
	{
		//控件内容填写
		AddPID(Cnt, DITAG);

		//自动填写相关内容
		OnAutoPIDInfo(NULL, NULL);
	}
}

void CAutoSetDataDlg::OnBnClickedButtonAo()
{
	// TODO: 在此添加控件通知处理程序代码
	int Cnt = GetDlgItemInt(IDC_EDIT_AO);
	if (Cnt > PIDCnt[2])
	{
		Cnt = PIDCnt[2];
	}

	if (Cnt > 0)
	{
		//控件内容填写
		AddPID(Cnt, AOTAG);

		//自动填写相关内容
		OnAutoPIDInfo(NULL, NULL);
	}
}

void CAutoSetDataDlg::OnBnClickedButtonDo()
{
	// TODO: 在此添加控件通知处理程序代码
	int Cnt = GetDlgItemInt(IDC_EDIT_DO);
	if (Cnt > 100)
	{
		Cnt = 100;
	}

	if (Cnt > 0)
	{
		//控件内容填写
		AddPID(Cnt, DOTAG);

		//自动填写相关内容
		OnAutoPIDInfo(NULL, NULL);
	}
}
