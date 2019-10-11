#pragma once
#include "02_Stack.h"

using namespace std;

class Postfix
{
private:
	static int Priority(const char);
	static int TypeCheck(const char);
	static int OperationsCount(string);
public:
	static string CreatePostfixForm(string);
	static double Calculate(string);
};