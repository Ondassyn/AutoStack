#include <iostream>

#include "stack.h"

stack::stack(const stack& stk)
{
	stack_size = stk.stack_size;
	array_capacity = stk.array_capacity;
	values = new int[stk.array_capacity];
	for (size_t i = 0; i < stack_size; ++i) {
		values[i] = stk.values[i];
	}
}

	// Initializer list constructor
stack::stack(std::initializer_list<int> ilist)
	: values(new int[array_capacity]),
	  stack_size(ilist.size()),
	  array_capacity((ilist.size() * 2))
		{
			size_t i = 0;
			for (int d: ilist) {
				values[i] = d;
				++i;
			}
		}

	// Copy assignment
	stack& stack::operator=(const stack& stk) {
		if (stack_size != stk.stack_size)	{
			delete[] values;
			values = new int[array_capacity];
		}
		stack_size = stk.stack_size;
		for (size_t i = 0; i < stack_size; ++i) {
			values[i] = stk.values[i];
		}
		return *this;
	}

	// Insert an item at the top of the stack
	void stack::push(int val) {
		stack_size += 1;
		if (array_capacity < stack_size) {
			if (stack_size < 2 * array_capacity) {
				array_capacity = 2 * array_capacity;
			}
			int* newdata = new int[array_capacity];
			for (size_t i = 0; i < stack_size; ++i) {
				newdata[i] = values[i];
			}
			delete[] values;
			values = newdata;
		}
		values[stack_size - 1] = val;
	}

	// Returns the value of the topmost item of the stack;
	// throws an exception if the stack is empty
	int stack::peek() const {
		return values[stack_size - 1];
	}

	// Remove the topmost item from the stack
	// throws an exception if the stack is empty
	void stack::pop() {
		stack_size -= 1;
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
		if (stack_size == 0) {
			return 1;
		}
		else return 0;
	}

	// Print out the contents of the stack


	// Destructor
	stack::~stack() {
		delete[] values;
	}
