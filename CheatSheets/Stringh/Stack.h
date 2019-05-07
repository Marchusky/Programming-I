#ifndef STACK_H
#define STACK_H
#define MAX_CHUNCK_SIZE 10

#include <cassert>
#include <iostream>

class Stack
{
public:
	// Ctor. and Dtor.
	Stack();
	~Stack()
	{
		delete[]_array;
	}
	// Modifiers
	void push(int value)
	{
		if(_top >= capacity)
		{
			increaseCapacity();
		}
		_top = (_top + 1);
		_array[_top] = value;
	}
	void pop()
	{
		assert(_top != -1 && "Stack is empty");
		_top--;
	}
	// Getters
	int top() const
	{
		return _array[_top];
	}
	bool empty() const
	{
		if (_top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	void increaseCapacity() 
	{
		capacity += MAX_CHUNCK_SIZE;
		int *new_array = new int[capacity];
		for (int i = 0; i < _top + 1; ++i)
		{
			new_array[i] = _array[i];
		}
	}
	int _top; // Current top index (-1 if empty)
	int *_array; // Dynamically allocated array
	int capacity = MAX_CHUNCK_SIZE;
};#endif // STACK_H