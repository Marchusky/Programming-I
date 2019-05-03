#include "DoublyLinkedList.h"
#include <iostream>

void test_doubly_linked_list()
{
	std::cout << "*** TEST_DOUBLY_LINKED_LIST ***" << std::endl;
	std::cout << std::endl;

	DoublyLinkedList<int> l;
	l.push_back(1);
	l.push_front(2);
	l.push_back(3);
	l.push_front(4);
	std::cout << "The list should print: 4 2 1 3" << std::endl << "contents: ";
	l.print();
	std::cout << std::endl;

	l.clear();
	std::cout << "The list should print nothing (it's empty)" << std::endl << "contents: ";
	l.print();
	std::cout << std::endl;

	for (int i = 0; i < 20; ++i) { l.push_back(i); }
	for (int i = 0; i < 20; ++i) { l.push_front(i); }
	for (int i = 0; i < 18; ++i) { l.pop_front(); }
	for (int i = 0; i < 17; ++i) { l.pop_back(); }
	std::cout << "The list should print 1 0 0 1 2" << std::endl << "contents: ";
	l.print();
	std::cout << std::endl;

	std::cout << "The list front should be 1" << std::endl << "front: ";
	std::cout << l.front() << std::endl;
	std::cout << std::endl;

	std::cout << "The list back should be 2" << std::endl << "back: ";
	std::cout << l.back() << std::endl;
	std::cout << std::endl;
}

int main()
{
	test_doubly_linked_list();
	system("pause");
	return 0;
}