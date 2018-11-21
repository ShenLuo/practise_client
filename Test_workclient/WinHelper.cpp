// ���ܣ��Ӱ�������
// ���ߣ�����
// ʱ�䣺2017/09/02

#include "WinHelper.h"
#include "resource.h"
#include "WorkClient.h"
#include "WinSocket.h"
#include <string>


// ��¼������
HWND WinHelper::m_pLoginWin = NULL; 

// ע�������
HWND WinHelper::m_pSigninWin = NULL;

// ���ݽ�����
HWND WinHelper::m_pDatanWin = NULL;

	// ��ʼ���ͻ��˽���
bool WinHelper::WinHelperInitWin(HINSTANCE hInstance)
{
	// �����ͻ��˽���
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

	// �������н���
	WinHelperShowWhichWin(WIN_NULL);

	return true;
}

// ��ʾĳ���ӽ���
bool WinHelper::WinHelperShowWhichWin(int nWhich)
{
	// �������н���
	ShowWindow(m_pLoginWin, SW_HIDE);
	ShowWindow(m_pSigninWin, SW_HIDE);
	ShowWindow(m_pDatanWin, SW_HIDE);

	HWND temwnd = NULL;

	if (nWhich == WIN_LOGIN)
	{
		// ��¼����
		temwnd = m_pLoginWin;
	}
	else if (nWhich == WIN_SIGNIN)
	{
		// ע�����
		temwnd = m_pSigninWin;
	}
	else if (nWhich == WIN_DATA)
	{
		// ���ݽ���
		temwnd = m_pDatanWin;
	}

	if (NULL == temwnd)
	{
		return false;
	}

	// ��ʾ����
	ShowWindow(temwnd, SW_SHOWNORMAL);

	// ��Ӧ������Ϣ
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

// ��¼���洦����
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
			// �رս���
			PostQuitMessage(WM_QUIT);
		}

		break;
	case WM_COMMAND:
		{
			// ��������
			if (LOWORD(wParam) == IDC_BUTTON1)
			{
				// ��¼��ť
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
				// ע�ᰴť
				WinHelperShowWhichWin(WIN_SIGNIN);
			}
		}

		break;
	default:
		{
			// Ĭ�ϴ���
			DefWindowProc(hwndDlg,uMsg,wParam,lParam);
		}

		break;
	}

	return 0;
}

// ע����洦����
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
			// �رս���
			PostQuitMessage(WM_QUIT);
		}

		break;
	case WM_COMMAND:
		{
			// ��������
			if (LOWORD(wParam) == IDC_BUTTON1)
			{
				// ��¼��ť
				WinHelperShowWhichWin(WIN_LOGIN);
			}
			else if (LOWORD(wParam) == IDC_BUTTON2)
			{
				// ע�ᰴť
				// ��¼��ť
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
			// Ĭ�ϴ���
			DefWindowProc(hwndDlg,uMsg,wParam,lParam);
		}

		break;
	}

	return 0;
}

// ���ݽ��洦����
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
			// �رս���
			PostQuitMessage(WM_QUIT);
		}

		break;
	case WM_COMMAND:
		{
			// ��������
			if (LOWORD(wParam) == IDC_BUTTON1)
			{
				// ��¼��ť

			}
			else if (LOWORD(wParam) == IDC_BUTTON2)
			{
				// ע�ᰴť
			}
		}

		break;
	default:
		{
			// Ĭ�ϴ���
			DefWindowProc(hwndDlg,uMsg,wParam,lParam);
		}

		break;
	}

	return 0;
}
