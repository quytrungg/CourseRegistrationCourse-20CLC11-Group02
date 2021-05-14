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
#include <time.h>
//#include <stdlib.h>
#include <algorithm>
#include <conio.h>//wgetch()
#include<Windows.h>
#include<iomanip>
using namespace std;
#define path_staff_account "staff_account.txt"
#define path_student_account "student_account.txt"
#define path_school_year "school_year.txt"
#define path_idClass "class.txt"
#define path_student_in4 "student_in4.csv"
#define path_date_semester "semester.txt"
#define path_date_create_course "date_create_course.txt"//thực ra là thời gian sinh viên đăng kí, cái này đặt nhầm tên
#define path_course_csv "course.csv"
#define path_score_csv "score.csv"
#define path_staff_in4 "staff_in4.txt"
#define path_semester_period "semester_period.txt"

const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());
struct account {
	string account_name, pass;
	account* pNext, * pPrev;
};

struct id_class {
	string id;
	id_class* pNext, * pPrev;
};

struct course {
	wstring id;
	wstring name, teacher_name;
	int num_cre;
	int max_student;
	int count = 0;
	//day of the week
	wstring session;//MONS1_MONS3 hoặc MONS1_FRIS3
	course* pNext, * pPrev;
};
struct HT_course {
	course* head, * tail;
};

struct id_course_of_student {
	wstring id,teacher_name;
	wstring session;
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

struct Date {
	int Day=-1;
	int Month=-1;
	int Year=-1;
};
//struct Time {
//	int Seconds;
//	int Minutes;
//	int Hours;
//};
struct LocalTime {
	//struct Time time;
	struct Date date;
};
struct score
{
	wstring id;
	wstring fullname;
	wstring id_class;
	wstring id_course;
	wstring teacher_name;
	wstring session;
	wstring schoolYear;
	LocalTime dateStartSemester;
	double totalMark = -1;
	double final = -1;
	double midterm = -1;
	double other = -1;
	score* pNext, * pPrev;
};

struct MenuList {
	wstring option;
	MenuList* pNext;
};
#endif