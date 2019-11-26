#pragma once

#include <iostream>

class SinglyLinkedList final
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
	friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& rhs);

private:
	struct Node
	{
		int Data;
		Node* Next;
	};
	size_t mSize;
	Node* mRootNode;
};
