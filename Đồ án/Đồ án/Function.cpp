#include"Function.h"

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

void OutputData()
{
    ChangeToVietNamese();
    std::wfstream fout;
    fout.open("dddd.csv", std::wfstream::out);
    fout << wchar_t(239);
    fout << wchar_t(187);
    fout << wchar_t(191);
    fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8_utf16<wchar_t>));
   
    fout.close();
}

void Inputdata(NodeStu*& t, std::wfstream &fin)
{
    t = new NodeStu;
    NodeStu* cur = t;
    std::wstring line;
    t = nullptr;
    if (!fin.is_open())
    {
        std::cout << "Error File Open";
    }
    else
    {
        fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8_utf16<wchar_t>));
        while (!fin.eof())
        {
            getline(fin, line);
            cur->next = new NodeStu;
            cur->next->pre = cur;
            fin.ignore();
            ChangeToData(line, cur->next);
            cur = cur->next;
            cur->next = nullptr;
        }
        if (t == nullptr)
        {
            delete t;
            t = nullptr;
        }
        else
        {
            NodeStu* temp = t;
            t = t->next;
            delete temp;
            t->pre = nullptr;
        }
    }
}        

void ChangeToData(std::wstring line, NodeStu*& t)
{
    wchar_t* temp;
    int st = line.find(L',', 0) + 1;
    int end = line.find(L',', st + 1);

    temp = new wchar_t[end - st + 1];

    temp[end - st] = L'\0';
    line.copy(temp, end - st, st);
    t->infor.ID = temp;
    delete[] temp;

    st = end + 1;
    end = line.find(L',', st);
    temp = new wchar_t[end - st + 1];
    temp[end - st] = L'\0';
    line.copy(temp, end - st, st);
    t->infor.name = temp;
    delete[] temp;

    st = end + 1;
    end = line.find(L',', st);
    temp = new wchar_t[end - st + 1];
    temp[end - st] = L'\0';
    line.copy(temp, end - st, st);
    t->infor.lastname = temp;
    delete[] temp;

    st = end + 1;
    end = line.find(L',', st);
    temp = new wchar_t[end - st + 1];
    temp[end - st] = L'\0';
    line.copy(temp, end - st, st);
    t->infor.gender = temp;
    delete[] temp;

    st = end + 1;
    end = line.find(L',', st);
    temp = new wchar_t[end - st + 1];
    temp[end - st] = L'\0';
    line.copy(temp, end - st, st);
    t->infor.date = temp;

    t->next = nullptr;
    delete[] temp;
}

void PrintStu(NodeStu*& data)
{
    NodeStu* cur = data;
    while (cur != nullptr)
    {
        std::wcout << data->infor.ID;
        std::wcout << std::setw(9) << data->infor.name;
        std::wcout << std::setw(7) << data->infor.lastname;
        std::wcout << std::setw(4) << data->infor.gender;
        std::wcout << "  " << data->infor.date << "\n";
        cur = cur->next;
    }
}

void DeallocateData(NodeStu* infor)
{
    NodeStu* temp = infor;
    while (infor != nullptr)
    {
        infor = infor->next;
        delete temp;
        temp = infor;
    }
}