/*
 * stack.cpp
 *
 *  Created on: Jun 24, 2019
 *      Author: zhamilya
 */
#include<ostream>
#include<iostream>
#include "stack.h"
#include<stdexcept>


// Copy constructor
stack::stack(const stack& stk):
				values(new int[stk.array_capacity]),
				stack_size(stk.stack_size),
				array_capacity(stk.array_capacity)
{
	for(size_t i = 0; i < stk.stack_size; i++){
		values[i] = stk.values[i];
	}
}

// Initializer list constructor
stack::stack(std::initializer_list<int> ilist):
				stack_size(ilist.size()),
				array_capacity(ilist.size()),
				values(new int[ilist.size()])
{

	size_t i = 0;
	for (int val: ilist){
		values[i] = val;
		i++;
	}
}

// Copy assignment
stack& stack::operator=(const stack& stk){
	stack_size = stk.stack_size;
	array_capacity = stk.array_capacity;
	delete [] values;
	values = new int[stk.array_capacity];
	for(size_t i = 0; i < stk.stack_size; i++){
		values[i] = stk.values[i];
	}
	return *this;
}

// Insert an item at the top of the stack
void stack::push(int val){
	if(array_capacity == stack_size){
		int *nvalues = new int[stack_size*2];
		size_t i = 0;
		while(i < array_capacity){
			nvalues[i] = values[i];
			i++;
		}
		delete [] values;
		values = nvalues;
		array_capacity *= 2;
	}
	values[stack_size] = val;
	stack_size++;
}

// Returns the value of the topmost item of the stack;
// throws an exception if the stack is empty
int stack::peek() const{
	if(stack_size == 0){
		throw std::invalid_argument("ERROR!!!");
	}
	return values[stack_size - 1];
}

// Remove the topmost item from the stack
// throws an exception if the stack is empty
void stack::pop(){
	if(stack_size == 0){
		throw std::invalid_argument("ERROR!!!");
}
	stack_size--;
}

// Remove everything from the stack
void stack::clear(){
	if(stack_size == 0){
		throw std::invalid_argument("ERROR!!!");
	}
	stack_size = 0;
}


// Returns the number of items on the stack
size_t stack::size() const{
	return stack_size;
}


// Returns whether or not the stack is currently empty
bool stack::empty() const{
	return (stack_size == 0);
}
// Destructor
stack::~stack(){
	delete [] values;
}
