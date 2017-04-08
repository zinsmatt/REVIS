#ifndef WORD_H
#define WORD_H
#include <string>
#include <ostream>


class Word
{
	std::string _str;
public:
	Word(const std::string& str) : _str(str) {}
	Word(const char* str) : _str(str) {}
	Word(char car);
	~Word() {}

	Word& operator +=(const Word& w);


	bool isPalyndrome() const;

	Word toLower() const;
	Word toUpper() const;
	Word inverseCase() const;



	friend std::ostream& operator <<(std::ostream& os, const Word& word);
};

#endif // WORD_H
