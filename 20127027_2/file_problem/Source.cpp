#include<iostream>
#include<fstream>
#include<io.h>
#include<fcntl.h>
#include <locale>
#include <codecvt>
#include<string>
#include<sstream>
using namespace std;
int main() {
	
	//wfout.imbue(utf8_locale);
	//_setmode(_fileno(stdout), _O_WTEXT);
	/*wstring s = L"aha";
	string t = "123";
	string wsTmp(s.begin(), s.end());

	t = t + wsTmp;
	cout << t;*/
	const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());
	wofstream fout("input.csv");
	//tạo luôn file csv bằng code cho máu, khỏi làm thủ công vì nó giáo điều quá, cách tạo file csv của m chưa chuẩn giáo điều, muốn chuẩn thì hỏi Trường hay mấy đứa nhóm t á
	//fout << wchar_t(239) << wchar_t(187) << wchar_t(191);//không có dòng này mở bằng note pad bình thường còn excel lỗi phông chữ,có thì note pad và excel bình thường nhưng khi có dòng này thì kí tự đầu tiên của file csv sẽ có mã unicode là 65279(ZERO WIDTH NO-BREAK SPACE) và t k biết cách loại nó ra. Nên đành code kiễu sống chung với nó.
	fout.imbue(utf8_locale);//chuyển fout sang luồng unicode của file, chắc vậy, imbue sau khi làm dòng 22
	fout << "";
	fout.close();


	//wifstream in("input.csv");
	//in.imbue(utf8_locale);//chuyển in sang luồng unicode của file, chắc vậy, không cần làm kiễu giống dòng 22
	//wstring a, temp;
	//getline(in, a);
	//wstringstream stream_in(a);
	//_setmode(_fileno(stdout), _O_WTEXT);
	//while (getline(stream_in, temp, L',')) {
	//	wcout << temp << endl;//thấy lúc in ra Nguyễn Thanh Hoàng bị lệch ở cạnh trái không? là ZERO WIDTH NO-BREAK SPACE đấy
	//}
	//in.close();
	return 0;
}