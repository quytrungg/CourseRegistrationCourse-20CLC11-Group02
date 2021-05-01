#include"Function.h"

void makefoler()
{

	wchar_t* name = new wchar_t[] {L"Semester"};
	_wmkdir(name);
	delete[] name;
	//name = new wchar_t[] {L"Class"};
	std::wcin >> name;
	_wmkdir(name);
	//delete[] name;
	//name = new wchar_t[] {L"Score"};
	//_wmkdir(name);
	//delete[] name;
	//name = new wchar_t[] {L"Student"};
	//_wmkdir(name);
	//delete[] name;

}

//void accessToFile()