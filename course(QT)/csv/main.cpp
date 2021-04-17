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
    //id_class* pHead = nullptr;
    //AddClass(pHead);
    //OutputClassFile("/Users/quytrunggg/Desktop/class.txt", pHead);
    //system("clear");
    //MenuClassList(pHead);
    //getchar();
    account* pHead = nullptr;
    int option;
    load_account("/Users/quytrunggg/Desktop/staff_account.txt", pHead);
    std::cout << "1. Change password\n" << "0. Exit\n";
    std::cout << "Choose your option: ";
    std::cin >> option;
    while(option == 1){
        switch (option) {
            case 1:{
                std::cout << "Enter your username: ";
                ChangePassword(pHead);
                SaveAccout("/Users/quytrunggg/Desktop/staff_account.txt", pHead);
                break;
            }
            default:
                break;
        }
        std::cout << "Choose your option: ";
        std::cin >> option;
    }
    PrintAccount(pHead);
    DeallocateAccount(pHead);
}
