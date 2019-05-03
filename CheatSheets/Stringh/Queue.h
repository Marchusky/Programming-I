#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>

#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_CHUNK_SIZE 8

template <class T> //cambiar ints por Ts.
class Queue
{
public:

	~Queue()
	{
		delete[] array;
	}

	void enqueue(T value)
	{
		if (num_elems == capacity) {
			increaseCapacity();
		}

		if (num_elems == 0)
		{
			index_front = 0;
			index_back = 0;
		}
		else
		{
			index_back = (index_back + 1) % capacity; //para que sea circular (donut)
		}

		array[index_back] = value;
		num_elems++;
	}

	void dequeue()
	{
		assert(num_elems > 0 && "The queue is empty");

		index_front = (index_front + 1) % capacity;
		num_elems--;

		if (num_elems == 0)
		{
			index_front = -1;
			index_back = -1;
		}
	}

	T front() const //retorna una T
	{
		assert(num_elems > 0 && "The queue is empty");

		return array[index_front];
	}

	T back() const
	{
		assert(num_elems > 0 && "The queue is empty");

		return array[index_back];
	}

	void clear()
	{
		delete[] array;
		array = nullptr;
		capacity = 0;
		num_elems = 0;
		index_front = -1;
		index_back = -1;
	}

	int size() const
	{
		return num_elems;
	}

	bool empty() const
	{
		return num_elems == 0;
	}

	void print() const
	{
		for (int i = 0; i < num_elems; ++i)
		{
			std::cout << array[(index_front + i) % capacity] << " ";
		}
		std::cout << std::endl;
	}

private:

	void increaseCapacity()
	{
		capacity = capacity + QUEUE_CHUNK_SIZE;
		T *new_array = new T[capacity];
		for (int i = 0; i < num_elems; ++i)
		{
			new_array[i] = array[(index_front + i) % num_elems];
		}
		delete[] array;
		array = new_array;
		index_front = 0;
		index_back = num_elems - 1;
	}

	T *array = new T[QUEUE_CHUNK_SIZE]; //cambia solo los que se refieren a los datos dentro del array
	int index_front = -1;//
	int index_back = -1; // esto son indices no se cambian
	int num_elems = 0;   //
	int capacity = QUEUE_CHUNK_SIZE;
};

#endif // QUEUE_H

