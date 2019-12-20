#include "Polynom.h"

int main()
{
	try
	{
		Polynom a;
		a.InsertEnd(123, 2);
		a.InsertEnd(234, -3);
		a.InsertEnd(345, 6);
		Polynom b;
		b.InsertEnd(123, 2);
		b.InsertEnd(234, -3);
		b.InsertEnd(345, 6);
		Polynom c = a + b;
		std::cout << c.Search(123)->koeff << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	return 1;
}