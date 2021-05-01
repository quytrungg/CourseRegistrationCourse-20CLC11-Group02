#include"func.h"
int choose_type_account() {
	wcout << L" _ĐĂNG NHẬP_" << endl;
	COORD cursor = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
	wstring* menu = new wstring[3];
	menu[0] = L"Thoát";
	menu[1] = L"Học sinh";
	menu[2] = L"Nhân viên";
	int t=choose_menu(cursor.X, cursor.Y, menu, 3);
	delete[]menu;
	/*wcout << L"1. Học sinh " << endl << L"2. Nhân viên " << endl << L"3. Thoát" << endl;
	wcout << L"Chọn: ";
	int t;
	t = user_choose_exist(1, 3);
	//code cũ
	*/
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
	if (choose == 1) {
		user.account_name = "end";
		return user;
	};
	wcout << L"Nhập tài khoản mật khẩu " << endl;
	wcout << L"Tài khoản: "; getline(cin, user.account_name);
	wcout << L"Mật khẩu: "; getline(cin, user.pass);
	wcout << endl;
	while (!check_exist_user(user, choose == 3 ? staff : student)) {
		wcout << L"Sai tài khoản, mật khẩu: " << endl;
		wcout << L"Chọn 1 để thử lại, chọn 2 để quay về ";
		int choose1;
		choose1 = user_choose_exist(1, 2);
		switch (choose1)
		{
		case 1:
			wcout << L"Tài khoản: "; getline(cin, user.account_name);
			wcout << L"Mật khẩu: "; getline(cin, user.pass);
			wcout << endl;
			break;
		case 2:
			user.account_name = "null";
			system("cls");
			return user;
		}
	}
	system("cls");
	return user;
}
account* FindNodeAccount(account*& pHead,account&user) {
	account* pCur = pHead;
	while (pCur != nullptr) {
		if (pCur->account_name == user.account_name) break;
		pCur = pCur->pNext;
	}
	return pCur;
}
//Đổi pass cho account đó,update file
void changePassword(account*& pHead,account& user) {
	string newpass, temp;
	account* pCur = FindNodeAccount(pHead,user);
	wcout << L"Nhập mật khẩu của bạn: ";
	getline(cin, newpass, '\n');
	wcout << L"Xác nhận mật khẩu: ";
	getline(cin, temp, '\n');
	while (newpass != temp) {
		wcout << L"Mật khẩu xác nhận không đúng"<<endl;
		COORD cursor = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
		wstring* menu = new wstring[2];
		menu[0] = L"Nhập lại";
		menu[1] = L"Quay về";
		int choose = choose_menu(cursor.X, cursor.Y, menu, 2);
		switch (choose) {
		case 1:return;
		case 2:getline(cin, temp, '\n');
		}
	}
	user.pass=pCur->pass = newpass;
	update_account(pHead);

	//update .txt
}