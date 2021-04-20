#include <conio.h>
#include<Windows.h>
#include<iostream>
#include<string>
#include<io.h>
#include<fcntl.h>
#include<algorithm>
using namespace std;
void main()
{
    wstring a = L"ab";
    a = a.substr(2);
    cout << (a[0] == L'\0');
    /*HWND hwnd = GetConsoleWindow();
    HMENU hmenu = GetSystemMenu(hwnd, FALSE);
    EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED);*/
    /*_setmode(_fileno(stdout), _O_WTEXT);
    wstring info = L"Ễ";*/
    //transform(info.begin(), info.end(), info.begin(), (int (*)(int))toupper);
}