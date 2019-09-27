#include "Matrix.h"

int main()
{
	TVector<double> Vector1(3), Vector2(2), VectorResult(3);
	TMatrix<double> Matrix1(3), Matrix2(3), Matrix3(2), Matrix5(4), MatrixResult(3);
	TVector<TVector<double>> VectorOfVectors1(4), VectorOfVectors2(2);
	for (int i = 0; i < 4; i++)
	{
		TVector<double> temp(4 - i);
		for (int j = i; j < 4; j++)
		{
			temp[j - i] = (double)(i + j + 1);
		}
		VectorOfVectors1[i] = temp;
	}
	std::cout << "Matrix5 = VectorOfVectors1(4)" << std::endl;
	try
	{
		Matrix5 = VectorOfVectors1;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Matrix5 = VectorOfVectors2(2) ";
	try
	{
		Matrix5 = VectorOfVectors2;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Matrix4(-3)";
	try
	{
		TMatrix<double> Matrix4(-3);
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	Vector1.Randomaze();
	Matrix1.Randomaize();
	Matrix3.Randomaize();
	std::cin >> Matrix2;
	std::cout << "MatrixResult = Matrix2:" << std::endl;
	MatrixResult = Matrix2;
	std::cout << "Matrix1" << std::endl << Matrix1 << "Matrix2" << std::endl << Matrix2;
	std::cout << " Matrix1 == Matrix2?: ";
	try
	{
		if (Matrix1 == Matrix2)
		{
			std::cout << "Equal" << std::endl;
		}
		else
		{
			std::cout << "Different" << std::endl;
		}
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << " Matrix1 != Matrix2?: ";
	try
	{
		if (Matrix1 != Matrix2)
		{
			std::cout << "Different" << std::endl;
		}
		else
		{
			std::cout << "Equal" << std::endl;
		}
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Matrix1 != Matrix3?: ";
	try
	{
		if (Matrix1 != Matrix3)
		{
			std::cout << "Different" << std::endl;
		}
		else
		{
			std::cout << "Equal" << std::endl;
		}
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Matrix1 == Matrix3?: ";
	try
	{
		if (Matrix1 == Matrix3)
		{
			std::cout << "Equal" << std::endl;
		}
		else
		{
			std::cout << "Different" << std::endl;
		}
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Matrix1 + Matrix2:" << std::endl;
	try
	{
		MatrixResult = Matrix1 + Matrix2;
		std::cout << MatrixResult << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k;
	}
	std::cout << "Matrix1 + Matrix3:";
	try
	{
		MatrixResult = Matrix1 + Matrix3;
		std::cout << MatrixResult << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Matrix1 - Matrix2: " << std::endl;
	try
	{
		MatrixResult = Matrix1 - Matrix2;
		std::cout << MatrixResult;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Matrix1 - Matrix3: ";
	try
	{
		MatrixResult = Matrix1 - Matrix3;
		std::cout << MatrixResult;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Matrix1 * Matrix2: " << std::endl;
	try
	{
		MatrixResult = Matrix1 * Matrix2;
		std::cout << MatrixResult;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Matrix1 * Matrix3: ";
	try
	{
		MatrixResult = Matrix1 * Matrix3;
		std::cout << MatrixResult;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Matrix1 + 1421:" << std::endl;
	std::cout << Matrix1 + 1412;
	std::cout << "Matrix2 - 67545:" << std::endl;
	std::cout << Matrix2 - 67545;
	std::cout << "Matrix3 * 1564:" << std::endl;
	std::cout << Matrix3 * 1564;
	std::cout << "Matrix1 * Vector1:" << std::endl;
	try
	{
		VectorResult = Matrix1 * Vector1;
		std::cout << VectorResult << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << " Matrix1 * Vector2: ";
	try
	{
		VectorResult = Matrix1 * Vector2;
		std::cout << VectorResult << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	system("pause");
}