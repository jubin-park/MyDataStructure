#include <cassert>

#include "SinglyLinkedList.h"
#include "SinglyCircularLinkedList.h"
#include "DoublyLinkedList.h"
#include "Stack.h"
#include "Queue.h"

void Example_SinglyLinkedList();
void Example_SinglyCircularLinkedList();
void Example_DoublyLinkedList();
void Example_Stack();
void Example_Queue();

int main()
{
	//Example_SinglyLinkedList();
	//Example_SinglyCircularLinkedList();
	//Example_DoublyLinkedList();
	//Example_Stack();
	Example_Queue();
	return 0;
}

void Example_SinglyLinkedList()
{
	SinglyLinkedList sLL1;

	std::cout << sLL1 << std::endl;

	sLL1.Insert(0, 10);
	sLL1.Insert(1, 20);
	sLL1.Insert(2, 30);
	sLL1.Insert(99, 50);
	std::cout << sLL1 << std::endl;
	assert(sLL1.GetSize() == 4);

	sLL1.Insert(1, 70);
	std::cout << sLL1 << std::endl;
	assert(sLL1.GetSize() == 5);

	sLL1.Insert(0, 90);
	std::cout << sLL1 << std::endl;
	assert(sLL1.GetSize() == 6);

	sLL1.DeleteByIndex(0);
	std::cout << sLL1 << std::endl;
	assert(sLL1.GetSize() == 5);

	SinglyLinkedList sLL2(sLL1);
	SinglyLinkedList sLL3;
	sLL3.Insert(0, 111);
	sLL3.Insert(0, 333);
	sLL3.Insert(0, 555);
	sLL3 = sLL2;

	SinglyLinkedList sLL4(std::move(sLL2));

	sLL1.DeleteByIndex(1);
	std::cout << sLL1 << std::endl;
	assert(sLL1.GetSize() == 4);

	sLL1.DeleteByIndex(2);
	std::cout << sLL1 << std::endl;
	assert(sLL1.GetSize() == 3);

	sLL1.DeleteByIndex(9999);
	sLL1.DeleteByIndex(9999);
	sLL1.DeleteByIndex(9999);
	sLL1.DeleteByIndex(9999);
	std::cout << sLL1 << std::endl;
	assert(sLL1.IsEmpty());
}

void Example_SinglyCircularLinkedList()
{
	SinglyCircularLinkedList sCLL1;
	std::cout << sCLL1 << std::endl;
	sCLL1.Insert(0, 100);
	std::cout << sCLL1 << std::endl;
	sCLL1.Insert(0, 200);
	std::cout << sCLL1 << std::endl;
	sCLL1.Insert(1, 300);
	std::cout << sCLL1 << std::endl;
	sCLL1.Insert(3, 400);
	std::cout << sCLL1 << std::endl;
	sCLL1.Insert(6, 500);
	std::cout << sCLL1 << std::endl;

	SinglyCircularLinkedList sCLL2;
	sCLL2.Insert(0, 11);
	sCLL2.Insert(3, 33);
	sCLL2.Insert(1, 22);

	SinglyCircularLinkedList sCLL3(sCLL1);

	sCLL3 = sCLL2;

	SinglyCircularLinkedList sCLLEmpty;
	sCLL3 = sCLLEmpty;

	SinglyCircularLinkedList sCCL4(std::move(sCLL1));
}

void Example_DoublyLinkedList()
{
	DoublyLinkedList<int> dLL1;
	std::cout << dLL1 << std::endl;
	dLL1.Insert(0, 1);
	dLL1.Insert(0, 2);
	dLL1.Insert(0, 3);
	dLL1.Insert(0, 4);
	dLL1.Insert(0, 5);
	dLL1.Insert(3, 100);
	std::cout << dLL1 << std::endl;
}

void Example_Stack()
{
	Stack<int, 5> st1;
	std::cout << "Capacity : " << st1.GetCapacity() << '\n';
	// st1.GetTop() // crash;
	st1.Push(10);
	st1.Push(30);
	st1.Push(50);
	st1.Push(70);
	st1.Push(90);
	st1.Push(110);

	std::cout << "Size : " << st1.GetSize() << '\n';

	while (!st1.IsEmpty())
	{
		std::cout << st1.GetTop() << '\n';
		st1.Pop();
	}
}

void Example_Queue()
{
	Queue<char, 4> que1;
	std::cout << "Capacity : " << que1.GetCapacity() << '\n';
	// que1.GetFront(); // crash

	que1.PushBack('d');
	que1.PushBack('u');
	que1.PushBack('m');
	que1.PushBack('p');
	que1.PushBack('!');

	while (!que1.IsEmpty())
	{
		std::cout << que1.GetFront() << ' ';
		que1.PopFront();
	}

	que1.PushBack('a');
	que1.PushBack('b');
	std::cout << "Now Size : " << que1.GetSize() << '\n';
}