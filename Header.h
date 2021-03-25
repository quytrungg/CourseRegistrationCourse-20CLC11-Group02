#ifndef HEADER_H
#define HEADER_H

#include <iostreams
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
	//class
	//course
	//score
};

struct Class
{
	std::string name;
	Student stu;
};

struct Semester
{
	int term;
	int year;
	//start;
	//end;
	//course
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
	//class
	//score
};

struct Account
{
	std::string user;
	std::string pass;
};

struct Score
{
	//student's data
	double total;
	double final;
	double midterm;
	double other;
	double gpa;
	double ovrgpa;
};

#endif // !HEADER_H

