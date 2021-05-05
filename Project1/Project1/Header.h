#ifndef HEADER_H_
#define HEADER_H_
struct Date {
	int Day = 0;
	int Month = 0;
	int Year = 0;
};
struct Time {
	int Seconds;
	int Minutes;
	int Hours;
};
struct LocalTime {
	struct Time time;
	struct Date date;
};
#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include <locale>
#include <codecvt> //possible C++11?
#include <fstream>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <direct.h>
#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>
#endif // !HEADER_H_
