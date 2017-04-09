#include "arrays.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>
//#define NO_STL



using namespace std;

int max(int a, int b, int c)
{
	return max(a,max(b,c));
}

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

void maxSubArray(int* a, int size)
{
	// find the sub array with the maximal sum

	// 1. O(n^3)	probably not the best
	// 2. O(n)		check if by adding the previous sum is better than just keeping the current elem
	int version = 2;

	switch(version)
	{
		case 1:
		{
			int maxSum = -99999;
			int l=0,r=0;
			for(int x1=0;x1<size;x1++)
			{
				for(int x2=x1;x2<size;x2++)
				{
					int sum = 0;
					for(int x3=x1;x3<=x2;x3++)
					{
						sum += a[x3];
					}
					if(sum>maxSum)
					{
						maxSum = sum;
						l = x1;
						r = x2;
					}
				}
			}
			for(int k=l;k<=r;k++)
				cout << a[k] << " ";
			cout << "==> " << maxSum << endl;
		}
		case 2:
		{
			int maxSum = a[0], sumEndingHere = a[0];
			int l=0,r=0,bestL = 0, bestR = 0;
			for(int iter=1;iter<size;++iter)
			{
				if(sumEndingHere + a[iter] < a[iter])
				{
					l = iter;
					r = iter;
					sumEndingHere = a[iter];
				}else
				{
					r = iter;
					sumEndingHere += a[iter];
				}

				if(sumEndingHere > maxSum)
				{
					maxSum = sumEndingHere;
					bestL = l;
					bestR = r;
				}
			}

			for(int k=bestL;k<=bestR;++k)
				cout << a[k] << " ";
			cout << "==> " << maxSum << endl;
		}
	}


}


int partition(int* array, int l0, int r0, int k)
{
	int l=l0, r=r0-1;
	swap(array+r0,array+k-1);
	while(l<r)
	{
		while(r>=l0 && array[r]<=array[r0])	r--;
		while(array[l]>array[r0])	l++;

		if(l<r)
			swap(array+l, array+r);
	}

	if(array[r0]>array[l])
		swap(array+r0, array+l);

	if(l+1 == k)
	{
		return l;
	}else if(l+1 < k)
	{
		return partition(array,l+1,r0,k);
	}else
	{
		return partition(array,l0,l-1,k);
	}
}

void KthLargest(int *a, int size, int k)
{
	// find the kth largest element as it would appear in the sorted array
	// quick sort select : after partitioning we know the pivot is the kth elem
	//						then continue with the higher or lower part
	// average O(n)
	cout << "kth-largest ==> " << a[partition(a,0,size-1,k)] << endl;
}

void findAllDuplicates(int* a, int size)
{
	// find all the duplicates in O(n) without extra memory
	//	1 <= a[i] <= size
	// O(n)

	vector<int> duplicates;
	for(int iter = 0; iter < size; iter++)
	{
		int idx = abs(a[iter])-1;
		if(a[idx]<0)
		{
			duplicates.push_back(idx+1);
		}
		a[idx] *= -1;
	}
	for(auto k : duplicates)
		cout << k << " ";
	cout << endl;
}

int partitionIncreasing(int *a, int l, int r)
{
	if(l>r) return 0;
	else if(r-l == 0) return 1;
	else if(r-l == 1 && a[r]>a[l]) return 2;
	else
	{
		int mid = (l+r)/2;
		int ll=1,rr=1;
		while(mid-ll>=l && a[mid-ll]<a[mid-ll+1])	ll++;
		while(mid+rr<=r && a[mid+rr]>a[mid+rr-1]) rr++;
		return max((1+rr-1+ll-1), partitionIncreasing(a,l,mid-ll), partitionIncreasing(a,mid+rr,r));
	}
}

void longestIncreasingSequence(int* a, int size)
{
	// find the length of the longest increasing sequence
	// 1. O(n^2)
	// 2. O(nlog(n))binary expand around the middle and then compare with outside part

	int version = 2;
	switch(version)
	{
		case 1:
		{
			int maxLength = 0;
			for(int iter=0; iter<size; iter++)
			{
				int length = 1;
				while(a[iter+length]>a[iter+length-1])
					length++;
				if(length > maxLength)
					maxLength = length;
			}
			cout << maxLength << endl;

			break;
		}
		case 2:
		{
			cout << partitionIncreasing(a,0,size-1) << endl;
			break;
		}
	}
}

void shuffle(int *a, int size)
{
	// O(n)

	for(int iter=0; iter < size; iter++)
	{
		int idx = iter + rand() % (size - iter);
		swap(a+iter,a+idx);
	}
}

void findMinInRotatedSorteArray(int* a, int size)
{
	// find the minimum value in an rotated sorted array
	// 1. O(n)
	// 2. O(log(n))
	int version=2;
	switch(version)
	{
		case 1:
		{
			int prev = size-1;
			int idx = 0;
			while(a[idx]>a[prev])
			{
				prev = idx;
				idx = (idx+1)%size;
			}
			cout << a[idx] << endl;
			break;
		}
		case 2:
		{
			// if a[middle] > a[last] => th eminimum is on the right of mid
			// if a[mid] < a[last] => the minimum is on the left of mid
			int l = 0;
			int r = size-1;

			while(l<r)
			{
				int mid = (l+r)/2;

				if(mid == r || mid == l)
				{
					cout << min(a[mid],min(a[l],a[r])) << endl;
					return;
				}

				if(a[mid]>a[r])
					l = mid+1;
				else
					r = mid;
			}
			cout << a[l] << endl;
			break;
		}
	}


}


void mainArrays()
{

	srand(time(NULL));
	int array[] = {2,3,4,5,6,7,8,9};
	int size = 8;

	//reverseArray(array,size);
	//reverseArray(array,array+size-1);
	//rotateArray(array,size,-4);

	//duplicate(array,size);

	//findPeak(array,size);

	//maxSubArray(array,size);

	//KthLargest(array,size,1);

	//findAllDuplicates(array,size);

	//longestIncreasingSequence(array, size);

	//shuffle(array,size);

	findMinInRotatedSorteArray(array,size);

	print(array, size);
}
