#include <iostream>
#include "var.h"
#include "MyString.h"

using namespace std;

var::var() {
	i_var = NULL;
	d_var = NULL;
}

var::var(int a) {
	i_var = a;
	d_var = NULL;
}

var::var(double a) {
	i_var = NULL;
	d_var = a;
}

var::var(const MyString& obj) {
	i_var = NULL;
	d_var = NULL;
	str_var = obj;
}

var::var(const char* s) {
	i_var = NULL;
	d_var = NULL;
	str_var.Input(s);
}

int var::Geti_num() {
	return i_var;
}

double var::Getd_num() {
	return d_var;
}

MyString& var::Getstr_var() {
	return str_var;
}

char* var::GetStr() {
	return str_var.GetStr();
}

void var::Setd_var(const double a) {
	d_var = a;
}

void var::Setstr_var(const char* obj) {
	str_var.Input(obj);
}

void var::Seti_var(const int a) {
	i_var = a;	
}

var::operator int() {
	if (i_var != NULL) {
		return i_var;
	}
	else if (d_var != NULL) {
		return (int)d_var;
	}
	else {
		return StringToNumber(GetStr());//str_var;
	}
	
}

var::operator double() {
	if (i_var != NULL) {
		return (double)i_var;
	}
	else if (d_var != NULL) {
		return d_var;
	}
	else {
		return (double)StringToNumber(GetStr());
	}
}

var::operator char* () {
	if (i_var != NULL) {
		return NumberToString(Geti_num());
	}
	else if (d_var != NULL) {
		return NumberToString((double)Getd_num());
	}
	else {
		return GetStr();
	}
}

var& var::operator= (const int a) {
	i_var = a;
	return *this;
}

var& var::operator= (const double a) {
	d_var = a;
	return *this;
}

var& var::operator=(const char* str) {
	str_var.Input(str);
	return *this;
}



int var::StringToNumber(const char * s) {
	int const zero_ascii = 48, nine_ascii = 57;
	int result = 0, i = 0;
	const char* ptr = s;
	if (int(*(ptr)) >= zero_ascii && int(*(ptr) <= nine_ascii)) {
		while (*(s + i) && (int(*(s + i)) >= zero_ascii && int(*(s + i) <= nine_ascii))) {
			result = result * 10 + (int(*(s + i)) - zero_ascii);
			i++;
		}
	}
	else {
		return 0;
	}
	return result;
}
char* var::NumberToString(const int number) {
	int const zero_ascii = 48;
	int size_definition = number, size = 1;
	while (size_definition / 10 > 0) {
		size_definition = int(size_definition / 10);
		size++;
	}
	int size_copy = size, num_copy = number;
	char* result = new char[size + 1];
	result[size] = '\0';
	int* digits = new int[size];
	for (int i = size; i >= 0; i--) {

		digits[i - 1] = num_copy % 10;
		num_copy /= 10;
	}
	/* for (int i = 0; i < size_copy; i++) {
		 cout << digits[i] << " ";
	 }*/
	for (int i = 0; i < size; i++) {
		result[i] = digits[i] + zero_ascii;
	}
	return result;
}

ostream& operator<<(ostream& os, var a) {

	if (a.Geti_num() != NULL) {
		os << "value is " << a.Geti_num();
	}
	else if (a.Getd_num() != NULL) {
		os << "value is " << a.Getd_num();
	}
	else {
		os << "string is \"" << a.GetStr() << "\"";
	}
	return os;
}

istream& operator>>(istream& is, var& a) {
	cout << "Select type(enter number 1-3):\n1)Int\n2)Double\n3)Char*\n";
	int select = 0;
	is >> select;
	cin.get();
	if (select == 1) {
		int num;
		is >> num;
		cin.get();
		a.Seti_var(num);
	}
	else if (select == 2) {
		double num;
		is >> num;
		cin.get();
		a.Setd_var(num);
	}
	else if(select == 3) {
		char buff[255];
		is >> buff;
		a.Setstr_var(buff);
	}
	else {
		cout << "wrong number\n";
	}
	return is;
}

var& var::operator+=(const int a) {
	if (i_var != NULL) {
		i_var += a;
	}
	else if (d_var != NULL) {
		d_var += a;
	}
	else {
		str_var.MyStrCat(NumberToString(a));
	}
	return *this;
}
var& var::operator+=(const double a) {
	if (i_var != NULL) {
		i_var += (int)a;
	}
	else if (d_var != NULL) {
		d_var += a;
	}
	else {
		str_var.MyStrCat(NumberToString((int)a));
	}
	return *this;
}
var& var::operator+=(const char* s) {
	if (i_var != NULL) {
		i_var += StringToNumber(s);
	}
	else if (d_var != NULL) {
		d_var += (double)StringToNumber(s);
	}
	else {
		str_var.MyStrCat(s);
	}
	return *this;
}
var& var::operator+=(var a) {
	if (i_var != NULL) {
		i_var += int(a);
	}
	else if (d_var != NULL) {
		d_var += double(a);
	}
	else {
		str_var.MyStrCat(a);
	}
	return *this;
}

var& var::operator-=(const int a) {
	if (i_var != NULL) {
		i_var -= a;
	}
	else if (d_var != NULL) {
		d_var -= a;
	}
	else {
		str_var.MyStrCat(NumberToString(a));
	}
	return *this;
}
var& var::operator-=(const double a) {
	if (i_var != NULL) {
		i_var -= (int)a;
	}
	else if (d_var != NULL) {
		d_var -= a;
	}
	else {
		str_var.MyStrCat(NumberToString((int)a));
	}
	return *this;
}
var& var::operator-=(const char* s) {
	if (i_var != NULL) {
		i_var -= StringToNumber(s);
	}
	else if (d_var != NULL) {
		d_var -= (double)StringToNumber(s);
	}
	else {
		str_var.MyStrCat(s);
	}
	return *this;
}
var& var::operator-=(var a) {
	if (i_var != NULL) {
		i_var -= int(a);
	}
	else if (d_var != NULL) {
		d_var -= double(a);
	}
	else {
		str_var.MyStrCat(a);
	}
	return *this;
}