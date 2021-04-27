#include"func.h"
int convert_num(string& a) {
	char t = a[0];
	int num = 0, i = 0;
	while (t != '\0') {
		if (t < '0' || t>'9') return -1;
		num = num * 10 + t - '0';
		i++;
		t = a[i];
	}
	return num;
}
int wconvert_num(wstring& a) {
	wchar_t t = a[0];
	int num = 0, i = 0;
	while (t != '\0') {
		if (t < L'0'|| t > L'9') return -1;
		num = num * 10 + t - L'0';
		i++;
		t = a[i];
	}
	return num;
}
int user_choose_exist(int left, int right) {
	string a;
	getline(cin, a);
	int t = convert_num(a);
	while (t<left || t>right) {
		wcout << L"Chọn lại từ " << left << L" đến " << right << " ";
		getline(cin, a);
		t = convert_num(a);
	}
	return t;
}
void remove_65279(wstring& a) {
	int i = 0;
	while (a[i] == 65279) i++;
	wstring t = a.substr(i);
	a = t;
}
//handle
void negativeClose() {
	HWND hwnd = GetConsoleWindow();
	HMENU hmenu = GetSystemMenu(hwnd, FALSE);
	EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED);
}
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
		if (!((move > 1 && move < 4) || (i == 0 && move == 0) || (i == n - 1 && move == 1))) {
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