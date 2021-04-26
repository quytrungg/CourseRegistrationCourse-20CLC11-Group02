#ifndef SAVE_H_
#define SAVE_H_
#include "Struct.h"

char* Create_second_folder(std::string str, char* main_folder);
char* Create_third_folder(std::string str, char* second_folder);
void Create_main_folder(char* current_year);
char* Create_file(char* filename, char* folder, std::string filetype);
wchar_t* Create_file_1(wchar_t* filename, char* folder, std::string filetype);
void Save_stu_to_test(Node_stu* pHead, char* folder);
void Save_cla_to_test(Node_cla* pHead, char* folder);
void Save_name_class(Node_cla* pHead);
void Save_cou_to_test(Node_cou* pHead, char* folder);
void Save_name_course(Node_cou* pHead);

#endif // !SAVE_H_

