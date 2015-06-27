// CVMimicDLLTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CVMimicDLLTest.h"
#include "CVMimicDLLTestDlg.h"
#include "CVMimicDefineCommondll.h"
#include "c:\CoreView_src\include\CVCommonDllCommon.h"	//for 2005
#include "c:\coreview_src\funcsrc\cvcrtopsrc\include\cvcrtmain_im.h"
#include "c:\coreview_src\funcsrc\cvcrtopsrc\include\gropdll_cv.h"
#include "c:\CoreView_src\include\CVtask.h"
#include "c:\coreview_src\funcsrc\cvmimicsrc\include\cvdispalycommdef.h"
#include "c:\coreview_src\funcsrc\cvcrtopsrc\include\cvcrtbuilderdll.h"
#include "afxole.h"
//#include "c:\CoreView_src\FuncSrc\CVMimicSrc\include\CVGrabCommondll.h"
#include "c:\coreview_src\include\cvfilemanagercomm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern "C" __declspec ( dllimport ) BOOL WINAPI GetCRTDOCountbyNetNo(BYTE NetNo,DWORD &DOCount);
extern "C" __declspec ( dllimport ) BOOL WINAPI GetCRTDOListbyNetNo(BYTE NetNo, long *CRTDOlist,DWORD &RealDOCount);// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

typedef struct GT_GRDATA_HEADER
{
	LONG		ofsBrushTable	;
	WORD		cntBrush		;

	LONG		ofsPenTable		;
	WORD		cntPen			;

	LONG		ofsFontTable	;
	WORD		cntFont			;

	LONG		ofsStaticObj	;
	WORD		cntStaticObj	;

	LONG		ofsDynMgt		;
	WORD		cntDynMgt		;

	LONG		ofsDynSpec		;
	WORD		cntDynSpec		;

	LONG		ofsEqns			;
	WORD		cntEqns			;

	LONG		ofsActiveList	;
	WORD		cntActiveList	;

	LONG		ofsPenStyle		;     /////// offset to pen style
	WORD        cntElements		;     /////// count of the array

	WORD		wWindowWidth	;
	WORD		wWindowHeight	;
	BYTE		ixBgClr			;

} GT_GRDATA_HEADER ;

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

// CCVMimicDLLTestDlg 对话框

CCVMimicDLLTestDlg::CCVMimicDLLTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCVMimicDLLTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCVMimicDLLTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_GroupList);
	DDX_Control(pDX, IDC_EDIT1, m_InputText);
	DDX_Control(pDX, IDC_EDIT2, m_MimicName);
}

BEGIN_MESSAGE_MAP(CCVMimicDLLTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_MIMICGRPDEF, &CCVMimicDLLTestDlg::OnBnClickedMimicgrpdef)
	//ON_BN_CLICKED(IDC_GETMIMICLIST, &CCVMimicDLLTestDlg::OnBnClickedGetmimiclist)
	ON_BN_CLICKED(IDC_BUTTON2, &CCVMimicDLLTestDlg::OnBnClickedGetGroupList)
	ON_BN_CLICKED(IDC_BUTTON28, &CCVMimicDLLTestDlg::OnBnClickedGetUnGroupedMimicList)
	ON_BN_CLICKED(IDC_BUTTON4, &CCVMimicDLLTestDlg::OnBnClickedGetGroupInfo)
	ON_BN_CLICKED(IDC_BUTTON5, &CCVMimicDLLTestDlg::OnBnClickedSelectGroupDialog)
	ON_BN_CLICKED(IDC_BUTTON6, &CCVMimicDLLTestDlg::OnBnClickedSetNewGroup)
	ON_BN_CLICKED(IDC_BUTTON7, &CCVMimicDLLTestDlg::OnBnClickedSetNewMimicToGroup)
	ON_BN_CLICKED(IDC_BUTTON8, &CCVMimicDLLTestDlg::OnBnClickedSelectMimicDialog)
	ON_BN_CLICKED(IDC_BUTTON9, &CCVMimicDLLTestDlg::OnBnClickedGetTrendDefineInfo)
	ON_BN_CLICKED(IDC_BUTTON10, &CCVMimicDLLTestDlg::OnBnClickedButton10)
	ON_LBN_DBLCLK(IDC_LIST3, &CCVMimicDLLTestDlg::OnLbnDblclkList2)
	ON_BN_CLICKED(IDC_BUTTON11, &CCVMimicDLLTestDlg::OnBnClickedGetGroupListMem)
	ON_BN_CLICKED(IDC_BUTTON12, &CCVMimicDLLTestDlg::OnBnClickedGetUnGroupedMimicListMem)
	ON_BN_CLICKED(IDC_BUTTON14, &CCVMimicDLLTestDlg::OnBnClickedGetUnGroupedMimicListMemNoName)
	ON_BN_CLICKED(IDC_BUTTON15, &CCVMimicDLLTestDlg::OnBnClickedGetMimicInfoListMem)
	ON_BN_CLICKED(IDC_BUTTON16, &CCVMimicDLLTestDlg::OnBnClickedGetMimicListMem)
	ON_BN_CLICKED(IDC_BUTTON17, &CCVMimicDLLTestDlg::OnBnClickedGetGroupInfoMem)
	ON_BN_CLICKED(IDC_BUTTON18, &CCVMimicDLLTestDlg::OnBnClickedGetMimicGroupMem)
	ON_BN_CLICKED(IDC_BUTTON19, &CCVMimicDLLTestDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CCVMimicDLLTestDlg::GetParentNamebyGroupName)
	ON_BN_CLICKED(IDC_BUTTON21, &CCVMimicDLLTestDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON22, &CCVMimicDLLTestDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON23, &CCVMimicDLLTestDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON24, &CCVMimicDLLTestDlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_GETRF, &CCVMimicDLLTestDlg::OnBnClickedGetrf)
	ON_BN_CLICKED(IDC_BUTTON26, &CCVMimicDLLTestDlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON27, &CCVMimicDLLTestDlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON30, &CCVMimicDLLTestDlg::OnBnClickedButton30)
	ON_BN_CLICKED(IDC_BUTTON31, &CCVMimicDLLTestDlg::OnBnClickedButton31)
	ON_BN_CLICKED(IDC_BUTTON29, &CCVMimicDLLTestDlg::OnBnClickedButton29)
	ON_BN_CLICKED(IDC_BUTTON32, &CCVMimicDLLTestDlg::OnBnClickedButton32)
	ON_BN_CLICKED(IDC_BUTTON33, &CCVMimicDLLTestDlg::OnBnClickedButton33)
	ON_BN_CLICKED(IDC_BUTTON34, &CCVMimicDLLTestDlg::OnBnClickedButton34)
