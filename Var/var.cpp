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

int var::Geti_num()const {
	return i_var;
}

double var::Getd_num() const {
	return d_var;
}

MyString var::Getstr_var()const {
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



int var::StringToNumber(const char * s) const {
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
char* var::NumberToString(const int number)const {
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
		char* s = NumberToString(a);
		str_var.MyStrCat(s);
		delete[]s;
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
		char* s = NumberToString(a);
		str_var.MyStrCat(s);
		delete[]s;
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
		char* s = NumberToString(a);
		str_var.MyStrCat(s);
		delete[]s;
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
		char* s = NumberToString(a);
		str_var.MyStrCat(s);
		delete[]s;
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

var var::operator+(const int a) {
	var obj = *this;
	if (obj.i_var != NULL) {
		obj.i_var += a;
	}
	else if (d_var != NULL) {
		obj.d_var += a;
	}
	else {
		char* s = NumberToString(a);
		obj.str_var.MyStrCat(s);
		delete[]s;
	}
	return obj;
}
var var::operator+(const double a) {
	var obj = *this;
	if (obj.i_var != NULL) {
		obj.i_var += (int)a;
	}
	else if (obj.d_var != NULL) {
		obj.d_var += a;
	}
	else {
		char* s = NumberToString(a);
		obj.str_var.MyStrCat(s);
		delete[]s;
	}
	return obj;
}
var var::operator+(const char* s) {
	var obj = *this;
	if (obj.i_var != NULL) {
		obj.i_var += StringToNumber(s);
	}
	else if (obj.d_var != NULL) {
		obj.d_var += (double)StringToNumber(s);
	}
	else {
		obj.str_var.MyStrCat(s);
	}
	return obj;
}
var var::operator+(var& a) {
	var obj = *this;
	if (obj.i_var != NULL) {
		obj.i_var += int(a);
	}
	else if (obj.d_var != NULL) {
		obj.d_var += double(a);
	}
	else {
		obj.str_var.MyStrCat(a);
	}
	return obj;
}

var var::operator-(const int a) {
	var obj=*this;
	if (obj.i_var != NULL) {
		obj.i_var -= a;
	}
	else if (obj.d_var != NULL) {
		obj.d_var -= a;
	}
	else {
		char* s = NumberToString(a);
		obj.str_var.MyStrCat(s);
		delete[]s;
	}
	return obj;
}
var var::operator-(const double a) {
	var obj=*this;
	if (obj.i_var != NULL) {
		obj.i_var -= (int)a;
	}
	else if (obj.d_var != NULL) {
		obj.d_var -= a;
	}
	else {
		char* s = NumberToString((int)a);
		obj.str_var.MyStrCat(s);
		delete[] s;
	}
	return obj;
}
var var::operator-(const char* s) {
	var obj = *this;
	if (obj.i_var != NULL) {
		obj.i_var -= StringToNumber(s);
	}
	else if (obj.d_var != NULL) {
		obj.d_var -= (double)StringToNumber(s);
	}
	else {
		obj.str_var.MyStrCat(s);
	}
	return obj;
}
var var::operator-(var& a) {
	var obj = *this;
	if (obj.i_var != NULL) {
		obj.i_var -= int(a);
	}
	else if (obj.d_var != NULL) {
		obj.d_var -= double(a);
	}
	else {
		obj.str_var.MyStrCat(a);
	}
	return obj;
}

int operator-(int a, const var& obj) {
	int rez = a;
	int val;
	if (obj.Geti_num() != NULL) {
		val = obj.Geti_num();
	}
	else if(obj.Getd_num() != NULL) {
		val = (int)obj.Getd_num();
	}
	else {
		val = obj.StringToNumber(obj.Getstr_var());
	}
	rez -= val;
	return rez;
}
double operator-(double a, const var& obj) {
	double rez = a;
	double val;
	if (obj.Geti_num() != NULL) {
		val = (double)obj.Geti_num();
	}
	else if (obj.Getd_num() != NULL) {
		val = obj.Getd_num();
	}
	else {
		val = (double)obj.StringToNumber(obj.Getstr_var());
	}
	rez -= val;
	return rez;
}

int operator+(int a, const var& obj) {
	int rez = a;
	int val;
	if (obj.Geti_num() != NULL) {
		val = obj.Geti_num();
	}
	else if (obj.Getd_num() != NULL) {
		val = (int)obj.Getd_num();
	}
	else {
		val = obj.StringToNumber(obj.Getstr_var());
	}
	rez += val;
	return rez;
}
double operator+(double a, const var& obj) {
	double rez = a;
	double val;
	if (obj.Geti_num() != NULL) {
		val = (double)obj.Geti_num();
	}
	else if (obj.Getd_num() != NULL) {
		val = obj.Getd_num();
	}
	else {
		val = (double)obj.StringToNumber(obj.Getstr_var());
	}
	rez += val;
	return rez;
}
char* operator+(char* s, const var& obj) {
	MyString rez = obj.Getstr_var();
	rez.MyStrCat(s);
	return rez.GetStr();
}

var& var::operator*=(const int a) {
	if (i_var != NULL) {
		i_var *= a;
	}
	else if (d_var != NULL) {
		d_var *= a;
	}
	else {
		char* s = NumberToString(a);
		char* t = GetStr();
		int s_size = strlen(s);
		int t_size = strlen(t);
		int counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					counter++;
				}
			}
		}
		char* rez = new char[counter + 1];
		rez[counter] = '\0';
		counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					rez[counter] = s[i];
					counter++;
				}
			}
		}
		Setstr_var(rez);
		delete[] rez;
		delete[]s;
	}
	return *this;
}
var& var::operator*=(const double a) {
	if (i_var != NULL) {
		i_var *= (int)a;
	}
	else if (d_var != NULL) {
		d_var *= a;
	}
	else {
		char* s = NumberToString((int)a);
		char* t = GetStr();
		int s_size = strlen(s);
		int t_size = strlen(t);
		int counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					counter++;
				}
			}
		}
		char* rez = new char[counter + 1];
		rez[counter] = '\0';
		counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					rez[counter] = s[i];
					counter++;
				}
			}
		}
		Setstr_var(rez);
		delete[] rez;
		delete[]s;
	}
	return *this;
}
var& var::operator*=(const char* s) {
	if (i_var != NULL) {
		i_var *= StringToNumber(s);
	}
	else if (d_var != NULL) {
		d_var *= (double)StringToNumber(s);
	}
	else {
		char* t = GetStr();
		int s_size = strlen(s);
		int t_size = strlen(t);
		int counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					counter++;
				}
			}
		}
		char* rez = new char[counter + 1];
		rez[counter] = '\0';
		counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					rez[counter] = s[i];
					counter++;
				}
			}
		}
		Setstr_var(rez);
		delete[] rez;
	}
	return *this;
}
var& var::operator*=( var& a) {
	if (i_var != NULL) {
		i_var *= int(a);
	}
	else if (d_var != NULL) {
		d_var *= double(a);
	}
	else {
		char* s = a.GetStr();
		char* t = GetStr();
		int s_size = strlen(s);
		int t_size = strlen(t);
		int counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					counter++;
				}
			}
		}
		char* rez = new char[counter + 1];
		rez[counter] = '\0';
		counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					rez[counter] = s[i];
					counter++;
				}
			}
		}
		Setstr_var(rez);
		delete[] rez;
	}
	return *this;
}

