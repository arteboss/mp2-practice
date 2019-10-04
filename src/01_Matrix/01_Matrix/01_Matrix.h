#pragma once
#include <iostream>

template <typename ValType>
class TVector
{
protected:
	ValType* elems;
	int size;
	int startIndex;
public:
	TVector(int _size = 10, int _startIndex = 0);
	TVector(const TVector&);
	~TVector();
	bool operator==(const TVector&) const;
	bool operator!=(const TVector&) const;
	TVector& operator=(const TVector&);
	TVector operator+(ValType) const;
	TVector operator+(const TVector&) const;
	TVector operator-(ValType) const;
	TVector operator-(const TVector&) const;
	TVector operator*(ValType) const;
	ValType operator*(const TVector&) const;
	ValType& operator[](int);
	const ValType& operator[](int) const;
	ValType length() const;
	int Size() const;
	int StartIndex() const;
	void random_vector();

	friend std::ostream & operator<<(std::ostream& out, const TVector<ValType>& tmp)
	{
		if (tmp.size <= 0) throw "Wrong size of vector";
		for (int i = 0; i < tmp.size; i++)
		{
			out << " " << tmp.elems[i] << " ";
		}
		return out;
	}

	friend std::istream& operator>>(std::istream& in, const TVector& tmp)
	{
		if (tmp.size <= 0) throw "Wrong size of vector";
		for (int i = 0; i < tmp.size; i++)
		{
			std::cout << "Enter " << i << " element: ";
			in >> tmp.elems[i];
		}
		return in;
	}
};

template<typename ValType>
TVector<ValType>::TVector(int _size, int _startIndex)
{
	if (_size <= 0) throw "Wrong size of vector";
	elems = new ValType[_size];
	size = _size;
	startIndex = _startIndex;
}

template<typename ValType>
TVector<ValType>::TVector(const TVector& tmp)
{
	if (tmp.size <= 0) throw "Wrong size of vector";
	size = tmp.size;
	startIndex = tmp.startIndex;
	elems = new ValType[size];
	for (int i = 0; i < size; i++) elems[i] = tmp.elems[i];
}

template<typename ValType>
TVector<ValType>::~TVector()
{
	delete[] elems;
}

template<typename ValType>
bool TVector<ValType>::operator==(const TVector& tmp) const
{
	if ((size != tmp.size) || (startIndex != tmp.startIndex)) return false;
	for (int i = 0; i < size; i++)
	{
		if (tmp.elems[i] != elems[i])
			return false;
	}
	return true;
}

template<typename ValType>
bool TVector<ValType>::operator!=(const TVector& tmp) const
{
	return !(tmp == *this);
}

template<typename ValType>
TVector<ValType>& TVector<ValType>::operator=(const TVector& tmp)
{
	if (this->elems == tmp.elems) throw "Self-equation";
	size = tmp.size;
	startIndex = tmp.startIndex;
	delete[] elems;
	elems = new ValType[size];
	for (int i = 0; i < size; i++)
	{
		elems[i] = tmp.elems[i];
	}
	return *this;
}

template<typename ValType>
TVector<ValType> TVector<ValType>::operator+(ValType tmp) const
{
	TVector<ValType> tmp1(*this);
	for (int i = 0; i < size; i++)
	{
		tmp1.elems[i] += tmp;
	}
	return tmp1;
}

template<typename ValType>
TVector<ValType> TVector<ValType>::operator+(const TVector& tmp) const
{
	if ((size != tmp.size) || (startIndex != tmp.startIndex)) throw "Different sizes of vectors";
	TVector<ValType> tmp1(*this);
	for (int i = 0; i < size; i++)
	{
		tmp1.elems[i] += tmp.elems[i];
	}
	return tmp1;
}

template<typename ValType>
TVector<ValType> TVector<ValType>::operator-(ValType tmp) const
{
	TVector<ValType> tmp1(*this);
	for (int i = 0; i < size; i++)
	{
		tmp1.elems[i] -= tmp;
	}
	return tmp1;
}

