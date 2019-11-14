#pragma once

#include <iostream>

class SinglyLinkedList
{
public:
	SinglyLinkedList();
	SinglyLinkedList(const SinglyLinkedList& other);
	SinglyLinkedList(SinglyLinkedList&& other);
	SinglyLinkedList& operator=(const SinglyLinkedList& other);
	~SinglyLinkedList();

	void Insert(size_t index, const int data);
	void DeleteByIndex(size_t index);
	bool IsEmpty();
	size_t GetSize();
	void Print();

private:
	struct Node
	{
		int Data;
		Node* Next;
	};
	size_t mSize;
	Node* mRootNode;
};
