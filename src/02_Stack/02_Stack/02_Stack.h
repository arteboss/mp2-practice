#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename ValType>
class TStack
{
private:
	ValType* elems;
	size_t size;
	size_t top;
public:
	//TStack();
	TStack(size_t);
	TStack(const TStack&);
	~TStack();
	void Push(ValType);
	void Pop();
	ValType Top() { return elems[top - 1]; }
	size_t GetTop() { return top; }
	bool IsEmpty() const;
	bool IsFull() const;
	TStack& operator=(const TStack&);
};

////////////////////////////////////////////////////////////////////////////////////

/*template<typename ValType>
TStack<ValType>::TStack()
{
	size = 0;
	top = 0;
}*/

template<typename ValType>
TStack<ValType>::TStack(size_t _size)
{
	size = _size;
	top = 0;
	elems = new ValType[size];
}

template<typename ValType>
TStack<ValType>::TStack(const TStack& tmp)
{
	if (tmp.top >= tmp.size) throw "Stack overflow";
	size = tmp.size;
	top = tmp.top;
	elems = new ValType[size];
	for (size_t i = 0; i < top; i++)
		elems[i] = tmp.elems[i];
}

template<typename ValType>
TStack<ValType>::~TStack()
{
	delete[] elems;
}

template<typename ValType>
void TStack<ValType>::Push(ValType tmp)
{
	if (IsFull()) throw "Stack is full";
	elems[top++] = tmp;
}

template<typename ValType>
void TStack<ValType>::Pop()
{
	if (IsEmpty()) throw "Stack is empty";
	top--;
}

template<typename ValType>
bool TStack<ValType>::IsEmpty() const
{
	return (top == 0);
}

template<typename ValType>
bool TStack<ValType>::IsFull() const
{
	return (top == size);
}

template<typename ValType>
TStack<ValType>& TStack<ValType>::operator=(const TStack& tmp)
{
	if (size != tmp.size)
	{
		size = tmp.size;
		delete[] elems;
		elems = new ValType[size];
	}
	for (size_t i = 0; i < size; i++)
		elems[i] = tmp.elems[i];
	return *this;
}