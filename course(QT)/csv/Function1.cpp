//
//  Function1.cpp
//  csv
//
//  Created by Mai Quý Trung on 31/03/2021.
//

#include "Function1.h"
#include "Funciton2.h"

//Class
//Thêm dữ liệu vào class.txt
void AddClass(id_class* &pHead){
    int option;
    std::cout << "1. Add class" << std::endl;
    std::cin >> option;
    if(option == 1){
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
    else return;
}

//Xuất dữ liệu vào class.txt
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

void InputStudent(std::string path, NodeStudent* &pHead){
    std::fstream fin;
    //NodeStudent* pCur = pHead;
    if(!fin){
        std::cout << "Can't open file!" << std::endl;
        return;
    }
    fin.open(path, std::fstream::in);
    while(!fin.ios_base::eof()){
        
    }
}

void OutputStudent(std::string path, NodeStudent* pHead){
    std::fstream fout;
    fout.open(path, std::fstream::out);
    NodeStudent* pCur = pHead;
    while(pCur != nullptr){
        
    }
}
*/

//Tìm lớp trong file class.txt
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

//Tìm student bằng cách mở file student.txt rồi tìm theo id và xuất ra thông tin trên console
void FindStudent(std::string path, in4_student* &pHead){
    std::fstream fin;
    fin.open(path, std::fstream::in);
    std::wstring findid;
    std::wcin >> findid;
    in4_student* pCur = pHead;
    while(comparei(pCur->id, findid)){
        if(pCur->id == find){
            std::cout << pCur->id << std::endl;
            std::wcout << pCur->fname << std::endl;
            std::wcout << pCur->lname << std::endl;
            std::wcout << pCur->gender << std::endl;
            std::wcout << pCur->dob << std::endl;
            std::cout << pCur->soid << std::endl;
            std::wcout << pCur->id_class << std::endl;
            while(pCur->id_course != nullptr){
                std::wcout << pCur->id_course->id << std::endl;
                pCur->id_course = pCur->id_course->pNext;
            }
            return;
        }
        else pCur = pCur->pNext;
    }
    fin.close();
}

//Tìm student trong file csv rồi trả về node in4student
in4_student* FindReturnStudent(std::string path, in4_student* &pHead){
    std::fstream fin;
    fin.open(path, std::fstream::in);
    std::wstring findid;
    std::wcin >> findid;
    in4_student* pCur = pHead;
    while(pCur != nullptr){
        if(comparei(pCur->id, findid)){
            break;
        }
        else pCur = pCur->pNext;
    }
    fin.close();
    return pCur;
}

//Đọc file class.txt
void LoadClass(std::string path, id_class* &pHead){
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

//Menu chọn lớp cho student
void ChooseClass(id_class* &pHead){
    int option, count = 1;
    std::string path;
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
    std::cin >> path;
}

//Kiểm tra xem 2 course session có bị trùng không
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

//Lấy năm học của class bằng cách lấy 2 chữ số đầu
int GetClassYear(id_class &a){
    char s[3];
    a.id.copy(s, 2);
    std::stringstream geek(s);
    int x = 0;
    geek >> x;
    return x;
}

//Deallocate class
void DeleteClass(id_class* &pHead){
    id_class* pTemp = pHead;
    while(pHead != nullptr){
        pHead = pHead->pNext;
        delete pTemp;
        pTemp = pHead;
    }
}

//Deallocate course
void DeleteCourse(course* &pHead){
    course* pTemp = pHead;
    while(pHead != nullptr){
        pHead = pHead->pNext;
        delete pTemp;
        pTemp = pHead;
    }
}

//Input file staff_account.txt
void load_account(std::string path, account*& acc) {
    std::fstream fin;
    fin.open(path);
    account* pCur = 0;
    while (!fin.eof()) {
        if (acc == 0) {
            acc = new account;
            fin >> acc->account_name >> acc->pass;
            acc->pNext = acc->pPrev = nullptr;
            pCur = acc;
        }
        else {
            pCur->pNext = new account;
            pCur->pNext->pPrev = pCur;
            pCur = pCur->pNext;
            fin >> pCur->account_name >> pCur->pass;
            pCur->pNext = nullptr;
        }
    }
    fin.close();
}

//In ra màn hình console file staff_account.txt
void PrintAccount(account* pHead){
    account* pCur = pHead;
    while(pCur != nullptr){
        std::cout << pCur->account_name << " ";
        std::cout << pCur->pass << " ";
        pCur = pCur->pNext;
        std::cout << std::endl;
    }
}

//Deallocate account
void DeallocateAccount(account* &pHead){
    account* pTemp = pHead;
    while(pHead != nullptr){
        pHead = pHead->pNext;
        delete pTemp;
        pTemp = pHead;
    }
}

//Tìm account cần đổi pass
account* FindAccount(account* &pHead){
    account* pCur = pHead;
    std::string finduser;
    std::cin >> finduser;
    while(pCur != nullptr){
        if(pCur->account_name == finduser){
            break;;
        }
        pCur = pCur->pNext;
    }
    //if(pCur == nullptr){
        //std::cout << "Can't find your account, please type again!" << std::endl;
        //FindAccount(pHead);
    //}
    return pCur;
}

//Đổi pass cho account đó
void ChangePassword(account* &pHead){
    account* pCur = FindAccount(pHead);
    std::string newpass;
    std::cout << "Enter your new password: ";
    std::cin >> newpass;
    pCur->pass = newpass;
}

//Cập nhật password vào file txt
void SaveAccout(std::string path, account* &pHead){
    std::fstream fout;
    if(!fout){
        std::cout << "Can't open file!";
        return;
    }
    fout.open(path, std::fstream::out);
    account* pCur = pHead;
    while(pCur != nullptr){
        fout << pCur->account_name << " ";
        fout << pCur->pass << std::endl;
        pCur = pCur->pNext;
    }
    fout.close();
}

//tìm course trong file course để đăng kí môn học cho stu
course* FindCourse(course* &pHead){
    course* pCur = pHead;
    std::wstring findcourseid;
    std::wcin >> findcourseid;
    while(pCur != nullptr){
        if(pCur->id == findcourseid){
            break;
        }
        pCur = pCur->pNext;
    }
    return pCur;
}
 
//Hàm để gán course stu đã đăng kí vào idcourseofstudent
void EnrollCourse(std::string path, in4_student* &pHead1, course* &pHead2){
    course* pTemp = FindCourse(pHead2);
    in4_student* pCur = FindReturnStudent(path, pHead1);
    pCur->id_course->id = pTemp->id;
}

void CourseMenu(std::string path, in4_student* &pHead1, course* &pHead2){
    int option;
    std::cout << "1. Enroll course\n" << "0. Exit\n";
    std::cout << "Choose your option: ";
    std::cin >> option;
    while(option == 1){
        switch (option) {
            case 1:{
                std::cout << "Choose your course: ";
                course* pCur = FindCourse(pHead2);
                EnrollCourse(path, pHead1, pCur);
                break;
            }
            default:
                break;
        }
        std::cout << "Choose your option: ";
        std::cin >> option;
    }
}

