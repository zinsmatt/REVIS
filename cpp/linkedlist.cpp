#include <iostream>
#include "linkedlist.h"
#include <ostream>

using namespace std;


ostream& operator <<(ostream& os, Item* h)
{
	while(h)
	{
		os << h->value << " ";
		h = h->next;
	}
	return os;
}


void pushFront(Item **h, int v)
{
	if(h)
	{
		Item *nouv = new Item;
		nouv->value = v;
		pushFront(h,nouv);
	}
}

void pushFront(Item **h, Item *n)
{
	if(h)
	{
		n->next = *h;
		*h = n;
	}
}

void release(Item *h)
{
	if(h)
	{
		Item *n = h->next;
		while(h)
		{
			delete h;
			h = n;
			n = n->next;
		}
	}
}

void mainLinkedList()
{
	cout << "LinkedList" << endl;

	Item *list;

	for(int i=0;i<5;i++)
	{
		pushFront(&list,i);
		cout << list << endl;
	}
}
