#include"func.h"
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
bool checkYear(int year)
{
	if (year % 400 == 0)
		return true;

	if (year % 4 == 0 && year % 100 != 0)
		return true;

	return false;
}

bool checkDayIsTrue(LocalTime& a) {
	if (a.date.Year < 0) return false;
	if (a.date.Month <= 0 || a.date.Month > 12)	return false;
	if (a.date.Day <= 0) return false;
	int* months = new int[13];
	for (int i = 0; i < 13; i++) months[i] = 30;
	months[1] = months[3] = months[5] = months[7] = months[8] = months[10] = months[12] = 31;
	if (checkYear(a.date.Year)) {
		months[2] = 29;
	}
	else months[2] = 28;
	if (a.date.Day <= 0 || a.date.Day > months[a.date.Month]) {
		delete[]months; return false;
	}
	delete[]months;
	return true;
}
LocalTime currentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	localtime_s(&tstruct, &now);
	strftime(buf, sizeof(buf), "%Y/%m/%d", &tstruct);
	stringstream time_in(buf);
	LocalTime a;
	string astr;
	getline(time_in, astr, '/');
	a.date.Year = convert_num(astr);
	getline(time_in, astr, '/');
	a.date.Month = convert_num(astr);
	getline(time_in, astr, '/');
	a.date.Day = convert_num(astr);
	return a;
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
bool inputPeriodTime(LocalTime& a, LocalTime& b) {
	LocalTime current_time;
	current_time = currentDateTime();
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
	std::wcout << L"Sử dụng phím W và S" << std::endl;
	std::wcout << L"Ngày bắt đầu: " << std::endl;
	int pointer = 5;
	int Max_List_Menu = 11;
	std::wcout << L"Năm: ";
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
	std::wcout << L"Tháng: ";
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
	std::wcout << L"Ngày: ";
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
	std::wcout << L"Ngày kết thúc: " << std::endl;
	std::wcout << L"Năm: ";
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
	std::wcout << L"Tháng: ";
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
	std::wcout << L"Ngày: ";
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
	system("cls");
	if (compare2Times(a, b)) {
		return true;
	}
	else {
		a.date.Year = 0;
		a.date.Month = 0;
		a.date.Day = 0;
		b.date.Year = 0;
		b.date.Month = 0;
		b.date.Day = 0;
		return false;
	}
}