// chatroom.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "chatroom.h"
#include "chatroomDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

SOCKET server;
// CchatroomApp

BEGIN_MESSAGE_MAP(CchatroomApp, CWinApp)
    ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CchatroomApp 构造

CchatroomApp::CchatroomApp()
{
    // TODO: 在此处添加构造代码，
    // 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CchatroomApp 对象

CchatroomApp theApp;


// CchatroomApp 初始化

BOOL CchatroomApp::InitInstance()
{
    // 如果一个运行在 Windows XP 上的应用程序清单指定要
    // 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
    //则需要 InitCommonControls()。否则，将无法创建窗口。
    InitCommonControls();

    CWinApp::InitInstance();

    AfxEnableControlContainer();

    // 标准初始化
    // 如果未使用这些功能并希望减小
    // 最终可执行文件的大小，则应移除下列
    // 不需要的特定初始化例程
    // 更改用于存储设置的注册表项
    // TODO: 应适当修改该字符串，
    // 例如修改为公司或组织名
    SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

    //***************************************************
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    server=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    sockaddr_in sockaddr;
    sockaddr.sin_family=PF_INET;
    sockaddr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
    sockaddr.sin_port=htons(10001);
    connect(server, (SOCKADDR*)&sockaddr, sizeof(SOCKADDR));
    //***************************************************
    
    CchatroomDlg dlg;
    m_pMainWnd = &dlg;
    INT_PTR nResponse = dlg.DoModal();
    
    if (nResponse == IDOK)
    {
        // TODO: 在此放置处理何时用“确定”来关闭
        //对话框的代码
    }
    else if (nResponse == IDCANCEL)
    {
        // TODO: 在此放置处理何时用“取消”来关闭
        //对话框的代码
    }
    
    // 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
    // 而不是启动应用程序的消息泵。
    return FALSE;
}

void sendss(CString mymsg)
{
    char buffer[MAXBYTE]={0};

    send(server, mymsg, strlen(mymsg)+sizeof(char), NULL);
    /*
       recv函数中的bufferlength参数是可以固定值的
       send函数中的bufferlength参数不能固定值，需要看实际长度，并且考虑到'\0'字符串
    */
    memset(buffer,0,sizeof(buffer));

    //closesocket(s);
    //WSACleanup();
}
