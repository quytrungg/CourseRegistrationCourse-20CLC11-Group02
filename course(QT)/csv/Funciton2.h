//
//  Funciton2.hpp
//  csv
//
//  Created by Mai Quý Trung on 31/03/2021.
//
/*
#ifdef __APPLE__
        #include <sys/uio.h>
#else
        #include <sys/io.h>
#endif
*/
#ifndef GUNCTION2_H
#define FUNCTION2_H

#define _CRT_SECURE_NO_WARNINGS

#include <io.h>
#include <fcntl.h>
#include <locale>
#include <windows.h>
#include <codecvt>
#include <sstream>

#define On_Black  "\033[40m"//tô nền màu đen
#define On_White  "\033[0;107m" //tô nền màu trắng
#define On_Yellow  "\033[0;103m" //to nen mau vang
#define RESET   "\033[0m" // đưa về nguyên bản
#define BLACK   "\033[1m\033[30m" //xuất chữ màu đen nhạt
#define ALLBLACK   "\033[30m" //xuất chữ màu đen
#define RED     "\033[31m" //xuất chữ màu đỏ
#define GREEN   "\033[32m" //xuất chữ màu lục
#define YELLOW  "\033[33m" //xuất chữ màu vàng
#define BLUE    "\033[34m" //xuất chữ màu lam
#define MAGENTA "\033[35m"//xuất chữ màu tím
#define CYAN    "\033[36m" //xuất chữ màu xanh dương nhạt
#define WHITE   "\033[37m" //xuất chữ màu vàng trắng
#define _SIZE 14    // kích cỡ bàn cờ
#define _LONGSIZE 120 // chiều dài console
#define KEY_UP 72 //phím di chuyển lên
#define KEY_DOWN 80 //phím di chuyển xuống
#define KEY_LEFT 75 //phím di chuyển trái
#define KEY_RIGHT 77 //phím di chuyển phải
#define KEY_ENTER 13//phim enter
#define KEY_ESC 27// phim esc

//void ReadVietnamese();
void ChangeToVietnamese();

const std::string currentDateTime();
char* StringToCharPointer(std::string text);

//bool comparei(std::wstring stringA , std::wstring stringB);

void GotoXY(short x, short y);
std::string WriteMenu(std::string str);
short Menu(std::string list[], short size, short Xposition, short Yposition);

//void Menu();

std::string InputHidden();

std::wstring StringToWString(std::wstring& ws, const std::string& s);

int ChangeStringToInt(std::wstring a);

#endif /* Funciton2_h */
