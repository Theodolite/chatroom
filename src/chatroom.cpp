// chatroom.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "chatroom.h"
#include "chatroomDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CchatroomApp

BEGIN_MESSAGE_MAP(CchatroomApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CchatroomApp ����

CchatroomApp::CchatroomApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CchatroomApp ����

CchatroomApp theApp;


// CchatroomApp ��ʼ��

BOOL CchatroomApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControls()�����򣬽��޷��������ڡ�
	InitCommonControls();

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CchatroomDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ�á�ȷ�������ر�
		//�Ի���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ�á�ȡ�������ر�
		//�Ի���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	// ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

void sendss(CString mymsg)
{
	WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET s=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    sockaddr_in sockaddr;
    sockaddr.sin_family=PF_INET;
    sockaddr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
    sockaddr.sin_port=htons(9000);

    connect(s, (SOCKADDR*)&sockaddr, sizeof(SOCKADDR));

    char buffer[MAXBYTE]={0};
    recv(s, buffer, MAXBYTE, NULL);

    //while(TRUE)
    {
        //char* mymsg=new char[100000];
        //printf("You can chat with server now:\n");
        //gets(mymsg);
        send(s, mymsg, strlen(mymsg)+sizeof(char), NULL);
        /*
           recv�����е�bufferlength�����ǿ��Թ̶�ֵ��
           send�����е�bufferlength�������̶ܹ�ֵ����Ҫ��ʵ�ʳ��ȣ����ҿ��ǵ�'\0'�ַ���
        */
        memset(buffer,0,sizeof(buffer));
        // recv(s, buffer, MAXBYTE, NULL);
        // if(strlen(buffer)!=0)
        // {
        //     printf("***SERVER***: %s", buffer);
        // }
        // else
        // {
        //     printf("Server dead\n");
        // }
        // if(Equal(mymsg,"exit"))
        // {
        //     closesocket(s);
        // }
    }

    closesocket(s);
    WSACleanup();
}
