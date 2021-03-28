#include "Header.h"
#include "ExtraHeader.h"

void SetDateTime(Date* d, Time* t)
{

}

void InputStudent(std::string path, NodeStudent*& pHead)
{
	std::fstream fin;
	if (!fin)
	{
		std::cout << "Can't open file!";
		return;
	}
	fin.open(path + ".csv", std::ios_base::in);
	fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
	pHead = nullptr;
	NodeStudent* pCur = nullptr;
	while (fin.eof())
	{
		if (pHead == nullptr)
		{
			pHead = new NodeStudent;
			pCur = pHead;
		}
		std::getline(fin, pCur->data.no, ',');
		std::getline(fin, pCur->data.id, ',');
		std::getline(fin, pCur->data.fname, ',');
		std::getline(fin, pCur->data.lname, ',');
		std::getline(fin, pCur->data.gender, ',');
		std::getline(fin, pCur->data.dob, ',');
		std::getline(fin, pCur->data.soid, ',');
		pCur->pNext = new NodeStudent;
		pCur = pCur->pNext;
	}
	fin.close();
}

void AddStudent(Student& stu, NodeStudent* pHead) {

}

void CreateSchoolyear() 
{

}

void CreateSemester()
{

}

void CreateCourse()
{

}

void InputScore(std::string path, NodeScore* &pHead)
{
	std::fstream fin;
	if (!fin)
	{
		std::cout << "Can't open file!";
		return;
	}
	fin.open(path + ".csv", std::ios_base::in);
	fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
	NodeScore* pCur = nullptr;
	pHead = nullptr;
	while (fin.eof())
	{
		if (pHead == nullptr) {
			pHead = new NodeScore;
			pCur = pHead;
		}
		fin >> pCur->data.total;
		fin >> pCur->data.final;
		fin >> pCur->data.midterm;
		fin >> pCur->data.other;
		fin >> pCur->data.gpa;
		fin >> pCur->data.ovrgpa;
		pCur->pNext = new NodeScore;
		pCur = pCur->pNext;
	}
	fin.close();
}

void OutputStudent(std::string path, NodeStudent* pHead)
{
	std::fstream fout;
	fout.open(path, std::ios_base::out);
	NodeStudent* pCur = pHead;
	while (pCur != nullptr)
	{
		fout << pCur->data.no << ",";
		fout << pCur->data.id << ",";
		fout << pCur->data.fname << ",";
		fout << pCur->data.lname << ",";
		fout << pCur->data.gender << ",";
		fout << pCur->data.soid << ",";
	}
	fout.close();
}

void OutputScore(std::string path, NodeScore* pHeead)
{
	std::fstream fout;
	fout.open(path, std::ios_base::out);
	NodeScore* pCur = pHeead;
	while (pCur != nullptr)
	{
		fout << pCur->data.total << ",";
		fout << pCur->data.final << ",";
		fout << pCur->data.midterm << ",";
		fout << pCur->data.other << ",";
		fout << pCur->data.gpa << ",";
		fout << pCur->data.ovrgpa << ",";
	}
	fout.close();
}