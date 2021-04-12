#ifndef STRUCT_H_
#define STRUCT_H_
#include <iostream>
#include <string>
#include <fstream>
#include <io.h>
#include <fcntl.h>
#include <locale>
#include <codecvt> //possible C++11?
#include <fstream>
#include <algorithm>
using namespace std;
struct account {
	string account_name, pass;
	account* pNext, * pPrev;
};//tài khoản
struct course {
	wstring id;
	wstring name, teacher_name;
	int num_cre;
	int max_student = 50;
	//day of the week
	wstring session;//MONS1_MONS3 hoặc MONS1_FRIS3
	course* pNext, * pPrev;
};//khóa học

// Struct ban đầu
//struct course {
//	string id;
//	wstring name, teacher_name;
//	int num_cre;
//	int max_student = 50;
//	//day of the week
//	string session;//MONS1_MONS3 hoặc MONS1_FRIS3
//	course* pNext, * pPrev;
//};//khóa học

struct id_class {
	string id;
	id_class* pNext, * pPrev;
};//lớp
struct id_course_of_student {
	string id;
	id_course_of_student* pNext, * pPrev;
};//id khóa học dùng cho cái in4_student
struct in4_student {
	unsigned long long int id;
	wstring fname;
	wstring lname;
	string gender;
	string dob;
	int soid;
	string id_class;
	in4_student* pNext, * pPrev;
	id_course_of_student* id_course;

};

#endif // !STRUCT_H_

