#include"func.h"
void create_school_year(string& school_year, bool& done_create_class, bool& done_add_student, bool& done_create_semester, bool& done_create_registration_session) {
	wcout << L"Nhập năm học mới. ";
	//điều kiện để sau
	getline(cin, school_year);
	update_school_year_txt(school_year, done_create_class, done_add_student, done_create_semester, done_create_registration_session);
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
void do_staff_work(id_class*& idClass, HT_in4_student& student_in4,HT_course& pCourse,account*& student) {
	string school_year = "\0";
	bool done_create_class = 0, done_create_semester = 0, done_add_student = 0, done_create_registration_session = 0;
	//check xem có đang trong giai đoạn bắt đầu năm học không,tạo lớp xog chưa,tạo 3 học kì xong chưa
	loadSchoolYear(school_year, done_create_class, done_add_student, done_create_semester, done_create_registration_session);
	while (1)
	{
		if (done_create_semester) {
			LocalTime aBegin, aEnd, cTime = currentDateTime();
			load_deadline_registration(aBegin, aEnd);
			//wcout << cTime.date.Day << " " << cTime.date.Month << " " << cTime.date.Year;
			while (done_create_registration_session == 0 || compare2Times(cTime, aEnd)) {
				wcout << L"1. Đăng xuất" << endl;
				if (done_create_registration_session == 0)
					wcout << L"2. Tạo phiên đăng kí học phần." << endl; 
				else
					wcout << L"2. Tạo khóa học." << endl;
				wcout << L"Chọn: "; int choose1 = user_choose_exist(1, 2);
				switch (choose1) {
				case 1:return;
				case 2:
					if (done_create_registration_session) {
						courseManage(pCourse);
					}
					else {
						done_create_registration_session = 1;
						wcout << L"Nhập ngày bắt đầu đăng kí học phần: ";
						cin >> aBegin.date.Day;
						wcout << L"Nhập tháng bắt đầu đăng kí học phần: ";
						cin >> aBegin.date.Month;
						wcout << L"Nhập năm bắt đầu đăng kí học phần: ";
						cin >> aBegin.date.Year;
						while (checkDayIsTrue(aBegin) == 0) {
							wcout << L"Ngày không tồn tại, chọn 1 để tiếp tục, chọn 2 để dừng ";
							cin.ignore(1000, '\n');
							int choose = user_choose_exist(1, 2);
							if (choose == 2) {
								done_create_registration_session = 0;
								break;
							}
							else {
								wcout << L"Nhập ngày bắt đầu đăng kí học phần: ";
								cin >> aBegin.date.Day;
								wcout << L"Nhập tháng bắt đầu đăng kí học phần: ";
								cin >> aBegin.date.Month;
								wcout << L"Nhập năm bắt đầu đăng kí học phần: ";
								cin >> aBegin.date.Year;
							}
						}
						if (done_create_registration_session) {
							wcout << L"Nhập ngày kết thúc đăng kí học phần: ";
							cin >> aEnd.date.Day;
							wcout << L"Nhập tháng kết thúc đăng kí học phần: ";
							cin >> aEnd.date.Month;
							wcout << L"Nhập năm kết thúc đăng kí học phần: ";
							cin >> aEnd.date.Year;
							while (checkDayIsTrue(aEnd) == 0) {
								wcout << L"Ngày không tồn tại, chọn 1 để tiếp tục, chọn 2 để dừng ";
								cin.ignore(1000, '\n');
								int choose = user_choose_exist(1, 2);
								if (choose == 2) {
									done_create_registration_session = 0;
									break;
								}
								else {
									wcout << L"Nhập ngày kết thúc đăng kí học phần: ";
									cin >> aEnd.date.Day;
									wcout << L"Nhập tháng kết thúc đăng kí học phần: ";
									cin >> aEnd.date.Month;
									wcout << L"Nhập năm kết thúc đăng kí học phần: ";
									cin >> aEnd.date.Year;
								}
							}
						}
						if (done_create_registration_session) {
							update_date_registration_session(aBegin, aEnd);
							update_school_year_txt(school_year, done_create_class, done_add_student, done_create_semester, done_create_registration_session);
						}
						else cin.ignore(1000, '\n');
					}
				}
			}
		}
		else {
			while (done_create_semester == 0)
			{
				wcout << L"1. Đăng xuất" << endl;
				wcout << "2. " << (school_year == "\0" ? L"Tạo năm học mới." : (done_create_class == 0 ? L"Tạo lớp học mới." : (done_add_student == 0 ? L"Thêm học sinh. " : L"Tạo thời gian 3 học kì."))) << endl;
				wcout << L"Chọn: ";
				int choose = user_choose_exist(1, 2);
				switch (choose) {
				case 1: return;
				case 2:
					if (school_year == "\0")
						create_school_year(school_year, done_create_class, done_add_student, done_create_semester, done_create_registration_session);
					else if (done_create_class == 0) {
						AddClass(idClass);
						wcout << L"Đây là toàn bộ các lớp của năm học chưa? 1.Rồi, 2.Chưa: ";
						choose = user_choose_exist(1, 2);
						if (choose == 1) {
							done_create_class = 1;
							update_school_year_txt(school_year, done_create_class, done_add_student, done_create_semester, done_create_registration_session);
						}
						update_class_txt(idClass);
					}
					else if (done_add_student == 0) {
						string t = choose_id_class(idClass), file_csv;
						wstring user_choose_id_class(t.begin(), t.end());
						if (user_choose_id_class != L"null") {
							wcout << L"Nhập tên file csv chứa thông tin sinh viên: "; getline(cin, file_csv);
							file_csv = file_csv + ".csv";
							add_student_in4(file_csv, student_in4, user_choose_id_class,student);
							update_student_in4_csv(student_in4);
							update_student_account(student);
							wcout << L"Đây là toàn bộ các học sinh của năm nhất chưa? 1.Rồi, 2.Chưa: ";
							choose = user_choose_exist(1, 2);
							if (choose == 1) {
								done_add_student = 1;
								update_school_year_txt(school_year, done_create_class, done_add_student, done_create_semester, done_create_registration_session);
							}
						}
					}
					else if (done_create_semester == 0) {
						done_create_semester = create_3_semester();
						update_school_year_txt(school_year, done_create_class, done_add_student, done_create_semester, done_create_registration_session);
					}
				}
			}
		}
	}
}