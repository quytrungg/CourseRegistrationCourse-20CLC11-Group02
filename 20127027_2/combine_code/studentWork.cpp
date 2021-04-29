#include"func.h"
bool check_active_course_registration() {
	ifstream in(path_semester_period);
	int a, b;
	in >> a >> b;
	in.close();
	return b;
}
in4_student* getNodetStudent_in4(string& username, HT_in4_student& student_in4) {
	in4_student* pCur = student_in4.head;
	wstring wname(username.begin(), username.end());
	while (pCur) {
		if (pCur->id == wname) return pCur;
		pCur = pCur->pNext;
	}
}
void do_student_work(string& username, id_class*& idClass, HT_in4_student& student_in4, HT_course& pCourse, account*& student) {
	//xem còn thời gian đăng kí không trong date_registration.txt 
	if (!check_active_course_registration()) {
		wcout << L"Chưa có khóa học nào, nhấn bất kì để tiếp tục";
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
			menu[2] = L"Xem danh sách khóa học đã đăng kí";
			menu[3] = L"Xóa khóa học đã đăng kí";
			choose = choose_menu(cursor.X, cursor.Y, menu, 4);
			delete[]menu;
			switch (choose) {
			case 1: return;
			case 2: //signCourse();
			}
		}
	}
}