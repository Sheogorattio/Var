#include "MyString.h"

int MyString::counter = 0;

int MyString::GetCount() {
	return counter;
}
void MyString::DemCount() {
	counter--;
}
MyString::MyString() {
	length = 80;
	str = new char[length+1];
	*(str+length) = '\0';
	counter++;
}
MyString::MyString(const MyString& obj) {
	str = new char[strlen(obj.str) + 1];
	strcpy_s(str, strlen(obj.str) + 1, obj.str);
	length = obj.length;
	counter++;
}
MyString::MyString(int size) {
	length = size;
	str = new char[size + 1];
	*(str + size) = '\0';
	counter++;
}
MyString::MyString(const char* s) {
	length = strlen(s);
	str = new char[length + 1];
	strcpy_s(str, long long(length + 1), s);
	counter++;
}
MyString::~MyString() {
	delete[] str;
	counter--;
}
int MyString::MyStrLen() {//вывод длинны строки
	length = 0;
	for (int i = 0;; i++) {
		length = i;
		if (*(str + i) == '\0') {
			break;
		}
	}
	return length;
}
void MyString::MyStrCpy(const MyString& obj) {//копирование строки
	if (str != nullptr) {
		delete[]str;
	}
	str = new char[strlen(obj.str) + 1];
	length = obj.length;
	char ch;
	for (int i = 0;; i++) {
		ch = *(obj.str + i);
		*(str + i) = ch;
		if (ch == '\0') {
			break;
		}
	}
}
void MyString::Print() const {//это моё
	cout << str << endl;
}
void MyString::Input(const char* buff) {//ввод и вывод
	if (str != nullptr) {
		delete[] str;
	}
	str = new char[strlen(buff) + 1];
	strcpy_s(str, strlen(buff) + 1, buff);
	length = strlen(str);
}
int MyString::MyStrCmp(MyString& b)const {//сравнение строк по длинне
	unsigned long long size_a = strlen(str);
	unsigned long long size_b = strlen(b.str);
	if (size_a == size_b) { return 0; }
	return (size_a > size_b) ? 1 : -1;
}
//void MyString::MyStrCat(MyString& b) {//конкатенация строк
//	unsigned long long size_a = strlen(str);
//	unsigned long long size_b = strlen(b.str);
//	int buff_size = strlen(str) + strlen(b.str) + 1;
//	char* buff = new char[buff_size];
//
//	int count = 0;
//	while (*(str + count) != '\0') {
//		*(buff + count) = *(str + count);
//		count++;
//	}
//	int count2 = 0;
//	while (*(b.str + count2) != '\0') {
//		*(buff + count) = *(b.str + count2);
//		count++;
//		count2++;
//	}
//	*(buff + count) = '\0';
//
//	delete[] str;
//	str = new char[size_a + size_b + 1];
//	strcpy_s(str, size_a + size_b + 1, buff);
//	length = strlen(str);
//	delete[]buff;
//}
void MyString::MyStrCat(const char* b) {//конкатенация строк
	unsigned long long size_a = strlen(str);
	unsigned long long size_b = strlen(b);
	int buff_size = strlen(str) + strlen(b) + 1;
	char* buff = new char[buff_size];

	int count = 0;
	while (*(str + count) != '\0') {
		*(buff + count) = *(str + count);
		count++;
	}
	int count2 = 0;
	while (*(b + count2) != '\0') {
		*(buff + count) = *(b + count2);
		count++;
		count2++;
	}
	*(buff + count) = '\0';

	delete[] str;
	str = new char[size_a + size_b + 1];
	strcpy_s(str, size_a + size_b + 1, buff);
	length = strlen(str);
	delete[]buff;
}
int MyString::MyChr(char c)const {//поиск указанного символа
	int counter = 0;
	for (int i = 0;; i++) {
		if (*(str + counter) == c || *(str + counter) == '\0') {
			break;
		}
		counter++;
	}
	if (counter == length) counter = -1;//если нет такой буквы
	return counter;
}
void MyString::MyDelChr(char c) {//удаление указанного символа
	if (str == nullptr) {
		return;
	}
	int ch_count = 0;//сколько раз всречается буква в слове
	for (int i = 0; *(str + i) != '\0'; i++) {
		if (*(str + i) == c) {
			ch_count++;
		}
	}
	int count = 0, buff_size = strlen(str) - ch_count, position = 0;
	char* buff = new char[buff_size + 1];
	for (int i = 0; i <= buff_size + 1; i++) {//запись в буфер с пропуском указанной буквы
		if (*(str + i) != c) {
			*(buff + position) = *(str + i);
			position++;
		}
		else {
			continue;
		}
	}
	*(buff + buff_size) = '\0';
	delete[] str;
	str = new char[buff_size + 1];
	strcpy_s(str, long long(buff_size + 1), buff);
	length = buff_size;
	delete[] buff;
}
bool MyString::MyStrStr(const char* s)const {//подстрока в строке
	int s_size = strlen(s);
	int orig_size = length;
	bool check = 0;
	for (int i = 0; i <= orig_size - s_size; i++) {
		if (*(str + i) == *(s)) {
			check = 1;
			int position = 0;
			for (int j = i; position < s_size; j++) {
				if (*(str + j) != *(s + position)) {
					check = 0;
					break;
				}
				position++;
			}
		}
	}
	return check;
}

MyString& MyString::operator= (const MyString& obj) {
	if (this == &obj){
		return *this;
	}
	if (str != nullptr){
		delete[] str;
	}
	str = new char[strlen(obj.str) + 1];
	strcpy_s(str, strlen(obj.str) + 1, obj.str);
	length = obj.length;
	return *this;
}

void MyString::operator() () {
	cout << str << "\t" << length;
}

char MyString::operator[] (int i) {
	if (i >= 0 && i < strlen(str)){
		return str[i];
	}
	else {
		cout << "wrong index\n";
		return '\0';
	}
}

MyString::operator int() {
	return length;
}

MyString::operator char* () {
	return str;
}

void PrintNum(int a) {
	cout << a << endl;
}

void PrintStr(const char* a) {
	cout << a << endl;
}

MyString& MyString::operator+(MyString& b) {
	unsigned long long size_a = strlen(str);
	unsigned long long size_b = strlen(b.str);
	int buff_size = strlen(str) + strlen(b.str) + 1;
	char* buff = new char[buff_size];

	int count = 0;
	while (*(str + count) != '\0') {
		*(buff + count) = *(str + count);
		count++;
	}
	int count2 = 0;
	while (*(b.str + count2) != '\0') {
		*(buff + count) = *(b.str + count2);
		count++;
		count2++;
	}
	*(buff + count) = '\0';

	delete[] str;
	str = new char[size_a + size_b + 1];
	strcpy_s(str, size_a + size_b + 1, buff);
	length = strlen(str);
	delete[]buff;
	return *this;
}

char* MyString::GetStr() {
	return str;
}