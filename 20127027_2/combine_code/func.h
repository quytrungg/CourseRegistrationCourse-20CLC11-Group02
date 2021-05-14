#ifndef func_h
#define func_h
#include"struct_include_define.h"
//accountManage
int choose_type_account();
bool check_exist_user(account, account*&);
account login(int, account*&, account*&);
void changePassword(account*&,account&);
//combine
int user_choose_exist(int, int);
//courseManage
void add_course(HT_course&);
void courseManage(HT_course&, bool&, id_class*&, HT_in4_student&,score*&);
bool Check_session(wstring);
bool notInTheSemester(LocalTime&, LocalTime&);
//deletePointer
void deleteall_course(course*&);
void deleteall_student_in4(in4_student*&);
void deleteall_class(id_class*&);
void deleteall_account(account*&);
void deleteall_score(score*&);
void deleteall_menu(MenuList&);
//extraFunction
int convert_num(string&);
int wconvert_num(wstring&);
void remove_65279(wstring&);
void negativeClose();
void GotoXY(short, short);
int choose_menu(int, int, wstring*&, int);
string chooseClass(id_class*&);
COORD GetConsoleCursorPosition(HANDLE);
void ShowCur(bool);
void resetDataSchoolYear();
void resetDataSemester();
//loadData
void load_account(string, account*&);
void load_class(id_class*&);
void load_student_in4(HT_in4_student&);
void loadSchoolYear(string&, bool&, bool&, bool&);
void load_deadline_registration(LocalTime&, LocalTime&);
void load_course(HT_course&);
void loadSemesterPeriod(bool&, bool&);
void load_score(score*&);
//staffWork
void create_school_year(string&, bool&, bool&, bool&);
string choose_id_class(id_class*&);
void do_staff_work(string&, id_class*&, HT_in4_student&, HT_course&, account*&, account*&,score*&);
string getSchoolYear();
bool create_3_semester();
//studentWork
void do_student_work(string&, id_class*&, HT_in4_student&, HT_course&, account*&,score*&);
//timeManage
bool compare2Times(LocalTime&, LocalTime&);
bool checkDayIsTrue(LocalTime&);
bool checkYear(int);
LocalTime currentDateTime();
bool inputPeriodTime(LocalTime& , LocalTime& );
//upDateData
void update_school_year_txt(string&, bool&, bool&, bool&);
void update_class_txt(id_class*&);
void AddClass(id_class*&,bool&);
void add_student_in4(string, HT_in4_student&,wstring&,account*&);
void update_student_in4_csv(HT_in4_student&);
void update_account(account*&);
void update_date_create_course(LocalTime, LocalTime);
void update_course_csv(HT_course&);
void update_semester_period(bool&, bool&);
void update_score(score*&);
#endif