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
in4_student* FindReturnStudent(std::string path, in4_student* &pHead){//, account* &pHead2){
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
        else pCur = pCur->pNext;
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

//UpdateCourseToStudentFile

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
            fin >> pCur->id >> pCur->teacher_name;// >> pCur->session;
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

//Thêm 1 course vào linked list
void AddCourse(course*& cou, course temp) {
    cou->id = temp.id;
    cou->name = temp.name;
    cou->teacher_name = temp.teacher_name;
    cou->num_cre = temp.num_cre;
    cou->max_student = temp.max_student;
    cou->session = temp.session;
    cou->pNext = new course;
    cou->pNext->pPrev = cou;
    cou = cou->pNext;
}

//Lọc data từ file
course ChangeToData(std::wstring line) {
    course cou;
    int start = line.find(L',', 0) + 1;
    int end = line.find(L',', start);

    wchar_t* temp = new wchar_t[end - start + 1];
    temp[end - start] = L'\0';
    line.copy(temp, end - start, start);
    cou.id = ChangeStringToInt(temp);
    delete[] temp;
    
    start = end + 1;
    end = line.find(L',', start);
    cou.name = new wchar_t[end - start + 1];
    cou.name[end - start] = L'\0';
    //line.copy(cou.name, end - start, start);

    start = end + 1;
    end = line.find(L',', start);
    cou.teacher_name = new wchar_t[end - start + 1];
    cou.teacher_name[end - start] = L'\0';
    //line.copy(cou.teacher_name, end - , start);

    start = end + 1;
    end = line.find(L',', start);
    cou.num_cre = new wchar_t[end - start + 1];
    cou.num_cre[end - start] = L'\0';
    //line.copy(cou.num_cre, end - start, start);

    start = end + 1;
    end = line.find(L',', start);
    temp = new wchar_t[end - start + 1];
    temp[end - start] = L'\0';
    cou.max_student = ChangeStringToInt(temp);
    delete[] temp;

    start = end + 1;
    end = line.find(L',', start);
    //replace = StringToWString(temp, cou.session);

    return cou;
}

//Lấy data từ file
course* InputCourse(course*& pHead, std::wfstream& fin) {
    if (!fin) {
        std::cout << "Can't open file!";
    }
    fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf8_utf16<wchar_t>));
    std::wstring temp;
    while (!fin.eof()) {
        ChangeToVietnamese();
        std::getline(fin, temp);
        if (temp.length() != 0) AddCourse(pHead, ChangeToData(temp));
    }
    return pHead;
}

//Reverse Course List
void ReverseTheList(course*& pHead) {
    course* pCur1 = nullptr;
    course* pCur2 = pHead;
    course* pCur3 = pHead->pPrev;

    while (pCur2 != nullptr) {
        pCur2->pPrev = pCur1;
        pCur1 = pCur2;
        pCur2 = pCur3;
        if (pCur3 != nullptr) {
            pCur3 = pCur3->pPrev;
        }
    }
    pHead = pCur1;
}

//Output Course to console and file
void PrintCourse(course* data, std::string path) {
    ChangeToVietnamese();

    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    std::wfstream fout;
    fout.open(path, std::wfstream::out);
    fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8_utf16<wchar_t>));
    fout << wchar_t(0xfeff);

    course* temp = data;
    data = data->pNext;
    delete temp;
    course* cur = data;

    ReverseTheList(data);

    while (cur != nullptr) {
        std::wcout << cur->id;
        std::wcout << " " << cur->name;
        std::wcout << std::setw(10) << cur->teacher_name;
        std::wcout << std::setw(10) << cur->num_cre;
        std::wcout << " " << cur->max_student;
        std::cout << std::setw(8) << cur->session << "\n";
        fout << cur->id << L',' << cur->name << L',' << cur->teacher_name << L',' << cur->num_cre << L',' << cur->max_student << L','; //<< cur->session << L',';
        cur = cur->pNext;
    }

    fout.close();
    _setmode(_fileno(stdin), _O_TEXT);
    _setmode(_fileno(stdout), _O_TEXT);
}