var& var::operator/=(const int a) {
	if (i_var != NULL) {
		i_var /= a;
	}
	else if (d_var != NULL) {
		d_var /= a;
	}
	else {
		char* s = NumberToString(a);
		char* t = GetStr();
		int s_size = strlen(s);
		int t_size = strlen(t);
		int counter = 0;
		bool check = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					check = 1;
					if (check == 0) {
						counter++;
						check = 0;
					}
				}
			}
		}
		char* rez = new char[counter + 1];
		rez[counter] = '\0';
		counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					check = 1;
					if (check == 0) {
						rez[counter] = s[i];
						counter++;
						check = 0;
					}
				}
			}
		}
		Setstr_var(rez);
		delete[] rez;
		delete[]s;
	}
	return *this;
}
var& var::operator/=(const double a) {
	if (i_var != NULL) {
		i_var /= (double)a;
	}
	else if (d_var != NULL) {
		d_var /= a;
	}
	else {
		char* s = NumberToString((int)a);
		char* t = GetStr();
		int s_size = strlen(s);
		int t_size = strlen(t);
		int counter = 0;
		bool check = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					check = 1;
					if (check == 0) {
						counter++;
						check = 0;
					}
				}
			}
		}
		char* rez = new char[counter + 1];
		rez[counter] = '\0';
		counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					check = 1;
					if (check == 0) {
						rez[counter] = s[i];
						counter++;
						check = 0;
					}
				}
			}
		}
		Setstr_var(rez);
		delete[] rez;
		delete[]s;
	}
	return *this;
}
var& var::operator/=(const char* s) {
	if (i_var != NULL) {
		i_var /= StringToNumber(s);
	}
	else if (d_var != NULL) {
		d_var /= StringToNumber(s);
	}
	else {
		char* t = GetStr();
		int s_size = strlen(s);
		int t_size = strlen(t);
		int counter = 0;
		bool check = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					check = 1;
					if (check == 0) {
						counter++;
						check = 0;
					}
				}
			}
		}
		char* rez = new char[counter + 1];
		rez[counter] = '\0';
		counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					check = 1;
					if (check == 0) {
						rez[counter] = s[i];
						counter++;
						check = 0;
					}
				}
			}
		}
		Setstr_var(rez);
		delete[] rez;
	}
	return *this;
}
var& var::operator/=(var& a) {
	if (i_var != NULL) {
		i_var /= (int)a;
	}
	else if (d_var != NULL) {
		d_var /= (double)a;
	}
	else {
		char* s = a.GetStr();
		char* t = GetStr();
		int s_size = strlen(s);
		int t_size = strlen(t);
		int counter = 0;
		bool check = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					check = 1;
					if (check == 0) {
						counter++;
						check = 0;
					}
				}
			}
		}
		char* rez = new char[counter + 1];
		rez[counter] = '\0';
		counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					check = 1;
					if (check == 0) {
						rez[counter] = s[i];
						counter++;
						check = 0;
					}
				}
			}
		}
		Setstr_var(rez);
		delete[] rez;
	}
	return *this;
}

