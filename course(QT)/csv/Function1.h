//
//  Function1.hpp
//  csv
//
//  Created by Mai Quý Trung on 31/03/2021.
//

#ifndef Function1_h
#define Function1_h

#include <iostream>
#include <fstream>
#include <string>

//Tài khoản
struct account {
    std::string account_name, pass;
    account* pNext, * pPrev;
};

//Khoá học
struct course {
    std::string id;
    std::wstring name,teacher_name;
    int num_cre;
    int max_student = 50;
    //day of the week
    std::string session;//MONS1_MONS3 hoặc MONS1_FRIS3
    course* pNext, * pPrev;
};

//Lớp
struct id_class {
    std::string id;
    id_class* pNext, * pPrev;
};

//id khóa học dùng cho cái in4_student
struct id_course_of_student {
    std::string id;
    id_course_of_student* pNext, * pPrev;
};

struct in4_student {
    unsigned long long int id;
    std::wstring fname;
    std::wstring lname;
    std::string gender;
    std::string dob;
    int soid;
    std::string id_class;
    in4_student* pNext, * pPrev;
    id_course_of_student* id_course;

};
/*
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

struct Semester
{
    int sem[3];
    int year;
    DateTime start;
    DateTime end;
    //Course data;
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
    Score* pNext;
    Score* pPrev;
*/
void AddClass(id_class* &pHead);
void OutputClassFile(std::string path, id_class* pHead);
id_class* FindClass(std::string path, id_class* &pHead);
void FindStudent(std::string path, in4_student* &pHead);
char* StringToChar(std::string text);
void MenuClassList(id_class* &pHead);
void InputClassList(std::string path, id_class* &pHead);
int GetClassYear(id_class &a);
bool check_conflicted_course(course &a, course &b);
void DeleteClass(id_class* &pHead);
void DeleteCourse(course* &pHead);
account* FindAccount(account* &pHead);
void ChangePassword(account* &pHead);

#endif /* Function1_h */
