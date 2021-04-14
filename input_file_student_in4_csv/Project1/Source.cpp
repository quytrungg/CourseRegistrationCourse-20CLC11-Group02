#include"func.h"
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
}
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
	HT_in4_student pStudent;
	pStudent.head = pStudent.tail = 0;
	load_student_in4(pStudent);
	in4_student* pCur = pStudent.head;
	while (pCur) {
		wcout << pCur->id << " " << pCur->lname << " " << pCur->fname << " " << pCur->gender << " " << pCur->soid << " " << pCur->id_class << ", ";
		id_course_of_student* pCur2 = pCur->id_course;
		while (pCur2) {
			wcout << pCur2->id << ", ";
			pCur2 = pCur2->pNext;
		}
		pCur = pCur->pNext;
		wcout << endl;
	}
	deleteall_student_in4(pStudent.head);
	return 0;
}