#include "student.h"

using namespace std;

Student::Student(const string& n, int a, long i) : Human(n,a), id(i)
{

}

Student::~Student()
{

}

ostream& operator <<(ostream& os, const Student& student)
{
	os << student.name ;
	return os;
}
