#ifndef STRINGARRAY_H
#define STRINGARRAY_H
#include <string>
#include "arraylist.h"

class StringArray
{

	ArrayList<std::string*> words;

public:
	StringArray(const std::string& s);

	// manage deep copy
	StringArray& operator =(const StringArray& base);
	StringArray(const StringArray& base);
	~StringArray();


};

#endif // STRINGARRAY_H
