//#include <conio.h>
#include<Windows.h>
#include<iostream>
#include<string>
#include <conio.h>
#include<io.h>
#include<fcntl.h>
//#include<algorithm>
using namespace std;
void GotoXY(short x, short y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int getTheMove_enter() {
    int _COMMAND, _COMMAND2;
    _COMMAND = toupper(_getch());
    _COMMAND2 = (_COMMAND == 224 ? toupper(_getch()) : 0);
    if (_COMMAND == 224 && _COMMAND2 == 75) return 2;
    else if (_COMMAND == 224 && _COMMAND2 == 72) return 0;
    else if (_COMMAND == 224 && _COMMAND2 == 80) return 1;
    else if (_COMMAND == 224 && _COMMAND2 == 77) return 3;
    else if (_COMMAND == 13) return 4;
    return -1;
}//0 lên,1 xuống,2 trái,3 phải,4 enter
int choose_menu(int x, int y, wstring*& menu, int n) {
    int i = 0;
    for (i = 0; i < n; i++) {
        GotoXY(x + 2, y + i); wcout << menu[i];
    }
    i = 0;
    GotoXY(x, y + i);
    wcout << "->";
    int move = -1;
    while (move != 4) {
        move = getTheMove_enter();
        if (!((move > 1 && move<4) || (i == 0 && move == 0) || (i == n - 1 && move == 1))) {
            GotoXY(x, y + i); wcout << "  ";
            if (move == 0) i--;
            if (move == 1) i++;
            GotoXY(x, y + i); wcout << "->";
        }
    }
    system("cls");
    return i + 1;
}
COORD GetConsoleCursorPosition(HANDLE hConsoleOutput)
{
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
    {
        return cbsi.dwCursorPosition;
    }
    else
    {
        // The function failed. Call GetLastError() for details.
        COORD invalid = { 0, 0 };
        return invalid;
    }
}
void main()
{
    cout << getTheMove_enter();
    /*GotoXY(10, 11);
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursor = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
    cout << c.X << " " << c.Y;*/
    /*_setmode(_fileno(stdout), _O_WTEXT);
    wstring* menu = new wstring[3];
    menu[0] = L"1. học sinh";
    menu[1] = L"2. giảng viên";
    menu[2] = L"3.thoát";
    wcout << choose_menu(1, 0, menu, 3);
    delete[]menu;*/
    /*wstring info = L"Ễ";*/
    //transform(info.begin(), info.end(), info.begin(), (int (*)(int))toupper);
}