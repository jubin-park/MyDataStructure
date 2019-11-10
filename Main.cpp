#include <cassert>

#include "SinglyLinkedList.h"

void Example_SinglyLinkedList();

int main()
{
	Example_SinglyLinkedList();
	return 0;
}

void Example_SinglyLinkedList()
{
	SinglyLinkedList sLL1;

	sLL1.Print();

	sLL1.Insert(0, 10);
	sLL1.Insert(1, 20);
	sLL1.Insert(2, 30);
	sLL1.Insert(99, 50);
	sLL1.Print();
	assert(sLL1.GetSize() == 4);

	sLL1.Insert(1, 70);
	sLL1.Print();
	assert(sLL1.GetSize() == 5);

	sLL1.Insert(0, 90);
	sLL1.Print();
	assert(sLL1.GetSize() == 6);

	sLL1.DeleteByIndex(0);
	sLL1.Print();
	assert(sLL1.GetSize() == 5);

	SinglyLinkedList sLL2(sLL1);

	sLL1.DeleteByIndex(1);
	sLL1.Print();
	assert(sLL1.GetSize() == 4);

	sLL1.DeleteByIndex(2);
	sLL1.Print();
	assert(sLL1.GetSize() == 3);

	sLL1.DeleteByIndex(9999);
	sLL1.DeleteByIndex(9999);
	sLL1.DeleteByIndex(9999);
	sLL1.DeleteByIndex(9999);
	sLL1.Print();
	assert(sLL1.IsEmpty());
}