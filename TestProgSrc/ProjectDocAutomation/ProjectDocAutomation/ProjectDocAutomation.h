// ProjectDocAutomation.h : ProjectDocAutomation Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CProjectDocAutomationApp:
// �йش����ʵ�֣������ ProjectDocAutomation.cpp
//

class CProjectDocAutomationApp : public CWinApp
{
public:
	CProjectDocAutomationApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CProjectDocAutomationApp theApp;