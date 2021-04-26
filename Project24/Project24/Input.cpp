#include "Struct.h"
bool Check_session(std::wstring str);

//void Input_course(course*& pHead) {
//	pHead = new course;
//	course* pCur = pHead;
//	int n;
//	std::wcout << "Input the course: " << std::endl;
//	std::wcout << "1. Input" << std::endl;
//	std::wcout << "2. Stop" << std::endl;
//	std::wcout << "Please input the number to choose: ";
//	std::wcin >> n;
//	while (n != 2) {
//		pCur->pNext = new course;
//		std::wcout << "Please input the course id: ";
//		std::cin.ignore();
//		std::getline(std::cin, pCur->pNext->id);
//		std::wcout << "Please input the course name: ";
//		std::getline(std::wcin, pCur->pNext->name);
//		std::wcout << "Please input the teacher name: ";
//		std::getline(std::wcin, pCur->pNext->teacher_name);
//		std::wcout << "Please input how many credits in this course: ";
//		std::wcin >> pCur->pNext->num_cre;
//		std::wcout << "Please input the timetable of the course (Ex: MONS1_MONS3): ";
//		std::cin.ignore();
//		std::getline(std::cin, pCur->pNext->session);
//		pCur->pNext->pPrev = pCur;
//		pCur = pCur->pNext;
//		std::wcout << "Input the course: " << std::endl;
//		std::wcout << "1. Input" << std::endl;
//		std::wcout << "2. Stop" << std::endl;
//		std::wcout << "Please input the number to choose: ";
//		std::wcin >> n;
//	}
//	if (pHead->pNext == nullptr) {
//		delete pHead;
//		pHead = nullptr;
//	}
//	else {
//		course* pTemp = pHead;
//		pHead = pHead->pNext;
//		delete pTemp;
//		pHead->pPrev = nullptr;
//	}
//}

void Input_course(course* &pHead) {
	pHead = new course;
	course* pCur = pHead;
	int n;
	std::wcout << "Input the course: " << std::endl;
	std::wcout << "1. Input" << std::endl;
	std::wcout << "2. Stop" << std::endl;
	std::wcout << "Please input the number to choose: ";
	std::wcin >> n;
	while (n != 2) {
		pCur->pNext = new course;
		std::wcout << "Please input the course id: ";
		std::wcin.ignore();
		std::getline(std::wcin, pCur->pNext->id);
		std::wcout << "Please input the course name: ";
		std::getline(std::wcin, pCur->pNext->name);
		std::wcout << "Please input the teacher name: ";
		std::getline(std::wcin, pCur->pNext->teacher_name);
		std::wcout << "Please input how many credits in this course: ";
		std::wcin >> pCur->pNext->num_cre;
		do {
			std::wcout << "Please input the timetable of the course (Ex: MONS1_MONS3): ";
			std::wcin.ignore();
			std::getline(std::wcin, pCur->pNext->session);
		} while (!Check_session(pCur->pNext->session));
		pCur->pNext->pPrev = pCur;
		pCur = pCur->pNext;
		pCur->pNext = nullptr;
		std::wcout << "Input the course: " << std::endl;
		std::wcout << "1. Input" << std::endl;
		std::wcout << "2. Stop" << std::endl;
		std::wcout << "Please input the number to choose: ";
		std::wcin >> n;
	}
	if (pHead->pNext == nullptr) {
		delete pHead;
		pHead = nullptr;
	}
	else {
		course* pTemp = pHead;
		pHead = pHead->pNext;
		delete pTemp;
		pHead->pPrev = nullptr;
	}
}

bool Check_session(std::wstring str) {
	wchar_t* a = new wchar_t[str.length() + 1];
	str.copy(a, str.length(), 0);
	a[str.length()] = L'\0';
	if (a[0] == L'M') {
		if (a[1] == L'O') {
			if (a[2] == L'N') {

			}
			else return false;
		}
		else return false;
	}
	else if (a[0] == L'T') {
		if (a[1] == L'U') {
			if (a[2] == L'E') {

			}
			else return false;
		}
		else return false;
	}
	else if (a[0] == L'W') {
		if (a[1] == L'E') {
			if (a[2] == L'D') {

			}
			else return false;
		}
		else return false;
	}
	else if (a[0] == L'T') {
		if (a[1] == L'H') {
			if (a[2] == L'U') {

			}
			else return false;
		}
		else return false;
	}
	else if (a[0] == L'F') {
		if (a[1] == L'R') {
			if (a[2] == L'I') {

			}
			else return false;
		}
		else return false;
	}
	else if (a[0] == L'S') {
		if (a[1] == L'A') {
			if (a[2] == L'T') {

			}
			else return false;
		}
		else return false;
	}
	else return false;
	if (a[3] == L'S') {

	}
	else return false;
	if (a[4] == L'1' || a[4] == L'2' || a[4] == L'3' || a[4] == L'4') {

	}
	else return false;
	if (a[5] == L'_') {

	}
	else return false;
	if (a[6] == L'M') {
		if (a[7] == L'O') {
			if (a[8] == L'N') {

			}
			else return false;
		}
		else return false;
	}
	else if (a[6] == L'T') {
		if (a[7] == L'U') {
			if (a[8] == L'E') {

			}
			else return false;
		}
		else return false;
	}
	else if (a[6] == L'W') {
		if (a[7] == L'E') {
			if (a[8] == L'D') {

			}
			else return false;
		}
		else return false;
	}
	else if (a[6] == L'T') {
		if (a[7] == L'H') {
			if (a[8] == L'U') {

			}
			else return false;
		}
		else return false;
	}
	else if (a[6] == L'F') {
		if (a[7] == L'R') {
			if (a[8] == L'I') {

			}
			else return false;
		}
		else return false;
	}
	else if (a[6] == L'S') {
		if (a[7] == L'A') {
			if (a[8] == L'T') {

			}
			else return false;
		}
		else return false;
	}
	else return false;
	if (a[9] == L'S') {

	}
	else return false;
	if (a[10] == L'1' || a[10] == L'2' || a[10] == L'3' || a[10] == L'4') {

	}
	else return false;
	return true;
}

void Output_the_course(course* pHead) {
	while (pHead != nullptr) {
		//std::wcout << pHead->id << "," << pHead->name << L"," << pHead->teacher_name << "," << pHead->num_cre << "," << pHead->session << std::endl;
		std::wcout << L"Id: " << pHead->id << std::endl;
		std::wcout << L"Tên khóa học: " << pHead->name << std::endl;
		std::wcout << L"Tên giảng viên: " << pHead->teacher_name << std::endl;
		std::wcout << L"Số tín chỉ: " << pHead->num_cre << std::endl;
		std::wcout << L"Số sinh viên tối đa: " << pHead->max_student << std::endl;
		std::wcout << L"Thời gian 2 buổi học trên tuần: " << pHead->session << std::endl;
		pHead = pHead->pNext;
	}
}

void Delete_the_course(course*& pHead) {
	course* pTemp = pHead;
	while (pHead != nullptr) {
		pHead = pHead->pNext;
		delete pTemp;
		pTemp = pHead;
	}
}
