// CVAdminTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "WriteLogOper.h"


// CCVAdminTestApp:
// �йش����ʵ�֣������ CVAdminTest.cpp
//

class CCVAdminTestApp : public CWinApp
{
public:
    CCVAdminTestApp();
    CWriteLogOper Log;
// ��д
public:
    virtual BOOL InitInstance();
    void CCVAdminTestApp::SetPrivateClassName(CString ClassName);

// ʵ��

    DECLARE_MESSAGE_MAP()
public:
    virtual int ExitInstance();
};

extern CCVAdminTestApp theApp;