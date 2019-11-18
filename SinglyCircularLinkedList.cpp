#include "SinglyCircularLinkedList.h"

SinglyCircularLinkedList::SinglyCircularLinkedList()
	: mSize(0)
	, mRootNode(nullptr)
{
}

SinglyCircularLinkedList::~SinglyCircularLinkedList()
{
	if (!IsEmpty())
	{
		Node* currentNode = mRootNode;
		do
		{
			Node* tempNode = currentNode;
			currentNode = currentNode->Next;
			delete tempNode;
		} while (currentNode != mRootNode);
	}
}

void SinglyCircularLinkedList::Insert(size_t index, const int data)
{
	if (IsEmpty())
	{
		mRootNode = new Node();
		mRootNode->Data = data;
		mRootNode->Next = mRootNode;
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
		// changing root
		if (index == 0)
		{
			tempNode->Next = mRootNode;
			mRootNode = tempNode;
			// circular pointing
			Node* tailNode = mRootNode;
			for (size_t i = 0; i < mSize; ++i)
			{
				tailNode = tailNode->Next;
			}
			tailNode->Next = tempNode;
		}
		// adding tail
		else if (index == mSize)
		{
			// circular pointing
			tempNode->Next = mRootNode;
			currentNode->Next = tempNode;
		}
		else
		{
			tempNode->Next = currentNode->Next;
			currentNode->Next = tempNode;
		}
	}
	++mSize;
}

void SinglyCircularLinkedList::DeleteByIndex(size_t index)
{
	if (IsEmpty())
	{
		return;
	}
	if (index >= mSize)
	{
		index = mSize - 1;
	}
	// delete head
	if (index == 0)
	{
		Node* tempNode = mRootNode;
		mRootNode = mRootNode->Next;
		delete tempNode;
		// jump to tail
		Node* currentNode = mRootNode;
		for (size_t i = 2; i < mSize; ++i)
		{
			currentNode = currentNode->Next;
		}
		currentNode->Next = mRootNode;
	}
	// delete tail
	else if (index == mSize - 1)
	{
		Node* currentNode = mRootNode;
		for (size_t i = 1; i < index; ++i)
		{
			currentNode = currentNode->Next;
		}
		Node* tempNode = currentNode->Next;
		currentNode->Next = mRootNode;
		delete tempNode;
	}
	// others
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
	if (IsEmpty())
	{
		mRootNode = nullptr;
	}
}

inline bool SinglyCircularLinkedList::IsEmpty()
{
	return mSize == 0;
}

inline size_t SinglyCircularLinkedList::GetSize()
{
	return mSize;
}

void SinglyCircularLinkedList::Print()
{
	std::cout << '[';
	if (!IsEmpty())
	{
		Node* currentNode = mRootNode;
		do
		{
			std::cout << currentNode->Data;
			currentNode = currentNode->Next;
			if (currentNode != mRootNode)
			{
				std::cout << ", ";
			}
		} while (currentNode != mRootNode);
	}
	std::cout << ']' << std::endl;	
}