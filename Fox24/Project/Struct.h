#ifndef STRUCT_H_
#define STRUCT_H_

#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include <locale>
#include <codecvt> //possible C++11?
#include <fstream>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <direct.h>
#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>

struct Account {
	wchar_t* ID;
	wchar_t* Pass;
};

struct Date {
	int Day;
	int Month;
	int Year;
};

struct Time {
	Date date;
	int seconds;
	int minutes;
	int hours;
};

struct Student {
	int ID;
	wchar_t* FirstName;
	wchar_t* LastName;
	wchar_t* Gender;
	Date Birthday;
	int SocialID;
	Account account;
};

struct Class {
	wchar_t* Name;
	wchar_t* StudentID;
};

struct Timetable {
	int day_of_week;
	int session;
};

struct Course {
	wchar_t* ID;
	wchar_t* Name;
	wchar_t* Teacher_Name;
	int Credit;
	int max_stu = 50;
	int count = 0;
	Timetable ses_1;
	Timetable ses_2;
	wchar_t* StudentID;

};

struct Node_stu {
	Student stu;
	Node_stu* pNext;
	Node_stu* pPre;
};

struct Node_cla {
	Class cla;
	Node_cla* pNext;
	Node_cla* pPre;
};

struct Node_cou {
	Course cou;
	Node_cou* pNext;
	Node_cou* pPre;
};

#endif // !STRUCT_H_

