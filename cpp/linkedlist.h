#ifndef LINKEDLIST
#define LINKEDLIST


struct Item
{
	int value;
	Item* next;
};

void pushFront(Item* h, Item* n);

void mainLinkedList();

void pushFront(Item** h, int v);
void pushFront(Item** h, Item* n);

#endif // LINKEDLIST

