// ���ܣ��Ӱ����ͻ���
// ���ߣ�����
// ʱ�䣺2017/09/02

#include "resource.h"
#include "WinHelper.h"
#include "WorkClient.h"
#include "WinSocket.h"
#include <stdio.h>
#include <windows.h>


int _stdcall wWinMain(HINSTANCE hInstance, 
			 HINSTANCE hPrevInstance, 
			 LPWSTR lpCmdLine,
			 int nShowCmd )
{
	// ������������
	WinSocket::WinSocketInitAndConnect();

	// �����ͻ��˽���
	WinHelper::WinHelperInitWin(hInstance);
	WinHelper::WinHelperShowWhichWin(WIN_LOGIN);

	return 0;
}