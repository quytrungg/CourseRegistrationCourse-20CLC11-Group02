//#include <conio.h>
#include<Windows.h>
#include<iostream>
#include<string>
#include <conio.h>
#include<io.h>
#include<fcntl.h>
#include<algorithm>
using namespace std;
bool Check_session(wstring a) {
	if (a[0] == L'M') {
		if (a[1] == L'O') {
			if (a[2] == L'N') {
			}
			else return false;
		}
		else return false;
	}
	else if (a[0] == L'T') {
		if (a[1] == L'U') {
			if (a[2] == L'E') {

			}
			else return false;
		}
		else if (a[1] != L'H')return false;
	}
	else if (a[0] == L'W') {
		if (a[1] == L'E') {
			if (a[2] == L'D') {

			}
			else return false;
		}
		else return false;
	}
	else if (a[0] == L'T') {
		if (a[1] == L'H') {
			if (a[2] == L'U') {

			}
			else return false;
		}
		else return false;
	}
	else if (a[0] == L'F') {
		if (a[1] == L'R') {
			if (a[2] == L'I') {

			}
			else return false;
		}
		else return false;
	}
	else if (a[0] == L'S') {
		if (a[1] == L'A') {
			if (a[2] == L'T') {

			}
			else return false;
		}
		else return false;
	}
	else return false;
	if (a[3] == L'S') {

	}
	else return false;
	if (a[4] == L'1' || a[4] == L'2' || a[4] == L'3' || a[4] == L'4') {

	}
	else return false;
	if (a[5] == L'_') {

	}
	else return false;
	if (a[6] == L'M') {
		if (a[7] == L'O') {
			if (a[8] == L'N') {

			}
			else return false;
		}
		else return false;
	}
	else if (a[6] == L'T') {
		if (a[7] == L'U') {
			if (a[8] == L'E') {

			}
			else return false;
		}
		else if (a[1] != L'H')return false;
	}
	else if (a[6] == L'W') {
		if (a[7] == L'E') {
			if (a[8] == L'D') {

			}
			else return false;
		}
		else return false;
	}
	else if (a[6] == L'T') {
		if (a[7] == L'H') {
			if (a[8] == L'U') {

			}
			else return false;
		}
		else return false;
	}
	else if (a[6] == L'F') {
		if (a[7] == L'R') {
			if (a[8] == L'I') {

			}
			else return false;
		}
		else return false;
	}
	else if (a[6] == L'S') {
		if (a[7] == L'A') {
			if (a[8] == L'T') {

			}
			else return false;
		}
		else return false;
	}
	else return false;
	if (a[9] == L'S') {

	}
	else return false;
	if (a[10] == L'1' || a[10] == L'2' || a[10] == L'3' || a[10] == L'4') {

	}
	else return false;
	if (a[1] == a[7] && a[4] == a[10]) return false;
	return true;
}

void main()
{
	wstring a = L"THUS1_THUS2";
	cout << Check_session(a);
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