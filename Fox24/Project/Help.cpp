#include "Struct.h"
#include "Time.h"
#include "Help.h"

int Convert_wchart_to_int(wchar_t* a, int n) {
	int m = 0;
	int p;
	for (int i = 0; i < n; i++) {
		p = a[i] - L'0';
		m = m * 10 + p;
	}
	return m;
}

int Convert_char_to_int(char* a, int n)
{
	int m = 0;
	int p;
	for (int i = 0; i < n; i++) {
		p = a[i] - L'0';
		m = m * 10 + p;
	}
	return m;
}

double Conver_wchart_to_double(wchar_t* a, int n) {
	double m = 0;
	int find = 0;
	double p;
	for (int i = 0; i < n; i++) {
		if (a[i] == L'.') {
			find = i;
			break;
		}
	}
	if (find == 0) {
		for (int i = 0; i < n; i++) {
			p = a[i] - L'0';
			m = m * 10 + p;
		}
	}
	else {
		double r = 10;
		for (int i = 0; i < find; i++) {
			p = a[i] - L'0';
			m = m * 10 + p;
		}
		for (int i = find + 1; i < n; i++) {
			p = a[i] - L'0';
			m = m + p / r;
			r = r * 10;
		}
	}
	return m;
}

char* Convert_int_to_char(int n) {
	int count = 0;
	for (int i = n; i > 0; i = i / 10) {
		count++;
	}
	char* a = new char[count + 1];
	int r;
	for (int i = 0; i < count; i++) {
		r = n % 10;
		n = n / 10;
		a[count - 1 - i] = r + '0';
	}
	a[count] = '\0';
	return a;
}

void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetColor(int background_color, int text_color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int color_code = background_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}

// Ham console
void SetWindowSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT WindowSize;

	WindowSize.Top = 0;
	WindowSize.Left = 0;
	WindowSize.Right = width;
	WindowSize.Bottom = height;

	SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

void SetScreenBufferSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD NewSize;
	NewSize.X = width;
	NewSize.Y = height;

	SetConsoleScreenBufferSize(hStdout, NewSize);
}

void DisableResizeWindow()
{
	HWND hWnd = GetConsoleWindow();
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

void DisableControlButon(bool Close, bool Min, bool Max)
{
	HWND hWnd = GetConsoleWindow();
	HMENU hMenu = GetSystemMenu(hWnd, false);

	if (Close == 1)
	{
		DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
	}
	if (Min == 1)
	{
		DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
	}
	if (Max == 1)
	{
		DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
	}
}

void ShowScrollBar(BOOL Show)
{
	HWND hWnd = GetConsoleWindow();
	ShowScrollBar(hWnd, SB_BOTH, Show);
}

// Ham an hien con tro
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(handle, &ConCurInf);
}

void Exit()
{
	exit(0);
}

bool checkFileWithFstream(std::wstring path) {
	std::ifstream isf(path);
	return isf.good();
}