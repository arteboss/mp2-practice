#include "01_Matrix.h"

int main()
{
	TVector<double> Vector1(3), Vector2(3), VectorERR(2), VectorRes(3);
	TMatrix<double> Matrix1(3), Matrix2(3), MatrixERR(2), MatrixRes(3), MatrixVectorofVectors(4);
	std::cout << "Trying to make Vector3 with -1 size" << std::endl;
	try
	{
		TVector<double> Vector3(-1);
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	Vector1.random_vector();
	std::cout << "Vector1" << std::endl << Vector1 << std::endl;
	Vector2.random_vector();
	std::cout << "Vector2" << std::endl << Vector2 << std::endl;
	VectorERR.random_vector();
	std::cout << "VectorERR" << std::endl << VectorERR << std::endl;
	std::cout << "Trying to VectorRes1(Vector1):" << std::endl;
	try
	{
		TVector<double> VectorRes1(Vector1);
		std::cout << "Success" << std::endl;
		std::cout << "VectorRes1" << std::endl << VectorRes1 << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Trying to VectorRes = Vector1" << std::endl;
	try
	{
		VectorRes = Vector1;
		std::cout << "Success" << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Trying to VectorRes = VectorRes" << std::endl;
	try
	{
		VectorRes = VectorRes;
		std::cout << "Success" << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Vector1 == Vector2?" << std::endl;
	try
	{
		if (Vector1 == Vector2) std::cout << "True" << std::endl;
		if (Vector1 != Vector2) std::cout << "False" << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Vector1 + 10:" << std::endl;
	std::cout << Vector1 + 10 << std::endl;
	std::cout << "Vector2 - 10:" << std::endl;
	std::cout << Vector2 - 10 << std::endl;
	std::cout << "VectorERR * 10:" << std::endl;
	std::cout << VectorERR * 10 << std::endl;
	std::cout << "Vector1 + Vector2:" << std::endl;
	try
	{
		VectorRes = Vector1 + Vector2;
		std::cout << VectorRes << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Vector1 + VectorERR:" << std::endl;
	try
	{
		VectorRes = Vector1 + VectorERR;
		std::cout << VectorRes << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Vector1 - Vector2:" << std::endl;
	try
	{
		VectorRes = Vector1 - Vector2;
		std::cout << VectorRes << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Vector1 - VectorERR:" << std::endl;
	try
	{
		VectorRes = Vector1 - VectorERR;
		std::cout << VectorRes << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Vector1 * Vector2:" << std::endl;
	try
	{
		double tmp = Vector1 * Vector2;
		std::cout << tmp << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Vector1 * VectorERR:" << std::endl;
	try
	{
		double tmp = Vector1 * VectorERR;
		std::cout << tmp << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Vector1[0] = ";
	try
	{
		std::cout << Vector1[0] << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Vector1[100] = ";
	try
	{
		std::cout << Vector1[100] << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "The length of Vector1 is ";
	try
	{
		std::cout << Vector1.length() << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "The length of Vector2 is ";
	try
	{
		std::cout << Vector2.length() << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Trying to make Matrix3 with -1 size" << std::endl;
	try
	{
		TMatrix<double> Matrix3(-1);
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	TVector<TVector<double>> VectorOfVectors(4);
	for (int i = 0; i < 4; i++)
	{
		TVector<double> temp(4 - i);
		std::cout << "Enter " << i << " row of vector of vectors: " << std::endl;
		std::cin >> temp;
		VectorOfVectors[i] = temp;
	}
	std::cout << "Trying to MatrixVectorofVectors = VectorOfVectors(4):" << std::endl;
	try
	{
		MatrixVectorofVectors = VectorOfVectors;
		std::cout << "Success" << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	Matrix1.random_matrix();
	std::cout << "Matrix1" << std::endl << Matrix1 << std::endl;
	Matrix2.random_matrix();
	std::cout << "Matrix2" << std::endl << Matrix2 << std::endl;
	MatrixERR.random_matrix();
	std::cout << "MatrixERR" << std::endl << MatrixERR << std::endl;
	std::cout << "Trying to MatrixRes1(Matrix1):" << std::endl;
	try
	{
		TMatrix<double> MatrixRes1(Matrix1);
		std::cout << "Success" << std::endl;
		std::cout << "MatrixRes1" << std::endl << MatrixRes1 << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Trying to MatrixRes = Matrix2:" << std::endl;
	try
	{
		MatrixRes = Matrix2;
		std::cout << "Success" << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Matrix1 == Matrix2?" << std::endl;
	try
	{
		if (Matrix1 == Matrix2) std::cout << "True" << std::endl;
		if (Matrix1 != Matrix2) std::cout << "False" << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Matrix1 == MatrixERR?: ";
	try
	{
		if (Matrix1 == MatrixERR) std::cout << "True" << std::endl;
		if (Matrix1 != MatrixERR) std::cout << "False" << std::endl;
		
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Matrix1 + 10:" << std::endl;
	std::cout << Matrix1 + 10 << std::endl;
	std::cout << "Matrix2 - 10:" << std::endl;
	std::cout << Matrix2 - 10 << std::endl;
	std::cout << "MatrixERR * 10:" << std::endl;
	std::cout << MatrixERR * 10 << std::endl;
	std::cout << "Matrix1 + Matrix2:" << std::endl;
	try
	{
		MatrixRes = Matrix1 + Matrix2;
		std::cout << MatrixRes << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Matrix1 + MatrixERR:";
	try
	{
		MatrixRes = Matrix1 + MatrixERR;
		std::cout << MatrixRes << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Matrix1 - Matrix2: " << std::endl;
	try
	{
		MatrixRes = Matrix1 - Matrix2;
		std::cout << MatrixRes << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Matrix1 - MatrixERR: ";
	try
	{
		MatrixRes = Matrix1 - MatrixERR;
		std::cout << MatrixRes << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Matrix1 * Matrix2: " << std::endl;
	try
	{
		MatrixRes = Matrix1 * Matrix2;
		std::cout << MatrixRes << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Matrix1 * MatrixERR: ";
	try
	{
		MatrixRes = Matrix1 * MatrixERR;
		std::cout << MatrixRes << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << "Matrix1 * Vector1: ";
	try
	{
		VectorRes = Matrix1 * Vector1;
		std::cout << VectorRes << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	std::cout << " Matrix1 * VectorERR: ";
	try
	{
		VectorRes = Matrix1 * VectorERR;
		std::cout << VectorRes << std::endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
	system("pause");
}