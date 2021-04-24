#include "Struct.h"
#include "Time.h"
#include "Help.h"
#include "Save.h"
#include "Delete.h"

char* Create_second_folder(std::string str, char* main_folder) {
	int n = str.length() + 2 + strlen(main_folder);
	char* second_folder = new char[n];
	int count = 0;
	for (int i = 0; i < strlen(main_folder); i++) {
		second_folder[count] = main_folder[i];
		count++;
	}
	second_folder[count] = '\\';
	count++;
	char* a = new char[str.length() + 1];
	str.copy(a, str.length(), 0);
	a[str.length()] = '\0';
	for (int i = 0; i < str.length(); i++) {
		second_folder[count] = a[i];
		count++;
	}
	delete[] a;
	second_folder[n - 1] = '\0';
	return second_folder;
}

char* Create_third_folder(std::string str, char* second_folder) {
	int n = str.length() + 2 + strlen(second_folder);
	char* third_folder = new char[n];
	int count = 0;
	for (int i = 0; i < strlen(second_folder); i++) {
		third_folder[count] = second_folder[i];
		count++;
	}
	third_folder[count] = '\\';
	count++;
	char* a = new char[str.length() + 1];
	str.copy(a, str.length(), 0);
	a[str.length()] = '\0';
	for (int i = 0; i < str.length(); i++) {
		third_folder[count] = a[i];
		count++;
	}
	delete[] a;
	third_folder[n - 1] = '\0';
	return third_folder;
}

char* Create_file(char* filename, char* folder, std::string filetype) {
	int n = filetype.length() + 2 + strlen(filename) + strlen(folder);
	char* file = new char[n];
	int count = 0;
	for (int i = 0; i < strlen(folder); i++) {
		file[count] = folder[i];
		count++;
	}
	file[count] = '\\';
	count++;
	for (int i = 0; i < strlen(filename); i++) {
		file[count] = filename[i];
		count++;
	}
	char* a = new char[filetype.length() + 1];
	filetype.copy(a, filetype.length(), 0);
	a[filetype.length()] = '\0';
	for (int i = 0; i < filetype.length(); i++) {
		file[count] = a[i];
		count++;
	}
	delete[] a;
	file[n - 1] = '\0';
	return file;
}

wchar_t* Create_file_1(wchar_t* filename, char* folder, std::string filetype) {
	int n = filetype.length() + 2 + wcslen(filename) + strlen(folder);
	wchar_t* file = new wchar_t[n];
	int count = 0;
	for (int i = 0; i < strlen(folder); i++) {
		file[count] = folder[i];
		count++;
	}
	file[count] = '\\';
	count++;
	for (int i = 0; i < wcslen(filename); i++) {
		file[count] = filename[i];
		count++;
	}
	char* a = new char[filetype.length() + 1];
	filetype.copy(a, filetype.length(), 0);
	a[filetype.length()] = '\0';
	for (int i = 0; i < filetype.length(); i++) {
		file[count] = a[i];
		count++;
	}
	delete[] a;
	file[n - 1] = '\0';
	return file;
}

void Create_main_folder(char* current_year) {
	_mkdir(current_year);
	_mkdir(Create_second_folder("Student", current_year));
	_mkdir(Create_second_folder("Semester", current_year));
	_mkdir(Create_second_folder("Class", current_year));
	_mkdir(Create_third_folder("1", Create_second_folder("Semester", current_year)));
	_mkdir(Create_third_folder("2", Create_second_folder("Semester", current_year)));
	_mkdir(Create_third_folder("3", Create_second_folder("Semester", current_year)));
}

/*void Save_stu_to_bin(int stu_ID, char* folder, Node_stu* pCur) {
	char* ID = Convert_int_to_char(stu_ID);
	char* file = Create_file(ID, folder, ".txt");
	std::wofstream fout(file,std::ios::binary);
	fout.write((wchar_t*)pCur->stu.ID, sizeof(pCur->stu.ID));
}*/

void Save_stu_to_test(Node_stu* pHead, char* folder) {
	char* file;
	char* filename;
	while (pHead != nullptr) {
		filename = Convert_int_to_char(pHead->stu.ID);
		file = Create_file(filename, folder, ".txt");
		std::wofstream fout(file);
		fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
		fout << pHead->stu.account.ID << L"," << pHead->stu.account.Pass << std::endl;
		fout << pHead->stu.ID << L"," << pHead->stu.FirstName << L"," << pHead->stu.LastName << L"," << pHead->stu.Gender << L"," << pHead->stu.Birthday.Day << L"/" << pHead->stu.Birthday.Month << L"/" << pHead->stu.Birthday.Year << L"," << pHead->stu.SocialID << std::endl;
		pHead = pHead->pNext;
		fout.close();
	}
}

void Save_cla_to_test(Node_cla* pHead, char* folder) {
	wchar_t* file;
	while (pHead != nullptr) {
		file = Create_file_1( pHead->cla.Name, folder, ".txt");
		std::wofstream fout(file);
		fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
		fout << pHead->cla.Name << std::endl;
		fout << pHead->cla.StudentID << std::endl;
		pHead = pHead->pNext;
		fout.close();
	}
}

void Save_name_class(Node_cla* pHead) {
	Node_cla* pHead_1 = new Node_cla;
	Node_cla* pCur = pHead_1;
	std::wstring str;
	std::wifstream fin("Class.txt");
	if (!fin) {

	}
	else {
		fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t>));
		while (!fin.eof()) {
			pCur->pNext = new Node_cla;
			pCur->pNext->pPre = pCur;
			std::getline(fin, str);
			pCur->pNext->cla.Name = new wchar_t[str.length() + 1];
			str.copy(pCur->pNext->cla.Name, str.length(), 0);
			pCur->pNext->cla.Name[str.length()] = L'\0';
			pCur = pCur->pNext;
			pCur->pNext = nullptr;
		}
		if (pHead_1->pNext == nullptr) {
			delete pHead_1;
			pHead_1 = nullptr;
		}
		else {
			Node_cla* pTemp = pHead_1;
			pHead_1 = pHead_1->pNext;
			delete pTemp;
		}
	}
	fin.close();
	pCur = pHead_1;
	std::wofstream fout("Class.txt");
	fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
	while (pCur != nullptr) {
		fout << pCur->cla.Name << std::endl;
		pCur = pCur->pNext;
	}
	while (pHead != nullptr) {
		fout << pHead->cla.Name << std::endl;
		pHead = pHead->pNext;
	}
	fout.close();
	Delete_Node_cla(pHead_1);
}

void Save_cou_to_test(Node_cou* pHead, char* folder) {
	wchar_t* file;
	while (pHead != nullptr) {
		file = Create_file_1(pHead->cou.ID, folder, ".txt");
		std::wofstream fout(file);
		fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
		fout << pHead->cou.ID << L',' << pHead->cou.Name << L',' << pHead->cou.Teacher_Name << L',' << pHead->cou.Credit << L',' << pHead->cou.max_stu << L',' << pHead->cou.count << std::endl;
		fout << pHead->cou.ses_1.day_of_week << L',' << pHead->cou.ses_1.session << L',' << pHead->cou.ses_2.day_of_week << L',' << pHead->cou.ses_2.session << std::endl;
		fout << pHead->cou.StudentID << std::endl;
		pHead = pHead->pNext;
		fout.close();
	}
}
