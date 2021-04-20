#include"func.h"
int convert_num(string& a) {
	char t = a[0];
	int num = 0, i = 0;
	while (t != '\0') {
		if (t < '0' && t>'9') return -1;
		num = num * 10 + t - '0';
		i++;
		t = a[i];
	}
	return num;
}
int wconvert_num(wstring& a) {
	wchar_t t = a[0];
	int num = 0, i = 0;
	while (t != '\0') {
		if (t < L'0' && t>L'9') return -1;
		num = num * 10 + t - L'0';
		i++;
		t = a[i];
	}
	return num;
}
int user_choose_exist(int left, int right) {
	string a;
	getline(cin, a);
	int t = convert_num(a);
	while (t<left || t>right) {
		wcout << L"Chọn lại từ " << left << L" đến " << right << " ";
		getline(cin, a);
		t = convert_num(a);
	}
	return t;
}
void remove_65279(wstring& a) {
	int i = 0;
	while (a[i] == 65279) i++;
	wstring t = a.substr(i);
	a = t;
}