//Tìm học sinh theo lớp
bool FindStudentClass(in4_student*& pHead, std::wstring find) {
    in4_student* pCur = pHead;
    while (pCur != nullptr) {
        if (pCur->id_class == find) {
            return true;
        }
        else pCur = pCur->pNext;
    }
    return false;
}

//Reverse Student List
void ReverseTheList(in4_student*& pHead) {
    in4_student* pCur1 = nullptr;
    in4_student* pCur2 = pHead;
    in4_student* pCur3 = pHead->pPrev;

    while (pCur2 != nullptr) {
        pCur2->pPrev = pCur1;
        pCur1 = pCur2;
        pCur2 = pCur3;
        if (pCur3 != nullptr) {
            pCur3 = pCur3->pPrev;
        }
    }
    pHead = pCur1;
}

//In ra student theo class vào file
void PrintStudentClass(in4_student* pHead, std::string path) {
    ChangeToVietnamese();

    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    std::wfstream fout;
    if (!fout) {
        std::cout << "Can't open file!";
        return;
    }
    fout.open(path, std::wfstream::out);
    fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8_utf16<wchar_t>));
    fout << wchar_t(0xfeff);

    std::wstring find;
    std::wcin >> find;

    in4_student* temp = pHead;
    pHead = pHead->pNext;
    delete temp;
    in4_student* pCur = pHead;

    ReverseTheList(pHead);

    while (pCur != nullptr) {
        if (pCur->id_class == find) {
            std::wcout << pCur->id;
            std::wcout << "  " << pCur->fname;
            const wchar_t* fname = pCur->fname.c_str();
            std::wcout << std::setw(27 - wcslen(fname)) << pCur->lname;
            std::wcout << std::setw(8) << pCur->gender;
            std::wcout << "   " << pCur->dob;
            std::wcout << std::setw(8) << pCur->soid << "\n";
        }
        else pCur = pCur->pNext;
    }

    fout.close();
    _setmode(_fileno(stdin), _O_TEXT);
    _setmode(_fileno(stdout), _O_TEXT);
}

//0 lên,1 xuống,2 trái,3 phải,4 enter, 5 backspace
int getTheMove_enter() {
    int _COMMAND, _COMMAND2;
    _COMMAND = toupper(_getwch());
    _COMMAND2 = (_COMMAND == 224 ? toupper(_getwch()) : 0);
    if (_COMMAND == 224 && _COMMAND2 == 75) return 2;
    else if (_COMMAND == 224 && _COMMAND2 == 72) return 0;
    else if (_COMMAND == 224 && _COMMAND2 == 80) return 1;
    else if (_COMMAND == 224 && _COMMAND2 == 77) return 3;
    else if (_COMMAND == 13) return 4;
    else if (_COMMAND == 8) return 5;
    return -1;
}

//Chọn menu theo Doubly Linked List
int ChooseMenu(MenuList* pHead, int x, int y, int n) {
    MenuList* pCur = pHead;
    int i = 0;
    n = 0;
    while (pCur != nullptr) {
        GotoXY(x + 2, y + i);
        std::wcout << pCur->option;
        i++;
        n++;
        pCur = pCur->pNext;
    }
    i = 0;
    GotoXY(x, y + i);
    std::wcout << "->";
    int move = -1;
    while (move != 5) {
        move = getTheMove_enter();
        if (!((move > 1 && move < 5) || (i == 0 && move == 0) || (i == n - 1 && move == 1))) {
            GotoXY(x, y + i); std::wcout << " ";
            if (move == 0) i--;
            if (move == 1) i++;
            GotoXY(x, y + i); std::wcout << "->";
        }
    }
    system("cls");
    return i + 1;
}

//Tìm student theo Score để sửa điểm
Score* FindStudentScore(Score*& pHead1, in4_student*& pHead2, std::string path) {
    in4_student* pFind = FindReturnStudent(path, pHead2);
    Score* pCur = pHead1;
    while (pCur != nullptr) {
        if (pCur->id == pFind->id) {
            break;
        }
        else pCur = pCur->pNext;
    }
    return pCur;
}

