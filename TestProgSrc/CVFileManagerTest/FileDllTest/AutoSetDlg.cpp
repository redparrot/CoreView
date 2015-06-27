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

	//�����б�
	SetFuncNameList();

	//ˢ��һ��״̬
	OnBnClickedOk();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CAutoSetDlg::SetFuncNameList()
{
	//��ֹ��Ļ����
	m_AutoSetList.InsertItem(0, "1");
	m_AutoSetList.SetItemText(0, 1, "Disable Screen Save");

	//��Դ����
	m_AutoSetList.InsertItem(1, "2");
	m_AutoSetList.SetItemText(1, 1, "Power Manage");

	//��ʾϵͳ�ļ���
	m_AutoSetList.InsertItem(2, "3");
	m_AutoSetList.SetItemText(2, 1, "Show System Folder");

	//��ʾ�����ļ�
	m_AutoSetList.InsertItem(3, "4");
	m_AutoSetList.SetItemText(3, 1, "Show Hide File");

	//��ʾ�ļ���չ��
	m_AutoSetList.InsertItem(4, "5");
	m_AutoSetList.SetItemText(4, 1, "Show File Ext");

	//��ʾȫ·��
	m_AutoSetList.InsertItem(5, "6");
	m_AutoSetList.SetItemText(5, 1, "Show Full Path");

	//���ü򵥹���
	m_AutoSetList.InsertItem(6, "7");
	m_AutoSetList.SetItemText(6, 1, "Disable Sample File Share");

	//���û�ӭ��Ļ
	m_AutoSetList.InsertItem(7, "8");
	m_AutoSetList.SetItemText(7, 1, "Disable Welcome Screen");

	//������������û���
	m_AutoSetList.InsertItem(8, "9");
	m_AutoSetList.SetItemText(8, 1, "Network Logon User Group");

	//���ý�ֹ�����û���
	m_AutoSetList.InsertItem(9, "10");
	m_AutoSetList.SetItemText(9, 1, "Deny Network Logon User Group");

	//����Զ�̿��������
	m_AutoSetList.InsertItem(10, "11");
	m_AutoSetList.SetItemText(10, 1, "Enable Remote Access Use Blank Password");

	//����InternetУʱ
	m_AutoSetList.InsertItem(11, "12");
	m_AutoSetList.SetItemText(11, 1, "Disable Internet Sync");

	//���÷���ǽ
	m_AutoSetList.InsertItem(12, "13");
	m_AutoSetList.SetItemText(12, 1, "Disable Firewall");

	//����ϵͳ��ԭ
	m_AutoSetList.InsertItem(13, "14");
	m_AutoSetList.SetItemText(13, 1, "Turn Off System Restore");

	//��ֹ�Զ�����
	m_AutoSetList.InsertItem(14, "15");
	m_AutoSetList.SetItemText(14, 1, "Turn Off Auto Update");

	//���ô��󱨸�
	m_AutoSetList.InsertItem(15, "16");
	m_AutoSetList.SetItemText(15, 1, "Disable Error Reporting");

	//�ر�Dr.Watson
	m_AutoSetList.InsertItem(16, "17");
	m_AutoSetList.SetItemText(16, 1, "Disable Dr.Watson");

	//��ֹ����
	m_AutoSetList.InsertItem(17, "18");
	m_AutoSetList.SetItemText(17, 1, "Disable Hibernate");

	//���ٴ���
	m_AutoSetList.InsertItem(18, "19");
	m_AutoSetList.SetItemText(18, 1, "Set MinAniMate");

	//���������ڴ�
	m_AutoSetList.InsertItem(19, "20");
	m_AutoSetList.SetItemText(19, 1, "Set Virtual Memory");

	//��ֹMSN����
	m_AutoSetList.InsertItem(20, "21");
	m_AutoSetList.SetItemText(20, 1, "Disable MSN");

	//�϶�����ʾ����
	m_AutoSetList.InsertItem(21, "22");
	m_AutoSetList.SetItemText(21, 1, "Disable Drag Full Windows");

	//ɾ���ļ�
	m_AutoSetList.InsertItem(22, "23");
	m_AutoSetList.SetItemText(22, 1, "Delete Gapi And Lmhosts");

	//��ֹ��������
	m_AutoSetList.InsertItem(23, "24");
	m_AutoSetList.SetItemText(23, 1, "Disable Index");


}

void CAutoSetDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//ˢ�µ�ǰ�������״̬
	CString s, Os;
	char KeyVal[MAX_PATH] = {0};
	BOOL b = FALSE;
	//��ֹ��Ļ����
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

	////��Դ����
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

	////��ʾϵͳ�ļ���
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

	////��ʾ�����ļ�
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

	////��ʾ�ļ���չ��
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

	////��ʾȫ·��
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

	////���ü򵥹���
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

	////���û�ӭ��Ļ
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

	////����Զ�̿��������
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

	////����InternetУʱ
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

	////���÷���ǽ
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

	////����ϵͳ��ԭ
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

	////��ֹ�Զ�����
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

	////���ô��󱨸�
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

	////�ر�Dr.Watson
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

	////��ֹ����
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

	////���ٴ���
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

	////���������ڴ�
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

	////��ֹMSN����
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

	////�϶�����ʾ����
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

	////ɾ���ļ�
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

	////��ֹ��������
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
	//����ѡ�е���Ŀ
	*pResult = 0;
	//return;
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	//BOOL b = FALSE;

	nItem = pNMListView->iItem;
	x = pNMListView->ptAction.x;
	if (nItem >= 0)
	{
		TRACE("ѡ���Item������%d\n", nItem);

		SetTimer(WM_TIMER + 1, 10, NULL);
	}
}

//ѡ��
void CAutoSetDlg::OnBnClickedCancel2()
{
	// TODO: Add your control notification handler code here
	//UINT ret = m_AutoSetList.GetItemState(0, LVIS_STATEIMAGEMASK);
	m_AutoSetList.SetItemState(0, 0x2000, LVIS_STATEIMAGEMASK);//��ѡ
	m_AutoSetList.SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);//����
	//m_AutoSetList.SetItemState(0, LVIS_FOCUSED, LVIS_FOCUSED);//����
	//m_AutoSetList.SetItemState(0, LVIS_ACTIVATING, LVIS_ACTIVATING);//����
}	

//ȡ��
void CAutoSetDlg::OnBnClickedCancel3()
{
	// TODO: Add your control notification handler code here
	m_AutoSetList.SetItemState(0, 0x1000, LVIS_STATEIMAGEMASK);//ȡ����ѡ
	m_AutoSetList.SetItemState(0, ~LVIS_SELECTED, LVIS_SELECTED);//������

// 	int Ret = m_AutoSetList.GetItemState(0, LVIS_SELECTED);
// 	if (Ret == LVIS_SELECTED)
// 	{
// 		m_AutoSetList.SetItemState(0, ~LVIS_SELECTED, LVIS_SELECTED);//������
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

		//�����һ�е��п�
		RECT Rect;

		m_AutoSetList.GetHeaderCtrl()->GetItemRect(0, &Rect);
		int W = Rect.right - Rect.left;
		if (x <= 20)
		{
			TRACE("��һ��\n");
			m_AutoSetList.SetItemState(nItem, LVIS_SELECTED, LVIS_SELECTED);//����;
			if (OldItem >= 0 && nItem != OldItem)
			{
				m_AutoSetList.SetItemState(OldItem, ~LVIS_SELECTED, LVIS_SELECTED);//������;
			}
		}
		else
		{
			TRACE("�ǵ�һ��\n");
			int Check = m_AutoSetList.GetCheck(nItem);
			if (Check)
			{
				m_AutoSetList.SetItemState(nItem, 0x1000, LVIS_STATEIMAGEMASK);//ȡ����ѡ
			}
			else
			{
				m_AutoSetList.SetItemState(nItem, 0x2000, LVIS_STATEIMAGEMASK);//��ѡ
			}
		}

		OldItem = nItem;
	}

	CDialog::OnTimer(nIDEvent);
}
