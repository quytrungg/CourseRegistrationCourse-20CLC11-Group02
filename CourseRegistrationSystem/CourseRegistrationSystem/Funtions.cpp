#include "Header.h"
#include "ExtraHeader.h"

void AddClass(NodeClass* &pHead){
    std::cout << "Press E to exit" << std::endl;
    pHead = nullptr;
    NodeClass* pCur = nullptr;
    std::string info;
    std::cin >> info;
    while(info != "E"){
        if(pHead == nullptr){
            pHead = new NodeClass;
            pCur = pHead;
        }
        else{
            pCur->pNext = new NodeClass;
            pCur = pCur-> pNext;
        }
        pCur->data.name = info;
        std::cin >> info;
    }
}

void OutputClassFile(std::string path, NodeClass* pHead){
    std::fstream fout;
    fout.open(path, std::fstream::out);
    NodeClass* pCur = pHead;
    while(pCur != nullptr){
        fout << pCur->data.name << std::endl;
        pCur = pCur->pNext;
    }
    fout.close();
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

void AddStudent(NodeStudent* &pHead, Student &info){
    NodeStudent* pCur = nullptr;
    if(pHead == nullptr){
        pHead = new NodeStudent;
        pCur = pHead;
    }
    else{
        pCur->pNext = new NodeStudent;
        pCur->pNext->pPrev = pCur;
        pCur = pCur->pNext;
    }
    pCur->data = info;
    pCur->pNext = nullptr;
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

void FindStudent(std::string path, NodeStudent* &pHead){
    std::fstream fin;
    std::cin >> path;
    fin.open(path, std::fstream::in);
    std::string findid;
    std::cin >> findid;
    std::stringstream geek(findid);
    int find;
    geek >> find;
    NodeStudent* pCur = pHead;
    while(pCur != nullptr){
        if(pCur->data.id == find){
            std::cout << pCur->data.no << std::endl;
            std::cout << pCur->data.id << std::endl;
            std::cout << pCur->data.fname << std::endl;
            std::cout << pCur->data.lname << std::endl;
            std::cout << pCur->data.gender << std::endl;
            std::cout << pCur->data.dob << std::endl;
            std::cout << pCur->data.soid << std::endl;
            return;
        }
        else pCur = pCur->pNext;
    }
}
