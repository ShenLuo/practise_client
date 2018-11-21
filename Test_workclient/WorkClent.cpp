// 功能：加班管理客户端
// 作者：罗深
// 时间：2017/09/02

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
	// 创建网络连接
	WinSocket::WinSocketInitAndConnect();

	// 开启客户端界面
	WinHelper::WinHelperInitWin(hInstance);
	WinHelper::WinHelperShowWhichWin(WIN_LOGIN);

	return 0;
}