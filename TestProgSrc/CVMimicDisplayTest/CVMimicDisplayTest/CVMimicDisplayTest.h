// CVMimicDisplayTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCVMimicDisplayTestApp:
// �йش����ʵ�֣������ CVMimicDisplayTest.cpp
//

class CCVMimicDisplayTestApp : public CWinApp
{
public:
	CCVMimicDisplayTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
public:
	CString GetExePath();
};

extern CCVMimicDisplayTestApp theApp;