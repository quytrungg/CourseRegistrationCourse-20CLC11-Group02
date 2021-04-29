#include "Struct.h"
#include "Time.h"
#include "Help.h"
#include "Save.h"
#include "Delete.h"

void Input_one_student_by_file(std::wstring str, Node_stu* pCur) {
	// ID
	int begin = str.find(',', 0) + 1;
	int end = str.find(',', begin + 1);
	wchar_t* a = new wchar_t[end - begin + 1];
	str.copy(a, end - begin, begin);
	a[end - begin] = L'\0';
	pCur->stu.ID = Convert_wchart_to_int(a, end - begin);
	delete[] a;

	// Account name
	pCur->stu.account.ID = new wchar_t[end - begin + 1];
	str.copy(pCur->stu.account.ID, end - begin, begin);
	pCur->stu.account.ID[end - begin] = L'\0';

	// First Name
	begin = end + 1;
	end = str.find(',', begin + 1);
	pCur->stu.FirstName = new wchar_t[end - begin + 1];
	str.copy(pCur->stu.FirstName, end - begin, begin);
	pCur->stu.FirstName[end - begin] = L'\0';

	// Last Name
	begin = end + 1;
	end = str.find(',', begin + 1);
	pCur->stu.LastName = new wchar_t[end - begin + 1];
	str.copy(pCur->stu.LastName, end - begin, begin);
	pCur->stu.LastName[end - begin] = L'\0';

	// Gender
	begin = end + 1;
	end = str.find(',', begin + 1);
	pCur->stu.Gender = new wchar_t[end - begin + 1];
	str.copy(pCur->stu.Gender, end - begin, begin);
	pCur->stu.Gender[end - begin] = L'\0';

	// Account password
	pCur->stu.account.Pass = new wchar_t[9];
	int count = 0;

	// Birthday day
	begin = end + 1;
	end = str.find('/', begin + 1);
	a = new wchar_t[end - begin + 1];
	str.copy(a, end - begin, begin);
	a[end - begin] = L'\0';
	for (int i = 0; i < end - begin; i++) {
		pCur->stu.account.Pass[count] = a[i];
		count++;
	}
	if (count == 1) {
		pCur->stu.account.Pass[count] = pCur->stu.account.Pass[count - 1];
		pCur->stu.account.Pass[0] = L'0';
		count++;
	}
	pCur->stu.Birthday.Day = Convert_wchart_to_int(a, end - begin);
	delete[] a;

	// Birthday month
	begin = end + 1;
	end = str.find('/', begin + 1);
	a = new wchar_t[end - begin + 1];
	str.copy(a, end - begin, begin);
	a[end - begin] = L'\0';
	for (int i = 0; i < end - begin; i++) {
		pCur->stu.account.Pass[count] = a[i];
		count++;
	}
	if (count == 3) {
		pCur->stu.account.Pass[count] = pCur->stu.account.Pass[count - 1];
		pCur->stu.account.Pass[count - 1] = L'0';
		count++;
	}
	pCur->stu.Birthday.Month = Convert_wchart_to_int(a, end - begin);
	delete[] a;

	// Birthday year
	begin = end + 1;
	end = str.find(',', begin + 1);
	a = new wchar_t[end - begin + 1];
	str.copy(a, end - begin, begin);
	a[end - begin] = L'\0';
	for (int i = 0; i < end - begin; i++) {
		pCur->stu.account.Pass[count] = a[i];
		count++;
	}
	pCur->stu.account.Pass[count] = L'\0';
	pCur->stu.Birthday.Year = Convert_wchart_to_int(a, end - begin);
	delete[] a;

	// Social ID
	begin = end + 1;
	end = str.length();
	a = new wchar_t[end - begin + 1];
	str.copy(a, end - begin, begin);
	a[end - begin] = L'\0';
	pCur->stu.SocialID = Convert_wchart_to_int(a, end - begin);
	delete[] a;

	// Course 1
	pCur->stu.course_1.ID = new wchar_t[2];
	pCur->stu.course_1.ID[0] = L'0';
	pCur->stu.course_1.ID[1] = L'\0';
	pCur->stu.course_1.FinalMark = 0;
	pCur->stu.course_1.MidtermMark = 0;
	pCur->stu.course_1.OtherMark = 0;
	pCur->stu.course_1.TotalMark = 0;

	// Course 2
	pCur->stu.course_2.ID = new wchar_t[2];
	pCur->stu.course_2.ID[0] = L'0';
	pCur->stu.course_2.ID[1] = L'\0';
	pCur->stu.course_2.FinalMark = 0;
	pCur->stu.course_2.MidtermMark = 0;
	pCur->stu.course_2.OtherMark = 0;
	pCur->stu.course_2.TotalMark = 0;

	// Course 3
	pCur->stu.course_3.ID = new wchar_t[2];
	pCur->stu.course_3.ID[0] = L'0';
	pCur->stu.course_3.ID[1] = L'\0';
	pCur->stu.course_3.FinalMark = 0;
	pCur->stu.course_3.MidtermMark = 0;
	pCur->stu.course_3.OtherMark = 0;
	pCur->stu.course_3.TotalMark = 0;

	// Course 4
	pCur->stu.course_4.ID = new wchar_t[2];
	pCur->stu.course_4.ID[0] = L'0';
	pCur->stu.course_4.ID[1] = L'\0';
	pCur->stu.course_4.FinalMark = 0;
	pCur->stu.course_4.MidtermMark = 0;
	pCur->stu.course_4.OtherMark = 0;
	pCur->stu.course_4.TotalMark = 0;

	// Course 5
	pCur->stu.course_5.ID = new wchar_t[2];
	pCur->stu.course_5.ID[0] = L'0';
	pCur->stu.course_5.ID[1] = L'\0';
	pCur->stu.course_5.FinalMark = 0;
	pCur->stu.course_5.MidtermMark = 0;
	pCur->stu.course_5.OtherMark = 0;
	pCur->stu.course_5.TotalMark = 0;

	// Schedule
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			pCur->stu.Schedule[i][j] = 0;
		}
	}
}

