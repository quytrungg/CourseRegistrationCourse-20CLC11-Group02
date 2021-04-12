
#include "Function.h"

int main()
{
    std::wfstream fin;
    in4_student* t = new in4_student;
    t->pPrev = nullptr;
    fin.open("Student_in4.csv", std::wfstream::in);

    //std::wstring line;
    //getline(fin, line);
    //std::wcout << line << "\n";    
    //int st = line.find(L',', 0) + 1;
    //int end = line.find(L',', st);
    //std::cout << end - st + 1<< "\n";
    //std::cout << st << "  " << end << "\n";
    //wchar_t* temp = new wchar_t[end - st + 1];
    //temp[end - st] = L'\0';
    //line.copy(temp, end - st, st);
    //std::wcout << temp << "\n";
    //delete[] temp;
    //st = end + 1;
    //end = line.find(L',', st);
    //temp = new wchar_t[end - st + 1];
    //temp[end - st] = L'\0';
    //line.copy(temp, end - st, st);
    //_setmode(_fileno(stdin), _O_U16TEXT);
    //_setmode(_fileno(stdout), _O_U16TEXT);
    //std::wcout << temp << "\n";
    //std::wcout << end - st << "\n";
    //std::wcout << st << "  " << end << "\n";
    //delete[] temp;
    //st = end + 1;
    //end = line.find(L',', st);
    //temp = new wchar_t[end - st + 1];;
    //temp[end - st] = L'\0';
    //line.copy(temp, end - st, st);
    //std::wcout << temp << "\n";
    //std::wcout << end - st << "\n";
    //std::wcout << st << "  " << end << "\n";
    //delete[] temp;
    //st = end + 1;
    //end = line.find(L',', st);
    //line.copy(temp, end - st, st);
    //std::wcout << temp << "\n";
    //std::wcout << end - st << "\n";
    //std::wcout << st << "  " << end << "\n";
    //delete[] temp;
    //st = end + 1;
    //end = line.find(L',', st);
    //line.copy(temp, end - st, st);
    //std::wcout << temp << "\n";
    //std::wcout << end - st << "\n";
    //std::wcout << st << "  " << end << "\n";
    //delete[] temp;

    Inputdata(t, fin);
    PrintStu(t);
    DeallocateData(t);
    OutputData(t);

    return 0;
}

