﻿#include"struct_include_define.h"
#include"func.h"
//#include<iostream>
//using namespace std;
int main() {
	negativeClose();
	_setmode(_fileno(stdout), _O_WTEXT);
	account* staff = 0, * student = 0,  user ;

	id_class* idClass = 0;

	HT_in4_student student_in4;
	student_in4.head = student_in4.tail = 0;

	HT_course pCourse;
	pCourse.head = pCourse.tail = nullptr;

	load_course(pCourse);
	load_class(idClass);
	load_student_in4(student_in4);
	load_account(path_staff_account, staff);//trong file có tài khoản mật khẩu staff, đưa tụi nó vào dll staff
	load_account(path_student_account, student);//trong file có tài khoản mật khẩu student, đưa tụi nó vào dll student
	while (user.account_name != "end") {
		user.account_name = "null";
		while (user.account_name == "null") {
			user = login(choose_type_account(), staff, student);//nhận tài khoản mật khẩu từ người dùng
			if (user.account_name == "end") break;
		}
		//cout << user.account_name[0];
		if (user.account_name != "end") {
			int choose;
			do {
				wstring showName(user.account_name.begin(), user.account_name.end());
				wcout << L" _Tài khoản " << showName << L"_" << endl;
				COORD cursor = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
				wstring* menu = new wstring[3];
				menu[0] = L"Đăng xuất";
				menu[1] = L"Đổi mật khẩu";
				menu[2] = L"Công việc của bạn";
				choose = choose_menu(cursor.X, cursor.Y, menu, 3);
				switch (choose) {
				case 2:changePassword((user.account_name[0] < '0' || user.account_name[0]>'9') ? staff : student, user); break;
				case 3:
					if (user.account_name[0] < '0' || user.account_name[0]>'9') 
						do_staff_work(user.account_name, idClass, student_in4, pCourse, student, staff); 
					else do_student_work(user.account_name, idClass, student_in4, pCourse, student);
				}
				system("cls");
			} while (choose != 1);
		}
	}
	deleteall_student_in4(student_in4.head);
	deleteall_class(idClass);
	deleteall_account(staff);
	deleteall_account(student);
	deleteall_course(pCourse.head);
	return 0;
}
