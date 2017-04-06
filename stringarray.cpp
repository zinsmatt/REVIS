#include "stringarray.h"
#include <iostream>
#include <ostream>

using namespace std;

StringArray::StringArray(const string& s)
{
	size_t l = 0, r = 0;
	while(r != string::npos)
	{
		r = s.find(' ',l+1);
		string* nouv;
		if(r == string::npos)
		{
			nouv = new string(s,l,s.size());
		}else
		{
			nouv = new string(s,l,r-l);
		}
		words.add(nouv);
		cout << *nouv << endl;
		l = r+1;
	}
}

StringArray::~StringArray()
{
	for(auto iter = words.begin(); iter != words.end(); ++iter)
	{
		delete *iter;
	}
}

StringArray::StringArray(const StringArray &base)
{
	for(ArrayList<string*>::Iterator it = base.words.begin();
	    it != base.words.end();
	    ++it)
	{
		words.add(new string(**it));
	}
}

StringArray& StringArray::operator =(const StringArray &base)
{
	// first clear the own array
	for(auto it = words.begin(); it != words.end(); ++it)
	{
		delete *it;
	}
	words.clear();

	// then add the new words
	for(ArrayList<string*>::Iterator it = base.words.begin();
	    it != base.words.end();
	    ++it)
	{
		words.add( new string(**it));
	}
	return *this;
}


ostream& operator <<(ostream& os, const StringArray& arr)
{
	os << arr.words;
	return os;
}
