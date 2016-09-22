#pragma once
#include <tchar.h>
#include <Windows.h>

class CELLWinApp{

public:
	HINSTANCE _hInstance;
	HWND _hWnd;
public:
	CELLWinApp(HINSTANCE hInstance)
		:_hInstance(hInstance)
	{
		WNDCLASSEX winClass;
		winClass.lpszClassName = _T("CELLWinApp");
		winClass.cbSize		   = sizeof(winClass);
		winClass.style		   = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		winClass.lpfnWndProc   = wndProc;
		winClass.hInstance     = hInstance;
		winClass.hIcon		   = 0;
		winClass.hIconSm	   = 0;
		winClass.hCursor       = LoadCursor(hInstance,IDC_ARROW);
		winClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		winClass.lpszMenuName  = NULL;
		winClass.cbClsExtra    = 0;
		winClass.cbWndExtra    = 0;
		RegisterClassEx(&winClass);
	}
	virtual ~CELLWinApp()
	{
		UnregisterClass(_T("CELLWinApp"),_hInstance);
	}
public:
	static LRESULT CALLBACK wndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
	{
		CELLWinApp * pThis = (CELLWinApp*)GetWindowLong(hWnd,GWL_USERDATA);
		if (pThis)
		{
			return pThis->onEvent(hWnd, msg, wParam, lParam);
		}
		if (WM_CREATE == msg)
		{
			CREATESTRUCT * pCreate = (CREATESTRUCT*)lParam;
			SetWindowLong(hWnd,GWL_USERDATA,(DWORD_PTR)pCreate->lpCreateParams);
		}
		return DefWindowProc(hWnd,msg,wParam,lParam);
	}

public:
	virtual LRESULT onEvent(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_CLOSE:
		case WM_DESTROY:
		{
			::PostQuitMessage(0);
		}
		break;
		case WM_MOUSEMOVE:
			break;
		case WM_LBUTTONDOWN:
			break;
		case WM_LBUTTONUP:
			break;
		case WM_RBUTTONDOWN:
			break;
		case WM_RBUTTONUP:
			break;
		case WM_KEYDOWN:
		{
			switch (wParam)
			{
			case VK_LEFT:
				break;
			default:
				break;
			}
		}
		break;
		case WM_KEYUP:
			break;
		default:
			return  DefWindowProc(hWnd, msg, wParam, lParam);
		}
		return  S_OK;
	}
	int main(int width, int height)
	{
		_hWnd = CreateWindowEx( NULL,
							    _T("CELLWinApp"),
							    _T("CELLWinApp"), 
								WS_OVERLAPPEDWINDOW,
								0,
								0,
								width,
								height,
								0,
								0,
								_hInstance,
								this
								);
		if (_hWnd == 0)
		{
			return -1;
		}

		UpdateWindow(_hWnd);
		ShowWindow(_hWnd, SW_MAXIMIZE);

		MSG msg = {0};
		while (msg.message != WM_QUIT)
		{
			if (msg.message == WM_DESTROY ||
				msg.message == WM_CLOSE)
			{
				break;
			}
			if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				Sleep(1);
			}
		}
		return 0;
	}
};