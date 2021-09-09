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

	element->pNext = stack.top;
	stack.top = element;
	stack.count++;
}

bool Pop(Stack& stack)
{
	if (stack.count == 0)
	{
		std::cout << "Stack is empty..." << std::endl;
		return false;
	}

	Element* prevTop{ stack.top };

	std::cout << "POP : " << prevTop->value << std::endl;

	stack.top = stack.top->pNext;
	stack.count--;

	delete prevTop;

	return true;
}

void Print(Stack& stack)
{
	Element* element = stack.top;

	while (element != nullptr)
	{
		std::cout << element->value << std::endl;
		element = element->pNext;
	}
}