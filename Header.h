#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>

struct Student
{
	int no;
	int id;
	std::string fname;
	std::string lname;
	bool gender;
	int dob;
	int soid;
	//Class data;
	//Course data;
	//Score data;
};

struct Class
{
	std::string name;
	Student data;
};

struct Semester
{
	int term;
	int year;
	DateTime start;
	DateTime end;
	//Course data;
};

struct Date
{
	int day;
	int month;
	int year;
};

struct Time
{
	int hour;
	int min;
	int sec;
};

struct DateTime
{
	Date d;
	Time t;
};

struct Course
{
	int id;
	std::string name;
	std::string teacher;
	int numofcre;
	int maxstu;
	//session
	//Class data;
	//Score data;
};

struct Account
{
	std::string user;
	std::string pass;
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
};

struct Node
{
	Student data;
	Node* pNext;
	Node* pPrev;
};

#endif // !HEADER_H

