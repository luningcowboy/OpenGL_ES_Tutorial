#include <tchar.h>
#include <Windows.h>
#include "CELLWinApp.hpp"
int CALLBACK _tWinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInst,
	LPTSTR lpCmdLine,
	int nShowCmd)
{
	CELLWinApp app(hInstance);
	return app.main(800, 600);
}