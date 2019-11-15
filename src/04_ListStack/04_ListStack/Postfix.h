#pragma once
#include "TStack.h"
#include <string>
#include <iostream>

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
	TStack<char>* Stack1;
	TStack<char>* Stack2;
	TStack<double>* Stack3;
	static int Priority(const char);
	static int TypeCheck(const char);
	static int OperationsCount(string);
public:
	enum Type
	{ArrayStack, ListStack};
	Postfix(int, size_t);
	Variables FillVariables(string);
	string CreatePostfixForm(string);
	double Calculate(string, Variables);
};