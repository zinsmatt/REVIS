#ifndef STRINGARRAY_H
#define STRINGARRAY_H
#include "arraylist.h"
#include "word.h"

class StringArray
{

	ArrayList<Word*> words;

public:
	StringArray(const std::string& s);

	// manage deep copy
	StringArray& operator =(const StringArray& base);
	StringArray(const StringArray& base);
	~StringArray();

	friend std::ostream& operator <<(std::ostream& os, const StringArray& arr);

	class Iterator : public ArrayList<Word*>::Iterator
	{
		friend class StringArray;
		Iterator(StringArray& array, int pos) : ArrayList<Word*>::Iterator(array.words, pos) {}

	public:
		Word& operator *() { return *(this->ArrayList<Word*>::Iterator::operator *()); }
		Iterator& operator ++() { return static_cast<Iterator&>(this->ArrayList<Word*>::Iterator::operator ++()); }
		bool operator !=(const Iterator& it) { return this->ArrayList<Word*>::Iterator::operator !=(it); }
	};

	Iterator begin() { return Iterator(*this,0); }
	Iterator end() { return Iterator(*this,words.getSize()); }


	class const_Iterator : public ArrayList<Word*>::const_Iterator
	{
		friend class StringArray;
		const_Iterator(const StringArray& array, int pos) : ArrayList<Word*>::const_Iterator(array.words, pos) {}

	public:
		const Word& operator *() { return *(this->ArrayList<Word*>::const_Iterator::operator *()); }
		const_Iterator& operator ++() { return static_cast<const_Iterator&>(this->ArrayList<Word*>::const_Iterator::operator ++()); }
		bool operator !=(const const_Iterator& it) { return this->ArrayList<Word*>::const_Iterator::operator !=(it); }
	};

	const_Iterator cbegin() const { return const_Iterator(*this,0); }
	const_Iterator cend() const { return const_Iterator(*this,words.getSize()); }
};

#endif // STRINGARRAY_H
