
#include "Function.h"

int main()
{
    std::wfstream fin;
    std::wfstream finScore;
    in4_student* t = new in4_student;
    t->pPrev = nullptr;

    score* p = new score;
    p->prev = nullptr;
    fin.open("Student_in4.csv", std::wfstream::in);

    Inputdata(t, fin);
    PrintStu(t);
    OutputData(t);

    finScore.open("Student_sc.csv", std::wfstream::in);
    inputScore(p, finScore);


    DeallocateData(t);
    DeallocateData(p);
    

    return 0;
}

