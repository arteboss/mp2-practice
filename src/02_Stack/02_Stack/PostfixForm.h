#pragma once
#include "02_Stack.h"

using namespace std;

class Postfix
{
public:
	static int Priority(const char);
	static int TypeCheck(const char);
	static int OperationsCount(string);
	static string CreatePostfixForm(string);
	static double Calculate(string);
};