template<typename ValType>
TVector<ValType> TVector<ValType>::operator-(const TVector& tmp) const
{
	if ((size != tmp.size) || (startIndex != tmp.startIndex)) throw "Different sizes of vectors";
	TVector<ValType> tmp1(*this);
	for (int i = 0; i < size; i++)
	{
		tmp1.elems[i] -= tmp.elems[i];
	}
	return tmp1;
}

template<typename ValType>
TVector<ValType> TVector<ValType>::operator*(ValType tmp) const
{
	TVector<ValType> tmp1(*this);
	for (int i = 0; i < size; i++)
	{
		tmp1.elems[i] *= tmp;
	}
	return tmp1;
}

template<typename ValType>
ValType TVector<ValType>::operator*(const TVector& tmp) const
{
	if ((size != tmp.size) || (startIndex != tmp.startIndex)) throw "Different sizes of vectors";
	TVector<ValType> tmp1(*this);
	ValType res = 0;
	for (int i = 0; i < size; i++)
	{
		res += tmp1.elems[i] * tmp.elems[i];
	}
	return res;
}

template<typename ValType>
ValType & TVector<ValType>::operator[](int index)
{
	if ((index - startIndex) >= size) throw "Out of range";
	return elems[index - startIndex];
}

template<typename ValType>
const ValType& TVector<ValType>::operator[](int index) const
{
	if ((index - startIndex) >= size) throw "Out of range";
	return elems[index - startIndex];
}

template<typename ValType>
ValType TVector<ValType>::length() const
{
	if (size <= 0) throw "Wrong size of vector";
	return sqrt((*this) * (*this));
}

template<typename ValType>
inline int TVector<ValType>::Size() const
{
	return size;
}

template<typename ValType>
inline int TVector<ValType>::StartIndex() const
{
	return startIndex;
}

template<typename ValType>
void TVector<ValType>::random_vector()
{
	ValType left = 1, right = 10;
	for (int i = 0; i < size; i++)
		elems[i] = left + ((double)rand() / RAND_MAX) * (right - left);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

template <typename ValType>
class TMatrix : TVector<TVector<ValType>>
{
public:
	TMatrix(int _size = 10);
	TMatrix(const TMatrix<ValType>&);
	TMatrix(const TVector<TVector<ValType>>&);
	~TMatrix();
	bool operator==(const TMatrix&) const;
	bool operator!=(const TMatrix&) const;
	const TMatrix& operator=(const TMatrix&);
	TMatrix operator+(ValType) const;
	TMatrix operator+(const TMatrix&) const;
	TMatrix operator-(ValType) const;
	TMatrix operator-(const TMatrix&) const;
	TMatrix operator*(ValType) const;
	TMatrix operator*(const TMatrix&) const;
	TVector<ValType> operator*(const TVector<ValType>&) const;
	void random_matrix();

	friend std::ostream& operator<<(std::ostream& out, const TMatrix& tmp)
	{
		if (tmp.size <= 0) throw "Wrong dimention";
		for (int i = 0; i < tmp.size; i++)
		{
			out << " " << tmp.elems[i] << " " << "\n";
		}
		return out;
	}

	friend std::istream& operator>>(std::istream& in, TMatrix& tmp)
	{
		if (tmp.size <= 0) throw "Wrong dimention";
		for (int i = 0; i < tmp.size; i++)
		{
			std::cout << "Enter " << i << " element: ";
			in >> tmp.elems[i];
		}
		return in;
	}
};

template<typename ValType>
TMatrix<ValType>::TMatrix(int _size) : TVector<TVector<ValType>>(_size)
{
	for (int i = 0; i < _size; i++)
		this->elems[i] = TVector<ValType>(_size - i, i);
}

template<typename ValType>
TMatrix<ValType>::TMatrix(const TMatrix<ValType>& tmp)
{
	this->size = tmp.size;
	this->elems = new TVector<ValType>[this->size];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = tmp.elems[i];
}

template<typename ValType>
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType>>& tmp) : TVector<TVector<ValType>>(tmp)
{

}

