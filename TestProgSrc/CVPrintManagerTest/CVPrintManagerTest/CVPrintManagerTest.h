// CVPrintManagerTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCVPrintManagerTestApp:
// �йش����ʵ�֣������ CVPrintManagerTest.cpp
//

class CCVPrintManagerTestApp : public CWinApp
{
public:
	CCVPrintManagerTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCVPrintManagerTestApp theApp;