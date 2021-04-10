#include"fun.h"
int main()
{
    const locale utf8_locale
        = locale(locale(), new codecvt_utf8<wchar_t>());
    wstring test;
    wifstream in("cc.csv");
    in.imbue(utf8_locale);//std::locale(in.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
    //in.imbue(utf8_locale);
    input(in, test);
    _setmode(_fileno(stdout), _O_WTEXT);
    /*std::wcout << L"Tiếng Việt có dấu" << std::endl;
    std::wcout << L"Hãy nhập vào một chuỗi ký tự:" << std::endl;tiem
    getline(std::wcin, test);
    std::wcout << L"Chuỗi ký tự mà bạn vừa mới nhập:" << std::endl;
    std::wcout << test << std::endl;*/
    wofstream out("codiem.csv");
    out << wchar_t(239) << wchar_t(187) << wchar_t(191);
    out.imbue(utf8_locale);
    _setmode(_fileno(stdin), _O_U8TEXT);
    out << test;
    //fi.imbue(std::locale(fi.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
    in.close();
    out.close();
    return 0;
}