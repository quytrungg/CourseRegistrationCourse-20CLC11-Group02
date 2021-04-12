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
