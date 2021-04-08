#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <windows.h>

struct Student
{
	int no;
	int id;
	unsigned long long int id;
	std::string fname;
	std::string lname;
	bool gender;
	int dob;
	char gender;
	unsigned long long int dob;
	int soid;
	Account acc;
	//Class data;
	//Course data;
	//Score data;
};
struct Class
{

};
struct Semester
{
		int term;
		int sem[3];
		int year;
		DateTime start;
		DateTime end;
};
struct Account
{

};
struct Score
{
	Student data;
	double total;
	double final;
	double midterm;
	double other;
	double gpa;
	double ovrgpa;
	//course
};
struct DateTime
{
	int dd;
	int mm;
	int yy;
};
struct NodeStudent
{
	Student data;
	NodeStudent* pNext;
	NodeStudent* pPrev;
};
struct NodeScore
{
	Score data;
	NodeScore* pNext;
	NodeScore* pPrev;
};

#endif // !HEADER_H
