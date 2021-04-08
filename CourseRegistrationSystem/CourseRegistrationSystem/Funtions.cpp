#include "Header.h"
#include "ExtraHeader.h"

//Thêm 1 class vào node (chưa rõ sẽ làm gì với nó)
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

//Hàm output class file (chưa rõ sẽ làm gì với nó)
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

//Hàm input student từ file csv
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

//Hàm thêm 1 student vào node
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

//Hàm input điểm từ csv
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

//Hàm xuất học sinh vào csv (chưa làm được tiếng việt có dấu)
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

//Hàm xuất bảng điểm vào csv
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


//Hàm tìm lớp
NodeClass* FindClass(std::string path, NodeClass* &pHead){
    NodeClass* pCur = pHead;
    while(pCur != nullptr){
        if(pCur->data.name == path){
            break;
        }
        else pCur = pCur->pNext;
    }
    return pCur;
}


//Hàm tìm 1 học sinh từ trong 1 file lớp theo id mssv
void FindStudent(std::string path, NodeStudent* &pHead){
    std::fstream fin;
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

//Chuyển từ string thành char để dùng trong binary file
char* StringToChar(std::string text){
    char* s;
    s = new char[text.length() + 1];
    for(int i = 0; i < text.length() + 1; i++){
        s[i] = text[i];
    }
    return s;
}
