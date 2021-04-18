//
//  Funciton2.cpp
//  csv
//
//  Created by Mai Quý Trung on 31/03/2021.
//

#include "Function1.h"
#include "Funciton2.h"

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

/*
void ReadVietnamese()
{
    _setmode(fileno(stdin), _O_U16TEXT);
    _setmode(fileno(stdout), _O_U16TEXT);
    _setmode(fileno(stdin), _O_WTEXT);
    _setmode(fileno(stdout), _O_WTEXT);
}
*/

//String to char*
char* StringToCharPointer(std::string text){
    char* s;
    s = new char[text.length() + 1];
    for(int i = 0; i < text.length() + 1; i++){
        s[i] = text[i];
    }
    return s;
}

//compare 2 wstring
bool comparei(std::wstring stringA , std::wstring stringB)
{
    transform(stringA.begin(), stringA.end(), stringA.begin(), toupper);
    transform(stringB.begin(), stringB.end(), stringB.begin(), toupper);
    return (stringA == stringB);
}

//Giao diện menu cho system (hiện tại là đăng kí course cho stu, tiện việc khỏi check conflict)
/*
void GotoXY(short x, short y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
 
std::string WriteMenu(std::string str) {
    //don gian la neu khong co gia tri thi tra ve chuoi <empty>
    if (str == "") { return "<empty>"; }
    else { return str; }
}

short Menu(std::string list[], short size, short Xposition, short Yposition) {
    //ham nay ve ra 1 danh sach co the chon 1 vi tri trong danh sach do dua vao mang 1 chieu dua vao, kich co toi da, va vi tri bat dau ve mang
    char book;
    std::cout << GREEN;
    for (short i = 0; i < size; i++)
    {
        GotoXY(Xposition, Yposition + i);
        std::cout << WriteMenu(list[i]);
    }
    GotoXY(Xposition, Yposition);
    std::cout << RED << WriteMenu(list[0]);
    GotoXY(Xposition - 1, Yposition);
    short index = 0;
    while (true)
    {
        book = _getwch();
        book = toupper(book);
        if (book == 'W' || book == KEY_UP) {
            GotoXY(Xposition, Yposition + index);
            std::cout << GREEN << WriteMenu(list[index]);
            if (index == 0) { index = size - 1; }
            else { index--; }
            GotoXY(Xposition, Yposition + index);
            std::cout << RED << WriteMenu(list[index]);
            GotoXY(Xposition - 1, Yposition + index);
        }
        else if (book == 'S' || book == KEY_DOWN) {
            GotoXY(Xposition, Yposition + index);
            std::cout << GREEN << WriteMenu(list[index]);
            if (index == size - 1) { index = 0; }
            else { index++; }
            GotoXY(Xposition, Yposition + index);
            std::cout << RED << WriteMenu(list[index]);
            GotoXY(Xposition - 1, Yposition + index);
        }
        else if (book == KEY_ENTER || book == ' ') { return index; }
        else if (book == KEY_ESC) { return -1; }
    }
}
*/
