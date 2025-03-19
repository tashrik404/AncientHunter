#include <iostream>
using namespace std;
#include <windows.h>

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wp, lp);
    }
    return 0;
}

int main()
{
    HINSTANCE hInstance = GetModuleHandle(NULL);

    // Register the window class
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MyWindowClass";
    RegisterClass(&wc);

    // Create the window
    HWND hwnd = CreateWindowEx(0, wc.lpszClassName, "Hello, Windows!", WS_OVERLAPPEDWINDOW,
                               CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);

    // Show the window
    ShowWindow(hwnd, SW_SHOWNORMAL);

    // Message loop
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}