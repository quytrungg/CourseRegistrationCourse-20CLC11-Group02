#include"func.h"
void add_course(HT_course& pHead) {
	wcout << L" _Thêm khóa học_" << endl;
	wstring* menu = new wstring[2];
	COORD cursor = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
	menu[0] = L"Nhập môn học";
	menu[1] = L"Dừng";
	int choose = choose_menu(cursor.X, cursor.Y, menu, 2);
	delete[]menu;
	/*std::wcout << L"1. Nhập môn học" << std::endl;
	std::wcout << L"2. Dừng" << std::endl;
	std::wcout << L"Chọn: ";
	n = user_choose_exist(1, 2);*/
	course* pCur = nullptr;
	while (choose != 2) {
		if (pHead.head == nullptr) {
			pHead.head = new course;
			pHead.tail = pHead.head;
			pHead.head->pNext = pHead.head->pPrev = nullptr;
			pCur = pHead.head;
		}
		else {
			pCur = pHead.tail;
			pCur->pNext = new course;
			pCur->pNext->pPrev = pCur;
			pCur = pCur->pNext;
			pCur->pNext = nullptr;
			pHead.tail = pCur;      
		}
		_setmode(_fileno(stdin), _O_WTEXT);
		wcout << L"ID : ";
		getline(wcin, pCur->id);
		wcout << L"Tên khóa học: ";
		getline(wcin, pCur->name);
		wcout << L"Tên giảng viên: ";
		getline(wcin, pCur->teacher_name);
		wstring temp;
		wcout << L"Số tín chỉ: ";
		getline(wcin, temp);
		pCur->num_cre = wconvert_num(temp);
		while (pCur->num_cre == -1) {
			wcout << L"Nhập lại (số tín chỉ là số tự nhiên): ";
			getline(wcin, temp);
			pCur->num_cre = wconvert_num(temp);
		}
		wcout << L"Số sinh viên tối đa: ";
		getline(wcin, temp);
		pCur->max_student = wconvert_num(temp);
		if (pCur->max_student == -1) pCur->max_student = 50;
		do {
			std::wcout << L"Nhập 2 buổi học trong tuần (Ex: MONS1_TUES3): ";
			getline(wcin, pCur->session);
		} while (!Check_session(pCur->session));
		wcout << L" _Thêm khóa học_" << endl;
		wstring* menu = new wstring[2];
		COORD cursor = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
		menu[0] = L"Nhập môn học";
		menu[1] = L"Dừng";
		choose = choose_menu(cursor.X, cursor.Y, menu, 2);
		delete[]menu;
	}
	_setmode(_fileno(stdin), _O_TEXT);
}
void update_course_list(HT_course& pCourse) {
	course* pCur = pCourse.head;
	int n = 0;
	wcout << L"No"<< setw(2) << L"id" << setw(8) << L"tên khóa học"<< setw(15) <<L"tên giảng viên" << setw(9) <<L"số tín chỉ"<< setw(3) << L"số sinh viên tối đa"<< setw(3) <<L"thời gian 2 buổi/1tuần." << endl;
	while (pCur) {
		n++;
		wcout << n << L". " << pCur->id << setw(2) << pCur->name << setw(25-pCur->name.length()) << pCur->teacher_name << setw(20-pCur->teacher_name.length()) << pCur->num_cre << "   " << pCur->max_student << "  " << pCur->session << endl;
		pCur = pCur->pNext;
	}
	wcout << n + 1 << L". Quay về." << endl;
	int choose = user_choose_exist(1, n+1);
	if (choose == n + 1) return;
	n = 0;
	pCur = pCourse.head;
	while (pCur) {
		n++;
		if (n == choose) {
			_setmode(_fileno(stdin), _O_WTEXT);
			wcout << L"ID : ";
			getline(wcin, pCur->id);
			wcout << L"Tên khóa học: ";
			getline(wcin, pCur->name);
			wcout << L"Tên giảng viên: ";
			getline(wcin, pCur->teacher_name);
			wstring temp;
			wcout << L"Số tín chỉ: ";
			getline(wcin, temp);
			pCur->num_cre = wconvert_num(temp);
			while (pCur->num_cre == -1) {
				wcout << L"Nhập lại (số tín chỉ là số tự nhiên): ";
				getline(wcin, temp);
				pCur->num_cre = wconvert_num(temp);
			}
			wcout << L"Số sinh viên tối đa: ";
			getline(wcin, temp);
			pCur->max_student = wconvert_num(temp);
			if (pCur->max_student == -1) pCur->max_student = 50;
			do {
				wcout << L"Nhập 2 buổi học trong tuần (Ex: MONS1_TUES3): ";
				getline(wcin, pCur->session);
			} while (!Check_session(pCur->session));
			_setmode(_fileno(stdin), _O_TEXT);
			break;
		}
		pCur = pCur->pNext;
	}
}
void delete_a_course(HT_course& pCourse) {
	course* pCur = pCourse.head;
	int n = 0;
	wcout << L"No" << setw(2) << L"id" << setw(8) << L"tên khóa học" << setw(15) << L"tên giảng viên" << setw(9) << L"số tín chỉ" << setw(3) << L"số sinh viên tối đa" << setw(3) << L"thời gian 2 buổi/1tuần." << endl;
	while (pCur) {
		n++;
		wcout << n << L". " << pCur->id << setw(2) << pCur->name << setw(25 - pCur->name.length()) << pCur->teacher_name << setw(20 - pCur->teacher_name.length()) << pCur->num_cre << "   " << pCur->max_student << "  " << pCur->session << endl;
		pCur = pCur->pNext;
	}
	wcout << n + 1 << L". Quay về." << endl;
	int choose = user_choose_exist(1, n + 1);
	if (choose == n + 1) return;
	n = 0;
	pCur = pCourse.head;
	while (pCur) {
		n++;
		if (n == choose) {
			if (pCur == pCourse.head) {
				pCourse.head = pCourse.head->pNext;
				pCourse.tail = pCourse.head;
			}
			if (pCur->pNext) pCur->pNext->pPrev = pCur->pPrev;
			if (pCur->pPrev)pCur->pPrev->pNext = pCur->pNext;
			delete pCur;
			break;
		}
		pCur = pCur->pNext;
	}
}
void view_list_course(HT_course& pCourse) {
	course* pCur = pCourse.head;
	int n = 0;
	if (pCur == nullptr) wcout << L"Chưa có khóa học nào."; else
		wcout << L"No" << setw(2) << L"id" << setw(8) << L"tên khóa học" << setw(15) << L"tên giảng viên" << setw(9) << L"số tín chỉ" << setw(3) << L"số sinh viên tối đa" << setw(3) << L"thời gian 2 buổi/1tuần." << endl;
	while (pCur) {
		n++;
		wcout << n << L". " << pCur->id << setw(2) << pCur->name << setw(25 - pCur->name.length()) << pCur->teacher_name << setw(20 - pCur->teacher_name.length()) << pCur->num_cre << "   " << pCur->max_student << "  " << pCur->session << endl;
		pCur = pCur->pNext;
	}
	wcout << L"Nhập bất kì để tiếp tục.";
	_getwch();
}
void viewClass_StudentInClass(id_class*& idClass, HT_in4_student& student_in4) {
	int n = 0;
	id_class* pCurClass = idClass;
	while (pCurClass) {
		n++;
		wstring temp(pCurClass->id.begin(), pCurClass->id.end());
		wcout << n << ". " << temp << endl;
		pCurClass = pCurClass->pNext;
	}
	wcout << n + 1 << L". Quay về" << endl;
	int choose = user_choose_exist(1, n + 1);
	if (choose == n + 1) return;
	n = 0;
	pCurClass = idClass;
	while (pCurClass) {
		n++;
		if (n == choose) break;
		pCurClass = pCurClass->pNext;
	}
	wstring temp(pCurClass->id.begin(), pCurClass->id.end());
	in4_student* pCurStudent = student_in4.head;
	n = 0;
	wcout << "\n";
	while (pCurStudent) {
		if (pCurStudent->id_class == temp) {
			n++;
			if (n <= 9)
			{
				wcout << n << ".  " << pCurStudent->id << "  " << pCurStudent->lname << setw(27 - pCurStudent->lname.length()) << pCurStudent->fname << "    " << pCurStudent->gender << setw(18 - pCurStudent->gender.length()) << pCurStudent->dob << "   " << pCurStudent->soid << setw(20 -pCurStudent->soid.length()) << pCurStudent->id_class << endl;
			}
			else
			{
				wcout << n << ". " << pCurStudent->id << "  " << pCurStudent->lname << setw(27 - pCurStudent->lname.length()) << pCurStudent->fname << "    " << pCurStudent->gender << setw(18 - pCurStudent->gender.length()) << pCurStudent->dob << "   " << pCurStudent->soid << setw(20 - pCurStudent->soid.length()) << pCurStudent->id_class << endl;
			}
		}
		pCurStudent = pCurStudent->pNext;
	}
	wcout << L"Nhấn bất kì để quay về.";
	_getch();
}
bool studentInThisCourse(in4_student*& pCurStudent, course*& pCurCourse) {
	id_course_of_student* pCurCourseStudent = pCurStudent->id_course;
	while (pCurCourseStudent) {
		if (pCurCourseStudent->id == pCurCourse->id && pCurCourseStudent->teacher_name == pCurCourse->teacher_name && pCurCourseStudent->session == pCurCourseStudent->session)
			return 1;
		pCurCourseStudent = pCurCourseStudent->pNext;
	}
	return 0;
}
void viewCourse_StudentInCourse(HT_course& pCourse, HT_in4_student& student_in4) {
	course* pCurCourse = pCourse.head;
	int n = 0;
	if (pCurCourse == nullptr) wcout << L"Chưa có khóa học nào."; else
		wcout << L"No" << "    " << L"id" <<setw(20) << L"tên khóa học"<< setw(20) <<L"tên giảng viên"<<  setw(20) << L"số tín chỉ"<< "   " <<L"số sinh viên tối đa"<< "    " << L"thời gian 2 buổi/1tuần"<< "     " <<L"lượng học sinh hiện tại." << endl;
	while (pCurCourse) {
		n++;
		wcout << n << L".  " << pCurCourse->id << setw(21 - pCurCourse->id.length()) << pCurCourse->name << setw(28-pCurCourse->name.length()) << pCurCourse->teacher_name << setw(27-pCurCourse->teacher_name.length()) << pCurCourse->num_cre << setw(17) << pCurCourse->max_student << setw(28) << pCurCourse->session << setw(25) << pCurCourse->count << endl;
		pCurCourse = pCurCourse->pNext;
	}
	wcout << n + 1 << L". Quay về." << endl;
	int choose = user_choose_exist(1, n + 1);
	if (choose == n + 1) return;
	n = 0;
	pCurCourse = pCourse.head;
	while (pCurCourse) {
		n++;
		if (n == choose) break;
		pCurCourse = pCurCourse->pNext;
	}
	in4_student* pCurStudent = student_in4.head;
	n = 0;
	wcout << "\n";
	while (pCurStudent) {
		if (studentInThisCourse(pCurStudent,pCurCourse)) {
			n++;
			wcout << n << ". " << pCurStudent->id << "  " << pCurStudent->lname << setw(27-pCurStudent->lname.length()) << pCurStudent->fname << setw(15 - pCurStudent->fname.length()) << pCurStudent->gender << "   " << pCurStudent->dob << "   " << pCurStudent->soid << setw(20 - pCurStudent->soid.length()) << pCurStudent->id_class << endl;
		}
		pCurStudent = pCurStudent->pNext;
	}
	wcout << L"Nhấn bất kì để tiếp tục.";
	_getch();

}

