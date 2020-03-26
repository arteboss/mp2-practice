#include "Heap.h"

template<typename TKey, typename TData>
THeap<TKey, TData>::THeap()
{
	elems = nullptr;
}

template<typename TKey, typename TData>
THeap<TKey, TData>::THeap(int _d, int _max_size)
{
	d = _d;
	max_size = _max_size;
	elems = new TNode<TKey, TData>[max_size];
	size = 0;
}

template<typename TKey, typename TData>
THeap<TKey, TData>::THeap(const THeap& temp)
{
	d = temp.d;
	max_size = d.max_size;
	size = d.size;
	delete elems;
	elems = new TNode<TKey, TData>[max_size];
	for (int i = 0; i < size; i++)
		elems[i] = temp.elems[i];
}

template<typename TKey, typename TData>
void THeap<TKey, TData>::Transpose(int i, int j)
{
	TNode<TKey, TData> temp = elems[i];
	elems[i] = elems[j];
	elems[j] = temp;
}

template<typename TKey, typename TData>
void THeap<TKey, TData>::Ascent(int i)
{
	unsigned p = (i - 1) / d;
	while (i > 0)
	{
		if (elems[p] > elems[i])
		{
			Transpose(i, p);
			i = p;
		}
		else break;
	}
}

template<typename TKey, typename TData>
int THeap<TKey, TData>::MinChild(int i)
{
	if (i * d + 1 >= size)
		return -1;
	int c1 = i * d + 1, c2 = Min( size - 1, i * d + d );
	int c = c1;
	for (i = c1; i < c2; i++)
	{
		if (elems[c] > elems[i]) c = i;
	}
	return c;
}

template<typename TKey, typename TData>
void THeap<TKey, TData>::Immersion(int i)
{
	int c = MinChild(i);
	while ((c != -1) && (elems[i] > elems[c]))
	{
		Transpose(c, i);
		i = c;
		c = MinChild(i);
	}
}

template<typename TKey, typename TData>
int THeap<TKey, TData>::Min(int i, int j)
{
	return i < j ? i : j;
}

template<typename TKey, typename TData>
void THeap<TKey, TData>::PyramidalSort()
{
	Hilling();
	for (int i = size; i >= 1; i++)
	{
		Transpose(0, i);
		size--;
		Immersion(i);
	}
}

template<typename TKey, typename TData>
void THeap<TKey, TData>::DeleteMinKey()
{
	Transpose(0, size - 1);
	size--;
	Immersion(0);
}

template<typename TKey, typename TData>
void THeap<TKey, TData>::Hilling()
{
	for (int i = size - 1; i >= 0; i--)
	{
		Immersion(i);
	}
}