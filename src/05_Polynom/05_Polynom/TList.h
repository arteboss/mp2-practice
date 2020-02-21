#pragma once
#include "TNode.h"

template<typename TKey, typename TData>
struct TList
{
	TNode<TKey, TData>* pFirst;
	TNode<TKey, TData>* pNext;
	TNode<TKey, TData>* pPrev;
	TNode<TKey, TData>* pCurrent;

	TList();
	TList(const TNode<TKey, TData>*);
	TList(const TList&);
	~TList();

	TNode<TKey, TData>* Search(TKey, char);
	void InsertStart(TKey, TData);
	void InsertEnd(TKey, TData);
	void InsertBefore(TKey, TKey, TData);
	void InsertAfter(TKey, TKey, TData);
	void Remove(TKey);
	void Remove(TNode<TKey, TData>*);
	void DeleteAll();

	TNode<TKey, TData>* Current();
	TNode<TKey, TData>* Prev();
	TNode<TKey, TData>* First();

	void Reset();
	bool IsEnded() const;
	bool Empty() const;
	void Next();

	friend std::ostream& operator<<(std::ostream& out, const TList<TKey, TData>& temp)
	{
		TNode<TKey, TData>* first = temp.pFirst;
		out << "-------------------------\n";
		while (first)
		{
			out << "{ key: " << first->key << " ; data: " << first->data << " }\n";
			out << "-------------------------\n";
			out << " |\n";
			out << "-------------------------\n";
			first = first->pNext;
		}
		return out;
	}
};


template<typename TKey, typename TData>
TList<TKey, TData>::TList()
{
	pCurrent = nullptr;
	pFirst = nullptr;
	pPrev = nullptr;
	pNext = nullptr;
}

template<typename TKey, typename TData>
TList<TKey, TData>::TList(const TNode<TKey, TData>* temp) : TList()
{
	if (!temp)
		return;
	pFirst = new TNode<TKey, TData>(*temp);
	TNode<TKey, TData>* node = temp->pNext, *prev = pFirst;
	while (node)
	{
		TNode<TKey, TData>* tmp = new TNode<TKey, TData>(*node);
		prev->pNext = tmp;
		prev = tmp;
		node = node->pNext;
	}
	Reset();
}

template<typename TKey, typename TData>
TList<TKey, TData>::TList(const TList& temp) : TList()
{
	if (!temp.pFirst)
		return;
	if (pFirst)
		delete pFirst;
	pFirst = new TNode<TKey, TData>(*temp.pFirst);
	TNode<TKey, TData>* node = temp.pFirst->pNext, * prev = pFirst;
	while (node)
	{
		TNode<TKey, TData>* tmp = new TNode<TKey, TData>(*node);
		prev->pNext = tmp;
		prev = tmp;
		node = node->pNext;
	}
	Reset();
}

template<typename TKey, typename TData>
TList<TKey, TData>::~TList()
{
	if (pCurrent != pFirst)
		Reset();
	while (!IsEnded())
	{
		Next();
		delete pPrev;
	}
}

template<typename TKey, typename TData>
TNode<TKey, TData>* TList<TKey, TData>::Search(TKey _key, char a)
{
	if (!pFirst)
		throw "List is empty";
	TNode<TKey, TData>* temp = new TNode<TKey, TData>;
	if (a == 0)
	{
		if (pCurrent != pFirst)
			Reset();
		temp = pFirst;
	}
	else
		temp = pCurrent;
	while (temp)
	{
		if (temp->key == _key)
			return temp;
		temp = temp->pNext;
	}
	return nullptr;
}

template<typename TKey, typename TData>
void TList<TKey, TData>::InsertStart(TKey _key, TData _data)
{
	if (pCurrent != pFirst)
		Reset();
	TNode<TKey, TData>* node = new TNode<TKey, TData>(_key, _data, pCurrent);
	pFirst = node;
	Reset();
}

