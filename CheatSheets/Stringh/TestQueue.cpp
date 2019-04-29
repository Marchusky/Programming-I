#include "Queue.h"
#include <iostream>

void test_queue()
{
	std::cout << "*** TEST_QUEUE ***" << std::endl;
	std::cout << std::endl;

	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	std::cout << "The queue should print: 1 2 3" << std::endl << "contents: ";
	q.print();
	std::cout << std::endl;

	q.clear();
	std::cout << "The queue should print nothing (it's empty)" << std::endl << "contents: ";
	q.print();
	std::cout << std::endl;

	for (int i = 10; i < 19; ++i) { q.enqueue(i); }
	for (int i = 0; i < 5; ++i) { q.dequeue(); }
	std::cout << "The queue should print from 15 to 18" << std::endl << "contents: ";
	q.print();
	std::cout << std::endl;

	std::cout << "The queue front should be 15" << std::endl << "front: ";
	std::cout << q.front() << std::endl;
	std::cout << std::endl;

	std::cout << "The queue back should be 18" << std::endl << "back: ";
	std::cout << q.back() << std::endl;
	std::cout << std::endl;
}
