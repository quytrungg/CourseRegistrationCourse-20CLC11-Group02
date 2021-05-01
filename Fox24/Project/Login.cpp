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

wchar_t* Login_stu() {
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

void Change_pass_stu(wchar_t* file) {
	system("cls");
	SetColor(15, 0);

	// Information student
	Node_stu* pHead_stu = new Node_stu;
	std::wstring str;
	std::wifstream fin(file);
	fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
	std::getline(fin, str);
	std::getline(fin, str);
	Read_file_stu(str, pHead_stu);
	std::getline(fin, str);
	Read_course_1(str, pHead_stu);
	std::getline(fin, str);
	Read_course_2(str, pHead_stu);
	std::getline(fin, str);
	Read_course_3(str, pHead_stu);
	std::getline(fin, str);
	Read_course_4(str, pHead_stu);
	std::getline(fin, str);
	Read_course_5(str, pHead_stu);
	std::getline(fin, str);
	int count = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			pHead_stu->stu.Schedule[i][j] = str[count] - int('0');
			count++;
		}
	}
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
	fout << pHead_stu->stu.course_1.ID << L"," << pHead_stu->stu.course_1.TotalMark << L"," << pHead_stu->stu.course_1.FinalMark << L"," << pHead_stu->stu.course_1.MidtermMark << L"," << pHead_stu->stu.course_1.OtherMark << std::endl;
	fout << pHead_stu->stu.course_2.ID << L"," << pHead_stu->stu.course_2.TotalMark << L"," << pHead_stu->stu.course_2.FinalMark << L"," << pHead_stu->stu.course_2.MidtermMark << L"," << pHead_stu->stu.course_2.OtherMark << std::endl;
	fout << pHead_stu->stu.course_3.ID << L"," << pHead_stu->stu.course_3.TotalMark << L"," << pHead_stu->stu.course_3.FinalMark << L"," << pHead_stu->stu.course_3.MidtermMark << L"," << pHead_stu->stu.course_3.OtherMark << std::endl;
	fout << pHead_stu->stu.course_4.ID << L"," << pHead_stu->stu.course_4.TotalMark << L"," << pHead_stu->stu.course_4.FinalMark << L"," << pHead_stu->stu.course_4.MidtermMark << L"," << pHead_stu->stu.course_4.OtherMark << std::endl;
	fout << pHead_stu->stu.course_5.ID << L"," << pHead_stu->stu.course_5.TotalMark << L"," << pHead_stu->stu.course_5.FinalMark << L"," << pHead_stu->stu.course_5.MidtermMark << L"," << pHead_stu->stu.course_5.OtherMark << std::endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			fout << pHead_stu->stu.Schedule[i][j];
		}
	}
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

void Screen_stu_to_console_stu(wchar_t* file) {
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
	int Max_List_Menu = 6;
	int flag = 0;
	SetColor(15, 0);
	std::wstring menu[] = { L"Information",L"Change pass",L"Register course",L"View course",L"Log out", L"Exit"};
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
						Screen_stu_to_console_stu(file);
						Sleep(100000);
						break;
					case 1:
						Change_pass_stu(file);
						Sleep(100000);
						break;
					case 2:
						Register_course(pHead_cou, file);
						Sleep(100000);
						break;
					case 3:
						View_course_stu(pHead_cou, file);
						Sleep(100000);
						break;
					case 4:
						Menu_stu();
						break;
					case 5:
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
	wchar_t* file = Login_stu();
	Sub_menu_stu(file);
	delete[] file;
}

void Cout_day_of_week(int n) {
	switch (n) {
	case 0: 
	{
		std::wcout << L"MON";
		break;
	}
	case 1: 
	{
		std::wcout << L"TUE";
		break;
	}
	case 2: 
	{
		std::wcout << L"WED";
		break;
	}
	case 3: 
	{
		std::wcout << L"THU";
		break;
	}
	case 4: 
	{
		std::wcout << L"FRI";
		break;
	}
	case 5:
	{
		std::wcout << L"SAT";
		break;
	}
	case 6: 
	{
		std::wcout << L"SUN";
		break;
	}
	}
}

