// CVPrecordDspTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCVPrecordDspTestApp:
// �йش����ʵ�֣������ CVPrecordDspTest.cpp
//

class CCVPrecordDspTestApp : public CWinApp
{
public:
	CCVPrecordDspTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCVPrecordDspTestApp theApp;