#include<iostream>
#include<fstream>
#include<io.h>
#include<fcntl.h>
#include <locale>
#include <codecvt>
#include<string>
using namespace std;
int main() {
	//_setmode(_fileno(stdout), _O_WTEXT);
	wstring s = L"aha";
	string t = "123";
	string wsTmp(s.begin(), s.end());

	t = t + wsTmp;
	cout << t;
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