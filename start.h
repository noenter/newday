#pragma once
#include <iostream>
using namespace std;

#define OnButtonR1Clicked		5
#define OnButtonR10Clicked		6
#define OnButtonR100Clicked		7

#define OnButtonL1Clicked		8
#define OnButtonL10Clicked		9
#define OnButtonL100Clicked		10
LRESULT CALLBACK SoftwareMainProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hinst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);

void MainWndAddWidgets(HWND hWnd);

void turnright(int step)
{
    int x = 412;
    SetCursorPos(x, 230);
    mouse_event(MOUSEEVENTF_RIGHTDOWN, x, 230, 0, 0);
    Sleep(10);
    mouse_event(MOUSEEVENTF_RIGHTUP, x, 230, 0, 0);
    Sleep(50);
    mouse_event(MOUSEEVENTF_RIGHTDOWN, x, 230, 0, 0);
    int nx = x + step;
    SetCursorPos(nx, 230);
    Sleep(200);
    mouse_event(MOUSEEVENTF_RIGHTUP, nx, 230, 0, 0);
    Sleep(300);
}
void turnleft(int step)
{
    int x = 612;
    SetCursorPos(x, 230);
    mouse_event(MOUSEEVENTF_RIGHTDOWN, x, 230, 0, 0);
    Sleep(10);
    mouse_event(MOUSEEVENTF_RIGHTUP, x, 230, 0, 0);
    Sleep(50);
    mouse_event(MOUSEEVENTF_RIGHTDOWN, x, 230, 0, 0);
    int nx = x - step;
    SetCursorPos(nx, 230);
    Sleep(200);
    mouse_event(MOUSEEVENTF_RIGHTUP, nx, 230, 0, 0);
    Sleep(300);
}
