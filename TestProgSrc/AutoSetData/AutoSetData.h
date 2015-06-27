// AutoSetData.h : main header file for the AUTOSETDATA application
//

#if !defined(AFX_AUTOSETDATA_H__3555A12F_FBE6_443C_BA7D_56839A185871__INCLUDED_)
#define AFX_AUTOSETDATA_H__3555A12F_FBE6_443C_BA7D_56839A185871__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "AutoSetDataDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CAutoSetDataApp:
// See AutoSetData.cpp for the implementation of this class
//

class CAutoSetDataApp : public CWinApp
{
public:
    CAutoSetDataApp();
	CAutoSetDataDlg* Dlg;

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CAutoSetDataApp)
public:
    virtual BOOL InitInstance();
    //}}AFX_VIRTUAL

// Implementation

    //{{AFX_MSG(CAutoSetDataApp)
    // NOTE - the ClassWizard will add and remove member functions here.
    //    DO NOT EDIT what you see in these blocks of generated code !
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOSETDATA_H__3555A12F_FBE6_443C_BA7D_56839A185871__INCLUDED_)
