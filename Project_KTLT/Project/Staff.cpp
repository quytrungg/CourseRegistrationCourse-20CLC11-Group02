#include "Struct.h"
#include "Staff.h"
#include "Help.h"
#include "Read.h"
#include<string>
#include "Time.h"
#include "Input.h"

wchar_t* Login_staff() {
	std::wstring str;
	wchar_t* pass = new wchar_t[1];
	pass[0] = L'\0';
	wchar_t* input = new wchar_t[1];
	input[0] = L'\0';
	wchar_t* filename = new wchar_t[1];
	filename[0] = L'\0';
	wchar_t* file = new wchar_t[1];
	file[0] = L'\0';
	int check = 0;
	do {
		system("cls");
		std::wcout << "Input the username: ";
		std::getline(std::wcin, str);
		filename = new wchar_t[str.length() + 1];
		str.copy(filename, str.length(), 0);
		filename[str.length()] = L'\0';
		file = Create_file_3(filename, "Staff", ".txt");
		std::wifstream fin(file);
		if (!fin) {
			std::wcout << L"Error username \n";
			Sleep(100);
			check = 0;
		}
		else {
			fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
			std::getline(fin, str);
			int begin = str.find(',', 0) + 1;
			int end = str.length();
			pass = new wchar_t[end - begin + 1];
			str.copy(pass, end - begin, begin);
			pass[end - begin] = L'\0';
			std::wcout << "Input the password: ";
			std::getline(std::wcin, str);
			input = new wchar_t[str.length() + 1];
			str.copy(input, str.length(), 0);
			input[str.length()] = L'\0';
			check = Check_pass(pass, input);
			if (check) {
				std::wcout << "Input success" << std::endl;
			}
			else {
				std::wcout << "Error password" << std::endl;
				Sleep(200);
			}
			fin.close();
		}
	} while (check != 1);
	return file;
}

void Screen_inf_to_console_staff(wchar_t* file) {
	system("cls");
	SetColor(15, 0);
	Node_staff* pHead_staff = new Node_staff;
	std::wstring str;
	std::wifstream fin(file);
	fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
	std::getline(fin, str);
	std::getline(fin, str);
	Read_file_staff(str, pHead_staff);
	fin.close();
	std::wcout << L"Staff ID: " << pHead_staff->staff.ID << std::endl;
	std::wcout << L"Staff Name: " << pHead_staff->staff.FirstName << L" " << pHead_staff->staff.LastName << std::endl;
	std::wcout << L"Gender: " << pHead_staff->staff.Gender << std::endl;
	std::wcout << L"Birthday: " << pHead_staff->staff.Birthday.Day << L"/" << pHead_staff->staff.Birthday.Month << L"/" << pHead_staff->staff.Birthday.Year << std::endl;
	std::wcout << L"Social ID: " << pHead_staff->staff.SocialID << std::endl;
	pHead_staff->pNext = nullptr;
	Delete_Node_staff(pHead_staff);
	char key = toupper(_getch());
	if (key == 27)
	{
		Sub_menu_staff(file);
	}
}

void Change_pass_staff(wchar_t* file) {
	Node_staff* pHead_staff = new Node_staff;
	std::wstring str;
	std::wifstream fin(file);
	fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
	std::getline(fin, str);
	int begin = str.find(',', 0) + 1;
	int end = str.length();
	wchar_t* Older_pass = new wchar_t[end - begin + 1];
	str.copy(Older_pass, end - begin, begin);
	Older_pass[end - begin] = L'\0';
	std::getline(fin, str);
	Read_file_staff(str, pHead_staff);
	fin.close();

	int check = 0;
	do {
		system("cls");
		SetColor(15, 0);
		std::wcout << L"Please input the older password: ";
		std::getline(std::wcin, str);
		wchar_t* Input_older_pass = new wchar_t[str.length() + 1];
		str.copy(Input_older_pass, str.length(), 0);
		Input_older_pass[str.length()] = L'\0';
		check = Check_pass(Older_pass, Input_older_pass);
		if (check) {
			std::wcout << "Input the new password: ";
			std::getline(std::wcin, str);
			pHead_staff->staff.account.Pass = new wchar_t[str.length() + 1];
			str.copy(pHead_staff->staff.account.Pass, str.length(), 0);
			pHead_staff->staff.account.Pass[str.length()] = L'\0';
			std::wofstream fout(file);
			fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
			fout << pHead_staff->staff.account.ID << L"," << pHead_staff->staff.account.Pass << std::endl;
			fout << pHead_staff->staff.ID << L"," << pHead_staff->staff.FirstName << L"," << pHead_staff->staff.LastName << L"," << pHead_staff->staff.Gender << L"," << pHead_staff->staff.Birthday.Day << L"/" << pHead_staff->staff.Birthday.Month << L"/" << pHead_staff->staff.Birthday.Year << L"," << pHead_staff->staff.SocialID << std::endl;
			fout.close();
			pHead_staff->pNext = nullptr;
			Delete_Node_staff(pHead_staff);
			std::wcout << "Change success" << std::endl;
		}
		else {
			std::wcout << "Older pass not correct" << std::endl;
			Sleep(200);
		}
		delete[] Input_older_pass;
	} while (check != 1);
	delete[] Older_pass;

	char key = toupper(_getch());
	if (key == 27)
	{
		Sub_menu_staff(file);
	}
}

