#ifndef MYSTRING_H_
#define MYSTRING_H_ 

class mystring {
private:
	char *_str;
	int    len;
public:
	mystring();
	mystring(int size);
	mystring(const mystring&);
	mystring(const char*);
	~mystring();

	char& operator[](int idx);
	char  operator[](int idx) const;

	bool operator==(const mystring&) const;
	bool operator!=(const mystring&) const;
	bool operator> (const mystring&) const;
	bool operator< (const mystring&) const;
	bool operator>=(const mystring&) const;
	bool operator<=(const mystring&) const;

	mystring operator+(const mystring&) const;
	mystring& operator=(const mystring&);

	operator const char*() const;

	int size();
};

#endif