END_MESSAGE_MAP()


// CCVMimicDLLTestDlg 消息处理程序

BOOL CCVMimicDLLTestDlg::OnInitDialog()
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

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCVMimicDLLTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCVMimicDLLTestDlg::OnPaint()
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
HCURSOR CCVMimicDLLTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCVMimicDLLTestDlg::OnBnClickedMimicgrpdef()
{
	MimicGroupDefine();
}


void CCVMimicDLLTestDlg::OnBnClickedGetmimiclist()
{
	CList<MimicInfo,MimicInfo&> MimicInfolists;

	GetMimicInfoList(MimicInfolists);
}

void CCVMimicDLLTestDlg::OnBnClickedGetGroupList()
{
	char debugstr[255];
	POSITION pSition;
	GroupInfo  grpinf;

	CList<GroupInfo,GroupInfo&> GroupInfoList;
	
	GetGroupList(GroupInfoList);
	m_GroupList.ResetContent();

	for(int i=0;i<GroupInfoList.GetCount();i++)
	{
		pSition = GroupInfoList.FindIndex(i);
		grpinf = GroupInfoList.GetAt(pSition);
		sprintf(debugstr,"GRPNO=%d",grpinf.GroupID);
		m_GroupList.AddString(debugstr);
		sprintf(debugstr,"--pGRPNO=%d",grpinf.pGroupID);
		m_GroupList.AddString(debugstr);
		sprintf(debugstr,"--GRPNAME=%s",grpinf.GroupName);
		m_GroupList.AddString(debugstr);
	}
}

void CCVMimicDLLTestDlg::OnBnClickedGetUnGroupedMimicList()
{
	char debugstr[255];
	POSITION pSition;
	MimicInfo  mimicinf;
	CList<MimicInfo,MimicInfo&> UnGroupMimicList;

	m_GroupList.ResetContent();
	GetUnGroupedMimicList(UnGroupMimicList);
	for(int i=0;i<UnGroupMimicList.GetCount();i++)
	{
		pSition = UnGroupMimicList.FindIndex(i);
		mimicinf = UnGroupMimicList.GetAt(pSition);
		sprintf(debugstr,"GrbIID=%s",mimicinf.grbiid);
		m_GroupList.AddString(debugstr);
		sprintf(debugstr,"--GRbNAME=%s",mimicinf.grbname);
		m_GroupList.AddString(debugstr);
		//OutputDebugString(debugstr);
	}
}

void CCVMimicDLLTestDlg::OnBnClickedGetGroupInfo()
{
	BYTE GroupID;
	BYTE pGroupID;
	char GroupName[40];
	BYTE subGrpCount=0;
	CList<GroupInfo> SubGroupInfoList;
	GroupInfo grpinf;
	WORD MimicCount=0;
	CList<MimicInfo> cMimicInfo;
	MimicInfo mimicinf;
	char debugstr[255];
	POSITION pSition;

	CString   csInputText;

	m_InputText.GetWindowText(csInputText);
	GroupID = atoi((char*)(const char*)csInputText);
	//GroupID = 1;
	m_GroupList.ResetContent();
	GetGroupInfo(GroupID,pGroupID,GroupName,subGrpCount,SubGroupInfoList,MimicCount,cMimicInfo);
	sprintf(debugstr,"GRPNO=%d;pGRPNO=%d;GRPNAME=%s",GroupID,pGroupID,GroupName);
	m_GroupList.AddString(debugstr);
	sprintf(debugstr,"SUBGRPNumber=%d",subGrpCount);
	OutputDebugString(debugstr);
	for(int i=0; i<subGrpCount;i++)
	{
		pSition = SubGroupInfoList.FindIndex(i);
		grpinf = SubGroupInfoList.GetAt(pSition);
		sprintf(debugstr,"SUBGRPNO=%d;pSUBGRPNO=%d;SUBGRPNAME=%s",grpinf.GroupID,grpinf.pGroupID,grpinf.GroupName);
		m_GroupList.AddString(debugstr);
	}
	sprintf(debugstr,"Mimicnumber=%d",MimicCount);
	m_GroupList.AddString(debugstr);
	for(int i=0; i<MimicCount;i++)
	{
		pSition = cMimicInfo.FindIndex(i);
		mimicinf = cMimicInfo.GetAt(pSition);
		sprintf(debugstr,"Mimicgrb=%s;mimicNAME=%s",mimicinf.grbiid,mimicinf.grbname);
		m_GroupList.AddString(debugstr);
	}
}
void CCVMimicDLLTestDlg::OnBnClickedSelectGroupDialog()
{
	char grpname[40];

	SelectGroupDialog(grpname,0);
}

