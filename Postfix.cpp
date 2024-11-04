#include"Postfix.h"



int significant(char sym)
{
	if (sym == '+') return 0;
	if (sym == '-') return 0;
	if (sym == '/') return 1;
	if (sym == '*') return 1;
	if (sym == '(' || sym == ')') return 0;
	return -1;
}

string InfixToPostfix(string inputString)
{
	Stack operators;
	size_t length = inputString.size();
	string res;
	string onceElem;
	for (size_t i = 0; i < length; i++)
	{
		if (isdigit(inputString[i]))
		{
			while (isdigit(inputString[i])) onceElem += inputString[i++]; i--;
			res += onceElem;
			onceElem.clear();
			continue;
		}
		if (inputString[i] == '(')
		{
			string staples;
			i++;
			while (inputString[i] != ')') staples += inputString[i++];
			string elem = InfixToPostfix(staples);
			res += elem;
			continue;
		}
		if (operators.isEmpty())
		{
			operators.SPUSH(inputString[i]);
		}
		else
		{
	
			int currentSignificant = significant(inputString[i]);
			if (significant(operators.SGET(0)) < currentSignificant)
			{
				operators.SPUSH(inputString[i]);
			}
			else
			{
				while (!operators.isEmpty() && significant(operators.SGET(0)) >= currentSignificant)
				{
					char currentOperator = operators.SPOP();
					res += currentOperator;
				}
				operators.SPUSH(inputString[i]);
			}
		}
	}
	while (!operators.isEmpty())
	{
		char currentOperator = operators.SPOP();
		if (currentOperator != '(' && currentOperator != ')')
		{
			res += currentOperator;
		}
	}
	return res;
}