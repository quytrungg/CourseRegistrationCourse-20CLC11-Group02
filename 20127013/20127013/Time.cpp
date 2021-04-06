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

// Change time from string to int
int Convertchartoint(char* a, int n) {
	int m = 0;
	int p;
	for (int i = 0; i < n; i++) {
		p = a[i] - L'0';
		m = m * 10 + p;
	}
	return m;
}

void Getcurrenttimetoint(LocalTime &b) {
	std::string str = currentDateTime();
	int begin = 0;
	int end = str.find("-", begin + 1);
	char* a = new char[end - begin + 1];
	str.copy(a, end - begin, begin);
	b.date.Year = Convertchartoint(a, end - begin);
	delete[] a;

	begin = end + 1;
	end = str.find("-", begin + 1);
	char* a = new char[end - begin + 1];
	str.copy(a, end - begin, begin);
	b.date.Month = Convertchartoint(a, end - begin);
	delete[] a;

	begin = end + 1;
	end = str.find(".", begin + 1);
	char* a = new char[end - begin + 1];
	str.copy(a, end - begin, begin);
	b.date.Day = Convertchartoint(a, end - begin);
	delete[] a;

	begin = end + 1;
	end = str.find(":", begin + 1);
	char* a = new char[end - begin + 1];
	str.copy(a, end - begin, begin);
	b.time.Hours = Convertchartoint(a, end - begin);
	delete[] a;

	begin = end + 1;
	end = str.find(":", begin + 1);
	char* a = new char[end - begin + 1];
	str.copy(a, end - begin, begin);
	b.time.Minutes = Convertchartoint(a, end - begin);
	delete[] a;

	begin = end + 1;
	end = str.length();
	char* a = new char[end - begin + 1];
	str.copy(a, end - begin, begin);
	b.time.Seconds = Convertchartoint(a, end - begin);
	delete[] a;
}

// Compare 2 times
bool Compare2times(LocalTime &a, LocalTime&b) {
	if (a.date.Year > b.date.Year)
	{
		return false;
	}
	if (a.date.Year == b.date.Year)
	{
		if (a.date.Month > b.date.Month)
		{
			return false;
		}
		if (a.date.Month == b.date.Month)
		{
			if (a.date.Day > b.date.Day)
			{
				return false;
			}
			if (a.date.Day == b.date.Day) 
			{
				if (a.time.Hours > b.time.Hours) 
				{
					return false;
				}
				if (a.time.Hours == b.time.Hours)
				{
					if (a.time.Minutes > b.time.Hours)
					{
						return false;
					}
					if (a.time.Minutes == b.time.Minutes)
					{
						if (a.time.Seconds > b.time.Seconds)
						{
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}

// Check this day is true
bool checkYear(int year)
{
	if (year % 400 == 0)
		return true;

	if (year % 4 == 0 && year % 100 != 0)
		return true;

	return false;
}

bool Checkdayistrue(LocalTime& a) {
	int months[12] = { 31,0,31,30,31,30,31,31,30,31,30,31 };
	int n;
	if (a.date.Year < 0) return false;
	if (a.date.Month < 0 || a.date.Month > 12)	return false;
	if (a.date.Day < 0) return false;
	if (a.date.Month == 2) {
		if (checkYear(a.date.Year)) {
			n = 29;
		}
		else n = 28;
		if (a.date.Day < 0 || a.date.Day > n)	return false;
	}
	else if (a.date.Day < 0 || a.date.Day > months[a.date.Month]) return false;
	if (a.time.Hours < 0 || a.time.Hours > 24)	return false;
	if (a.time.Minutes < 0 || a.time.Minutes > 60)	return false;
	if (a.time.Seconds < 0 || a.time.Seconds > 60)	return false;
}
