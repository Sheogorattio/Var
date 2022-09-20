#pragma once
#include <iostream>
#include "MyString.h"
class var
{
	int i_var;
	double d_var;
	MyString str_var;
	//friend istream& operator>>(istream& is, var a);
public:

	int StringToNumber(const char * s);
	char* NumberToString(const int a);

	var();
	var(int a);
	var(double a);
	var(const MyString& obj);
	var(const char* s);

	int Geti_num();
	double Getd_num();
	MyString& Getstr_var();

	void Seti_var(const int a);
	void Setd_var(const double a);
	void Setstr_var(const char* obj);
	char* GetStr();

	operator int();
	operator double();
	operator char* ();

	var& operator=(const int a);
	var& operator=(const double a);
	var& operator=(const char* str);

	var& operator+=(const int a);
	var& operator+=(const double a);
	var& operator+=(const char* s);
	var& operator+=(var a);

	var& operator-=(const int a);
	var& operator-=(const double a);
	var& operator-=(const char* s);
	var& operator-=(var a);

	var operator+(const int a);
	var operator+(const double a);
	var operator+(const char* s);
	var operator+(const var& a);


	var operator-(const int a);
	var operator-(const double a);
	var operator-(const char* s);
	var operator-(const var& a);
	

};

ostream& operator<<(ostream& os, var a);

istream& operator>>(istream& is, var& a);

//istream& operator>>(istream& is, var a) {
//	if (a.i_var != NULL) {
//		is >> a.i_var;
//		cin.get();
//	}
//	else if (a.d_var != NULL) {
//		is >> a.d_var;
//		cin.get();
//	}
//	else {
//		char buff[255];
//		is >> buff;
//		a.str_var.Input(buff);
//	}
//	return is;
//}

//int operator+=(int num, const var& a);
//double operator+=(double num, const var& a);
//
//int operator-=(int num, const var& a);
//double operator-=(double num, const var& a);
//
//int operator+(int num, const var& a);
//double operator+(double num, const var& a);
//
//
//int operator-(int num, const var& a);
//double operator-(double num, const var& a);