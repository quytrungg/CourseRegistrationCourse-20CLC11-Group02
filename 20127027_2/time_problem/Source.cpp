#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include "Struct.h"
#include <string.h>
#include <stdlib.h>

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
string currentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	localtime_s(&tstruct,&now);
	strftime(buf, sizeof(buf), "%Y/%m/%d", &tstruct);
	return buf;
}
int main()
{
	string t = currentDateTime();
	cout << t;
	return 0;
}

//// Change time from string to int
//int convertchartoint(char* a, int n) {
//	int m = 0;
//	int p;
//	for (int i = 0; i < n; i++) {
//		p = a[i] - l'0';
//		m = m * 10 + p;
//	}
//	return m;
//}
//
//void getcurrenttimetoint(localtime& b) {
//	std::string str = currentdatetime();
//	int begin = 0;
//	int end = str.find("-", begin + 1);
//	char* a = new char[end - begin + 1];
//	str.copy(a, end - begin, begin);
//	b.date.year = convertchartoint(a, end - begin);
//	delete[] a;
//
//	begin = end + 1;
//	end = str.find("-", begin + 1);
//	str.copy(a, end - begin, begin);
//	b.date.month = convertchartoint(a, end - begin);
//	delete[] a;
//
//	begin = end + 1;
//	end = str.find(".", begin + 1);
//	str.copy(a, end - begin, begin);
//	b.date.day = convertchartoint(a, end - begin);
//	delete[] a;
//
//	begin = end + 1;
//	end = str.find(":", begin + 1);
//	char* a = new char[end - begin + 1];
//	str.copy(a, end - begin, begin);
//	b.time.hours = convertchartoint(a, end - begin);
//	delete[] a;
//
//	begin = end + 1;
//	end = str.find(":", begin + 1);
//	str.copy(a, end - begin, begin);
//	b.time.minutes = convertchartoint(a, end - begin);
//	delete[] a;
//
//	begin = end + 1;
//	end = str.length();
//	str.copy(a, end - begin, begin);
//	b.time.seconds = convertchartoint(a, end - begin);
//	delete[] a;
//}
//
//// compare 2 times
//bool compare2times(localtime& a, localtime& b) {
//	if (a.date.year > b.date.year)
//	{
//		return false;
//	}
//	if (a.date.year == b.date.year)
//	{
//		if (a.date.month > b.date.month)
//		{
//			return false;
//		}
//		if (a.date.month == b.date.month)
//		{
//			if (a.date.day > b.date.day)
//			{
//				return false;
//			}
//			if (a.date.day == b.date.day)
//			{
//				if (a.time.hours > b.time.hours)
//				{
//					return false;
//				}
//				if (a.time.hours == b.time.hours)
//				{
//					if (a.time.minutes > b.time.hours)
//					{
//						return false;
//					}
//					if (a.time.minutes == b.time.minutes)
//					{
//						if (a.time.seconds > b.time.seconds)
//						{
//							return false;
//						}
//					}
//				}
//			}
//		}
//	}
//	return true;
//}
//
//// check this day is true
//bool checkyear(int year)
//{
//	if (year % 400 == 0)
//		return true;
//
//	if (year % 4 == 0 && year % 100 != 0)
//		return true;
//
//	return false;
//}
//
//bool checkdayistrue(localtime& a) {
//	int months[12] = { 31,0,31,30,31,30,31,31,30,31,30,31 };
//	int n;
//	if (a.date.year < 0) return false;
//	if (a.date.month < 0 || a.date.month > 12)	return false;
//	if (a.date.day < 0) return false;
//	if (a.date.month == 2) {
//		if (checkyear(a.date.year)) {
//			n = 29;
//		}
//		else n = 28;
//		if (a.date.day < 0 || a.date.day > n)	return false;
//	}
//	else if (a.date.day < 0 || a.date.day > months[a.date.month]) return false;
//	if (a.time.hours < 0 || a.time.hours > 24)	return false;
//	if (a.time.minutes < 0 || a.time.minutes > 60)	return false;
//	if (a.time.seconds < 0 || a.time.seconds > 60)	return false;
//}