var var::operator*(const int a) {
	var obj = *this;
	if (obj.i_var != NULL) {
		obj.i_var *= a;
	}
	else if (obj.d_var != NULL) {
		obj.d_var *= a;
	}
	else {
		char* s = NumberToString(a);
		char* t = obj.GetStr();
		int s_size = strlen(s);
		int t_size = strlen(t);
		int counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					counter++;
				}
			}
		}
		char* rez = new char[counter + 1];
		rez[counter] = '\0';
		counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					rez[counter] = s[i];
					counter++;
				}
			}
		}
		obj.Setstr_var(rez);
		delete[] rez;
		delete[]s;
	}
	return obj;
}
var var::operator*(const double a) {
	var obj = *this;
	if (obj.i_var != NULL) {
		obj.i_var *= (int)a;
	}
	else if (obj.d_var != NULL) {
		obj.d_var *= a;
	}
	else {
		char* s = NumberToString((int)a);
		char* t = obj.GetStr();
		int s_size = strlen(s);
		int t_size = strlen(t);
		int counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					counter++;
				}
			}
		}
		char* rez = new char[counter + 1];
		rez[counter] = '\0';
		counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					rez[counter] = s[i];
					counter++;
				}
			}
		}
		obj.Setstr_var(rez);
		delete[] rez;
		delete[]s;
	}
	return obj;
}
var var::operator*(const char* s) {
	var obj = *this;
	if (obj.i_var != NULL) {
		obj.i_var *= StringToNumber(s);
	}
	else if (obj.d_var != NULL) {
		obj.d_var *= (double)StringToNumber(s);
	}
	else {
		char* t = obj.GetStr();
		int s_size = strlen(s);
		int t_size = strlen(t);
		int counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					counter++;
				}
			}
		}
		char* rez = new char[counter + 1];
		rez[counter] = '\0';
		counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					rez[counter] = s[i];
					counter++;
				}
			}
		}
		obj.Setstr_var(rez);
		delete[] rez;
	}
	return obj;
}
var var::operator*(var& a) {
	var obj = *this;
	if (obj.i_var != NULL) {
		obj.i_var *= int(a);
	}
	else if (obj.d_var != NULL) {
		obj.d_var *= double(a);
	}
	else {
		char* s = a.GetStr();
		char* t = obj.GetStr();
		int s_size = strlen(s);
		int t_size = strlen(t);
		int counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					counter++;
				}
			}
		}
		char* rez = new char[counter + 1];
		rez[counter] = '\0';
		counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					rez[counter] = s[i];
					counter++;
				}
			}
		}
		obj.Setstr_var(rez);
		delete[] rez;
	}
	return obj;
}

