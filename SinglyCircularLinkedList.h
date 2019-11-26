#pragma once

#include <iostream>

class SinglyCircularLinkedList final
{
public:
	SinglyCircularLinkedList();
	SinglyCircularLinkedList(const SinglyCircularLinkedList& other);
	SinglyCircularLinkedList(SinglyCircularLinkedList&& other);
	SinglyCircularLinkedList& operator=(const SinglyCircularLinkedList& other);
	~SinglyCircularLinkedList();

	void Insert(size_t index, const int data);
	void DeleteByIndex(size_t index);
	bool IsEmpty();
	size_t GetSize();
	friend std::ostream& operator<<(std::ostream& os, const SinglyCircularLinkedList& rhs);

private:
	struct Node
	{
		int Data;
		Node* Next;
	};
	size_t mSize;
	Node* mRootNode;
};