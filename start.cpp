#include <Windows.h>
#include "start.h"
#include <stdlib.h>
#include <string>


POINT CurPos;
int x, y;
void GetCurPos() {
	GetCursorPos(&CurPos);
	x = (int)CurPos.x;
	y = (int)CurPos.y;
	SetWindowTextA(hStaticControl, ("X-" + std::to_string(x) + " Y-" + std::to_string(y)).c_str());
}


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
	WNDCLASS SoftwareMainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(NULL, IDI_QUESTION),
		L"Mainwndclass", SoftwareMainProcedure);

	if (!RegisterClassW(&SoftwareMainClass)) { return -1; }
	MSG SoftwareMainMessage = { 0 };

	CreateWindowEx(WS_EX_TOPMOST, L"MainWndClass", L"First C++ window", WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_BORDER , 824, 0, 200, 300, NULL, NULL, NULL, NULL);
	
	while (GetMessage(&SoftwareMainMessage, NULL, NULL, NULL))
	{
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
	
LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{	
	switch (msg)
	{

	case WM_COMMAND:
		switch (wp) {
		case OnButtonR1Clicked:
			SetCursorPos(x, 180);
			mouse_event(MOUSEEVENTF_RIGHTDOWN, x, 180, 0, 0);
			Sleep(10);
			mouse_event(MOUSEEVENTF_RIGHTUP, x, 180, 0, 0);
			Sleep(500);
			turnright(1);
			break;
		case OnButtonR10Clicked:
			SetCursorPos(x, 180);
			mouse_event(MOUSEEVENTF_RIGHTDOWN, x, 180, 0, 0);
			Sleep(10);
			mouse_event(MOUSEEVENTF_RIGHTUP, x, 180, 0, 0);
			Sleep(500);
			turnright(10);
			break;
		case OnButtonR100Clicked:
			SetCursorPos(x, 180);
			mouse_event(MOUSEEVENTF_RIGHTDOWN, x, 180, 0, 0);
			Sleep(10);
			mouse_event(MOUSEEVENTF_RIGHTUP, x, 180, 0, 0);
			Sleep(500);
			turnright(100);
			break;
		case OnButtonL1Clicked:
			SetCursorPos(x, 180);
			mouse_event(MOUSEEVENTF_RIGHTDOWN, x, 180, 0, 0);
			Sleep(10);
			mouse_event(MOUSEEVENTF_RIGHTUP, x, 180, 0, 0);
			Sleep(500);
			turnleft(1);
			break;
		case OnButtonL10Clicked:
			SetCursorPos(x, 180);
			mouse_event(MOUSEEVENTF_RIGHTDOWN, x, 180, 0, 0);
			Sleep(10);
			mouse_event(MOUSEEVENTF_RIGHTUP, x, 180, 0, 0);
			Sleep(500);
			turnleft(10);
			break;
		case OnButtonL100Clicked:
			SetCursorPos(x, 180);
			mouse_event(MOUSEEVENTF_RIGHTDOWN, x, 180, 0, 0);
			Sleep(10);
			mouse_event(MOUSEEVENTF_RIGHTUP, x, 180, 0, 0);
			Sleep(500);
			turnleft(100);
			break;
		case OnButtonStartGUIClicked:
			stgui = false;
			break;
		case OnButtonStopGUIClicked:
			isTreading = false;
			stgui = true;
			Sleep(500);
			CloseHandle(thread2);
			ExitThread(0);
			break;

		default: break;
		}
		break;
	case WM_CREATE:
		MainWndAddWidgets(hWnd);
		thread = CreateThread(NULL, 0, thread2, NULL, 0, NULL);
		break;
	case WM_DESTROY:
		isTreading = false;
		stgui = true;
		CloseHandle(thread2);
		ExitProcess(0);
		PostQuitMessage(0);

		break;
	default: return DefWindowProc(hWnd, msg, wp, lp);
	}
}

void MainWndAddWidgets(HWND hWnd)
{
	// статик поля
	hStaticControl = CreateWindowA("static", "Info 1", WS_VISIBLE | WS_CHILD, 1, 1, 190, 20, hWnd, NULL, NULL, NULL);
	hStaticControl2 = CreateWindowA("static", "Info 2", WS_VISIBLE | WS_CHILD, 1, 21, 190, 20, hWnd, NULL, NULL, NULL);
	hStaticControl3 = CreateWindowA("static", "Info 3", WS_VISIBLE | WS_CHILD, 1, 42, 190, 20, hWnd, NULL, NULL, NULL);

	//эдит поля
	hEditControl = CreateWindowA("edit", "dfgdfgdgdg", WS_VISIBLE | WS_CHILD, 1, 170, 190, 20, hWnd, NULL, NULL, NULL);

//	CreateWindowA("button", "Click me!", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 60, 120, 30, hWnd, (HMENU)OnButtonClicked, NULL, NULL, NULL);
	CreateWindowA("button", "R-1", WS_VISIBLE | WS_CHILD | ES_CENTER, 0, 60, 32, 18, hWnd, (HMENU)OnButtonR1Clicked, NULL, NULL);
	CreateWindowA("button", "R-10", WS_VISIBLE | WS_CHILD | ES_CENTER, 32, 60, 40, 18, hWnd, (HMENU)OnButtonR10Clicked, NULL, NULL);
	CreateWindowA("button", "R-100", WS_VISIBLE | WS_CHILD | ES_CENTER, 72, 60, 48, 18, hWnd, (HMENU)OnButtonR100Clicked, NULL, NULL);

	CreateWindowA("button", "L-1", WS_VISIBLE | WS_CHILD | ES_CENTER, 0, 80, 32, 18, hWnd, (HMENU)OnButtonL1Clicked, NULL, NULL);
	CreateWindowA("button", "L-10", WS_VISIBLE | WS_CHILD | ES_CENTER, 32, 80, 40, 18, hWnd, (HMENU)OnButtonL10Clicked, NULL, NULL);
	CreateWindowA("button", "L-100", WS_VISIBLE | WS_CHILD | ES_CENTER, 72, 80, 48, 18, hWnd, (HMENU)OnButtonL100Clicked, NULL, NULL);

	CreateWindowA("button", "StartGUI", WS_VISIBLE | WS_CHILD | ES_CENTER, 10, 110, 60, 18, hWnd, (HMENU)OnButtonStartGUIClicked, NULL, NULL);
	CreateWindowA("button", "StopGUI", WS_VISIBLE | WS_CHILD | ES_CENTER, 10, 150, 60, 18, hWnd, (HMENU)OnButtonStopGUIClicked, NULL, NULL);


}