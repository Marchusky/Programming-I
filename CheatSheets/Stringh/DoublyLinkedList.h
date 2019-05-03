#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <cassert>

//all template classes must be entirely 
//defined in the header (so, in the .h file)
//Nothing must be defined in the .cpp

template<class T>
class DoublyLinkedList
{
public:

	~DoublyLinkedList()
	{
		clear();
	}

	void push_back(int value)
	{
		Node *node = new Node;
		node->value = value;
		node->prev = last;
		node->next = nullptr;

		if (last != nullptr)
		{
			last->next = node;
		}

		if (num_elems == 0)
		{
			first = node;
		}

		last = node;

		num_elems++;
	}

	void push_front(int value)
	{
		Node *node = new Node;
		node->value = value;
		node->prev = nullptr;
		node->next = first;

		if (first != nullptr)
		{
			first->prev = node;
		}

		if (num_elems == 0)
		{
			last = node;
		}

		first = node;

		num_elems++;
	}

	void pop_front()
	{
		assert(num_elems > 0 && "The list is empty");

		Node *to_delete = first;
		
		first = first->next;
		
		if (first != nullptr)
		{
			first->prev = nullptr;
		}
		else
		{
			last = nullptr;
		}

		delete to_delete;

		num_elems--;
	}

	void pop_back()
	{
		assert(num_elems > 0 && "The list is empty");

		Node *to_delete = last;

		last = last->prev;

		if (last != nullptr)
		{
			last->next = nullptr;
		}
		else
		{
			first = nullptr;
		}

		delete to_delete;

		num_elems--;
	}

	void insert(unsigned int index, int value)
	{
		assert(index <= num_elems && "Index out of bounds");
		if (index == 0) //principio
		{
			push_front(value);
		}
		else if (index == num_elems) //final
		{
			push_back(value);
		}
		else //por el medio
		{
			// Find element
			Node *it = first;
			for (int i = 0; i < index; ++i) //avanza el it(iterador) hasta el index para saber la posición.
			{
				it = it->next;
			}

			// Create a new node
			Node *new_node = new Node; //creo nodo
			new_node->value = value;   //le pongo el valor
			new_node->prev = it->prev; 
			new_node->next = it;
			//con dibujito (v1 v2) sin dibujito (it)
			Node *v1 = it -> next;
			Node *v2 = it;
			v1->prev->next = new_node;
			v2->prev = new_node;
		}
	}

	void erase(unsigned int index)
	{
		assert(index < num_elems && "Index out of bounds");

		// Find element to erase
		Node *it = first;
		for (int i = 0; i < index; ++i)
		{
			it = it->next;
		}

		// Re-link the list / detach the it pointer
		if (it->prev != nullptr) //si no hay anterior...es el primero
		{
			it->prev->next = it->next;
		}
		if (it->next != nullptr) //si no hay siguiente...es el ultimo
		{
			it->next->prev = it->prev;
		}

		// Update first and last pointers if needed
		if (first == it)
		{
			first = first->next;
		}
		if (last == it)
		{
			last = last->prev;
		}

		// Delete the detached node
		delete it;

		num_elems--;
	}

	T value_at(unsigned int index) const
	{
		assert(index < num_elems && "Index out of bounds");
		Node *it = first;
		for (int i = 0; i < index; ++i)
		{
			it = it->next;
		}
		return it->value;
	}


	void clear()
	{
		Node *it = first;
		while (it != nullptr)
		{
			Node *it_next = it->next;
			delete it;
			it = it_next;
		}
		first = nullptr;
		last = nullptr;
		num_elems = 0;
	}

	T &front()
	{
		assert(num_elems > 0 && "The list is empty");

		return first->value;
	}

	T &back()
	{
		assert(num_elems > 0 && "The list is empty");

		return last->value;
	}

	bool empty() const { return num_elems == 0; }
	int size() const { return num_elems; }

	void print() const
	{
		Node *it = first;
		while (it != nullptr)
		{
			std::cout << it->value << " ";
			it = it->next;
		}
		std::cout << std::endl;
	}

private:

	struct Node
	{
		T value = 0;
		Node *next = nullptr;
		Node *prev = nullptr;
	};

	Node *first = nullptr;
	Node *last = nullptr;
	int num_elems = 0;
};

#endif // DOUBLY_LINKED_LIST_H