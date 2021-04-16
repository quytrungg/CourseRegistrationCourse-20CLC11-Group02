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
	third_folder[n - 1] = '\0';
	return third_folder;
}

void Create_main_folder() {
	Time current_time;
	Get_current_time_to_int(current_time);
	char* current_year = Convert_int_to_char(current_time.date.Year);
	_mkdir(current_year);
	_mkdir(Create_second_folder("Student", current_year));
	_mkdir(Create_second_folder("Semester", current_year));
	_mkdir(Create_second_folder("Class", current_year));
	_mkdir(Create_third_folder("1", Create_second_folder("Semester", current_year)));
}

void main() {
	Create_main_folder();
}