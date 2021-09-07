#include "Stack.h"
#include <iostream>

void Initialize(Stack& stack)
{
	stack.count = 0;
	stack.top = nullptr;
}

void Release(Stack& stack)
{
	Element* element{ stack.top };

	while (element != nullptr)
	{
		Element* next = element->pNext;
		delete element;
		element = next;
	}

	Initialize(stack);
}

void Push(Stack& stack, int value)
{
	Element* element = new Element;
	element->value = value;
	stack.count++;

	if (stack.top == nullptr)
	{
		stack.top = element;
		element->pNext = nullptr;
	}
	else if(stack.top->pNext == element)
	{
		stack.top = element->pNext;
		stack.top->pNext = nullptr;
	}
	else
	{
		stack.top = element->pNext;
		stack.top->pNext = nullptr;
	}
}

bool Pop(Stack& stack)
{
	Element* element{ stack.top };

	while (element->pNext != nullptr)
	{
		if (element->pNext == stack.top)
		{
			break;
		}

		stack.top = element->pNext;
	}

	delete element;

	return false;
}

void Print(Stack& stack)
{
	Element* element = stack.top;

	while (element != nullptr)
	{
		std::cout << "# " << stack.count << " : " << element->value << std::endl;
		element = element->pNext;
	}
}