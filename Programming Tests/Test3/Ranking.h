//							 //
//	 Marc Gallardo Quesada   //
//							 //



#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <assert.h>


class Ranking
{
public:

	Ranking() :
		first(nullptr),
		num_elems(0)
	{ }

	~Ranking()
	{
		clear();
	}

	int size() const
	{
		return num_elems;
	}

	bool empty() const
	{
		return num_elems == 0;
	}

	const char *head()
	{
		assert(num_elems > 0 && "The ranking is empty");
		return first->name;
	}

	const char *head() const
	{
		assert(num_elems > 0 && "The ranking is empty");
		return first->name;
	}

	void push_front(const char *name)
	{
		Node *new_node = new Node;
		new_node->name = name;
		new_node->prev = nullptr;
		new_node->next = first;
		if (first != nullptr) {
			first->prev = new_node;
		}
		first = new_node;
		num_elems++;
	}

	void clear()
	{
		Node *it = first;
		while (it != nullptr) {
			Node *to_delete = it;
			it = it->next;
			delete to_delete;
		}
	}

	int find_player_position(const char *name)
	{
		// TODO: Insert your code here
		assert(num_elems > 0 && "The list is empty");
		Node *it = first;
		for (int pos = 0; pos < num_elems; ++pos)
		{
			if (it == nullptr)
			{
				return pos;
			}
			else if (strcmp(it->name, name) == 0)
			{
				return pos;
			}
			else
			{
				it = it->next;
			}
		}
		return -1;
	}

	void advance(int position)
	{
		 //TODO: Insert your code here
		assert(position < num_elems && "The position is out of bounds"); //preguntar
		Node *it = first;
		if (position == 0) //principio
		{
			push_front(it->name);
		}
		else //por el medio
		{
			// Find element
			Node *save=nullptr;
			for (int i = 0; i < position; ++i) //avanza el it(iterador) hasta el index para saber la posición.
			{
				it = it->next;
			}
			if (it->next == nullptr) //final
			{
				it->prev->next = nullptr;
				it->prev = it->prev->prev;
				it->prev->prev = it;
				it->next = it->prev;
			}
			else
			{
				it->next->prev = it->prev; //prev actualizado (siguiente)
				it->prev->next = it->next; //next actualizado (anterior)
				it->prev->prev = it; //prev actualizado (anterior)
				it->next = it->prev; //next actualizado (it)
				it->prev = it->prev->prev; //prev actualizado (it)
			}
			//actualizar punteros
			
			
		//	//new_node->value = value;   //le pongo el valor
		//	//new_node->prev = it->prev;
		//	//new_node->next = it;
		}
	}

private:

	struct Node
	{
		const char *name = nullptr;
		Node *next = nullptr;
		Node *prev = nullptr;
	};

	Node *first;
	int num_elems;
};

#endif // PRIORITY_QUEUE_H
