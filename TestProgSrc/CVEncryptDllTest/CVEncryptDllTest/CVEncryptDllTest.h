// CVEncryptDllTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCVEncryptDllTestApp:
// �йش����ʵ�֣������ CVEncryptDllTest.cpp
//

class CCVEncryptDllTestApp : public CWinApp
{
public:
	CCVEncryptDllTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCVEncryptDllTestApp theApp;