#include "word.h"
#include <ctype.h>
#include <sstream>
using namespace std;

Word::Word(char car)
{
	stringstream ss;
	ss << car;
	ss >> _str;
}

bool Word::isPalyndrome() const
{
	if(_str.size() < 1 || _str.size() == 2)
		return false;
	else if(_str.size() == 1)
		return true;
	else
	{
		int l = 0, r = _str.size() -1;
		bool pal = true;
		while(r-l>0)
		{
			if(_str[l] != _str[r])
			{
				pal = false;
				break;
			}
			l++;
			r--;
		}
		return pal;
	}
}

Word& Word::operator +=(const Word& w)
{
	_str += w._str;
	return *this;
}

Word Word::toLower() const
{
	Word word("");
	for(int iter=0;iter<_str.size(); ++iter)
	{
		word += tolower((int)_str[iter]);
	}
	return word;
}

Word Word::toUpper() const
{
	Word word("");
	for(int iter=0; iter < _str.size(); ++iter)
	{
		word += toupper((int) _str[iter]);
	}
	return word;
}

Word Word::inverseCase() const
{
	Word word("");
	for(int iter=0; iter <_str.size(); ++iter)
	{
		if(isupper((int)_str[iter]))
			word += tolower((int)_str[iter]);
		else if(islower((int)_str[iter]))
			word += toupper((int) _str[iter]);
		else
			word += _str[iter];
	}
	return word;
}


ostream& operator <<(ostream& os, const Word& word)
{
	os << word._str;
	return os;
}



