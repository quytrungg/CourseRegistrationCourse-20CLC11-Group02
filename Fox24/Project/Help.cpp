#include "Struct.h"
#include "Time.h"
#include "Help.h"

int Convert_wchart_to_int(wchar_t* a, int n) {
	int m = 0;
	int p;
	for (int i = 0; i < n; i++) {
		p = a[i] - L'0';
		m = m * 10 + p;
	}
	return m;
}

int Convert_char_to_int(char* a, int n)
{
	int m = 0;
	int p;
	for (int i = 0; i < n; i++) {
		p = a[i] - L'0';
		m = m * 10 + p;
	}
	return m;
}

char* Convert_int_to_char(int n) {
	int count = 0;
	for (int i = n; i > 0; i = i / 10) {
		count++;
	}
	char* a = new char[count + 1];
	int r;
	for (int i = 0; i < count; i++) {
		r = n % 10;
		n = n / 10;
		a[count - 1 - i] = r + '0';
	}
	a[count] = '\0';
	return a;
}

