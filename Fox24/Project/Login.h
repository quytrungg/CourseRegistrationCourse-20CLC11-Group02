#ifndef LOGIN_H_
#define LOGIN_H_
static int flag;

bool Check_pass(wchar_t* pass, wchar_t* input);
wchar_t* Login_stu();
void Change_pass_stu(wchar_t* file);
void Screen_stu_to_console_stu(wchar_t* file);
void Sub_menu_stu(wchar_t* file);
void Menu_stu();

#endif // !LOGIN_H_

