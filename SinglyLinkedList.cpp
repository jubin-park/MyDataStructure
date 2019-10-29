#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList()
	: mSize(0)
	, mRootNode(nullptr)
{
}

SinglyLinkedList::~SinglyLinkedList()
{
	Node* currentNode = mRootNode;
	while (currentNode != nullptr)
	{
		Node* nextNode = currentNode->Next;
		delete currentNode;
		currentNode = nextNode;
	}
}

void SinglyLinkedList::Insert(size_t index, const int data)
{
	if (mSize == 0)
	{
		mRootNode = new Node();
		mRootNode->Data = data;
		mRootNode->Next = nullptr;
	}
	else
	{
		if (index > mSize)
		{
			index = mSize;
		}
		Node* currentNode = mRootNode;
		for (size_t i = 1; i < index; ++i)
		{
			currentNode = currentNode->Next;
		}
		Node* tempNode = new Node();
		tempNode->Data = data;
		if (index == 0)
		{
			tempNode->Next = mRootNode;
			mRootNode = tempNode;
		}
		else
		{
			tempNode->Next = currentNode->Next;
			currentNode->Next = tempNode;
		}
	}
	++mSize;
}

void SinglyLinkedList::DeleteByIndex(size_t index)
{
	if (mSize == 0)
	{
		return;
	}
	if (index >= mSize)
	{
		index = mSize - 1;
	}
	Node* currentNode = mRootNode;
	for (size_t i = 1; i < index; ++i)
	{
		currentNode = currentNode->Next;
	}
	if (index == 0)
	{
		Node* tempNode = mRootNode;
		mRootNode = mRootNode->Next;
		delete tempNode;
	}
	else
	{
		Node* tempNode = currentNode->Next;
		currentNode->Next = currentNode->Next->Next;
		delete tempNode;
	}
	--mSize;
}

bool SinglyLinkedList::IsEmpty()
{
	return mSize == 0;
}

size_t SinglyLinkedList::GetSize()
{
	return mSize;
}

void SinglyLinkedList::Print()
{
	Node* tempNode = mRootNode;
	std::cout << '[';
	while (tempNode != nullptr)
	{
		std::cout << tempNode->Data;
		if (tempNode->Next != nullptr)
		{
			std::cout << ", ";
		}
		tempNode = tempNode->Next;
	}
	std::cout << ']' << std::endl;
}