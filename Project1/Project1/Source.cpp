#include "Header.h"

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(handle, &ConCurInf);
}

void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


bool compare2Times(LocalTime& a, LocalTime& b) {//true khi b>a
	if (a.date.Year > b.date.Year)
	{
		return false;
	}
	if (a.date.Year == b.date.Year)
	{
		if (a.date.Month > b.date.Month)
		{
			return false;
		}
		if (a.date.Month == b.date.Month)
		{
			if (a.date.Day >= b.date.Day) return false;
		}
	}
	return true;
}

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    //tstruct = *localtime(&now);
    localtime_s(&tstruct, &now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
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

bool checkYear(int year)
{
	if (year % 400 == 0)
		return true;

	if (year % 4 == 0 && year % 100 != 0)
		return true;

	return false;
}

void Get_current_time_to_int(LocalTime& current_time) {
	std::string str = currentDateTime();
	int begin = 0;
	int end = str.find("-", begin + 1);
	char* a = new char[end - begin + 1];
	str.copy(a, end - begin, begin);
	current_time.date.Year = Convert_char_to_int(a, end - begin);
	delete[] a;

	begin = end + 1;
	end = str.find("-", begin + 1);
	a = new char[end - begin + 1];
	str.copy(a, end - begin, begin);
	current_time.date.Month = Convert_char_to_int(a, end - begin);
	delete[] a;

	begin = end + 1;
	end = str.find(".", begin + 1);
	a = new char[end - begin + 1];
	str.copy(a, end - begin, begin);
	current_time.date.Day = Convert_char_to_int(a, end - begin);
	delete[] a;

	begin = end + 1;
	end = str.find(":", begin + 1);
	a = new char[end - begin + 1];
	str.copy(a, end - begin, begin);
	current_time.time.Hours = Convert_char_to_int(a, end - begin);
	delete[] a;

	begin = end + 1;
	end = str.find(":", begin + 1);
	a = new char[end - begin + 1];
	str.copy(a, end - begin, begin);
	current_time.time.Minutes = Convert_char_to_int(a, end - begin);
	delete[] a;

	begin = end + 1;
	end = str.length();
	a = new char[end - begin + 1];
	str.copy(a, end - begin, begin);
	current_time.time.Seconds = Convert_char_to_int(a, end - begin);
	delete[] a;
}

bool Input_time(LocalTime& a, LocalTime& b) {
    LocalTime current_time;
    Get_current_time_to_int(current_time);
	int* year = new int[11];
	int* month = new int[12];
	int* day_1 = new int[31];
	int* day_2 = new int[30];
	int* day_3 = new int[29];
	int* day_4 = new int[28];
	for (int i = 0; i < 11; i++) {
		year[i] = current_time.date.Year - 5 + i;
	}
 	for (int i = 0; i < 12; i++) {
		month[i] = i + 1;
	}
	for (int i = 0; i < 31; i++) {
		day_1[i] = i + 1;
	}
	for (int i = 0; i < 30; i++) {
		day_2[i] = i + 1;
	}
	for (int i = 0; i < 29; i++) {
		day_3[i] = i + 1;
	}
	for (int i = 0; i < 28; i++) {
		day_4[i] = i + 1;
	}
	std::wcout << L"Use W adn S to choose" << std::endl;
	std::wcout << L"Start date: " << std::endl;
	int pointer = 5;
	int Max_List_Menu = 11;
	std::wcout << "Year: ";
	while (1) {
		//in menu ra man hinh
		GotoXY(6, 2);
		ShowCur(0);
		std::wcout << year[pointer] << std::endl;
		char key;
		while (1) {
			if (_kbhit()) {
				key = _getch();
				if (key == 72 || key == 'w' || key == 'W') {
					if (pointer < Max_List_Menu - 1) {
						pointer++;
					}
					else {
						pointer = 0;
					}
					break;
				}
				if (key == 80 || key == 's' || key == 'S') {
					if (pointer > 0) {
						pointer--;
					}
					else {
						pointer = Max_List_Menu - 1;
					}
					break;
				}
				if (key == 13) {
					a.date.Year = year[pointer];
					break;
				}
			}
		}
		if (key == 13) {
			break;
		}
	}
	GotoXY(11, 2);
	std::wcout << "Month: ";
	pointer = 0;
	Max_List_Menu = 12;
	while (1) {
		//in menu ra man hinh
		GotoXY(17, 2);
		ShowCur(0);
		if (month[pointer] < 10) {
			std::wcout << 0;
		}
		std::wcout << month[pointer] << std::endl;
		char key;
		while (1) {
			if (_kbhit()) {
				key = _getch();
				if (key == 72 || key == 'w' || key == 'W') {
					if (pointer < Max_List_Menu - 1) {
						pointer++;
					}
					else {
						pointer = 0;
					}
					break;
				}
				if (key == 80 || key == 's' || key == 'S') {
					if (pointer > 0) {
						pointer--;
					}
					else {
						pointer = Max_List_Menu - 1;
					}
					break;
				}
				if (key == 13) {
					a.date.Month = month[pointer];
					break;
				}
			}
		}
		if (key == 13) {
			break;
		}
	}
	GotoXY(20, 2);
	std::wcout << L"Day: ";
	if (a.date.Month == 1 || a.date.Month == 3 || a.date.Month == 5 || a.date.Month == 7 || a.date.Month == 8 || a.date.Month == 10 || a.date.Month == 12) {
		pointer = 0;
		Max_List_Menu = 31;
		while (1) {
			//in menu ra man hinh
			GotoXY(24, 2);
			ShowCur(0);
			if (day_1[pointer] < 10) {
				std::wcout << 0;
			}
			std::wcout << day_1[pointer] << std::endl;
			char key;
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer < Max_List_Menu - 1) {
							pointer++;
						}
						else {
							pointer = 0;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer > 0) {
							pointer--;
						}
						else {
							pointer = Max_List_Menu - 1;
						}
						break;
					}
					if (key == 13) {
						a.date.Day = day_1[pointer];
						break;
					}
				}
			}
			if (key == 13) {
				break;
			}
		}
	}
	else if (a.date.Month != 2) {
		pointer = 0;
		Max_List_Menu = 30;
		while (1) {
			//in menu ra man hinh
			GotoXY(24, 2);
			ShowCur(0);
			if (day_2[pointer] < 10) {
				std::wcout << 0;
			}
			std::wcout << day_2[pointer] << std::endl;
			char key;
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer < Max_List_Menu - 1) {
							pointer++;
						}
						else {
							pointer = 0;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer > 0) {
							pointer--;
						}
						else {
							pointer = Max_List_Menu - 1;
						}
						break;
					}
					if (key == 13) {
						a.date.Day = day_2[pointer];
						break;
					}
				}
			}
			if (key == 13) {
				break;
			}
		}
	}
	else if (checkYear(a.date.Year)) {
		pointer = 0;
		Max_List_Menu = 29;
		while (1) {
			//in menu ra man hinh
			GotoXY(24, 2);
			ShowCur(0);
			if (day_3[pointer] < 10) {
				std::wcout << 0;
			}
			std::wcout << day_3[pointer] << std::endl;
			char key;
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer < Max_List_Menu - 1) {
							pointer++;
						}
						else {
							pointer = 0;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer > 0) {
							pointer--;
						}
						else {
							pointer = Max_List_Menu - 1;
						}
						break;
					}
					if (key == 13) {
						a.date.Day = day_3[pointer];
						break;
					}
				}
			}
			if (key == 13) {
				break;
			}
		}
	}
	else {
		pointer = 0;
		Max_List_Menu = 28;
		while (1) {
			//in menu ra man hinh
			GotoXY(24, 2);
			ShowCur(0);
			if (day_4[pointer] < 10) {
				std::wcout << 0;
			}
			std::wcout << day_4[pointer] << std::endl;
			char key;
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer < Max_List_Menu - 1) {
							pointer++;
						}
						else {
							pointer = 0;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer > 0) {
							pointer--;
						}
						else {
							pointer = Max_List_Menu - 1;
						}
						break;
					}
					if (key == 13) {
						a.date.Day = day_4[pointer];
						break;
					}
				}
			}
			if (key == 13) {
				break;
			}
		}
	}
	GotoXY(0, 3);
	std::wcout << L"End date: " << std::endl;
	std::wcout << "Year: ";
	pointer = 5;
	Max_List_Menu = 11;
	while (1) {
		//in menu ra man hinh
		GotoXY(6, 4);
		ShowCur(0);
		std::wcout << year[pointer] << std::endl;
		char key;
		while (1) {
			if (_kbhit()) {
				key = _getch();
				if (key == 72 || key == 'w' || key == 'W') {
					if (pointer < Max_List_Menu - 1) {
						pointer++;
					}
					else {
						pointer = 0;
					}
					break;
				}
				if (key == 80 || key == 's' || key == 'S') {
					if (pointer > 0) {
						pointer--;
					}
					else {
						pointer = Max_List_Menu - 1;
					}
					break;
				}
				if (key == 13) {
					b.date.Year = year[pointer];
					break;
				}
			}
		}
		if (key == 13) {
			break;
		}
	}

	GotoXY(11, 4);
	std::wcout << "Month: ";
	pointer = 0;
	Max_List_Menu = 12;
	while (1) {
		//in menu ra man hinh
		GotoXY(17, 4);
		ShowCur(0);
		if (month[pointer] < 10) {
			std::wcout << 0;
		}
		std::wcout << month[pointer] << std::endl;
		char key;
		while (1) {
			if (_kbhit()) {
				key = _getch();
				if (key == 72 || key == 'w' || key == 'W') {
					if (pointer < Max_List_Menu - 1) {
						pointer++;
					}
					else {
						pointer = 0;
					}
					break;
				}
				if (key == 80 || key == 's' || key == 'S') {
					if (pointer > 0) {
						pointer--;
					}
					else {
						pointer = Max_List_Menu - 1;
					}
					break;
				}
				if (key == 13) {
					b.date.Month = month[pointer];
					break;
				}
			}
		}
		if (key == 13) {
			break;
		}
	}
	GotoXY(20, 4);
	std::wcout << L"Day: ";
	if (b.date.Month == 1 || b.date.Month == 3 || b.date.Month == 5 || b.date.Month == 7 || b.date.Month == 8 || b.date.Month == 10 || b.date.Month == 12) {
		pointer = 0;
		Max_List_Menu = 31;
		while (1) {
			//in menu ra man hinh
			GotoXY(24, 4);
			ShowCur(0);
			if (day_1[pointer] < 10) {
				std::wcout << 0;
			}
			std::wcout << day_1[pointer] << std::endl;
			char key;
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer < Max_List_Menu - 1) {
							pointer++;
						}
						else {
							pointer = 0;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer > 0) {
							pointer--;
						}
						else {
							pointer = Max_List_Menu - 1;
						}
						break;
					}
					if (key == 13) {
						b.date.Day = day_1[pointer];
						break;
					}
				}
			}
			if (key == 13) {
				break;
			}
		}
	}
	else if (b.date.Month != 2) {
		pointer = 0;
		Max_List_Menu = 30;
		while (1) {
			//in menu ra man hinh
			GotoXY(24, 4);
			ShowCur(0);
			if (day_2[pointer] < 10) {
				std::wcout << 0;
			}
			std::wcout << day_2[pointer] << std::endl;
			char key;
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer < Max_List_Menu - 1) {
							pointer++;
						}
						else {
							pointer = 0;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer > 0) {
							pointer--;
						}
						else {
							pointer = Max_List_Menu - 1;
						}
						break;
					}
					if (key == 13) {
						b.date.Day = day_2[pointer];
						break;
					}
				}
			}
			if (key == 13) {
				break;
			}
		}
	}
	else if (checkYear(b.date.Year)) {
		pointer = 0;
		Max_List_Menu = 29;
		while (1) {
			//in menu ra man hinh
			GotoXY(24, 4);
			ShowCur(0);
			if (day_3[pointer] < 10) {
				std::wcout << 0;
			}
			std::wcout << day_3[pointer] << std::endl;
			char key;
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer < Max_List_Menu - 1) {
							pointer++;
						}
						else {
							pointer = 0;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer > 0) {
							pointer--;
						}
						else {
							pointer = Max_List_Menu - 1;
						}
						break;
					}
					if (key == 13) {
						b.date.Day = day_3[pointer];
						break;
					}
				}
			}
			if (key == 13) {
				break;
			}
		}
	}
	else {
		pointer = 0;
		Max_List_Menu = 28;
		while (1) {
			//in menu ra man hinh
			GotoXY(24, 4);
			ShowCur(0);
			if (day_4[pointer] < 10) {
				std::wcout << 0;
			}
			std::wcout << day_4[pointer] << std::endl;
			char key;
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer < Max_List_Menu - 1) {
							pointer++;
						}
						else {
							pointer = 0;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer > 0) {
							pointer--;
						}
						else {
							pointer = Max_List_Menu - 1;
						}
						break;
					}
					if (key == 13) {
						b.date.Day = day_4[pointer];
						break;
					}
				}
			}
			if (key == 13) {
				break;
			}
		}
	}

	delete[] year;
	delete[] month;
	delete[] day_1;
	delete[] day_2;
	delete[] day_3;
	delete[] day_4;
	if (compare2Times(a, b)) {
		std::wcout << "Input success" << std::endl;
		return true;
	}
	else {
		std::wcout << "End date is smaller than start date. Input wrong" << std::endl;
		a.date.Year = 0;
		a.date.Month = 0;
		a.date.Day = 0;
		b.date.Year = 0;
		b.date.Month = 0;
		b.date.Day = 0;
		return false;
	}
}



std::wstring Create_school_year() {
	wchar_t* a = new wchar_t[10];
	LocalTime current_time;
	Get_current_time_to_int(current_time);
	int n1 = current_time.date.Year ;
	int n2 = current_time.date.Year + 1;
	int m = 1000;
	int r;
	int count = 0;
	for (int j = n1; j > 0; j = j / 10) {
		r = n1 / m;
		n1 = n1 - r * m;
		m = m / 10;
		a[count] = r + L'0';
		count++;
	}
	a[count] = L'_';
	m = 1000;
	count++;
	for (int j = n2; j > 0; j = j / 10) {
		r = n2 / m;
		n2 = n2 - r * m;
		m = m / 10;
		a[count] = r + L'0';
		count++;
	}
	a[count]  = L'\0';
	std::wcout << a << std::endl;
	std::wstring school_year_1(a);
	return school_year_1;
}

void main() {
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	std::wcout << Create_school_year();
}
