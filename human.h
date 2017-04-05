#ifndef HUMAN_H
#define HUMAN_H
#include <string>

class Human
{
protected:
	std::string name;
	int age;

public:
	Human(const std::string& n, int a = 0);
	~Human();
};

#endif // HUMAN_H
