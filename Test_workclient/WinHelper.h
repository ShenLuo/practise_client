// ���ܣ��Ӱ�������
// ���ߣ�����
// ʱ�䣺2017/09/02

#ifndef WIN_HELPER_H_
#define WIN_HELPER_H_

#include <windows.h>

class WinHelper
{
public:
	// ��ʼ���ͻ��˽���
	static bool WinHelperInitWin(HINSTANCE hInstance);

	// ��ʾĳ���ӽ���
	static bool WinHelperShowWhichWin(int nWhich);

	// ��¼���洦����
	static int CALLBACK  DialogProcLogin(
			_In_ HWND   hwndDlg,
			_In_ UINT   uMsg,
			_In_ WPARAM wParam,
			_In_ LPARAM lParam);

	// ע����洦����
	static int CALLBACK DialogProcSignin(
			_In_ HWND   hwndDlg,
			_In_ UINT   uMsg,
			_In_ WPARAM wParam,
			_In_ LPARAM lParam);

	// ���ݽ��洦����
	static int CALLBACK DialogProcData(
			_In_ HWND   hwndDlg,
			_In_ UINT   uMsg,
			_In_ WPARAM wParam,
			_In_ LPARAM lParam);

public:
	// ��¼������
	static HWND m_pLoginWin;

	// ע�������
	static HWND m_pSigninWin;

	// ���ݽ�����
	static HWND m_pDatanWin;

};

#endif // WIN_HELPER_H_