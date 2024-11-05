#include<iostream>
//#include<Windows.h>
#include<fstream>
#include"Postfix.h"
#include"Tools.h"
#include"set.h"
#include"Turtle.h"
#include"Array.h"
#include"histogram.h"
#include"Tree.h"
#include"MaxLenUbiqueSubString.h"


using namespace std;


int main()
{
	//SetConsoleCP(65001);
	//SetConsoleOutputCP(65001);

	cout << "numberOfProgram=";
	int numberOfProgram;
	cin >> numberOfProgram;

	switch (numberOfProgram)
	{
	case 1:
	{
		string infix;
		cin.ignore();
		getline(cin, infix);
		string postfix = InfixToPostfix(infix);
		cout << postfix << '\n';
		break;
	}
	case 2:
	{
		int quantity;
		cout << "N=";
		cin >> quantity;

		Pair<int, int>* statements = new Pair<int,int>[quantity];
		for (size_t i = 0; i < quantity; i++)
		{
			Pair<int, int> p;
			cin >> p;
			statements[i] = p;
		}
		cout << TrustTurtle(quantity, statements) << '\n';
		break;
	}
	case 3:
	{
		string message;
		cin.ignore();
		getline(cin, message);

		Array hist(127);
		hist = GetHistogram(message);

		for (int i = 0; i < 127; i++)
		{
			if (hist[i] == 0) continue;
			else
			{
				char sym = i;
				cout << sym;
				for (size_t j = 0; j < hist[i]; j++)
				{
					cout << '#';
				}
				cout << '\n';
			}
		}
		break;
	}

	case 4:
	{
		cout << "How many elem  ";
		int quantity;
		cin >> quantity;
		Tree tree;
		DL<int> elements;
		for (size_t i = 0; i < quantity; i++)
		{
			int elem;
			cin >> elem;
			if (tree.findNode(tree.root, elem) == nullptr)
			{
				tree.TINSERT(elem);
				elements.LDPUSHT(elem);
			}
		}
		tree.PRINT(tree.root);
		for (size_t i = 0; i < elements.len; i++)
		{
			cout << tree.depth(tree.root, tree.findNode(tree.root, elements[i])) << " ";
		}
		cout << '\n';
		break;
	}
	case 5:
	{
		// string fileName = "1.txt";
		// ifstream fileRead(fileName);
		// if (!fileRead.is_open())
		// {
		// 	cout << "There is not such file\n";
		// }
		string str;
		cin>>str;
		// while (!fileRead.eof())
		// {
		// 	string buf;
		// 	getline(fileRead, buf);
		// 	str += buf;
		// }
		// fileRead.close();
		//cout << str << "\n";
		Pair<string, int> res = MaxLenUbiqueSubString(str);
		cout << res.second << '\n' << res.first << '\n';
		break;
	}
	default:
		break;
	}
	
	return 0;
}