template<typename ValType>
TMatrix<ValType>::~TMatrix()
{
}

template<typename ValType>
bool TMatrix<ValType>::operator==(const TMatrix& tmp) const
{
	if (tmp.size != this->size) throw "Different sizes of matrixes";
	for (int i = 0; i < this->size; i++)
	{
		if (this->elems[i] != tmp.elems[i])
			return false;
	}
	return true;
}

template<typename ValType>
bool TMatrix<ValType>::operator!=(const TMatrix& tmp) const
{
	return !(tmp == (*this));
}

template<typename ValType>
const TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix& tmp)
{
	if (tmp.size == 0) throw "Null dimension";
	if (this->size != tmp.size)
	{
		this->size = tmp.size;
		delete this->elems;
		this->elems = new TVector<ValType>[tmp.size];
	}
	for (int i = 0; i < this->size; i++)
	{
		this->elems[i] = tmp.elems[i];
	}
	return *this;
}

template<typename ValType>
TMatrix<ValType> TMatrix<ValType>::operator+(ValType tmp) const
{
	TMatrix<ValType> tmp1(*this);
	for (int i = 0; i < this->size; i++)
		tmp1.elems[i] = tmp1.elems[i] + tmp;
	return tmp1;
}

template<typename ValType>
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix& tmp) const
{
	if (this->size != tmp.size) throw "Inccorect sizes";
	TMatrix<ValType> tmp1(*this);
	for (int i = 0; i < this->size; i++)
		tmp1.elems[i] = tmp1.elems[i] + tmp.elems[i];
	return tmp1;
}

template<typename ValType>
TMatrix<ValType> TMatrix<ValType>::operator-(ValType tmp) const
{
	TMatrix<ValType> tmp1(*this);
	for (int i = 0; i < this->size; i++)
		tmp1.elems[i] = tmp1.elems[i] - tmp;
	return tmp1;
}

template<typename ValType>
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix& tmp) const
{
	if (this->size != tmp.size) throw "Inccorect sizes";
	TMatrix<ValType> tmp1(*this);
	for (int i = 0; i < this->size; i++)
		tmp1.elems[i] = tmp1.elems[i] - tmp.elems[i];
	return tmp1;
}

template<typename ValType>
TMatrix<ValType> TMatrix<ValType>::operator*(ValType tmp) const
{
	TMatrix<ValType> tmp1(*this);
	for (int i = 0; i < this->size; i++)
		tmp1.elems[i] = tmp1.elems[i] * tmp;
	return tmp1;
}

template<typename ValType>
TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix& tmp) const
{
	if (this->size != tmp.size) throw "Incorrect sizes";
	TMatrix<ValType> tmp1(*this);
	for (int i = 0; i < tmp1.size; i++)
	{
		int flag = 1;
		int si = tmp.elems[i].StartIndex();
		for (int j = si; j < tmp1.size; j++)
		{
			tmp1.elems[i][j] = ValType(0);
			for (int k = 0; k < flag; k++)
			{
				tmp1.elems[i][j] = tmp1.elems[i][j] + this->elems[i][k + i] * tmp.elems[k + i][j];
			}
			flag++;
		}
	}
	return tmp1;
}

template<typename ValType>
TVector<ValType> TMatrix<ValType>::operator*(const TVector<ValType>& tmp) const
{
	int _size = tmp.Size();
	if (this->size != _size) throw "Different sizes";
	TVector<ValType> tmp1(_size);
	for (int i = 0; i < _size; i++)
	{
		tmp1[i] = ValType(0);
		int si = this->elems[i].StartIndex();
		for (int j = si; j < _size; j++)
			tmp1[i] = tmp1[i] + this->elems[i][j] * tmp[j];
	}
	return tmp1;
}

template<typename ValType>
void TMatrix<ValType>::random_matrix()
{
	for (int i = 0; i < this->size; i++)
		this->elems[i].random_vector();
}