#include"func.h"

void update_school_year_txt(string& school_year, bool& done_create_class, bool& done_add_student, bool& done_create_semester) {
	ofstream fout;
	fout.open(path_school_year);
	fout << school_year << endl << done_create_class << " " << done_add_student << " " << done_create_semester;
	fout.close();
}
void update_semester_period(bool& done_create_registration_session, bool& active_registration_session) {
	ofstream fout;
	fout.open(path_semester_period);
	fout << done_create_registration_session <<" "<<active_registration_session;
	fout.close();
}
void update_class_txt(id_class*& idClass) {
	ofstream out;
	out.open(path_idClass);
	id_class* pCur = idClass;
	while (pCur) {
		out << pCur->id;
		if (pCur->pNext) out << endl;
		pCur = pCur->pNext;
	}
	out.close();
}
void update_date_create_course(LocalTime a, LocalTime b) {
	ofstream out(path_date_create_course);
	out << a.date.Day << " " << a.date.Month << " " << a.date.Year << endl;
	out << b.date.Day << " " << b.date.Month << " " << b.date.Year;
	out.close();
}
bool notExistClass(id_class*& pHead, string a) {
	id_class* pCur = pHead;
	while (pCur) {
		if (pCur->id == a) return 0;
		pCur = pCur->pNext;
	}
	return 1;
}
void AddClass(id_class*& pHead,bool& isAdd) {
		wcout << L"Nhập tên lớp (Nhấn E để dừng). " << endl;
		string info;
		getline(cin, info);
		transform(info.begin(), info.end(), info.begin(), (int (*)(int))toupper);
		while (info != "E") {
			isAdd = 1;
			if (pHead == nullptr) {
				pHead = new id_class;
				pHead->pNext = pHead->pPrev = nullptr;
				pHead->id = info;
			}
			else {
				if (notExistClass(pHead, info) == 1) {
					pHead->pPrev = new id_class;
					pHead->pPrev->pNext = pHead;
					pHead = pHead->pPrev;
					pHead->pPrev = nullptr;
					pHead->id = info;
				}
			}
			getline(cin, info);
			transform(info.begin(), info.end(), info.begin(), (int (*)(int))toupper);
		}
}
bool notExistStudent(in4_student*& pHead, in4_student& a) {
	in4_student* pCur = pHead;
	while (pCur) {
		if (pCur->id == a.id) {
			a.pPrev = pCur->pPrev;
			a.pNext = pCur->pNext;
			(*pCur) = a;
			return 0;
		}
		pCur = pCur->pNext;
	}
	return 1;
}
void makeAccountStudent(account*& student,in4_student*& pCur) {
	if (student == nullptr) {
		student = new account;
		student->pNext = student->pPrev = nullptr;
	}
	else {
		student->pPrev = new account;
		student->pPrev->pNext = student;
		student = student->pPrev;
		student->pPrev = nullptr;
	}
	string t(pCur->id.begin(), pCur->id.end());
	student->account_name = t;
	string t2(pCur->dob.begin(), pCur->dob.end());
	student->pass = t2;
}
void update_account(account*& pHead) {
	if (!pHead) return;
	ofstream out;
	out.open((pHead->account_name[0] < '0' || pHead->account_name[0]>'9') ? path_staff_account : path_student_account);
	account* pCur = pHead;
	while (pCur) {
		out << pCur->account_name << endl << pCur->pass;
		if (pCur->pNext)out << endl;
		pCur = pCur->pNext;
	}
	out.close();
}
void add_student_in4(string file_csv,HT_in4_student& pStudent,wstring& user_choose_id_class,account*& student) {
	wifstream wfin;
	wfin.imbue(utf8_locale);
	wfin.open(file_csv);
	wstring temp, No;
	in4_student* pCur;
	pCur = nullptr;
	wfin.ignore(1000, '\n');
	while (!wfin.eof())
	{
		getline(wfin, temp);
		if (temp[0] == 65279)remove_65279(temp);
		if (temp[0] != L'\0') {
			wstringstream wsin(temp);
			in4_student a;
			getline(wsin, No, L',');
			getline(wsin, a.id, L',');
			getline(wsin, a.lname, L',');
			getline(wsin, a.fname, L',');
			getline(wsin, a.gender, L',');
			getline(wsin, a.dob, L',');
			getline(wsin, a.soid, L',');
			a.id_class = user_choose_id_class;
			a.id_course = nullptr;
			if (notExistStudent(pStudent.head, a) == 1) {
				if (pStudent.head == nullptr) {
					pStudent.head = new in4_student;
					pStudent.tail = pStudent.head;
					pStudent.head->pNext = pStudent.head->pPrev = nullptr;
					pCur = pStudent.head;
				}
				else {
					pCur = pStudent.tail;
					pCur->pNext = new in4_student;
					pCur->pNext->pPrev = pCur;
					pCur = pCur->pNext;
					pCur->pNext = nullptr;
					pStudent.tail = pCur;
				}
				a.pPrev = pCur->pPrev;
				a.pNext = pCur->pNext;
				(*pCur) = a;
				makeAccountStudent(student, pCur);
			}
		}
	}
	wfin.close();
}
void update_student_in4_csv(HT_in4_student& pStudent) {
	wofstream wfout;
	wfout.open(path_student_in4);
	wfout << wchar_t(239) << wchar_t(187) << wchar_t(191);
	wfout.imbue(utf8_locale);
	in4_student* pCur = pStudent.head;
	while (pCur) {
		wfout << pCur->id << L"," << pCur->lname << L"," << pCur->fname << L"," << pCur->gender << L"," << pCur->dob << L"," << pCur->soid << L"," << pCur->id_class;
		id_course_of_student* pCur2 = pCur->id_course;
		while (pCur2) {
			wfout << L"," << pCur2->id << L"," << pCur2->teacher_name << L"," << pCur2->session;
			pCur2 = pCur2->pNext;
		}
		if(pCur->pNext)wfout << endl;
		pCur = pCur->pNext;
	}
	wfout.close();
}
void update_course_csv(HT_course& pCourse) {
	wofstream wfout;
	wfout.open(path_course_csv);
	wfout << wchar_t(239) << wchar_t(187) << wchar_t(191);
	wfout.imbue(utf8_locale);
	course* pCur = pCourse.head;
	while (pCur) {
		wfout << pCur->id << L"," << pCur->name << L"," << pCur->teacher_name << L"," << pCur->num_cre << L"," << pCur->max_student << L"," << pCur->session<<L","<<pCur->count;
		if (pCur->pNext) wfout << endl;
		pCur = pCur->pNext;
	}
	wfout.close();
}
void update_score(score*& pScore) {
	wofstream wfout;
	wfout.open(path_score_csv);
	wfout << wchar_t(239) << wchar_t(187) << wchar_t(191);
	wfout.imbue(utf8_locale);
	score* pCur = pScore;
	while (pCur) {
		wfout << pCur->id << "," << pCur->fullname << "," << pCur->id_class << "," << pCur->id_course << "," << pCur->teacher_name << "," << pCur->session << "," << pCur->schoolYear << ",";
		wfout << pCur->dateStartSemester.date.Day << "," << pCur->dateStartSemester.date.Month << "," << pCur->dateStartSemester.date.Year << ",";
		wfout << pCur->totalMark << "," << pCur->final << "," << pCur->midterm << "," << pCur->other;
		if (pCur->pNext) wfout << endl;
		pCur = pCur->pNext;
	}
	wfout.close();
}
void update_date_sign_course() {
	ofstream out(path_date_sign_course);
}