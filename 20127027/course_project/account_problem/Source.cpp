#include<iostream>
#include<fstream>
#include<io.h>
#include<fcntl.h>
using namespace std;
struct account {
	string account_name, pass;
	int job;//1 is staff,0 is student
};
bool check_pass(int& job, string a, ifstream& in) {
	string b;
	in >> b;
	in >> job;
	return a == b;
}
account input_account() {
	account a;
	wcout << L"Nhập tài khoản và mật khẩu " << endl;
	wcout << L"Tài khoản: "; cin >> a.account_name;
	wcout << L"Mật khẩu: "; cin >> a.pass;
	ifstream in;
	in.open(a.account_name + ".txt");
	while (!in.is_open() || (in.is_open() && check_pass(a.job, a.pass, in) == 0)) {
		system("cls");
		wcout << L"Tài khoản không tồn tại hoặc sai mật khẩu, vui lòng nhập lại." << endl;
		wcout << L"Tài khoản: "; cin >> a.account_name;
		wcout << L"Mật khẩu: "; cin >> a.pass;
		in.close();
		in.open(a.account_name + ".txt");
	}
	system("cls");
	in.close();
	return a;
}
void change_pass(account& user) {
	string s;
	wcout << L"Nhập mật khẩu mới: "; cin >> s;//chưa phân biệt được người dùng nhập chuỗi unicode hay không
	user.pass = s;
	ofstream out(user.account_name + ".txt");
	out << user.pass << endl << user.job;
	out.close();
	system("cls");
}
void  show_in4(account user) {

}
void menu(account& user) {
	int choose = 0;
	user = input_account();
	_setmode(_fileno(stdout), _O_WTEXT);
	while (1)
	{
		//user choice
		wcout << L"1.Thông tin cá nhân" << endl;
		wcout << L"2.Thay đổi mật khẩu" << endl;
		wcout << L"3.Đăng xuất" << endl;
		if (user.job) wcout << L"4.Công việc" << endl;
		else wcout << L"4.Học tập" << endl;
		wcout << L"Chọn: ";
		cin >> choose;
		while (choose > 4 || choose < 1) {
			wcout << L"Chọn lại: ";
			cin >> choose;
		}
		system("cls");
		switch (choose) {
		case 1: {
			//show_in4(user);
			break;
		}
		case 2: { 
			change_pass(user);
			break; 
		}
		case 3: {
			/*delete_data();*/ 
			user = input_account(); 
			break; 
		}
		case 4:
			//if (user.job) staff_interact(); else student_interact();
			break;
		}
	}
}
int main() {
	_setmode(_fileno(stdout), _O_WTEXT);
	account user;
	menu(user);

	return 0;
}