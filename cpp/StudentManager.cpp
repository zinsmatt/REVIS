#include <iostream>
#include "StudentManager.h"

using namespace std;

StudentManager* StudentManager::instance = 0;

Student* StudentManager::getNewStudent(const string &n, int a)
{
	Student* student = new Student(n,a);
	if(student)
	{
		student->setId(counter++);
	}
	pair<long,Student*> newPair = make_pair(student->getId(),student);
	students.insert(newPair);
	return student;
}

StudentManager::~StudentManager()
{
	for(auto it = students.begin(); it != students.end(); ++it)
	{
		delete static_cast<Student*>(it->second);
	}
}

void StudentManager::removeStudent(long id)
{
	Student* pt = students.at(id);
	students.erase(id);
	if(pt) delete pt;
}


ostream& operator <<(ostream& os, const StudentManager& manager)
{
	for(auto it = manager.students.begin();
	    it!=manager.students.end();
	    ++it)
	{
		os << it->first << " " ;
		os << *(static_cast<Student*>(it->second)) << endl;
	}
	return os;
}
