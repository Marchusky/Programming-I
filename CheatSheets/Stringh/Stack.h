#ifndef STACK_H
#define STACK_H

#include <cassert>
#include <iostream>

class Stack
{
public:
	// Ctor. and Dtor.
	Stack();
	~Stack();
	// Modifiers
	void push(int value);
	void pop();
	// Getters
	int top() const;
	bool empty() const;
private:
	int _top; // Current top index (-1 if empty)
	int *_array; // Dynamically allocated array
};#endif // STACK_H