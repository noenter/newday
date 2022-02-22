#pragma once
#include <iostream>
#include <wingdi.h>
#include <string>
using namespace std;

#define OnButtonR1Clicked		5
#define OnButtonR10Clicked		6
#define OnButtonR100Clicked		7

#define OnButtonL1Clicked		8
#define OnButtonL10Clicked		9
#define OnButtonL100Clicked		10

#define OnButtonStartGUIClicked	11
#define OnButtonStopGUIClicked	12

int idmob = 0;
volatile bool stgui = true;
volatile bool isTreading = true;

HWND hEditControl;
HWND hStaticControl;
HANDLE thread;

LRESULT CALLBACK SoftwareMainProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hinst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);

void MainWndAddWidgets(HWND hWnd);
void StartGUI();

DWORD WINAPI thread2(LPVOID t) 
{
    while (isTreading)
    {
        while (stgui)
        {
            //SetWindowTextA(hStaticControl, "Whit");
        }
        StartGUI();

    }

    return 0;
}

void Setkeytab()
{
    keybd_event(0x09, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
    Sleep(50);
    keybd_event(0x09, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    Sleep(100);
    SetWindowTextA(hStaticControl, "Tab");
    Sleep(500);

}

void Set1()
{
    // Simulate a key press
    keybd_event(0x31,
        0x45,
        KEYEVENTF_EXTENDEDKEY | 0,
        0);
    Sleep(30);
    // Simulate a key release
    keybd_event(0x31,
        0x45,
        KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
        0);
    Sleep(300);

}

void SetF1()
{
    // Simulate a key press
    keybd_event(0x70,
        0x45,
        KEYEVENTF_EXTENDEDKEY | 0,
        0);
    Sleep(30);
    // Simulate a key release
    keybd_event(0x70,
        0x45,
        KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
        0);
}

void SetF5()
{
    // Simulate a key press
    keybd_event(0x74,
        0x45,
        KEYEVENTF_EXTENDEDKEY | 0,
        0);
    Sleep(30);
    // Simulate a key release
    keybd_event(0x74,
        0x45,
        KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
        0);
}

void Set5()
{
    // Simulate a key press
    keybd_event(0x35,
        0x45,
        KEYEVENTF_EXTENDEDKEY | 0,
        0);
    Sleep(30);
    // Simulate a key release
    keybd_event(0x35,
        0x45,
        KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
        0);
}

void Set2()
{
    // Simulate a key press
    keybd_event(0x32,
        0x45,
        KEYEVENTF_EXTENDEDKEY | 0,
        0);
    Sleep(30);
    // Simulate a key release
    keybd_event(0x32,
        0x45,
        KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
        0);
    Sleep(300);

}

void Set3()
{keybd_event(0x33, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
 Sleep(30);
 keybd_event(0x33, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
 Sleep(500);
}

void CheckTarget()
{
    Setkeytab();
    SetWindowTextA(hStaticControl, "Key  -Tab");
    int xt = 406;
    int yt = 75;
    while(isTreading){
    Sleep(100);
    SetWindowTextA(hStaticControl, "");
    HDC dng = GetDC(NULL);
    COLORREF c = GetPixel(dng, xt, yt);
    int pr = (int)GetRValue(c);
    int pg = (int)GetGValue(c);
    int pb = (int)GetBValue(c);
    if (pr == 205 && pg == 44 && pb == 43)
        {
        SetWindowTextA(hStaticControl, "Target-OK");
        ReleaseDC(NULL, dng);
        break;
        }
    ReleaseDC(NULL, dng);
    Setkeytab();
    //SetWindowTextA(hStaticControl, "Key  -Tab");
    //Sleep(300);
    }
}


void getpixelMob()
{
    int xm = 502;
    int ym = 90;
    while (xm < 522)
    {
    HDC dng = GetDC(NULL);
    COLORREF c = GetPixel(dng, xm, ym);
    int pr = (int)GetRValue(c);
    int pg = (int)GetGValue(c);
    int pb = (int)GetBValue(c);
    SetWindowTextA(hStaticControl, ("X-" + to_string(xm) + "R-" + to_string(pr) + " G-" + to_string(pg) + " B-" + to_string(pb)).c_str());
    Sleep(100);
    if (pr == 255 && pg == 140 && pb == 0)
    {
        idmob = 1;
        SetWindowTextA(hStaticControl, "Mob1-target");
        Sleep(1000);
        ReleaseDC(NULL, dng);
        break;
    }
    if (pr == 96 && pg == 128 && pb == 42)
    {
        idmob = 2;
        SetWindowTextA(hStaticControl, "Mob2-target");
        Sleep(1000);
        ReleaseDC(NULL, dng);
        break;
    }

    //cout<<pr<<endl;
    //cout<<(int)GetGValue(c)<<endl;
    //cout<<(int)GetBValue(c)<<endl;
    ReleaseDC(NULL, dng);
    //std::cout << c << endl;
    xm++;
    }
}

void CheckKill()
{
    int xk = 406;
    int yk = 75;
    while (isTreading)
    {
        HDC dng = GetDC(NULL);
        COLORREF c = GetPixel(dng, xk, yk);
        int pr = (int)GetRValue(c);
        int pg = (int)GetGValue(c);
        int pb = (int)GetBValue(c);
        //SetWindowTextA(hStaticControl, "Start - Kill");
        //Sleep(500);
        if (pr != 205 && pg != 44 && pb != 43)
        {
            break;
        }
        SetWindowTextA(hStaticControl, "Kill");
        Set2();
        Sleep(500);
        ReleaseDC(NULL, dng);
    }
}


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


void StartGUI()
{

    Sleep(2000);
    SetCursorPos(512, 230);
    mouse_event(MOUSEEVENTF_RIGHTDOWN, 512, 230, 0, 0);
    Sleep(10);
    mouse_event(MOUSEEVENTF_RIGHTUP, 512, 230, 0, 0);
    Sleep(100);
    int t1 = 0;
    while (isTreading)
    {

        CheckTarget();
        CheckKill();
        SetWindowTextA(hStaticControl, (to_string(t1)).c_str());
        Sleep(2000);
        t1++;
        if (t1 == 10)
        {
            SetWindowTextA(hStaticControl, "Baff");
            Set1();
            Sleep(1800);
            SetF5();
            Sleep(300);
            SetWindowTextA(hStaticControl, "Key - 3");
            Set3();
            Sleep(500);
            t1 = 0;
        }
    }
}
