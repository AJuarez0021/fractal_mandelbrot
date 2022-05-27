// Mandel.h : main header file for the MANDEL application
//

#if !defined(AFX_MANDEL_H__531E3A8E_2B32_4525_826E_34F77B60C2B9__INCLUDED_)
#define AFX_MANDEL_H__531E3A8E_2B32_4525_826E_34F77B60C2B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMandelApp:
// See Mandel.cpp for the implementation of this class
//

class CMandelApp : public CWinApp
{
public:
	CMandelApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMandelApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMandelApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANDEL_H__531E3A8E_2B32_4525_826E_34F77B60C2B9__INCLUDED_)
