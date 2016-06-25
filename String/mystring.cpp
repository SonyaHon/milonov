#include "mystring.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
	
mystring::mystring():_str(0), len(0){}
mystring::mystring(int size):_str(new char[size + 1]), len(0){}
mystring::mystring(const mystring& s):_str(new char[s.len + 1]), len(s.len) {
	strcpy(_str, s._str);
}
mystring::mystring(const char* s):_str(new char[strlen(s)]), len(strlen(s)){
	strcpy(_str, s);
}
mystring::~mystring() {
	delete[] _str;
}
char& mystring::operator[](int idx) {
	if(idx < 0 || idx >= len) exit(1);
	return _str[idx];
}
char mystring::operator[](int idx) const {
	if(idx < 0 || idx >= len) exit(1);
	return _str[idx];
}
bool mystring::operator==(const mystring& s) const {
	return !strcmp(s, _str);
}
bool mystring::operator!=(const mystring& s) const {
	return !operator==(s);
}
bool mystring::operator> (const mystring& s) const {
	return strcmp(_str, s) > 0;
}
bool mystring::operator< (const mystring& s) const {
	return strcmp(_str, s) < 0;
}
bool mystring::operator>=(const mystring& s) const {
	return strcmp(_str, s) >= 0;
}
bool mystring::operator<=(const mystring& s) const {
	return strcmp(_str, s) <= 0;
}
mystring mystring::operator+(const mystring& s) const {
	mystring res(len + s.len);
	strcpy(res._str, _str);
	strcat(res._str, s._str);
	res.len = len + s.len;
	return res;
}
mystring::operator const char*() const {
	return _str;
}
mystring& mystring::operator=(const mystring& s) {
	if(this != &s) {
		delete _str;
		_str = new char[s.len + 1];
		strcpy(_str, s._str);
		len = s.len;
	}
	return *this;
}
int mystring::size() {
	return len;
}