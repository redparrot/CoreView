// CVMimicDefineCommdll_ImTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCVMimicDefineCommdll_ImTestApp:
// �йش����ʵ�֣������ CVMimicDefineCommdll_ImTest.cpp
//

class CCVMimicDefineCommdll_ImTestApp : public CWinApp
{
public:
	CCVMimicDefineCommdll_ImTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCVMimicDefineCommdll_ImTestApp theApp;