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
	void clear();

	int getSize() const { return size; }
	int getCapacity() const { return capacity; }

	Type& operator[](int index);

	template <class Type1>
	friend std::ostream& operator <<(std::ostream& os, const ArrayList<Type1>& array);

	class Iterator
	{
	protected:
		friend class ArrayList<Type>;
		Type* pt;
		int index;
		Iterator(ArrayList<Type>& p, int idx);
	public:
		Type& operator *();
		Iterator& operator ++();
		bool operator !=(const Iterator& it);
	};

	Iterator begin() { return Iterator(*this, 0); }
	Iterator end() { return Iterator(*this, size); }

	class const_Iterator
	{
	protected:
		friend class ArrayList<Type>;
		const Type* pt;
		int index;
		const_Iterator(const ArrayList<Type>& p, int idx);
	public:
		const Type& operator *();
		const_Iterator& operator ++();
		bool operator !=(const const_Iterator& it);
	};

	const_Iterator cbegin() const { return const_Iterator(*this, 0); }
	const_Iterator cend() const { return const_Iterator(*this, size); }
};

// method implementation ArrayList

template <class Type>
ArrayList<Type>::ArrayList() : size(0), capacity(0), array(0)
{
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
void ArrayList<Type>::clear()
{
	// not necessary to delete the array
	//if(array) delete[] array;
	//size = 0;
	//capacity = 0;

	size = 0;

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
	return os;
}


//	methods implementation for ArrayList::Iterator
template <class Type>
ArrayList<Type>::Iterator::Iterator(ArrayList<Type> &p, int idx) : pt(p.array), index(idx) {}

template <class Type>
Type& ArrayList<Type>::Iterator::operator *()
{
	return *(pt + index);
}

template <class Type>
typename ArrayList<Type>::Iterator& ArrayList<Type>::Iterator::operator ++()
{
	index++;
	return *this;
}

template <class Type>
bool ArrayList<Type>::Iterator::operator !=(const ArrayList<Type>::Iterator& it)
{
	return index != it.index;
}

//	methods implementation for ArrayList::const_Iterator
template <class Type>
ArrayList<Type>::const_Iterator::const_Iterator(const ArrayList<Type> &p, int idx) : pt(p.array), index(idx) {}

template <class Type>
const Type& ArrayList<Type>::const_Iterator::operator *()
{
	return *(pt + index);
}

template <class Type>
typename ArrayList<Type>::const_Iterator& ArrayList<Type>::const_Iterator::operator ++()
{
	index++;
	return *this;
}

template <class Type>
bool ArrayList<Type>::const_Iterator::operator !=(const ArrayList<Type>::const_Iterator& it)
{
	return index != it.index;
}

#endif // ARRAYLIST_H
