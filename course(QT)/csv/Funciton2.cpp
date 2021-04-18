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
