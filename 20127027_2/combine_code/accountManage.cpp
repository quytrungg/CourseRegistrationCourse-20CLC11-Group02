#include"func.h"
int choose_type_account() {
	wcout << L"Đăng nhập: " << endl;
	wcout << L"1. Học sinh " << endl << L"2. Nhân viên " << endl;
	wcout << L"Chọn: ";
	int t;
	t = user_choose_exist(1, 2);
	return t;
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
	wcout << L"Tài khoản: "; getline(cin, user.account_name);
	wcout << L"Mật khẩu: "; getline(cin, user.pass);
	wcout << endl;
	while (!check_exist_user(user, choose == 2 ? staff : student)) {
		wcout << L"Sai tài khoản, mật khẩu: " << endl;
		wcout << L"Chọn 1 để thử lại, chọn 2 để quay về ";
		int choose;
		choose = user_choose_exist(1, 2);
		switch (choose)
		{
		case 1:
			wcout << L"Tài khoản: "; getline(cin, user.account_name);
			wcout << L"Mật khẩu: "; getline(cin, user.pass);
			wcout << endl;
			break;
		case 2:
			user.account_name = "null";
			return user;
		}
	}
	return user;
}