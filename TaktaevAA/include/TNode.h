#pragma once
#include <iostream>

using namespace std;

template<typename TKey, typename TData>
struct TNode
{
	TKey key;
	TData data;

	TNode();
	TNode(TKey, TData);
	TNode(const TNode&);

	TNode& operator=(const TNode&);
	bool operator>(const TNode&) const;
};

template<typename TKey, typename TData>
TNode<TKey, TData>::TNode()
{
	key = 0;
	data = 0;
}

template<typename TKey, typename TData>
TNode<TKey, TData>::TNode(TKey _key, TData _data)
{
	key = _key;
	data = _data;
}

template<typename TKey, typename TData>
TNode<TKey, TData>::TNode(const TNode<TKey, TData>& temp)
{
	key = temp.key;
	data = temp.data;
}

template<typename TKey, typename TData>
TNode<TKey, TData>& TNode<TKey, TData>::operator=(const TNode<TKey, TData>& temp)
{
	return *this(temp);
}

template<typename TKey, typename TData>
bool TNode<TKey, TData>::operator>(const TNode<TKey, TData>& temp) const
{
	if (key > temp.key) return true;
	else return false;
}