// 功能：加班界面管理
// 作者：罗深
// 时间：2017/09/02

#ifndef WIN_HELPER_H_
#define WIN_HELPER_H_

#include <windows.h>

class WinHelper
{
public:
	// 初始化客户端界面
	static bool WinHelperInitWin(HINSTANCE hInstance);

	// 显示某个子界面
	static bool WinHelperShowWhichWin(int nWhich);

	// 登录界面处理函数
	static int CALLBACK  DialogProcLogin(
			_In_ HWND   hwndDlg,
			_In_ UINT   uMsg,
			_In_ WPARAM wParam,
			_In_ LPARAM lParam);

	// 注册界面处理函数
	static int CALLBACK DialogProcSignin(
			_In_ HWND   hwndDlg,
			_In_ UINT   uMsg,
			_In_ WPARAM wParam,
			_In_ LPARAM lParam);

	// 数据界面处理函数
	static int CALLBACK DialogProcData(
			_In_ HWND   hwndDlg,
			_In_ UINT   uMsg,
			_In_ WPARAM wParam,
			_In_ LPARAM lParam);

public:
	// 登录界面句柄
	static HWND m_pLoginWin;

	// 注册界面句柄
	static HWND m_pSigninWin;

	// 数据界面句柄
	static HWND m_pDatanWin;

};

#endif // WIN_HELPER_H_