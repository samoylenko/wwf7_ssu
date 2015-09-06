// wwf7_ssu.h : main header file for the WWF7_SSU application
//

#if !defined(AFX_WWF7_SSU_H__239F7F93_815B_409D_9AC2_B5230DAACA07__INCLUDED_)
#define AFX_WWF7_SSU_H__239F7F93_815B_409D_9AC2_B5230DAACA07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWwf7_ssuApp:
// See wwf7_ssu.cpp for the implementation of this class
//

class CWwf7_ssuApp : public CWinApp
{
public:
	CWwf7_ssuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWwf7_ssuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWwf7_ssuApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WWF7_SSU_H__239F7F93_815B_409D_9AC2_B5230DAACA07__INCLUDED_)
