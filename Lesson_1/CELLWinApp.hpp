#pragma once
#include <Windows.h>
class CELLWinApp
{
protected:
	HWND _hWnd;//����һ��ָ�룬���ھ��
	HINSTANCE _hInst;
public:
	CELLWinApp(HINSTANCE hInstance)
		:_hInst(hInstance)
	{
		//1.ע��һ��������
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
		// ��������
		_hWnd = CreateWindow("CELLWinApp","CELLWinApp",WS_OVERLAPPEDWINDOW,0,0,width,height,0,0,_hInst,this);
		if (_hWnd == 0)
		{
			return 0;
		}
		// ������ʾ����
		UpdateWindow(_hWnd);
		// ��ʾ
		ShowWindow(_hWnd, SW_NORMAL);

		// ��Ϣѭ��
		MSG msg = {0};

		while (GetMessage(&msg, 0, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return 0;
	}
};