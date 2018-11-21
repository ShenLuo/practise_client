// ���ܣ��Ӱ�ͨ�Ź���
// ���ߣ�����
// ʱ�䣺2017/09/02

#include "WinSocket.h"
#include "CarGpsUtil.h"
#include "WorkClient.h"
#include "WinHelper.h"
#include <windows.h>

SOCKET WinSocket::m_Socket = INVALID_SOCKET;

// �����������������
bool WinSocket::WinSocketInitAndConnect()
{
	// �鿴����汾
	WSADATA wsData;
	int nResult = WSAStartup(MAKEWORD(2,2), &wsData);
	if (NO_ERROR != nResult)
	{
		return false;
	}

	// ����Socket����
	SOCKET soConnect= INVALID_SOCKET;
	soConnect = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (soConnect == INVALID_SOCKET)
	{
		return false;
	}
	
	// ����Socket��Ŀ��
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

	// ����Socket
	m_Socket = soConnect;

	// �������ܷ�������Ϣ�߳�
	unsigned long  nThreadid= 0 ;
	CreateThread(NULL, 0, 
		(LPTHREAD_START_ROUTINE)WinSocket::WinSockRecvInfoFromServer ,
		&m_Socket, 0, &nThreadid);

	return true;
}

// ���ܷ���������
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
			// ��¼��Ϣ
			WinHelper::WinHelperShowWhichWin(WIN_DATA);
		}
		else if (strcmp(tyve.GetString(0), MSG_SERVER_TO_CLIENT_SUCCESS_SIGNIN) == 0)
		{
			// ��¼��Ϣ
			WinHelper::WinHelperShowWhichWin(WIN_LOGIN);
		}
		else if (strcmp(tyve.GetString(0), MSG_SERVER_TO_CLIENT_WORKDATA) == 0)
		{
			// ��¼��Ϣ
			WinHelper::WinHelperShowWhichWin(WIN_LOGIN);
		}
	}

	return true;
}

// ��������������Ϣ
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