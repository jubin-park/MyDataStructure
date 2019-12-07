#pragma once

template<typename T, size_t N>
class Stack
{
public:
	Stack();
	~Stack();
	Stack(const Stack& other) = delete;
	Stack(Stack&& other) = delete;
	Stack& operator=(const Stack& rhs) = delete;
	Stack& operator=(Stack&& rhs) = delete;

	void Push(const T& item);
	void Pop();
	T GetTop();
	inline size_t GetSize() const;
	inline size_t GetCapacity() const;
	inline bool IsEmpty() const;

private:
	struct Node
	{
		T Data;
		Node* Next;
	};
	size_t mTop;
	Node* mRootNode;
};

template<typename T, size_t N>
Stack<T, N>::Stack()
	: mTop(0)
	, mRootNode(nullptr)
{
}

template<typename T, size_t N>
Stack<T, N>::~Stack()
{
	Node* currentNode = mRootNode;
	while (currentNode != nullptr)
	{
		Node* tempNode = currentNode->Next;
		delete currentNode;
		currentNode = tempNode;
	}
}

template<typename T, size_t N>
void Stack<T, N>::Push(const T& item)
{
	if (mTop == N)
	{
		return;
	}
	Node* tempNode = mRootNode;
	mRootNode = new Node();
	mRootNode->Data = item;
	mRootNode->Next = tempNode;
	++mTop;
}

template<typename T, size_t N>
void Stack<T, N>::Pop()
{
	if (mTop == 0)
	{
		return;
	}
	Node* tempNode = mRootNode;
	mRootNode = mRootNode->Next;
	delete tempNode;
	--mTop;
}

template<typename T, size_t N>
T Stack<T, N>::GetTop()
{
	assert(mRootNode != nullptr);
	return mRootNode->Data;
}

template<typename T, size_t N>
size_t Stack<T, N>::GetSize() const
{
	return mTop;
}

template<typename T, size_t N>
size_t Stack<T, N>::GetCapacity() const
{
	return N;
}

template<typename T, size_t N>
bool Stack<T, N>::IsEmpty() const
{
	return mTop == 0;
}