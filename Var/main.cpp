#include <iostream>
#include "MyString.h"
#include "var.h"
using namespace std;

int main() {
	var a = 15;
	var b = "Hello";
	var c = 7.5;
	var d = "50";
	b = a;
	b+=d;
	cout << b;
}
