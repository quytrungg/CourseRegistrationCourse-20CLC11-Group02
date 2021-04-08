
#include "Function.h"

int main()
{
    ChangeToVietNamese();
    NodeStu* t;
    std::wfstream fin;
    fin.open("DATA.csv", std::wfstream::in);

    Inputdata(t, fin);

    NodeStu* cur = t;

    while (cur != nullptr)
    {
        std::wcout << t->infor.ID;
        std::wcout << std::setw(9) << t->infor.name;
        std::wcout << std::setw(7) << t->infor.lastname;
        std::wcout << std::setw(4) << t->infor.gender;
        std::wcout << "  " << t->infor.date << "\n";
        cur = cur->next;
    }

    DeallocateData(t);

    fin.close();
    return 0;
}

