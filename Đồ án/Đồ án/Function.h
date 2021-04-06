#ifndef HEADER_H
#define HEADER_H
//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#include<fstream>
#include <locale>
#include <codecvt>
#include <string>
#include <wincrypt.h>
#include<iomanip>


struct Student
{
	wchar_t* no;
	wchar_t* ID;
	wchar_t* name;
	wchar_t* lastname;
	wchar_t* gender;
	std::wstring date;

};
struct NodeStu
{
	struct Student infor;
	NodeStu* next;
	NodeStu* pre;
}; 

void ChangeToVietNamese();
void Inputdata(NodeStu*& infor, std::wfstream &fin);
void OutputData();
void ChangeToData(std::wstring line, NodeStu*& t);
//void NewNodeStu(NodeStu*& data);
void PrintStu(NodeStu*& data);
void DeallocateData(NodeStu* infor);
#endif // !HEADER_H