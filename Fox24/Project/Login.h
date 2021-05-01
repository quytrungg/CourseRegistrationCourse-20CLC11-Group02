#ifndef LOGIN_H_
#define LOGIN_H_
static int flag;

bool Check_pass(wchar_t* pass, wchar_t* input);
wchar_t* Login_stu();
void Change_pass_stu(wchar_t* file);
void Screen_stu_to_console_stu(wchar_t* file);
void Sub_menu_stu(wchar_t* file);
void Menu_stu();
void Register_course(Node_cou*& pHead_cou_1, wchar_t* file);
void cout_name_course(Node_cou* pHead_cou, int n);
void View_course_stu(Node_cou*& pHead_cou, wchar_t* file);
void Cout_day_of_week(int n);

#endif // !LOGIN_H_

