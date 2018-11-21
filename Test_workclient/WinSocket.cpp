// 功能：加班通信管理
// 作者：罗深
// 时间：2017/09/02

#include "WinSocket.h"
#include "CarGpsUtil.h"
#include "WorkClient.h"
#include "WinHelper.h"
#include <windows.h>

SOCKET WinSocket::m_Socket = INVALID_SOCKET;

// 建立与服务器的连接
bool WinSocket::WinSocketInitAndConnect()
{
	// 查看网络版本
	WSADATA wsData;
	int nResult = WSAStartup(MAKEWORD(2,2), &wsData);
	if (NO_ERROR != nResult)
	{
		return false;
	}

	// 创建Socket对象
	SOCKET soConnect= INVALID_SOCKET;
	soConnect = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (soConnect == INVALID_SOCKET)
	{
		return false;
	}
	
	// 连接Socket到目标
	sockaddr_in stAddress;
	stAddress.sin_family = AF_INET;
	stAddress.sin_addr.S_un.S_addr = inet_addr("192.168.1.40");
	stAddress.sin_port = htons(6677);

	int nResultB = connect(soConnect, 
					(SOCKADDR *)&stAddress, sizeof(stAddress));
	if (nResultB == SOCKET_ERROR)
	{
		return false;
	}

	// 保存Socket
	m_Socket = soConnect;

	// 创建接受服务器消息线程
	unsigned long  nThreadid= 0 ;
	CreateThread(NULL, 0, 
		(LPTHREAD_START_ROUTINE)WinSocket::WinSockRecvInfoFromServer ,
		&m_Socket, 0, &nThreadid);

	return true;
}

// 接受服务器数据
bool WinSocket::WinSockRecvInfoFromServer(void* pParam)
{
	if (NULL == pParam)
	{
		return false;
	}

	SOCKET* socket_c = (SOCKET*)pParam;
	if (NULL == socket_c)
	{
		return false;
	}

	while (true)
	{
		char serverinfo[512] = {0};
		recv(*socket_c, serverinfo, 512, 0);
		TypeVector tyve(serverinfo);
		if (strcmp(tyve.GetString(0), MSG_SERVER_TO_CLIENT_SUCCESS_LOGININ) == 0)
		{
			// 登录信息
			WinHelper::WinHelperShowWhichWin(WIN_DATA);
		}
		else if (strcmp(tyve.GetString(0), MSG_SERVER_TO_CLIENT_SUCCESS_SIGNIN) == 0)
		{
			// 登录信息
			WinHelper::WinHelperShowWhichWin(WIN_LOGIN);
		}
		else if (strcmp(tyve.GetString(0), MSG_SERVER_TO_CLIENT_WORKDATA) == 0)
		{
			// 登录信息
			WinHelper::WinHelperShowWhichWin(WIN_LOGIN);
		}
	}

	return true;
}

// 给服务器发送消息
bool WinSocket::WinSockSendInfoToServer(const char* sInfo)
{
	if (m_Socket == INVALID_SOCKET || NULL == sInfo ||
		strcmp(sInfo, "") == 0)
	{
		return false;
	}

	int nVlaue = send(m_Socket, sInfo, strlen(sInfo), 0);

	return true;
}