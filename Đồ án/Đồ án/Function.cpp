﻿#include"Function.h"

int ChangeStringToInt(std::wstring a)
{

    int num = 0;
    for (int i = 0; i < a.length(); i++)
    {
        num = num * 10 + (a[i] - '0');
    }
    return num;
}
void ChangeToVietNamese()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    HANDLE hdlConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX consoleFont;
    consoleFont.cbSize = sizeof(consoleFont);
    GetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
    memcpy(consoleFont.FaceName, L"Consolas", sizeof(consoleFont.FaceName));
    SetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
}
void ReverseTheList(in4_student*& pHead)
{
    in4_student* pCur1 = nullptr;
    in4_student* pCur2 = pHead;
    in4_student* pCur3 = pHead->pPrev;

    while (pCur2 != nullptr)
    {
        pCur2->pPrev = pCur1;
        pCur1 = pCur2;
        pCur2 = pCur3;
        if (pCur3 != nullptr)
        {
            pCur3 = pCur3->pPrev;
        }
    }
    pHead = pCur1;
}
void ReverseTheList(score*& pHead)
{
    score* pCur1 = nullptr;
    score* pCur2 = pHead;
    score* pCur3 = pHead->prev;

    while (pCur2 != nullptr)
    {
        pCur2->prev = pCur1;
        pCur1 = pCur2;
        pCur2 = pCur3;
        if (pCur3 != nullptr)
        {
            pCur3 = pCur3->prev;
        }
    }
    pHead = pCur1;
}

in4_student* Inputdata(in4_student*& t, std::wfstream &fin)
{
    
    if (!fin)
    {
        std::cout << "Can't open !\n";
        t = nullptr;
        return t;
    }
    fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8_utf16<wchar_t>));
    std::wstring temp;
    while (!fin.eof())
    {
        ChangeToVietNamese();
        std::getline(fin, temp);
        if (temp.length() != 0) add_student(t,ChangeToData(temp));
    }
    return t;
}        
void add_student(in4_student*& stu, in4_student temp)
{
    stu->id = temp.id;
    stu->fname = temp.fname;
    stu->lname = temp.lname;
    stu->gender = temp.gender;
    stu->soid = temp.soid;
    stu->dob = temp.dob;
    stu->pNext = new in4_student;
    stu->pNext->pPrev = stu;
    stu = stu->pNext;
}
in4_student ChangeToData(std::wstring line)
{ 
    // id - fname - lname - gender - dob - soid
   
    in4_student stu;
    
    int start = line.find(L',', 0) + 1;
    int end = line.find(L',', start);
    
    wchar_t* temp = new wchar_t[end - start + 1];
    temp[end - start] = L'\0';
    line.copy(temp, end - start, start);
    stu.id = ChangeStringToInt(temp);
    delete[] temp;

    start = end + 1;
    end = line.find(L',', start);
    stu.fname = new wchar_t[end - start + 1];
    stu.fname[end - start] = L'\0';
    line.copy(stu.fname, end - start, start);


    start = end + 1;
    end = line.find(L',', start);
    stu.lname = new wchar_t[end - start + 1];
    stu.lname[end - start] = L'\0';
    line.copy(stu.lname,end -start,start);


    start = end + 1;
    end = line.find(L',', start);
    stu.gender = new wchar_t[end - start + 1];
    stu.gender[end - start] = L'\0';
    line.copy(stu.gender, end - start, start);

    start = end + 1;
    end = line.find(L',', start);
    stu.dob = new wchar_t[end - start + 1];
    stu.dob[end - start] = L'\0';
    line.copy(stu.dob, end - start, start);

    start = end + 1;
    end = line.length();
    temp = new wchar_t[end - start + 1];
    temp[end - start] = L'\0';
    stu.soid = ChangeStringToInt(temp);
    delete[] temp;
    return stu;
}
void PrintStu(in4_student*& data)
{
    ChangeToVietNamese();
    if (data == nullptr)
    {
        return;
    }
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::wfstream fout;
    fout.open("output.csv", std::wfstream::out);
    fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8_utf16<wchar_t>));
    fout << wchar_t(0xfeff);

    in4_student* temp = data;
    data = data->pPrev;
    delete temp;
    ReverseTheList(data);
    in4_student* cur = data;
    while (cur != nullptr)
    {
        std::wcout << cur->id;
        std::wcout << "  "  << cur->fname;
        std::wcout << std::setw(27 - wcslen(cur->fname)) << cur->lname;
        std::wcout << std::setw(8) << cur->gender;
        std::wcout << "   " << cur->dob;
        std::wcout << std::setw(8) << cur->soid << "\n";

        fout << cur->id << L',' << cur->fname << L',' << cur->lname << L',' << cur->gender << L',' << cur->dob << L',' << cur->soid << "\n";

        cur = cur->pPrev;
    }

    fout.close();
    _setmode(_fileno(stdin), _O_TEXT);
    _setmode(_fileno(stdout), _O_TEXT);
}
void DeallocateData(in4_student*& infor)
{
    in4_student* temp = infor;
    while (infor != nullptr)
    {
        infor = infor->pPrev;
        delete temp;
        temp = infor;
    }
}