var var::operator/(const int a) {
	var obj = *this;
	if (obj.i_var != NULL) {
		obj.i_var /= a;
	}
	else if (obj.d_var != NULL) {
		obj.d_var /= a;
	}
	else {
		char* s = NumberToString(a);
		char* t = obj.GetStr();
		int s_size = strlen(s);
		int t_size = strlen(t);
		int counter = 0;
		bool check = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					check = 1;
					if (check == 0) {
						counter++;
						check = 0;
					}
				}
			}
		}
		char* rez = new char[counter + 1];
		rez[counter] = '\0';
		counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					check = 1;
					if (check == 0) {
						rez[counter] = s[i];
						counter++;
						check = 0;
					}
				}
			}
		}
		obj.Setstr_var(rez);
		delete[] rez;
		delete[]s;
	}
	return obj;
}
var var::operator/(const double a) {
	var obj = *this;
	if (obj.i_var != NULL) {
		obj.i_var /= (double)a;
	}
	else if (obj.d_var != NULL) {
		obj.d_var /= a;
	}
	else {
		char* s = NumberToString((int)a);
		char* t = obj.GetStr();
		int s_size = strlen(s);
		int t_size = strlen(t);
		int counter = 0;
		bool check = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					check = 1;
					if (check == 0) {
						counter++;
						check = 0;
					}
				}
			}
		}
		char* rez = new char[counter + 1];
		rez[counter] = '\0';
		counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					check = 1;
					if (check == 0) {
						rez[counter] = s[i];
						counter++;
						check = 0;
					}
				}
			}
		}
		obj.Setstr_var(rez);
		delete[] rez;
		delete[]s;
	}
	return obj;
}
var var::operator/(const char* s) {
	var obj = *this;
	if (obj.i_var != NULL) {
		obj.i_var /= StringToNumber(s);
	}
	else if (obj.d_var != NULL) {
		obj.d_var /= StringToNumber(s);
	}
	else {
		char* t = obj.GetStr();
		int s_size = strlen(s);
		int t_size = strlen(t);
		int counter = 0;
		bool check = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					check = 1;
					if (check == 0) {
						counter++;
						check = 0;
					}
				}
			}
		}
		char* rez = new char[counter + 1];
		rez[counter] = '\0';
		counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					check = 1;
					if (check == 0) {
						rez[counter] = s[i];
						counter++;
						check = 0;
					}
				}
			}
		}
		obj.Setstr_var(rez);
		delete[] rez;
	}
	return obj;
}
var var::operator/(var& a) {
	var obj = *this;
	if (obj.i_var != NULL) {
		obj.i_var /= (int)a;
	}
	else if (obj.d_var != NULL) {
		obj.d_var /= (double)a;
	}
	else {
		char* s = a.GetStr();
		char* t = obj.GetStr();
		int s_size = strlen(s);
		int t_size = strlen(t);
		int counter = 0;
		bool check = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					check = 1;
					if (check == 0) {
						counter++;
						check = 0;
					}
				}
			}
		}
		char* rez = new char[counter + 1];
		rez[counter] = '\0';
		counter = 0;
		for (int i = 0; i < s_size; i++) {
			for (int j = 0; j < t_size; j++) {
				if (s[i] == t[j]) {
					check = 1;
					if (check == 0) {
						rez[counter] = s[i];
						counter++;
						check = 0;
					}
				}
			}
		}
		obj.Setstr_var(rez);
		delete[] rez;
	}
	return obj;
}

bool var::operator>(int a) {
	if (i_var != NULL) {
		return i_var > a ? 1 : 0;
	}
	else if (d_var != NULL) {
		return d_var > (double)a ? 1 : 0;
	}
	else {
		int rez = StringToNumber(str_var.GetStr());
		return rez > a ? 1 : 0;
	}
}
bool var::operator>=(int a) {
	if (i_var != NULL) {
		return i_var >= a ? 1 : 0;
	}
	else if (d_var != NULL) {
		return d_var >= (double)a ? 1 : 0;
	}
	else {
		int rez = StringToNumber(str_var.GetStr());
		return rez >= a ? 1 : 0;
	}
}
bool var::operator<(int a) {
	if (i_var != NULL) {
		return i_var < a ? 1 : 0;
	}
	else if (d_var != NULL) {
		return d_var < (double)a ? 1 : 0;
	}
	else {
		int rez = StringToNumber(str_var.GetStr());
		return rez < a ? 1 : 0;
	}
}
bool var::operator<=(int a) {
	if (i_var != NULL) {
		return i_var <= a ? 1 : 0;
	}
	else if (d_var != NULL) {
		return d_var <= (double)a ? 1 : 0;
	}
	else {
		int rez = StringToNumber(str_var.GetStr());
		return rez <= a ? 1 : 0;
	}
}
bool var::operator==(int a) {
	if (i_var != NULL) {
		return i_var == a ? 1 : 0;
	}
	else if (d_var != NULL) {
		return d_var == (double)a ? 1 : 0;
	}
	else {
		int rez = StringToNumber(str_var.GetStr());
		return rez == a ? 1 : 0;
	}
}
bool var::operator!=(int a) {
	if (i_var != NULL) {
		return i_var != a ? 1 : 0;
	}
	else if (d_var != NULL) {
		return d_var != (double)a ? 1 : 0;
	}
	else {
		int rez = StringToNumber(str_var.GetStr());
		return rez != a ? 1 : 0;
	}
}