void Create_school_year(wchar_t* file_login) {
	system("cls");
	SetColor(15, 0);
	int n1, n2,r,m;
	Time current_time;
	wchar_t* school_year_1 = new wchar_t[2];
	school_year_1[0] = L'0';
	school_year_1[1] = L'\0';
	Get_current_time_to_int(current_time);
	wchar_t** year = new wchar_t*[11];
	for (int i = 0; i < 11; i++) {
		year[i] = new wchar_t[10];
	}
	for (int i = 0; i < 11; i++) {
		n1 = current_time.date.Year - 5 + i;
		n2 = current_time.date.Year - 4 + i;
		int count = 0;
		m = 1000;
		for (int j = n1; j > 0; j = j / 10) {
			r = n1 / m;
			n1 = n1 - r * m;
			m = m / 10;
			year[i][count] = r + '0';
			count++;
		}
		year[i][count] = L'-';
		m = 1000;
		count++;
		for (int j = n2; j > 0; j = j / 10) {
			r = n2 / m;
			n2 = n2 - r * m;
			m = m / 10;
			year[i][count] = r + '0';
			count++;
		}
		year[i][count] = L'\0';
	}
	std::wstring str_1;
	std::wcout << "Please input the school year you want to create: ";
	int pointer = 5;
	int Max_List_Menu = 11;
	while (1) {
		//in menu ra man hinh
		GotoXY(50, 0);
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
					school_year_1 = year[pointer];
					break;
				}
				if (key == 27) {
					Sub_menu_time_staff(file_login);
				}
			}
		}
		if (key == 13) {
			break;
		}
	}	
	std::wstring str_2;
	int check = 1;
	if (checkFileWithFstream_wstring(L"School_year.txt")) {
		Node_help_1* pHead_help_1 = new Node_help_1;
		Node_help_1* pCur_help_1 = pHead_help_1;
		std::wifstream fin("School_year.txt");
		fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
		while (!fin.eof()) {
			pCur_help_1->pNext = new Node_help_1;
			std::getline(fin, str_2);
			pCur_help_1->pNext->data = new wchar_t[str_2.length() + 1];
			str_2.copy(pCur_help_1->pNext->data, str_2.length(), 0);
			pCur_help_1->pNext->data[str_2.length()] = L'\0';
			pCur_help_1 = pCur_help_1->pNext;
			pCur_help_1->pNext = nullptr;
		}
		if (pHead_help_1->pNext == nullptr) {
			delete pHead_help_1;
			pHead_help_1 = nullptr;
		}
		else {
			Node_help_1* pTemp = pHead_help_1;
			pHead_help_1 = pHead_help_1->pNext;
			delete pTemp;
		}
		fin.close();

		pCur_help_1 = pHead_help_1;
		while (pCur_help_1 != nullptr) {
			if (wcscmp(pCur_help_1->data, school_year_1) == 0) {
				check = 0;
				break;
			}
			pCur_help_1 = pCur_help_1->pNext;
		}
	}
	if (check == 1) {
		char* school_year = new char[wcslen(year[pointer]) + 1];
		for (int i = 0; i < wcslen(year[pointer]); i++) {
			school_year[i] = school_year_1[i];
		}
		school_year[wcslen(year[pointer])] = '\0';
		_mkdir(school_year);
		_mkdir(Create_second_folder("Student", school_year));
		_mkdir(Create_second_folder("Semester", school_year));
		_mkdir(Create_second_folder("Class", school_year));
		wchar_t* file = Create_file_4("Time", Create_second_folder("Semester", school_year), ".txt");
		std::wofstream fout(file);
		fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
		fout << 0 << std::endl;
		fout << 0 << std::endl;
		fout << 0 << std::endl;
		fout.close();


		if (checkFileWithFstream_wstring(L"School_year.txt")) {
			Node_help_1* pHead_help = new Node_help_1;
			Node_help_1* pCur_help = pHead_help;
			std::wifstream fin("School_year.txt");
			fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
			while (!fin.eof()) {
				pCur_help->pNext = new Node_help_1;
				std::getline(fin, str_2);
				pCur_help->pNext->data = new wchar_t[str_2.length() + 1];
				str_2.copy(pCur_help->pNext->data, str_2.length(), 0);
				pCur_help->pNext->data[str_2.length()] = L'\0';
				pCur_help = pCur_help->pNext;
				pCur_help->pNext = nullptr;
			}
			if (pHead_help->pNext == nullptr) {
				delete pHead_help;
				pHead_help = nullptr;
			}
			else {
				Node_help_1* pTemp = pHead_help;
				pHead_help = pHead_help->pNext;
				delete pTemp;
			}
			fin.close();

			pCur_help = pHead_help;
			_wremove(L"School_year.txt");
			std::wofstream fout_1(L"School_year.txt");
			fout_1.imbue(std::locale(fout_1.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
			while (pCur_help->pNext != nullptr) {
				fout_1 << pCur_help->data << std::endl;
				pCur_help = pCur_help->pNext;
			}
			fout_1 << school_year_1 << std::endl;
			fout_1.close();
			Delete_Node_help_1(pHead_help);
		}
		else {
			std::wofstream fout_2(L"School_year.txt");
			fout_2.imbue(std::locale(fout_2.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
			fout_2 << school_year << std::endl;
			fout_2.close();
		}
		for (int i = 0; i < 11; i++) {
			delete[] year[i];
		}
		delete[] year;
		std::wcout << "Input success" << std::endl;
	}
	else {
		std::wcout << "School year had been created" << std::endl;
	}
	char key = toupper(_getch());
	if (key == 27)
	{
		Sub_menu_time_staff(file_login);
	}
}

void Create_semester_1(wchar_t* file_login) {
	std::wstring str_2;
	if (checkFileWithFstream_wstring(L"School_year.txt")) {
		int count = 0;
		Node_help_1* pHead_help = new Node_help_1;
		Node_help_1* pCur_help = pHead_help;
		std::wifstream fin("School_year.txt");
		fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
		while (!fin.eof()) {
			pCur_help->pNext = new Node_help_1;
			std::getline(fin, str_2);
			pCur_help->pNext->data = new wchar_t[str_2.length() + 1];
			str_2.copy(pCur_help->pNext->data, str_2.length(), 0);
			pCur_help->pNext->data[str_2.length()] = L'\0';
			pCur_help = pCur_help->pNext;
			pCur_help->pNext = nullptr;
			count++;
		}
		if (pHead_help->pNext == nullptr) {
			delete pHead_help;
			pHead_help = nullptr;
		}
		else {
			Node_help_1* pTemp = pHead_help;
			pHead_help = pHead_help->pNext;
			delete pTemp;
		}
		count--;
		fin.close();
		int x = 0;
		int check = 0;
		pCur_help = pHead_help;
		while (pCur_help != nullptr) {
			x++;
			pCur_help = pCur_help->pNext;
		}
		x--;
		int pointer = 0;
		while (1) {
			ShowCur(0);
			system("cls");
			pCur_help = pHead_help;
			int count = 0;
			while (pCur_help->pNext != nullptr) {
				if (count == pointer) {
					SetColor(15, 4);
					GotoXY(50, 20 + count);
					std::wcout << pCur_help->data;
				}
				else {
					SetColor(15, 3);
					GotoXY(50, 20 + count);
					std::wcout << pCur_help->data;
				}
				count++;
				pCur_help = pCur_help->pNext;
			}
			while (1) {
				if (_kbhit()) {
					char key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer > 0) {
							pointer--;
						}
						else {
							pointer = x - 1;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer < x - 1) {
							pointer++;
						}
						else {
							pointer = 0;
						}
						break;
					}
					if (key == 13) {
						pCur_help = pHead_help;
						if (pointer == -1) {

						}
						else{
							for (int i = 0; i < pointer; i++) {
								pCur_help = pCur_help->pNext;
							}
							check = 1;
							break;
						}
					}
					if (key == 27) {
						Sub_menu_time_staff(file_login);
					}
				}
			}
			if (check == 1) {
				break;
			}
		}

		char* folder = new char[wcslen(pCur_help->data) + 1];
		for (int i = 0; i < wcslen(pCur_help->data); i++) {
			folder[i] = pCur_help->data[i];
		}
		folder[wcslen(pCur_help->data)] = '\0';
		wchar_t* file = Create_file_4("Time", Create_second_folder("Semester", folder), ".txt");

		Create_semester_2(file,folder, file_login);
		Delete_Node_help_1(pHead_help);
	}
	else {
		std::wcout << "Don't have any school year had been created" << std::endl;
	}
	char key = toupper(_getch());
	if (key == 27)
	{
		Sub_menu_time_staff(file_login);
	}
}

void Create_semester_2(wchar_t* file, char* folder, wchar_t* file_login) {
	Node_help_1* pHead_help_1 = new Node_help_1;
	Node_help_1* pCur_help_1 = pHead_help_1;
	Node_time_semester* pHead_time = new Node_time_semester;
	Node_time_semester* pCur_time = pHead_time;
	std::wifstream fin_1(file);
	fin_1.imbue(std::locale(fin_1.getloc(), new std::codecvt_utf8<wchar_t>));
	std::wstring kt = L"0";
	std::wstring kt1 = L"";
	std::wstring str_2;
	wchar_t* a;
	SetColor(15, 0);
	while (!fin_1.eof()) {
		pCur_help_1->pNext = new Node_help_1;
		pCur_time->pNext = new Node_time_semester;
		std::getline(fin_1, str_2);
		if (kt.compare(str_2) == 0) {
			pCur_help_1->pNext->data = new wchar_t[str_2.length() + 1];
			str_2.copy(pCur_help_1->pNext->data, str_2.length(), 0);
			pCur_help_1->pNext->data[str_2.length()] = L'\0';
		}
		else if (kt1.compare(str_2) != 0) {
			pCur_help_1->pNext->data = new wchar_t[2];
			pCur_help_1->pNext->data[0] = L'1';
			pCur_help_1->pNext->data[1] = L'\0';
			int begin = 0;
			int end = str_2.find(',', begin);
			a = new wchar_t[end - begin + 1];
			str_2.copy(a, end - begin, begin);
			a[end - begin] = L'\0';
			pCur_time->pNext->start.Day = Convert_wchart_to_int(a, end - begin);
			delete[] a;

			begin = end + 1;
			end = str_2.find(',', begin);
			a = new wchar_t[end - begin + 1];
			str_2.copy(a, end - begin, begin);
			a[end - begin] = L'\0';
			pCur_time->pNext->start.Month = Convert_wchart_to_int(a, end - begin);
			delete[] a;

			begin = end + 1;
			end = str_2.find(',', begin);
			a = new wchar_t[end - begin + 1];
			str_2.copy(a, end - begin, begin);
			a[end - begin] = L'\0';
			pCur_time->pNext->start.Year = Convert_wchart_to_int(a, end - begin);
			delete[] a;

			begin = end + 1;
			end = str_2.find(',', begin);
			a = new wchar_t[end - begin + 1];
			str_2.copy(a, end - begin, begin);
			a[end - begin] = L'\0';
			pCur_time->pNext->end.Day = Convert_wchart_to_int(a, end - begin);
			delete[] a;

			begin = end + 1;
			end = str_2.find(',', begin);
			a = new wchar_t[end - begin + 1];
			str_2.copy(a, end - begin, begin);
			a[end - begin] = L'\0';
			pCur_time->pNext->end.Month = Convert_wchart_to_int(a, end - begin);
			delete[] a;

			begin = end + 1;
			end = str_2.length();
			a = new wchar_t[end - begin + 1];
			str_2.copy(a, end - begin, begin);
			a[end - begin] = L'\0';
			pCur_time->pNext->end.Year = Convert_wchart_to_int(a, end - begin);
			delete[] a;
		}
		pCur_help_1 = pCur_help_1->pNext;
		pCur_help_1->pNext = nullptr;
		pCur_time = pCur_time->pNext;
		pCur_time->pNext = nullptr;
	}
	if (pHead_help_1->pNext == nullptr) {
		delete pHead_help_1;
		pHead_help_1 = nullptr;
	}
	else {
		Node_help_1* pTemp_1 = pHead_help_1;
		pHead_help_1 = pHead_help_1->pNext;
		delete pTemp_1;
	}
	if (pHead_time->pNext == nullptr) {
		delete pHead_time;
		pHead_time = nullptr;
	}
	else {
		Node_time_semester* pTemp_2 = pHead_time;
		pHead_time = pHead_time->pNext;
		delete pTemp_2;
	}
	fin_1.close();



	pCur_help_1 = pHead_help_1;
	int x = 0;
	while (pCur_help_1 != nullptr) {
		x++;
		pCur_help_1 = pCur_help_1->pNext;
	}
	x--;
	int pointer = 0;
	int check = 0;
	a = new wchar_t[2];
	a[0] = L'0';
	a[1] = L'\0';
	while (1) {
		ShowCur(0);
		system("cls");
		pCur_help_1 = pHead_help_1;
		pCur_time = pHead_time;
		int count = 0;
		while (pCur_help_1->pNext != nullptr && pCur_time->pNext != nullptr) {
			if (count == pointer) {
				SetColor(15, 4);
				GotoXY(50, 20 + count);
				std::wcout << count + 1 << ".";
				if (wcscmp(a, pCur_help_1->data) == 0) {
					std::wcout << "Not create";
				}
				else {
					std::wcout << pCur_time->start.Day << L'//' << pCur_time->start.Month << L'//' << pCur_time->start.Year << L',' << pCur_time->end.Day << L'//' << pCur_time->end.Month << L'//' << pCur_time->end.Year;
				}
			}
			else {
				SetColor(15, 3);
				GotoXY(50, 20 + count);
				std::wcout << count + 1 << ".";
				if (wcscmp(a, pCur_help_1->data) == 0) {
					std::wcout << "Not create";
				}
				else {
					std::wcout << pCur_time->start.Day << L'//' << pCur_time->start.Month << L'//' << pCur_time->start.Year << L',' << pCur_time->end.Day << L'//' << pCur_time->end.Month << L'//' << pCur_time->end.Year;
				}
			}
			count++;
			pCur_help_1 = pCur_help_1->pNext;
			pCur_time = pCur_time->pNext;
		}
		while (1) {
			if (_kbhit()) {
				char key = _getch();
				if (key == 72 || key == 'w' || key == 'W') {
					if (pointer > 0) {
						pointer--;
					}
					else {
						pointer = x - 1;
					}
					break;
				}
				if (key == 80 || key == 's' || key == 'S') {
					if (pointer < x - 1) {
						pointer++;
					}
					else {
						pointer = 0;
					}
					break;
				}
				if (key == 13) {
					pCur_help_1 = pHead_help_1;
					pCur_time = pHead_time;
					if (pointer == -1) {

					}
					else {
						for (int i = 0; i < pointer; i++) {
							pCur_help_1 = pCur_help_1->pNext;
						}
						for (int i = 0; i < pointer; i++) {
							pCur_time = pCur_time->pNext;
						}
						check = 1;
						break;
					}
				}
				if (key == 27) {
					Create_semester_1(file_login);
				}
			}
		}
		if (check == 1) {
			break;
		}
	}

	system("cls");
	if (wcscmp(a, pCur_help_1->data) != 0) {
		std::wcout << "Semester had been created" << std::endl;
	}
	else {
		Time current_time;
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
		std::wcout << "Start date:" << std::endl;
		std::wcout << "Year: ";
		int pointer_1 = 5;
		int Max_List_Menu = 11;
		while (1) {
			//in menu ra man hinh
			GotoXY(7, 1);
			ShowCur(0);
			std::wcout << year[pointer_1] << std::endl;
			char key;
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer_1 < Max_List_Menu - 1) {
							pointer_1++;
						}
						else {
							pointer_1 = 0;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer_1 > 0) {
							pointer_1--;
						}
						else {
							pointer_1 = Max_List_Menu - 1;
						}
						break;
					}
					if (key == 13) {
						pCur_time->start.Year = year[pointer_1];
						break;
					}
				}
			}
			if (key == 13) {
				break;
			}
		}
		GotoXY(13, 1);
		std::wcout << "Month: ";
		pointer_1 = 0;
		Max_List_Menu = 12;
		while (1) {
			//in menu ra man hinh
			GotoXY(22, 1);
			ShowCur(0);
			if (month[pointer_1] < 10) {
				std::wcout << 0;
			}
			std::wcout << month[pointer_1] << std::endl;
			char key;
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer_1 < Max_List_Menu - 1) {
							pointer_1++;
						}
						else {
							pointer_1 = 0;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer_1 > 0) {
							pointer_1--;
						}
						else {
							pointer_1 = Max_List_Menu - 1;
						}
						break;
					}
					if (key == 13) {
						pCur_time->start.Month = month[pointer_1];
						break;
					}
				}
			}
			if (key == 13) {
				break;
			}
		}
		GotoXY(26, 1);
		std::wcout << "Day: ";
		if (pCur_time->start.Month == 1 || pCur_time->start.Month == 3 || pCur_time->start.Month == 5 || pCur_time->start.Month == 7 || pCur_time->start.Month == 8 || pCur_time->start.Month == 10 || pCur_time->start.Month == 12) {
			pointer_1 = 0;
			Max_List_Menu = 31;
			while (1) {
				//in menu ra man hinh
				GotoXY(33, 1);
				ShowCur(0);
				if (day_1[pointer_1] < 10) {
					std::wcout << 0;
				}
				std::wcout << day_1[pointer_1] << std::endl;
				char key;
				while (1) {
					if (_kbhit()) {
						key = _getch();
						if (key == 72 || key == 'w' || key == 'W') {
							if (pointer_1 < Max_List_Menu - 1) {
								pointer_1++;
							}
							else {
								pointer_1 = 0;
							}
							break;
						}
						if (key == 80 || key == 's' || key == 'S') {
							if (pointer_1 > 0) {
								pointer_1--;
							}
							else {
								pointer_1 = Max_List_Menu - 1;
							}
							break;
						}
						if (key == 13) {
							pCur_time->start.Day = day_1[pointer_1];
							break;
						}
					}
				}
				if (key == 13) {
					break;
				}
			}
		}
		else if (pCur_time->start.Month != 2) {
			pointer_1 = 0;
			Max_List_Menu = 30;
			while (1) {
				//in menu ra man hinh
				GotoXY(33, 1);
				ShowCur(0);
				if (day_2[pointer_1] < 10) {
					std::wcout << 0;
				}
				std::wcout << day_2[pointer_1] << std::endl;
				char key;
				while (1) {
					if (_kbhit()) {
						key = _getch();
						if (key == 72 || key == 'w' || key == 'W') {
							if (pointer_1 < Max_List_Menu - 1) {
								pointer_1++;
							}
							else {
								pointer_1 = 0;
							}
							break;
						}
						if (key == 80 || key == 's' || key == 'S') {
							if (pointer_1 > 0) {
								pointer_1--;
							}
							else {
								pointer_1 = Max_List_Menu - 1;
							}
							break;
						}
						if (key == 13) {
							pCur_time->start.Day = day_2[pointer_1];
							break;
						}
					}
				}
				if (key == 13) {
					break;
				}
			}
		}
		else if (checkYear(pCur_time->start.Year)) {
			pointer_1 = 0;
			Max_List_Menu = 29;
			while (1) {
				//in menu ra man hinh
				GotoXY(33, 1);
				ShowCur(0);
				if (day_3[pointer_1] < 10) {
					std::wcout << 0;
				}
				std::wcout << day_3[pointer_1] << std::endl;
				char key;
				while (1) {
					if (_kbhit()) {
						key = _getch();
						if (key == 72 || key == 'w' || key == 'W') {
							if (pointer_1 < Max_List_Menu - 1) {
								pointer_1++;
							}
							else {
								pointer_1 = 0;
							}
							break;
						}
						if (key == 80 || key == 's' || key == 'S') {
							if (pointer_1 > 0) {
								pointer_1--;
							}
							else {
								pointer_1 = Max_List_Menu - 1;
							}
							break;
						}
						if (key == 13) {
							pCur_time->start.Day = day_3[pointer_1];
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
			pointer_1 = 0;
			Max_List_Menu = 28;
			while (1) {
				//in menu ra man hinh
				GotoXY(33, 1);
				ShowCur(0);
				if (day_4[pointer_1] < 10) {
					std::wcout << 0;
				}
				std::wcout << day_4[pointer_1] << std::endl;
				char key;
				while (1) {
					if (_kbhit()) {
						key = _getch();
						if (key == 72 || key == 'w' || key == 'W') {
							if (pointer_1 < Max_List_Menu - 1) {
								pointer_1++;
							}
							else {
								pointer_1 = 0;
							}
							break;
						}
						if (key == 80 || key == 's' || key == 'S') {
							if (pointer_1 > 0) {
								pointer_1--;
							}
							else {
								pointer_1 = Max_List_Menu - 1;
							}
							break;
						}
						if (key == 13) {
							pCur_time->start.Day = day_4[pointer_1];
							break;
						}
					}
				}
				if (key == 13) {
					break;
				}
			}
		}

		GotoXY(0, 2);
		std::wcout << "End date:" << std::endl;
		std::wcout << "Year: ";
		pointer_1 = 5;
		Max_List_Menu = 11;
		while (1) {
			//in menu ra man hinh
			GotoXY(7, 3);
			ShowCur(0);
			std::wcout << year[pointer_1] << std::endl;
			char key;
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer_1 < Max_List_Menu - 1) {
							pointer_1++;
						}
						else {
							pointer_1 = 0;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer_1 > 0) {
							pointer_1--;
						}
						else {
							pointer_1 = Max_List_Menu - 1;
						}
						break;
					}
					if (key == 13) {
						pCur_time->end.Year = year[pointer_1];
						break;
					}
				}
			}
			if (key == 13) {
				break;
			}
		}
		GotoXY(13, 3);
		std::wcout << "Month: ";
		pointer_1 = 0;
		Max_List_Menu = 12;
		while (1) {
			//in menu ra man hinh
			GotoXY(22, 3);
			ShowCur(0);
			if (month[pointer_1] < 10) {
				std::wcout << 0;
			}
			std::wcout << month[pointer_1] << std::endl;
			char key;
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer_1 < Max_List_Menu - 1) {
							pointer_1++;
						}
						else {
							pointer_1 = 0;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer_1 > 0) {
							pointer_1--;
						}
						else {
							pointer_1 = Max_List_Menu - 1;
						}
						break;
					}
					if (key == 13) {
						pCur_time->end.Month = month[pointer_1];
						break;
					}
				}
			}
			if (key == 13) {
				break;
			}
		}
		GotoXY(26, 3);
		std::wcout << "Day: ";
		if (pCur_time->end.Month == 1 || pCur_time->end.Month == 3 || pCur_time->end.Month == 5 || pCur_time->end.Month == 7 || pCur_time->end.Month == 8 || pCur_time->end.Month == 10 || pCur_time->end.Month == 12) {
			pointer_1 = 0;
			Max_List_Menu = 31;
			while (1) {
				//in menu ra man hinh
				GotoXY(33, 3);
				ShowCur(0);
				if (day_1[pointer_1] < 10) {
					std::wcout << 0;
				}
				std::wcout << day_1[pointer_1] << std::endl;
				char key;
				while (1) {
					if (_kbhit()) {
						key = _getch();
						if (key == 72 || key == 'w' || key == 'W') {
							if (pointer_1 < Max_List_Menu - 1) {
								pointer_1++;
							}
							else {
								pointer_1 = 0;
							}
							break;
						}
						if (key == 80 || key == 's' || key == 'S') {
							if (pointer_1 > 0) {
								pointer_1--;
							}
							else {
								pointer_1 = Max_List_Menu - 1;
							}
							break;
						}
						if (key == 13) {
							pCur_time->end.Day = day_1[pointer_1];
							break;
						}
					}
				}
				if (key == 13) {
					break;
				}
			}
		}
		else if (pCur_time->end.Month != 2) {
			pointer_1 = 0;
			Max_List_Menu = 30;
			while (1) {
				//in menu ra man hinh
				GotoXY(33, 3);
				ShowCur(0);
				if (day_2[pointer_1] < 10) {
					std::wcout << 0;
				}
				std::wcout << day_2[pointer_1] << std::endl;
				char key;
				while (1) {
					if (_kbhit()) {
						key = _getch();
						if (key == 72 || key == 'w' || key == 'W') {
							if (pointer_1 < Max_List_Menu - 1) {
								pointer_1++;
							}
							else {
								pointer_1 = 0;
							}
							break;
						}
						if (key == 80 || key == 's' || key == 'S') {
							if (pointer_1 > 0) {
								pointer_1--;
							}
							else {
								pointer_1 = Max_List_Menu - 1;
							}
							break;
						}
						if (key == 13) {
							pCur_time->end.Day = day_2[pointer_1];
							break;
						}
					}
				}
				if (key == 13) {
					break;
				}
			}
		}
		else if (checkYear(pCur_time->end.Year)) {
			pointer_1 = 0;
			Max_List_Menu = 29;
			while (1) {
				//in menu ra man hinh
				GotoXY(33, 3);
				ShowCur(0);
				if (day_3[pointer_1] < 10) {
					std::wcout << 0;
				}
				std::wcout << day_3[pointer_1] << std::endl;
				char key;
				while (1) {
					if (_kbhit()) {
						key = _getch();
						if (key == 72 || key == 'w' || key == 'W') {
							if (pointer_1 < Max_List_Menu - 1) {
								pointer_1++;
							}
							else {
								pointer_1 = 0;
							}
							break;
						}
						if (key == 80 || key == 's' || key == 'S') {
							if (pointer_1 > 0) {
								pointer_1--;
							}
							else {
								pointer_1 = Max_List_Menu - 1;
							}
							break;
						}
						if (key == 13) {
							pCur_time->end.Day = day_3[pointer_1];
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
			pointer_1 = 0;
			Max_List_Menu = 28;
			while (1) {
				//in menu ra man hinh
				GotoXY(33, 3);
				ShowCur(0);
				if (day_4[pointer_1] < 10) {
					std::wcout << 0;
				}
				std::wcout << day_4[pointer_1] << std::endl;
				char key;
				while (1) {
					if (_kbhit()) {
						key = _getch();
						if (key == 72 || key == 'w' || key == 'W') {
							if (pointer_1 < Max_List_Menu - 1) {
								pointer_1++;
							}
							else {
								pointer_1 = 0;
							}
							break;
						}
						if (key == 80 || key == 's' || key == 'S') {
							if (pointer_1 > 0) {
								pointer_1--;
							}
							else {
								pointer_1 = Max_List_Menu - 1;
							}
							break;
						}
						if (key == 13) {
							pCur_time->end.Day = day_4[pointer_1];
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

		if (compare2Times(pCur_time->start, pCur_time->end)) {
			delete pCur_help_1->data;
			pCur_help_1->data = new wchar_t[2];
			pCur_help_1->data[0] = L'1';
			pCur_help_1->data[1] = L'\0';
			if (pointer == 0) {
				_mkdir(Create_third_folder("1", Create_second_folder("Semester", folder)));
			}
			else if (pointer == 1) {
				_mkdir(Create_third_folder("2", Create_second_folder("Semester", folder)));
			}
			else if (pointer == 2) {
				_mkdir(Create_third_folder("3", Create_second_folder("Semester", folder)));
			}
			std::wcout << "Input success" << std::endl;
		}
		else {
			std::wcout << "End date is smaller than start date. Input wrong" << std::endl;
		}
	}
	_wremove(file);
	a = new wchar_t[2];
	a[0] = L'0';
	a[1] = L'\0';
	pCur_help_1 = pHead_help_1;
	pCur_time = pHead_time;
	std::wofstream fout(file);
	fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
	while (pCur_help_1->pNext != nullptr) {
		if (wcscmp(a, pCur_help_1->data) == 0) {
			fout << pCur_help_1->data << std::endl;
		}
		else {
			fout << pCur_time->start.Day << L"," << pCur_time->start.Month << L"," << pCur_time->start.Year << L"," << pCur_time->end.Day << L"," << pCur_time->end.Month << L"," << pCur_time->end.Year << std::endl;
		}
		pCur_help_1 = pCur_help_1->pNext;
		pCur_time = pCur_time->pNext;
	}
	fout.close();

	char key = toupper(_getch());
	if (key == 27)
	{
		Create_semester_1(file_login);
	}
	Delete_Node_time_semester(pHead_time);
	Delete_Node_help_1(pHead_help_1);
	delete[] file;
	delete[] a;
}

void Choose_default_time_1(wchar_t* file_login, int n) {
	std::wstring str_2;
	if (checkFileWithFstream_wstring(L"Default_time.txt") && n == 0) {
		system("cls");
		std::wcout << "The default time had been choosed. You want to do it again ?" << std::endl;
		std::wcout << "Y to continue or N to exit" << std::endl;
		char key = _getch();
		if (key == 'N' || key == 'n' || key == 27)
		{
			Sub_menu_time_staff(file_login);
		}
		else if (key == 'Y' || key == 'y') {
			if (checkFileWithFstream_wstring(L"School_year.txt")) {
				int count = 0;
				Node_help_1* pHead_help = new Node_help_1;
				Node_help_1* pCur_help = pHead_help;
				std::wifstream fin("School_year.txt");
				fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
				while (!fin.eof()) {
					pCur_help->pNext = new Node_help_1;
					std::getline(fin, str_2);
					pCur_help->pNext->data = new wchar_t[str_2.length() + 1];
					str_2.copy(pCur_help->pNext->data, str_2.length(), 0);
					pCur_help->pNext->data[str_2.length()] = L'\0';
					pCur_help = pCur_help->pNext;
					pCur_help->pNext = nullptr;
					count++;
				}
				if (pHead_help->pNext == nullptr) {
					delete pHead_help;
					pHead_help = nullptr;
				}
				else {
					Node_help_1* pTemp = pHead_help;
					pHead_help = pHead_help->pNext;
					delete pTemp;
				}
				count--;
				fin.close();
				int x = 0;
				int check = 0;
				pCur_help = pHead_help;
				while (pCur_help != nullptr) {
					x++;
					pCur_help = pCur_help->pNext;
				}
				x--;
				int pointer = 0;
				while (1) {
					ShowCur(0);
					system("cls");
					pCur_help = pHead_help;
					int count = 0;
					while (pCur_help->pNext != nullptr) {
						if (count == pointer) {
							SetColor(15, 4);
							GotoXY(50, 20 + count);
							std::wcout << pCur_help->data;
						}
						else {
							SetColor(15, 3);
							GotoXY(50, 20 + count);
							std::wcout << pCur_help->data;
						}
						count++;
						pCur_help = pCur_help->pNext;
					}
					while (1) {
						if (_kbhit()) {
							char key = _getch();
							if (key == 72 || key == 'w' || key == 'W') {
								if (pointer > 0) {
									pointer--;
								}
								else {
									pointer = x - 1;
								}
								break;
							}
							if (key == 80 || key == 's' || key == 'S') {
								if (pointer < x - 1) {
									pointer++;
								}
								else {
									pointer = 0;
								}
								break;
							}
							if (key == 13) {
								pCur_help = pHead_help;
								if (pointer == -1) {

								}
								else {
									for (int i = 0; i < pointer; i++) {
										pCur_help = pCur_help->pNext;
									}
									check = 1;
									break;
								}
							}
							if (key == 27) {
								Sub_menu_time_staff(file_login);
							}
						}
					}
					if (check == 1) {
						break;
					}
				}

				char* folder = new char[wcslen(pCur_help->data) + 1];
				for (int i = 0; i < wcslen(pCur_help->data); i++) {
					folder[i] = pCur_help->data[i];
				}
				folder[wcslen(pCur_help->data)] = '\0';
				default_year_1 = folder;
				default_year_2 = new wchar_t[wcslen(pCur_help->data) + 1];
				for (int i = 0; i < wcslen(pCur_help->data); i++) {
					default_year_2[i] = default_year_1[i];
				}
				default_year_2[wcslen(pCur_help->data)] = L'\0';
				wchar_t* file = Create_file_4("Time", Create_second_folder("Semester", folder), ".txt");
				Choose_default_time_2(file, folder, file_login, default_year_1, default_year_2);
				Delete_Node_help_1(pHead_help);
			}
			else {
				std::wcout << "School year not created" << std::endl;
			}
			char key = toupper(_getch());
			if (key == 27)
			{
				Sub_menu_time_staff(file_login);
			}
		}
	}
	else {
	if (checkFileWithFstream_wstring(L"School_year.txt")) {
		int count = 0;
		Node_help_1* pHead_help = new Node_help_1;
		Node_help_1* pCur_help = pHead_help;
		std::wifstream fin("School_year.txt");
		fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
		while (!fin.eof()) {
			pCur_help->pNext = new Node_help_1;
			std::getline(fin, str_2);
			pCur_help->pNext->data = new wchar_t[str_2.length() + 1];
			str_2.copy(pCur_help->pNext->data, str_2.length(), 0);
			pCur_help->pNext->data[str_2.length()] = L'\0';
			pCur_help = pCur_help->pNext;
			pCur_help->pNext = nullptr;
			count++;
		}
		if (pHead_help->pNext == nullptr) {
			delete pHead_help;
			pHead_help = nullptr;
		}
		else {
			Node_help_1* pTemp = pHead_help;
			pHead_help = pHead_help->pNext;
			delete pTemp;
		}
		count--;
		fin.close();
		int x = 0;
		int check = 0;
		pCur_help = pHead_help;
		while (pCur_help != nullptr) {
			x++;
			pCur_help = pCur_help->pNext;
		}
		x--;
		int pointer = 0;
		while (1) {
			ShowCur(0);
			system("cls");
			pCur_help = pHead_help;
			int count = 0;
			while (pCur_help->pNext != nullptr) {
				if (count == pointer) {
					SetColor(15, 4);
					GotoXY(50, 20 + count);
					std::wcout << pCur_help->data;
				}
				else {
					SetColor(15, 3);
					GotoXY(50, 20 + count);
					std::wcout << pCur_help->data;
				}
				count++;
				pCur_help = pCur_help->pNext;
			}
			while (1) {
				if (_kbhit()) {
					char key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer > 0) {
							pointer--;
						}
						else {
							pointer = x - 1;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer < x - 1) {
							pointer++;
						}
						else {
							pointer = 0;
						}
						break;
					}
					if (key == 13) {
						pCur_help = pHead_help;
						if (pointer == -1) {

						}
						else {
							for (int i = 0; i < pointer; i++) {
								pCur_help = pCur_help->pNext;
							}
							check = 1;
							break;
						}
					}
					if (key == 27) {
						Sub_menu_time_staff(file_login);
					}
				}
			}
			if (check == 1) {
				break;
			}
		}

		char* folder = new char[wcslen(pCur_help->data) + 1];
		for (int i = 0; i < wcslen(pCur_help->data); i++) {
			folder[i] = pCur_help->data[i];
		}
		folder[wcslen(pCur_help->data)] = '\0';
		default_year_1 = folder;
		default_year_2 = new wchar_t[wcslen(pCur_help->data) + 1];
		for (int i = 0; i < wcslen(pCur_help->data); i++) {
			default_year_2[i] = default_year_1[i];
		}
		default_year_2[wcslen(pCur_help->data)] = L'\0';
		wchar_t* file = Create_file_4("Time", Create_second_folder("Semester", folder), ".txt");
		Choose_default_time_2(file, folder, file_login, default_year_1, default_year_2);
		Delete_Node_help_1(pHead_help);
	}
	else {
		std::wcout << "School year not created" << std::endl;
	}
	char key = toupper(_getch());
	if (key == 27)
	{
		Sub_menu_time_staff(file_login);
	}
	}
}

void Choose_default_time_2(wchar_t* file, char* folder, wchar_t* file_login, char* default_year_1, wchar_t* default_year_2) {
	std::wstring str_2;
	Node_help_1* pHead_help_1 = new Node_help_1;
	Node_help_1* pCur_help_1 = pHead_help_1;
	Node_time_semester* pHead_time = new Node_time_semester;
	Node_time_semester* pCur_time = pHead_time;
	std::wifstream fin_1(file);
	fin_1.imbue(std::locale(fin_1.getloc(), new std::codecvt_utf8<wchar_t>));
	std::wstring kt = L"0";
	std::wstring kt1 = L"";
	wchar_t* a;
	while (!fin_1.eof()) {
		pCur_help_1->pNext = new Node_help_1;
		pCur_time->pNext = new Node_time_semester;
		std::getline(fin_1, str_2);
		if (kt.compare(str_2) == 0) {
			pCur_help_1->pNext->data = new wchar_t[str_2.length() + 1];
			str_2.copy(pCur_help_1->pNext->data, str_2.length(), 0);
			pCur_help_1->pNext->data[str_2.length()] = L'\0';
		}
		else if (kt1.compare(str_2) != 0) {
			pCur_help_1->pNext->data = new wchar_t[2];
			pCur_help_1->pNext->data[0] = L'1';
			pCur_help_1->pNext->data[1] = L'\0';
			int begin = 0;
			int end = str_2.find(',', begin);
			a = new wchar_t[end - begin + 1];
			str_2.copy(a, end - begin, begin);
			a[end - begin] = L'\0';
			pCur_time->pNext->start.Day = Convert_wchart_to_int(a, end - begin);
			delete[] a;

			begin = end + 1;
			end = str_2.find(',', begin);
			a = new wchar_t[end - begin + 1];
			str_2.copy(a, end - begin, begin);
			a[end - begin] = L'\0';
			pCur_time->pNext->start.Month = Convert_wchart_to_int(a, end - begin);
			delete[] a;

			begin = end + 1;
			end = str_2.find(',', begin);
			a = new wchar_t[end - begin + 1];
			str_2.copy(a, end - begin, begin);
			a[end - begin] = L'\0';
			pCur_time->pNext->start.Year = Convert_wchart_to_int(a, end - begin);
			delete[] a;

			begin = end + 1;
			end = str_2.find(',', begin);
			a = new wchar_t[end - begin + 1];
			str_2.copy(a, end - begin, begin);
			a[end - begin] = L'\0';
			pCur_time->pNext->end.Day = Convert_wchart_to_int(a, end - begin);
			delete[] a;

			begin = end + 1;
			end = str_2.find(',', begin);
			a = new wchar_t[end - begin + 1];
			str_2.copy(a, end - begin, begin);
			a[end - begin] = L'\0';
			pCur_time->pNext->end.Month = Convert_wchart_to_int(a, end - begin);
			delete[] a;

			begin = end + 1;
			end = str_2.length();
			a = new wchar_t[end - begin + 1];
			str_2.copy(a, end - begin, begin);
			a[end - begin] = L'\0';
			pCur_time->pNext->end.Year = Convert_wchart_to_int(a, end - begin);
			delete[] a;
		}
		pCur_help_1 = pCur_help_1->pNext;
		pCur_help_1->pNext = nullptr;
		pCur_time = pCur_time->pNext;
		pCur_time->pNext = nullptr;
	}
	if (pHead_help_1->pNext == nullptr) {
		delete pHead_help_1;
		pHead_help_1 = nullptr;
	}
	else {
		Node_help_1* pTemp_1 = pHead_help_1;
		pHead_help_1 = pHead_help_1->pNext;
		delete pTemp_1;
	}
	if (pHead_time->pNext == nullptr) {
		delete pHead_time;
		pHead_time = nullptr;
	}
	else {
		Node_time_semester* pTemp_2 = pHead_time;
		pHead_time = pHead_time->pNext;
		delete pTemp_2;
	}
	fin_1.close();

	pCur_help_1 = pHead_help_1;
	int x = 0;
	while (pCur_help_1 != nullptr) {
		x++;
		pCur_help_1 = pCur_help_1->pNext;
	}
	x--;
	int pointer = 0;
	int check = 0;
	a = new wchar_t[2];
	a[0] = L'0';
	a[1] = L'\0';
	while (1) {
		ShowCur(0);
		system("cls");
		pCur_help_1 = pHead_help_1;
		pCur_time = pHead_time;
		int count = 0;
		while (pCur_help_1->pNext != nullptr) {
			if (count == pointer) {
				SetColor(15, 4);
				GotoXY(50, 20 + count);
				std::wcout << count + 1 << ".";
				if (wcscmp(a, pCur_help_1->data) == 0) {
					std::wcout << "Not create";
				}
				else {
					std::wcout << pCur_time->start.Day << L'//' << pCur_time->start.Month << L'//' << pCur_time->start.Year << L',' << pCur_time->end.Day << L'//' << pCur_time->end.Month << L'//' << pCur_time->end.Year;
				}
			}
			else {
				SetColor(15, 3);
				GotoXY(50, 20 + count);
				std::wcout << count + 1 << ".";
				if (wcscmp(a, pCur_help_1->data) == 0) {
					std::wcout << "Not create";
				}
				else {
					std::wcout << pCur_time->start.Day << L'//' << pCur_time->start.Month << L'//' << pCur_time->start.Year << L',' << pCur_time->end.Day << L'//' << pCur_time->end.Month << L'//' << pCur_time->end.Year;
				}
			}
			count++;
			pCur_help_1 = pCur_help_1->pNext;
			pCur_time = pCur_time->pNext;
		}
		while (1) {
			if (_kbhit()) {
				char key = _getch();
				if (key == 72 || key == 'w' || key == 'W') {
					if (pointer > 0) {
						pointer--;
					}
					else {
						pointer = x - 1;
					}
					break;
				}
				if (key == 80 || key == 's' || key == 'S') {
					if (pointer < x - 1) {
						pointer++;
					}
					else {
						pointer = 0;
					}
					break;
				}
				if (key == 13) {
					pCur_help_1 = pHead_help_1;
					pCur_time = pHead_time;
					if (pointer == -1) {

					}
					else {
						for (int i = 0; i < pointer; i++) {
							pCur_help_1 = pCur_help_1->pNext;
						}
						for (int i = 0; i < pointer; i++) {
							pCur_time = pCur_time->pNext;
						}
						check = 1;
						break;
					}
				}
				if (key == 27) {
					Choose_default_time_1(file_login,1);
				}
			}
		}
		if (check == 1) {
			break;
		}
	}
	Time current_time;
	Get_current_time_to_int(current_time);
	if (wcscmp(a, pCur_help_1->data) == 0) {
		system("cls");
		std::wcout << "Semester has not been created. You can not choose" << std::endl;
	}
	else {
		if (compare2Times(current_time.date, pCur_time->end)) {
			if (pointer == 0) {
				default_semester_1 = Create_third_folder("1", Create_second_folder("Semester", default_year_1));
			}
			else if (pointer == 1) {
				default_semester_1 = Create_third_folder("2", Create_second_folder("Semester", default_year_1));
			}
			else {
				default_semester_1 = Create_third_folder("3", Create_second_folder("Semester", default_year_1));
			}
			default_semester_2 = new wchar_t[strlen(default_semester_1) + 1];
			for (int i = 0; i < strlen(default_semester_1); i++) {
				default_semester_2[i] = default_semester_1[i];
			}
			default_semester_2[strlen(default_semester_1)] = L'\0';
			_wremove(L"Default_time.txt");
			std::wofstream fout(L"Default_time.txt");
			fout << default_year_1 << std::endl;
			fout << default_semester_1 << std::endl;
			fout.close();
			system("cls");
			std::wcout << "Choose success" << std::endl;
			char key = toupper(_getch());
			if (key == 27)
			{
				Sub_menu_time_staff(file_login);
			}
		}
		else {
			system("cls");
			std::wcout << "Semester had been ended. Choose fail" << std::endl;
			delete[] default_semester_1;
			delete[] default_semester_2;
			delete[] default_year_1;
			delete[] default_year_2;
		}
	}
	Delete_Node_help_1(pHead_help_1);
	Delete_Node_time_semester(pHead_time);

	

	char key = toupper(_getch());
	if (key == 27)
	{
		Choose_default_time_1(file_login,1);
	}
}

void View_list_of_class(wchar_t* file) {
	Node_cla* pHead_cla;
	std::wstring str_1;
	std::wifstream fin(L"Default_time.txt");
	fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
	std::getline(fin, str_1);
	fin.close();
	char* current_year = new char[str_1.length() + 1];
	for (int i = 0; i < str_1.length(); i++) {
		current_year[i] = str_1[i];
	}
	current_year[str_1.length()] = L'\0';
	system("cls");
	if (checkFileWithFstream_wstring(Create_file_4("Class", Create_second_folder("Class", current_year), ".txt"))) {
		pHead_cla = new Node_cla;
		Node_cla* pCur_cla = pHead_cla;
		std::wstring str;
		int x = 0;
		std::wifstream fin(Create_file_4("Class", Create_second_folder("Class", current_year), ".txt"));
		fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
		while (!fin.eof()) {
			pCur_cla->pNext = new Node_cla;
			std::getline(fin, str);
			pCur_cla->pNext->cla.Name = new wchar_t[str.length() + 1];
			str.copy(pCur_cla->pNext->cla.Name, str.length(), 0);
			pCur_cla->pNext->cla.Name[str.length()] = L'\0';
			pCur_cla = pCur_cla->pNext;
			pCur_cla->pNext = nullptr;
			x++;
		}
		if (pHead_cla->pNext == nullptr) {
			delete pHead_cla;
			pHead_cla = nullptr;
		}
		else {
			Node_cla* pTemp = pHead_cla;
			pHead_cla = pHead_cla->pNext;
			delete pTemp;
		}
		x--;
		int pointer = 0;
		int check = 0;
		while (1) {
			ShowCur(0);
			system("cls");
			pCur_cla = pHead_cla;
			int count = 0;
			while (pCur_cla->pNext != nullptr) {
				if (count == pointer) {
					SetColor(15, 4);
					GotoXY(50, 20 + count);
					std::wcout << pCur_cla->cla.Name;
				}
				else {
					SetColor(15, 3);
					GotoXY(50, 20 + count);
					std::wcout << pCur_cla->cla.Name;
				}
				count++;
				pCur_cla = pCur_cla->pNext;
			}
			while (1) {
				if (_kbhit()) {
					char key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer > 0) {
							pointer--;
						}
						else {
							pointer = x - 1;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer < x - 1) {
							pointer++;
						}
						else {
							pointer = 0;
						}
						break;
					}
					if (key == 13) {
						pCur_cla = pHead_cla;
						if (pointer == -1) {

						}
						else {
							for (int i = 0; i < pointer; i++) {
								pCur_cla = pCur_cla->pNext;
							}
							check = 1;
							break;
						}
					}
					if (key == 27) {
						Sub_menu_stu_staff(file);
					}
				}
			}
			if (check == 1) {
				break;
			}
		}
		View_list_of_student_class(pCur_cla->cla.Name, current_year,file);
	}
	else {

	}
	char key = toupper(_getch());
	if (key == 27)
	{
		Sub_menu_staff(file);
	}
}

void View_list_of_student_class(wchar_t* cla, char* current_year, wchar_t* file) {
	Node_stu* pHead_stu = new Node_stu;
	Node_stu* pCur_stu = pHead_stu;
	std::wstring str_1;
	std::wifstream fin(Create_file_3(cla, Create_second_folder("Class", current_year), ".txt"));
	fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
	std::getline(fin, str_1);
	std::getline(fin, str_1);
	fin.close();
	int loop = str_1.length() / 9;
	int begin = 0;
	int end = -1;
	wchar_t* a;
	for (int i = 0; i < loop; i++) {
		pCur_stu->pNext = new Node_stu;
		begin = end + 1;
		end = str_1.find(',', begin);
		a = new wchar_t[end - begin + 1];
		str_1.copy(a, end - begin, begin);
		a[end - begin] = L'\0';
		pCur_stu->pNext->stu.ID = Convert_wchart_to_int(a, end - begin);
		delete[] a;
		pCur_stu = pCur_stu->pNext;
		pCur_stu->pNext = nullptr;
	}
	if (pHead_stu->pNext == nullptr) {
		delete pHead_stu;
		pHead_stu = nullptr;
	}
	else {
		Node_stu* pTemp = pHead_stu;
		pHead_stu = pHead_stu->pNext;
		delete pTemp;
	}
	pCur_stu = pHead_stu;
	for (int i = 0; i < loop; i++) {
		wchar_t* file_1 = Convert_int_to_wchart(pCur_stu->stu.ID);
		wchar_t* file_2 = Create_file_2(file_1, Create_second_folder("Student", current_year), ".txt");
		std::wcout << file_2 << std::endl;
		std::wifstream fin(file_2);
		fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
		std::getline(fin, str_1);
		std::getline(fin, str_1);
		Read_file_stu(str_1, pCur_stu);
		fin.close();
		pCur_stu = pCur_stu->pNext;
	}
	system("cls");
	pCur_stu = pHead_stu;
	for (int i = 0; i < loop; i++) {
		std::wcout << i + 1 << L"," << pCur_stu->stu.ID << L"," << pCur_stu->stu.FirstName << L" " << pCur_stu->stu.LastName << L"," << pCur_stu->stu.Gender << L"," << pCur_stu->stu.Birthday.Day << L"/" << pCur_stu->stu.Birthday.Month << L"/" << pCur_stu->stu.Birthday.Year << L"," << pCur_stu->stu.SocialID << std::endl;
		pCur_stu = pCur_stu->pNext;
	}
	Delete_Node_stu(pHead_stu);
	char key = toupper(_getch());
	if (key == 27)
	{
		View_list_of_class(file);
	}
}

void Choose_cou_regis_time(wchar_t* file_login) {
	system("cls");
	Node_cla* pHead_cla;
	std::wstring str_1;
	std::wifstream fin(L"Default_time.txt");
	fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
	std::getline(fin, str_1);
	std::getline(fin, str_1);
	fin.close();
	char* current_semester = new char[str_1.length() + 1];
	for (int i = 0; i < str_1.length(); i++) {
		current_semester[i] = str_1[i];
	}
	current_semester[str_1.length()] = L'\0';
	if (checkFileWithFstream_wstring(Create_file_4("Time", current_semester, ".txt"))) {
		system("cls");
		std::wcout << "The default time had been choosed. You want to do it again ?" << std::endl;
		std::wcout << "Y to continue or N to exit" << std::endl;
		char key = _getch();
		if (key == 'N' || key == 'n' || key == 27)
		{
			Sub_menu_cou_staff(file_login);
		}
		else if (key == 'Y' || key == 'y') {
			_wremove(Create_file_4("Time", current_semester, ".txt"));
			Node_time_semester* pHead_time = new Node_time_semester;
			Node_time_semester* pCur_time = pHead_time;
			Time current_time;
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
			std::wcout << "Start date:" << std::endl;
			std::wcout << "Year: ";
			int pointer_1 = 5;
			int Max_List_Menu = 11;
			while (1) {
				//in menu ra man hinh
				GotoXY(7, 1);
				ShowCur(0);
				std::wcout << year[pointer_1] << std::endl;
				char key;
				while (1) {
					if (_kbhit()) {
						key = _getch();
						if (key == 72 || key == 'w' || key == 'W') {
							if (pointer_1 < Max_List_Menu - 1) {
								pointer_1++;
							}
							else {
								pointer_1 = 0;
							}
							break;
						}
						if (key == 80 || key == 's' || key == 'S') {
							if (pointer_1 > 0) {
								pointer_1--;
							}
							else {
								pointer_1 = Max_List_Menu - 1;
							}
							break;
						}
						if (key == 13) {
							pCur_time->start.Year = year[pointer_1];
							break;
						}
					}
				}
				if (key == 13) {
					break;
				}
			}
			GotoXY(13, 1);
			std::wcout << "Month: ";
			pointer_1 = 0;
			Max_List_Menu = 12;
			while (1) {
				//in menu ra man hinh
				GotoXY(22, 1);
				ShowCur(0);
				if (month[pointer_1] < 10) {
					std::wcout << 0;
				}
				std::wcout << month[pointer_1] << std::endl;
				char key;
				while (1) {
					if (_kbhit()) {
						key = _getch();
						if (key == 72 || key == 'w' || key == 'W') {
							if (pointer_1 < Max_List_Menu - 1) {
								pointer_1++;
							}
							else {
								pointer_1 = 0;
							}
							break;
						}
						if (key == 80 || key == 's' || key == 'S') {
							if (pointer_1 > 0) {
								pointer_1--;
							}
							else {
								pointer_1 = Max_List_Menu - 1;
							}
							break;
						}
						if (key == 13) {
							pCur_time->start.Month = month[pointer_1];
							break;
						}
					}
				}
				if (key == 13) {
					break;
				}
			}
			GotoXY(26, 1);
			std::wcout << "Day: ";
			if (pCur_time->start.Month == 1 || pCur_time->start.Month == 3 || pCur_time->start.Month == 5 || pCur_time->start.Month == 7 || pCur_time->start.Month == 8 || pCur_time->start.Month == 10 || pCur_time->start.Month == 12) {
				pointer_1 = 0;
				Max_List_Menu = 31;
				while (1) {
					//in menu ra man hinh
					GotoXY(33, 1);
					ShowCur(0);
					if (day_1[pointer_1] < 10) {
						std::wcout << 0;
					}
					std::wcout << day_1[pointer_1] << std::endl;
					char key;
					while (1) {
						if (_kbhit()) {
							key = _getch();
							if (key == 72 || key == 'w' || key == 'W') {
								if (pointer_1 < Max_List_Menu - 1) {
									pointer_1++;
								}
								else {
									pointer_1 = 0;
								}
								break;
							}
							if (key == 80 || key == 's' || key == 'S') {
								if (pointer_1 > 0) {
									pointer_1--;
								}
								else {
									pointer_1 = Max_List_Menu - 1;
								}
								break;
							}
							if (key == 13) {
								pCur_time->start.Day = day_1[pointer_1];
								break;
							}
						}
					}
					if (key == 13) {
						break;
					}
				}
			}
			else if (pCur_time->start.Month != 2) {
				pointer_1 = 0;
				Max_List_Menu = 30;
				while (1) {
					//in menu ra man hinh
					GotoXY(33, 1);
					ShowCur(0);
					if (day_2[pointer_1] < 10) {
						std::wcout << 0;
					}
					std::wcout << day_2[pointer_1] << std::endl;
					char key;
					while (1) {
						if (_kbhit()) {
							key = _getch();
							if (key == 72 || key == 'w' || key == 'W') {
								if (pointer_1 < Max_List_Menu - 1) {
									pointer_1++;
								}
								else {
									pointer_1 = 0;
								}
								break;
							}
							if (key == 80 || key == 's' || key == 'S') {
								if (pointer_1 > 0) {
									pointer_1--;
								}
								else {
									pointer_1 = Max_List_Menu - 1;
								}
								break;
							}
							if (key == 13) {
								pCur_time->start.Day = day_2[pointer_1];
								break;
							}
						}
					}
					if (key == 13) {
						break;
					}
				}
			}
			else if (checkYear(pCur_time->start.Year)) {
				pointer_1 = 0;
				Max_List_Menu = 29;
				while (1) {
					//in menu ra man hinh
					GotoXY(33, 1);
					ShowCur(0);
					if (day_3[pointer_1] < 10) {
						std::wcout << 0;
					}
					std::wcout << day_3[pointer_1] << std::endl;
					char key;
					while (1) {
						if (_kbhit()) {
							key = _getch();
							if (key == 72 || key == 'w' || key == 'W') {
								if (pointer_1 < Max_List_Menu - 1) {
									pointer_1++;
								}
								else {
									pointer_1 = 0;
								}
								break;
							}
							if (key == 80 || key == 's' || key == 'S') {
								if (pointer_1 > 0) {
									pointer_1--;
								}
								else {
									pointer_1 = Max_List_Menu - 1;
								}
								break;
							}
							if (key == 13) {
								pCur_time->start.Day = day_3[pointer_1];
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
				pointer_1 = 0;
				Max_List_Menu = 28;
				while (1) {
					//in menu ra man hinh
					GotoXY(33, 1);
					ShowCur(0);
					if (day_4[pointer_1] < 10) {
						std::wcout << 0;
					}
					std::wcout << day_4[pointer_1] << std::endl;
					char key;
					while (1) {
						if (_kbhit()) {
							key = _getch();
							if (key == 72 || key == 'w' || key == 'W') {
								if (pointer_1 < Max_List_Menu - 1) {
									pointer_1++;
								}
								else {
									pointer_1 = 0;
								}
								break;
							}
							if (key == 80 || key == 's' || key == 'S') {
								if (pointer_1 > 0) {
									pointer_1--;
								}
								else {
									pointer_1 = Max_List_Menu - 1;
								}
								break;
							}
							if (key == 13) {
								pCur_time->start.Day = day_4[pointer_1];
								break;
							}
						}
					}
					if (key == 13) {
						break;
					}
				}
			}

			GotoXY(0, 2);
			std::wcout << "End date:" << std::endl;
			std::wcout << "Year: ";
			pointer_1 = 5;
			Max_List_Menu = 11;
			while (1) {
				//in menu ra man hinh
				GotoXY(7, 3);
				ShowCur(0);
				std::wcout << year[pointer_1] << std::endl;
				char key;
				while (1) {
					if (_kbhit()) {
						key = _getch();
						if (key == 72 || key == 'w' || key == 'W') {
							if (pointer_1 < Max_List_Menu - 1) {
								pointer_1++;
							}
							else {
								pointer_1 = 0;
							}
							break;
						}
						if (key == 80 || key == 's' || key == 'S') {
							if (pointer_1 > 0) {
								pointer_1--;
							}
							else {
								pointer_1 = Max_List_Menu - 1;
							}
							break;
						}
						if (key == 13) {
							pCur_time->end.Year = year[pointer_1];
							break;
						}
					}
				}
				if (key == 13) {
					break;
				}
			}
			GotoXY(13, 3);
			std::wcout << "Month: ";
			pointer_1 = 0;
			Max_List_Menu = 12;
			while (1) {
				//in menu ra man hinh
				GotoXY(22, 3);
				ShowCur(0);
				if (month[pointer_1] < 10) {
					std::wcout << 0;
				}
				std::wcout << month[pointer_1] << std::endl;
				char key;
				while (1) {
					if (_kbhit()) {
						key = _getch();
						if (key == 72 || key == 'w' || key == 'W') {
							if (pointer_1 < Max_List_Menu - 1) {
								pointer_1++;
							}
							else {
								pointer_1 = 0;
							}
							break;
						}
						if (key == 80 || key == 's' || key == 'S') {
							if (pointer_1 > 0) {
								pointer_1--;
							}
							else {
								pointer_1 = Max_List_Menu - 1;
							}
							break;
						}
						if (key == 13) {
							pCur_time->end.Month = month[pointer_1];
							break;
						}
					}
				}
				if (key == 13) {
					break;
				}
			}
			GotoXY(26, 3);
			std::wcout << "Day: ";
			if (pCur_time->end.Month == 1 || pCur_time->end.Month == 3 || pCur_time->end.Month == 5 || pCur_time->end.Month == 7 || pCur_time->end.Month == 8 || pCur_time->end.Month == 10 || pCur_time->end.Month == 12) {
				pointer_1 = 0;
				Max_List_Menu = 31;
				while (1) {
					//in menu ra man hinh
					GotoXY(33, 3);
					ShowCur(0);
					if (day_1[pointer_1] < 10) {
						std::wcout << 0;
					}
					std::wcout << day_1[pointer_1] << std::endl;
					char key;
					while (1) {
						if (_kbhit()) {
							key = _getch();
							if (key == 72 || key == 'w' || key == 'W') {
								if (pointer_1 < Max_List_Menu - 1) {
									pointer_1++;
								}
								else {
									pointer_1 = 0;
								}
								break;
							}
							if (key == 80 || key == 's' || key == 'S') {
								if (pointer_1 > 0) {
									pointer_1--;
								}
								else {
									pointer_1 = Max_List_Menu - 1;
								}
								break;
							}
							if (key == 13) {
								pCur_time->end.Day = day_1[pointer_1];
								break;
							}
						}
					}
					if (key == 13) {
						break;
					}
				}
			}
			else if (pCur_time->end.Month != 2) {
				pointer_1 = 0;
				Max_List_Menu = 30;
				while (1) {
					//in menu ra man hinh
					GotoXY(33, 3);
					ShowCur(0);
					if (day_2[pointer_1] < 10) {
						std::wcout << 0;
					}
					std::wcout << day_2[pointer_1] << std::endl;
					char key;
					while (1) {
						if (_kbhit()) {
							key = _getch();
							if (key == 72 || key == 'w' || key == 'W') {
								if (pointer_1 < Max_List_Menu - 1) {
									pointer_1++;
								}
								else {
									pointer_1 = 0;
								}
								break;
							}
							if (key == 80 || key == 's' || key == 'S') {
								if (pointer_1 > 0) {
									pointer_1--;
								}
								else {
									pointer_1 = Max_List_Menu - 1;
								}
								break;
							}
							if (key == 13) {
								pCur_time->end.Day = day_2[pointer_1];
								break;
							}
						}
					}
					if (key == 13) {
						break;
					}
				}
			}
			else if (checkYear(pCur_time->end.Year)) {
				pointer_1 = 0;
				Max_List_Menu = 29;
				while (1) {
					//in menu ra man hinh
					GotoXY(33, 3);
					ShowCur(0);
					if (day_3[pointer_1] < 10) {
						std::wcout << 0;
					}
					std::wcout << day_3[pointer_1] << std::endl;
					char key;
					while (1) {
						if (_kbhit()) {
							key = _getch();
							if (key == 72 || key == 'w' || key == 'W') {
								if (pointer_1 < Max_List_Menu - 1) {
									pointer_1++;
								}
								else {
									pointer_1 = 0;
								}
								break;
							}
							if (key == 80 || key == 's' || key == 'S') {
								if (pointer_1 > 0) {
									pointer_1--;
								}
								else {
									pointer_1 = Max_List_Menu - 1;
								}
								break;
							}
							if (key == 13) {
								pCur_time->end.Day = day_3[pointer_1];
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
				pointer_1 = 0;
				Max_List_Menu = 28;
				while (1) {
					//in menu ra man hinh
					GotoXY(33, 3);
					ShowCur(0);
					if (day_4[pointer_1] < 10) {
						std::wcout << 0;
					}
					std::wcout << day_4[pointer_1] << std::endl;
					char key;
					while (1) {
						if (_kbhit()) {
							key = _getch();
							if (key == 72 || key == 'w' || key == 'W') {
								if (pointer_1 < Max_List_Menu - 1) {
									pointer_1++;
								}
								else {
									pointer_1 = 0;
								}
								break;
							}
							if (key == 80 || key == 's' || key == 'S') {
								if (pointer_1 > 0) {
									pointer_1--;
								}
								else {
									pointer_1 = Max_List_Menu - 1;
								}
								break;
							}
							if (key == 13) {
								pCur_time->end.Day = day_4[pointer_1];
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

			std::wofstream fout(Create_file_4("Time", current_semester, ".txt"));
			fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
			fout << pCur_time->start.Day << L"," << pCur_time->start.Month << L"," << pCur_time->start.Year << L"," << pCur_time->end.Day << L"," << pCur_time->end.Month << L"," << pCur_time->end.Year << std::endl;
			fout.close();
			std::wcout << "Choose success" << std::endl;
			pCur_time->pNext = nullptr;
			Delete_Node_time_semester(pHead_time);
		}
	}
	else {
	Node_time_semester* pHead_time = new Node_time_semester;
	Node_time_semester* pCur_time = pHead_time;
	Time current_time;
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
	std::wcout << "Start date:" << std::endl;
	std::wcout << "Year: ";
	int pointer_1 = 5;
	int Max_List_Menu = 11;
	while (1) {
		//in menu ra man hinh
		GotoXY(7, 1);
		ShowCur(0);
		std::wcout << year[pointer_1] << std::endl;
		char key;
		while (1) {
			if (_kbhit()) {
				key = _getch();
				if (key == 72 || key == 'w' || key == 'W') {
					if (pointer_1 < Max_List_Menu - 1) {
						pointer_1++;
					}
					else {
						pointer_1 = 0;
					}
					break;
				}
				if (key == 80 || key == 's' || key == 'S') {
					if (pointer_1 > 0) {
						pointer_1--;
					}
					else {
						pointer_1 = Max_List_Menu - 1;
					}
					break;
				}
				if (key == 13) {
					pCur_time->start.Year = year[pointer_1];
					break;
				}
			}
		}
		if (key == 13) {
			break;
		}
	}
	GotoXY(13, 1);
	std::wcout << "Month: ";
	pointer_1 = 0;
	Max_List_Menu = 12;
	while (1) {
		//in menu ra man hinh
		GotoXY(22, 1);
		ShowCur(0);
		if (month[pointer_1] < 10) {
			std::wcout << 0;
		}
		std::wcout << month[pointer_1] << std::endl;
		char key;
		while (1) {
			if (_kbhit()) {
				key = _getch();
				if (key == 72 || key == 'w' || key == 'W') {
					if (pointer_1 < Max_List_Menu - 1) {
						pointer_1++;
					}
					else {
						pointer_1 = 0;
					}
					break;
				}
				if (key == 80 || key == 's' || key == 'S') {
					if (pointer_1 > 0) {
						pointer_1--;
					}
					else {
						pointer_1 = Max_List_Menu - 1;
					}
					break;
				}
				if (key == 13) {
					pCur_time->start.Month = month[pointer_1];
					break;
				}
			}
		}
		if (key == 13) {
			break;
		}
	}
	GotoXY(26, 1);
	std::wcout << "Day: ";
	if (pCur_time->start.Month == 1 || pCur_time->start.Month == 3 || pCur_time->start.Month == 5 || pCur_time->start.Month == 7 || pCur_time->start.Month == 8 || pCur_time->start.Month == 10 || pCur_time->start.Month == 12) {
		pointer_1 = 0;
		Max_List_Menu = 31;
		while (1) {
			//in menu ra man hinh
			GotoXY(33, 1);
			ShowCur(0);
			if (day_1[pointer_1] < 10) {
				std::wcout << 0;
			}
			std::wcout << day_1[pointer_1] << std::endl;
			char key;
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer_1 < Max_List_Menu - 1) {
							pointer_1++;
						}
						else {
							pointer_1 = 0;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer_1 > 0) {
							pointer_1--;
						}
						else {
							pointer_1 = Max_List_Menu - 1;
						}
						break;
					}
					if (key == 13) {
						pCur_time->start.Day = day_1[pointer_1];
						break;
					}
				}
			}
			if (key == 13) {
				break;
			}
		}
	}
	else if (pCur_time->start.Month != 2) {
		pointer_1 = 0;
		Max_List_Menu = 30;
		while (1) {
			//in menu ra man hinh
			GotoXY(33, 1);
			ShowCur(0);
			if (day_2[pointer_1] < 10) {
				std::wcout << 0;
			}
			std::wcout << day_2[pointer_1] << std::endl;
			char key;
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer_1 < Max_List_Menu - 1) {
							pointer_1++;
						}
						else {
							pointer_1 = 0;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer_1 > 0) {
							pointer_1--;
						}
						else {
							pointer_1 = Max_List_Menu - 1;
						}
						break;
					}
					if (key == 13) {
						pCur_time->start.Day = day_2[pointer_1];
						break;
					}
				}
			}
			if (key == 13) {
				break;
			}
		}
	}
	else if (checkYear(pCur_time->start.Year)) {
		pointer_1 = 0;
		Max_List_Menu = 29;
		while (1) {
			//in menu ra man hinh
			GotoXY(33, 1);
			ShowCur(0);
			if (day_3[pointer_1] < 10) {
				std::wcout << 0;
			}
			std::wcout << day_3[pointer_1] << std::endl;
			char key;
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer_1 < Max_List_Menu - 1) {
							pointer_1++;
						}
						else {
							pointer_1 = 0;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer_1 > 0) {
							pointer_1--;
						}
						else {
							pointer_1 = Max_List_Menu - 1;
						}
						break;
					}
					if (key == 13) {
						pCur_time->start.Day = day_3[pointer_1];
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
		pointer_1 = 0;
		Max_List_Menu = 28;
		while (1) {
			//in menu ra man hinh
			GotoXY(33, 1);
			ShowCur(0);
			if (day_4[pointer_1] < 10) {
				std::wcout << 0;
			}
			std::wcout << day_4[pointer_1] << std::endl;
			char key;
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer_1 < Max_List_Menu - 1) {
							pointer_1++;
						}
						else {
							pointer_1 = 0;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer_1 > 0) {
							pointer_1--;
						}
						else {
							pointer_1 = Max_List_Menu - 1;
						}
						break;
					}
					if (key == 13) {
						pCur_time->start.Day = day_4[pointer_1];
						break;
					}
				}
			}
			if (key == 13) {
				break;
			}
		}
	}

	GotoXY(0, 2);
	std::wcout << "End date:" << std::endl;
	std::wcout << "Year: ";
	pointer_1 = 5;
	Max_List_Menu = 11;
	while (1) {
		//in menu ra man hinh
		GotoXY(7, 3);
		ShowCur(0);
		std::wcout << year[pointer_1] << std::endl;
		char key;
		while (1) {
			if (_kbhit()) {
				key = _getch();
				if (key == 72 || key == 'w' || key == 'W') {
					if (pointer_1 < Max_List_Menu - 1) {
						pointer_1++;
					}
					else {
						pointer_1 = 0;
					}
					break;
				}
				if (key == 80 || key == 's' || key == 'S') {
					if (pointer_1 > 0) {
						pointer_1--;
					}
					else {
						pointer_1 = Max_List_Menu - 1;
					}
					break;
				}
				if (key == 13) {
					pCur_time->end.Year = year[pointer_1];
					break;
				}
			}
		}
		if (key == 13) {
			break;
		}
	}
	GotoXY(13, 3);
	std::wcout << "Month: ";
	pointer_1 = 0;
	Max_List_Menu = 12;
	while (1) {
		//in menu ra man hinh
		GotoXY(22, 3);
		ShowCur(0);
		if (month[pointer_1] < 10) {
			std::wcout << 0;
		}
		std::wcout << month[pointer_1] << std::endl;
		char key;
		while (1) {
			if (_kbhit()) {
				key = _getch();
				if (key == 72 || key == 'w' || key == 'W') {
					if (pointer_1 < Max_List_Menu - 1) {
						pointer_1++;
					}
					else {
						pointer_1 = 0;
					}
					break;
				}
				if (key == 80 || key == 's' || key == 'S') {
					if (pointer_1 > 0) {
						pointer_1--;
					}
					else {
						pointer_1 = Max_List_Menu - 1;
					}
					break;
				}
				if (key == 13) {
					pCur_time->end.Month = month[pointer_1];
					break;
				}
			}
		}
		if (key == 13) {
			break;
		}
	}
	GotoXY(26, 3);
	std::wcout << "Day: ";
	if (pCur_time->end.Month == 1 || pCur_time->end.Month == 3 || pCur_time->end.Month == 5 || pCur_time->end.Month == 7 || pCur_time->end.Month == 8 || pCur_time->end.Month == 10 || pCur_time->end.Month == 12) {
		pointer_1 = 0;
		Max_List_Menu = 31;
		while (1) {
			//in menu ra man hinh
			GotoXY(33, 3);
			ShowCur(0);
			if (day_1[pointer_1] < 10) {
				std::wcout << 0;
			}
			std::wcout << day_1[pointer_1] << std::endl;
			char key;
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer_1 < Max_List_Menu - 1) {
							pointer_1++;
						}
						else {
							pointer_1 = 0;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer_1 > 0) {
							pointer_1--;
						}
						else {
							pointer_1 = Max_List_Menu - 1;
						}
						break;
					}
					if (key == 13) {
						pCur_time->end.Day = day_1[pointer_1];
						break;
					}
				}
			}
			if (key == 13) {
				break;
			}
		}
	}
	else if (pCur_time->end.Month != 2) {
		pointer_1 = 0;
		Max_List_Menu = 30;
		while (1) {
			//in menu ra man hinh
			GotoXY(33, 3);
			ShowCur(0);
			if (day_2[pointer_1] < 10) {
				std::wcout << 0;
			}
			std::wcout << day_2[pointer_1] << std::endl;
			char key;
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer_1 < Max_List_Menu - 1) {
							pointer_1++;
						}
						else {
							pointer_1 = 0;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer_1 > 0) {
							pointer_1--;
						}
						else {
							pointer_1 = Max_List_Menu - 1;
						}
						break;
					}
					if (key == 13) {
						pCur_time->end.Day = day_2[pointer_1];
						break;
					}
				}
			}
			if (key == 13) {
				break;
			}
		}
	}
	else if (checkYear(pCur_time->end.Year)) {
		pointer_1 = 0;
		Max_List_Menu = 29;
		while (1) {
			//in menu ra man hinh
			GotoXY(33, 3);
			ShowCur(0);
			if (day_3[pointer_1] < 10) {
				std::wcout << 0;
			}
			std::wcout << day_3[pointer_1] << std::endl;
			char key;
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer_1 < Max_List_Menu - 1) {
							pointer_1++;
						}
						else {
							pointer_1 = 0;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer_1 > 0) {
							pointer_1--;
						}
						else {
							pointer_1 = Max_List_Menu - 1;
						}
						break;
					}
					if (key == 13) {
						pCur_time->end.Day = day_3[pointer_1];
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
		pointer_1 = 0;
		Max_List_Menu = 28;
		while (1) {
			//in menu ra man hinh
			GotoXY(33, 3);
			ShowCur(0);
			if (day_4[pointer_1] < 10) {
				std::wcout << 0;
			}
			std::wcout << day_4[pointer_1] << std::endl;
			char key;
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 72 || key == 'w' || key == 'W') {
						if (pointer_1 < Max_List_Menu - 1) {
							pointer_1++;
						}
						else {
							pointer_1 = 0;
						}
						break;
					}
					if (key == 80 || key == 's' || key == 'S') {
						if (pointer_1 > 0) {
							pointer_1--;
						}
						else {
							pointer_1 = Max_List_Menu - 1;
						}
						break;
					}
					if (key == 13) {
						pCur_time->end.Day = day_4[pointer_1];
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

	std::wofstream fout(Create_file_4("Time", current_semester, ".txt"));
	fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
	fout << pCur_time->start.Day << L"," << pCur_time->start.Month << L"," << pCur_time->start.Year << L"," << pCur_time->end.Day << L"," << pCur_time->end.Month << L"," << pCur_time->end.Year << std::endl;
	fout.close();
	std::wcout << "Choose success" << std::endl;
	pCur_time->pNext = nullptr;
	Delete_Node_time_semester(pHead_time);
	}
	char key = toupper(_getch());
	if (key == 27)
	{
		Sub_menu_cou_staff(file_login);
	}
}

