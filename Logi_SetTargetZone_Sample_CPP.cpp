#include "stdafx.h"
#include "LogitechLEDLib.h"
#include <iostream>
#include <Windows.h>
#define _WIN32_WINNT 0x050


using namespace LogiLed;


#define HeatMapSize (21 * 6 * 4)
byte activeMap[HeatMapSize];
byte HeatMap[HeatMapSize];
bool HeatMapChange = true;
bool ZoneChange = true;
int mRed = 0;    // Mouse rgb
int mGreen = 0;
int mBlue = 0;

int mX = 0;
int mY = 0;
int mouseIntensity = 0;


KeyName bitmapExcluded[] = {NUM_LOCK, NUM_SLASH, NUM_ASTERISK, NUM_MINUS,
                            NUM_SEVEN, NUM_EIGHT, NUM_NINE, NUM_PLUS,
                            NUM_FOUR, NUM_FIVE, NUM_SIX,
                            NUM_ONE, NUM_TWO, NUM_THREE, NUM_ENTER,
                            NUM_ZERO, NUM_PERIOD};


const int DISSIPATE_RATE = 10;
const float mouseFall = 0.98;


int GetIndex(int a, int b) {
    return min((a + b*21)*4, HeatMapSize-1);
}


void setIndexColor(int a, int b, int r = 255, int g = 0, int b2 = 255) {
    int ind = GetIndex(a, b);
    activeMap[ind] = b2;
    activeMap[ind+1] = g;
    activeMap[ind+2] = r;
}

void setZones(int r, int g, int b) {
    LogiLedSetLightingForTargetZone(Keyboard, 0, r, g, b);
}


LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode == HC_ACTION)
    {
        switch (wParam)
        {
        case WM_KEYDOWN:
        case WM_SYSKEYDOWN:
            mouseIntensity += 10000;
            PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
            std::cout << p->vkCode << std::endl;
            switch (p->vkCode) {
            case 27: setIndexColor(0, 0); break;
            case 112: setIndexColor(1, 0); break;
            case 113: setIndexColor(2, 0); break;
            case 114: setIndexColor(3, 0); break;
            case 115: setIndexColor(4, 0); break;
            case 116: setIndexColor(5, 0); break;
            case 117: setIndexColor(6, 0); break;
            case 118: setIndexColor(7, 0); break;
            case 119: setIndexColor(8, 0); break;
            case 120: setIndexColor(9, 0); break;
            case 121: setIndexColor(10, 0); break;
            case 122: setIndexColor(11, 0); break;
            case 123: setIndexColor(12, 0); break;
            case 44: setIndexColor(13, 0); break;
            case 145: setIndexColor(14, 0); break;
            case 19: setIndexColor(15, 0); break;
            
            case 220: setIndexColor(0, 1); break;
            case 49: setIndexColor(1, 1); break;
            case 50: setIndexColor(2, 1); break;
            case 51: setIndexColor(3, 1); break;
            case 52: setIndexColor(4, 1); break;
            case 53: setIndexColor(5, 1); break;
            case 54: setIndexColor(6, 1); break;
            case 55: setIndexColor(7, 1); break;
            case 56: setIndexColor(8, 1); break;
            case 57: setIndexColor(9, 1); break;
            case 48: setIndexColor(10, 1); break;
            case 187: setIndexColor(11, 1); break;
            case 219: setIndexColor(12, 1); break;
            case 8: setIndexColor(13, 1); break;
            case 45: setIndexColor(14, 1); break;
            case 36: setIndexColor(15, 1); break;
            case 33: setIndexColor(16, 1); break;
            case 144: setIndexColor(17, 1); break;
            case 111: setIndexColor(18, 1); break;
            case 106: setIndexColor(19, 1); break;
            case 109: setIndexColor(20, 1); break;

            case 9: setIndexColor(0, 2); break;
            case 81: setIndexColor(1, 2); break;
            case 87: setIndexColor(2, 2); break;
            case 69: setIndexColor(3, 2); break;
            case 82: setIndexColor(4, 2); break;
            case 84: setIndexColor(5, 2); break;
            case 89: setIndexColor(6, 2); break;
            case 85: setIndexColor(7, 2); break;
            case 73: setIndexColor(8, 2); break;
            case 79: setIndexColor(9, 2); break;
            case 80: setIndexColor(10, 2); break;
            case 221: setIndexColor(11, 2); break;
            case 186: setIndexColor(12, 2); break;
            //case 13: setIndexColor(13, 2); break;
            case 46: setIndexColor(14, 2); break;
            case 35: setIndexColor(15, 2); break;
            case 34: setIndexColor(16, 2); break;
            case 107: setIndexColor(20, 2); break;

            case 20: setIndexColor(0, 3); break;
            case 65: setIndexColor(1, 3); break;
            case 83: setIndexColor(2, 3); break;
            case 68: setIndexColor(3, 3); break;
            case 70: setIndexColor(4, 3); break;
            case 71: setIndexColor(5, 3); break;
            case 72: setIndexColor(6, 3); break;
            case 74: setIndexColor(7, 3); break;
            case 75: setIndexColor(8, 3); break;
            case 76: setIndexColor(9, 3); break;
            case 192: setIndexColor(10, 3); break;
            case 222: setIndexColor(11, 3); break;
            case 191: setIndexColor(12, 3); break;
            case 13: setIndexColor(13, 3); break;

            case 160: setIndexColor(0, 4); break;
            case 226: setIndexColor(1, 4); break;
            case 90: setIndexColor(2, 4); break;
            case 88: setIndexColor(3, 4); break;
            case 67: setIndexColor(4, 4); break;
            case 86: setIndexColor(5, 4); break;
            case 66: setIndexColor(6, 4); break;
            case 78: setIndexColor(7, 4); break;
            case 77: setIndexColor(8, 4); break;
            case 188: setIndexColor(9, 4); break;
            case 190: setIndexColor(10, 4); break;
            case 189: setIndexColor(11, 4); break;
            case 161: setIndexColor(13, 4); break;
            case 38: setIndexColor(15, 4); break;

            case 162: setIndexColor(0, 5); break;
            case 91: setIndexColor(1, 5); break;
            case 164: setIndexColor(2, 5); break;
            case 32: setIndexColor(6, 5); break;
            case 165: setIndexColor(11, 5); break;
            case 92: setIndexColor(12, 5); break;
            case 93: setIndexColor(13, 5); break;
            case 163: setIndexColor(14, 5); break;
            case 37: setIndexColor(15, 5); break;
            case 40: setIndexColor(16, 5); break;
            case 39: setIndexColor(17, 5); break;
            }
            if (p->vkCode == 'A') {
                int ind = GetIndex(11, 3);
                activeMap[9] = 255;
                activeMap[ind + 1] = 255;
                activeMap[ind + 2] = 255;
                HeatMapChange = true;
                break;
            }
            break;
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
    PMSLLHOOKSTRUCT m = (PMSLLHOOKSTRUCT) lParam;
    mouseIntensity += abs(mX - m->pt.x)*2;
    mouseIntensity += abs(mY - m->pt.y)*2;
    mX = m->pt.x;
    mY = m->pt.y;
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}


void byteout(byte b) {
    int x = b;
    std::cout << x << std::endl;
}


void bytesafadd(byte& a, int b) {
    a += b;
    if (a < b) { a = 255; }
}


void bytesafsub(byte& a, int b) {
    if (b > a) { a = 0; return; }
    a -= b;
}


void clearHeatMap(byte brightness = 255) {
    for (int n = 0; n < HeatMapSize; n += 4) {
        HeatMap[n + 3] = brightness;
        HeatMap[n + 2] = 40;
        HeatMap[n + 1] = 0;
        HeatMap[n] = 60;
    }
}


int HeatMapDissipate() {
    clearHeatMap();
    int ind;
    for (int b = 0; b < 6; b++) {
        for (int a = 0; a < 21; a++) {
            ind = GetIndex(a, b);
            if (activeMap[ind] == 0 && activeMap[ind + 1] == 0 && activeMap[ind + 2] == 0) {
                continue;
            }
            HeatMapChange = true;
            bytesafsub(activeMap[ind], DISSIPATE_RATE);
            bytesafsub(activeMap[ind+1], DISSIPATE_RATE);
            bytesafsub(activeMap[ind+2], DISSIPATE_RATE);
            bytesafadd(HeatMap[ind], activeMap[ind]);
            bytesafadd(HeatMap[ind+1], activeMap[ind+1]);
            bytesafadd(HeatMap[ind+2], activeMap[ind+2]);

            if (b != 0) {
                bytesafadd(HeatMap[ind - 82], activeMap[ind + 2] / 3);
                bytesafadd(HeatMap[ind - 83], activeMap[ind + 1] / 3);
                bytesafadd(HeatMap[ind - 84], activeMap[ind] / 3);
            }
            if (b != 5) {
                bytesafadd(HeatMap[ind + 86], activeMap[ind+2] / 3);
                bytesafadd(HeatMap[ind + 85], activeMap[ind+1] / 3);
                bytesafadd(HeatMap[ind + 84], activeMap[ind] / 3);
            }
            if (a != 0) {
                bytesafadd(HeatMap[ind - 2], activeMap[ind+2] / 3);
                bytesafadd(HeatMap[ind - 3], activeMap[ind+1] / 3);
                bytesafadd(HeatMap[ind - 4], activeMap[ind] / 3);
            }
            if (a != 20) {
                bytesafadd(HeatMap[ind + 6], activeMap[ind+2] / 3);
                bytesafadd(HeatMap[ind + 5], activeMap[ind+1] / 3);
                bytesafadd(HeatMap[ind + 4], activeMap[ind] / 3);
            }
        }
    }
    return 0;
}


void mousePerTick() {
    if (mouseIntensity < 10) {
        return;
    }
    ZoneChange = true;
    mRed = mouseIntensity / 150;
    mGreen = mouseIntensity / 1500;
    mBlue = mouseIntensity / 300;
    mouseIntensity = max(mouseIntensity * mouseFall, 0);
}


int main()
{
    for (int n = 0; n < HeatMapSize; n+=4) {
        activeMap[n+3] = 255;
        activeMap[n+2] = 0;
        activeMap[n+1] = 0;
        activeMap[n] = 0;
    }
    HeatMap[9] = 255;
    std::cout << "INITALIZING" << std::endl;
    LogiLedInitWithName("theInsignificantdoll");
    // Install the low-level keyboard & mouse hooks
    HHOOK hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, 0, 0);
    HHOOK hhkLowLevelMouse = SetWindowsHookEx(WH_MOUSE_LL, MouseProc, 0, 0);
    LogiLedExcludeKeysFromBitmap(bitmapExcluded, 17);

    MSG msg;
    while (true) {
        Sleep(1000 / 72);
        HeatMapDissipate();
        mousePerTick();
        if (HeatMapChange) {
            LogiLedSetLightingFromBitmap(HeatMap);
            HeatMapChange = false;
        }
        if (ZoneChange) {
            setZones(mRed, mGreen, mBlue);
            LogiLedSetLightingForTargetZone(Mouse, 0, mRed, mGreen, mBlue);
            LogiLedSetLightingForTargetZone(Mouse, 1, mRed, mGreen, mBlue);
            ZoneChange = false;
        }
        PeekMessage(&msg, NULL, NULL, NULL, NULL);
    }

    LogiLedShutdown();
    UnhookWindowsHookEx(hhkLowLevelKybd);
    UnhookWindowsHookEx(hhkLowLevelMouse);

    return(0);
}
