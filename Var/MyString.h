#pragma once
#include<iostream>
using namespace std;
class MyString {
private:
	char* str;
	int length;
	static int counter;
public:

	MyString();
	MyString(const MyString& obj);
	MyString(int size);
	MyString(const char* s);
	~MyString();
	void Input(const char* s);
	void MyStrCpy(const MyString& obj);
	bool MyStrStr(const char* s)const;
	int MyChr(char c)const;
	int MyStrLen();
	void MyStrCat(MyString& obj);
	void MyStrCat(const char* obj);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b)const;
	void Print() const;
	static int GetCount();
	static void DemCount();
	MyString& operator= (const MyString& obj);
	void operator() ();
	char operator[] (int i);
	operator int();
	operator char*();
	MyString& operator+(MyString& obj);
	char* GetStr();
};

void PrintNum(int a);
void PrintStr(const char* a);