void CCVMimicDLLTestDlg::OnBnClickedSetNewGroup()
{
	CString   csInputText;

	m_InputText.GetWindowText(csInputText);
	SetNewGroup((char*)(const char*)csInputText);
}

void CCVMimicDLLTestDlg::OnBnClickedSetNewMimicToGroup()
{
	CString   csInputText,csMimicName;

	m_InputText.GetWindowText(csInputText);
	m_MimicName.GetWindowText(csMimicName);
	//SetNewMimicToGroup((char*)(const char*)csMimicName,(char*)(const char*)csInputText);
}

void CCVMimicDLLTestDlg::OnBnClickedSelectMimicDialog()
{
	CString grbno,graname,grpname;

	MimicInfoincludegrp csmimicinfogrps[20];
	short rtn = SelectMimicDialog(csmimicinfogrps);
}

void CCVMimicDLLTestDlg::OnBnClickedGetTrendDefineInfo()
{
	int count = GetTrendColPidCount();
	long *iidlist= new long[count];
	GetTrendColPidList(iidlist);
	m_GroupList.ResetContent();
	char pidasc[PIDLEN];
	for(int i=0;i<count;i++)
	{
		GetPID(iidlist[i],pidasc);
		m_GroupList.AddString(pidasc);
	}
	delete []iidlist;
}

void CCVMimicDLLTestDlg::OnBnClickedButton10()
{
	int		instcount;
	DRVINFOS	*TagName;

	instcount = GetInstCount();
	TagName = new DRVINFOS[instcount];

	GetInstList(TagName);
	m_GroupList.ResetContent();
	for(int i=0; i<instcount; i++)
	{
		m_GroupList.AddString(TagName[i].drviid);
	}
	delete []TagName;

	//long drvid[2];

	//drvid[1] = 0;
	//GetInstDrvIDbyTagName("MD0988",drvid[0]);
	//CRTMimicRectClick("GR400135",111,TagName[i].drviid);
	////ChangeGropPos(m_SaveGropPos);

	//ShowGROPWindow();


}

void CCVMimicDLLTestDlg::OnLbnDblclkList2()
{
	CString GrNo;

	int Index = m_GroupList.GetCurSel();
	if(Index < 0)
		GrNo = "";
	else		
		m_GroupList.GetText(Index, GrNo);

	if (GrNo.IsEmpty() == FALSE)
	{
		SwitchMimic_Im(GrNo);
	}

}

void CCVMimicDLLTestDlg::OnBnClickedGetGroupListMem()
{
	GroupInfo *GroupInfoList;
	char debugstr[255];
	CString   csInputText;
	BYTE aaa;
	short GroupCount;

	m_InputText.GetWindowText(csInputText);
	aaa = atoi((char*)(const char*)csInputText);
	if(aaa == 1)
		GroupCount = GetGroupListCountTotal();
	else
		GroupCount = GetGroupListCount();
	m_GroupList.ResetContent();
	if(GroupCount >0)
	{
		GroupInfoList = new GroupInfo[GroupCount];
		if(aaa == 1)
			GetGroupListMemTotal(GroupInfoList);
		else
			GetGroupListMem(GroupInfoList);
		for(int i=0;i<GroupCount;i++)
		{
			sprintf(debugstr,"GRPNO=%d",GroupInfoList[i].GroupID);
			m_GroupList.AddString(debugstr);
			sprintf(debugstr,"--pGRPNO=%d",GroupInfoList[i].pGroupID);
			m_GroupList.AddString(debugstr);
			sprintf(debugstr,"--GRPNAME=%s",GroupInfoList[i].GroupName);
			m_GroupList.AddString(debugstr);
		}
		delete []GroupInfoList;
	}
}

void CCVMimicDLLTestDlg::OnBnClickedGetUnGroupedMimicListMem()
{
	MimicInfo *UnGroupMimicList;
	char debugstr[255];
	short UnGroupedMimicCount = GetUnGroupedMimicListCount();
	m_GroupList.ResetContent();
	if(UnGroupedMimicCount >0)
	{
		UnGroupMimicList = new MimicInfo[UnGroupedMimicCount];
		GetUnGroupedMimicListMem(UnGroupMimicList);
		for(int i=0;i<UnGroupedMimicCount;i++)
		{
			sprintf(debugstr,"GrbIID=%s",UnGroupMimicList[i].grbiid);
			m_GroupList.AddString(debugstr);
			sprintf(debugstr,"--GRbNAME=%s",UnGroupMimicList[i].grbname);
			m_GroupList.AddString(debugstr);
		}
		delete []UnGroupMimicList;
	}
}

void CCVMimicDLLTestDlg::OnBnClickedGetUnGroupedMimicListMemNoName()
{
	char *UnGroupMimicList;
	char debugstr[255];
	short UnGroupedMimicCount = GetUnGroupedMimicListWithoutNameCount();
	m_GroupList.ResetContent();
	if(UnGroupedMimicCount >0)
	{
		UnGroupMimicList = new char[UnGroupedMimicCount*9];
		GetUnGroupedMimicListWithoutNameMem(UnGroupMimicList);
		for(int i=0;i<UnGroupedMimicCount;i++)
		{
			memcpy(debugstr,UnGroupMimicList+i*9,9);
			m_GroupList.AddString(debugstr);
		}
		delete []UnGroupMimicList;
	}
}

