// chatroom.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������
#include <winsock2.h>
#include <windows.h>


// CchatroomApp:
// �йش����ʵ�֣������ chatroom.cpp
//

class CchatroomApp : public CWinApp
{
public:
	CchatroomApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CchatroomApp theApp;

void sendss(CString mymsg);
