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
	int n;
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
	if (a.date.Day <= 0 || a.date.Day > months[a.date.Month]) return false;
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
bool create_3_semester() {
	//điều kiện để sau
	ofstream out;
	out.open(path_date_semester);
	string t;
	LocalTime* date = new LocalTime[6];
	for (int i = 1; i <= 3; i++) {
		wcout << L"Nhập ngày bắt đầu học kì " << i << L": ";
		cin >> date[i - 1].date.Day;
		wcout << L"Nhập tháng bắt đầu học kì " << i << L": ";
		cin >> date[i - 1].date.Month;
		wcout << L"Nhập năm bắt đầu học kì " << i << L": ";
		cin >> date[i - 1].date.Year;
		while (checkDayIsTrue(date[i - 1]) == 0) {
			wcout << L"Ngày không tồn tại, chọn 1 để tiếp tục, chọn 2 để dừng ";
			cin.ignore(1000, '\n');
			int choose = user_choose_exist(1, 2);
			if (choose == 2) {
				delete[]date;
				return 0;
			}
			else {
				wcout << L"Nhập ngày bắt đầu học kì " << i << L": ";
				cin >> date[i - 1].date.Day;
				wcout << L"Nhập tháng bắt đầu học kì " << i << L": ";
				cin >> date[i - 1].date.Month;
				wcout << L"Nhập năm bắt đầu học kì " << i << L": ";
				cin >> date[i - 1].date.Year;
			}
		}
		out << date[i - 1].date.Day << " " << date[i - 1].date.Month << " " << date[i - 1].date.Year << endl;
		wcout << L"Nhập ngày kết thúc học kì " << i << L": ";
		cin >> date[i + 2].date.Day;
		wcout << L"Nhập tháng kết thúc học kì " << i << L": ";
		cin >> date[i + 2].date.Month;
		wcout << L"Nhập năm kết thúc học kì " << i << L": ";
		cin >> date[i + 2].date.Year;
		while (checkDayIsTrue(date[i + 2]) == 0) {
			wcout << L"Ngày không tồn tại, chọn 1 để tiếp tục, chọn 2 để dừng ";
			cin.ignore(1000, '\n');
			int choose = user_choose_exist(1, 2);
			if (choose == 2) {
				delete[]date;
				return 0;
			}
			else {
				wcout << L"Nhập ngày kết thúc học kì " << i << L": ";
				cin >> date[i + 2].date.Day;
				wcout << L"Nhập tháng kết thúc học kì " << i << L": ";
				cin >> date[i + 2].date.Month;
				wcout << L"Nhập năm kết thúc học kì " << i << L": ";
				cin >> date[i + 2].date.Year;
			}
		}
		out << date[i + 2].date.Day << " " << date[i + 2].date.Month << " " << date[i + 2].date.Year << endl;
	}
	cin.ignore(1000, '\n');
	delete[]date;
	out.close();
	return 1;
}