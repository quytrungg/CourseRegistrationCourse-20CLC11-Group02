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

struct Node_stu {
	Student stu;
	Node_stu* pNext;
	Node_stu* pPre;
};

#endif // !STRUCT_H_

