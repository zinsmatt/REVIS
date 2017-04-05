#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <cstring>
#include <stdexcept>
#include <ostream>


template <class Type>
class ArrayList
{
	int size;
	int capacity;
	Type* array;


public:
	ArrayList();
	ArrayList(int init_size, Type* values = 0);
	~ArrayList();

	bool resize(int newCapacity);

	bool add(Type elem);
	bool pop();

	Type& operator[](int index);

	template <class Type1>
	friend std::ostream& operator <<(std::ostream& os, const ArrayList<Type1>& array);
};

template <class Type>
ArrayList<Type>::ArrayList() : size(0), capacity(0), array(0)
{
	array = nullptr;
}

template <class Type>
ArrayList<Type>::ArrayList(int init_size, Type *values) : size(0), capacity(init_size), array(0)
{
	array = new Type[init_size];
	if(values)
	{
		size = init_size;
		memcpy(array,values,init_size*sizeof(Type));
	}
}

template <class Type>
ArrayList<Type>::~ArrayList()
{
	if(array)	delete[] array;
}

template <class Type>
bool ArrayList<Type>::resize(int newCapacity)
{
	if(newCapacity < size) return false;

	Type* temp = new Type[newCapacity];
	if(!temp) return false;

	if(array)
	{
		memcpy(temp,array,size*sizeof(Type));
		delete[] array;
	}
	array = temp;
	capacity = newCapacity;
	return true;
}

template <class Type>
bool ArrayList<Type>::add(Type elem)
{
	if(size==capacity)
		if(!resize(capacity*2+1))
			return false;
	array[size++]  =elem;
	return true;
}

template <class Type>
bool ArrayList<Type>::pop()
{
	if(size==0) return false;
	size--;
	return true;
}

template <class Type>
Type& ArrayList<Type>::operator [](int index)
{
	if(index < 0 || index >= size)
		throw std::invalid_argument("invalid index");
	else return array[index];
}

template <class Type>
std::ostream& operator <<(std::ostream& os, const ArrayList<Type> & array)
{
	for(int iter=0;iter<array.size; ++iter)
	{
		os << array.array[iter] << " ";
	}
	os << std::endl;
	return os;
}

#endif // ARRAYLIST_H