void Input_student(std::wstring str, Node_stu*& pHead) {
	pHead = new Node_stu;
	Node_stu* pCur = pHead;
	std::wifstream fin(str);
	std::wstring a;
	if (!fin) {
		std::wcout << L"Không thể đọc file \n";
	}
	else {
		fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
		while (!fin.eof()) {
			std::getline(fin, a);
			pCur->pNext = new Node_stu;
			pCur->pNext->pPre = pCur;
			fin.ignore();
			Input_one_student_by_file(a, pCur->pNext);
			pCur = pCur->pNext;
			pCur->pNext = nullptr;
		}
		if (pHead->pNext == nullptr) {
			delete pHead;
			pHead = nullptr;
		}
		else {
			Node_stu* pTemp = pHead;
			pHead = pHead->pNext;
			delete pTemp;
			pHead->pPre = nullptr;
		}
	}
	fin.close();
}

void Input_one_class(std::wstring str, Node_cla* pCur_cla, Node_stu* pHead_stu) {
	// Class name
	int  k = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == L'\\')	k++;
	}
	int begin = 0;
	int end = -1;
	for (int i = 0; i < k; i++) {
		begin = end + 1;
		end = str.find('\\', begin + 1);
	}
	begin = end + 1;
	end = str.find('.', begin + 1);
	pCur_cla->cla.Name = new wchar_t[end - begin + 1];
	str.copy(pCur_cla->cla.Name, end - begin, begin);
	pCur_cla->cla.Name[end - begin] = L'\0';

	// Student ID
	Node_stu* pCur_stu = pHead_stu;
	int count = 0;
	while (pCur_stu != nullptr) {
		count++;
		pCur_stu = pCur_stu->pNext;
	}
	pCur_cla->cla.StudentID = new wchar_t[count * 9];
	pCur_stu = pHead_stu;
	k = 0;
	for (int i = 0; i < count; i++) {
		int n = pCur_stu->stu.ID;
		int m = 10000000;
		for (int i = 0; i < 8; i++) {
			int r = n / m;
			n = n - r * m;
			m = m / 10;
			pCur_cla->cla.StudentID[k] = wchar_t(r + '0');
			k++;
		}
		pCur_cla->cla.StudentID[k] = L',';
		k++;
		pCur_stu = pCur_stu->pNext;
	}
	pCur_cla->cla.StudentID[count * 9 - 1] = L'\0';
}