void courseManage(HT_course& pCourse,bool& active_registration_session,id_class*& idClass,HT_in4_student& student_in4) {
	int choose;
	if (active_registration_session == 0) {
		do {
			wcout << L" _Khóa học_" << endl;
			wstring* menu = new wstring[6];
			COORD cursor = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
			menu[0] = L"Quay về";
			menu[1] = L"Thêm khóa học";
			menu[2] = L"Cập nhật khóa học";
			menu[3] = L"Xóa khóa học";
			menu[4] = L"Xem danh sách khóa học";
			menu[5] = L"Kích hoạt phiên đăng kí khóa học của học kì hiện tại";
			choose = choose_menu(cursor.X, cursor.Y, menu, 6);
			delete[]menu;
			/*wcout << L"1. Quay về." << endl;
			wcout << L"2.Thêm khóa học." << endl;
			wcout << L"3.Cập nhật khóa học." << endl;
			wcout << L"4.Xóa khóa học." << endl;
			wcout << L"5.Xem danh sách khóa học." << endl;
			wcout << L"6. Kích hoạt phiên đăng kí khóa học của học kì hiện tại" << endl;
			wcout << L"Chọn: ";
			choose = user_choose_exist(1, 5);*/
			switch (choose) {
			case 2: add_course(pCourse); break;
			case 3: update_course_list(pCourse); break;
			case 4: delete_a_course(pCourse); break;
			case 5: view_list_course(pCourse); break;
			case 6:if (pCourse.head) {
				active_registration_session = 1;
				update_date_sign_course();
			}
				  else wcout << L"Chưa có khóa học nào!";
			}
			if (choose <= 4 && choose >= 2) update_course_csv(pCourse);
			system("cls");
		} while (choose != 1);
	}
	else {
		do {
			wcout << L" _Xem lớp và khóa học_" << endl;
			wstring* menu = new wstring[3];
			COORD cursor = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
			menu[0] = L"Quay về";
			menu[1] = L"Xem lớp";
			menu[2] = L"Xem khóa học";
			choose = choose_menu(cursor.X, cursor.Y, menu, 3);
			delete[]menu;
			switch (choose) {
			case 2:viewClass_StudentInClass(idClass, student_in4); break;
			case 3:viewCourse_StudentInCourse(pCourse,student_in4);
			}
			system("cls");
		} while (choose != 1);
	}
}
bool Check_session(wstring str) {
	wchar_t* a = new wchar_t[str.length() + 1];
	str.copy(a, str.length(), 0);
	a[str.length()] = L'\0';
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
		else return false;
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
		else return false;
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
