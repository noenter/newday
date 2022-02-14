#include <Windows.h>
#include "start.h"



POINT CurPos;
int x, y;

string to_string(int n)
{
	char buf[40];
	sprintf(buf, "%d", n);
	return buf;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {

	WNDCLASS SoftwareMainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(NULL, IDI_QUESTION),
		L"Mainwndclass", SoftwareMainProcedure);

	if (!RegisterClassW(&SoftwareMainClass)) { return -1; }
	MSG SoftwareMainMessage = { 0 };

	CreateWindowEx(WS_EX_TOPMOST, L"MainWndClass", L"First C++ window", WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_BORDER , 824, 0, 200, 300, NULL, NULL, NULL, NULL);

	while (GetMessage(&SoftwareMainMessage, NULL, NULL, NULL)) {
		TranslateMessage(&SoftwareMainMessage);
		DispatchMessage(&SoftwareMainMessage);
	}
	return 0;
}

WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hinst, HICON Icon, LPCWSTR Name, WNDPROC Procedure) {
		WNDCLASS NWC = { 0 };

		NWC.hIcon = Icon;
		NWC.hCursor = Cursor;
		NWC.hInstance = hinst;
		NWC.lpszClassName = Name;
		NWC.hbrBackground = BGColor;
		NWC.lpfnWndProc = Procedure;

		return NWC;
}
	
LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {

	GetCursorPos(&CurPos);
	x = (int)CurPos.x;
	y = (int)CurPos.y;
	SetWindowTextA(hWnd, a);

	switch (msg) {
	case WM_COMMAND:
		switch (wp) {
		case OnButtonR1Clicked:
			Sleep(500);
			turnright(1);
			break;
		case OnButtonR10Clicked:
			Sleep(500);
			turnright(10);
			break;
		case OnButtonR100Clicked:
			Sleep(500);
			turnright(100);
			break;
		case OnButtonL1Clicked:
			Sleep(500);
			turnleft(1);
			break;
		case OnButtonL10Clicked:
			Sleep(500);
			turnleft(10);
			break;
		case OnButtonL100Clicked:
			Sleep(500);
			turnleft(100);
			break;
		default: break;
		}
		break;
	case WM_CREATE:
		MainWndAddWidgets(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default: return DefWindowProc(hWnd, msg, wp, lp);
	}
}

void MainWndAddWidgets(HWND hWnd) {

	CreateWindowA("static", "Hello Window!", WS_VISIBLE | WS_CHILD, 5, 5, 490, 20, hWnd, NULL, NULL, NULL, NULL);

	CreateWindowA("edit", "dfgdfgdgdg", WS_VISIBLE | WS_CHILD, 5, 30, 490, 20, hWnd, NULL, NULL, NULL, NULL);

//	CreateWindowA("button", "Click me!", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 60, 120, 30, hWnd, (HMENU)OnButtonClicked, NULL, NULL, NULL);
	CreateWindowA("button", "R-1", WS_VISIBLE | WS_CHILD | ES_CENTER, 0, 60, 32, 18, hWnd, (HMENU)OnButtonR1Clicked, NULL, NULL, NULL);
	CreateWindowA("button", "R-10", WS_VISIBLE | WS_CHILD | ES_CENTER, 32, 60, 40, 18, hWnd, (HMENU)OnButtonR10Clicked, NULL, NULL, NULL);
	CreateWindowA("button", "R-100", WS_VISIBLE | WS_CHILD | ES_CENTER, 72, 60, 48, 18, hWnd, (HMENU)OnButtonR100Clicked, NULL, NULL, NULL);

	CreateWindowA("button", "L-1", WS_VISIBLE | WS_CHILD | ES_CENTER, 0, 80, 32, 18, hWnd, (HMENU)OnButtonL1Clicked, NULL, NULL, NULL);
	CreateWindowA("button", "L-10", WS_VISIBLE | WS_CHILD | ES_CENTER, 32, 80, 40, 18, hWnd, (HMENU)OnButtonL10Clicked, NULL, NULL, NULL);
	CreateWindowA("button", "L-100", WS_VISIBLE | WS_CHILD | ES_CENTER, 72, 80, 48, 18, hWnd, (HMENU)OnButtonL100Clicked, NULL, NULL, NULL);


}