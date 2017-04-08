#include <iostream>
#include <unordered_map>
#include <string>
#include<cstring>
#include <algorithm>
#include "StudentManager.h"
#include "arraylist.h"
#include "stringarray.h"
#include "word.h"
#include "arrays.h"

using namespace std;


string generateRandomString(size_t length)
{
  const char* charmap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const size_t charmapLength = std::strlen(charmap);
  auto generator = [&](){ return charmap[rand()%charmapLength]; };
  string result;
  result.reserve(length);
  generate_n(back_inserter(result), length, generator);
  return result;
}

int main()
{
	mainArrays();

	return 0;

	//STOP ---

	ArrayList<int> ageList;
	StudentManager& manager = StudentManager::getInstance();
	for(int k=0;k<1000;k++)
	{
		string name = generateRandomString(5);
		manager.getNewStudent(name, k+30);
		ageList.add(k+30);
	}

	//cout << manager << endl;


	for(int k=1;k<10;k+=2)
	{
		manager.removeStudent((long)k);
	}

	//cout << manager << endl;

	//cout << ageList;
	ageList.pop();
	ageList.pop();
	//cout << ageList;


	StringArray arr("allez le losc");

	StringArray arr2(arr),arr3("il fait beau");

	cout << arr << endl;
	cout << arr2 << endl;
	cout << arr3 << endl;

	arr3 = arr;
	cout << arr3 << endl;

	Word w("csoL");
	w += "Losc";

	cout << w << endl;
	cout << (w.isPalyndrome() ? "palydrome" : "not palydrome") << endl;


	cout << w.toUpper() << endl;
	cout << w.toLower() << endl;
	cout << w.inverseCase() << endl;



	return 0;
}
