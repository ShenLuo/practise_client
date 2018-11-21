// 功能：加班通信管理
// 作者：罗深
// 时间：2017/09/02

#ifndef WIN_SOCKET__MY_H_
#define WIN_SOCKET__MY_H_

//#include <winsock2.h>
#include <windows.h>

class WinSocket
{
public:
	// 建立与服务器的连接
	static bool WinSocketInitAndConnect();

	// 给服务器发送消息
	static bool WinSockSendInfoToServer(const char* sInfo);

	// 接受服务器数据
	static bool WinSockRecvInfoFromServer(void* pParam);

public:
	// 客户端通信对象
	static SOCKET m_Socket;
};

#endif // WIN_SOCKET__MY_H_