#include"stack.h"

static string StackID = "0";

Stack::Stack()
{
	spointer = nullptr;
}

Stack::~Stack()
{
	while (!isEmpty())
	{
		DNode* temp = spointer;
		spointer = spointer->prev;
		if (spointer) 
		{
			spointer->next = nullptr;
		}
		char res = temp->data;
		delete temp;
		len--;
	}
}

void Stack::SPUSH(char elem)
{
	DNode* newNode = new DNode(elem);
	newNode->prev = spointer;
	if (spointer) 
	{
		spointer->next = newNode;
	}
	spointer = newNode;
	len++;
}

char Stack::SPOP()
{
	if (isEmpty())
	{
		cout << "Пустой стек\n";
		return 'e';
	}
	DNode* temp = spointer;
	spointer = spointer->prev;
	if (spointer) 
	{
		spointer->next = nullptr;
	}
	char res = temp->data;
	delete temp;
	len--;
	return res;
}

char Stack::SGET(int index) 
{
	DNode* current = spointer;
	int currentIndex = 0;

	while (current != nullptr)
	{
		if (currentIndex == index)
		{
			return current->data;
		}
		current = current->prev;
		currentIndex++;
	}
	cout << "Index out of range.";
	return 'e';
}

void Stack::PRINT()
{
	if (isEmpty())
	{
		cout << "Пустой стек\n";
		return;
	}
	DNode* current = spointer;
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->prev;
	}
	cout << "- дно \n";
}