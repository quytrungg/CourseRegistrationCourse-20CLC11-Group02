//
//  Function1.hpp
//  csv
//
//  Created by Mai Quý Trung on 31/03/2021.
//

#ifndef FUNCTION1_H
#define FUNCTION1_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#define _CRT_SECURE_NO_WARNINGS

//Tài khoản
struct account {
    std::string account_name, pass;
    account* pNext, * pPrev;
};

//Khoá học
struct course {
    std::wstring id;
    std::wstring name,teacher_name;
    std::wstring num_cre;
    int max_student = 50;
    int count;
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
    std::wstring id;
    std::wstring teacher_name;
    std::string session;
    id_course_of_student* pNext, * pPrev;
};

//info student
struct in4_student {
    std::wstring id;
    std::wstring fname;
    std::wstring lname;
    std::wstring gender;
    std::wstring dob;
    int soid;
    std::wstring id_class;
    in4_student* pNext, * pPrev;
    id_course_of_student* id_course = nullptr;

};

struct HT_in4_student {
    in4_student* head, * tail;
    //a.data.id_course.data.id
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

struct Semester
{
    int sem[3];
    int year;
    DateTime start;
    DateTime end;
    //Course data;
};

struct Score{
    wchar_t* no;
    wchar_t* id;
    wchar_t* fname;
    wchar_t* lname;
    wchar_t* totalScore;
    wchar_t* final;
    wchar_t* midterm;
    wchar_t* other;
    wchar_t* gpa;
    wchar_t* ovrgpa;
    Score *pNext, *pPrev;
};

struct MenuList
{
    int option;
    MenuList* pNext;
    MenuList* pPrev;
};

//--------------------Class--------------------
void AddClass(id_class* &pHead);
void OutputClassFile(std::string path, id_class* pHead);
id_class* FindClass(std::string path, id_class* &pHead);
void ChooseClass(id_class*& pHead);
void LoadClass(std::string path, id_class*& pHead);
int GetClassYear(id_class& a);
void AddMoreClass(id_class*& pHead);

//--------------------Student--------------------
void FindStudent(std::string path, in4_student* &pHead);
in4_student* FindReturnStudent(std::string path, in4_student* &pHead);

//--------------------Account--------------------
void load_account(std::string path, account*& acc);
void PrintAccount(account* pHead);
account* FindAccount(account* &pHead);
void ChangePassword(account* &pHead);
void SaveAccount(std::string path, account* &pHead);

//--------------------Course-Registration--------------------
bool check_conflicted_course(course& a, course& b);
void DeleteCourse(course*& pHead);
course* FindCourse(course*& pHead);
void Enroll(std::string path, in4_student* &pHead1, course* &pHead2);
void UnEnroll(std::string path, in4_student* &pHead1, course* &pHead2);
void CourseMenu(std::string path, in4_student* &pHead1, course* &pHead2);

//--------------------Deallocation--------------------
void DeallocateStudent(in4_student* &pHead);
void DeallocateCourseOfStudent(id_course_of_student* &pHead);
void DeallocateScore(Score* &pHead);
void DeleteClass(id_class*& pHead);
void DeallocateAccount(account*& pHead);

//--------------------Check-Course--------------------
bool CheckCourseQuantity(in4_student* &pHead);
bool CheckStudentQuantity(course* &pHead);
bool CheckConflictedEnroll(course* &pHead1, id_course_of_student* &pHead2);
bool CheckConflictedCourse(course* &pHead1, in4_student* &pHead2);

//--------------------Add-Course--------------------
void LoadCourse(std::string path, course*& pHead);
void AddCourse(course*& cou, course temp);
course ChangeToData(std::wstring line);
course* InputCourse(course*& pHead, std::wfstream& fin);
void ReverseTheList(course*& pHead);
void PrintCourse(course* data, std::string path);
void AddCourse(course*& pHead);
void PrintStudentInCourseOnConsole(course*& pHead1, in4_student*& pHead2, std::string path);

//--------------------Student-Class--------------------
bool FindStudentClass(in4_student*& pHead, std::wstring find);
void ReverseTheList(in4_student*& pHead);
void PrintStudentClass(in4_student* pHead, std::string path);

//--------------------Score--------------------
Score* FindStudentScore(Score*& pHead1, in4_student*& pHead2, std::string path);
void ChangeScore(Score*& pHead1, in4_student*& pHead2, std::string path);
void ReverseTheList(Score*& pHead);
void UpdateScore(Score*& pHead, std::string path);

//---------------------Student-Class-Score--------------------
void FindScore(Score*& pHead1, in4_student*& pHead2, std::string path);
void PrintStudentScore(Score*& pHead1, in4_student*& pHead2, std::string path);
void PrintScoreboardCourse(in4_student*& pHead1, Score*& pHead2, course* pHead3, std::string path);

//SubFunction
void Exit();
void ClearScreen();
void EditScoreFile(Score*& pHead1, in4_student*& pHead2, std::string path);
#endif /* Function1_h */