bool var::operator>(double a) {
	if (i_var != NULL) {
		return i_var > (double)a ? 1 : 0;
	}
	else if (d_var != NULL) {
		return d_var > a ? 1 : 0;
	}
	else {
		int rez = StringToNumber(str_var.GetStr());
		return (double)rez > a ? 1 : 0;
	}
}
bool var::operator>=(double a) {
	if (i_var != NULL) {
		return i_var >= (double)a ? 1 : 0;
	}
	else if (d_var != NULL) {
		return d_var >= a ? 1 : 0;
	}
	else {
		int rez = StringToNumber(str_var.GetStr());
		return (double)rez >= a ? 1 : 0;
	}
}
bool var::operator<(double a) {
	if (i_var != NULL) {
		return i_var < (double)a ? 1 : 0;
	}
	else if (d_var != NULL) {
		return d_var < a ? 1 : 0;
	}
	else {
		int rez = StringToNumber(str_var.GetStr());
		return (double)rez < a ? 1 : 0;
	}
}
bool var::operator<=(double a) {
	if (i_var != NULL) {
		return i_var <= (double)a ? 1 : 0;
	}
	else if (d_var != NULL) {
		return d_var <= a ? 1 : 0;
	}
	else {
		int rez = StringToNumber(str_var.GetStr());
		return (double)rez <= a ? 1 : 0;
	}
}
bool var::operator==(double a) {
	if (i_var != NULL) {
		return i_var == (double)a ? 1 : 0;
	}
	else if (d_var != NULL) {
		return d_var == a ? 1 : 0;
	}
	else {
		int rez = StringToNumber(str_var.GetStr());
		return (double)rez == a ? 1 : 0;
	}
}
bool var::operator!=(double a) {
	if (i_var != NULL) {
		return i_var != (double)a ? 1 : 0;
	}
	else if (d_var != NULL) {
		return d_var != a ? 1 : 0;
	}
	else {
		int rez = StringToNumber(str_var.GetStr());
		return (double)rez != a ? 1 : 0;
	}
}

bool var::operator>(var& a) {
	if (i_var != NULL) {
		return i_var > (int)a;
	}
	else if (d_var != NULL) {
		return d_var > (double)a;
	}
	else {
		int l_v = StringToNumber(str_var.GetStr());
		int r_v = StringToNumber(a.GetStr());
		return l_v > r_v;
	}
}
bool var::operator>=(var& a) {
	if (i_var != NULL) {
		return i_var >= (int)a;
	}
	else if (d_var != NULL) {
		return d_var >= (double)a;
	}
	else {
		int l_v = StringToNumber(str_var.GetStr());
		int r_v = StringToNumber(a.GetStr());
		return l_v >= r_v;
	}
}
bool var::operator<(var& a) {
	if (i_var != NULL) {
		return i_var < (int)a;
	}
	else if (d_var != NULL) {
		return d_var < (double)a;
	}
	else {
		int l_v = StringToNumber(str_var.GetStr());
		int r_v = StringToNumber(a.GetStr());
		return l_v < r_v;
	}
}
bool var::operator<=(var& a) {
	if (i_var != NULL) {
		return i_var <= (int)a;
	}
	else if (d_var != NULL) {
		return d_var <= (double)a;
	}
	else {
		int l_v = StringToNumber(str_var.GetStr());
		int r_v = StringToNumber(a.GetStr());
		return l_v <= r_v;
	}
}
bool var::operator==(var& a) {
	if (i_var != NULL) {
		return i_var == (int)a;
	}
	else if (d_var != NULL) {
		return d_var == (double)a;
	}
	else {
		int l_v = StringToNumber(str_var.GetStr());
		int r_v = StringToNumber(a.GetStr());
		return l_v == r_v;
	}
}
bool var::operator!=(var& a) {
	if (i_var != NULL) {
		return i_var != (int)a;
	}
	else if (d_var != NULL) {
		return d_var != (double)a;
	}
	else {
		int l_v = StringToNumber(str_var.GetStr());
		int r_v = StringToNumber(a.GetStr());
		return l_v != r_v;
	}
}