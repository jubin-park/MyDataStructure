#pragma once

template<typename T, size_t N>
class Queue final
{
public:
	Queue();
	~Queue();
	Queue(const Queue& other) = delete;
	Queue(Queue&& other) = delete;
	Queue& operator=(const Queue& other) = delete;
	Queue& operator=(Queue&& other) = delete;

	void PushBack(const T& item);
	void PopFront();
	T GetFront() const;
	inline size_t GetSize() const;
	inline size_t GetCapacity() const;
	inline bool IsEmpty() const;

private:
	struct Node
	{
		T Data;
		Node* Next;
	};
	size_t mSize;
	Node* mFrontNode;
	Node* mRoarNode;
};

template<typename T, size_t N>
Queue<T, N>::Queue()
	: mSize(0)
	, mFrontNode(nullptr)
	, mRoarNode(nullptr)
{
}

template<typename T, size_t N>
Queue<T, N>::~Queue()
{
	Node* currentNode = mFrontNode;
	while (currentNode != nullptr)
	{
		delete currentNode;
		currentNode = currentNode->Next;
	}
}

template<typename T, size_t N>
void Queue<T, N>::PushBack(const T& item)
{
	if (mSize == N)
	{
		return;
	}
	if (IsEmpty())
	{
		mFrontNode = new Node;
		mFrontNode->Data = item;
		mFrontNode->Next = nullptr;
	}
	else
	{
		if (mSize == 1)
		{
			mRoarNode = new Node;
			mRoarNode->Data = item;
			mRoarNode->Next = nullptr;
			mFrontNode->Next = mRoarNode;
		}
		else
		{
			mRoarNode->Next = new Node;
			mRoarNode->Next->Data = item;
			mRoarNode->Next->Next = nullptr;
			mRoarNode = mRoarNode->Next;
		}
	}
	++mSize;
}

template<typename T, size_t N>
void Queue<T, N>::PopFront()
{
	if (IsEmpty())
	{
		return;
	}
	Node* tempNode = mFrontNode;
	mFrontNode = mFrontNode->Next;
	delete tempNode;
	--mSize;
}

template<typename T, size_t N>
T Queue<T, N>::GetFront()
{
	assert(!IsEmpty());
	return mFrontNode->Data;
}

template<typename T, size_t N>
size_t Queue<T, N>::GetSize() const
{
	return mSize;
}

template<typename T, size_t N>
size_t Queue<T, N>::GetCapacity() const
{
	return N;
}

template<typename T, size_t N>
bool Queue<T, N>::IsEmpty() const
{
	return mSize == 0;
}