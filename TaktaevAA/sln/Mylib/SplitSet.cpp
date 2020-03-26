#include "SplitSet.h"

SplitSet::SplitSet()
{
	f = nullptr;
}

SplitSet::~SplitSet()
{
	delete[] f;
}

SplitSet::SplitSet(int un)
{
	if (un <= 0)
		throw "Wrong index";
	n = un;
	f = new int[n];
	for (int i = 0; i < n; i++)
		f[i] = -1;
}

void SplitSet::CreateSingleton(int i)
{
	if (i <= 0 || i > n)
		throw "Wrong index";
	f[i] = i;
}

void SplitSet::Unification(int i, int j)
{
	if (i <= 0 || i > n)
		throw "Wrong index";
	if (j <= 0 || j > n)
		throw "Wrong index";
	for (int k = 0; k < n; k++)
	{
		if (f[k] == j) f[k] = i;
	}
}