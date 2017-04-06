#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "human.h"
#include <ostream>

class Student : public Human
{
	long id;
public:
	Student(const std::string& n, int age = 0, long i = 0);
	~Student();

	void setId(long i) { id = i; }
	long getId() { return id; }

	friend std::ostream& operator <<(std::ostream& os, const Student& student);
};

#endif // STUDENT_H
