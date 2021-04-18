#include "Struct.h"
#include "Time.h"
#include "Help.h"
#include "Save.h"

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
	}
}