void Sub_menu_time_staff(wchar_t* file) {
	int Max_List_Menu = 4;
	int flag = 0;
	int pointer = 0;
	SetColor(15, 0);
	std::wstring menu[] = { L"Create School Year", L"Create Semester", L"Choose Default Time" ,L"Exit"};
	while (1) {
		//xoa man hinh
		ShowCur(0);
		system("cls");
		//in menu ra man hinh
		for (int i = 0; i < Max_List_Menu; i++)
		{
			if (pointer == i) {
				SetColor(15, 4);
				GotoXY(50, 20 + i);
				std::wcout << "    " << menu[i] << std::endl;
			}
			else {
				SetColor(15, 3);
				GotoXY(50, 20 + i);
				std::wcout << "    " << menu[i] << std::endl;
			}

		}
		while (1) {
			if (_kbhit()) {
				char key = _getch();
				if (key == 72 || key == 'w' || key == 'W') {
					if (pointer > 0) {
						pointer--;
					}
					else {
						pointer = Max_List_Menu - 1;
					}
					break;
				}
				if (key == 80 || key == 's' || key == 'S') {
					if (pointer < Max_List_Menu - 1) {
						pointer++;
					}
					else {
						pointer = 0;
					}
					break;
				}
				if (key == 13) {
					switch (pointer) {
					case 0:
						Create_school_year(file);
						Sleep(100000);
						break;
					case 1:
						Create_semester_1(file);
						Sleep(100000);
						break;
					case 2:
						Choose_default_time_1(file, 0);
						Sleep(100000);
						break;
					case 3:
						Sub_menu_staff(file);
						break;
					}
					break;
				}
				if (key == 27) {
					Sub_menu_staff(file);
					break;
				}
			}
		}
		Sleep(100);
	}
}

