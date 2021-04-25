#include "Delete.h"

void Delete_Node_stu(Node_stu*& pHead) {
	Node_stu* pTemp = pHead;
	while (pHead != nullptr) {
		pHead = pHead->pNext;
		delete pTemp;
		pTemp = pHead;
	}
}

void Delete_Node_cla(Node_cla*& pHead) {
	Node_cla* pTemp = pHead;
	while (pHead != nullptr) {
		pHead = pHead->pNext;
		delete pTemp;
		pTemp = pHead;
	}
}

void Delete_Node_cou(Node_cou*& pHead) {
	Node_cou* pTemp = pHead;
	while (pHead != nullptr) {
		pHead = pHead->pNext;
		delete pTemp;
		pTemp = pHead;
	}
}