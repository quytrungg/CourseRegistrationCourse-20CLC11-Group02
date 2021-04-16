//
//  Function1.cpp
//  csv
//
//  Created by Mai Quý Trung on 31/03/2021.
//

#include "Function1.h"
#include "Funciton2.h"

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
            std::cout << pCur->gender << std::endl;
            std::cout << pCur->dob << std::endl;
            std::cout << pCur->soid << std::endl;
            return;
        }
        else pCur = pCur->pNext;
    }
}

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

void MenuClassList(id_class* &pHead){
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

char* StringToChar(std::string text){
    char* s;
    s = new char[text.length() + 1];
    for(int i = 0; i < text.length() + 1; i++){
        s[i] = text[i];
    }
    return s;
}

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

int GetClassYear(id_class &a){
    char s[3];
    a.id.copy(s, 2);
    std::stringstream geek(s);
    int x = 0;
    geek >> x;
    return x;
}

void DeleteClass(id_class* &pHead){
    id_class* pTemp = pHead;
    while(pHead != nullptr){
        pHead = pHead->pNext;
        delete pTemp;
        pTemp = pHead;
    }
}

void DeleteCourse(course* &pHead){
    course* pTemp = pHead;
    while(pHead != nullptr){
        pHead = pHead->pNext;
        delete pTemp;
        pTemp = pHead;
    }
}

void InputCourseCSV(course* &pHead){
    
}

void OutputCourseCSV(course* &pHead){
    
}

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
    return pCur;
}

void ChangePassword(account* &pHead){
    account* pCur = FindAccount(pHead);
    std::string newpass;
    std::cout << "Enter your new password: ";
    std::cin >> newpass;
    pCur->pass = newpass;
}

