#pragma once

#include <iostream>

template<typename DATA>
class DoublyLinkedList final
{
public:
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList<DATA>& other) = default;
	DoublyLinkedList(DoublyLinkedList<DATA>&& other) = default;
	DoublyLinkedList<DATA>& operator=(const DoublyLinkedList<DATA>& rhs) = default;
	~DoublyLinkedList() = default;

	void Insert(size_t index, const DATA& data);
	bool IsEmpty() const;
	size_t GetSize() const;


	struct Node
	{
		DATA Data;
		Node* Next;
		Node* Prev;
	};

private:

	Node* mRootNode;
	size_t mSize;
};

template<typename DATA>
DoublyLinkedList<DATA>::DoublyLinkedList()
	: mRootNode(nullptr)
	, mSize(0)
{
}

template<typename DATA>
void DoublyLinkedList<DATA>::Insert(size_t index, const DATA& data)
{
	if (IsEmpty())
	{
		mRootNode = new Node();
		mRootNode->Data = data;
		mRootNode->Next = nullptr;
		mRootNode->Prev = nullptr;
	}
	else
	{
		if (index > mSize)
		{
			index = mSize;
		}
		// head
		if (index == 0)
		{
			Node* tempNode = mRootNode;
			mRootNode = new Node();
			mRootNode->Data = data;
			mRootNode->Prev = nullptr;
			mRootNode->Next = tempNode;
			mRootNode->Next->Prev = mRootNode;
		}
		// tail
		else if (index == mSize)
		{
			Node* currentNode = mRootNode;
			for (int i = 1; i < mSize; ++i)
			{
				currentNode = currentNode->Next;
			}
			currentNode->Next = new Node();
			currentNode->Next->Data = data;
			currentNode->Next->Prev = currentNode;
			currentNode->Next->Next = nullptr;
		}
		// body
		else
		{
			Node* currentNode = mRootNode;
			for (size_t i = 1; i < index; ++i)
			{
				currentNode = currentNode->Next;
			}
			Node* newNode = new Node();
			newNode->Data = data;
			newNode->Next = currentNode->Next;
			currentNode->Next = newNode;
			newNode->Prev = currentNode;
			newNode->Next->Prev = newNode;
		}
	}
	++mSize;
}

template<typename DATA>
bool DoublyLinkedList<DATA>::IsEmpty() const
{
	return mSize == 0;
}

template<typename DATA>
size_t DoublyLinkedList<DATA>::GetSize() const
{
	return mSize;
}