void Sub_menu_cou_staff(wchar_t* file) {
	int Max_List_Menu = 6;
	int flag = 0;
	int pointer = 0;
	SetColor(15, 0);
	std::wstring menu[] = { L"Choose Course Registration Time",L"Input Course", L"View List Of Course", L"Update Course" ,L"Delete Course",L"Exit" };
	while (1) {
		//xoa man hinh
		ShowCur(0);
		system("cls");
		//in menu ra man hinh
		for (int i = 0; i < Max_List_Menu; i++)
		{
			if (pointer == i) {
				SetColor(15, 4);
				GotoXY(50, 20 + i);
				std::wcout << "    " << menu[i] << std::endl;
			}
			else {
				SetColor(15, 3);
				GotoXY(50, 20 + i);
				std::wcout << "    " << menu[i] << std::endl;
			}

		}
		while (1) {
			if (_kbhit()) {
				char key = _getch();
				if (key == 72 || key == 'w' || key == 'W') {
					if (pointer > 0) {
						pointer--;
					}
					else {
						pointer = Max_List_Menu - 1;
					}
					break;
				}
				if (key == 80 || key == 's' || key == 'S') {
					if (pointer < Max_List_Menu - 1) {
						pointer++;
					}
					else {
						pointer = 0;
					}
					break;
				}
				if (key == 13) {
					switch (pointer) {
					case 0:
						Choose_cou_regis_time(file);
						Sleep(100000);
						break;
					case 1:
						// Input_course
						Sleep(100000);
						break;
					case 2:
						// View_course
						Sleep(100000);
						break;
					case 3:
						// Update_course
						Sleep(100000);
						break;
					case 4:
						// Delete_course
						Sleep(100000);
						break;
					case 5:
						Sub_menu_staff(file);
						break;
					}
					break;
				}
				if (key == 27) {
					Sub_menu_staff(file);
					break;
				}
			}
		}
		Sleep(100);
	}
}

