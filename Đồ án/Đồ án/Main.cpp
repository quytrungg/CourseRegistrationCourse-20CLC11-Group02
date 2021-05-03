
#include "Function.h"

int main()
{
    std::wfstream fin;
    //std::wfstream finScore;
    in4_student* t = new in4_student;
    t->pPrev = nullptr;

    //score* p = new score;
    //p->prev = nullptr;

    makeAccess(fin);
    //fin.open("20CLC11.csv", std::wfstream::in);

    Inputdata(t, fin);
    PrintStu(t);

    /*finScore.open("Score1.csv", std::wfstream::in);
    inputScore(p, finScore);
    OutputScore(p);*/

    DeallocateData(t);
    //DeallocateData(p);
    
    makeBigfolder();

    return 0;
}

