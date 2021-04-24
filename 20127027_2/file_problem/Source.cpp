#include<iostream>
#include<fstream>
#include<io.h>
#include<fcntl.h>
#include <locale>
#include <codecvt>
#include<string>
using namespace std;
int main() {
	const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());
	wofstream wfout;
	wfout.open("inpp2.csv");
	wfout << wchar_t(239) << wchar_t(187) << wchar_t(191);
	//65279
	//wfout.imbue(utf8_locale);
	wfout.close();
	wifstream in("inpp2.csv");
	in.imbue(utf8_locale);
	wstring s;
	getline(in, s);
	cout << int(s[0]);
	//wfout.imbue(utf8_locale);
	//_setmode(_fileno(stdout), _O_WTEXT);
	/*wstring s = L"aha";
	string t = "123";
	string wsTmp(s.begin(), s.end());

	t = t + wsTmp;
	cout << t;*/
	/*const locale utf8_locale
		= locale(locale(), new codecvt_utf8<wchar_t>());
	wofstream out("input.txt");
	out.imbue(utf8_locale);
	out << L"Nguyễn Thanh Hoàng";
	out.close();
	wifstream in("input.txt");
	in.imbue(utf8_locale);
	wstring a;
	getline(in, a);
	wcout << a;*/
	return 0;
}