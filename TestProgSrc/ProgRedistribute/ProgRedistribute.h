// ProgRedistribute.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CProgRedistributeApp:
// �йش����ʵ�֣������ ProgRedistribute.cpp
//

class CProgRedistributeApp : public CWinApp
{
public:
	CProgRedistributeApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CProgRedistributeApp theApp;