void CCVMimicDLLTestDlg::OnBnClickedGetMimicInfoListMem()
{
	MimicInfo *MimicInfolists;
	short MimicCount = GetMimicInfoListCount();
	char debugstr[255];

	if(MimicCount <= 0)
		return;
	MimicInfolists = new MimicInfo[MimicCount];
	GetMimicInfoListMem(MimicInfolists);
	m_GroupList.ResetContent();
	for(short i=0; i<MimicCount; i++)
	{
		sprintf(debugstr,"GrbIID=%s",MimicInfolists[i].grbiid);
		m_GroupList.AddString(debugstr);
		sprintf(debugstr,"--GRbNAME=%s",MimicInfolists[i].grbname);
		m_GroupList.AddString(debugstr);
	}
	delete []MimicInfolists;
}

void CCVMimicDLLTestDlg::OnBnClickedGetMimicListMem()
{
	char *MimicList;
	int MimicCount = GetMimicListCount();
	char debugstr[255];
	if(MimicCount > 0)
	{
		m_GroupList.ResetContent();
		MimicList = new char[MimicCount * 9];
		GetMimicListMem(MimicList);
		for(int i=0;i<MimicCount;i++)
		{
			memcpy(debugstr,MimicList+i*9,9);
			m_GroupList.AddString(debugstr);
		}
		delete []MimicList;

	}
}

void CCVMimicDLLTestDlg::OnBnClickedGetGroupInfoMem()
{
	BYTE GroupID,SubGrpCount=0,pGroupID;
	WORD MimicCount=0;
	CString csInputText;
	GroupInfo *SubGroupInfoList;
	MimicInfo *cMimicInfo;
	char GroupName[40];
	char debugstr[255];

	m_GroupList.ResetContent();
	m_InputText.GetWindowText(csInputText);
	GroupID = atoi((char*)(const char*)csInputText);
	if(GroupID == 0)
		GetQuickAccessGroupInfoCount(MimicCount);
	else
	{
		GetGroupInfoCount(GroupID,SubGrpCount,MimicCount);
		SubGroupInfoList = new GroupInfo[SubGrpCount];
	}
	if(MimicCount == 0)
		return;

	cMimicInfo = new MimicInfo[MimicCount];
	if(GroupID == 0)
		GetQuickAccessGroupInfoMem(MimicCount,cMimicInfo);
	else
		GetGroupInfoMem(GroupID,pGroupID,GroupName,SubGrpCount,SubGroupInfoList,MimicCount,cMimicInfo);
	sprintf(debugstr,"GRPNO=%d;pGRPNO=%d;GRPNAME=%s",GroupID,pGroupID,GroupName);
	m_GroupList.AddString(debugstr);
	sprintf(debugstr,"SUBGRPNumber=%d",SubGrpCount);
	OutputDebugString(debugstr);
	for(int i=0; i<SubGrpCount;i++)
	{
		sprintf(debugstr,"SUBGRPNO=%d;pSUBGRPNO=%d;SUBGRPNAME=%s",SubGroupInfoList[i].GroupID,SubGroupInfoList[i].pGroupID,SubGroupInfoList[i].GroupName);
		m_GroupList.AddString(debugstr);
	}
	sprintf(debugstr,"Mimicnumber=%d",MimicCount);
	m_GroupList.AddString(debugstr);
	for(int i=0; i<MimicCount;i++)
	{
		sprintf(debugstr,"Mimicgrb=%s;mimicNAME=%s",cMimicInfo[i].grbiid,cMimicInfo[i].grbname);
		m_GroupList.AddString(debugstr);
	}
	if(GroupID != 0)
		delete []SubGroupInfoList;
	delete []cMimicInfo;
}

void CCVMimicDLLTestDlg::OnBnClickedGetMimicGroupMem()
{
	CString csMimicName;
	BYTE	MimicGroupCount;
	char	*GrpName;
	char debugstr[255];

	m_MimicName.GetWindowText(csMimicName);
	MimicGroupCount = GetMimicGroupCount((char*)(const char*)csMimicName);
	if(MimicGroupCount > 0)
	{
		GrpName = new char[MimicGroupCount * 41];
		GetMimicGroupMem((char*)(const char*)csMimicName, GrpName);
		m_GroupList.ResetContent();
		for(int i=0; i<MimicGroupCount; i++)
		{
			memcpy(debugstr,GrpName+i*41,41);
			m_GroupList.AddString(debugstr);
		}
		delete []GrpName;
	}
}

void CCVMimicDLLTestDlg::OnBnClickedButton19()
{
	CString TagSelName;
	char	drvName[7];
	long	drvid;

	int TagSelNo = m_GroupList.GetCurSel();
	if(TagSelNo < 0)
		TagSelName = "";
	else		
		m_GroupList.GetText(TagSelNo,TagSelName);
	memset(drvName,'\0',7);
	memcpy(drvName,TagSelName,6);

	GetInstDrvIDbyTagName((char*)(const char*)drvName,drvid);
	HWND  InsthWnd = GetHwndByTaskName("CVInstInfo");//FindWindow("操作端详细信息显示","操作端详细信息显示");
	{
		::PostMessage(InsthWnd,WM_USER + 6004,0,drvid);
	}

}

