#include "PostfixForm.h"

int Postfix::Priority(const char s)
{
	if ((s == '*') || (s == '/')) return 3;
	if ((s == '+') || (s == '-')) return 2;
	if (s == '(')  return 1;
	return 0;
}

int Postfix::TypeCheck(const char s)
{
	if ( ( (s >= 'a') && (s <= 'z') ) || ( (s >= 'A') && (s <= 'Z') ) ) return 1;
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
	TStack<char> Stack1(OperationsCount(line)), Stack2(line.length());
	size_t i = 0;
	size_t count = 0;
	if (TypeCheck(line[0]) > 2) throw "Expression can't start with this symbol";
	while (line[i] != '\0')
	{
		if (line.find_last_of(line[i] != i)) throw "There is two identical operands in the string";
		if (line[i] == ' ')
		{
			i++;
			continue;
		}
		if (TypeCheck(line[i]) == 1)
		{
			Stack2.Push(line[i]);
			if ((TypeCheck(line[i + 1]) == 1)) throw "Two operands in a row";
		}
		else if (TypeCheck(line[i]) == 2)
		{
			if ((TypeCheck(line[i + 1]) == 2)) throw "Two operators in a row";
			if ((line[i] != '(') && (!Stack1.IsEmpty()))
			{
				while (Priority(Stack1.Top()) >= Priority(line[i]))
					Stack2.Push(Stack1.Pop());
				Stack1.Push(line[i]);
			}
			else Stack1.Push(line[i]);
			if (line[i] == '(') CountLeft++;
		}
		else if (TypeCheck(line[i]) == 3)
		{
			CountRight++;
			if (CountRight > CountLeft) throw "Wrong order of '(' and ')' or ')' without '(' ";
			while (Stack1.Top() != '(')
				Stack2.Push(Stack1.Pop());
			Stack1.Pop();
		}
		else throw "Unacceptable symbol";
		if (CountRight < CountLeft) throw "There is a non-closed '(' ";
		i++;
	}
	while (!(Stack1.IsEmpty())) Stack2.Push(Stack1.Pop());
	string res;
	res.resize(Stack2.GetTop(), 0);
	for (string::reverse_iterator j = res.rbegin(); !Stack2.IsEmpty(); j++)
		*j = Stack2.Pop();
	return res;
}

double Postfix::Calculate(string line)
{
	size_t Variables = line.length() - OperationsCount(line);
	double* mas = new double[Variables];
	size_t j = 0;
	TStack<double> Stack(Variables);
	size_t i = 0;
	double a = 0, b = 0;
	while (line[i] != '\0')
	{
		if (TypeCheck(line[i]) == 1)
		{
			cout << "Enter the value of " << line[i] << ":"<< endl;
			cin >> mas[j];
			Stack.Push(mas[j]);
			j++;
		}
		else if (TypeCheck(line[i]) == 2)
		{
			b = Stack.Pop();
			a = Stack.Pop();
			if (line[i] == '+') Stack.Push(a + b);
			else if (line[i] == '-') Stack.Push(a - b);
			else if (line[i] == '*') Stack.Push(a * b);
			else if (line[i] == '/') Stack.Push(a / b);
		}
		i++;
	}
	return Stack.Pop();
}

