// SystemLoadingGenerator.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSystemLoadingGeneratorApp:
// �йش����ʵ�֣������ SystemLoadingGenerator.cpp
//

class CSystemLoadingGeneratorApp : public CWinApp
{
public:
	CSystemLoadingGeneratorApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSystemLoadingGeneratorApp theApp;