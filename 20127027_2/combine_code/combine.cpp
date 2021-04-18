#include"struct_include_define.h"
#include"func.h"
//#include<iostream>
//using namespace std;
int main() {
	//int i = "haha";
	//cout << 1;
	_setmode(_fileno(stdout), _O_WTEXT);
	account* staff = 0, * student = 0, user;
	id_class* idClass = 0;
	HT_in4_student student_in4;
	student_in4.head = student_in4.tail = 0;
	HT_course pCourse;
	pCourse.head = pCourse.tail = nullptr;
	user.account_name = "null";
	load_course(pCourse);
	load_class(idClass);
	load_student_in4(student_in4);
	load_account(path_staff_account, staff);//trong file có tài khoản mật khẩu staff, đưa tụi nó vào dll staff
	load_account(path_student_account, student);//trong file có tài khoản mật khẩu student, đưa tụi nó vào dll student
	while (user.account_name == "null") {
		user = login(choose_type_account(), staff, student);//nhận tài khoản mật khẩu từ người dùng
	}
	//cout << user.account_name[0];

	if (user.account_name[0] < '0' || user.account_name[0]>'9') { do_staff_work(idClass, student_in4,pCourse,student); }
	////menu(user);
	deleteall_student_in4(student_in4.head);
	deleteall_class(idClass);
	deleteall_account(staff);
	deleteall_account(student);
	return 0;
}