void Register_course(Node_cou*& pHead_cou_1, wchar_t* file) {
	Time current_time;
	Get_current_time_to_int(current_time);
	char* current_year = Convert_int_to_char(current_time.date.Year);
	Node_cou* pCur_cou_1;
	std::wstring str;
	system("cls");
	SetColor(15, 0);

	// Information student
	Node_stu* pHead_stu_1 = new Node_stu;
	std::wifstream fin(file);
	fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
	std::getline(fin, str);
	int begin = str.find(',', 0) + 1;
	int end = str.length();
	pHead_stu_1->stu.account.Pass = new wchar_t[end - begin + 1];
	str.copy(pHead_stu_1->stu.account.Pass, end - begin, begin);
	pHead_stu_1->stu.account.Pass[end - begin] = L'\0';
	std::getline(fin, str);
	Read_file_stu(str, pHead_stu_1);
	std::getline(fin, str);
	Read_course_1(str, pHead_stu_1);
	std::getline(fin, str);
	Read_course_2(str, pHead_stu_1);
	std::getline(fin, str);
	Read_course_3(str, pHead_stu_1);
	std::getline(fin, str);
	Read_course_4(str, pHead_stu_1);
	std::getline(fin, str);
	Read_course_5(str, pHead_stu_1);
	std::getline(fin, str);
	int count = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			pHead_stu_1->stu.Schedule[i][j] = str[count] - int('0');
			count++;
		}
	}
	fin.close();


	// Course
	if (checkFileWithFstream(L"Course.txt")) {
		pHead_cou_1 = new Node_cou;
		pCur_cou_1 = pHead_cou_1;
		std::wifstream fin("Course.txt");
		if (!fin) {

		}
		else {
			fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
			while (!fin.eof()) {
				pCur_cou_1->pNext = new Node_cou;
				pCur_cou_1->pNext->pPre = pCur_cou_1;
				std::getline(fin, str);
				pCur_cou_1->pNext->cou.ID = new wchar_t[str.length() + 1];
				str.copy(pCur_cou_1->pNext->cou.ID, str.length(), 0);
				pCur_cou_1->pNext->cou.ID[str.length()] = L'\0';
				pCur_cou_1 = pCur_cou_1->pNext;
				pCur_cou_1->pNext = nullptr;
			}
			if (pHead_cou_1->pNext == nullptr) {
				delete pHead_cou_1;
				pHead_cou_1 = nullptr;
			}
			else {
				Node_cou* pTemp = pHead_cou_1;
				pHead_cou_1 = pHead_cou_1->pNext;
				delete pTemp;
			}
		}
		fin.close();
		wchar_t* file_1;
		pCur_cou_1 = pHead_cou_1;
		while (pCur_cou_1 != nullptr) {
			file_1 = Create_file_1(pCur_cou_1->cou.ID, Create_third_folder("1", Create_second_folder("Semester", current_year)), ".txt");
			std::wifstream fin(file_1);
			fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
			std::getline(fin, str);
			Read_file_cou(str, pCur_cou_1);
			pCur_cou_1 = pCur_cou_1->pNext;
			fin.close();
		}
		int count = 1;
		pCur_cou_1 = pHead_cou_1;
		while (pCur_cou_1->pNext != nullptr) {
			std::wcout << count << L',' << pCur_cou_1->cou.ID << L',' << pCur_cou_1->cou.Name << L',' << pCur_cou_1->cou.Teacher_Name << L',' << pCur_cou_1->cou.Credit << L',' << pCur_cou_1->cou.count << L'//' << pCur_cou_1->cou.max_stu << L',';
			Cout_day_of_week(pCur_cou_1->cou.ses_1.day_of_week);
			std::wcout << L" S" << pCur_cou_1->cou.ses_1.session + 1 << L',';
			Cout_day_of_week(pCur_cou_1->cou.ses_2.day_of_week);
			std::wcout << L" S" << pCur_cou_1->cou.ses_2.session + 1 << std::endl;
			pCur_cou_1 = pCur_cou_1->pNext;
			count++;
		}

		// Register course
		int check = 0;
		wchar_t* a = new wchar_t[2];
		a[0] = L'0';
		a[1] = L'\0';
		if (wcscmp(a, pHead_stu_1->stu.course_1.ID) == 0) {
			check = 1;
		}
		else if (wcscmp(a, pHead_stu_1->stu.course_2.ID) == 0) {
			check = 2;
		}
		else if (wcscmp(a, pHead_stu_1->stu.course_3.ID) == 0) {
			check = 3;
		}
		else if (wcscmp(a, pHead_stu_1->stu.course_4.ID) == 0) {
			check = 4;
		}
		else if (wcscmp(a, pHead_stu_1->stu.course_5.ID) == 0) {
			check = 5;
		}
		delete[] a;

		if (check == 0) {
			std::wcout << "Full course" << std::endl;
		}
		else {
			int x;
			std::wcout << "Input the number to choose course: ";
			std::wcin >> x;
			pCur_cou_1 = pHead_cou_1;
			if (x == 1) {

			}
			else {
				for (int i = 0; i < x - 1; i++) {
					pCur_cou_1 = pCur_cou_1->pNext;
				}
			}
			if (pCur_cou_1->cou.count < 50) {
				if (pHead_stu_1->stu.Schedule[pCur_cou_1->cou.ses_1.session][pCur_cou_1->cou.ses_1.day_of_week] == 0 && pHead_stu_1->stu.Schedule[pCur_cou_1->cou.ses_2.session][pCur_cou_1->cou.ses_2.day_of_week] == 0) {
					if (check == 1) {
						pHead_stu_1->stu.course_1.ID = pCur_cou_1->cou.ID;
						pHead_stu_1->stu.Schedule[pCur_cou_1->cou.ses_1.session][pCur_cou_1->cou.ses_1.day_of_week] = 1;
						pHead_stu_1->stu.Schedule[pCur_cou_1->cou.ses_2.session][pCur_cou_1->cou.ses_2.day_of_week] = 1;
					}
					else if (check == 2) {
						pHead_stu_1->stu.course_2.ID = pCur_cou_1->cou.ID;
						pHead_stu_1->stu.Schedule[pCur_cou_1->cou.ses_1.session][pCur_cou_1->cou.ses_1.day_of_week] = 2;
						pHead_stu_1->stu.Schedule[pCur_cou_1->cou.ses_2.session][pCur_cou_1->cou.ses_2.day_of_week] = 2;
					}
					else if (check == 3) {
						pHead_stu_1->stu.course_3.ID = pCur_cou_1->cou.ID;
						pHead_stu_1->stu.Schedule[pCur_cou_1->cou.ses_1.session][pCur_cou_1->cou.ses_1.day_of_week] = 3;
						pHead_stu_1->stu.Schedule[pCur_cou_1->cou.ses_2.session][pCur_cou_1->cou.ses_2.day_of_week] = 3;
					}
					else if (check == 4) {
						pHead_stu_1->stu.course_4.ID = pCur_cou_1->cou.ID;
						pHead_stu_1->stu.Schedule[pCur_cou_1->cou.ses_1.session][pCur_cou_1->cou.ses_1.day_of_week] = 4;
						pHead_stu_1->stu.Schedule[pCur_cou_1->cou.ses_2.session][pCur_cou_1->cou.ses_2.day_of_week] = 4;
					}
					else if (check == 5) {
						pHead_stu_1->stu.course_5.ID = pCur_cou_1->cou.ID;
						pHead_stu_1->stu.Schedule[pCur_cou_1->cou.ses_1.session][pCur_cou_1->cou.ses_1.day_of_week] = 5;
						pHead_stu_1->stu.Schedule[pCur_cou_1->cou.ses_2.session][pCur_cou_1->cou.ses_2.day_of_week] = 5;
					}
					wchar_t* file_2;
					file_2 = Create_file_1(pCur_cou_1->cou.ID, Create_third_folder("1", Create_second_folder("Semester", current_year)), ".txt");
					std::wifstream fin(file_2);
					fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
					std::getline(fin, str);
					pCur_cou_1->cou.count++;
					std::getline(fin, str);
					fin.close();
					if (str == L"0") {
						pCur_cou_1->cou.StudentID = new wchar_t[10];
						int r;
						int n = pHead_stu_1->stu.ID;
						count = 0;
						for (int i = n; i > 0; i = i / 10) {
							count++;
						}
						for (int i = 0; i < count; i++) {
							r = n % 10;
							n = n / 10;
							pCur_cou_1->cou.StudentID[count - 1 - i] = r + '0';
						}
						pCur_cou_1->cou.StudentID[8] = L',';
						pCur_cou_1->cou.StudentID[9] = L'\0';
					}
					else {
						count = 0;
						Node_stu* pHead_stu_2 = new Node_stu;
						Node_stu* pCur_stu_2 = pHead_stu_2;
						for (int i = 0; i < str.length(); i++) {
							if (str[i] == L',') {
								count++;
							}
						}
						begin = 0;
						end = -1;
						for (int i = 0; i < count; i++) {
							begin = end + 1;
							end = str.find(',', begin + 1);
							a = new wchar_t[end - begin + 1];
							str.copy(a, end - begin, begin);
							a[end - begin] = L'/0';
							pCur_stu_2->pNext = new Node_stu;
							pCur_stu_2->pNext->stu.ID = Convert_wchart_to_int(a, end - begin);
							pCur_stu_2 = pCur_stu_2->pNext;
							pCur_stu_2->pNext = nullptr;
						}
						if (pHead_stu_2->pNext == nullptr) {
							delete pHead_stu_2;
							pHead_stu_2 = nullptr;
						}
						else {
							Node_stu* pTemp = pHead_stu_2;
							pHead_stu_2 = pHead_stu_2->pNext;
							delete pTemp;
						}
						pCur_stu_2->pNext = new Node_stu;
						pCur_stu_2->pNext->stu.ID = pHead_stu_1->stu.ID;
						pCur_stu_2 = pCur_stu_2->pNext;
						pCur_stu_2->pNext = nullptr;
						pCur_stu_2 = pHead_stu_2;
						pCur_cou_1->cou.StudentID = new wchar_t[9 * count + 1];
						int k = 0;
						count++;
						for (int i = 0; i < count; i++) {
							int n = pCur_stu_2->stu.ID;
							int m = 10000000;
							for (int i = 0; i < 8; i++) {
								int r = n / m;
								n = n - r * m;
								m = m / 10;
								pCur_cou_1->cou.StudentID[k] = wchar_t(r + '0');
								k++;
							}
							pCur_cou_1->cou.StudentID[k] = L',';
							k++;
							pCur_stu_2 = pCur_stu_2->pNext;
						}
						pCur_cou_1->cou.StudentID[count * 9] = L'\0';
						Delete_Node_stu(pHead_stu_2);
					}
					_wremove(file_2);
					std::wofstream fout_1(file_2);
					fout_1.imbue(std::locale(fout_1.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
					fout_1 << pCur_cou_1->cou.ID << L',' << pCur_cou_1->cou.Name << L',' << pCur_cou_1->cou.Teacher_Name << L',' << pCur_cou_1->cou.Credit << L',' << pCur_cou_1->cou.max_stu << L',' << pCur_cou_1->cou.count << L',';
					fout_1 << pCur_cou_1->cou.ses_1.day_of_week << L',' << pCur_cou_1->cou.ses_1.session << L',' << pCur_cou_1->cou.ses_2.day_of_week << L',' << pCur_cou_1->cou.ses_2.session << std::endl;
					fout_1 << pCur_cou_1->cou.StudentID << std::endl;
					fout_1.close();

					_wremove(file);
					std::wofstream fout(file);
					fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
					fout << pHead_stu_1->stu.account.ID << L"," << pHead_stu_1->stu.account.Pass << std::endl;
					fout << pHead_stu_1->stu.ID << L"," << pHead_stu_1->stu.FirstName << L"," << pHead_stu_1->stu.LastName << L"," << pHead_stu_1->stu.Gender << L"," << pHead_stu_1->stu.Birthday.Day << L"/" << pHead_stu_1->stu.Birthday.Month << L"/" << pHead_stu_1->stu.Birthday.Year << L"," << pHead_stu_1->stu.SocialID << std::endl;
					fout << pHead_stu_1->stu.course_1.ID << L"," << pHead_stu_1->stu.course_1.TotalMark << L"," << pHead_stu_1->stu.course_1.FinalMark << L"," << pHead_stu_1->stu.course_1.MidtermMark << L"," << pHead_stu_1->stu.course_1.OtherMark << std::endl;
					fout << pHead_stu_1->stu.course_2.ID << L"," << pHead_stu_1->stu.course_2.TotalMark << L"," << pHead_stu_1->stu.course_2.FinalMark << L"," << pHead_stu_1->stu.course_2.MidtermMark << L"," << pHead_stu_1->stu.course_2.OtherMark << std::endl;
					fout << pHead_stu_1->stu.course_3.ID << L"," << pHead_stu_1->stu.course_3.TotalMark << L"," << pHead_stu_1->stu.course_3.FinalMark << L"," << pHead_stu_1->stu.course_3.MidtermMark << L"," << pHead_stu_1->stu.course_3.OtherMark << std::endl;
					fout << pHead_stu_1->stu.course_4.ID << L"," << pHead_stu_1->stu.course_4.TotalMark << L"," << pHead_stu_1->stu.course_4.FinalMark << L"," << pHead_stu_1->stu.course_4.MidtermMark << L"," << pHead_stu_1->stu.course_4.OtherMark << std::endl;
					fout << pHead_stu_1->stu.course_5.ID << L"," << pHead_stu_1->stu.course_5.TotalMark << L"," << pHead_stu_1->stu.course_5.FinalMark << L"," << pHead_stu_1->stu.course_5.MidtermMark << L"," << pHead_stu_1->stu.course_5.OtherMark << std::endl;
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 7; j++) {
							fout << pHead_stu_1->stu.Schedule[i][j];
						}
					}
					fout.close();
					std::wcout << "Register successful" << std::endl;
				}
				else {
					std::wcout << "Can not register" << std::endl;
				}
			}
			else {
				std::wcout << "Can not register" << std::endl;
			}
		}
	}
	else {
		std::wcout << "No courses have been created yet" << std::endl;
	}
	pHead_stu_1->pNext = nullptr;
	Delete_Node_stu(pHead_stu_1);
	Delete_Node_cou(pHead_cou_1);
	char key = toupper(_getch());
	if (key == 27)
	{
		Sub_menu_stu(file);
	}
}

