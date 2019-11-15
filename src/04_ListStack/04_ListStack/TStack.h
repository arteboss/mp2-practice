#pragma once
#include "TList.h"
template<typename ValType>
class TStack
{
public:
	virtual void Push(ValType) = 0;
	virtual void Pop() = 0;
	virtual ValType Top() const = 0;
	virtual size_t GetTop() const = 0;
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull() const = 0;
};

template <typename ValType>
class TArrayStack : public TStack<ValType>
{
private:
	int size;
	int top;
	ValType* elems;
public:
	TArrayStack(size_t);
	TArrayStack(const TArrayStack<ValType>&);
	~TArrayStack();
	void Push(ValType);
	void Pop();
	ValType Top() const { return elems[top - 1]; }
	size_t GetTop() const { return top; }
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
	size_t GetTop() const;
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
	elems = tmp;
}

template<typename ValType>
TListStack<ValType>::~TListStack()
{
	delete[] elems;
}

template<typename ValType>
void TListStack<ValType>::Push(ValType tmp)
{
	elems->InsertStart(tmp, nullptr);
}

template<typename ValType>
ValType TListStack<ValType>::Top() const
{
	return elems->First()->key;
}

template<typename ValType>
inline size_t TListStack<ValType>::GetTop() const
{
	return elems->First();
}

template<typename ValType>
void TListStack<ValType>::Pop()
{
	elems->Delete(elems->First()->key);
}

template<typename ValType>
bool TListStack<ValType>::IsEmpty() const
{
	return elems->IsEnded();
}

template<typename ValType>
bool TListStack<ValType>::IsFull() const
{
	TList<ValType, ValType>::TNode* temp = new TList<ValType, ValType>::TNode;
	if (temp == nullptr)
	{
		return true;
	}
	return false;
}
