// CVMimicDisplayTest.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "CVMimicDisplayTest.h"
#include "CVMimicDisplayTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCVMimicDisplayTestApp

BEGIN_MESSAGE_MAP(CCVMimicDisplayTestApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CCVMimicDisplayTestApp ����

CCVMimicDisplayTestApp::CCVMimicDisplayTestApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CCVMimicDisplayTestApp ����

CCVMimicDisplayTestApp theApp;


// CCVMimicDisplayTestApp ��ʼ��

BOOL CCVMimicDisplayTestApp::InitInstance()
{
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

	CCVMimicDisplayTestDlg dlg;
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

CString CCVMimicDisplayTestApp::GetExePath()
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

