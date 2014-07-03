// chatroom.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error 在包含用于 PCH 的此文件之前包含“stdafx.h”
#endif

#include "resource.h"		// 主符号
#include <winsock2.h>
#include <windows.h>


// CchatroomApp:
// 有关此类的实现，请参阅 chatroom.cpp
//

class CchatroomApp : public CWinApp
{
public:
	CchatroomApp();

// 重写
	public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CchatroomApp theApp;

void sendss(CString mymsg);
