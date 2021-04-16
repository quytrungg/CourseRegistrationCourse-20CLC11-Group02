#ifndef SAVE_H_
#define SAVE_H_
#include "Struct.h"

char* Create_second_folder(std::string str, char* main_folder);
char* Create_third_folder(std::string str, char* second_folder);
void Create_main_folder();
char* Create_file(char* filename, char* folder, std::string filetype);

#endif // !SAVE_H_

