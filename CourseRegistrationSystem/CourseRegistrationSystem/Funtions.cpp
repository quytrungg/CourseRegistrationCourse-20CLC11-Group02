#include "Header.h"
#include "ExtraHeader.h"

//Thêm 1 class vào node và lưu nó lại
void AddClass(id_class* &pHead){
    std::cout << "Press E to exit" << std::endl;
    pHead = nullptr;
    id_class* pCur = nullptr;
    std::string info;
    std::cin >> info;
    while(info != "E"){
        if(pHead == nullptr){
            pHead = new id_class;
            pCur = pHead;
        }
        else{
            pCur->pNext = new id_class;
            pCur->pNext->pPrev = pCur;
            pCur = pCur-> pNext;
        }
        pCur->id = info;
        pCur->pNext = nullptr;
        std::cin >> info;
    }
}

//Hàm output class file vào txt
void OutputClassFile(std::string path, id_class* pHead){
    std::fstream fout;
    fout.open(path, std::fstream::out);
    if(pHead == nullptr) return;
    id_class* pCur = pHead;
    while(pCur != nullptr){
        fout << pCur->id << std::endl;
        pCur = pCur->pNext;
    }
    fout.close();
}
/*
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
		fin >> pCur->data.total >> ',';
		fin >> pCur->data.final >> ',';
		fin >> pCur->data.midterm >> ',';
		fin >> pCur->data.other >> ',';
		fin >> pCur->data.gpa >> ',';
		fin >> pCur->data.ovrgpa >> ',';
		pCur->pNext = new NodeScore >> ',';
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
void OutputScore(std::string path, Score* pHead)
{
	std::fstream fout;
	fout.open(path, std::ios_base::out);
	Score* pCur = pHead;
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
*/

//Hàm tìm lớp
id_class* FindClass(std::string path, id_class* &pHead){
    id_class* pCur = pHead;
    while(pCur != nullptr){
        if(pCur->id == path){
            break;
        }
        else pCur = pCur->pNext;
    }
    return pCur;
}


//Hàm tìm 1 học sinh từ trong 1 file lớp theo id mssv
void FindStudent(std::string path, in4_student* &pHead){
    std::fstream fin;
    fin.open(path, std::fstream::in);
    std::string findid;
    std::cin >> findid;
    std::stringstream geek(findid);
    int find;
    geek >> find;
    in4_student* pCur = pHead;
    while(pCur != nullptr){
        if(pCur->id == find){
            std::cout << pCur->id << std::endl;
            std::wcout << pCur->fname << std::endl;
            std::wcout << pCur->lname << std::endl;
            std::cout << pCur->gender << std::endl;
            std::cout << pCur->dob << std::endl;
            std::cout << pCur->soid << std::endl;
            return;
        }
        else pCur = pCur->pNext;
    }
}

//Lấy danh sách lớp học từ file txt
void InputClassList(std::string path, id_class* &pHead){
    std::fstream fin;
    std::cin >> path;
    if(!fin){
        std::cout << "Can't open file!" << std::endl;
        return;
    }
    fin.open(path, std::fstream::in);
    id_class* pCur = pHead;
    while(pCur != nullptr){
        fin >> pCur->id;
        pCur = pCur->pNext;
    }
    fin.close();
}

//Làm menu để người dùng chọn lớp để import danh sách sinh viên
void MenuClassList(id_class* &pHead){
    int option, count = 1;
    id_class* pCur = pHead;
    while(pCur != nullptr){
        std::cout << count << ". " << pCur->id << std::endl;
        count++;
        pCur = pCur->pNext;
    }
    std::wcout << L"Chon lop cua ban: ";
    std::cin >> option;
    std::wcout << L"Ban chon: " << option << std::endl;
    id_class* pTemp = pHead;
    for(int i = 1; i < option; i++){
        pTemp = pTemp->pNext;
    }
    std::cout << "Nhap ten file cua lop " << pTemp->id << ": " << std::endl;
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

//Kiểm tra xem 2 course session có bị trùng nhau hay ko
bool check_conflicted_course(course &a, course &b){
    char m[6], n[6], p[6], q[6];
    std::cin >> a.session;
    std::cin >> b.session;
    a.session.copy(m, 5);
    a.session.copy(n, 5, '_' + 1);
    b.session.copy(p, 5);
    b.session.copy(q, 5, '_' + 1);
    if(!strcmp(m, n) or !strcmp(m, p) or !strcmp(m, q) or !strcmp(n, p) or !strcmp(n, q) or !strcmp(p, q)){
        return true;
    }
    return false;
}

//Lấy khoá của sinh viên từ tên lớp
int GetClassYear(id_class &a){
    char s[3];
    a.id.copy(s, 2);
    std::stringstream geek(s);
    int x = 0;
    geek >> x;
    return x;
}
