//#include"func.h"
//void update_course_list(HT_course& pCourse) {
//	course* pCur = pCourse.head;
//	int n = 0;
//	wcout << L"No, id, tên khóa học, tên giảng viên, số tín chỉ, số sinh viên tối đa, thời gian 2 buổi/1tuần." << endl;
//	while (pCur) {
//		n++;
//		wcout << n << L". " << pCur->id << "," << pCur->name << "," << pCur->teacher_name << "," << pCur->num_cre << "," << pCur->max_student << "," << pCur->session << endl;
//		pCur = pCur->pNext;
//	}
//	wcout << n + 1 << L". Quay về." << endl;
//	int choose = user_choose_exist(1, n + 1);
//	if (choose == n + 1) return;
//	n = 0;
//}
//void do_student_work(string& username, id_class*& idClass, HT_in4_student& student_in4, HT_course& pCourse, account*& student) {
//	//xem còn thời gian đăng kí không trong date_registration.txt 
//	while (1) {
//		wcout << L"1. Đăng kí." << endl;
//		wcout << L"2. Thoát" << endl;
//		wcout << L"Chọn: ";
//		int choose = user_choose_exist(1, 2);
//		switch (choose) {
//		case 1: {
//
//		}
//		case 2: return;
//		}
//	}
//}