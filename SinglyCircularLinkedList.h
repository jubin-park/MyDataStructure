#pragma once

#include <iostream>

class SinglyCircularLinkedList
{
public:
	SinglyCircularLinkedList();
	//SinglyCircularLinkedList(const SinglyCircularLinkedList& other);
	//SinglyCircularLinkedList(SinglyCircularLinkedList&& other);
	//SinglyCircularLinkedList& operator=(const SinglyCircularLinkedList& other);
	~SinglyCircularLinkedList();

	void Insert(size_t index, const int data);
	void DeleteByIndex(size_t index);
	inline bool IsEmpty();
	inline size_t GetSize();
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