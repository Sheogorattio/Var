#include <iostream>
#include "MyString.h"
#include "var.h"
using namespace std;

int main() {
	/*var a = 15;
	var b = "Hello";
	var c = 7.5;
	var d = "50";
	b = a;
	b+=d;
	cout << b;*/

	var a = 10, b = "120", c;
	c = a + b;
	cout << c; // ֲûגוהוע 130
	c = b + a;
	cout<< c; // ֲûגוהוע “12010”
}