void Input_student_data(Node_stu*& pHead_stu, Node_cla*& pHead_cla) {
	Time current_time;
	Get_current_time_to_int(current_time);
	char* current_year = Convert_int_to_char(current_time.date.Year);
	Create_main_folder(current_year);
	int x;
	pHead_cla = new Node_cla;
	Node_cla* pCur_cla = pHead_cla;
	std::wstring str;
	std::wcout << "Please input the total number of classes in the school year: ";
	std::wcin >> x;
	std::wcin.ignore();
	for (int i = 0; i < x; i++) {
		pCur_cla->pNext = new Node_cla;
		std::wcout << "Please input the link: ";
		std::getline(std::wcin, str);
		Input_student(str, pHead_stu);
		Input_one_class(str, pCur_cla->pNext, pHead_stu);
		Save_stu_to_test(pHead_stu, Create_second_folder("Student", current_year));
		Delete_Node_stu(pHead_stu);
		pCur_cla = pCur_cla->pNext;
		pCur_cla->pNext = nullptr;
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
	Save_name_class(pHead_cla);
	Save_cla_to_test(pHead_cla, Create_second_folder("Class", current_year));
	Delete_Node_cla(pHead_cla);
}

void Input_one_course_direct(Node_cou* pCur) {
	system("cls");
	// ID
	std::wstring str;
	std::wcin.ignore();
	std::wcout << "Please input the course id: ";
	std::getline(std::wcin, str);
	pCur->cou.ID = new wchar_t[str.length() + 1];
	str.copy(pCur->cou.ID, str.length(), 0);
	pCur->cou.ID[str.length()] = L'\0';

	// Course Name
	std::wcout << "Please input the course name: ";
	std::getline(std::wcin, str);
	pCur->cou.Name = new wchar_t[str.length() + 1];
	str.copy(pCur->cou.Name, str.length(), 0);
	pCur->cou.Name[str.length()] = L'\0';

	// Teacher Name
	std::wcout << "Please input the teacher name: ";
	std::getline(std::wcin, str);
	pCur->cou.Teacher_Name = new wchar_t[str.length() + 1];
	str.copy(pCur->cou.Teacher_Name, str.length(), 0);
	pCur->cou.Teacher_Name[str.length()] = L'\0';

	// Credit
	std::wcout << "Please input how many credits in this course: ";
	std::wcin >> pCur->cou.Credit;

	// Timetable
	std::wcout << "Please input the timetable: " << std::endl;
	std::wcout << "Session 1:";

	ShowCur(0);
	std::wstring menu_1[] = { L"MON",L"TUE",L"WED",L"THU",L"FRI", L"SAT", L"SUN"};
	int pointer = 0;
	int color = 0;
	int Max_List_Menu = 7;
	while (1) {
		//in menu ra man hinh
		GotoXY(11, 5);
		std::wcout << menu_1[pointer] << std::endl;
		char key;
		while (1) {
			if (_kbhit()) {
				key = _getch();
				if (key == 72 || key == 'w' || key == 'W') {
					//PlaySound(TEXT("dichuyen.wav"), NULL, SND_FILENAME | SND_ASYNC);
					if (pointer > 0) {
						pointer--;
					}
					else {
						pointer = Max_List_Menu - 1;
					}
					break;
				}
				if (key == 80 || key == 's' || key == 'S') {
					//PlaySound(TEXT("dichuyen.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
						pCur->cou.ses_1.day_of_week = 0;
						break;
					case 1:
						pCur->cou.ses_1.day_of_week = 1;
						break;
					case 2:
						pCur->cou.ses_1.day_of_week = 2;
						break;
					case 3:
						pCur->cou.ses_1.day_of_week = 3;
						break;
					case 4:
						pCur->cou.ses_1.day_of_week = 4;
						break;
					case 5:
						pCur->cou.ses_1.day_of_week = 5;
						break;
					case 6:
						pCur->cou.ses_1.day_of_week = 6;
						break;
					default:
						std::wcout << "Erorr" << std::endl;
					}
					break;
				}
			}
		}
		if (key == 13) {
			break;
		}
	}
	GotoXY(17, 5);
	std::wcout << "Time:";
	std::wstring menu_2[] = { L"S1 (07:30)",L"S2 (09:30)",L"S3 (13:30)",L"S4 (15:30)"};
	pointer = 0;
	Max_List_Menu = 4;
	while (1) {
		//in menu ra man hinh
		GotoXY(23, 5);
		std::wcout << menu_2[pointer] << std::endl;
		char key;
		while (1) {
			if (_kbhit()) {
				key = _getch();
				if (key == 72 || key == 'w' || key == 'W') {
					//PlaySound(TEXT("dichuyen.wav"), NULL, SND_FILENAME | SND_ASYNC);
					if (pointer > 0) {
						pointer--;
					}
					else {
						pointer = Max_List_Menu - 1;
					}
					break;
				}
				if (key == 80 || key == 's' || key == 'S') {
					//PlaySound(TEXT("dichuyen.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
						pCur->cou.ses_1.session = 0;
						break;
					case 1:
						pCur->cou.ses_1.session = 1;
						break;
					case 2:
						pCur->cou.ses_1.session = 2;
						break;
					case 3:
						pCur->cou.ses_1.session = 3;
						break;
					default:
						std::wcout << "Erorr" << std::endl;
					}
					break;
				}
			}
		}
		if (key == 13) {
			break;
		}
	}

	GotoXY(0, 6);
	std::wcout << "Session 1:";

	std::wstring menu_3[] = { L"MON",L"TUE",L"WED",L"THU",L"FRI", L"SAT", L"SUN" };
	pointer = 0;
	Max_List_Menu = 7;
	while (1) {
		//in menu ra man hinh
		GotoXY(11, 6);
		std::wcout << menu_3[pointer] << std::endl;
		char key;
		while (1) {
			if (_kbhit()) {
				key = _getch();
				if (key == 72 || key == 'w' || key == 'W') {
					//PlaySound(TEXT("dichuyen.wav"), NULL, SND_FILENAME | SND_ASYNC);
					if (pointer > 0) {
						pointer--;
					}
					else {
						pointer = Max_List_Menu - 1;
					}
					break;
				}
				if (key == 80 || key == 's' || key == 'S') {
					//PlaySound(TEXT("dichuyen.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
						pCur->cou.ses_2.day_of_week = 0;
						break;
					case 1:
						pCur->cou.ses_2.day_of_week = 1;
						break;
					case 2:
						pCur->cou.ses_2.day_of_week = 2;
						break;
					case 3:
						pCur->cou.ses_2.day_of_week = 3;
						break;
					case 4:
						pCur->cou.ses_2.day_of_week = 4;
						break;
					case 5:
						pCur->cou.ses_2.day_of_week = 5;
						break;
					case 6:
						pCur->cou.ses_2.day_of_week = 6;
						break;
					default:
						std::wcout << "Erorr" << std::endl;
					}
					break;
				}
			}
		}
		if (key == 13) {
			break;
		}
	}
	GotoXY(17, 6);
	std::wcout << "Time:";
	std::wstring menu_4[] = { L"S1 (07:30)",L"S2 (09:30)",L"S3 (13:30)",L"S4 (15:30)" };
	pointer = 0;
	Max_List_Menu = 4;
	while (1) {
		//in menu ra man hinh
		GotoXY(23, 6);
		std::wcout << menu_4[pointer] << std::endl;
		char key;
		while (1) {
			if (_kbhit()) {
				key = _getch();
				if (key == 72 || key == 'w' || key == 'W') {
					//PlaySound(TEXT("dichuyen.wav"), NULL, SND_FILENAME | SND_ASYNC);
					if (pointer > 0) {
						pointer--;
					}
					else {
						pointer = Max_List_Menu - 1;
					}
					break;
				}
				if (key == 80 || key == 's' || key == 'S') {
					//PlaySound(TEXT("dichuyen.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
						pCur->cou.ses_2.session = 0;
						break;
					case 1:
						pCur->cou.ses_2.session = 1;
						break;
					case 2:
						pCur->cou.ses_2.session = 2;
						break;
					case 3:
						pCur->cou.ses_2.session = 3;
						break;
					default:
						std::wcout << "Erorr" << std::endl;
					}
					break;
				}
			}
		}
		if (key == 13) {
			break;
		}
	}
	pCur->cou.StudentID = new wchar_t[2];
	pCur->cou.StudentID[0] = L'0';
	pCur->cou.StudentID[1] = L'\0';
}

