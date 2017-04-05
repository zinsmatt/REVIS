#include <unordered_map>
#include <ostream>
#include "student.h"

class StudentManager
{
	StudentManager() : counter(0) {}			// private constructor
	~StudentManager();			// private destructor
	StudentManager(const StudentManager&);		// private copy constructor
	StudentManager& operator=(StudentManager&);	// private affectation operator
	
	static StudentManager* instance;	// static isntance
	long counter;
	std::unordered_map<long, Student*> students;

public:
	static StudentManager& getInstance() {
		if(instance) return *instance;
		else instance = new StudentManager;
		return *instance;
	}
	static void freeInstance() {
		if(instance)	delete instance;
		instance = 0;
	}

	Student* getNewStudent(const std::string& n, int a);
	void removeStudent(long id);

	void print();

	friend std::ostream& operator <<(std::ostream& os, const StudentManager& manager);
};
