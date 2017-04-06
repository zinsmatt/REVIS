#include "mystring.h"

using namespace std;

MyString::~MyString()
{

}


ostream& operator <<(ostream& os, const MyString& ms)
{
	os << ms._ss;
	return os;
}

