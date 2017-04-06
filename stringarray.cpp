#include "stringarray.h"
#include <iostream>

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
			nouv = new string(s.substr(l,s.size()));
		}else
		{
			nouv = new string(s.substr(l,r-l));
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

