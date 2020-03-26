#pragma once
#include "TNode.h"
#include <iostream>

template<typename TKey, typename TData>
class THeap
{
	int max_size;
	int size;
	int d;
	TNode<TKey, TData>* elems;
public:
	THeap();
	THeap(int, int);
	THeap(const THeap&);

	void Transpose(int, int);
	void Ascent(int);
	int MinChild(int);
	void Immersion(int);
	int Min(int, int);

	void PyramidalSort();

	void DeleteMinKey();
	void Hilling();

	void FullFill()
	{
		std::cout << "Fullfill the heap" << endl;
		char a;
		for (int i = 0; i <= max_size; i++)
		{
			std::cout << "0 - continue, 1 - break:" << endl;
			std::cin >> a;
			if (a == 0)
			{
				size++;
				std::cout << "Enter element ¹" << i << endl;
				std::cin >> elems[i];
			}
			else if (a == 1) break;
			else throw "Wrong";
		}
	}
};
