#pragma once
#include "Monom.h"
#include <iostream>

class Polynom
{
private:
	Monom* pFirst;
	Monom* pNext;
	Monom* pPrev;
	Monom* pCurrent;

public:
	Polynom();
	Polynom(const Monom*);
	Polynom(const Polynom&);
	~Polynom();

	Monom* Search(int);
	void InsertStart(int, double);
	void InsertEnd(int, double);
	void InsertBefore(int, int, double);
	void InsertAfter(int, int, double);
	void Remove(int);

	Monom* Current();
	Monom* First();

	void Reset();
	bool IsEnded() const;
	bool Empty() const;
	void Next();

	Polynom operator+(Polynom&) const;
	Polynom operator-(Polynom&) const;
	Polynom operator-() const;
	//Polynom operator*(const Monom&) const;
	//Polynom operator*(Polynom&) const;
	Polynom& operator=(const Polynom&);

	void Reduce();
};



Polynom::Polynom()
{
	pCurrent = nullptr;
	pFirst = nullptr;
	pPrev = nullptr;
	pNext = nullptr;
}


Polynom::Polynom(const Monom* temp) : Polynom()
{
	if (!temp)
		return;
	pFirst = new Monom(temp);
	Monom* node = temp->next, *prev = pFirst;
	while (node)
	{
		Monom* tmp = new Monom(node);
		prev->next = tmp;
		prev = tmp;
		node = node->next;
	}
	Reset();
}


Polynom::Polynom(const Polynom& temp) : Polynom()
{
	if (!temp.pFirst)
		return;
	pFirst = new Monom(temp.pFirst);
	Monom* node = temp.pFirst->next, *prev = pFirst;
	while (node)
	{
		Monom* tmp = new Monom(node);
		prev->next = tmp;
		prev = tmp;
		node = node->next;
	}
	Reset();
}


Polynom::~Polynom()
{
	if (pCurrent != pFirst)
		Reset();
	while (!IsEnded())
	{
		Next();
		delete pPrev;
	}
}


Monom* Polynom::Search(int _key)
{
	if (pCurrent != pFirst)
		Reset();
	while (!IsEnded())
	{
		if (pCurrent->key == _key)
			return pCurrent;
		Next();
	}
	return nullptr;
}


void Polynom::InsertStart(int _key, double _data)
{
	if (pCurrent != pFirst)
		Reset();
	Monom* node = new Monom(_key, _data, pCurrent);
	pFirst = node;
	Reset();
}


void Polynom::InsertEnd(int _key, double _data)
{
	if (pCurrent != pFirst)
		Reset();
	Monom* node = new Monom(_key, _data);
	if (pFirst == nullptr)
	{
		pCurrent = node;
		pFirst = node;
		pPrev = nullptr;
		pNext = nullptr;
		return;
	}
	while (!IsEnded())
	{
		Next();
	}
	pCurrent = node;
	pPrev->next = node;
	pNext = nullptr;
	Reset();
}


void Polynom::InsertBefore(int _key, int temp_key, double _data)
{
	if (pCurrent != pFirst)
		Reset();
	while (!IsEnded() && (pCurrent->key != _key))
		Next();
	if (pNext == nullptr && pCurrent->key != _key)
		throw "The key is not found";
	Monom* node = new Monom(temp_key, _data);
	if (pFirst == pCurrent)
	{
		pFirst = node;
		node->next = pCurrent;
		Reset();
		return;
	}
	pPrev->next = node;
	node->next = pCurrent;
	Reset();
}


void Polynom::InsertAfter(int _key, int temp_key, double _data)
{
	if (pCurrent != pFirst)
		Reset();
	while (!IsEnded() && (pCurrent->key != _key))
		Next();
	if (pCurrent == nullptr)
		throw "The key is not found";
	Monom* node = new Monom(temp_key, _data, pNext);
	pCurrent->next = node;
	Reset();
}


