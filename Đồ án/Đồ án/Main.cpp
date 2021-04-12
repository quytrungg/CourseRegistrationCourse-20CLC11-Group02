
#include "Function.h"

int main()
{
    std::wfstream fin;
    in4_student* t = new in4_student;
    t->pPrev = nullptr;
    fin.open("Student_in4.csv", std::wfstream::in);

    Inputdata(t, fin);
    PrintStu(t);
    //OutputData(t);
    DeallocateData(t);
    

    return 0;
}