void Input_one_course_by_file(std::wstring str, Node_cou* pCur) {
	wchar_t* a;

	int begin = 0;
	int end = str.find(',', begin + 1);
	pCur->cou.ID = new wchar_t[end - begin + 1];
	str.copy(pCur->cou.ID, end - begin, begin);
	pCur->cou.ID[end - begin] = L'\0';

	begin = end + 1;
	end = str.find(',', begin + 1);
	pCur->cou.Name = new wchar_t[end - begin + 1];
	str.copy(pCur->cou.Name, end - begin, begin);
	pCur->cou.Name[end - begin] = L'\0';

	begin = end + 1;
	end = str.find(',', begin + 1);
	pCur->cou.Teacher_Name = new wchar_t[end - begin + 1];
	str.copy(pCur->cou.Teacher_Name, end - begin, begin);
	pCur->cou.Teacher_Name[end - begin] = L'\0';

	begin = end + 1;
	end = str.find(',', begin + 1);
	a = new wchar_t[end - begin + 1];
	str.copy(a, end - begin, begin);
	a[end - begin] = L'\0';
	pCur->cou.Credit = Convert_wchart_to_int(a, end - begin);
	delete[] a;

	begin = end + 1;
	end = str.find(',', begin + 1);
	a = new wchar_t[end - begin + 1];
	str.copy(a, end - begin, begin);
	a[end - begin] = L'\0';
	pCur->cou.max_stu = Convert_wchart_to_int(a, end - begin);
	delete[] a;

	begin = end + 1;
	end = str.find(',', begin + 1);
	a = new wchar_t[end - begin + 1];
	str.copy(a, end - begin, begin);
	a[end - begin] = L'\0';
	pCur->cou.count = Convert_wchart_to_int(a, end - begin);
	delete[] a;

	begin = end + 1;
	end = str.find(',', begin + 1);
	a = new wchar_t[end - begin + 1];
	str.copy(a, end - begin, begin);
	a[end - begin] = L'\0';
	pCur->cou.ses_1.day_of_week = Convert_wchart_to_int(a, end - begin);
	delete[] a;

	begin = end + 1;
	end = str.find(',', begin + 1);
	a = new wchar_t[end - begin + 1];
	str.copy(a, end - begin, begin);
	a[end - begin] = L'\0';
	pCur->cou.ses_1.session = Convert_wchart_to_int(a, end - begin);
	delete[] a;

	begin = end + 1;
	end = str.find(',', begin + 1);
	a = new wchar_t[end - begin + 1];
	str.copy(a, end - begin, begin);
	a[end - begin] = L'\0';
	pCur->cou.ses_2.day_of_week = Convert_wchart_to_int(a, end - begin);
	delete[] a;

	begin = end + 1;
	end = str.length();
	a = new wchar_t[end - begin + 1];
	str.copy(a, end - begin, begin);
	a[end - begin] = L'\0';
	pCur->cou.ses_2.session = Convert_wchart_to_int(a, end - begin);
	delete[] a;

	pCur->cou.StudentID = new wchar_t[2];
	pCur->cou.StudentID[0] = L'0';
	pCur->cou.StudentID[1] = L'\0';
}

