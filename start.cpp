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

	CreateWindowEx(WS_EX_TOPMOST, L"MainWndClass", L"First C++ window", WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_BORDER , 0, 200, 200, 300, NULL, NULL, NULL, NULL);
	
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
			SetCursorPos(xc, yc);
			mouse_event(MOUSEEVENTF_RIGHTDOWN, xc, yc, 0, 0);
			Sleep(10);
			mouse_event(MOUSEEVENTF_RIGHTUP, xc, yc, 0, 0);
			Sleep(500);
			turnright(1);
			break;
		case OnButtonR10Clicked:
			SetCursorPos(xc, yc);
			mouse_event(MOUSEEVENTF_RIGHTDOWN, xc, yc, 0, 0);
			Sleep(10);
			mouse_event(MOUSEEVENTF_RIGHTUP, xc, yc, 0, 0);
			Sleep(500);
			turnright(10);
			break;
		case OnButtonR100Clicked:
			SetCursorPos(xc, yc);
			mouse_event(MOUSEEVENTF_RIGHTDOWN, xc, yc, 0, 0);
			Sleep(10);
			mouse_event(MOUSEEVENTF_RIGHTUP, xc, yc, 0, 0);
			Sleep(500);
			turnright(100);
			break;
		case OnButtonL1Clicked:
			SetCursorPos(xc, yc);
			mouse_event(MOUSEEVENTF_RIGHTDOWN, xc, yc, 0, 0);
			Sleep(10);
			mouse_event(MOUSEEVENTF_RIGHTUP, xc, yc, 0, 0);
			Sleep(500);
			turnleft(1);
			break;
		case OnButtonL10Clicked:
			SetCursorPos(xc, yc);
			mouse_event(MOUSEEVENTF_RIGHTDOWN, xc, yc, 0, 0);
			Sleep(10);
			mouse_event(MOUSEEVENTF_RIGHTUP, xc, yc, 0, 0);
			Sleep(500);
			turnleft(10);
			break;
		case OnButtonL100Clicked:
			SetCursorPos(xc, yc);
			mouse_event(MOUSEEVENTF_RIGHTDOWN, xc, yc, 0, 0);
			Sleep(10);
			mouse_event(MOUSEEVENTF_RIGHTUP, xc, yc, 0, 0);
			Sleep(500);
			turnleft(100);
			break;
		case OnButtonStartGUIClicked:
			ResumeThread(thread);
			break;
		case OnButtonPauseGUIClicked:
			if (pause) { SuspendThread(thread); }
			else{ResumeThread(thread);}
			!pause;
			break;

		case OnButtonStopGUIClicked:
			isTreading = false;
			TerminateThread(thread, 0);
			break;

		default: break;
		}
		break;
	case WM_CREATE:
		MainWndAddWidgets(hWnd);
		thread = CreateThread(NULL, 0, thread2, NULL, CREATE_SUSPENDED, NULL);
		break;
	case WM_DESTROY:
		isTreading = false;
		TerminateThread(thread, 0);
		PostQuitMessage(0);

		break;
	default: return DefWindowProc(hWnd, msg, wp, lp);
	}
}

void MainWndAddWidgets(HWND hWnd)
{
	// статик поля
	hStaticControl = CreateWindowA("static", "Info 1", WS_VISIBLE | WS_CHILD, 1, 1, 95, 20, hWnd, NULL, NULL, NULL);
	hStaticControl2 = CreateWindowA("static", "Info 2", WS_VISIBLE | WS_CHILD, 100, 1, 95, 20, hWnd, NULL, NULL, NULL);
	hStaticControl3 = CreateWindowA("static", "Info 3", WS_VISIBLE | WS_CHILD, 1, 42, 190, 20, hWnd, NULL, NULL, NULL);

	//эдит поля
	hEditControl = CreateWindowA("edit", "dfgdfgdgdg", WS_VISIBLE | WS_CHILD, 1, 170, 190, 20, hWnd, NULL, NULL, NULL);

	CreateWindowA("button", "R-1", WS_VISIBLE | WS_CHILD | ES_CENTER, 0, 160, 32, 18, hWnd, (HMENU)OnButtonR1Clicked, NULL, NULL);
	CreateWindowA("button", "R-10", WS_VISIBLE | WS_CHILD | ES_CENTER, 32, 160, 40, 18, hWnd, (HMENU)OnButtonR10Clicked, NULL, NULL);
	CreateWindowA("button", "R-100", WS_VISIBLE | WS_CHILD | ES_CENTER, 72, 160, 48, 18, hWnd, (HMENU)OnButtonR100Clicked, NULL, NULL);

	CreateWindowA("button", "L-1", WS_VISIBLE | WS_CHILD | ES_CENTER, 0, 180, 32, 18, hWnd, (HMENU)OnButtonL1Clicked, NULL, NULL);
	CreateWindowA("button", "L-10", WS_VISIBLE | WS_CHILD | ES_CENTER, 32, 180, 40, 18, hWnd, (HMENU)OnButtonL10Clicked, NULL, NULL);
	CreateWindowA("button", "L-100", WS_VISIBLE | WS_CHILD | ES_CENTER, 72, 180, 48, 18, hWnd, (HMENU)OnButtonL100Clicked, NULL, NULL);

	CreateWindowA("button", "Start", WS_VISIBLE | WS_CHILD | ES_CENTER, 0, 70, 58, 18, hWnd, (HMENU)OnButtonStartGUIClicked, NULL, NULL);
	CreateWindowA("button", "Stop", WS_VISIBLE | WS_CHILD | ES_CENTER, 60, 70, 58, 18, hWnd, (HMENU)OnButtonStopGUIClicked, NULL, NULL);
	CreateWindowA("button", "Pause", WS_VISIBLE | WS_CHILD | ES_CENTER, 120, 70, 58, 18, hWnd, (HMENU)OnButtonPauseGUIClicked, NULL, NULL);


}