#pragma once
template<typename TKey, typename TData>
struct TNode
{
	TKey key;
	TData* pData;
	TNode* pNext;
	TNode();
	TNode(TKey, TData*, TNode* _next = 0);
};

template<typename TKey, typename TData>
TNode<TKey, TData>::TNode()
{
	pData = nullptr;
	pNext = nullptr;
}

template<typename TKey, typename TData>
TNode<TKey, TData>::TNode(TKey _key, TData* _data, TNode* _next)
{
	key = _key;
	pData = new TData;
	pNext = _next;
}


template<typename TKey, typename TData>
class TList
{
private:
	TNode<TKey, TData>* pFirst;
	TNode<TKey, TData>* pNext;
	TNode<TKey, TData>* pPrev;
	TNode<TKey, TData>* pCurrent;

public:
	TList();
	TList(const TNode<TKey, TData>*);
	TList(const TList&);
	~TList();

	TNode<TKey, TData>* Search(TKey);
	void InsertStart(TKey, TData*);
	void InsertEnd(TKey, TData*);
	void InsertBefore(TKey, TKey, TData*);
	void InsertAfter(TKey, TKey, TData*);
	void Remove(TKey);

	TNode<TKey, TData>* Current();
	TNode<TKey, TData>* First();

	void Reset();
	bool IsEnded() const;
	bool Empty() const;
	void Next();
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
	pFirst = new TNode(temp);
	TNode* node = temp->pNext, *prev = pFirst;
	while (node)
	{
		TNode* tmp = new TNode(node);
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
	pFirst = new TNode(temp.pFirst);
	TNode* node = temp.pFirst->pNext, *prev = pFirst;
	while (node)
	{
		TNode* tmp = new TNode(node);
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
TNode<TKey, TData>* TList<TKey, TData>::Search(TKey _key)
{
	if (pCurrent != pFirst)
		Reset();
	while (!IsEnded())
	{
		if (pCurrent->key == _key)
			return pCurrent;
		Next();
	}
	return nullptr;
}

template<typename TKey, typename TData>
void TList<TKey, TData>::InsertStart(TKey _key, TData* _data)
{
	if (pCurrent != pFirst)
		Reset();
	TNode<TKey, TData>* node = new TNode<TKey, TData>(_key, _data, pCurrent);
	pFirst = node;
	Reset();
}

template<typename TKey, typename TData>
void TList<TKey, TData>::InsertEnd(TKey _key, TData* _data)
{
	if (pCurrent != pFirst)
		Reset();
	TNode* node = new TNode(_key, _data);
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
void TList<TKey, TData>::InsertBefore(TKey _key, TKey temp_key, TData* _data)
{
	if (pCurrent != pFirst)
		Reset();
	while (!IsEnded() && (pCurrent->key != _key))
		Next();
	if (pNext == nullptr && pCurrent->key != _key)
		throw "The key is not found";
	TNode* node = new TNode(temp_key, _data);
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
void TList<TKey, TData>::InsertAfter(TKey _key, TKey temp_key, TData* _data)
{
	if (pCurrent != pFirst)
		Reset();
	while (!IsEnded() && (pCurrent->key != _key))
		Next();
	if (pCurrent == nullptr)
		throw "The key is not found";
	TNode* node = new TNode(temp_key, _data, pNext);
	pCurrent->pNext = node;
	Reset();
}

template<typename TKey, typename TData>
void TList<TKey, TData>::Remove(TKey _key)
{
	TNode < TKey, TData)* tmp1 = pCurrent;
	if (pCurrent != pFirst)
		Reset();
	while (!IsEnded() && (pCurrent->key != _key))
		Next();
	if (pCurrent == nullptr)
		throw "The key is not found";
	if (pCurrent == pFirst)
	{
		pFirst = pCurrent->pNext;
		pNext = pFirst->pNext;
	}
	else
	{

		pPrev->pNext = pCurrent->pNext;
		if (pCurrent->pNext == nullptr)
		{
			pNext = nullptr;
		}
		else
		{
			pNext = pCurrent->pNext->pNext;
		}
	}
	if (pCurrent == tmp1)
	{
		delete pCurrent;
		Reset();
	}
	else
	{
		delete pCurrent;
		pCurrent = tmp1;
	}
}

template<typename TKey, typename TData>
TNode<TKey, TData>* TList<TKey, TData>::Current()
{
	return pCurrent;
}

template<typename TKey, typename TData>
TNode<TKey, TData>* TList<TKey, TData>::First()
{
	return pFirst;
}

template<typename TKey, typename TData>
void TList<TKey, TData>::Reset()
{
	if (pFirst == nullptr)
	{
		pPrev = pCurrent = pNext = nullptr;
		return;
	}
	pCurrent = pFirst;
	pPrev = nullptr;
	pNext = pFirst->pNext;
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
	if (pCurrent != nullptr)
		pNext = pNext->pNext;
	else
		pNext = nullptr;
}