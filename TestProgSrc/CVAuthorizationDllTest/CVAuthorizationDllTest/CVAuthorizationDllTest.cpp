// CVAuthorizationDllTest.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "CVAuthorizationDllTest.h"
#include "CVAuthorizationDllTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma data_seg(".OnlyOne")
long InstanceCount = 0;
#pragma data_seg()
#pragma comment(linker, "/SECTION:.OnlyOne,RWS")


// CCVAuthorizationDllTestApp

BEGIN_MESSAGE_MAP(CCVAuthorizationDllTestApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CCVAuthorizationDllTestApp ����

CCVAuthorizationDllTestApp::CCVAuthorizationDllTestApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CCVAuthorizationDllTestApp ����

CCVAuthorizationDllTestApp theApp;


// CCVAuthorizationDllTestApp ��ʼ��

BOOL CCVAuthorizationDllTestApp::InitInstance()
{
	//������ʵ������
	InstanceCount++;
	if (InstanceCount > 1)
	{
		return FALSE;
	}

	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CCVAuthorizationDllTestDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˴����ô����ʱ�á�ȷ�������ر�
		//  �Ի���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ�á�ȡ�������ر�
		//  �Ի���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

int CCVAuthorizationDllTestApp::ExitInstance()
{
	// TODO: �ڴ����ר�ô����/����û���
	InstanceCount--;

	return CWinApp::ExitInstance();
}
