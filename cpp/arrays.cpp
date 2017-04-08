#include "arrays.h"
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>

//#define NO_STL



using namespace std;

void print(int* array, int size)
{
	for(int k=0;k<size;k++)
		cout << array[k] << " ";
	cout << endl;
}


void swap(int* a, int* b)
{
	if(a != b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

void reverseArray(int *l, int* r)
{
	while(l<r)
	{
		swap(l++,r--);
	}
}

void reverseArray(int* array, int size)
{
	//O(n/2) -> O(n)

	for(int k=0; k<size/2; k++)
	{
		swap(array+k, array+size-1-k);
	}
}

void rotateArray(int *array, int size, int k)
{
	// O(n) + O(n) -> O(n)
	int dec = k%size;
	if(dec>0)
	{
		reverseArray(array,size);
		reverseArray(array,array+dec-1);
		reverseArray(array+dec,array+size-1);
	}else
	{	dec *= -1;
		reverseArray(array,size);
		reverseArray(array+size-dec,array+size-1);
		reverseArray(array,array+size-1-dec);
	}
}

void duplicate(int *array, int size)
{	// return print if ther is a duplicate number
	// 1. O(n^2)
	// 2. O(n) ( unordered_set access in O(1))
#ifdef NO_STL
	for(int iter=0; iter < size; iter++)
	{
		for(int iter2=iter+1;iter2<size; iter2++)
			if(array[iter] == array[iter2])
			{
				cout << "True" << endl;
				return;
			}
	}
	cout << "False" << endl;

#else
	unordered_set<int> temp;
	for(int iter=0; iter<size; iter++)
	{
		pair<unordered_set<int>::iterator, bool> ret = temp.insert(array[iter]);
		if(ret.second == false)
		{
			cout << "True" << endl;
			return;
		}
	}
	cout << "False" << endl;
#endif
}

void findPeak(int* a, int size)
{
	// peak element if prev and succ are lower
	// assume array[k]!=array[k+1] for all
	// assume array[-1] = array[size] = -INF
	// print the index of one of the peaks or -1

	//1. O(n)
	//2. O(log(n))

	int version = 2;

	switch(version)
	{
		case 1:
		{
			bool increasing = 1;
			for(int k=0;k<size;k++)
			{
				if(increasing && (k==size-1 || a[k+1]<a[k]))
				{
					cout << k << " : " << a[k] << endl;
					return;
				}
				if(a[k]>a[k+1])
					increasing = false;
				else
					increasing = true;
			}

			cout << "-1" << endl;
			break;
		}
		case 2:
		{
			// binary search
			// check if middle is the peak
			// if not : if descending go to the left
			//			if ascending go to the right
			int l = 0;
			int r = size-1;

			if(size == 1)
				cout << "0 : " << a[0] << endl;
			else
			{
				while(l<r)
				{
					int mid = (l+r) / 2;

					if(mid == 0 && a[mid]>a[mid+1])
					{
						cout << "0 : " << a[0] << endl;
						return;
					}else if(mid == size-1 && a[mid-1]<a[mid])
					{
						cout << size-1 << " : " << a[size-1] << endl;
						return;
					}else
					{
						if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
						{
							cout << mid << " : " << a[mid] << endl;
							return;
						}else if(a[mid]>a[mid-1])
						{
							l = mid+1;
						}else if(a[mid]>a[mid+1])
						{
							r = mid-1;
						}
					}
				}

				if(a[l] > a[l-1] && a[l] > a[l+1])
					cout << l << " : " << a[l] << endl;
			}
			break;
		}
	}
}


void mainArrays()
{
	int array[] = {0,-1,2,4,30,31};
	int size = 6;

	//reverseArray(array,size);
	//reverseArray(array,array+size-1);
	//rotateArray(array,size,-4);

	//duplicate(array,size);

	findPeak(array,size);

	print(array, size);
}
