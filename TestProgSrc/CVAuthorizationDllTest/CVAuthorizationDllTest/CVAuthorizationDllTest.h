// CVAuthorizationDllTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCVAuthorizationDllTestApp:
// �йش����ʵ�֣������ CVAuthorizationDllTest.cpp
//

class CCVAuthorizationDllTestApp : public CWinApp
{
public:
	CCVAuthorizationDllTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
public:
	virtual int ExitInstance();
};

extern CCVAuthorizationDllTestApp theApp;