// CVMimicDLLTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCVMimicDLLTestApp:
// �йش����ʵ�֣������ CVMimicDLLTest.cpp
//

class CCVMimicDLLTestApp : public CWinApp
{
public:
	CCVMimicDLLTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCVMimicDLLTestApp theApp;