//Sửa điểm cho studnet
void ChangeScore(Score*& pHead1, in4_student* &pHead2, std::string path) {
    std::wstring newtotalscore, newmidterm, newfinal, newother, newgpa, newovrgpa;
    std::wcin >> newtotalscore >> newmidterm >> newfinal >> newother >> newgpa >> newovrgpa;
    const wchar_t* n1 = newtotalscore.c_str();
    const wchar_t* n2 = newmidterm.c_str();
    const wchar_t* n3 = newfinal.c_str();
    const wchar_t* n4 = newother.c_str();
    const wchar_t* n5 = newgpa.c_str();
    const wchar_t* n6 = newovrgpa.c_str();
    Score* pCur = FindStudentScore(pHead1, pHead2, path);
    pCur->totalScore = (wchar_t*)n1;
    pCur->midterm = (wchar_t*)n2;
    pCur->final = (wchar_t*)n3;
    pCur->other = (wchar_t*)n4;
    pCur->gpa = (wchar_t*)n5;
    pCur->ovrgpa = (wchar_t*)n6;
}

//Reverse list để xuất điểm cho Student
void ReverseTheList(Score*& pHead) {
    Score* pCur1 = nullptr;
    Score* pCur2 = pHead;
    Score* pCur3 = pHead->pPrev;

    while (pCur2 != nullptr) {
        pCur2->pPrev = pCur1;
        pCur1 = pCur2;
        pCur2 = pCur3;
        if (pCur3 != nullptr) {
            pCur3 = pCur3->pPrev;
        }
    }
    pHead = pCur1;
}

//Hàm update điểm cho Student vào file
void UpdateScore(Score*& pHead, std::string path) {
    ChangeToVietnamese();

    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    std::wfstream fout;
    fout.open(path, std::wfstream::out);
    fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8_utf16<wchar_t>));
    fout << wchar_t(0xfeff);

    Score* temp = pHead;
    pHead = pHead->pNext;
    delete temp;
    Score* pCur = pHead;

    ReverseTheList(pHead);

    while (pCur != nullptr) {
        std::wcout << pCur->totalScore;
        std::wcout << " " << pCur->midterm;
        std::wcout << std::setw(27 - wcslen(pCur->midterm)) << pCur->final;
        std::wcout << std::setw(8) << pCur->other;
        std::wcout << "   " << pCur->gpa;
        std::wcout << std::setw(8) << pCur->ovrgpa<< "\n";
        pCur = pCur->pNext;
    }
    fout.close();
    _setmode(_fileno(stdin), _O_TEXT);
    _setmode(_fileno(stdout), _O_TEXT);
}

//Tìm điểm của student để xuất ra console
void FindScore(Score*& pHead1, in4_student*& pHead2, std::string path) {
    in4_student* pFind = FindReturnStudent(path, pHead2);
    Score* pCur = pHead1;
    while (pCur != nullptr) {
        if (pCur->id == pFind->id) {
            std::wcout << " " << pCur->midterm;
            std::wcout << std::setw(27 - wcslen(pCur->midterm)) << pCur->final;
            std::wcout << std::setw(8) << pCur->other;
            std::wcout << "   " << pCur->gpa;
            std::wcout << std::setw(8) << pCur->ovrgpa << "\n";
            return;
        }
        else pCur = pCur->pNext;
    }
}

//In ra điểm của Student lên console
void PrintStudentScore(Score*& pHead1, in4_student*& pHead2, std::string path) {
    ChangeToVietnamese();

    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    std::wfstream fout;
    fout.open(path, std::wfstream::out);
    fout.imbue(std::locale(fout.getloc(), new std::codecvt_utf8_utf16<wchar_t>));

    Score* temp = pHead1;
    pHead1 = pHead1->pNext;
    delete temp;

    Score* pCur1 = pHead1;
    in4_student* pCur2 = pHead2;

    ReverseTheList(pHead1);
    ReverseTheList(pHead2);

    std::wstring find;
    std::wcin >> find;

    while (pCur2 != nullptr) {
        if (pCur2->id_class == find) {
            FindScore(pHead1, pHead2, path);
        }
        else pCur2 = pCur2->pNext;
    }

    fout.close();

    _setmode(_fileno(stdin), _O_TEXT);
    _setmode(_fileno(stdout), _O_TEXT);
}

