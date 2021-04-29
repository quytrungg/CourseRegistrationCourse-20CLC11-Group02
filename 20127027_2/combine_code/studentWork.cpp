#include"func.h"
bool check_active_course_registration() {
	ifstream in(path_semester_period);
	int a, b;
	in >> a >> b;
	in.close();
	return b;
}
in4_student* getNodeStudent_in4(string& username, HT_in4_student& student_in4) {
	in4_student* pCur = student_in4.head;
	wstring wname(username.begin(), username.end());
	while (pCur) {
		if (pCur->id == wname) return pCur;
		pCur = pCur->pNext;
	}
}
bool check_conflicted_course(wstring& a, wstring& b) {
	wstring a1 = a.substr(0, 5);
	wstring a2 = a.substr(6);
	wstring b1 = b.substr(0, 5);
	wstring b2 = b.substr(6);
	return ((a1 == b1) || (a1 == b2) || (a2 == b1) || (a2 == b2));
}

void signCourse(HT_course& pCourse, in4_student*& nodeStudent_in4) {
	course* pCur = pCourse.head;
	int n = 0;
	wcout << L"No, id, tên khóa học, tên giảng viên, số tín chỉ, số sinh viên tối đa, thời gian 2 buổi/1tuần." << endl;
	while (pCur) {
		n++;
		wcout << n << L". " << pCur->id << "," << pCur->name << "," << pCur->teacher_name << "," << pCur->num_cre << "," << pCur->max_student << "," << pCur->session << endl;
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
			if (pCur->max_student <= pCur->count) { 
				wcout << pCur->max_student << " " << pCur->count << endl;
				wcout << L"Số sinh viên học môn này đạt tối đa! Nhấn bất kì để quay về"; 
				_getch();
				return;
			}
			id_course_of_student* pCurStudent_in4 = nodeStudent_in4->id_course, * pPastStudent = 0;
			while (pCurStudent_in4) {
				if (check_conflicted_course(pCurStudent_in4->session, pCur->session)) {
					wcout << L"Trùng giờ học! Nhấn bất kì để quay về";
					_getch();
					return;
				}
				pPastStudent = pCurStudent_in4;
				pCurStudent_in4 = pCurStudent_in4->pNext;
			}
			if (pPastStudent==nullptr) {
				nodeStudent_in4->id_course = new id_course_of_student; 
				pPastStudent = nodeStudent_in4->id_course;
				pPastStudent->pNext = pPastStudent->pPrev = nullptr;
			}
			else {
				pPastStudent->pNext = new id_course_of_student;
				pPastStudent->pNext->pPrev = pPastStudent;
				pPastStudent = pPastStudent->pNext;
				pPastStudent->pNext = nullptr;
			}
				pCur->count++;
				pPastStudent->id = pCur->id;
				pPastStudent->teacher_name = pCur->teacher_name;
				pPastStudent->session = pCur->session;
			break;
		}
		pCur = pCur->pNext;
	}

}
void deleteACourse(HT_course& pCourse, in4_student*& nodeStudent_in4) {
	id_course_of_student* pCurStudent = nodeStudent_in4->id_course;
	int n = 0;
	wcout << L"id khóa học,tên giảng viên,thời gian học trong tuần" << endl;
	while (pCurStudent) {
		n++;
		wcout <<n<< L". " << pCurStudent->id << "," << pCurStudent->teacher_name << "," << pCurStudent->session << endl;
		pCurStudent = pCurStudent->pNext;
	}
	wcout << n + 1 << L". Quay về." << endl;
	int choose = user_choose_exist(1, n + 1);
	if (choose == n + 1) return;
	n = 0;
	pCurStudent = nodeStudent_in4->id_course;
	while (pCurStudent) {
		n++;
		if (n == choose) break;
		pCurStudent = pCurStudent->pNext;
	}
	course* pCurCourse = pCourse.head;
	while (pCurCourse) {
		if (pCurCourse->id == pCurStudent->id && pCurCourse->teacher_name == pCurStudent->teacher_name && pCurCourse->session == pCurStudent->session) break;
		pCurCourse = pCurCourse->pNext;
	}
	pCurCourse->count--;
	if (pCurStudent->pNext) pCurStudent->pNext->pPrev = pCurStudent->pPrev;
	if (pCurStudent->pPrev) pCurStudent->pPrev->pNext = pCurStudent->pNext;
	if (pCurStudent == nodeStudent_in4->id_course)nodeStudent_in4->id_course = pCurStudent->pNext;
	delete pCurStudent;
}
void viewSignCourse(in4_student*& nodeStudent_in4) {
	id_course_of_student* pCurStudent = nodeStudent_in4->id_course;
	int n = 0;
	wcout << L"id khóa học,tên giảng viên,thời gian học trong tuần" << endl;
	while (pCurStudent) {
		n++;
		wcout << n << L". " << pCurStudent->id << "," << pCurStudent->teacher_name << "," << pCurStudent->session << endl;
		pCurStudent = pCurStudent->pNext;
	}
	wcout << L"Nhấn bất kì để tiếp tục.";
	_getch();
}
void do_student_work(string& username, id_class*& idClass, HT_in4_student& student_in4, HT_course& pCourse, account*& student) {
	//xem còn thời gian đăng kí không trong date_registration.txt 
	LocalTime aBegin, aEnd, cTime = currentDateTime();
	load_deadline_registration(aBegin, aEnd);
	int t = 1;/*compare2Times(cTime, aEnd);*///so sánh cTime có nằm trong abegin, aend không
	if (!check_active_course_registration() || t==0) {
		wcout << L"Chưa có hoạt động nào, nhấn bất kì để tiếp tục";
		_getch();
		system("cls");
	}
	else {

		in4_student* nodeStudent_in4=getNodeStudent_in4(username, student_in4);
		int choose = -1;
		while (choose!=1) {
			wcout << L" _Khóa học_" << endl;
			wstring* menu = new wstring[4];
			COORD cursor = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
			menu[0] = L"Quay về";
			menu[1] = L"Đăng kí";
			menu[2] = L"Xóa khóa học đã đăng kí";
			menu[3] = L"Xem danh sách khóa học đã đăng kí";
			choose = choose_menu(cursor.X, cursor.Y, menu, 4);
			delete[]menu;
			switch (choose) {
			case 1: return;
			case 2:signCourse(pCourse, nodeStudent_in4); break;
			case 3:deleteACourse(pCourse, nodeStudent_in4); break;
			case 4:viewSignCourse(nodeStudent_in4);
			}
			if (choose <= 3 && choose >= 2) {
				update_course_csv(pCourse);
				update_student_in4_csv(student_in4);
			}
			system("cls");
		}
	}
}