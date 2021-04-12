#include<iostream>
#include<fstream>
#include<io.h>
#include<fcntl.h>
using namespace std;
struct account {
	string account_name, pass;
	account* pNext, * pPrev;
};
#define path_staff_account "staff_account.txt"
#define path_student_account "student_account.txt"
int user_choose_exist(int choose, int left, int right) {
	while (choose<left || choose>right) {
		wcout << L"Chọn lại từ " << left << L" đến " << right << L" ";
		cin >> choose;//người dùng nhập gì khác số là chương trình bị drop :))
	}
	return choose;
}
int choose_type_account() {
	wcout << L"Đăng nhập: " << endl;
	wcout << L"1. Học sinh " << endl << L"2. Nhân viên " << endl;
	wcout << L"Chọn: ";
	int t;
	cin >> t;//người dùng nhập gì khác số là chương trình bị drop :))
	t = user_choose_exist(t, 1, 2);
	return t;
}
void load_account(string path, account*& acc) {
	ifstream fin;
	fin.open(path);
	account* pCur = 0;
	while (!fin.eof()) {
		if (acc == 0) {
			acc = new account;
			fin >> acc->account_name >> acc->pass;
			acc->pNext = acc->pPrev = nullptr;
			pCur = acc;
		}
		else {
			pCur->pNext = new account;
			pCur->pNext->pPrev = pCur;
			pCur = pCur->pNext;
			fin >> pCur->account_name >> pCur->pass;
			pCur->pNext = nullptr;
		}
	}
	fin.close();
}
bool check_exist_user(account user, account*& acc_list) {
	account* pCur = acc_list;
	while (pCur) {
		if (pCur->account_name == user.account_name && pCur->pass == user.pass) return 1;
		pCur = pCur->pNext;
	}
	return 0;
}
account login(int choose, account*& staff, account*& student) {
	account user;
	wcout << L"Nhập tài khoản mật khẩu " << endl;
	wcout << L"Tài khoản: "; cin >> user.account_name;
	wcout << L"Mật khẩu: "; cin >> user.pass;
	wcout << endl;
	while (!check_exist_user(user, choose == 2 ? staff : student)) {
		wcout << L"Sai tài khoản, mật khẩu: " << endl;
		wcout << L"Chọn 1 để thử lại, chọn 2 để quay về ";
		int choose; cin >> choose;
		choose = user_choose_exist(choose, 1, 2);
		switch (choose)
		{
		case 1:
			wcout << L"Tài khoản: "; cin >> user.account_name;
			wcout << L"Mật khẩu: "; cin >> user.pass;
			wcout << endl;
			break;
		case 2:
			user.account_name = "null";
			return user;
		}
	}
	return user;
}
void deleteall_account(account*& pH) {
	while (pH) {
		account* pCur = pH;
		pH = pH->pNext;
		delete pCur;
	}
}
int main() {
	_setmode(_fileno(stdout), _O_WTEXT);
	ifstream fin;
	account* staff = 0, * student = 0;
	account user;
	user.account_name = "null";
	load_account(path_staff_account, staff);//trong file có tài khoản mật khẩu staff, đưa tụi nó vào dll staff
	load_account(path_student_account, student);//trong file có tài khoản mật khẩu student, đưa tụi nó vào dll student
	while (user.account_name == "null") {
		user = login(choose_type_account(), staff, student);//nhận tài khoản mật khẩu từ người dùng
	}
	//menu(user);
	deleteall_account(staff);
	deleteall_account(student);
	return 0;
}