//============================================================================
// Name        : stack.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <initializer_list>
using namespace std;
#include "stack.h"

// Copy constructor
stack::stack(const stack& stk) :
		values(new int[stk.array_capacity]),
		stack_size(stk.stack_size),
		array_capacity(stk.array_capacity)
{
	size_t i;
	for (i = 0; i < stack_size; i++) {
		values[i] = stk.values[i];
	}
}

// Initializer list constructor
stack::stack(std::initializer_list<int> ilist) :
		values(new int[ilist.size()]),
		stack_size(ilist.size()),
		array_capacity(ilist.size())
{
	size_t i = 0;
	for (int val : ilist) {
		values[i] = val;
		i++;
	}
}

// Copy assignment
stack& stack::operator=(const stack& stk) {
	if (this == &stk)
		return *this;

	size_t i;

	stack_size = stk.stack_size;
	array_capacity = stk.array_capacity;

	delete[] values;
	values = new int[array_capacity];

	for (i = 0; i < stack_size; i++) {
		values[i] = stk.values[i];
	}

	return *this;
}

// Insert an item at the top of the stack
void stack::push(int val) {

	if (stack_size < array_capacity) {
		values[stack_size] = val;
		stack_size++;
	} else {
		size_t i;
		array_capacity *= 2;
		int* new_values = new int[array_capacity];
		for (i = 0; i < stack_size; i++) {
			new_values[i] = values[i];
		}
		delete[] values;
		values = new_values;

		values[stack_size] = val;
		stack_size++;
	}
}

// Returns the value of the topmost item of the stack;
// throws an exception if the stack is empty
int stack::peek() const {
	if (stack_size == 0) {
		throw std::invalid_argument("\nThe stack is empty\n");
	} else {
		return values[stack_size - 1];
	}
}

// Remove the topmost item from the stack
// throws an exception if the stack is empty
void stack::pop() {
	if (stack_size == 0) {
		throw std::invalid_argument("\nThe stack is empty\n");
	} else {
		stack_size--;
	}
}

// Remove everything from the stack
void stack::clear() {
	stack_size = 0;
}

// Returns the number of items on the stack
size_t stack::size() const {
	return stack_size;
}

// Returns whether or not the stack is currently empty
bool stack::empty() const {
	return (!stack_size);
}

// Destructor
stack::~stack() {
	delete[] values;
}

