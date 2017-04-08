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
		Word* nouv;
		if(r == string::npos)
		{
			nouv = new Word(s.substr(l,s.size()));
		}else
		{
			nouv = new Word(s.substr(l,r-l));
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
	for(ArrayList<Word*>::const_Iterator it = base.words.cbegin();
	    it != base.words.cend();
	    ++it)
	{
		words.add(new Word(**it));
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
	for(ArrayList<Word*>::const_Iterator it = base.words.cbegin();
	    it != base.words.cend();
	    ++it)
	{
		words.add( new Word(**it));
	}
	return *this;
}


ostream& operator <<(ostream& os, const StringArray& arr)
{
	for(StringArray::const_Iterator iter = arr.cbegin(); iter != arr.cend(); ++iter)
		cout << *iter << " ";
	return os;
}