//In ra bảng điểm của student theo course
void PrintScoreboardCourse(in4_student* &pHead1, Score* &pHead2, course* pHead3, std::string path) {
    ChangeToVietnamese();

    Score* pTemp1 = FindStudentScore(pHead2, pHead1, path);
    course* pTemp2 = FindCourse(pHead3);
    in4_student* pCur = pHead1;
    while (pCur != nullptr) {
        if (pCur->id_course->id == pTemp2->id) {
            FindScore(pHead2, pHead1, path);
        }
        pCur = pCur->pNext;
    }
    if (pCur == nullptr) {
        return;
    }
}

void AddCourse(course*& pHead) {
    course* pCur = pHead;
    while (pCur->pNext != nullptr) {
        pCur = pCur->pNext;
    }
    course* pNew = new course;
    ChangeToVietnamese();
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    std::wcin >> pNew->id;
    std::getline(std::wcin, pNew->name);
    std::getline(std::wcin, pNew->teacher_name);
    std::wcin >> pNew->max_student;
    std::wcin >> pNew->num_cre;
    std::cin >> pNew->session;

    pCur->pNext = pNew;
    pCur->pNext->pPrev = pCur;
    pNew->pNext = nullptr;

    _setmode(_fileno(stdin), _O_TEXT);
    _setmode(_fileno(stdout), _O_TEXT);
}

void AddMoreClass(id_class*& pHead) {
    id_class* pCur = pHead;
    while (pCur->pNext != nullptr) {
        pCur = pCur->pNext;
    }
    id_class* pNew = new id_class;
    ChangeToVietnamese();
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    std::cin >> pNew->id;

    pCur->pNext = pNew;
    pCur->pNext->pPrev = pCur;
    pNew->pNext = nullptr;

    _setmode(_fileno(stdin), _O_TEXT);
    _setmode(_fileno(stdout), _O_TEXT);
}

void PrintStudentInCourseOnConsole(course*& pHead1, in4_student*& pHead2, std::string path) {
    course* pCur1 = pHead1;
    in4_student* pCur2 = pHead2;
    ChangeToVietnamese();
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    std::wstring temp;
    std::wstring id;
    std::getline(std::wcin, temp);
    while (pCur1 != nullptr) {
        if (pCur1->name == temp) {
            id = pCur1->id;
            break;
        }
        else pCur1 = pCur1->pNext;
    }

    while (pCur2 != nullptr) {
        if (pCur2->id_course->id == id) {
            std::wcout << pCur2->id;
            std::wcout << std::setw(10) << pCur2->fname << " ";
            std::wcout << pCur2->lname;
        }
        pCur2 = pCur2->pNext;
    }

    _setmode(_fileno(stdin), _O_TEXT);
    _setmode(_fileno(stdout), _O_TEXT);
}

void Exit() {
    exit(0);
}

void ClearScreen() {
    system("cls");
}

void EditScoreFile(Score*& pHead1, in4_student*& pHead2, std::string path) {
    Score* pCur1 = pHead1;
    in4_student* pCur2 = pHead2;
    std::fstream f;
    if (!f) {
        std::cout << "Can't open file!";
        return;
    }
    f.open(path, std::fstream::in);
    f.imbue(std::locale(f.getloc(), new std::codecvt_utf8_utf16<wchar_t>));

    while (pCur1 != nullptr) {
        pCur1 = pCur1->pNext;
    }

    while (pCur2 != nullptr) {
        pCur2 = pCur2->pNext;
    }

    f.close();
}
