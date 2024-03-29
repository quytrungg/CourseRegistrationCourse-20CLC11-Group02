#include"func.h"
void load_account(string path, account*& acc) {
	ifstream fin;
	fin.open(path);
	account* pCur = 0;
	while (!fin.eof()) {
		if (acc == 0) {
			acc = new account;
			getline(fin, acc->account_name, '\n');
			getline(fin, acc->pass, '\n');
			acc->pNext = acc->pPrev = nullptr;
			pCur = acc;
		}
		else {
			pCur->pNext = new account;
			pCur->pNext->pPrev = pCur;
			pCur = pCur->pNext;
			getline(fin, pCur->account_name, '\n');
			getline(fin, pCur->pass, '\n');
			pCur->pNext = nullptr;
		}
	}
	fin.close();
}
void load_score(score*& pScore) {
	wifstream wfin;
	wfin.imbue(utf8_locale);
	wstring temp;
	score* pCurScore;
	pCurScore = nullptr;
	wfin.open(path_score_csv);
	while (!wfin.eof())
	{
		getline(wfin, temp);
		if (temp[0] == 65279)remove_65279(temp);
		if (temp[0] != L'\0') {
			wstringstream wsin(temp);
			if (pScore == nullptr) {
				pScore = new score;
				pScore->pNext = pScore->pPrev = nullptr;
				pCurScore = pScore;
			}
			else {
				pCurScore->pNext = new score;
				pCurScore->pNext->pPrev = pCurScore;
				pCurScore = pCurScore->pNext;
				pCurScore->pNext = nullptr;
			}
			getline(wsin, pCurScore->id, L',');
			getline(wsin, pCurScore->fullname, L',');
			getline(wsin, pCurScore->id_class, L',');
			getline(wsin, pCurScore->id_course, L',');
			getline(wsin, pCurScore->teacher_name, L',');
			getline(wsin, pCurScore->session, L',');
			getline(wsin, pCurScore->schoolYear, L',');
			wsin >> pCurScore->dateStartSemester.date.Day;
			wsin.ignore(10, L',');
			wsin >> pCurScore->dateStartSemester.date.Month;
			wsin.ignore(10, L',');
			wsin >> pCurScore->dateStartSemester.date.Year;
			wsin.ignore(10, L',');
			wsin >> pCurScore->totalMark;
			wsin.ignore(10,L',');
			wsin >> pCurScore->final;
			wsin.ignore(10, L',');
			wsin >> pCurScore->midterm;
			wsin.ignore(10, L',');
			wsin >> pCurScore->other;
		}
	}
	wfin.close();
}
void load_class(id_class*& idClass) {
	ifstream fin;
	fin.open(path_idClass);
	id_class* pCur = 0;
	string a;
	while (!fin.eof()) {
		getline(fin, a);
		if (a[0] != '\0') {
			if (idClass == 0) {
				idClass = new id_class;
				idClass->id = a;
				idClass->pNext = idClass->pPrev = nullptr;
				pCur = idClass;
			}
			else {
				pCur->pNext = new id_class;
				pCur->pNext->pPrev = pCur;
				pCur = pCur->pNext;
				pCur->id = a;
				pCur->pNext = nullptr;
			}
		}
	}
	fin.close();
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
		if (temp[0] == 65279)remove_65279(temp);
		if (temp[0] != L'\0') {
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
			getline(wsin, pCur->id, L',');
			getline(wsin, pCur->lname, L',');
			getline(wsin, pCur->fname, L',');
			getline(wsin, pCur->gender, L',');
			getline(wsin, pCur->dob, L',');
			getline(wsin, pCur->soid, L',');
			getline(wsin, pCur->id_class, L',');
			pCur->id_course = nullptr;
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
				getline(wsin, temp, L',');
				pCur2->teacher_name = temp;
				getline(wsin, temp, L',');
				pCur2->session = temp;
			}
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
	wfin.close();
}
void load_course(HT_course& pCourse) {
	wifstream wfin;
	wfin.imbue(utf8_locale);
	wfin.open(path_course_csv);
	wstring temp;
	course* pCur;
	pCur = nullptr;
	while (!wfin.eof()) {
			getline(wfin, temp);
			if (temp[0] == 65279)remove_65279(temp);
			if (temp[0] != L'\0') {
			wstringstream wsin(temp);
			if (pCourse.head == nullptr) {
				pCourse.head = new course;
				pCourse.tail = pCourse.head;
				pCourse.head->pNext = pCourse.head->pPrev = nullptr;
				pCur = pCourse.head;
			}
			else {
				pCur->pNext = new course;
				pCur->pNext->pPrev = pCur;
				pCur = pCur->pNext;
				pCur->pNext = nullptr;
				pCourse.tail = pCur;
			}
			getline(wsin, pCur->id, L',');
			getline(wsin, pCur->name, L',');
			getline(wsin, pCur->teacher_name, L',');
			wstring temp2;
			wsin >> pCur->num_cre;
			wsin.ignore(100,L',');
			wsin >> pCur->max_student;
			wsin.ignore(100,L',');
			getline(wsin, pCur->session, L',');
			wsin >> pCur->count;
		}
	}
	//wcout << pCourse.head->max_student << endl;
	wfin.close();
}
void loadSchoolYear(string& school_year,bool& done_create_class,bool& done_add_student,bool& done_create_semester) {
	ifstream fin;
	fin.open(path_school_year);
	if (!fin.is_open()) return;
	getline(fin, school_year);
	fin >> done_create_class >> done_add_student >> done_create_semester ;
	fin.close();
}
void loadSemesterPeriod(bool& done_create_registration_session, bool& active_registration_session) {
	ifstream fin;
	fin.open(path_semester_period);
	if (!fin.is_open()) return;
	fin >> done_create_registration_session >> active_registration_session;
	fin.close();
}
void load_deadline_registration(LocalTime& aBegin, LocalTime& aEnd) {
	ifstream in(path_date_create_course);
	if (!in.is_open()) return;
	in >> aBegin.date.Day >> aBegin.date.Month >> aBegin.date.Year;
	in >> aEnd.date.Day >> aEnd.date.Month >> aEnd.date.Year;
	in.close();
}
