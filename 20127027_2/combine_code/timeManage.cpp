#include"func.h"
bool compare2Times(LocalTime& a, LocalTime& b) {//true khi b>a
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
			if (a.date.Day >= b.date.Day) return false;
		}
	}
	return true;
}
bool checkYear(int year)
{
	if (year % 400 == 0)
		return true;

	if (year % 4 == 0 && year % 100 != 0)
		return true;

	return false;
}

bool checkDayIsTrue(LocalTime& a) {
	if (a.date.Year < 0) return false;
	if (a.date.Month <= 0 || a.date.Month > 12)	return false;
	if (a.date.Day <= 0) return false;
	int* months = new int[13];
	for (int i = 0; i < 13; i++) months[i] = 30;
	months[1] = months[3] = months[5] = months[7] = months[8] = months[10] = months[12] = 31;
	if (checkYear(a.date.Year)) {
		months[2] = 29;
	}
	else months[2] = 28;
	if (a.date.Day <= 0 || a.date.Day > months[a.date.Month]) {
		delete[]months; return false;
	}
	delete[]months;
	return true;
}
LocalTime currentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	localtime_s(&tstruct, &now);
	strftime(buf, sizeof(buf), "%Y/%m/%d", &tstruct);
	stringstream time_in(buf);
	LocalTime a;
	string astr;
	getline(time_in, astr, '/');
	a.date.Year = convert_num(astr);
	getline(time_in, astr, '/');
	a.date.Month = convert_num(astr);
	getline(time_in, astr, '/');
	a.date.Day = convert_num(astr);
	return a;
}
