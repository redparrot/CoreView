// MultiStartTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMultiStartTestApp:
// �йش����ʵ�֣������ MultiStartTest.cpp
//

class CMultiStartTestApp : public CWinApp
{
public:
	CMultiStartTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMultiStartTestApp theApp;