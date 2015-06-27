// CVAdminTest.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "CVAdminTest.h"
#include "CVAdminTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCVAdminTestApp

BEGIN_MESSAGE_MAP(CCVAdminTestApp, CWinApp)
    ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CCVAdminTestApp ����

CCVAdminTestApp::CCVAdminTestApp()
{
    // TODO: �ڴ˴���ӹ�����룬
    // ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CCVAdminTestApp ����

CCVAdminTestApp theApp;


// CCVAdminTestApp ��ʼ��
void CCVAdminTestApp::SetPrivateClassName(CString ClassName)
{
    WNDCLASS wc;

    ::GetClassInfo(AfxGetInstanceHandle(), "#32770", &wc);
    wc.lpszClassName = ClassName;
    AfxRegisterClass(&wc);
}

BOOL CCVAdminTestApp::InitInstance()
{
    //����LOG·��
    SHCreateDirectoryEx(NULL, "C:\\CoreView\\Record data\\Log\\CVAdminMaker\\", NULL);
    Log.SetName("C:\\CoreView\\Record data\\Log\\CVAdminMaker\\CVAdminMaker.txt");
    Log.SetMaxSize(1000);
    Log.Open();

    Log.Write("��������");

    SetPrivateClassName("CVAdminManager");

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

    CCVAdminTestDlg dlg;
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

int CCVAdminTestApp::ExitInstance()
{
    // TODO: �ڴ����ר�ô����/����û���
    Log.Write("���������ر�");
    Log.Colse();

    return CWinApp::ExitInstance();
}
