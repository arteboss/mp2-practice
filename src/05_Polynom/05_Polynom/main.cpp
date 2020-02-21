#include "Polynom.h"

int main()
{
	TList<unsigned int, double> list;
	list.InsertStart(123, 1);
	list.InsertEnd(321, -6);
	list.InsertBefore(321, 234, -1);
	list.InsertAfter(123, 789, -5);
	cout << list << endl;
	Polynom A, C;
	string PolynomB;
	unsigned int number = 4;
	cout << "Polynom(list): ";
	try
	{
		Polynom F(list);
		cout << F << endl;
		cout << "-Polynom" << endl;
		F = -F;
		cout << F << endl;
	}
	catch (const char* k)
	{
		std::cout << k << endl;
	}
	cout << "Enter polynom A:";
	try
	{
		cin >> A;
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	cout << "Enter polynom B: ";
	try
	{
		getline(cin, PolynomB);
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	Polynom B;
	try
	{
		Polynom G(PolynomB);
		B = G;
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	cout << "Polynom A:" << endl;
	cout << A << endl;
	cout << "Polynom B:" << endl;
	cout << B << endl;
	cout << "Polynom A * 4:" << endl;
	cout << A << " * " << number << " = ";
	try
	{
		C = A * number;
		cout << C << endl;
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	cout <<  endl;
	cout << "Polynom A + Polynom B:" << endl;
	cout << A << " + " << B << " = ";
	try
	{
		C = A + B;
		cout << C << endl;
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	cout << endl;
	cout << "Polynom A - Polynom B:" << endl;
	cout << A << " - " << B << " = ";
	try
	{
		C = A - B;
		cout << C << endl;
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	cout << endl;
	cout << "Polynom A * Polynom B:" << endl;
	cout << A << " * " << B << " = ";
	try
	{
		C = A * B;
		cout << C << endl;
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	cout << endl;
	cout << "Polynom A += Polynom B:" << endl;
	cout << A << " += " << B << " => ";
	try
	{
		A += B;
		cout << A << endl;
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	cout << endl;
	cout << "Polynom A -= Polynom B:" << endl;
	cout << A << " -= " << B << " => ";
	try
	{
		A -= B;
		cout << A << endl;
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	cout << endl;
	cout << "Polynom C * Polynom B:" << endl;
	cout << C << " * " << B << " = ";
	try
	{
		C = C * B;
		cout << C << endl;
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	cout << endl;
	cout << "PolynomG(PolynomC): ";
	try
	{
		Polynom G(C);
		cout << G << endl;
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	cout << endl;
	cout << "Polynom C *= Polynom C:" << endl;
	cout << C << " *= " << C << " => ";
	try
	{
		C *= C;
		cout << C << endl;
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	cout << endl;
	cout << "Polynom A == Polynom B?:" << endl;
	cout << A << " == " << B << " ? ";
	try
	{
		cout << (A == B) << endl;
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	system("pause");
}