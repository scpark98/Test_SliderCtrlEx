
// Test_SliderCtrlEx.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTest_SliderCtrlExApp:
// See Test_SliderCtrlEx.cpp for the implementation of this class
//

class CTest_SliderCtrlExApp : public CWinApp
{
public:
	CTest_SliderCtrlExApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTest_SliderCtrlExApp theApp;