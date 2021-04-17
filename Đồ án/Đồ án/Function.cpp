#include"Function.h"
#include "SmallFunction.cpp"

int ChangeStringToInt(std::wstring a)
{

    int num = 0;
    for (int i = 0; i < a.length(); i++)
    {
        num = num * 10 + a[i] - '0';
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

void OutputData(in4_student*&stu)
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::wfstream fout;
    fout.open("output.csv", std::wfstream::out);
    fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8_utf16<wchar_t>));
    fout << wchar_t(0xfeff);
    in4_student* temp = stu;
    stu = stu->pPrev;
    delete temp;
    in4_student* cur = stu->pPrev;
    if (cur == nullptr)
    {
        std::wcout << "Null";
        return;
    }
    do
    {
        fout << cur->id << L',' << cur->fname << L',' << cur->lname << L',' << cur->gender << L',' << cur->dob << L',' << cur->soid << "\n";
        cur = cur->pPrev;
    }while (cur != nullptr);


    fout.close();
    _setmode(_fileno(stdin),  _O_TEXT);
    _setmode(_fileno(stdout), _O_TEXT);
}

in4_student* Inputdata(in4_student*& t, std::wfstream &fin)
{
    
    if (!fin) std::cout << "Can't open !";
    fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8_utf16<wchar_t>));
    std::wstring temp;
    while (fin)
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

    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::wfstream fout;
    fout.open("output.csv", std::wfstream::out);
    fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8_utf16<wchar_t>));
    fout << wchar_t(0xfeff);

    in4_student* temp = data;
    data = data->pPrev;
    delete temp;
    in4_student* cur = data;
    while (cur != nullptr)
    {

        std::wcout << cur->id;
        std::wcout << " "  << cur->fname;
        std::wcout << std::setw(10) << cur->lname;
        std::wcout << std::setw(10) << cur->gender;
        std::wcout << "  " << cur->dob;
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
    sc->no = temp.no;
    sc->fname = temp.fname;
    sc->lname = temp.lname;
    sc->totalScore = temp.totalScore;
    sc->final = temp.final;
    sc->midterm = temp.midterm;
    sc->next = new score;
    sc->next->prev = sc;
    sc = sc->next;
}
score ChangeScoreToData(std::wstring line)
{
    score sc;

    int start = line.find(L',', 0) + 1;
    int end = line.find(L',', start);

    wchar_t* temp = new wchar_t[end - start + 1];
    temp[end - start] = L'\0';
    line.copy(temp, end - start, start);

    sc.Id = ChangeStringToInt(temp);
    delete[] temp;

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
    end = line.find(L',', start);
    sc.ovrGPA = new wchar_t[end - start + 1];
    sc.ovrGPA[end - start] = L'\0';
    line.copy(sc.ovrGPA, end - start, start);

    return sc;
}
score* inputScore(score*& t, std::wfstream& finScore)
{
    
    if (!finScore) std::cout << "Can't open !";
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
