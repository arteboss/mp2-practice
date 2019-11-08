#pragma once
template<typename TKey, typename TData>
class TList
{
public:
	template<typename TKey, typename TData>
	struct TNode
	{
		TKey key;
		TData* pData;
		TNode<TKey, TData>* pNext;

		TNode()
		{
			key = 0;
			pData = nullptr;
			pNext = nullptr;
		}
		TNode(TKey _key, TData* _data)
		{
			key = _key;
			if (_data != nullptr)
				pData = new TData(*_data);
			else
				pData = nullptr;
			pNext = nullptr;
		}
		TNode(TNode<TKey, TData>* temp)
		{
			key = temp->key;
			pData = new TData;
			*pData = *temp->pData;
			pNext = nullptr;
		}
	};

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

	TKey Search(TKey);
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
	pFirst = new TNode<TKey, TData>(temp);
	TNode<TKey, TData>* node = temp->pNext, *prev = pFirst;
	while (node)
	{
		TNode<TKey, TData>* tmp = new TNode<TKey, TData>(node);
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
	pFirst = new TNode<TKey, TData>(temp.pFirst);
	TNode<TKey, TData>* node = temp.pFirst->pNext, *prev = pFirst;
	while (node)
	{
		TNode<TKey, TData>* tmp = new TNode<TKey, TData>(node);
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
		delete[] pPrev;
	}
}

template<typename TKey, typename TData>
TKey TList<TKey, TData>::Search(TKey _key)
{
	if (pCurrent != pFirst)
		Reset();
	while (!IsEnded())
	{
		if (pCurrent->key == _key)
			return pCurrent->key;
		Next();
	}
	throw "The key is not found";
}

template<typename TKey, typename TData>
void TList<TKey, TData>::InsertStart(TKey _key, TData* _data)
{
	if (pCurrent != pFirst)
		Reset();
	TNode<TKey, TData>* node = new TNode<TKey, TData>(_key, _data);
	pFirst = node;
	node->pNext = pCurrent;
	pPrev = node;
	Reset();
}

template<typename TKey, typename TData>
void TList<TKey, TData>::InsertEnd(TKey _key, TData* _data)
{
	if (pCurrent != pFirst)
		Reset();
	TNode<TKey, TData>* node = new TNode<TKey, TData>(_key, _data);
	if (pCurrent == nullptr)
	{
		pCurrent = node;
		pFirst = node;
		return;
	}
	while (!IsEnded())
	{
		Next();
	}
	pCurrent = node;
	pPrev->pNext = node;
	node->pNext = nullptr;
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
void TList<TKey, TData>::InsertAfter(TKey _key, TKey temp_key, TData* _data)
{
	if (pCurrent != pFirst)
		Reset();
	while (!IsEnded() && (pCurrent->key != _key))
		Next();
	if ((pNext == nullptr) && (pCurrent->key != _key))

		throw "The key is not found";
	TNode<TKey, TData>* node = new TNode<TKey, TData>(temp_key, _data);
	pCurrent->pNext = node;
	node->pNext = pNext;
	Reset();
}

template<typename TKey, typename TData>
void TList<TKey, TData>::Remove(TKey _key)
{
	if (pCurrent != pFirst)
		Reset();
	while (!IsEnded() && (pCurrent->key != _key))
		Next();
	if (pCurrent == nullptr)
		throw "The key is not found";
	if (pCurrent == pFirst)
	{
		pFirst = pCurrent->pNext;
	}
	else
		pPrev->pNext = pCurrent->pNext;
	delete pCurrent;
	pCurrent = nullptr;
	if (pFirst != pCurrent)
		Reset();
}

template<typename TKey, typename TData>
void TList<TKey, TData>::Reset()
{
	if (pFirst == nullptr)
		return;
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
		return;
}

template<typename TKey, typename TData>
TList<TKey, TData>::TNode<TKey, TData>* TList<TKey, TData>::Current()
{
	return pCurrent;
}

template<typename TKey, typename TData>
TList<TKey, TData>::TNode<TKey, TData>* TList<TKey, TData>::First()
{
	return pFirst;
}