void CCVMimicDLLTestDlg::GetParentNamebyGroupName()
{
	CString csMimicName;
	char	GrpName[41];

	m_InputText.GetWindowText(csMimicName);

	memset(GrpName,'\0',41);
	GetMimicGroupbyGroupName((char*)(const char*)csMimicName,GrpName);

	m_MimicName.SetWindowText(GrpName);
}

void CCVMimicDLLTestDlg::OnBnClickedButton21()
{
	//STARTUPINFO strtup={0} ;
	//PROCESS_INFORMATION Info ;

	//BOOL blRtn = CreateProcess(NULL,"C:\\CoreView\\FuncExec\\exe\\FuncForSetup-Mimic_Im.exe 1",0,0,0,0,0,0,&strtup,&Info);
	//CloseHandle(Info.hProcess);
	//CloseHandle(Info.hThread);
	//CFile csFile;
	//CFileException e;

	//csFile.Open("C:\\Drawings\\GR000001.GRB",CFile::modeRead,&e);
	//BYTE *buffer;
	//DWORD dwRead;
	//long  reallen = csFile.GetLength();
	//buffer = new BYTE[reallen];
	//dwRead = csFile.Read(buffer, reallen);
	//csFile.Close();
	//delete []buffer;
	ShellExecuteA(NULL,"open",CVCRTBUILDERLOADFUNC,"16",CVCRTBUILDERLOADFUNCPATH,SW_SHOW);
}

void CCVMimicDLLTestDlg::OnBnClickedButton22()
{
	CRTInst *m_CRTinstList;
	char	csstring[255];
	POINT	csPoint;
	char	bitmapname[255];

	int count = GetMimicCRTInstCount("GR104001");
	m_CRTinstList = new CRTInst[count];
	csPoint.x = 1680;
	csPoint.y = 918;
	GetMimicCRTInstList("GR104001",bitmapname,csPoint,m_CRTinstList);
	for(int i=0 ;i<count; i++)
	{
		sprintf(csstring,"Rect.top = %d,left = %d,rightx = %d,bottom = %d\n,Drv1=%s,Drv2=%s\n",
				m_CRTinstList[i].m_Rect.top,
				m_CRTinstList[i].m_Rect.left,
				m_CRTinstList[i].m_Rect.right,m_CRTinstList[i].m_Rect.bottom,
				m_CRTinstList[i].DrvTag1,m_CRTinstList[i].DrvTag2);
		OutputDebugString(csstring);
	}
	delete []m_CRTinstList;
}

void CCVMimicDLLTestDlg::OnBnClickedButton23()
{
	char szAppName[]="C:\\CoreView\\FuncExec\\exe\\grop_im.exe";
	long	drvid1,drvid2;
	char	drvName1[7],drvName2[7];
	STARTUPINFO strtup={0} ;
	char	cmdLindstr[1024];
	char	TagName1[TAGNAME_SIZE+1],TagName2[TAGNAME_SIZE+1];
	PROCESS_INFORMATION Info ;
	static HANDLE ghGROPProcess=NULL;
	static HANDLE ghGROPThread=NULL;
	POINT  pPos;

	pPos.x = 167;
	pPos.y = 120;

	memset(drvName1,'\0',7);
	memcpy(drvName1,"MD0014",6);
	memset(drvName2,'\0',7);
	memcpy(drvName2,"MD1148",6);
	GetInstDrvIDbyTagName((char*)(const char*)drvName1,drvid1);
	GetInstDrvIDbyTagName((char*)(const char*)drvName2,drvid2);
	GetInstTagNamebyID(drvid1,TagName1);
	GetInstTagNamebyID(drvid2,TagName2);
	sprintf(cmdLindstr,"%s,%d,%d,%s,%s,%s,%s\0","GR400135",111,2,TagName1,drvName1,TagName2,drvName2);//
	BOOL blRtn = CreateProcess(szAppName,cmdLindstr,0,0,0,0,0,0,&strtup,&Info);
	ghGROPProcess = Info.hProcess;
	CloseHandle(Info.hProcess);
	CloseHandle(Info.hThread);
	HWND hWnd = ::FindWindow(drvName1,TagName1);
	while(hWnd == NULL)
	{
		hWnd = ::FindWindow(drvName1,TagName1);
		Sleep(100);
	}
	::PostMessage(hWnd,WM_USER+1005,pPos.x,pPos.y);
	//RECT  rect;
	long GropWidth,GropHeight;
	GetGrop_ImRect(drvid1,drvid2,GropWidth,GropHeight);
	TRACE("%s:GropWidth=%d,GropHeight=%d\n",TagName1,GropWidth,GropHeight);
}

void CCVMimicDLLTestDlg::OnBnClickedButton24()
{
	char DrvTag1[32];
	char DrvTag2[32];

	//GetInstanceName("C:\\CoreView\\FuncExec\\CVCRTopExec\\Configure\\defdrv.ini",
	//				"C1,BS35003B",DrvTag1,DrvTag2);
}

