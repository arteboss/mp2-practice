#pragma once
#pragma once
#include "TList.h"
template<typename ValType>
class TStack
{
public:
	virtual void Push(ValType) = 0;
	virtual void Pop() = 0;
	virtual ValType Top() const = 0;
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull() const = 0;
};

template <typename ValType>
class TArrayStack : public TStack<ValType>
{
private:
	size_t size;
	int top;
	ValType* elems;
public:
	TArrayStack(size_t);
	TArrayStack(const TArrayStack<ValType>&);
	~TArrayStack();
	void Push(ValType);
	void Pop();
	ValType Top() const { return elems[top - 1]; }
	bool IsEmpty() const;
	bool IsFull() const;
};

template<typename ValType>
TArrayStack<ValType>::TArrayStack(size_t _size)
{
	size = _size;
	top = 0;
	elems = new ValType[size];
}

template<typename ValType>
TArrayStack<ValType>::TArrayStack(const TArrayStack& tmp)
{
	if (tmp.top >= tmp.size) throw "Stack overflow";
	size = tmp.size;
	top = tmp.top;
	elems = new ValType[size];
	for (size_t i = 0; i < top; i++)
		elems[i] = tmp.elems[i];
}

template<typename ValType>
TArrayStack<ValType>::~TArrayStack()
{
	delete[] elems;
}

template<typename ValType>
void TArrayStack<ValType>::Push(ValType tmp)
{
	if (IsFull()) throw "Stack is full";
	elems[top++] = tmp;
}

template<typename ValType>
void TArrayStack<ValType>::Pop()
{
	if (IsEmpty()) throw "Stack is empty";
	top--;
}

template<typename ValType>
bool TArrayStack<ValType>::IsEmpty() const
{
	return (top == 0);
}

template<typename ValType>
bool TArrayStack<ValType>::IsFull() const
{
	return (top == size);
}




template<typename ValType>
class TListStack : public TStack<ValType>
{
private:
	TList<ValType, ValType>* elems;
public:
	TListStack();
	TListStack(const TListStack<ValType>&);
	~TListStack();
	void Push(ValType);
	void Pop();
	ValType Top() const;
	bool IsEmpty() const;
	bool IsFull() const;
};

template<typename ValType>
TListStack<ValType>::TListStack()
{
	elems = new TList<ValType, ValType>;
}

template<typename ValType>
TListStack<ValType>::TListStack(const TListStack<ValType> & tmp)
{
	elems = new TList<ValType, ValType>(tmp);
}

template<typename ValType>
TListStack<ValType>::~TListStack()
{
	delete elems;
}

template<typename ValType>
void TListStack<ValType>::Push(ValType tmp)
{
	elems->InsertStart(tmp, nullptr);
}

template<typename ValType>
ValType TListStack<ValType>::Top() const
{
	if (IsEmpty()) return -1;
	return elems->First()->key;
}

template<typename ValType>
void TListStack<ValType>::Pop()
{
	if (IsEmpty()) return;
	elems->Remove(elems->First()->key);
}

template<typename ValType>
bool TListStack<ValType>::IsEmpty() const
{
	return elems->Current() == nullptr;
}

template<typename ValType>
bool TListStack<ValType>::IsFull() const
{
	try
	{
		TNode<ValType, ValType>* temp = new TNode<ValType, ValType>;
		if (temp == nullptr)
		{
			return true;
		}
		delete temp;
		return false;
	}
	catch (...)
	{
		return true;
	}
}
