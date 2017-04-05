#include <iostream>
#include <unordered_map>
#include <string>
#include<cstring>
#include <algorithm>
#include "StudentManager.h"
#include "arraylist.h"

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

int main(int argc, char const *argv[])
{

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

	cout << ageList;
	ageList.pop();
	ageList.pop();
	cout << ageList;
	return 0;
}