void CCVMimicDLLTestDlg::OnBnClickedGetrf()
{
	char rflogic[50];

	sprintf_s(rflogic,"$A=EQ(A0001,1)");
	//GetRfLogic("C:\\CoreView\\FuncExec\\CVCRTopExec\\Configure\\defdrv.ini","C1,BS35003B",rflogic);
	int station1,station2;
	CString cs1,cs2;
	CString m_exchar;

	m_exchar.Format("%s",rflogic);
	station1 = m_exchar.Find("(");
	cs1=m_exchar.Left(station1+1);
	station2 = m_exchar.Find(",");
	cs2=m_exchar.Right(m_exchar.GetLength()-station2);
	sprintf(rflogic,"%s%s%s\0",cs1,"L0451",cs2);

}

void CCVMimicDLLTestDlg::OnBnClickedButton26()
{
	// TODO: Add your control notification handler code here
	DWORD DOCount;
	long *Dolist;
	char PIDname[PIDLEN];

	GetCRTDOCountbyNetNo(1,DOCount);
	Dolist = new long [DOCount];
	TRACE("DOCount = %d\n",DOCount);
	GetCRTDOListbyNetNo(1,Dolist,DOCount);
	for(int i=0; i<DOCount; i++)
	{
		GetPID(Dolist[i],PIDname);
		TRACE("%.4d = DOiid:%d,%s\n",i,Dolist[i],PIDname);
	}
	TRACE("RealDOCount = %d\n",DOCount);
	delete []Dolist;
}

void CCVMimicDLLTestDlg::OnBnClickedButton27()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString GrlFileName = "c:\\Drawings\\convert\\GR200403.GRL";
	//CFile GrlFile;
	//OpenGrasDocument(GrlFileName);
	//BOOL b = GrlFile.Open(GrlFileName, CFile::modeRead | CFile::typeBinary, NULL);
	//if (b)
	//{
	//	int FileSize = GrlFile.GetLength();
	//	char* Buf = NULL;
	//	Buf = new char[FileSize];
	//	CArchive ar(&GrlFile, CArchive::load, FileSize, Buf);

	//	//ar >> FileSize;
	//	//UINT Size = GrlFile.Read(Buf, FileSize);
	//	 ar.Read(Buf, FileSize);

	//	GT_GRDATA_HEADER GrDataHeader;
	//	GrDataHeader = *(GT_GRDATA_HEADER*)Buf;

	//	GrlFile.Close();
	//	delete[] Buf;
	//}

	//打开动态库
	//typedef void (*GetGrbPidmapSize)(long, long&);
	//GetGrbPidmapSize pGetGrbPidmapSize;
	//typedef void (*GetGrbPidmap)(long lGrbNo, list<long> &usedPidlist);
	//GetGrbPidmap pGetGrbPidmap;

	//HMODULE m_libHandle = (HMODULE)::LoadLibrary("C:\\CoreView\\FuncExec\\bin\\CVMimicCommonDll_Im.dll");
	//if (NULL != m_libHandle)
	//{
	//	pGetGrbPidmapSize = (GetGrbPidmapSize)::GetProcAddress(m_libHandle, "GetGrbPidmapSize");
	//	pGetGrbPidmap = (GetGrbPidmap)::GetProcAddress(m_libHandle, "GetGrbPidmap");
	//}
	//else
	//{
	//	return;
	//}

	//long lGrbNo = 200403;
	//long usedIidlistSize = 0;
	//pGetGrbPidmapSize(lGrbNo, usedIidlistSize);

	HWND hWnd = ::FindWindow("GetGrbPIDList", NULL);
	if (hWnd != NULL)
	{
		COPYDATASTRUCT cpd;
		char FileName[1024] = "c:\\CoreView\\DriverExec\\CVWebServer\\DataTemp\\GR200403_126464_1332124769.dat";

		cpd.dwData = cpd.cbData = strlen(FileName) + 1;
		cpd.lpData = FileName;

		::SendMessage(hWnd, WM_COPYDATA, NULL, (LPARAM)&cpd);
	}
}

BOOL CCVMimicDLLTestDlg::OpenGrasDocument(LPCTSTR lpszPathName)
{
    USES_CONVERSION;

    ASSERT(lpszPathName == NULL || AfxIsValidString(lpszPathName));

    // just use default implementation if 'docfile' not enabled
    BOOL bResult = FALSE;
	LPSTORAGE lpStorage = NULL;
    TRY
    {
        //if (m_lpRootStg = NULL)
        {
            LPCOLESTR lpsz = T2COLE(lpszPathName);

            // use STGM_CONVERT if necessary
            SCODE sc;
            if (StgIsStorageFile(lpsz) == S_FALSE)
            {
                // convert existing storage file
                sc = StgCreateDocfile(lpsz, STGM_SHARE_DENY_NONE ,
                /* STGM_READWRITE|
                STGM_TRANSACTED|STGM_SHARE_EXCLUSIVE|STGM_CONVERT,*/
                0, &lpStorage);
                if (FAILED(sc) || lpStorage == NULL)
                    sc = StgCreateDocfile(lpsz, //STGM_SHARE_DENY_NONE ,
                    STGM_READ |
                    STGM_TRANSACTED | STGM_SHARE_DENY_WRITE | STGM_CONVERT,
                    0, &lpStorage);
            }
            else
            {
				// open new storage file /****change by venky***/
				sc = StgOpenStorage(lpsz, NULL, STGM_READWRITE | STGM_TRANSACTED | STGM_SHARE_DENY_NONE, 
					//|STGM_SHARE_DENY_NONE ,
					/*STGM_READWRITE|STGM_TRANSACTED|STGM_SHARE_EXCLUSIVE,*/
					0, 0, &lpStorage);

				if (FAILED(sc) || lpStorage == NULL)
					sc = StgOpenStorage(lpsz, NULL,//STGM_READWRITE|STGM_SHARE_DENY_NONE|STGM_TRANSACTED ,
					//STGM_READ|STGM_TRANSACTED|STGM_SHARE_DENY_WRITE,
					STGM_READWRITE | STGM_SHARE_DENY_WRITE,
					0, 0, &lpStorage);
            }

            //			pstgPriority = lpStorage;

            if (FAILED(sc))
                AfxThrowOleException(sc);

            ASSERT(lpStorage != NULL);
            //m_lpRootStg = lpStorage;
        }

        // use helper to read document from storage
        LoadFromStorage(lpStorage);

        bResult = TRUE;
    }
    CATCH_ALL(e)
    {
        //DeleteContents();   // removed failed contents
        //RELEASE(m_lpRootStg);

        // if not file-based load, return exceptions to the caller
        if (lpszPathName == NULL)
        {
            THROW_LAST();
            ASSERT(FALSE);  // not reached
        }

        TRY
        {
            //			ReportSaveLoadException(lpszPathName, e,	//comented by ebine 2001.6.14
            //				FALSE, AFX_IDP_FAILED_TO_OPEN_DOC);
        }
        END_TRY
        //		DELETE_EXCEPTION(e);//comented by ebine 2001.6.18
    }
    END_CATCH_ALL

    return bResult;
}

