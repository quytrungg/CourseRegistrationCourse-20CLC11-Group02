#include "Struct.h"
#include "Time.h"
#include "Help.h"
#include "Save.h"

void Input_one_student_by_file(std::wstring str, Node_stu* pCur) {
	// ID
	int begin = str.find(',', 0) + 1;
	int end = str.find(',', begin + 1);
	wchar_t* a = new wchar_t[end - begin + 1];
	str.copy(a, end - begin, begin);
	a[end - begin] = L'\0';
	pCur->stu.ID = Convert_wchart_to_int(a, end - begin);
	delete[] a;

	// Account name
	pCur->stu.account.ID = new wchar_t[end - begin + 1];
	str.copy(pCur->stu.account.ID, end - begin, begin);
	pCur->stu.account.ID[end - begin] = L'\0';

	// First Name
	begin = end + 1;
	end = str.find(',', begin + 1);
	pCur->stu.FirstName = new wchar_t[end - begin + 1];
	str.copy(pCur->stu.FirstName, end - begin, begin);
	pCur->stu.FirstName[end - begin] = L'\0';

	// Last Name
	begin = end + 1;
	end = str.find(',', begin + 1);
	pCur->stu.LastName = new wchar_t[end - begin + 1];
	str.copy(pCur->stu.LastName, end - begin, begin);
	pCur->stu.LastName[end - begin] = L'\0';

	// Gender
	begin = end + 1;
	end = str.find(',', begin + 1);
	pCur->stu.Gender = new wchar_t[end - begin + 1];
	str.copy(pCur->stu.Gender, end - begin, begin);
	pCur->stu.Gender[end - begin] = L'\0';

	// Account password
	pCur->stu.account.Pass = new wchar_t[9];
	int count = 0;

	// Birthday day
	begin = end + 1;
	end = str.find('/', begin + 1);
	a = new wchar_t[end - begin + 1];
	str.copy(a, end - begin, begin);
	a[end - begin] = L'\0';
	for (int i = 0; i < end - begin; i++) {
		pCur->stu.account.Pass[count] = a[i];
		count++;
	}
	pCur->stu.Birthday.Day = Convert_wchart_to_int(a, end - begin);
	delete[] a;

	// Birthday month
	begin = end + 1;
	end = str.find('/', begin + 1);
	a = new wchar_t[end - begin + 1];
	str.copy(a, end - begin, begin);
	a[end - begin] = L'\0';
	for (int i = 0; i < end - begin; i++) {
		pCur->stu.account.Pass[count] = a[i];
		count++;
	}
	pCur->stu.Birthday.Month = Convert_wchart_to_int(a, end - begin);
	delete[] a;

	// Birthday year
	begin = end + 1;
	end = str.find(',', begin + 1);
	a = new wchar_t[end - begin + 1];
	str.copy(a, end - begin, begin);
	a[end - begin] = L'\0';
	for (int i = 0; i < end - begin; i++) {
		pCur->stu.account.Pass[count] = a[i];
		count++;
	}
	pCur->stu.account.Pass[count] = L'\0';
	pCur->stu.Birthday.Year = Convert_wchart_to_int(a, end - begin);
	delete[] a;

	// Social ID
	begin = end + 1;
	end = str.length();
	a = new wchar_t[end - begin + 1];
	str.copy(a, end - begin, begin);
	a[end - begin] = L'\0';
	pCur->stu.SocialID = Convert_wchart_to_int(a, end - begin);
	delete[] a;
}

void Input_student(std::wstring str, Node_stu*& pHead) {
	pHead = new Node_stu;
	Node_stu* pCur = pHead;
	std::wifstream fin(str);
	std::wstring a;
	if (!fin) {
		std::wcout << L"Không thể đọc file \n";
	}
	else {
		fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
		while (!fin.eof()) {
			std::getline(fin, a);
			pCur->pNext = new Node_stu;
			pCur->pNext->pPre = pCur;
			fin.ignore();
			Input_one_student_by_file(a, pCur->pNext);
			pCur = pCur->pNext;
			pCur->pNext = nullptr;
		}
		if (pHead->pNext == nullptr) {
			delete pHead;
			pHead = nullptr;
		}
		else {
			Node_stu* pTemp = pHead;
			pHead = pHead->pNext;
			delete pTemp;
			pHead->pPre = nullptr;
		}
	}
	fin.close();
}

void Input_one_class(std::wstring str, Node_cla* pCur_cla, Node_stu* pHead_stu) {
	// Class name
	int  k = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == L'\\')	k++;
	}
	int begin = 0;
	int end = -1;
	for (int i = 0; i < k; i++) {
		begin = end + 1;
		end = str.find('\\', begin + 1);
	}
	begin = end + 1;
	end = str.find('.', begin + 1);
	pCur_cla->cla.Name = new wchar_t[end - begin];
	str.copy(pCur_cla->cla.Name, end - begin, begin);
	pCur_cla->cla.Name[end - begin] = L'\0';

	// Student ID
	Node_stu* pCur_stu = pHead_stu;
	int count = 0;
	while (pCur_stu != nullptr) {
		count++;
		pCur_stu = pCur_stu->pNext;
	}
	pCur_cla->cla.StudentID = new wchar_t[count * 9 + 1];
	pCur_stu = pHead_stu;
	k = 0;
	for (int i = 0; i < count; i++) {
		int n = pCur_stu->stu.ID;
		int m = 10000000;
		for (int i = 0; i < 8; i++) {
			int r = n / m;
			n = n - r * m;
			m = m / 10;
			pCur_cla->cla.StudentID[k] = wchar_t(r + '0');
			k++;
		}
		pCur_cla->cla.StudentID[k] = L',';
		k++;
		pCur_stu = pCur_stu->pNext;
	}
	pCur_cla->cla.StudentID[count * 9 - 1] = L'\0';
}

