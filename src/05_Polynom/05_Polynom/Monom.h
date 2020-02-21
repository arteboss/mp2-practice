#pragma once
#include "TNode.h"

template<>
struct TNode<unsigned int, double>
{
	unsigned int key;
	double data;
	TNode<unsigned int, double>* pNext;

	TNode();
	TNode(const TNode&);
	TNode(unsigned int, double, TNode* _next = 0);

	unsigned int GetKey() { return key; }
	double GetData() { return data; }

	TNode operator+(const TNode&) const;
	TNode operator-(const TNode&) const;
	TNode& operator=(const TNode&);
	TNode operator*(double) const;
	TNode operator-() const;
	TNode operator*(const TNode&) const;
	bool operator>(const TNode&) const;
	bool operator<(const TNode&) const;
	bool operator==(const TNode&) const;
	bool operator!=(const TNode&) const;
	TNode& operator+=(const TNode&);
	TNode& operator-=(const TNode&);
	TNode& operator*=(const TNode&);

	int GetXDegree() const { return key / 100; }
	int GetYDegree() const { return key % 100 / 10; }
	int GetZDegree() const { return key % 10; }
};
