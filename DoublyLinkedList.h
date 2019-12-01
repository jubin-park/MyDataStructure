#pragma once

#include <iostream>

template<typename DATA>
class DoublyLinkedList final
{
public:
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList<DATA>& other);
	DoublyLinkedList(DoublyLinkedList<DATA>&& other);
	DoublyLinkedList<DATA>& operator=(const DoublyLinkedList<DATA>& rhs);
	~DoublyLinkedList();

	void Insert(size_t index, const DATA& data);
	void DeleteByIndex(size_t index);
	bool IsEmpty() const;
	size_t GetSize() const;

	friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<DATA>& rhs)
	{
		Node* tempNode = rhs.mRootNode;
		os << '[';
		while (tempNode != nullptr)
		{
			os << tempNode->Data;
			if (tempNode->Next != nullptr)
			{
				os << ", ";
			}
			tempNode = tempNode->Next;
		}
		os << ']';
		return os;
	}

private:
	struct Node
	{
		DATA Data;
		Node* Next;
		Node* Prev;
	};
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
DoublyLinkedList<DATA>::DoublyLinkedList(const DoublyLinkedList<DATA>& other)
	: mRootNode(nullptr)
	, mSize(other.mSize)
{
	if (!IsEmpty())
	{
		mRootNode = new Node();
		mRootNode->Data = other.mRootNode->Data;
		mRootNode->Next = nullptr;
		mRootNode->Prev = nullptr;
		Node* myNode = mRootNode;
		Node* otherNode = other.mRootNode;
		while (otherNode->Next != nullptr)
		{
			myNode->Next = new Node();
			myNode->Next->Data = otherNode->Next->Data;
			myNode->Next->Prev = otherNode->Next->Prev;
			myNode = myNode->Next;
			otherNode = otherNode->Next;
		}
		myNode->Next = nullptr;
	}
}

template<typename DATA>
DoublyLinkedList<DATA>::DoublyLinkedList(DoublyLinkedList<DATA>&& other)
	: mRootNode(other.mRootNode)
	, mSize(other.mSize)
{
	other.mRootNode = nullptr;
	other.mSize = 0;
}

template<typename DATA>
DoublyLinkedList<DATA>& DoublyLinkedList<DATA>::operator=(const DoublyLinkedList<DATA>& rhs)
{
	if (this != &rhs)
	{
		// delete
		Node* currentNode = mRootNode;
		while (currentNode != nullptr)
		{
			Node* tempNode = currentNode->Next;
			delete currentNode;
			currentNode = tempNode;
		}
		// initialization
		this->mSize = rhs.mSize;
		mRootNode = nullptr;
		// copy
		if (!IsEmpty())
		{
			mRootNode = new Node();
			mRootNode->Data = rhs.mRootNode->Data;
			mRootNode->Next = nullptr;
			mRootNode->Prev = nullptr;
			Node* myNode = mRootNode;
			Node* otherNode = rhs.mRootNode;
			while (otherNode->Next != nullptr)
			{
				myNode->Next = new Node();
				myNode->Next->Data = otherNode->Next->Data;
				myNode->Next->Prev = otherNode->Next->Prev;
				myNode = myNode->Next;
				otherNode = otherNode->Next;
			}
			myNode->Next = nullptr;
		}
	}
	return *this;
}

template<typename DATA>
DoublyLinkedList<DATA>::~DoublyLinkedList()
{
	Node* currentNode = mRootNode;
	while (currentNode != nullptr)
	{
		Node* tempNode = currentNode->Next;
		delete currentNode;
		currentNode = tempNode;
	}
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
			for (size_t i = 1; i < mSize; ++i)
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
void DoublyLinkedList<DATA>::DeleteByIndex(size_t index)
{
	if (IsEmpty())
	{
		return;
	}
	if (index >= mSize)
	{
		index = mSize - 1;
	}
	if (index == 0)
	{
		Node* tempNode = mRootNode;
		mRootNode = mRootNode->Next;
		delete tempNode;
		mRootNode->Prev = nullptr;
	}
	else if (index == mSize - 1)
	{
		Node* currentNode = mRootNode;
		for (size_t i = 1; i < index; ++i)
		{
			currentNode = currentNode->Next;
		}
		delete currentNode->Next;
		currentNode->Next = nullptr;
	}
	else
	{
		Node* currentNode = mRootNode;
		for (size_t i = 1; i < index; ++i)
		{
			currentNode = currentNode->Next;
		}
		Node* tempNode = currentNode->Next;
		currentNode->Next = currentNode->Next->Next;
		currentNode->Next->Prev = currentNode;
		delete tempNode;
	}
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