void CCVMimicDLLTestDlg::LoadFromStorage(LPSTORAGE& lpStorage)
{
	//ASSERT(m_lpRootStg != NULL);

	// open Contents stream
	COleStreamFile file;
	CFileException fe;
	if (!file.OpenStream(lpStorage, _T("Contents"),
		CFile::modeRead|CFile::shareExclusive, &fe) &&
		!file.CreateStream(lpStorage, _T("Contents"),
		CFile::modeRead|CFile::shareExclusive|CFile::modeCreate, &fe))
	{
		if (fe.m_cause == CFileException::fileNotFound)
			AfxThrowArchiveException(CArchiveException::badSchema);
		else
			AfxThrowFileException(fe.m_cause, fe.m_lOsError);
	}

	// load it with CArchive (loads from Contents stream)
	CArchive loadArchive(&file, CArchive::load | CArchive::bNoFlushOnDelete);
	//loadArchive.m_pDocument = this;
	loadArchive.m_bForceFlat = FALSE;

	TRY
	{
		if (file.GetLength() != 0)
			Serialize(loadArchive);     // load main contents
		loadArchive.Close();
		file.Close();
	}
	CATCH_ALL(e)
	{
		file.Abort();   // will not throw an exception
		//DeleteContents();   // removed failed contents
		//NO_CPP_EXCEPTION(loadArchive.Abort());
		THROW_LAST();
	}
	END_CATCH_ALL
}

void CCVMimicDLLTestDlg::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		;
	}
	else
	{
		int FileSize = 0;
		ar >> FileSize;

		char* Buf = NULL;
		Buf = new char[FileSize];
		ar.Read(Buf, FileSize);

		GT_GRDATA_HEADER GrDataHeader;
		GrDataHeader = *(GT_GRDATA_HEADER*)Buf;

		int a = 0;


		//if(m_ptrGrData != NULL)
		//	free( m_ptrGrData );
		//m_ptrGrData = (char*)malloc(m_FileSize);
		//ASSERT(m_ptrGrData != NULL );
		//ar.Read(m_ptrGrData, m_FileSize);

		//ar >> m_OleCount;
		//m_arOleItems.RemoveAll();
		//if(m_OleCount > 0 && m_OleCount <= 10 )
		//{
		//	for(int idx = 0; idx < (int)m_OleCount; ++idx)
		//	{
		//		m_arOleItems.Add( new CGRASCntrItem );
		//		m_arOleItems[idx]->Serialize(ar);
		//	}
		//}
	}
}

void CCVMimicDLLTestDlg::OnBnClickedButton30()
{
	// TODO: 在此添加控件通知处理程序代码
	int Cnt = GetUnGroupedMimicListWithoutNameCount();
}

void CCVMimicDLLTestDlg::OnBnClickedButton31()
{
	// TODO: 在此添加控件通知处理程序代码
	char *UnGroupMimicList = NULL;
	int Cnt = GetUnGroupedMimicListWithoutNameCount();

	UnGroupMimicList = new char[Cnt * 16];

	short ret = GetUnGroupedMimicListWithoutNameMem(UnGroupMimicList);
}

void CCVMimicDLLTestDlg::OnBnClickedButton29()
{
	// TODO: 在此添加控件通知处理程序代码
	time_t t1, t2;
	typedef void (*AutoConvertGrbDef)(void);
	AutoConvertGrbDef AutoConvertGrb;

	HMODULE hModule;
	hModule = LoadLibrary("c:\\CoreView\\FuncExec\\bin\\CVMimicDefineCommdll_Im.dll");
	if (hModule)
	{
		AutoConvertGrb = (AutoConvertGrbDef)::GetProcAddress(hModule, "AutoConvertGrb");
		if (AutoConvertGrb != NULL)
		{
			t1 = GetTickCount();
			AutoConvertGrb();
			t2 = GetTickCount();
		}
		FreeLibrary(hModule);
	}

	CString Msg;
	Msg.Format("AutoConvertGrb函数耗时=%d ms", t2 - t1);
	MessageBox(Msg, "", MB_OK);
}

