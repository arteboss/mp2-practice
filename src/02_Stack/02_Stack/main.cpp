#include "PostfixForm.h"

int main()
{
	string line, line1;
	double res;
	cout << "Enter the expression" << endl;
	getline(cin, line);
	try
	{
		line1 = Postfix::CreatePostfixForm(line);
		cout << "Postfix form:" << endl;
		cout << line1 << endl;
		res = Postfix::Calculate(line1, Postfix::FillVariables(line1));
		cout << "The value of this expression is " << res << endl;
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	system("pause");
}