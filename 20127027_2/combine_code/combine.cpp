#include"struct_include_define.h"

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
int choose_type_account() {
	wcout << L"Đăng nhập: " << endl;
	wcout << L"1. Học sinh " << endl << L"2. Nhân viên " << endl;
	wcout << L"Chọn: ";
	int t;
	t = user_choose_exist(1, 2);
	return t;
}
void load_account(string path, account*& acc) {
	ifstream fin;
	fin.open(path);
	account* pCur = 0;
	while (!fin.eof()) {
		if (acc == 0) {
			acc = new account;
			getline(fin, acc->account_name);
			getline(fin, acc->pass);
			acc->pNext = acc->pPrev = nullptr;
			pCur = acc;
		}
		else {
			pCur->pNext = new account;
			pCur->pNext->pPrev = pCur;
			pCur = pCur->pNext;
			getline(fin, pCur->account_name);
			getline(fin, pCur->pass);
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
void deleteall_account(account*& pH) {
	while (pH) {
		account* pCur = pH;
		pH = pH->pNext;
		delete pCur;
	}
}
void deleteall_class(id_class*& pH) {
	while (pH) {
		id_class* pCur = pH;
		pH = pH->pNext;
		delete pCur;
	}
}
void update_school_year_txt(string& school_year, bool& done_create_class, bool& done_add_student, bool& done_create_semester) {
	ofstream fout;
	fout.open(path_school_year);
	fout << school_year << endl << done_create_class << " " << done_add_student << " " << done_create_semester;
	fout.close();
}
void create_school_year(string& school_year, bool& done_create_class, bool& done_add_student, bool& done_create_semester) {
	//some condition here
	wcout << L"Nhập năm học mới. ";
	getline(cin, school_year);
	update_school_year_txt(school_year, done_create_class, done_add_student, done_create_semester);
}
//bool create_3_semester() {
//
//}
void AddClass(id_class*& pHead) {
	int option;
	wcout << L"1. Thêm lớp. " << endl;
	wcout << L"2. Quay về. " << endl;
	wcout << L"Chọn: ";
	option = user_choose_exist(1, 2);
	if (option == 1) {
		wcout << L"Nhấn E để dừng. " << endl;
		string info;
		getline(cin, info);
		while (info != "E") {
			if (pHead == nullptr) {
				pHead = new id_class;
				pHead->pNext = pHead->pPrev = nullptr;
				pHead->id = info;
			}
			else {
				pHead->pPrev = new id_class;
				pHead->pPrev->pNext = pHead;
				pHead = pHead->pPrev;
				pHead->pPrev = nullptr;
				pHead->id = info;
			}
			getline(cin, info);
		}
	}
	else {
		wcout << endl; return;
	}
}
void update_class_txt(id_class*& idClass) {
	ofstream out;
	out.open(path_idClass);
	id_class* pCur = idClass;
	while (pCur) {
		out << pCur->id << endl;
		pCur = pCur->pNext;
	}
	out.close();
}
void load_class(id_class*& idClass) {
	ifstream fin;
	fin.open(path_idClass);
	id_class* pCur = 0;
	while (!fin.eof()) {
		if (idClass == 0) {
			idClass = new id_class;
			getline(fin, idClass->id);
			idClass->pNext = idClass->pPrev = nullptr;
			pCur = idClass;
		}
		else {
			pCur->pNext = new id_class;
			pCur->pNext->pPrev = pCur;
			pCur = pCur->pNext;
			getline(fin, pCur->id);
			pCur->pNext = nullptr;
		}
	}
	fin.close();
}
string choose_id_class(id_class*& idClass) {
	id_class* pCur = idClass;
	int n = 0;
	_setmode(_fileno(stdout), _O_TEXT);
	while (pCur) {
		n++;
		cout << n << ". " << pCur->id << endl;
		pCur = pCur->pNext;
	}
	_setmode(_fileno(stdout), _O_WTEXT);
	wcout << n + 1 << L". Quay về." << endl;
	wcout << L"Chọn: ";
	int choose = user_choose_exist(1, n + 1);
	if (choose == n + 1) return "null";
	n = 0;
	pCur = idClass;
	while (pCur) {
		n++;
		if (choose == n) return pCur->id;
		pCur = pCur->pNext;
	}
}
void do_staff_work(id_class*& idClass) {
	string school_year = "\0";
	bool done_create_class = 0, done_create_semester = 0, done_add_student = 0;
	//check xem có đang trong giai đoạn bắt đầu năm học không,tạo lớp xog chưa,tạo 3 học kì xong chưa
	ifstream fin;
	fin.open(path_school_year);
	getline(fin, school_year);
	fin >> done_create_class >> done_add_student >> done_create_semester;
	fin.close();
	if (done_create_semester) {}
	else {
		while (1)
		{
			wcout << L"1. Đăng xuất" << endl;
			wcout << "2. " << (school_year == "\0" ? L"Tạo năm học mới." : (done_create_class == 0 ? L"Tạo lớp học mới." : (done_add_student == 0 ? L"Thêm học sinh. " : (done_create_semester == 0 ? L"Tạo thời gian 3 học kì." : L"Tạo thời gian đăng kí khóa học của học kì hiện tại.")))) << endl;
			wcout << L"Chọn: ";
			int choose = user_choose_exist(1, 2);
			switch (choose) {
			case 1: return;
			case 2:
				if (school_year == "\0") create_school_year(school_year, done_create_class, done_add_student, done_create_semester);
				else if (done_create_class == 0) {
					AddClass(idClass);
					wcout << L"Đây là toàn bộ các lớp của năm học chưa? 1.Rồi, 2.Chưa: ";
					choose = user_choose_exist(1, 2);
					if (choose == 1) {
						done_create_class = 1;
						update_school_year_txt(school_year, done_create_class, done_add_student, done_create_semester);
					}
					update_class_txt(idClass);
				}
				else if (done_add_student == 0) {
					string user_choose_id_class = choose_id_class(idClass), file_csv;
					if (user_choose_id_class != "null") {
						wcout << L"Nhập tên file csv chứa thông tin sinh viên: "; cin >> file_csv;
						//update_student_in4_csv(file_csv)
					}
				}
				//else if (done_create_semester == 0) done_create_semester = create_3_semester();
			}
		}
	}
}
void load_student_in4(HT_in4_student& pStudent);
void deleteall_student_in4(in4_student*& pH) {
	while (pH) {
		in4_student* pCur = pH;
		id_course_of_student* pH2 = pH->id_course;
		while (pH2) {
			id_course_of_student* pCur2 = pH2;
			pH2 = pH2->pNext;
			delete pCur2;
		}
		pH = pH->pNext;
		delete pCur;
	}
}


int main() {
	_setmode(_fileno(stdout), _O_WTEXT);
	account* staff = 0, * student = 0, user;
	id_class* idClass = 0;
	HT_in4_student student_in4;
	student_in4.head = student_in4.tail = 0;
	user.account_name = "null";
	/*load_class(idClass);*/
	load_student_in4(student_in4);
	//load_account(path_staff_account, staff);//trong file có tài khoản mật khẩu staff, đưa tụi nó vào dll staff
	//load_account(path_student_account, student);//trong file có tài khoản mật khẩu student, đưa tụi nó vào dll student
	//while (user.account_name == "null") {
	//	user = login(choose_type_account(), staff, student);//nhận tài khoản mật khẩu từ người dùng
	//}
	//if (user.account_name[0] < '0' || user.account_name[0]>'9') do_staff_work(idClass);
	////menu(user);
	deleteall_student_in4(student_in4.head);
	deleteall_class(idClass);
	deleteall_account(staff);
	deleteall_account(student);
	return 0;
}
void load_student_in4(HT_in4_student& pStudent) {
	wifstream wfin;
	wfin.imbue(utf8_locale);
	wfin.open(path_student_in4);
	wstring temp;
	in4_student* pCur;
	pCur = nullptr;
	while (!wfin.eof())
	{
		getline(wfin, temp);
		wstringstream wsin(temp);
		if (pStudent.head == nullptr) {
			pStudent.head = new in4_student;
			pStudent.tail = pStudent.head;
			pStudent.head->pNext = pStudent.head->pPrev = nullptr;
			pCur = pStudent.head;
		}
		else {
			pCur->pNext = new in4_student;
			pCur->pNext->pPrev = pCur;
			pCur = pCur->pNext;
			pCur->pNext = nullptr;
			pStudent.tail = pCur;
		}
		pCur->id_course = nullptr;
		getline(wsin, pCur->id, L',');
		getline(wsin, pCur->lname, L',');
		getline(wsin, pCur->fname, L',');
		getline(wsin, pCur->gender, L',');
		getline(wsin, pCur->soid, L',');
		getline(wsin, pCur->id_class, L',');
		wstring temp;
		id_course_of_student* pCur2;
		pCur2 = nullptr;
		while (getline(wsin, temp, L',')) {
			if (pCur->id_course == nullptr) {
				pCur->id_course = new id_course_of_student;
				pCur->id_course->pNext = pCur->id_course->pPrev = nullptr;
				pCur2 = pCur->id_course;
			}
			else {
				pCur2->pNext = new id_course_of_student;
				pCur2->pNext->pPrev = pCur2;
				pCur2 = pCur2->pNext;
				pCur2->pNext = nullptr;
			}
			pCur2->id = temp;
		}
	}
	/*pCur = pStudent.head;
	while (pCur) {
		wcout << pCur->id << " " << pCur->lname << " " << pCur->fname << " " << pCur->gender << " " << pCur->soid << " " << pCur->id_class << ", ";
		id_course_of_student* pCur2 = pCur->id_course;
		while (pCur2) {
			wcout << pCur2->id << ", ";
			pCur2 = pCur2->pNext;
		}
		pCur = pCur->pNext;
		wcout << endl;
	}*/
}