#include "Struct.h"
#include "Help.h"
#include "Save.h"
#include "Time.h"
#include "Save.h"
#include "Input.h"
#include "Delete.h"
#include "Read.h"
#include "Login.h"

bool Check_pass(wchar_t* pass, wchar_t* input) {
	int n = wcslen(pass);
	int m = wcslen(input);
	if (m != n)	return false;
	for (int i = 0; i < n; i++) {
		if (pass[i] != input[i]) {
			return false;
		}
	}
	return true;
}

wchar_t* Login() {
	Time current_time;
	Get_current_time_to_int(current_time);
	char* current_year = Convert_int_to_char(current_time.date.Year);
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
		file = Create_file_1(filename, Create_second_folder("Student", current_year), ".txt");
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

void Change_pass(wchar_t* file) {
	system("cls");
	SetColor(15, 0);
	Node_stu* pHead_stu = new Node_stu;
	std::wstring str;
	std::wifstream fin(file);
	fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
	std::getline(fin, str);
	std::getline(fin, str);
	Read_file_stu(str, pHead_stu);
	fin.close();
	_wremove(file);
	//std::wcin.ignore();
	std::wcout << "Input the new password: ";
	std::getline(std::wcin, str);
	pHead_stu->stu.account.Pass = new wchar_t[str.length() + 1];
	str.copy(pHead_stu->stu.account.Pass, str.length(), 0);
	pHead_stu->stu.account.Pass[str.length()] = L'\0';
	std::wofstream fout(file);
	fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
	fout << pHead_stu->stu.account.ID << L"," << pHead_stu->stu.account.Pass << std::endl;
	fout << pHead_stu->stu.ID << L"," << pHead_stu->stu.FirstName << L"," << pHead_stu->stu.LastName << L"," << pHead_stu->stu.Gender << L"," << pHead_stu->stu.Birthday.Day << L"/" << pHead_stu->stu.Birthday.Month << L"/" << pHead_stu->stu.Birthday.Year << L"," << pHead_stu->stu.SocialID << std::endl;
	fout.close();
	pHead_stu->pNext = nullptr;
	Delete_Node_stu(pHead_stu);
	std::wcout << "Change success" << std::endl;
	char key = toupper(_getch());
	if (key == 27)
	{
		Sub_menu_stu(file);
	}
}

void Screen_stu_to_console(wchar_t* file) {
	system("cls");
	SetColor(15, 0);
	Node_stu* pHead_stu = new Node_stu;
	std::wstring str;
	std::wifstream fin(file);
	fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
	std::getline(fin, str);
	std::getline(fin, str);
	Read_file_stu(str, pHead_stu);
	fin.close();
	std::wcout << L"Student ID: " << pHead_stu->stu.ID << std::endl;
	std::wcout << L"Student Name: " << pHead_stu->stu.FirstName << L" " << pHead_stu->stu.LastName << std::endl;
	std::wcout << L"Gender: " << pHead_stu->stu.Gender << std::endl;
	std::wcout << L"Birthday: " << pHead_stu->stu.Birthday.Day << L"/" << pHead_stu->stu.Birthday.Month << L"/" << pHead_stu->stu.Birthday.Year << std::endl;
	std::wcout << L"Social ID: " << pHead_stu->stu.SocialID << std::endl;
	pHead_stu->pNext = nullptr;
	Delete_Node_stu(pHead_stu);
	char key = toupper(_getch());
	if (key == 27)
	{
		Sub_menu_stu(file);
	}
}

void Sub_menu_stu(wchar_t* file) {
	int Max_List_Menu = 4;
	int flag = 0;
	SetColor(15, 0);
	std::wstring menu[] = { L"Information",L"Change pass",L"Log out", L"Exit"};
	int pointer = 0;
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
						Screen_stu_to_console(file);
						Sleep(100000);
						break;
					case 1:
						Change_pass(file);
						Sleep(100000);
						break;
					case 2:
						Menu_stu();
						break;
					case 3:
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

void Menu_stu() {
	SetColor(15, 0);
	wchar_t* file = Login();
	Sub_menu_stu(file);
	delete[] file;
}

