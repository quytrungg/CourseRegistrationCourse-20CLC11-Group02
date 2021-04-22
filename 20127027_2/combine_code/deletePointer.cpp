#include"func.h"
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
void deleteall_course(course*& pH) {
	while (pH) {
		course* pCur = pH;
		pH = pH->pNext;
		delete pCur;
	}
}
