// CVAlarmDisplayTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCVAlarmDisplayTestApp:
// �йش����ʵ�֣������ CVAlarmDisplayTest.cpp
//

class CCVAlarmDisplayTestApp : public CWinApp
{
public:
	CCVAlarmDisplayTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCVAlarmDisplayTestApp theApp;