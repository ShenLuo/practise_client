// ���ܣ��Ӱ�ͨ�Ź���
// ���ߣ�����
// ʱ�䣺2017/09/02

#ifndef WIN_SOCKET__MY_H_
#define WIN_SOCKET__MY_H_

//#include <winsock2.h>
#include <windows.h>

class WinSocket
{
public:
	// �����������������
	static bool WinSocketInitAndConnect();

	// ��������������Ϣ
	static bool WinSockSendInfoToServer(const char* sInfo);

	// ���ܷ���������
	static bool WinSockRecvInfoFromServer(void* pParam);

public:
	// �ͻ���ͨ�Ŷ���
	static SOCKET m_Socket;
};

#endif // WIN_SOCKET__MY_H_