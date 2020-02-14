#pragma once
#include "Polynom.h"
struct Monom
{
	int key;
	double koeff;
	Monom* next;

	Monom();
	Monom(double);
	Monom(const Monom*);
	Monom(int, double, Monom* _next = 0);

	Monom& operator=(const Monom&);
	Monom operator+(const Monom&) const;
	Monom operator-() const;
	Monom operator-(const Monom&) const;
	Monom operator*(const Monom&) const;
	//Monom operator*(const Polynom&) const;

	int GetXDegree() const { return key / 100; }
	int GetYDegree() const { return key % 100 / 10; }
	int GetZDegree() const { return key % 10; }
};

Monom::Monom()
{
	next = nullptr;
}

Monom::Monom(double k)
{
	koeff = k;
}

Monom::Monom(const Monom* monom)
{
	key = monom->key;
	koeff = monom->koeff;
}

Monom::Monom(int _key, double _koeff, Monom* _next)
{
	if ((_key < 0) || (key > 999)) throw "ErrKey";
	key = _key;
	koeff = _koeff;
	next = _next;
}

Monom& Monom::operator=(const Monom& monom)
{
	key = monom.key;
	koeff = monom.koeff;
	return *this;
}

Monom Monom::operator+(const Monom& monom) const
{
	Monom res;
	if (key == monom.key)
	{
		res.koeff = koeff + monom.koeff;
		return res;
	}
	else throw "Err in + of monoms";
}

Monom Monom::operator-() const
{
	return Monom(-koeff);
}

Monom Monom::operator-(const Monom& monom) const
{
	Monom res;
	if (key == monom.key)
	{
		res.koeff = koeff - monom.koeff;
		return res;
	}
	else throw "Err in - of monoms";
}

Monom Monom::operator*(const Monom& monom) const
{
	Monom res;
	res.koeff = koeff * monom.koeff;
	res.key = 100 * (GetXDegree() + monom.GetXDegree()) 
		+ 10 * (GetYDegree() + monom.GetYDegree()) 
		+ GetZDegree() + monom.GetZDegree();
	if (res.key > 999) throw "Multiplying overflow(x)";
	if (res.GetYDegree() < GetYDegree()) throw "Multiplying overflow(y)";
	if (res.GetZDegree() < GetZDegree()) throw "Multiplying overflow(z)";
	return res;
}

//Monom Monom::operator*(const Polynom&) const
//{

//}
