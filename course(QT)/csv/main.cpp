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

/*std::string list[3] = { "Student", "Staff", "Exit" };
    short size = 3;
    short x = 1;
    short y = 3;
    Menu(list, size, x, y);*/

int main() {
    /*id_class* pHead = nullptr;
    AddClass(pHead);
    OutputClassFile("/Users/quytrunggg/Desktop/class.txt", pHead);
    system("clear");
    ChooseClass(pHead);
    getchar();*/
    /*account* pHead = nullptr;
    int option;
    load_account("staff_account.txt", pHead);
    std::cout << "1. Change password\n" << "0. Exit\n";
    std::cout << "Choose your option: ";
    std::cin >> option;
    while(option == 1){
        switch (option) {
            case 1:{
                system("cls");
                std::cout << "Enter your username: ";
                ChangePassword(pHead);
                SaveAccount("staff_account.txt", pHead);
                break;
            }
            default:
                break;
        }
        std::cout << "Choose your option: ";
        std::cin >> option;
    }
    PrintAccount(pHead);
    DeallocateAccount(pHead);*/
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);

    {
        char* a = new char[1];
        *a = 'b';
    }

    if (_CrtDumpMemoryLeaks())
    {
        std::cout << "Leak";
    }
    else std::cout << "No";
}
