#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>

struct Account
{
	std::string user;
	std::string pass;
};

struct Student
{
	std::string no;
	std::string id;
	std::string fname;
	std::string lname;
	std::string gender;
	std::string dob;
	std::string soid;
	Account acc;
	//Class data;
	//Course data;
	//Score data;
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

struct Class
{
	std::string name;
	Student data;
};

struct DateTime
{
	Date d;
	Time t;
};

struct Semester
{
	int sem[3];
	int year;
	DateTime start;
	DateTime end;
	//Course data;
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

struct Score
{
	double total;
	double final;
	double midterm;
	double other;
	double gpa;
	double ovrgpa;
	//course
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

void SetDateTime(Date* d, Time* t);
void InputStudent(std::string path, NodeStudent* &pHead);
void InputScore(std::string path, NodeScore* &pHead);

#endif // !HEADER_H