void cout_name_course(Node_cou* pHead_cou, int n) {
	Node_cou* pCur = pHead_cou;
	for (int i = 0; i < n - 1; i++) {
		pCur = pCur->pNext;
	}
	std::wcout << pCur->cou.Name << " ";
}

void View_course_stu(Node_cou*& pHead_cou, wchar_t* file) {
	Time current_time;
	Get_current_time_to_int(current_time);
	char* current_year = Convert_int_to_char(current_time.date.Year);
	system("cls");
	SetColor(15, 0);
	ShowCur(0);

	std::wstring str;
	Node_stu* pHead_stu_1 = new Node_stu;
	std::wifstream fin(file);
	fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
	std::getline(fin, str);
	int begin = str.find(',', 0) + 1;
	int end = str.length();
	pHead_stu_1->stu.account.Pass = new wchar_t[end - begin + 1];
	str.copy(pHead_stu_1->stu.account.Pass, end - begin, begin);
	pHead_stu_1->stu.account.Pass[end - begin] = L'\0';
	std::getline(fin, str);
	Read_file_stu(str, pHead_stu_1);
	std::getline(fin, str);
	Read_course_1(str, pHead_stu_1);
	std::getline(fin, str);
	Read_course_2(str, pHead_stu_1);
	std::getline(fin, str);
	Read_course_3(str, pHead_stu_1);
	std::getline(fin, str);
	Read_course_4(str, pHead_stu_1);
	std::getline(fin, str);
	Read_course_5(str, pHead_stu_1);
	std::getline(fin, str);
	int count = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			pHead_stu_1->stu.Schedule[i][j] = str[count] - int('0');
			count++;
		}
	}
	fin.close();

	pHead_cou = new Node_cou;
	Node_cou* pCur_cou = pHead_cou;
	wchar_t* a = new wchar_t[2];
	a[0] = L'0';
	a[1] = L'\0';
	wchar_t* file_1;
	int k = 0;
	if (wcscmp(a, pHead_stu_1->stu.course_1.ID) != 0) {
		file_1 = Create_file_1(pHead_stu_1->stu.course_1.ID, Create_third_folder("1", Create_second_folder("Semester", current_year)), ".txt");
		std::wifstream fin_1(file_1);
		fin_1.imbue(std::locale(fin_1.getloc(), new std::codecvt_utf8<wchar_t>));
		std::getline(fin_1, str);
		pCur_cou->pNext = new Node_cou;
		Read_file_cou(str, pCur_cou->pNext);
		pCur_cou = pCur_cou->pNext;
		pCur_cou->pNext = nullptr;
		fin_1.close();
		k++;
	}
	if (wcscmp(a, pHead_stu_1->stu.course_2.ID) != 0) {
		file_1 = Create_file_1(pHead_stu_1->stu.course_2.ID, Create_third_folder("1", Create_second_folder("Semester", current_year)), ".txt");
		std::wifstream fin_1(file_1);
		fin_1.imbue(std::locale(fin_1.getloc(), new std::codecvt_utf8<wchar_t>));
		std::getline(fin_1, str);
		pCur_cou->pNext = new Node_cou;
		Read_file_cou(str, pCur_cou->pNext);
		pCur_cou = pCur_cou->pNext;
		pCur_cou->pNext = nullptr;
		fin_1.close();
		k++;
	}
	if (wcscmp(a, pHead_stu_1->stu.course_3.ID) != 0) {
		file_1 = Create_file_1(pHead_stu_1->stu.course_3.ID, Create_third_folder("1", Create_second_folder("Semester", current_year)), ".txt");
		std::wifstream fin_1(file_1);
		fin_1.imbue(std::locale(fin_1.getloc(), new std::codecvt_utf8<wchar_t>));
		std::getline(fin_1, str);
		pCur_cou->pNext = new Node_cou;
		Read_file_cou(str, pCur_cou->pNext);
		pCur_cou = pCur_cou->pNext;
		pCur_cou->pNext = nullptr;
		fin_1.close();
		k++;
	}
	if (wcscmp(a, pHead_stu_1->stu.course_4.ID) != 0) {
		file_1 = Create_file_1(pHead_stu_1->stu.course_4.ID, Create_third_folder("1", Create_second_folder("Semester", current_year)), ".txt");
		std::wifstream fin_1(file_1);
		fin_1.imbue(std::locale(fin_1.getloc(), new std::codecvt_utf8<wchar_t>));
		std::getline(fin_1, str);
		pCur_cou->pNext = new Node_cou;
		Read_file_cou(str, pCur_cou->pNext);
		pCur_cou = pCur_cou->pNext;
		pCur_cou->pNext = nullptr;
		fin_1.close();
		k++;
	}
	if (wcscmp(a, pHead_stu_1->stu.course_5.ID) != 0) {
		file_1 = Create_file_1(pHead_stu_1->stu.course_5.ID, Create_third_folder("1", Create_second_folder("Semester", current_year)), ".txt");
		std::wifstream fin_1(file_1);
		fin_1.imbue(std::locale(fin_1.getloc(), new std::codecvt_utf8<wchar_t>));
		std::getline(fin_1, str);
		pCur_cou->pNext = new Node_cou;
		Read_file_cou(str, pCur_cou->pNext);
		pCur_cou = pCur_cou->pNext;
		pCur_cou->pNext = nullptr;
		fin_1.close();
		k++;
	}
	if (k == 0) {
		std::wcout << "No register course" << std::endl;
		Sleep(1000000);
		char key = toupper(_getch());
		if (key == 27)
		{
			Sub_menu_stu(file);
		}
	}
	if (pHead_cou->pNext == nullptr) {
		delete pHead_cou;
		pHead_cou = nullptr;
	}
	else {
		Node_cou* pTemp = pHead_cou;
		pHead_cou = pHead_cou->pNext;
		delete pTemp;
	}
	pCur_cou = pHead_cou;
	count = 1;
	while (pCur_cou != nullptr) {
		std::wcout << count << L',' << pCur_cou->cou.ID << L',' << pCur_cou->cou.Name << L',' << pCur_cou->cou.Teacher_Name << L',' << pCur_cou->cou.Credit << L',' << pCur_cou->cou.count << L'//' << pCur_cou->cou.max_stu << L',';
		Cout_day_of_week(pCur_cou->cou.ses_1.day_of_week);
		std::wcout << L" S" << pCur_cou->cou.ses_1.session + 1 << L',';
		Cout_day_of_week(pCur_cou->cou.ses_2.day_of_week);
		std::wcout << L" S" << pCur_cou->cou.ses_2.session + 1 << std::endl;
		pCur_cou = pCur_cou->pNext;
		count++;
	}
	std::wcout << L"Schedule" << std::endl;
	for (int i = 0; i < 7; i++) {
		Cout_day_of_week(i);
		std::wcout << "                 ";
	}
	std::wcout << std::endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			if (pHead_stu_1->stu.Schedule[i][j] != 0) {
				cout_name_course(pHead_cou, pHead_stu_1->stu.Schedule[i][j]);
				std::wcout << L"  ";
			}
			else {
				std::wcout << L"-----------------  ";
			}
		}
		std::wcout << std::endl;
	}

	pHead_stu_1->pNext = nullptr;
	Delete_Node_cou(pHead_cou);
	Delete_Node_stu(pHead_stu_1);
	char key = toupper(_getch());
	if (key == 27)
	{
		Sub_menu_stu(file);
	}
}

void main() {
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	/*Node_stu* pHead_stu;
	Node_cla* pHead_cla;
	Input_student_data(pHead_stu, pHead_cla);
	Delete_Node_cla(pHead_cla);
	Delete_Node_stu(pHead_stu);*/
	Menu_stu();
}