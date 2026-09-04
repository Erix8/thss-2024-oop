
// MFCApplication_OOP_Week7.h: MFCApplication_OOP_Week7 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// CMFCApplicationOOPWeek7App:
// 有关此类的实现，请参阅 MFCApplication_OOP_Week7.cpp
//

class CMFCApplicationOOPWeek7App : public CWinApp
{
public:
	CMFCApplicationOOPWeek7App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplicationOOPWeek7App theApp;
