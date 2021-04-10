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
