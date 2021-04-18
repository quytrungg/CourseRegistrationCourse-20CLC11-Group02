#include"func.h"
void add_course(HT_course& pHead) {
	_setmode(_fileno(stdin), _O_WTEXT);
	int n;
	std::wcout << L"1. Nhập môn học" << std::endl;
	std::wcout << L"2. Dừng" << std::endl;
	std::wcout << L"Chọn: ";
	n = user_choose_exist(1, 2);
	course* pCur = nullptr;
	while (n != 2) {
		if (pHead.head == nullptr) {
			pHead.head = new course;
			pHead.tail = pHead.head;
			pHead.head->pNext = pHead.head->pPrev = nullptr;
			pCur = pHead.head;
		}
		else {
			pCur = pHead.tail;
			pCur->pNext = new course;
			pCur->pNext->pPrev = pCur;
			pCur = pCur->pNext;
			pCur->pNext = nullptr;
			pHead.tail = pCur;
		}
		wcout << L"ID : ";
		getline(wcin, pCur->id);
		wcout << L"Tên khóa học: ";
		getline(wcin, pCur->name);
		wcout << L"Tên giảng viên: ";
		getline(wcin, pCur->teacher_name);
		wcout << L"Số tín chỉ: ";
		wcin >> pCur->num_cre;
		wcin.ignore();
		do {
			std::wcout << "Nhập 2 buổi học trong tuần (Ex: MONS1_TUES3): ";
			getline(wcin, pCur->session);
		} while (!Check_session(pCur->session));
		wcout << L"1. Nhập môn học" << endl;
		wcout << L"2. Dừng" << endl;
		wcout << L"Chọn: ";
		n = user_choose_exist(1, 2);
	}
	_setmode(_fileno(stdin), _O_TEXT);
}

void courseManage(HT_course& pCourse) {

}
bool Check_session(wstring str) {
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
