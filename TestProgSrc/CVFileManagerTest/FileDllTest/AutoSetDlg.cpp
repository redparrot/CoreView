// AutoSetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FileDllTest.h"
#include "AutoSetDlg.h"


// CAutoSetDlg dialog

IMPLEMENT_DYNAMIC(CAutoSetDlg, CDialog)

CAutoSetDlg::CAutoSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAutoSetDlg::IDD, pParent)
{

}

CAutoSetDlg::~CAutoSetDlg()
{
}

void CAutoSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_AutoSetList);
}


BEGIN_MESSAGE_MAP(CAutoSetDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CAutoSetDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CAutoSetDlg::OnBnClickedCancel)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CAutoSetDlg::OnNMClickList1)
	ON_BN_CLICKED(IDCANCEL2, &CAutoSetDlg::OnBnClickedCancel2)
	ON_BN_CLICKED(IDCANCEL3, &CAutoSetDlg::OnBnClickedCancel3)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CAutoSetDlg message handlers

BOOL CAutoSetDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	m_AutoSetList.SetExtendedStyle(/*m_List.GetExtendedStyle()  | */LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	m_AutoSetList.InsertColumn(0, "No.", LVCFMT_LEFT, 40, -1);
	m_AutoSetList.InsertColumn(1, "Func", LVCFMT_LEFT, 230, -1);
	m_AutoSetList.InsertColumn(2, "Status", LVCFMT_CENTER, 70, -1);

	//功能列表
	SetFuncNameList();

	//刷新一次状态
	OnBnClickedOk();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CAutoSetDlg::SetFuncNameList()
{
	//禁止屏幕保护
	m_AutoSetList.InsertItem(0, "1");
	m_AutoSetList.SetItemText(0, 1, "Disable Screen Save");

	//电源管理
	m_AutoSetList.InsertItem(1, "2");
	m_AutoSetList.SetItemText(1, 1, "Power Manage");

	//显示系统文件夹
	m_AutoSetList.InsertItem(2, "3");
	m_AutoSetList.SetItemText(2, 1, "Show System Folder");

	//显示隐藏文件
	m_AutoSetList.InsertItem(3, "4");
	m_AutoSetList.SetItemText(3, 1, "Show Hide File");

	//显示文件扩展名
	m_AutoSetList.InsertItem(4, "5");
	m_AutoSetList.SetItemText(4, 1, "Show File Ext");

	//显示全路径
	m_AutoSetList.InsertItem(5, "6");
	m_AutoSetList.SetItemText(5, 1, "Show Full Path");

	//禁用简单共享
	m_AutoSetList.InsertItem(6, "7");
	m_AutoSetList.SetItemText(6, 1, "Disable Sample File Share");

	//禁用欢迎屏幕
	m_AutoSetList.InsertItem(7, "8");
	m_AutoSetList.SetItemText(7, 1, "Disable Welcome Screen");

	//设置网络访问用户组
	m_AutoSetList.InsertItem(8, "9");
	m_AutoSetList.SetItemText(8, 1, "Network Logon User Group");

	//设置禁止访问用户组
	m_AutoSetList.InsertItem(9, "10");
	m_AutoSetList.SetItemText(9, 1, "Deny Network Logon User Group");

	//允许远程空密码访问
	m_AutoSetList.InsertItem(10, "11");
	m_AutoSetList.SetItemText(10, 1, "Enable Remote Access Use Blank Password");

	//禁用Internet校时
	m_AutoSetList.InsertItem(11, "12");
	m_AutoSetList.SetItemText(11, 1, "Disable Internet Sync");

	//禁用防火墙
	m_AutoSetList.InsertItem(12, "13");
	m_AutoSetList.SetItemText(12, 1, "Disable Firewall");

	//禁用系统还原
	m_AutoSetList.InsertItem(13, "14");
	m_AutoSetList.SetItemText(13, 1, "Turn Off System Restore");

	//禁止自动更新
	m_AutoSetList.InsertItem(14, "15");
	m_AutoSetList.SetItemText(14, 1, "Turn Off Auto Update");

	//禁用错误报告
	m_AutoSetList.InsertItem(15, "16");
	m_AutoSetList.SetItemText(15, 1, "Disable Error Reporting");

	//关闭Dr.Watson
	m_AutoSetList.InsertItem(16, "17");
	m_AutoSetList.SetItemText(16, 1, "Disable Dr.Watson");

	//禁止休眠
	m_AutoSetList.InsertItem(17, "18");
	m_AutoSetList.SetItemText(17, 1, "Disable Hibernate");

	//加速窗口
	m_AutoSetList.InsertItem(18, "19");
	m_AutoSetList.SetItemText(18, 1, "Set MinAniMate");

	//设置虚拟内存
	m_AutoSetList.InsertItem(19, "20");
	m_AutoSetList.SetItemText(19, 1, "Set Virtual Memory");

	//禁止MSN启动
	m_AutoSetList.InsertItem(20, "21");
	m_AutoSetList.SetItemText(20, 1, "Disable MSN");

	//拖动不显示内容
	m_AutoSetList.InsertItem(21, "22");
	m_AutoSetList.SetItemText(21, 1, "Disable Drag Full Windows");

	//删除文件
	m_AutoSetList.InsertItem(22, "23");
	m_AutoSetList.SetItemText(22, 1, "Delete Gapi And Lmhosts");

	//禁止索引服务
	m_AutoSetList.InsertItem(23, "24");
	m_AutoSetList.SetItemText(23, 1, "Disable Index");


}

void CAutoSetDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//刷新当前所有项的状态
	CString s, Os;
	char KeyVal[MAX_PATH] = {0};
	BOOL b = FALSE;
	//禁止屏幕保护
	//Os = GetOSVersion();
	//if (Os == "WINXP")
	//{
	//	b = GetScreenSaveStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(0, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(0, 2, "N");
	//	}
	//}

	////电源管理
	//if (Os == "WINXP")
	//{
	//	b = GetPowerManageStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(1, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(1, 2, "N");
	//	}
	//}

	////显示系统文件夹
	//if (Os == "WINXP")
	//{
	//	b = GetShowSystemFolderStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(2, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(2, 2, "N");
	//	}
	//}

	////显示隐藏文件
	//if (Os == "WINXP")
	//{
	//	b = GetShowHideFileStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(3, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(3, 2, "N");
	//	}
	//}

	////显示文件扩展名
	//if (Os == "WINXP")
	//{
	//	b = GetShowFileExtStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(4, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(4, 2, "N");
	//	}
	//}

	////显示全路径
	//if (Os == "WINXP")
	//{
	//	b = GetShowFullPathStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(5, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(5, 2, "N");
	//	}
	//}

	////禁用简单共享
	//if (Os == "WINXP")
	//{
	//	b = GetDisableSampleFileShareStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(6, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(6, 2, "N");
	//	}
	//}

	////禁用欢迎屏幕
	//if (Os == "WINXP")
	//{
	//	b = GetDisableWelcomeScreenStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(7, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(7, 2, "N");
	//	}
	//}

	////允许远程空密码访问
	//if (Os == "WINXP")
	//{
	//	b = GetEnableRemoteAccessUseBlankPasswordStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(10, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(10, 2, "N");
	//	}
	//}

	////禁用Internet校时
	//if (Os == "WINXP")
	//{
	//	b = GetDisableInternetSyncStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(11, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(11, 2, "N");
	//	}
	//}

	////禁用防火墙
	//if (Os == "WINXP")
	//{
	//	b = GetDisableFirewallStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(12, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(12, 2, "N");
	//	}
	//}

	////禁用系统还原
	//if (Os == "WINXP")
	//{
	//	b = GetTurnOffSystemRestoreStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(13, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(13, 2, "N");
	//	}
	//}

	////禁止自动更新
	//if (Os == "WINXP")
	//{
	//	b = GetTurnOffAutoUpdateStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(14, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(14, 2, "N");
	//	}
	//}

	////禁用错误报告
	//if (Os == "WINXP")
	//{
	//	b = GetDisableErrorReportingStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(15, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(15, 2, "N");
	//	}
	//}

	////关闭Dr.Watson
	//if (Os == "WINXP")
	//{
	//	b = GetDisableDrWatsonStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(16, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(16, 2, "N");
	//	}
	//}

	////禁止休眠
	//if (Os == "WINXP")
	//{
	//	b = GetDisableHibernateStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(17, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(17, 2, "N");
	//	}
	//}

	////加速窗口
	//if (Os == "WINXP")
	//{
	//	b = GetMinAniMateStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(18, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(18, 2, "N");
	//	}
	//}

	////设置虚拟内存
	//if (Os == "WINXP")
	//{
	//	b = GetVirtualMemoryStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(19, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(19, 2, "N");
	//	}
	//}

	////禁止MSN启动
	//if (Os == "WINXP")
	//{
	//	b = GetDisableMSNStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(20, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(20, 2, "N");
	//	}
	//}

	////拖动不显示内容
	//if (Os == "WINXP")
	//{
	//	b = GetDisableDragFullWindowsStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(21, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(21, 2, "N");
	//	}
	//}

	////删除文件
	//if (Os == "WINXP")
	//{
	//	b = GetDeleteGapiAndLmhostsStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(22, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(22, 2, "N");
	//	}
	//}

	////禁止索引服务
	//if (Os == "WINXP")
	//{
	//	b = GetDisableIndexStatus();
	//	if (b)
	//	{
	//		m_AutoSetList.SetItemText(23, 2, "Y");
	//	}
	//	else
	//	{
	//		m_AutoSetList.SetItemText(23, 2, "N");
	//	}
	//}
}

void CAutoSetDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void CAutoSetDlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	//计算选中的项目
	*pResult = 0;
	//return;
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	//BOOL b = FALSE;

	nItem = pNMListView->iItem;
	x = pNMListView->ptAction.x;
	if (nItem >= 0)
	{
		TRACE("选择的Item索引：%d\n", nItem);

		SetTimer(WM_TIMER + 1, 10, NULL);
	}
}

//选中
void CAutoSetDlg::OnBnClickedCancel2()
{
	// TODO: Add your control notification handler code here
	//UINT ret = m_AutoSetList.GetItemState(0, LVIS_STATEIMAGEMASK);
	m_AutoSetList.SetItemState(0, 0x2000, LVIS_STATEIMAGEMASK);//勾选
	m_AutoSetList.SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);//高亮
	//m_AutoSetList.SetItemState(0, LVIS_FOCUSED, LVIS_FOCUSED);//焦点
	//m_AutoSetList.SetItemState(0, LVIS_ACTIVATING, LVIS_ACTIVATING);//焦点
}	

//取消
void CAutoSetDlg::OnBnClickedCancel3()
{
	// TODO: Add your control notification handler code here
	m_AutoSetList.SetItemState(0, 0x1000, LVIS_STATEIMAGEMASK);//取消勾选
	m_AutoSetList.SetItemState(0, ~LVIS_SELECTED, LVIS_SELECTED);//不高亮

// 	int Ret = m_AutoSetList.GetItemState(0, LVIS_SELECTED);
// 	if (Ret == LVIS_SELECTED)
// 	{
// 		m_AutoSetList.SetItemState(0, ~LVIS_SELECTED, LVIS_SELECTED);//不高亮
// 		//Ret = m_AutoSetList.GetItemState(0, LVIS_SELECTED);
// 	}
}

void CAutoSetDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	static int OldItem = -1;

	if (nIDEvent == WM_TIMER + 1)
	{
		KillTimer(WM_TIMER + 1);

		//计算第一列的列宽
		RECT Rect;

		m_AutoSetList.GetHeaderCtrl()->GetItemRect(0, &Rect);
		int W = Rect.right - Rect.left;
		if (x <= 20)
		{
			TRACE("第一列\n");
			m_AutoSetList.SetItemState(nItem, LVIS_SELECTED, LVIS_SELECTED);//高亮;
			if (OldItem >= 0 && nItem != OldItem)
			{
				m_AutoSetList.SetItemState(OldItem, ~LVIS_SELECTED, LVIS_SELECTED);//不高亮;
			}
		}
		else
		{
			TRACE("非第一列\n");
			int Check = m_AutoSetList.GetCheck(nItem);
			if (Check)
			{
				m_AutoSetList.SetItemState(nItem, 0x1000, LVIS_STATEIMAGEMASK);//取消勾选
			}
			else
			{
				m_AutoSetList.SetItemState(nItem, 0x2000, LVIS_STATEIMAGEMASK);//勾选
			}
		}

		OldItem = nItem;
	}

	CDialog::OnTimer(nIDEvent);
}