void Polynom::Remove(int _key)
{
	Monom* tmp1 = pCurrent;
	if (pCurrent != pFirst)
		Reset();
	while (!IsEnded() && (pCurrent->key != _key))
		Next();
	if (pCurrent == nullptr)
		throw "The key is not found";
	if (pCurrent == pFirst)
	{
		pFirst = pCurrent->next;
	}
	else
	{

		pPrev->next = pCurrent->next;
		if (pCurrent->next == nullptr)
		{
			pNext = nullptr;
		}
		else
		{
			pNext = pCurrent->next->next;
		}
	}
	if (pCurrent == tmp1)
	{
		delete pCurrent;
		Reset();
	}
	else
	{
		delete pCurrent;
		pCurrent = tmp1;
	}
}


Monom* Polynom::Current()
{
	return pCurrent;
}


Monom* Polynom::First()
{
	return pFirst;
}


void Polynom::Reset()
{
	if (pFirst == nullptr)
	{
		pPrev = pCurrent = pNext = nullptr;
		return;
	}
	pCurrent = pFirst;
	pPrev = nullptr;
	pNext = pFirst->next;
}


bool Polynom::IsEnded() const
{
	return pCurrent == nullptr;
}


bool Polynom::Empty() const
{
	return pFirst == nullptr;
}


void Polynom::Next()
{
	if (!pCurrent) return;
	pPrev = pCurrent;
	pCurrent = pNext;
	if (pCurrent != nullptr)
		pNext = pNext->next;
	else
		pNext = nullptr;
}

Polynom Polynom::operator+(Polynom& polynom) const
{
	Polynom res = (*this);
	polynom.Reset();
	while (!polynom.IsEnded())
	{
		if (!res.Search(polynom.pCurrent->key)) res.Search(polynom.pCurrent->key)->koeff += polynom.pCurrent->koeff;
		else res.InsertEnd(polynom.pCurrent->key, polynom.pCurrent->koeff);
		polynom.Next();
	}
	polynom.Reset();
	return res;
}

Polynom Polynom::operator-(Polynom& polynom) const
{
	Polynom res = (*this);
	polynom.Reset();
	while (!polynom.IsEnded())
	{
		if (!res.Search(polynom.pCurrent->key)) res.Search(polynom.pCurrent->key)->koeff -= polynom.pCurrent->koeff;
		else res.InsertEnd(polynom.pCurrent->key, polynom.pCurrent->koeff);
		polynom.Next();
	}
	polynom.Reset();
	return res;
}

Polynom Polynom::operator-() const
{
	Polynom res = (*this);
	while (!res.IsEnded())
	{
		(*res.pCurrent) = -(*res.pCurrent);
	}
	return res;
}

Polynom& Polynom::operator=(const Polynom& polynom)
{
	if (!polynom.pFirst) throw "Err";
	pFirst = new Monom(polynom.pFirst);
	Monom* node = polynom.pFirst->next, *prev = pFirst;
	while (node)
	{
		Monom* tmp = new Monom(node);
		prev->next = tmp;
		prev = tmp;
		node = node->next;
	}
	Reset();
	return (*this);
}

/*Polynom Polynom::operator*(const Monom& monom) const
{
	Polynom res = (*this);
	while (!res.IsEnded())
	{
		res.pCurrent-> key += monom.key;
		res.pCurrent->koeff *= monom.koeff;
	}
	
}*/

/*Polynom Polynom::operator*(Polynom& polynom) const
{
	Polynom res = (*this);
	polynom.Reset();
	while (!polynom.IsEnded())
	{
		pCurrent->key + 
	}
}*/

void Polynom::Reduce()
{
	Reset();
	while (!IsEnded())
	{
		int f = 0;
		if (pCurrent->key == 0)
		{
			Monom* cur = pCurrent;
			Next();
			f = 1;
			Remove(cur->key);
		}
		if (f == 0) Next();
	}
	Reset();
	Polynom tmp = (*this);
	while (!IsEnded())
	{
		tmp.pCurrent = pCurrent->next;
		while (!tmp.IsEnded())
		{
			int f = 0;
			if (pCurrent->key == tmp.pCurrent->key)
			{
				pCurrent->koeff += tmp.pCurrent->koeff;
				Monom* cur = tmp.pCurrent;
				tmp.Next();
				f = 1;
				tmp.Remove(cur->key);
			}
			if (f == 0) tmp.Next();
		}
		tmp.Reset();
	}
}