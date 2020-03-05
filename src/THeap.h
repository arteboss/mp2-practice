#pragma once
#include "TNode.h"

template<typename TKey, typename TData>
class THeap
{
	unsigned max_size;
	unsigned size;
	int d;
	TNode<TKey, TData>* elems;
public:
	THeap();
	THeap(int, unsigned);
	THeap(const THeap&);

	void Transpose(int, int);
	void Ascent(int);
	int MinChild(int);
	void Immersion(int);

	void DeleteMinKey();
	void Hilling();
};