void Sub_menu_stu_staff(wchar_t* file) {
	Node_stu* pHead_stu;
	Node_cla* pHead_cla;
	int Max_List_Menu = 4;
	int flag = 0;
	int pointer = 0;
	SetColor(15, 0);
	std::wstring menu[] = { L"Input Student", L"View List Of Class", L"Score", L"Exit" };
	while (1) {
		//xoa man hinh
		ShowCur(0);
		system("cls");
		//in menu ra man hinh
		for (int i = 0; i < Max_List_Menu; i++)
		{
			if (pointer == i) {
				SetColor(15, 4);
				GotoXY(50, 20 + i);
				std::wcout << "    " << menu[i] << std::endl;
			}
			else {
				SetColor(15, 3);
				GotoXY(50, 20 + i);
				std::wcout << "    " << menu[i] << std::endl;
			}

		}
		while (1) {
			if (_kbhit()) {
				char key = _getch();
				if (key == 72 || key == 'w' || key == 'W') {
					if (pointer > 0) {
						pointer--;
					}
					else {
						pointer = Max_List_Menu - 1;
					}
					break;
				}
				if (key == 80 || key == 's' || key == 'S') {
					if (pointer < Max_List_Menu - 1) {
						pointer++;
					}
					else {
						pointer = 0;
					}
					break;
				}
				if (key == 13) {
					switch (pointer) {
					case 0:
						Input_student_data(pHead_stu, pHead_cla, file);
						Sleep(100000);
						break;
					case 1:
						View_list_of_class(file);
						Sleep(100000);
						break;
					case 2:

						Sleep(100000);
						break;
					case 3:
						Sub_menu_staff(file);
						break;
					}
					break;
				}
				if (key == 27) {
					Sub_menu_staff(file);
					break;
				}
			}
		}
		Sleep(100);
	}
}

