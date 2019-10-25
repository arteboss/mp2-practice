#pragma once
#include "02_Stack.h"

using namespace std;

struct Variable
{
	char Name;
	double Value;
};

struct Variables
{
	Variable* varmas;
	int size;
	Variables(int);
};

class Postfix
{
private:
	static int Priority(const char);
	static int TypeCheck(const char);
	static int OperationsCount(string);
public:
	static Variables FillVariables(string);
	static string CreatePostfixForm(string);
	static double Calculate(string, Variables);
};