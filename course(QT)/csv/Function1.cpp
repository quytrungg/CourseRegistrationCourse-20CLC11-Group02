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
    while(pCur->id == findid){
        if(pCur->id == findid){
            std::wcout << pCur->id << std::endl;
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
        if(pCur->id == findid){
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
    pHead->pNext = nullptr;
    pHead->pPrev = nullptr;
}

//Deallocate course
void DeleteCourse(course* &pHead){
    course* pTemp = pHead;
    while(pHead != nullptr){
        pHead = pHead->pNext;
        delete pTemp;
        pTemp = pHead;
    }
    pHead->pNext = nullptr;
    pHead->pPrev = nullptr;
}

//Input file staff_account.txt
void load_account(std::string path, account*& acc) {
    std::fstream fin;
    if(!fin){
        std::cout << "Can't open file!";
        return;
    }
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
    return pCur;
}

//Đổi pass cho account đó
void ChangePassword(account* &pHead){
    std::string newpass, temp;
    account* pNew = FindAccount(pHead);
    while(pNew == nullptr){
        std::cout << "Can't find your account, please enter again: ";
        pNew = FindAccount(pHead);
    }
    std::cout << "Enter your new password: ";
    std::cin >> newpass;
    std::cout << "Confirm your new password: ";
    std::cin >> temp;
    while(newpass != temp){
        std::cout << "Invalid password, please enter again: ";
        std::cin >> temp;
    }
    pNew->pass = newpass;
}

//Cập nhật password vào file txt
void SaveAccount(std::string path, account* &pHead){
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
void Enroll(std::string path, in4_student* &pHead1, course* &pHead2){
    course* pTemp = FindCourse(pHead2);
    in4_student* pCur = FindReturnStudent(path, pHead1);
    pCur->id_course = new id_course_of_student;
    pCur->id_course->id = pTemp->id;
    pCur->id_course->session = pTemp->session;
    pCur->id_course = pCur->id_course->pNext;
}

//Hàm dùng để huỷ đăng kí môn học đó trong idcourseofstudent
void UnEnroll(std::string path, in4_student* &pHead1, course* &pHead2){
    course* pTemp = FindCourse(pHead2);
    in4_student* pCur = FindReturnStudent(path, pHead1);
    in4_student* pTemp2 = pCur;
    while(pTemp2->id_course->pNext != nullptr){
        if(pTemp2->id_course->pNext->id == pTemp->id){
            id_course_of_student* pDel = pTemp2->id_course->pNext;
            pTemp2->id_course->pNext = pTemp2->id_course->pNext->pNext;
            delete pDel;
            return;
        }
        else pTemp2->id_course = pTemp2->id_course->pNext;
    }
    if(pCur->id_course->id == pTemp->id){
        id_course_of_student* pNew = pCur->id_course;
        pCur->id_course = pCur->id_course->pNext;
        delete pNew;
        return;
    }
}

void LoadCourse(std::string path, course* &pHead){
    std::wfstream fin;
    if(!fin){
        std::cout << "Can't open file!";
        return;
    }
    fin.open(path);
    course* pCur = nullptr;
    while(!fin.eof()){
        if(pHead == nullptr){
            pHead = new course;
            fin >> pHead->id;// >> pHead->session;
            pHead->pNext = pHead->pPrev = nullptr;
            pCur = pHead;
        }
        else{
            pCur->pNext = new course;
            pCur->pNext->pPrev = pCur;
            pCur = pCur->pNext;
            fin >> pCur->id;// >> pCur->session;
            pCur->pNext = nullptr;
        }
    }
    fin.close();
}


//Menu dùng để đăng kí môn học
void CourseMenu(std::string path, in4_student* &pHead1, course* &pHead2){
    int option;
    std::cout << "1. Enroll course\n" << "0. Exit\n";
    std::cout << "Choose your option: ";
    std::cin >> option;
    while(option == 1){
        switch (option) {
            case 1:{
                std::cout << "Choose your course: ";
                //loadcoursefile
                course* pCur = FindCourse(pHead2);
                Enroll(path, pHead1, pCur);
                //savecoursetostudentfile
                break;
            }
            default:
                break;
        }
        std::cout << "Choose your option: ";
        std::cin >> option;
    }
}

//Delete Student
void DeallocateStudent(in4_student* &pHead){
    in4_student* pTemp = pHead;
    while(pHead != nullptr){
        pHead = pHead->pNext;
        delete pTemp;
        pTemp = pHead;
    }
}

//Delete id course of student
void DeallocateCourseOfStudent(id_course_of_student* &pHead){
    id_course_of_student* pTemp = pHead;
    while(pHead != nullptr){
        pHead = pHead->pNext;
        delete pTemp;
        pTemp = pHead;
    }
}

//Delete Score
void DeallocateScore(Score* &pHead){
    Score* pTemp = pHead;
    while(pHead != nullptr){
        pHead = pHead->pNext;
        delete pTemp;
        pTemp = pHead;
    }
}

//Kiểm tra số lương môn học đăng kí có vượt quá 5 không
bool CheckCourseQuantity(in4_student* &pHead){
    in4_student* pCur = pHead;
    int temp = 0;
    while(pCur != nullptr){
        temp++;
        pCur = pCur->pNext;
    }
    if(temp > 5) return false;
    return true;
}

//Kiểm tra xem giờ học có bị trùng nhau không
bool CheckConflictedEnroll(course* &pHead1, id_course_of_student* &pHead2){
    char m[6], n[6], p[6], q[6];
    pHead1->session.copy(m, 5);
    pHead1->session.copy(n, 5, '_' + 1);
    pHead2->session.copy(p, 5);
    pHead2->session.copy(q, 5, '_' + 1);
    if(!strcmp(m, p) or !strcmp(m, q) or !strcmp(n, p) or !strcmp(n, q)) return true;
    return false;
}

//Kiểm tra xem môn học đó đã đủ học sinh chưa
bool CheckStudentQuantity(course* &pHead){
    course* pTemp = FindCourse(pHead);
    return pTemp->count <= 50;
}

//Kiểm tra toàn bộ điều kiện để đăng kí môn học
bool CheckConflictedCourse(course* &pHead1, in4_student* &pHead2){
    in4_student* pCur = pHead2;
    if(!CheckStudentQuantity(pHead1) and CheckCourseQuantity(pHead2)) return false;
    while(pCur != nullptr){
        if(CheckConflictedEnroll(pHead1, pCur->id_course)){
            return false;
        }
        else pCur->id_course = pCur->id_course->pNext;
    }
    return true;
}

/*
//Load file course.txt
void LoadCourse(std::string path, course*& pHead) {
    std::wfstream fin;
    if (!fin) {
        std::cout << "Can't open file!";
        return;
    }
    fin.open(path, std::wfstream::in);
    ReadVietnamese();
    pHead = nullptr;
    course* pCur = nullptr;
    while (!fin.eof()) {
        if (pHead == nullptr) {
            pHead = new course;
            pCur = pHead;
        }
        else {
            pCur->pNext = new course;
            pCur = pCur->pNext;
        }
        fin >> pCur->id >> L"," >> pCur->name >> L"," >> pCur->teacher_name >> L"," >> pCur->num_cre >> L"," >> pCur->count >> L"," >> pCur->session >> L",";

    }
}
*/
