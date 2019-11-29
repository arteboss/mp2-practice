#include "Postfix.h"
#include <string>

int main()
{
	string line, line1;
	double res;
	int type;
	try
	{
		cout << "Enter a type of a stack: 0 - ArrayStack, 1 - ListStack" << endl;
		cin >> type;
		getchar();
		cout << "Enter the expression" << endl;
		getline(cin, line);
		Postfix post(type, line.size());
		line1 = post.CreatePostfixForm(line);
		cout << "Postfix form:" << endl;
		cout << line1 << endl;
		res = post.Calculate(line1, post.FillVariables(line1));
		cout << "The value of this expression is " << res << endl;
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	system("pause");
}