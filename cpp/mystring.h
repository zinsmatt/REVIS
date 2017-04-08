#ifndef MYSTRING_H
#define MYSTRING_H
#include <string>
#include <ostream>

class MyString
{

	std::string _ss;
public:
	MyString(std::string s) : _ss(s) {}
	~MyString();


	void setString(const std::string& s) { _ss = s; }
	int size() { return _ss.size(); }

	friend std::ostream& operator <<(std::ostream& os, const MyString& ms);
};

#endif // MYSTRING_H
