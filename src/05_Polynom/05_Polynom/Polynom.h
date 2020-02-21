#pragma once
#include "Monom.h"
#include "TList.h"
#include <string>

class Polynom
{
	TList<unsigned int, double>* pMonom;

	void Reduce();
	void Validation();

public:
	Polynom();
	Polynom(const string&);
	Polynom(const TList<unsigned int, double>&);
	Polynom(const TNode<unsigned int, double>*);
	Polynom(const Polynom&);
	~Polynom();

	void InsertSort();

	Polynom operator*(double) const;
	Polynom operator+(const TNode<unsigned int, double>&) const;
	Polynom operator-(const TNode<unsigned int, double>&) const;
	Polynom operator*(const TNode<unsigned int, double>&) const;
	Polynom operator+(const Polynom&) const;
	Polynom operator-(const Polynom&) const;
	Polynom operator*(const Polynom&) const;
	Polynom operator-() const;
	Polynom& operator=(const Polynom&);
	bool operator==(const Polynom&) const;
	Polynom& operator+=(const Polynom&);
	Polynom& operator-=(const Polynom&);
	Polynom& operator*=(const Polynom&);

	friend std::ostream& operator<<(std::ostream& out, const Polynom& temp)
	{
		int x = 0, y = 0, z = 0, degree = 0, firstdegree = 0;
		double coeff = 0;
		temp.pMonom->Reset();
		if (temp.pMonom->IsEnded())
		{
			out << "0";
			return out;
		}
		firstdegree = temp.pMonom->First()->GetKey();
		while (!temp.pMonom->IsEnded())
		{
			degree = temp.pMonom->Current()->GetKey();
			coeff = temp.pMonom->Current()->GetData();
			x = degree / 100;
			y = degree % 100 / 10;
			z = degree % 10;
			if (coeff > 0)
			{
				if (degree != firstdegree)
					out << "+ ";
				if (coeff != 1 || degree == 0)
					out << coeff << " ";
			}
			else if (coeff < 0)
			{
				if (coeff == -1 && degree != 0)
					out << "- ";
				else
					out << coeff << " ";
			}
			if (x != 0 || y != 0 || z != 0)
			{
				if (x > 1)
					out << "x^" <<  x << " ";
				else if (x == 1)
					out << "x" << " ";
				if (y > 1)
					out << "y^" << y << " ";
				else if (y == 1)
					out << "y" << " ";
				if (z > 1)
					out << "z^" << z << " ";
				else if (z == 1)
					out << "z" << " ";
			}
			temp.pMonom->Next();
		}
		return out;
	}
	friend std::istream& operator>>(std::istream& in, Polynom& temp)
	{
		string strf;
		getline(in, strf);
		if (temp.pMonom)
		{
			delete temp.pMonom;
			temp.pMonom = new  TList<unsigned int, double>;
		}
			temp = strf;
		return in;
	}
};