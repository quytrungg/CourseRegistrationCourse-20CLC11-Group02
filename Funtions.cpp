#include "Header.h"

void CreateDateTime(Date* d, Time* t)
{

}

void InputStudent(std::string path, NodeStudent* pHead)
{
	std::fstream fin;
	if (!fin) 
	{
		std::cout << "Can't open file!";
		return;
	}
	pHead = nullptr;
	NodeStudent* pCur = nullptr;
	fin.open(path + ".csv", std::fstream::in);
	while (fin.eof())
	{
		if (pHead == nullptr)
		{
			pHead = new NodeStudent;
			pCur = pHead;
		}
		fin >> pCur->data.no;
		std::getline(fin, pCur->data.id, ",");
		std::getline(fin, pCur->data.fname, ",");
		std::getline(fin, pCur->data.lname, ",");
		std::getline(fin, pCur->data.gender, ",");
		std::getline(fin, pCur->data.dob, ",");
		std::getline(fin, pCur->data.soid, ",");
		pCur->pNext = new NodeStudent;
		pCur = pCur->pNext;
	}
	fin.close();
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

void InputScore(std::string path, NodeScore* pHead)
{
	std::fstream fin;
	if (!fin)
	{

	}
}