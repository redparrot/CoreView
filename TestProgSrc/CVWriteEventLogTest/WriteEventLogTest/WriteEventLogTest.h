// WriteEventLogTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CWriteEventLogTestApp:
// �йش����ʵ�֣������ WriteEventLogTest.cpp
//

class CWriteEventLogTestApp : public CWinApp
{
public:
	CWriteEventLogTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CWriteEventLogTestApp theApp;