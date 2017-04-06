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

	friend std::ostream& operator <<(std::ostream& os, const StringArray& arr);

	class Iterator : public ArrayList<std::string*>::Iterator
	{
		friend class StringArray;
		Iterator(StringArray& array, int pos) : ArrayList<std::string*>::Iterator(array.words, pos) {}

	public:
		std::string& operator *() { return *(this->ArrayList<std::string*>::Iterator::operator *()); }
		Iterator& operator ++() { return static_cast<Iterator&>(this->ArrayList<std::string*>::Iterator::operator ++()); }
		bool operator !=(const Iterator& it) { return this->ArrayList<std::string*>::Iterator::operator !=(it); }
	};

	Iterator begin() { return Iterator(*this,0); }
	Iterator end() { return Iterator(*this,words.getSize()); }


	class const_Iterator : public ArrayList<std::string*>::const_Iterator
	{
		friend class StringArray;
		const_Iterator(const StringArray& array, int pos) : ArrayList<std::string*>::const_Iterator(array.words, pos) {}

	public:
		const std::string& operator *() { return *(this->ArrayList<std::string*>::const_Iterator::operator *()); }
		const_Iterator& operator ++() { return static_cast<const_Iterator&>(this->ArrayList<std::string*>::const_Iterator::operator ++()); }
		bool operator !=(const const_Iterator& it) { return this->ArrayList<std::string*>::const_Iterator::operator !=(it); }
	};

	const_Iterator cbegin() const { return const_Iterator(*this,0); }
	const_Iterator cend() const { return const_Iterator(*this,words.getSize()); }
};

#endif // STRINGARRAY_H
