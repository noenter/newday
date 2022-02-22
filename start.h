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
#define OnButtonPauseGUIClicked 13

int idmob = 0;
volatile bool isTreading = true;
bool target = false;
int nt = 0;

HWND hEditControl;
HWND hEditControl2;
HWND hEditControl3;
HWND hStaticControl;
HWND hStaticControl2;
HWND hStaticControl3;
HANDLE thread;

LRESULT CALLBACK SoftwareMainProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hinst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);

void MainWndAddWidgets(HWND hWnd);
void StartGUI();

DWORD WINAPI thread2(LPVOID t) 
{
    StartGUI();
    return 0;
}

void Setkeytab()
{   keybd_event(0x09, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
    Sleep(50);
    keybd_event(0x09, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    Sleep(50);
}
void Set1()
{   keybd_event(0x31, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
    Sleep(30);
    keybd_event(0x31, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    Sleep(100);
}
void SetF1()
{   keybd_event(0x70, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
    Sleep(30);
    keybd_event(0x70, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    Sleep(100);
}
void SetF5()
{   keybd_event(0x74, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
    Sleep(50);
    keybd_event(0x74, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    Sleep(50);
}
void SetF7()
{
    keybd_event(0x76, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
    Sleep(50);
    keybd_event(0x76, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    Sleep(50);
}
void SetF8()
{   keybd_event(0x77, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
    Sleep(50);
    keybd_event(0x77, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    Sleep(50);
}
void Set5()
{   keybd_event(0x35, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
    Sleep(30);
    keybd_event(0x35, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
}
void Set2()
{   keybd_event(0x32, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
    Sleep(30);
    keybd_event(0x32, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    Sleep(100);
}
void Set3()
{keybd_event(0x33, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
 Sleep(30);
 keybd_event(0x33, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
 Sleep(100);
}

void CheckTarget()
{
    int xt = 406;
    int yt = 75;
    HDC dng = GetDC(NULL);
    COLORREF c = GetPixel(dng, xt, yt);
    int pr = (int)GetRValue(c);
    int pg = (int)GetGValue(c);
    int pb = (int)GetBValue(c);
    if (pr == 205 && pg == 44 && pb == 43)
        {
        SetWindowTextA(hStaticControl, "Target-OK");
        ReleaseDC(NULL, dng);
        target = true;
        nt = 0;
        }
    else
    {
        nt++;
        SetWindowTextA(hStaticControl, ("Not-Target" + std::to_string(nt)).c_str());
        ReleaseDC(NULL, dng);
        target = false;
        if (nt == 1)
        {
            Set3();
        }
        if (nt == 10 || nt == 30 || nt == 50 || nt == 70 || nt == 90 || nt == 110 || nt == 130 || nt == 150)
        {
            Set1();
        }
        Setkeytab();
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
    int xk = 530;
    int yk = 90;
    while (xk < 551)
    {
        HDC dng = GetDC(NULL);
        COLORREF c = GetPixel(dng, xk, yk);
        int pr = (int)GetRValue(c);
        int pg = (int)GetGValue(c);
        int pb = (int)GetBValue(c);
        if (pr == 135 && pg == 179 && pb == 59)
        {
            SetWindowTextA(hStaticControl2, "Boss");
            SetF5();
            SetF7();
            SetF8();
            SetF1();
            ReleaseDC(NULL, dng);
            break;
        }
        if (pr == 255 && pg == 140 && pb == 0)
        {
            SetWindowTextA(hStaticControl2, "Mob");
            SetF5();
            Set2();
            ReleaseDC(NULL, dng);
            break;
        }
        ReleaseDC(NULL, dng);
        xk++;
    }
}

void leftclick(int xc, int yc)
{   SetCursorPos(xc, yc);
    mouse_event(MOUSEEVENTF_LEFTDOWN, xc, yc, 0, 0);
    Sleep(50);
    mouse_event(MOUSEEVENTF_LEFTUP, xc, yc, 0, 0);
    Sleep(500);
}
void turnright(int step)
{   int x = 500;
    SetCursorPos(x, 180);
    mouse_event(MOUSEEVENTF_RIGHTDOWN, x, 180, 0, 0);
    int nx = x + step;
    SetCursorPos(nx, 180);
    Sleep(200);
    mouse_event(MOUSEEVENTF_RIGHTUP, nx, 180, 0, 0);
    Sleep(300);
}
void turnleft(int step)
{   int x = 512;
    SetCursorPos(x, 180);
    mouse_event(MOUSEEVENTF_RIGHTDOWN, x, 180, 0, 0);
    int nx = x - step;
    SetCursorPos(nx, 180);
    Sleep(200);
    mouse_event(MOUSEEVENTF_RIGHTUP, nx, 180, 0, 0);
    Sleep(300);
}
void Setkeyw(int msec)
{   keybd_event(0x57, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
    Sleep(msec);
    keybd_event(0x57, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    Sleep(300);
}

void StartGUI()
{

    Sleep(2000);
    SetCursorPos(512, 230);
    mouse_event(MOUSEEVENTF_RIGHTDOWN, 512, 180, 0, 0);
    Sleep(10);
    mouse_event(MOUSEEVENTF_RIGHTUP, 512, 180, 0, 0);
    Sleep(100);
    while (isTreading)
    {

        turnleft(400);//left 1285
        turnleft(400);
        turnleft(400);
        turnleft(85);
        Setkeyw(8000);// w 8000
        leftclick(514, 334);// 514 334
        Sleep(1000);
        leftclick(520, 340);//520 340 задание
        leftclick(520, 325);//520 325 no pets
        leftclick(520, 325);//520 325 gotovi
        Sleep(8000);
        turnleft(400);
        turnleft(130);// l 530
        leftclick(520, 332);//520 332
        Sleep(2000);
        leftclick(520, 340);//520 340 задание
        leftclick(520, 325);//520 325 борьба во имя
        leftclick(520, 325);//520 325 это про нас
        leftclick(520, 325);//520 325 это про нас
        Sleep(1000);
        turnright(200);//640
        turnright(200);
        turnright(240);
        Setkeyw(14000);// w 8000
        turnleft(400);
//        turnleft(400);
        Setkeyw(8000);// w 8000

//        CloseHandle(thread2);

//        Sleep(300000);

        CheckTarget();
            if (target)
            {
            CheckKill();
            }
        Sleep(1000);
    }
}
