#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList()
	: mSize(0)
	, mRootNode(nullptr)
{
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& other)
	: mSize(other.mSize)
	, mRootNode(nullptr)
{
	if (!IsEmpty())
	{
		mRootNode = new Node();
		mRootNode->Data = other.mRootNode->Data;
		mRootNode->Next = nullptr;
		Node* myNode = mRootNode;
		Node* otherNode = other.mRootNode;
		while (otherNode->Next != nullptr)
		{
			myNode->Next = new Node();
			myNode->Next->Data = otherNode->Next->Data;
			myNode = myNode->Next;
			otherNode = otherNode->Next;
		}
		myNode->Next = NULL;
	}
}

SinglyLinkedList::SinglyLinkedList(SinglyLinkedList&& other)
{
	mSize = other.mSize;
	mRootNode = other.mRootNode;
	other.mRootNode = nullptr;
	other.mSize = 0;
}

SinglyLinkedList& SinglyLinkedList::operator=(const SinglyLinkedList& other)
{
	if (this != &other)
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
		this->mSize = other.mSize;
		mRootNode = nullptr;
		// copy
		if (!IsEmpty())
		{
			mRootNode = new Node();
			mRootNode->Data = other.mRootNode->Data;
			mRootNode->Next = nullptr;
			Node* myNode = mRootNode;
			Node* otherNode = other.mRootNode;
			while (otherNode->Next != nullptr)
			{
				myNode->Next = new Node();
				myNode->Next->Data = otherNode->Next->Data;
				myNode = myNode->Next;
				otherNode = otherNode->Next;
			}
			myNode->Next = NULL;
		}
	}
	return *this;
}

SinglyLinkedList::~SinglyLinkedList()
{
	Node* currentNode = mRootNode;
	while (currentNode != nullptr)
	{
		Node* tempNode = currentNode->Next;
		delete currentNode;
		currentNode = tempNode;
	}
}

void SinglyLinkedList::Insert(size_t index, const int data)
{
	if (IsEmpty())
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