#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include "Struct.h"
#include <string.h>
#include <stdlib.h>

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

void tm(LocalTime dstime[]) {
    std::string a = currentDateTime();
    std::cout << a << std::endl;
    a.copy(local.date.Year, 4, 0);
    local.date.Year[4] = '\0';
    a.copy(local.date.Month, 2, 5);
    local.date.Month[2] = '\0';
    a.copy(local.date.Day, 2, 8);
    local.date.Day[2] = '\0';
}

int main() {
    LocalTime dstime[50];
    tm(dstime);
    std::cout << local.date.Year;
    getchar();  // wait for keyboard input
}