void DeallocateData(score*& infor)
{
    score* temp = infor;
    while (infor != nullptr)
    {
        infor = infor->prev;
        delete temp;
        temp = infor;
    }
}

void add_score(score*& sc, score temp)
{
    sc->Id = temp.Id;
    sc->fname = temp.fname;
    sc->lname = temp.lname;
    sc->totalScore = temp.totalScore;
    sc->final = temp.final;
    sc->midterm = temp.midterm;
    sc->other = temp.other;
    sc->GPA = temp.GPA;
    sc->ovrGPA = temp.ovrGPA;
    sc->next = new score;
    sc->next->prev = sc;
    sc = sc->next;
}
score ChangeScoreToData(std::wstring line)
{
    score sc;

    // Id - Ho & Ten Dem - Ten - dem1 - dem 2 - dem3- dem 4 - dem5

    int start = line.find(L',', 0) + 1;
    int end = line.find(L',', start);

    sc.Id = new wchar_t[end - start + 1];
    sc.Id[end - start] = L'\0';
    line.copy(sc.Id, end - start, start);

    start = end + 1;
    end = line.find(L',', start);
    sc.fname = new wchar_t[end - start + 1];
    sc.fname[end - start] = L'\0';
    line.copy(sc.fname, end - start, start);

    start = end + 1;
    end = line.find(L',', start);
    sc.lname = new wchar_t[end - start + 1];
    sc.lname[end - start] = L'\0';
    line.copy(sc.lname, end - start, start);

    start = end + 1;
    end = line.find(L',', start);
    sc.totalScore = new wchar_t[end - start + 1];
    sc.totalScore[end - start] = L'\0';
    line.copy(sc.totalScore, end - start, start);

    start = end + 1;
    end = line.find(L',', start);
    sc.final = new wchar_t[end - start + 1];
    sc.final[end - start] = L'\0';
    line.copy(sc.final, end - start, start);

    start = end + 1;
    end = line.find(L',', start);
    sc.midterm = new wchar_t[end - start + 1];
    sc.midterm[end - start] = L'\0';
    line.copy(sc.midterm, end - start, start);

    start = end + 1;
    end = line.find(L',', start);
    sc.other = new wchar_t[end - start + 1];
    sc.other[end - start] = L'\0';
    line.copy(sc.other, end - start, start);

    start = end + 1;
    end = line.find(L',', start);
    sc.GPA = new wchar_t[end - start + 1];
    sc.GPA[end - start] = L'\0';
    line.copy(sc.GPA, end - start, start);

    start = end + 1;
    end = line.length();
    sc.ovrGPA = new wchar_t[end - start + 1];
    sc.ovrGPA[end - start] = L'\0';
    line.copy(sc.ovrGPA, end - start, start);

    return sc;
}
score* inputScore(score*& t, std::wfstream& finScore)
{
    
    if (!finScore)
    {
        std::cout << "Can't open !\n";
        return t;
    }

    finScore.imbue(std::locale(finScore.getloc(), new std::codecvt_utf8_utf16<wchar_t>));
    std::wstring temp;
    while (finScore)
    {
        ChangeToVietNamese();
        std::getline(finScore, temp);
        if (temp.length() != 0) add_score(t, ChangeScoreToData(temp));
    }
    return t;
}
 void OutputScore(score*& sc)
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::wfstream fout;
    fout.open("outputScore.csv", std::wfstream::out);
    fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8_utf16<wchar_t>));
    fout << wchar_t(0xfeff);

    score* temp = sc;
    sc = sc->prev;
    delete temp;
    ReverseTheList(sc);
    score* cur = sc;
    while (cur != nullptr)
    {
        std::wcout << cur->Id << "    " << cur->fname << "     " << cur->lname << "    " << cur->totalScore << "    " << cur->final << "    " << cur->midterm << " " << cur->other << "    "<< cur->GPA << "    " << cur->ovrGPA << "\n";
        fout << cur->Id << L',' << cur->fname << L',' << cur->lname << L',' << cur->totalScore << L',' << cur->final << L',' << cur->midterm << L',' << cur->other << L',' << cur->GPA << L',' << cur->ovrGPA << "\n";

        cur = cur->prev;
    }

    fout.close();
    _setmode(_fileno(stdin), _O_TEXT);
    _setmode(_fileno(stdout), _O_TEXT);
}


 void makeBigfolder()
 {
     wchar_t* name = new wchar_t[] {L"Data"};
     _wmkdir(name);
     delete[] name;

     _wmkdir(L"C:\\Users\\Asus\\Desktop\\Đồ án\\Đồ án\\Data\\2021");
     _wmkdir(L"C:\\Users\\Asus\\Desktop\\Đồ án\\Đồ án\\Data\\2021\\Student");
     _wmkdir(L"C:\\Users\\Asus\\Desktop\\Đồ án\\Đồ án\\Data\\2021\\Sem 1");
     _wmkdir(L"C:\\Users\\Asus\\Desktop\\Đồ án\\Đồ án\\Data\\2021\\Sem 2");
     _wmkdir(L"C:\\Users\\Asus\\Desktop\\Đồ án\\Đồ án\\Data\\2021\\Sem 3");
     _wmkdir(L"C:\\Users\\Asus\\Desktop\\Đồ án\\Đồ án\\Data\\2021\\Sem 1\\Course");
     _wmkdir(L"C:\\Users\\Asus\\Desktop\\Đồ án\\Đồ án\\Data\\2021\\Sem 1\\Score");

 }

 void makeAccess(std::wfstream& fin)
 {
     std::string choose;

     std::cout << "Pls enter the year you want to access: ";
     std::cin >> choose;

     if (choose == "2021")
     {
         std::cout << "Pls enter your choose:\n1. Sem 1 - press 1\n2. Sem 2 - press 2\n3. Sem 3 - press 3\n4. Student - press 4\n";
         int num;
         std::cin >> num;
         if (num == 1)
         {
             fin.open(L"C:\\Users\\Asus\\Desktop\\Đồ án\\Đồ án\\Data\\2021\\Sem 1\\Score\\score1.csv", std::wfstream::in);
         }
         if (num == 2)
         {
             // như trên :>
         }
         if (num == 3)
         {
             // như trên nốt
         }
         if (num == 4)
         {
             fin.open(L"C:\\Users\\Asus\\Desktop\\Đồ án\\Đồ án\\Data\\2021\\Student\\20CLC11.csv", std::wfstream::in);
         }
     }
 }
 
 // hoang task
 void taskMakeFolderAsscess(std::wfstream& fin)
 {
     std::cout << "1. to system - press 1\n2. to input file - press 2\n3. to output file";
     int choose;
     std::cin >> choose;
     if (choose == 1)
     {
         fin.open(L"D:\\course_app\\system file");
     }
     if (choose == 2)
     {
         fin.open(L"D:\\course_app\\input file");

     }
     if (choose == 3)
     {
         fin.open(L"D:\\course_app\\output file");
     }
 }

 