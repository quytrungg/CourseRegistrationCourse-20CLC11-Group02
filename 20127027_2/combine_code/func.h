#ifndef func_h
#define func_h
#include"struct_include_define.h"
//accountManage
int choose_type_account();
bool check_exist_user(account, account*&);
account login(int, account*&, account*&);
//courseManage
void add_course(HT_course&);
void courseManage(HT_course&);
bool Check_session(wstring);
//deletePointer
void deleteall_student_in4(in4_student*&);
void deleteall_class(id_class*&);
void deleteall_account(account*&);
//extraFunction
int convert_num(string&);
int wconvert_num(wstring&);
int user_choose_exist(int, int);
//loadData
void load_account(string, account*&);
void load_class(id_class*&);
void load_student_in4(HT_in4_student&);
void loadSchoolYear(string&, bool&, bool&, bool&, bool&);
void load_deadline_registration(LocalTime&, LocalTime&);
void load_course(HT_course&);
//staffWork
void create_school_year(string&, bool&, bool&, bool&, bool&);
string choose_id_class(id_class*&);
void do_staff_work(id_class*&, HT_in4_student&,HT_course&,account*&);
//timeManage
bool compare2Times(LocalTime&, LocalTime&);
bool checkDayIsTrue(LocalTime&);
bool create_3_semester();
LocalTime currentDateTime();
//upDateData
void update_school_year_txt(string&, bool&, bool&, bool&,bool&);
void update_class_txt(id_class*&);
void AddClass(id_class*&);
void add_student_in4(string, HT_in4_student&,wstring&,account*&);
void update_student_in4_csv(HT_in4_student&);
void update_student_account(account*&);
void update_date_registration_session(LocalTime, LocalTime);
#endif