//
//  main.cpp
//  csv
//
//  Created by Mai Quý Trung on 31/03/2021.
//

#include "Function1.h"
#include "Funciton2.h"

/*
    id_class a;
    a.id = "20clc11";
    std::cout << GetClassYear(a);
    std::cout << currentDateTime();
*/

int main() {
    id_class* pHead = nullptr;
    AddClass(pHead);
    OutputClassFile("/Users/quytrunggg/Desktop/class.txt", pHead);
    system("clear");
    MenuClassList(pHead);
    getchar();
}