#define WM_ALL_MIMIC_CALL_LIST	    WM_USER + 1011
#define WM_ALL_MIMIC_PID_LIST	    WM_USER + 1012

void CCVMimicDLLTestDlg::OnBnClickedButton32()
{
	// TODO: 在此添加控件通知处理程序代码
	StartServer();

	HWND hwnd = ::FindWindow(Server_Class_Name, NULL);
	if (hwnd == NULL)
	{
		StartServer();
		hwnd = ::FindWindow(Server_Class_Name, NULL);
	}

	LRESULT Ret = ::SendMessage(hwnd, WM_ALL_MIMIC_CALL_LIST, NULL, NULL);

	StopServer();
}

CString CCVMimicDLLTestDlg::GetOsTempPath()
{
	char OsTempPath[MAX_PATH] = "";
	GetTempPath(MAX_PATH, OsTempPath);

	return OsTempPath;
}

void CCVMimicDLLTestDlg::OnBnClickedButton33()
{
	// TODO: 在此添加控件通知处理程序代码
	StartServer();

	HWND hwnd = ::FindWindow(Server_Class_Name, NULL);
	if (hwnd == NULL)
	{
		StartServer();
		hwnd = ::FindWindow(Server_Class_Name, NULL);
	}

	//判断c:\Users\WangHao\AppData\Local\Temp\Mimic\*_MimicList.txt是否存在
	vector<CString> CallListFile;
	int CallListFileCnt = GetCallListFileCnt(CallListFile);
	vector<CString> PIDListFile;
	int PIDListFileCnt = GetPIDListFileCnt(PIDListFile);

	LRESULT Ret = ::SendMessage(hwnd, WM_ALL_MIMIC_CALL_LIST, NULL, NULL);
	Ret = ::SendMessage(hwnd, WM_ALL_MIMIC_PID_LIST, NULL, NULL);

	StopServer();

	//获取含有指定PID的系统图列表……
	CString FileName;
	CStdioFile f;
	vector<CString> MimicList;
	CString OsTempPath = GetOsTempPath();
	for (int i = 0; i < PIDListFileCnt; i++)
	{
		CString Item = PIDListFile[i];
		FileName.Format("%sMimic\\%s", OsTempPath, Item);
		BOOL b = f.Open(FileName, CFile::modeRead | CFile::typeText);
		if (b)
		{
			CString PID, Size, WriteTime, FileDesrip;
			f.ReadString(Size);
			f.ReadString(WriteTime);
			f.ReadString(FileDesrip);

			while (f.ReadString(PID))
			{
				if (PID.CompareNoCase("A0028") == 0)
				{
					MimicList.push_back(Item.Left(8/*GRB文件的有效长度*/));
					break;
				}
			}

			f.Close();
		}
	}


	MessageBox("OK :-)", "提示：", MB_OK);
}

int CCVMimicDLLTestDlg::GetCallListFileCnt(OUT vector<CString>& CallList)
{
	CallList.clear();
	WIN32_FIND_DATA     FindFileData;
	HANDLE				handle;
	CString PathFile;
	int Cnt = 0;
	PathFile.Format("%s\\Mimic\\*_MimicList.txt", GetOsTempPath());
	handle = FindFirstFile(PathFile, &FindFileData);
	if (handle != INVALID_HANDLE_VALUE)
	{
		BOOL		bResult = TRUE;
		CString		csGrb;
		MimicInfo GrbInfo;
		memset(&GrbInfo, 0, sizeof(MimicInfo));

		while (bResult)
		{
			csGrb.Format("%s", FindFileData.cFileName);
			CallList.push_back(csGrb);
			Cnt++;
			bResult = FindNextFile(handle, &FindFileData);
		}
	}
	FindClose(handle);

	return Cnt;
}

int CCVMimicDLLTestDlg::GetPIDListFileCnt(OUT vector<CString>& PIDList)
{
	PIDList.clear();
	WIN32_FIND_DATA     FindFileData;
	HANDLE				handle;
	CString PathFile;
	int Cnt = 0;
	PathFile.Format("%s\\Mimic\\*_PidList.txt", GetOsTempPath());
	handle = FindFirstFile(PathFile, &FindFileData);
	if (handle != INVALID_HANDLE_VALUE)
	{
		BOOL		bResult = TRUE;
		CString		csGrb;
		MimicInfo GrbInfo;
		memset(&GrbInfo, 0, sizeof(MimicInfo));

		while (bResult)
		{
			csGrb.Format("%s", FindFileData.cFileName);
			PIDList.push_back(csGrb);
			Cnt++;
			bResult = FindNextFile(handle, &FindFileData);
		}
	}
	FindClose(handle);

	return Cnt;
}

void CCVMimicDLLTestDlg::OnBnClickedButton34()
{
	// TODO: 在此添加控件通知处理程序代码
	CString csMimicPID = "A0028";
	MimiNOAndName* pMimiList = NULL;
	int Cnt = GetMimicCountByPID_Im(csMimicPID);
	if (Cnt > 0)
	{
		pMimiList = new MimiNOAndName[Cnt];
		if (pMimiList != NULL)
		{
			bool b = GetMimicByPID_Im(csMimicPID, pMimiList);
		}

		m_GroupList.ResetContent();
		CString Msg;
		for (int i = 0; i < Cnt; i++)
		{
			Msg.Format("%s, %s\n", pMimiList[i].MimNO, pMimiList[i].MimName);
			m_GroupList.AddString(Msg);
		}

		delete[] pMimiList;
	}
}
