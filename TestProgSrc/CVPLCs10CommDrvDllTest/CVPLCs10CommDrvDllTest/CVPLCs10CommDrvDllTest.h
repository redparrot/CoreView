// CVPLCs10CommDrvDllTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCVPLCs10CommDrvDllTestApp:
// �йش����ʵ�֣������ CVPLCs10CommDrvDllTest.cpp
//

class CCVPLCs10CommDrvDllTestApp : public CWinApp
{
public:
	CCVPLCs10CommDrvDllTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CCVPLCs10CommDrvDllTestApp theApp;