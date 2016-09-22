#pragma once
#include <Windows.h>
class CELLWinApp
{
protected:
	HWND _hWnd;//就是一个指针，窗口句柄
	HINSTANCE _hInst;
public:
	CELLWinApp(HINSTANCE hInstance)
		:_hInst(hInstance)
	{
		//1.注册一个窗口类
		WNDCLASSEX wndClass;
		memset(&wndClass,0,sizeof(wndClass));
		wndClass.cbSize = sizeof(wndClass);
		wndClass.style = CS_VREDRAW | CS_HREDRAW | CS_OWNDC;
		wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		wndClass.hCursor = ::LoadCursor(hInstance,IDC_ARROW);
	
		wndClass.lpszClassName = "CELLWinApp";
		wndClass.lpfnWndProc = wndProc;
		wndClass.hIcon = 0;
		wndClass.lpszMenuName = 0;

		RegisterClassEx(&wndClass);
	}
	virtual ~CELLWinApp(void)
	{
		UnregisterClass("CELLWinApp",_hInst);
	}
public:
	static LRESULT CALLBACK wndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
	{
		switch (msg)
		{
		case WM_CREATE:
			break;
		case WM_DESTROY:
		case WM_CLEAR:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd,msg,wParam,lParam);
		}
		return S_OK;
	}
	int main(int width, int height)
	{
		// 创建窗口
		_hWnd = CreateWindow("CELLWinApp","CELLWinApp",WS_OVERLAPPEDWINDOW,0,0,width,height,0,0,_hInst,this);
		if (_hWnd == 0)
		{
			return 0;
		}
		// 更新显示窗口
		UpdateWindow(_hWnd);
		// 显示
		ShowWindow(_hWnd, SW_NORMAL);

		// 消息循环
		MSG msg = {0};

		while (GetMessage(&msg, 0, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return 0;
	}
};