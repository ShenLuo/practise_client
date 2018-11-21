// 功能：加班界面管理
// 作者：罗深
// 时间：2017/09/02

#include "WinHelper.h"
#include "resource.h"
#include "WorkClient.h"
#include "WinSocket.h"
#include <string>


// 登录界面句柄
HWND WinHelper::m_pLoginWin = NULL; 

// 注册界面句柄
HWND WinHelper::m_pSigninWin = NULL;

// 数据界面句柄
HWND WinHelper::m_pDatanWin = NULL;

	// 初始化客户端界面
bool WinHelper::WinHelperInitWin(HINSTANCE hInstance)
{
	// 创建客户端界面
	m_pLoginWin =  CreateDialog(hInstance,  
		MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProcLogin);
	m_pSigninWin =  CreateDialog(hInstance,  
		MAKEINTRESOURCE(IDD_DIALOG2), NULL, DialogProcSignin);
	m_pDatanWin =  CreateDialog(hInstance,  
		MAKEINTRESOURCE(IDD_DIALOG3), NULL, DialogProcData);
	if (NULL == m_pLoginWin || NULL == m_pSigninWin || NULL == m_pDatanWin)
	{
		return false;
	}

	// 隐藏所有界面
	WinHelperShowWhichWin(WIN_NULL);

	return true;
}

// 显示某个子界面
bool WinHelper::WinHelperShowWhichWin(int nWhich)
{
	// 隐藏所有界面
	ShowWindow(m_pLoginWin, SW_HIDE);
	ShowWindow(m_pSigninWin, SW_HIDE);
	ShowWindow(m_pDatanWin, SW_HIDE);

	HWND temwnd = NULL;

	if (nWhich == WIN_LOGIN)
	{
		// 登录界面
		temwnd = m_pLoginWin;
	}
	else if (nWhich == WIN_SIGNIN)
	{
		// 注册界面
		temwnd = m_pSigninWin;
	}
	else if (nWhich == WIN_DATA)
	{
		// 数据界面
		temwnd = m_pDatanWin;
	}

	if (NULL == temwnd)
	{
		return false;
	}

	// 显示界面
	ShowWindow(temwnd, SW_SHOWNORMAL);

	// 响应界面消息
	MSG nMsg={0};
	while (GetMessage(&nMsg, temwnd, 0, 0))
	{
		int nMsgID = nMsg.message;
		if (0 == nMsgID)
		{
			break;
		}

		TranslateMessage(&nMsg);
		DispatchMessage(&nMsg);
	}
	
	return true;
}

// 登录界面处理函数
int CALLBACK  WinHelper::DialogProcLogin(
	_In_ HWND   hwndDlg,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam)
{
	if (hwndDlg != m_pLoginWin)
	{
		return 0;
	}
		
	switch (uMsg)
	{
	case WM_DESTROY:
		{
			// 关闭界面
			PostQuitMessage(WM_QUIT);
		}

		break;
	case WM_COMMAND:
		{
			// 操作界面
			if (LOWORD(wParam) == IDC_BUTTON1)
			{
				// 登录按钮
				std::string sLogin = MSG_CLIENT_TO_SERVER_LOGININ;
				sLogin += "|";

				HWND hedit_user = GetDlgItem(m_pLoginWin, IDC_EDIT1);
				HWND hedit_keyword = GetDlgItem(m_pLoginWin, IDC_EDIT2);

				char user[16] = {0};
				char key[16] = {0};

				GetWindowText(hedit_user, user, sizeof(user));
				GetWindowText(hedit_keyword, key, sizeof(key));

				sLogin += user;
				sLogin += "|";
				sLogin += key;
				
				WinSocket::WinSockSendInfoToServer(sLogin.c_str());
			}
			else if (LOWORD(wParam) == IDC_BUTTON2)
			{
				// 注册按钮
				WinHelperShowWhichWin(WIN_SIGNIN);
			}
		}

		break;
	default:
		{
			// 默认处理
			DefWindowProc(hwndDlg,uMsg,wParam,lParam);
		}

		break;
	}

	return 0;
}

// 注册界面处理函数
int CALLBACK WinHelper::DialogProcSignin(
	_In_ HWND   hwndDlg,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam)
{
	if (hwndDlg != m_pSigninWin)
	{
		return 0;
	}

	switch (uMsg)
	{
	case WM_DESTROY:
		{
			// 关闭界面
			PostQuitMessage(WM_QUIT);
		}

		break;
	case WM_COMMAND:
		{
			// 操作界面
			if (LOWORD(wParam) == IDC_BUTTON1)
			{
				// 登录按钮
				WinHelperShowWhichWin(WIN_LOGIN);
			}
			else if (LOWORD(wParam) == IDC_BUTTON2)
			{
				// 注册按钮
				// 登录按钮
				std::string sLogin = MSG_CLIENT_TO_SERVER_SIGNIN;
				sLogin += "|";

				HWND hedit_user = GetDlgItem(m_pLoginWin, IDC_EDIT1);
				HWND hedit_keyword = GetDlgItem(m_pLoginWin, IDC_EDIT2);

				char user[16] = {0};
				char key[16] = {0};

				GetWindowText(hedit_user, user, sizeof(user));
				GetWindowText(hedit_keyword, key, sizeof(key));

				sLogin += user;
				sLogin += "|";
				sLogin += key;

				WinSocket::WinSockSendInfoToServer(sLogin.c_str());
			}
		}

		break;
	default:
		{
			// 默认处理
			DefWindowProc(hwndDlg,uMsg,wParam,lParam);
		}

		break;
	}

	return 0;
}

// 数据界面处理函数
int CALLBACK WinHelper::DialogProcData(
	_In_ HWND   hwndDlg,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam)
{
	if (hwndDlg != m_pDatanWin)
	{
		return 0;
	}

	switch (uMsg)
	{
	case WM_DESTROY:
		{
			// 关闭界面
			PostQuitMessage(WM_QUIT);
		}

		break;
	case WM_COMMAND:
		{
			// 操作界面
			if (LOWORD(wParam) == IDC_BUTTON1)
			{
				// 登录按钮

			}
			else if (LOWORD(wParam) == IDC_BUTTON2)
			{
				// 注册按钮
			}
		}

		break;
	default:
		{
			// 默认处理
			DefWindowProc(hwndDlg,uMsg,wParam,lParam);
		}

		break;
	}

	return 0;
}
