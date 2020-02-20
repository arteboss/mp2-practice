#pragma once
#include <iostream>

using namespace std;

template<typename TKey, typename TData>
struct TNode
{
	TKey key;
	TData data;
	TNode* pNext;
	
	TNode();
	TNode(TKey, TData, TNode* _next = 0);
	TNode(const TNode&);
};

template<typename TKey, typename TData>
TNode<TKey, TData>::TNode()
{
	key = 0;
	data = 0;
	pNext = nullptr;
}

template<typename TKey, typename TData>
TNode<TKey, TData>::TNode(TKey _key, TData _data, TNode* _next)
{
	key = _key;
	data = _data;
	pNext = _next;
}

template<typename TKey, typename TData>
TNode<TKey, TData>::TNode(const TNode& temp)
{
	key = temp.key;
	data = temp.data;
	pNext = nullptr;
}