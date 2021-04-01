#include "Header.h"
#include "ExtraHeader.h"

void ReadVietnamese()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    SetConsoleTitleW(L"Việt Nam Vô Địch!");
    HANDLE hdlConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX consoleFont;
    consoleFont.cbSize = sizeof(consoleFont);
    GetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
    memcpy(consoleFont.FaceName, L"Consolas", sizeof(consoleFont.FaceName));
    SetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
    std::wcout << L"Tiếng Việt có dấu" << std::endl;
    std::wstring test;
    std::wcout << L"Hãy nhập vào một chuỗi ký tự:" << std::endl;
    std::getline(std::wcin, test);
    std::wcout << L"Chuỗi ký tự mà bạn vừa mới nhập:" << std::endl;
    std::wcout << test << std::endl;
}

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