void Input_course_direct(Node_cou* &pHead_cou) {
	Time current_time;
	Get_current_time_to_int(current_time);
	char* current_year = Convert_int_to_char(current_time.date.Year);
	system("cls");
	int x;
	pHead_cou = new Node_cou;
	Node_cou* pCur_cou = pHead_cou;
	std::wcout << "Please input the total number of course do you want to input: ";
	std::wcin >> x;
	for (int i = 0; i < x; i++) {
		pCur_cou->pNext = new Node_cou;
		Input_one_course_direct(pCur_cou->pNext);
		pCur_cou = pCur_cou->pNext;
		pCur_cou->pNext = nullptr;
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
	Save_cou_to_test(pHead_cou, Create_third_folder("1", Create_second_folder("Semester", current_year)));
	Save_name_course(pHead_cou);
	std::wcout << "Input success" << std::endl;
}

void Input_course_by_file(Node_cou*& pHead_cou) {
	Time current_time;
	Get_current_time_to_int(current_time);
	char* current_year = Convert_int_to_char(current_time.date.Year);
	system("cls");
	pHead_cou = new Node_cou;
	Node_cou* pCur_cou = pHead_cou;
	std::wstring str;
	std::wstring a;
	std::wcout << "Please input the link: ";
	std::getline(std::wcin, str);
	std::wifstream fin(str);
	if (!fin) {
		std::wcout << L"Không thể đọc file \n";
	}
	else {
		fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
		while (!fin.eof()) {
			std::getline(fin, a);
			pCur_cou->pNext = new Node_cou;
			Input_one_course_by_file(a, pCur_cou->pNext);
			pCur_cou = pCur_cou->pNext;
			pCur_cou->pNext = nullptr;
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
	}
	fin.close();
	Save_cou_to_test(pHead_cou, Create_third_folder("1", Create_second_folder("Semester", current_year)));
	Save_name_course(pHead_cou);
	std::wcout << "Input success" << std::endl;
}

void Input_course_data(Node_cou*& pHead_cou) {
	int Max_List_Menu = 3;
	int flag = 0;
	SetColor(15, 0);
	std::wstring menu[] = { L"Input course by file",L"Input course by direct",L"Exit" };
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
						Input_course_by_file(pHead_cou);
						Sleep(100000);
						break;
					case 1:
						Input_course_direct(pHead_cou);
						Sleep(100000);
						break;
					case 2:
						Exit();
						flag = -1;
						break;
					}
					break;
				}
			}
		}
		if (flag == -1) {

			break;
		}
		Sleep(100);
	}
	Delete_Node_cou(pHead_cou);
}

