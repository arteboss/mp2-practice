#include "Polynom.h"

Polynom::Polynom()
{
	pMonom = new TList<unsigned int, double>;
}

Polynom::Polynom(const string& strf) : Polynom()
{
	string strcoeff;
	size_t startIndex = 0, endIndex = 0;
	int x = 0, y = 0, z = 0, degree = 0;
	double coeff;
	if (strf.find_first_not_of("0123456789*+-xyz^(). ") != -1)
		throw "Invalid polynom";
	string str;
	for (int i = 0; i < strf.size(); i++)
		if (strf[i] != ' ')
			str += strf[i];
	for (size_t i = 0; i < str.size();)
	{
		x = 0, y = 0, z = 0;
		startIndex = i;
		while (str[i] != 'x' && str[i] != 'y' && str[i] != 'z' && i != str.size())
		{
			if (str[i + 1] == '+' ||  str[i + 1] == '-')
			{
				i++;
				endIndex = i;
				break;
			}
			else
			{
				i++;
				endIndex = i;
			}
		}
		strcoeff = str.substr(startIndex, endIndex - startIndex);
		if (strcoeff == "+" || strcoeff == "" )
			coeff = 1;
		else if (strcoeff == "-")
			coeff = -1;
		else
		{
			coeff = stod(strcoeff);
		}
		while (i != str.size() && str[i] != '+' && str[i] != '-')
		{
			if (str[i] == 'x')
			{
				if (isalpha(str[i + 1]) || (i + 1) == str.size() || str[i + 1] == '+' || str[i + 1] == '-')
				{
					x = 1;
					i++;
				}
				else
				{
					while (!isdigit(str[i]))
						i++;
					if (isdigit(str[i]) && isdigit(str[i + 1]))
						throw "Degree overflow.";
					x = str[i] - 48;
				}
			}
			else if (str[i] == 'y')
			{
				if (isalpha(str[i + 1]) || (i + 1) == str.size() || str[i + 1] == '+' || str[i + 1] == '-')
				{
					y = 1;
					i++;
				}
				else
				{
					while (!isdigit(str[i]))
						i++;
					if (isdigit(str[i]) && isdigit(str[i + 1]))
						throw "Degree overflow.";
					y = str[i] - 48;
				}
			}
			else if (str[i] == 'z')
			{
				if (isalpha(str[i + 1]) || (i + 1) == str.size() || str[i + 1] == '+' || str[i + 1] == '-')
				{
					z = 1;
					i++;
				}
				else
				{
					while (!isdigit(str[i]))
						i++;
					if (isdigit(str[i]) && isdigit(str[i + 1]))
						throw "Degree overflow.";
					z = str[i] - 48;
				}
			}
			else
				i++;
		}
		degree = x * 100 + y * 10 + z;
		pMonom->InsertEnd(degree, coeff);
	}
	Reduce();
	InsertSort();/////
}

Polynom::Polynom(const TList<unsigned int, double>& temp)
{
	pMonom = new TList<unsigned int, double>(temp);
	Validation();
	Reduce();
	InsertSort();//////
}

Polynom::Polynom(const TNode<unsigned int, double>* temp)
{
	pMonom = new TList<unsigned int, double>(temp);
	Validation();
	Reduce();
	InsertSort();//////
}

Polynom::Polynom(const Polynom& temp)
{
	pMonom = new TList<unsigned int, double>(*temp.pMonom);
}

Polynom::~Polynom()
{
	delete pMonom;
}

void Polynom::InsertSort()
{
	{
		if ((pMonom->pFirst == nullptr) || (pMonom->pFirst->pNext == nullptr))
			return;
		Polynom temp(*this);
		pMonom->DeleteAll();
		TNode<unsigned int, double>* node = temp.pMonom->pFirst, max(*temp.pMonom->pFirst);
		while (temp.pMonom->pFirst)
		{
			node = temp.pMonom->pFirst;
			while (node)
			{
				if (max.key <= node->key)
					max = *node;
				node = node->pNext;
			}
			pMonom->InsertEnd(max.key, max.data);
			temp.pMonom->Remove(max.key);
			max.key = 0;
		}
	}
}

void Polynom::Validation()
{
	pMonom->Reset();
	while (!pMonom->IsEnded())
	{
		if (pMonom->Current()->key > 999)
			throw "One of polynom's key is wrong";
		pMonom->Next();
	}
}

