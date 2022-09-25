#pragma once
#include <iostream>
#include "MyString.h"
class var
{
	int i_var;
	double d_var;
	MyString str_var;
public:

	int StringToNumber(const char * s)const;
	char* NumberToString(const int a)const;

	var();
	var(int a);
	var(double a);
	var(const MyString& obj);
	var(const char* s);

	int Geti_num()const;
	double Getd_num()const;
	MyString Getstr_var()const;

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
	var operator+( var& a);


	var operator-(const int a);
	var operator-(const double a);
	var operator-(const char* s);
	var operator-(var& a);

	var& operator*=(const int a);
	var& operator*=(const double a);
	var& operator*=(const char* s);
	var& operator*=(var& a);

	var& operator/=(const int a);
	var& operator/=(const double a);
	var& operator/=(const char* s);
	var& operator/=(var& a);
	
	var operator*(const int a);
	var operator*(const double a);
	var operator*(const char* s);
	var operator*( var& a);

	var operator/(const int a);
	var operator/(const double a);
	var operator/(const char* s);
	var operator/( var& a);

	bool operator>(int a);
	bool operator>=(int a);
	bool operator<(int a);
	bool operator<=(int a);
	bool operator==(int a);
	bool operator!=(int a);

	bool operator>(double a);
	bool operator>=(double a);
	bool operator<(double a);
	bool operator<=(double a);
	bool operator==(double a);
	bool operator!=(double a);

	bool operator>(var& a);
	bool operator>=(var& a);
	bool operator<(var& a);
	bool operator<=(var& a);
	bool operator==(var& a);
	bool operator!=(var& a);
};

ostream& operator<<(ostream& os, var a);

istream& operator>>(istream& is, var& a);