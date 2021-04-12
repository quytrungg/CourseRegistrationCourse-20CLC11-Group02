#include "Header.h"
#include "ExtraHeader.h"

/*
 system("cls");
 ReadVietnamese();
 std::wcout << char(239) << std::endl;
 std::wcout << char(187) << std::endl;
 std::wcout << char(191) << std::endl;
 std::wcout << L"Xin chào các bạn" << std::endl;
 */

/*
    id_class a;
    a.id = "20clc11";
    std::cout << GetClassYear(a);
    std::cout << currentDateTime();
*/

int main()
{
    id_class* pHead = nullptr;
    AddClass(pHead);
    OutputClassFile("/Users/quytrunggg/Desktop/class.txt", pHead);
    system("cls");
    MenuClassList(pHead);
    getchar();
    return 0;
}