void Sub_menu_staff(wchar_t* file) {
	int Max_List_Menu = 7;
	int flag = 0;
	SetColor(15, 0);
	std::wstring menu[] = { L"Information",L"Change Pass",L"Time",L"Course",L"Student",L"Log Out", L"Exit" };
	int pointer = 0;
	Node_cou* pHead_cou;
	while (1) {
		//xoa man hinh
		ShowCur(0);
		system("cls");
		//in menu ra man hinh
		for (int i = 0; i < Max_List_Menu; i++)
		{
			if (pointer == i) {
				SetColor(15, 4);
				GotoXY(50, 20 + i);
				std::wcout << "    " << menu[i] << std::endl;
			}
			else {
				SetColor(15, 3);
				GotoXY(50, 20 + i);
				std::wcout << "    " << menu[i] << std::endl;
			}

		}
		while (1) {
			if (_kbhit()) {
				char key = _getch();
				if (key == 72 || key == 'w' || key == 'W') {
					if (pointer > 0) {
						pointer--;
					}
					else {
						pointer = Max_List_Menu - 1;
					}
					break;
				}
				if (key == 80 || key == 's' || key == 'S') {
					if (pointer < Max_List_Menu - 1) {
						pointer++;
					}
					else {
						pointer = 0;
					}
					break;
				}
				if (key == 13) {
					switch (pointer) {
					case 0:
						Screen_inf_to_console_staff(file);
						Sleep(100000);
						break;
					case 1:
						Change_pass_staff(file);
						Sleep(100000);
						break;
					case 2:
						Sub_menu_time_staff(file);
						Sleep(100000);
						break;
					case 3:
						Sub_menu_cou_staff(file);
						Sleep(100000);
						break;
					case 4:
						Sub_menu_stu_staff(file);
						Sleep(100000);
						break;
					case 5:
						Menu_staff();
						break;
					case 6: 
						Exit();
						flag = -1;
						break;
					}
					break;
				}
			}
		}
		if (flag == -1) {
			delete[] file;
			break;
		}
		Sleep(100);
	}
	std::cout << "Thank you very much. Bye!" << std::endl;
	Sleep(100);
	_getch();
}

void Menu_staff() {
	SetColor(15, 0);
	wchar_t* file = Login_staff();
	Sub_menu_staff(file);
	delete[] file;
}

void main() {
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);

	{
		//bỏ các hàm thực thi vào đây

		Menu_staff();
	}

	if (_CrtDumpMemoryLeaks())
	{
		std::wcout << "Leak";
	}
	else std::wcout << "No";

}