template<typename TKey, typename TData>
void TList<TKey, TData>::InsertEnd(TKey _key, TData _data)
{
	if (pCurrent != pFirst)
		Reset();
	TNode<TKey, TData>* node = new TNode<TKey, TData>(_key, _data);
	if (pFirst == nullptr)
	{
		pCurrent = node;
		pFirst = node;
		pPrev = nullptr;
		pNext = nullptr;
		return;
	}
	while (!IsEnded())
	{
		Next();
	}
	pCurrent = node;
	pPrev->pNext = node;
	Reset();
}

template<typename TKey, typename TData>
void TList<TKey, TData>::InsertBefore(TKey _key, TKey temp_key, TData _data)
{
	if (pCurrent != pFirst)
		Reset();
	while (!IsEnded() && (pCurrent->key != _key))
		Next();
	if (pNext == nullptr && pCurrent->key != _key)
		throw "The key is not found";
	TNode<TKey, TData>* node = new TNode<TKey, TData>(temp_key, _data);
	if (pFirst == pCurrent)
	{
		pFirst = node;
		node->pNext = pCurrent;
		Reset();
		return;
	}
	pPrev->pNext = node;
	node->pNext = pCurrent;
	Reset();
}

template<typename TKey, typename TData>
void TList<TKey, TData>::InsertAfter(TKey _key, TKey temp_key, TData _data)
{
	if (pCurrent != pFirst)
		Reset();
	while (!IsEnded() && (pCurrent->key != _key))
		Next();
	if (pCurrent == nullptr)
		throw "The key is not found";
	TNode<TKey, TData>* node = new TNode<TKey, TData>(temp_key, _data, pNext);
	pCurrent->pNext = node;
	Reset();
}

template<typename TKey, typename TData>
void TList<TKey, TData>::Remove(TKey _key)
{
	if (!pFirst)
		return;
	TNode<TKey, TData>* current = pCurrent;
	TNode<TKey, TData>* prev = pPrev;
	if (pFirst->key == _key)
	{
		TNode<TKey, TData>* node = pFirst;
		pFirst = pFirst->pNext;
		if (current == node)
			current = nullptr;
		delete node;
		pCurrent = current;
		return;
	}
	TNode<TKey, TData>* first = pFirst;
	while (first->pNext && (first->pNext->key != _key))
	{
		first = first->pNext;
	}
	if (!first->pNext)
		throw "Key was not found";
	TNode<TKey, TData>* node = first->pNext;
	first->pNext = node->pNext;
	if (current == node)
		current = prev;
	delete node;
	pCurrent = current;
	Reset();
}

template<typename TKey, typename TData>
void TList<TKey, TData>::Remove(TNode<TKey, TData>* temp)
{
	this->Remove(temp->key);
}

template<typename TKey, typename TData>
void TList<TKey, TData>::DeleteAll()
{
	if (pCurrent != pFirst)
		Reset();
	while (!IsEnded())
	{
		Next();
		delete pPrev;
	}
	pFirst = nullptr;
	pPrev = nullptr;
}

template<typename TKey, typename TData>
TNode<TKey, TData>* TList<TKey, TData>::Current()
{
	return pCurrent;
}

template<typename TKey, typename TData>
TNode<TKey, TData>* TList<TKey, TData>::Prev()
{
	return pPrev;
}

template<typename TKey, typename TData>
TNode<TKey, TData>* TList<TKey, TData>::First()
{
	return pFirst;
}

template<typename TKey, typename TData>
void TList<TKey, TData>::Reset()
{
	pCurrent = pFirst;
	pPrev = nullptr;
	if (pFirst)
		pNext = pFirst->pNext;
	else
		pNext = nullptr;
}

template<typename TKey, typename TData>
bool TList<TKey, TData>::IsEnded() const
{
	return pCurrent == nullptr;
}

template<typename TKey, typename TData>
bool TList<TKey, TData>::Empty() const
{
	return pFirst == nullptr;
}

template<typename TKey, typename TData>
void TList<TKey, TData>::Next()
{
	pPrev = pCurrent;
	pCurrent = pNext;
	if (pNext != nullptr)
			pNext = pNext->pNext;
	else
		return;
}