void Polynom::Reduce()
{
	pMonom->Reset();
	if (pMonom->Current() == nullptr)
		return;
	while (!pMonom->IsEnded())
	{
		if (pMonom->Current()->data == 0)
		{
			pMonom->Remove(pMonom->Current());
		}
		else
		{
			pMonom->Next();
			TNode<unsigned int, double>* temp = pMonom->Search(pMonom->Prev()->key, 1);
			if (temp)
			{
				*pMonom->Prev() += *temp;
				temp->data = 0;
			}
		}
	}
	pMonom->Reset();
}

Polynom Polynom::operator*(double temp) const
{
	if (!pMonom)
		return *this;
	if (temp == 0)
		return Polynom();
	pMonom->Reset();
	Polynom result(*this);
	while (!result.pMonom->IsEnded())
	{
		result.pMonom->Current()->data *= temp;
		result.pMonom->Next();
	}
	return result;
}

Polynom Polynom::operator+(const TNode<unsigned int, double>& temp) const
{
	if (!pMonom)
		return *this;
	pMonom->Reset();
	Polynom result(*this);
	if (result.pMonom->First() == nullptr)
	{
		result.pMonom->InsertStart(temp.key, temp.data);
		return result;
	}
	while (!result.pMonom->IsEnded())
	{
		if (*result.pMonom->Current() < temp)
		{
			result.pMonom->InsertBefore(result.pMonom->Current()->key, temp.key, temp.data);
			return result;
		}
		else if (result.pMonom->Current()->key == temp.key)
		{
				*result.pMonom->Current() += temp;
			if (result.pMonom->Current()->data == 0)
				result.pMonom->Remove(result.pMonom->Current()->key);
			return result;
		}
		else
			result.pMonom->Next();
	}
	result.pMonom->InsertEnd(temp.key, temp.data);
	return result;
}

Polynom Polynom::operator-(const TNode<unsigned int, double>& temp) const///2+y-2z+x^2y//-2+5x^2y+z-yz+x^2yz
{
	Polynom result;
	result = *this + (-temp); // unary minus
	return result;
}

Polynom Polynom::operator*(const TNode<unsigned int, double>& temp) const
{
	if (!pMonom)
		return *this;
	pMonom->Reset();
	Polynom result(*this);
	while (!result.pMonom->IsEnded())
	{
		*result.pMonom->Current() *= temp;
		result.pMonom->Next();
	}
	return result;
}

Polynom Polynom::operator+(const Polynom& temp) const
{
	if (!pMonom)
		return *this;
	Polynom result(*this), other(temp);
	pMonom->Reset();
	other.pMonom->Reset();
	while (!other.pMonom->IsEnded())
	{
		result = result + *other.pMonom->Current();
		other.pMonom->Next();
	}
	result.Reduce(); //////!!!
	result.Validation();////////!!!!!
	return result;
}

Polynom Polynom::operator-(const Polynom& temp) const
{
	Polynom result;
	result = *this + (-temp);// unary minus
	return result;
}

Polynom Polynom::operator*(const Polynom& temp) const
{
	Polynom result, tmp(temp), other;
	tmp.pMonom->Reset();
	while (!tmp.pMonom->IsEnded())
	{
		other = *this * *(tmp.pMonom->Current());
		result = result + other;
		tmp.pMonom->Next();
	}
	//result.Reduce();
	//result.Validation();
	return result;
}

Polynom Polynom::operator-() const
{
	Polynom res(*this);
	return(res * (-1.0));
}

bool Polynom::operator==(const Polynom& temp) const
{
	while (!pMonom->IsEnded() || !temp.pMonom->IsEnded())
	{
		if (pMonom->Current() != temp.pMonom->Current())
			return false;
	}
	if (!pMonom->IsEnded() || !temp.pMonom->IsEnded())
		return false;
	return true;
}

Polynom& Polynom::operator=(const Polynom& temp)
{
	if (pMonom)
	{
		delete pMonom;
		pMonom = new TList<unsigned int, double>;
	}
	if (*this == temp)
		return *this;
	temp.pMonom->Reset();
	while (!temp.pMonom->IsEnded())
	{
		pMonom->InsertEnd(temp.pMonom->Current()->key, temp.pMonom->Current()->data);
		temp.pMonom->Next();
	}
	InsertSort();/**/
	return *this;
}

Polynom& Polynom::operator+=(const Polynom& temp)
{
	if (!pMonom)
		return *this;
	pMonom->Reset();
	temp.pMonom->Reset();
	*this = *this + temp;
	return *this;
}

Polynom& Polynom::operator-=(const Polynom& temp)
{
	if (!pMonom)
		return *this;
	*this = *this - temp;
	return *this;
}

Polynom& Polynom::operator*=(const Polynom& temp)
{
	if (!pMonom)
		return *this;
	*this = *this * temp;
	return *this;
}