#include <string>
#include <iostream>
#include "Struct.h"

std::wstring trim(const std::wstring& str,
    const std::wstring& whitespace = L" \t")
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return L""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

std::wstring reduce(const std::wstring& str,
    const std::wstring& fill = L" ",
    const std::wstring& whitespace = L" \t")
{
    // trim first
    auto result = trim(str, whitespace);

    // replace sub ranges
    auto beginSpace = result.find_first_of(whitespace);
    while (beginSpace != std::string::npos)
    {
        const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
        const auto range = endSpace - beginSpace;

        result.replace(beginSpace, range, fill);

        const auto newStart = beginSpace + fill.length();
        beginSpace = result.find_first_of(whitespace, newStart);
    }

    return result;
}

void uppercaseTheWstring(std::wstring& a) {
    transform(
        a.begin(), a.end(),
        a.begin(),
        toupper);
}

void main() {
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::wstring str = L"Đặng Nguyễn Duy";
    std::wcout << str << std::endl;
    uppercaseTheWstring(str);
    std::wcout << str << std::endl;
}