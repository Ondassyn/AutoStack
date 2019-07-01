// stack.cpp :
//
//Meirzhan Altynbekov

#include <iostream>
#include <string>
#include <cstdlib>
#include "stack.h"

//copy constructor
stack::stack(const stack& stk)
	:values(new int[stk.array_capacity]),
	stack_size(stk.stack_size),
	array_capacity(stk.array_capacity)
{
	for (unsigned int i = 0; i < stk.stack_size; i++) {
		values[i] = stk.values[i];
	}
}

//initializer list constructor
stack::stack(std::initializer_list<int> ilist)
{
	stack_size = ilist.size(); //how do they know the name of a variable in ilist?
	array_capacity = stack_size * 2;
	values = new int[array_capacity];

	size_t i = 0;
	for (int val : ilist) { //wtf weird syntax 'val: ilist', why it doesn't need iterating variable? 
		values[i] = val;
		++i;
	}
}

//copy assignment
stack& stack:: operator=(const stack& stk) {
	if (this == &stk) { //why would we need to allocate object to itself
		return *this;
	}

	if (array_capacity != stk.array_capacity) {
		delete[] values;
		stack_size = stk.stack_size;
		array_capacity = stk.array_capacity;
		values = new int[stk.array_capacity];

		for (size_t i = 0; i < stack_size; i++) {
			values[i] = stk.values[i];
		}
		return *this;
	}
	else {
		for (size_t i = 0; i < stack_size; i++) {
			values[i] = stk.values[i];
		}
		return *this;
	}
}

//insert an item at the top of the stack 
void stack::push(int val) {
	if (stack_size == array_capacity) {
		array_capacity = array_capacity * 2;
		int* new_values;
		new_values = new int[array_capacity];

		for (size_t i = 0; i < stack_size; ++i) {
			new_values[i] = values[i];
		}
		new_values[stack_size] = val;
		++stack_size;

		delete[] values;
		values = new_values;
	}
	else {
		values[stack_size] = val;
		stack_size++;
	}
}

//return top item of stack. exception if stack empty
int stack::peek() const {
	if (stack_size == 0) {
		throw std::invalid_argument("THE STACK IS EMPTY");
	}
	return values[stack_size - 1];
}

//remove top item of stack. exception if stack empty
void stack::pop() {
	if (stack_size == 0) {
		throw std::invalid_argument ("THE STACK IS EMPTY");
	}
	stack_size--;
}

//remove all in stack 
void stack::clear() {
	stack_size = 0;
}

//return number of items in stack
size_t stack::size() const {
	return stack_size;
}

//return whether stack is empty
bool stack::empty() const {
	return stack_size == 0;
}

//destructor 
stack::~stack() {
	delete[] values;
}
