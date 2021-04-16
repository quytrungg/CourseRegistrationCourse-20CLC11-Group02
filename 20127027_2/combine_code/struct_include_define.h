#ifndef struct_include_define_h
#define struct_include_define_h
#include<iostream>
#include<fstream>
#include<io.h>
#include<fcntl.h>
#include <locale>
#include <codecvt>
#include<string>
#include<sstream>
using namespace std;
#define path_staff_account "staff_account.txt"
#define path_student_account "student_account.txt"
#define path_school_year "school_year.txt"
#define path_idClass "class.txt"
#define path_student_in4 "student_in4.csv"
const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());
struct account {
	string account_name, pass;
	account* pNext, * pPrev;
};
struct id_class {
	string id;
	id_class* pNext, * pPrev;
};
struct id_course_of_student {
	wstring id;
	id_course_of_student* pNext, * pPrev;
};//id khóa học dùng cho cái in4_student
struct in4_student {
	wstring id;
	wstring fname;
	wstring lname;
	wstring gender;
	wstring dob;
	wstring soid;
	wstring id_class;
	in4_student* pNext, * pPrev;
	id_course_of_student* id_course;

};
struct HT_in4_student {
	in4_student * head,* tail;
	//a.data.id_course.data.id
};
#endif