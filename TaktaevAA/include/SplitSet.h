#pragma once
class SplitSet
{
	int n;
	int* f;
public:
	SplitSet();
	~SplitSet();
	SplitSet(int);
	void CreateSingleton(int);
	void Unification(int, int);
	int FindSet(int i) 
	{ 
		if (i <= 0 || i > n)
			throw "Wrong index";
		return f[i];
	}
};