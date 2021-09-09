#include "Queue.h"
#include <iostream>

void Initiailze(Queue& queue)
{
	queue.count = 0;
	queue.pFront = queue.pRear = nullptr;
}

void Release(Queue& queue)
{
	Element* element{ queue.pFront };

	while (element != nullptr)
	{
		Element* next{ element->pNext };
		delete element;
		element = next;
	}

	Initiailze(queue);
}

void Enqueue(Queue& queue, int value)
{
	Element* element = new Element;
	element->value = value;
	element->pNext = nullptr;

	// Enqueue 넣기 pFront와 pRear가 없을 때
	if (queue.count == 0)
	{
		queue.pFront = element;
		queue.pRear = element;
	}
	else
	{
		queue.pRear->pNext = element;
		queue.pRear = element;
	}

	queue.count++;
}

bool Dequeue(Queue& queue)
{
	if (queue.count == 0)
	{
		std::cout << "Queue is empty..." << std::endl;
		return false;
	}

	Element* element{ queue.pFront };
	std::cout << "DEQUEUE : " << element->value << std::endl;

	queue.pFront = element->pNext;

	delete element;
	queue.count--;

	if (queue.count == 0)
	{
		Initiailze(queue);
	}

	return true;
}

void Print(Queue& queue)
{
	Element* element{ queue.pFront };

	while (element != nullptr)
	{
		std::cout << element->value << std::endl;
		element = element->pNext;
	}
}