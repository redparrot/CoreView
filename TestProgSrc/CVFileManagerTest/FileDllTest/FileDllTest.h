// FileDllTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "C:/CoreView_Src/Include/CVFileManagerComm.h"


// CFileDllTestApp:
// �йش����ʵ�֣������ FileDllTest.cpp
//

class CFileDllTestApp : public CWinApp
{
public:
	CFileDllTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFileDllTestApp theApp;