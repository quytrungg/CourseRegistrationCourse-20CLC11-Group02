#ifndef HEADER_H
#define HEADER_H
//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#include<fstream>
#include <locale>
#include <codecvt>
#include <string>
#include <wincrypt.h>
#include<iomanip>
#include <iostream>
#include<Windows.h>
#include<sys/stat.h>
#include<sys/types.h>


struct in4_student {
	int id;
	wchar_t* fname; 
	wchar_t* lname;
	wchar_t* gender;
	wchar_t* dob;
	int soid;
	std::string id_class;
	in4_student* pNext, * pPrev;
	//id_course_of_student* id_course;
};

struct account {
	std::string account_name, pass;
	account* pNext, * pPrev;
};//tài khoản

struct course {
	std::string id;
	std::wstring name, teacher_name;
	int num_cre;
	int max_student = 50;
	//day of the week
	std::string session;//MONS1_MONS3 hoặc MONS1_FRIS3
	course* pNext, * pPrev;
};//khóa học

struct id_class {
	std::string id;
	id_class* pNext, * pPrev;
};//lớp
	
struct id_course_of_student {
	std::string id;
	id_course_of_student* pNext, * pPrev;
};//id khóa học dùng cho cái in4_student

struct score
{
	wchar_t* no;
	wchar_t* Id;
	wchar_t* fname;
	wchar_t* lname;
	wchar_t* totalScore;
	wchar_t* final;
	wchar_t* midterm;
	wchar_t* other;
	wchar_t* GPA;
	wchar_t* ovrGPA;
	score* next,* prev;
};

void ChangeToVietNamese();

in4_student* Inputdata(in4_student*& t, std::wfstream& fin);
in4_student ChangeToData(std::wstring line);
void add_student(in4_student*& stu, in4_student temp);

void PrintStu(in4_student*& data);
void DeallocateData(in4_student*& infor);
void DeallocateData(score*& infor);
int ChangeStringToInt(std::wstring a);

void add_score(score*& sc, score temp);
score ChangeScoreToData(std::wstring line);
score* inputScore(score*& t, std::wfstream& finScore);
void OutputScore(score*& sc);
void forceNotComma(std::wstring a);
void makeBigfolder();
void accessToFile(std::wfstream& fin);
void ReverseTheList(in4_student*& pHead);
void makeAccess(std::wfstream& fin);
#endif // !HEADER_H