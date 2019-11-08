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

		TNode<TKey, TData>()
		{
			key = NULL;
			pData = new TData;
			pNext = nullptr;
		}
		TNode<TKey, TData>(TKey _key, TData* _data)
		{
			key = _key;
			pData = new TData;
			*pData = *_data;
			pNext = nullptr;
		}
		TNode<TKey, TData>(TNode<TKey, TData>* temp)
		{
			key = temp->key;
			pData = new TData;
			*pData = *temp->pData;
			pNext = temp->pNext;
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

	TNode<TKey, TData>* Search(TKey);
	void InsertStart(TKey, TData*);
	void InsertEnd(TKey, TData*);
	void InsertBefore(TKey, TKey, TData*);
	void InsertAfter(TKey, TKey, TData*);
	void Remove(TKey);

	void Reset();
	bool IsEnded() const;
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
TList<TKey, TData>::TList(const TNode<TKey, TData>* temp)
{
	TNode<TKey, TData> node(temp);
	while (node.pNext != nullptr)
	{
		if (pFirst == nullptr)
		{
			pCurrent = new TNode<TKey, TData>(node.key, node.pData);
			pFirst = pCurrent;
			pPrev = nullptr;
		}
		else
		{
			pPrev = pCurrent;
			pCurrent = new TNode<TKey, TData>(node.key, node.pData);
			pPrev->pNext = pCurrent;
		}
		node = node.pNext;
	}
	pPrev = pCurrent;
	pCurrent = new TNode<TKey, TData>(node.key, node.pData);
	pPrev->pNext = pCurrent;
	pNext = nullptr;
	Reset();
}

template<typename TKey, typename TData>
TList<TKey, TData>::TList(const TList& temp)
{
	if (temp.pCurrent != temp.pFirst)
		throw "";
	TNode<TKey, TData> node(temp.pCurrent);
	while (node.pNext != nullptr)
	{
		if (pFirst == nullptr)
		{
			pCurrent = new TNode<TKey, TData>(node.key, node.pData);
			pFirst = pCurrent;
			pPrev = nullptr;
		}
		else
		{
			pPrev = pCurrent;
			pCurrent = new TNode<TKey, TData>(node.key, node.pData);
			pPrev->pNext = pCurrent;
		}
		node = node.pNext;
	}
	pPrev = pCurrent;
	pCurrent = new TNode<TKey, TData>(node.key, node.pData);
	pPrev->pNext = pCurrent;
	pNext = nullptr;
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
	delete[] pCurrent;
}

template<typename TKey, typename TData>
TList<TKey, TData>::TNode<TKey, TData>* TList<TKey, TData>::Search(TKey _key)
{
	if (pCurrent != pFirst)
		Reset();
	while (!IsEnded())
	{
		if (pCurrent->key == _key)
			return pCurrent;
		Next();
	}
	if (pCurrent->key == _key)
		return pCurrent;
	throw " ";
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
	while (!IsEnded())
	{
		Next();
	}
	pCurrent->pNext = node;
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
		throw " ";
	TNode<TKey, TData>* node = new TNode<TKey, TData>(temp_key, _data);
	if (pFirst == pCurrent)
	{
		pFirst = node;
		node->pNext =

			pCurrent;
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
	if (pCurrent == pFirst)
		pFirst = pCurrent->pNext;
	else
		pPrev->pNext = pCurrent->pNext;
	delete[] pCurrent;
	Reset();
	return;
}

template<typename TKey, typename TData>
void TList<TKey, TData>::Reset()
{
	pCurrent = pFirst;
	pPrev = nullptr;
	pNext = pFirst->pNext;
}

template<typename TKey, typename TData>
bool TList<TKey, TData>::IsEnded() const
{
	return pNext == nullptr;
}

template<typename TKey, typename TData>
void TList<TKey, TData>::Next()
{
	pPrev = pCurrent;
	pCurrent = pNext;
	pNext = pNext->pNext;
}