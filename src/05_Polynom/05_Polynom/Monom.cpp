#include "Monom.h"

TNode<unsigned int, double>::TNode()
{
	key = 0;
	data = 0;
	pNext = nullptr;
}

TNode<unsigned int, double>::TNode(const TNode& temp)
{
	key = temp.key;
	data = temp.data;
	pNext = nullptr;
}

TNode<unsigned int, double>::TNode(unsigned int _key, double _data, TNode* _next)
{
	if (_key > 999)
		throw "Degree overflow";
	key = _key;
	data = _data;
	pNext = _next;
}

TNode<unsigned int, double> TNode<unsigned int, double>::operator+(const TNode& temp) const
{
	if (this->key != temp.key)
		throw "Err in + of monoms";
	TNode res;
	res.key = key;
	res.data = data + temp.data;
	res.pNext = pNext;
	return res;
}

TNode<unsigned int, double> TNode<unsigned int, double>::operator-(const TNode& temp) const
{
	if (this->key != temp.key)
		throw "Err in - of monoms";
	TNode res;
	res.key = key;
	res.data = data - temp.data;
	res.pNext = pNext;
	return res;
}

TNode<unsigned int, double>& TNode<unsigned int, double>::operator=(const TNode& temp)
{
	key = temp.key;
	data = temp.data;
	return *this;
}

TNode<unsigned int, double> TNode<unsigned int, double>::operator*(double temp) const
{
	TNode res = *this;
	res.data = data * temp;
	return res;
}

TNode<unsigned int, double> TNode<unsigned int, double>::operator*(const TNode& temp) const
{
	TNode res;
	res.data = data * temp.data;
	res.key = key + temp.key;
	if (res.key > 999) throw "Multiplying overflow(x)";
	if (res.GetYDegree() < GetYDegree()) throw "Multiplying overflow(y)";
	if (res.GetZDegree() < GetZDegree()) throw "Multiplying overflow(z)";
	return res;
}

TNode<unsigned int, double> TNode<unsigned int, double>::operator-() const
{
	TNode<unsigned int, double> res(*this);
	return(res * (-1.0));
}

bool TNode<unsigned int, double>::operator>(const TNode& temp) const
{
	if (key != temp.key)
		return key > temp.key;
	else return data > temp.data;
}

bool TNode<unsigned int, double>::operator<(const TNode& temp) const
{
	if (key != temp.key)
		return key < temp.key;
	else return data < temp.data;
}

bool TNode<unsigned int, double>::operator==(const TNode& temp) const
{
	return (key == temp.key && data == temp.data);
}

bool TNode<unsigned int, double>::operator!=(const TNode& temp) const
{
	return (key != temp.key || data != temp.data);
}

TNode<unsigned int, double>& TNode<unsigned int, double>::operator+=(const TNode& temp)
{
	if (key != temp.key)
		throw "Err in += of monoms";
	data += temp.data;
	return *this;
}

TNode<unsigned int, double>& TNode<unsigned int, double>::operator-=(const TNode& temp)
{
	if (key != temp.key)
		throw "Err in -= of monoms";
	data -= temp.data;
	return *this;
}

TNode<unsigned int, double>& TNode<unsigned int, double>::operator*=(const TNode& temp)
{
	int y = GetYDegree(), z = GetZDegree();
	key += temp.key;
	data *= temp.data;
	if (key > 999) throw "Multiplying overflow(x)";
	if (GetYDegree() < y) throw "Multiplying overflow(y)";
	if (GetZDegree() < z) throw "Multiplying overflow(z)";
	return *this;
}
