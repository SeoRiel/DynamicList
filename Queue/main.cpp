#include <iostream>
#include "Queue.h"

void PrintInfo()
{
	std::cout << "< QUEUE >" << std::endl;
	std::cout << "[1] ENQUEUE" << std::endl;
	std::cout << "[2] DEQUEUE" << std::endl;
	std::cout << "[3] EXIT" << std::endl;
	std::cout << "------------" << std::endl;
}

void ProcessUserInput(Queue& queue)
{
	int commend{ -1 };

	while (true)
	{
		Print(queue);

		std::cout << std::endl;
		std::cout << " > ";
		std::cin >> commend;

		switch (commend)
		{
			case ENQUEUE:
			{
				int value;
				std::cout << "	enqueue value : ";
				std::cin >> value;
				Enqueue(queue, value);
				break;
			}

			case DEQUEUE:
			{
				Dequeue(queue);
				break;
			}

			case EXIT:
			{
				return;
				break;
			}

			default:
			{
				std::cout << "잘못된 명령어입니다." << std::endl;
				break;
			}

		}
	}

}

int main()
{
	Queue myQueue;

	Initiailze(myQueue);

	PrintInfo();
	ProcessUserInput(myQueue);

	Release(myQueue);
}