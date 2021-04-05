#include<iostream>
#include<fstream>
using namespace std;
int main() {
	ifstream in;
	in.open("input.txt");
	int a;
	in >> a;
	cout << a;
	in.close();
	in.open("input.txt");
	in >> a;
	cout << a;
	return 0;
}