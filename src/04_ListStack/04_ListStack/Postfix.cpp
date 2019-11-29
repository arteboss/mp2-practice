#include "Postfix.h"

Variables::Variables(int _size)
{
	size = _size;
	varmas = new Variable[size];
}

int Postfix::Priority(const char s)
{
	if ((s == '*') || (s == '/')) return 3;
	if ((s == '+') || (s == '-')) return 2;
	if (s == '(')  return 1;
	return 0;
}

int Postfix::TypeCheck(const char s)
{
	if (((s >= 'a') && (s <= 'z')) || ((s >= 'A') && (s <= 'Z'))) return 1;
	if (Priority(s) > 0) return 2;
	if (s == ')') return 3;
	return 0;
}

int Postfix::OperationsCount(string line)
{
	int res = 0;
	for (size_t i = 0; i < line.length(); i++)
		if (TypeCheck(line[i]) == 2) res++;
	return res;
}

string Postfix::CreatePostfixForm(string line)
{
	size_t CountLeft = 0, CountRight = 0;
	if (OperationsCount(line) == 0) throw "There is no operations";
	size_t i = 0;
	size_t count = 0;
	if ((TypeCheck(line[0]) == 2) && (line[0] != '(')) throw "Expression can't start with this symbol";
	if (TypeCheck(line[line.length() - 1]) == 2) throw "Expression can't end with this symbol";
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
		{
			i++;
			continue;
		}
		if (TypeCheck(line[i]) == 1)
		{
			Stack2->Push(line[i]);
		}
		else if (TypeCheck(line[i]) == 2)
		{
			if ((line[i] != '(') && (!Stack1->IsEmpty()))
			{
				while (Priority(Stack1->Top()) >= Priority(line[i]))
				{
					Stack2->Push(Stack1->Top());
					Stack1->Pop();
				}
				Stack1->Push(line[i]);
			}
			else Stack1->Push(line[i]);
			if (line[i] == '(') CountLeft++;
		}
		else if (TypeCheck(line[i]) == 3)
		{
			CountRight++;
			if (CountRight > CountLeft) throw "Wrong order of '(' and ')' or ')' without '(' ";
			while (Stack1->Top() != '(')
			{
				Stack2->Push(Stack1->Top());
				Stack1->Pop();
			}
			Stack1->Pop();
		}
		else throw "Unacceptable symbol";
		i++;
	}
	if (CountRight < CountLeft) throw "There is a non-closed '(' ";
	while (!(Stack1->IsEmpty()))
	{
		Stack2->Push(Stack1->Top());
		Stack1->Pop();
	}
	string res;
	while (!Stack2->IsEmpty())
	{
		res += Stack2->Top();
		Stack2->Pop();
	}
	reverse(res.rbegin(), res.rend());
	return res;
}

Postfix::Postfix(int type, int size)
{
	switch (type)
	{
	case(ArrayStack):
		Stack1 = new TArrayStack<char>(size);
		Stack2 = new TArrayStack<char>(size);
		Stack3 = new TArrayStack<double>(size);
		break;
	case(ListStack):
		Stack1 = new TListStack<char>;
		Stack2 = new TListStack<char>;
		Stack3 = new TListStack<double>;
	}
}

Variables Postfix::FillVariables(string line)
{
	Variables mas(line.length() - OperationsCount(line));
	size_t i = 0, j = 0;
	while (line[i] != '\0')
	{
		if (TypeCheck(line[i]) == 1)
		{
			if (line.find_first_of(line[i]) == i)
				mas.varmas[j++].Name = line[i];
		}
		i++;
	}
	for (size_t l = 0; l < j; l++)
	{
		cout << "Enter the value of " << mas.varmas[l].Name << endl;
		cin >> mas.varmas[l].Value;
	}
	return mas;
}

double Postfix::Calculate(string line, Variables mas)
{
	size_t Variables = line.length() - OperationsCount(line);
	size_t i = 0, j = 0;
	double a = 0, b = 0;
	while (line[i] != '\0')
	{
		if (TypeCheck(line[i]) == 1)
		{
			for (int m = 0; m < mas.size; m++)
				if (mas.varmas[m].Name == line[i]) Stack3->Push(mas.varmas[m].Value);
		}
		else if (TypeCheck(line[i]) == 2)
		{
			b = Stack3->Top();
			Stack3->Pop();
			a = Stack3->Top();
			Stack3->Pop();
			if (line[i] == '+') Stack3->Push(a + b);
			else if (line[i] == '-') Stack3->Push(a - b);
			else if (line[i] == '*') Stack3->Push(a * b);
			else if (line[i] == '/') Stack3->Push(a / b);
		}
		i++;
	}
	return Stack3->Top();
}