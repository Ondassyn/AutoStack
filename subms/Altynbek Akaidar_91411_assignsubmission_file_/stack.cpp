#include <iostream>
#include <stdexcept> 
#include "stack.h" 

	// Copy constructor 
	stack::stack(const stack& stk) { 
		values = new int[stk.array_capacity]; 
		stack_size = stk.stack_size; 
		array_capacity = stk.array_capacity; 
		size_t i = 0;
		for (i = 0; i < stk.stack_size; i++) {
			values[i] = stk.values[i]; 
		}
	}	 

	// Initializer list constructor 
	stack::stack(std::initializer_list<int> ilist):stack() {
		stack_size = ilist.size(); 
		if(array_capacity > stack_size){ 
			int j = 0; 
			for(int init : ilist) {
				values[j] = init; 
				j++;
			}
		} else {
			array_capacity = stack_size; 
			int j = 0; 
			for (int init: ilist) {
				values[j] = init;
				j++; 
			} 
		} 
	}	 

	// Copy assignment 
	stack& stack::operator=(const stack& stk) { 
		stack_size=stk.stack_size; 
		array_capacity=stk.array_capacity; 
		values = new int[stk.array_capacity]; 
		size_t i=0;
		for (i=0;i<stk.stack_size;i++) {
			values[i]=stk.values[i];
		}
	} 

	// Insert an item at the top of the stack 
	void stack::push(int val) { 
		if(array_capacity==stack_size) {
			array_capacity = array_capacity * 2; 
		}
		values[stack_size] = val; 
		stack_size=stack_size+1; 
	} 
		
	// Returns the value of the topmost item of the stack; 
	// throws an exception if the stack is empty 
	int stack::peek() const { 
		if(stack_size==0) {
			throw std::out_of_range("stack is empty");
		}
		return values[stack_size-1]; 
	} 

	// Remove the topmost item from the stack 
	// throws an exception if the stack is empty 
	void stack::pop() { 
		if(stack_size==0) { 
			throw std::out_of_range("stack is empty");
		}
		stack_size=stack_size-1; 
	} 

	// Remove everything from the stack 
	void stack::clear() { 
		stack_size=0; 
	} 

	// Returns the number of items on the stack 
	size_t stack::size() const { 
		return stack_size; 
	} 

	// Returns whether or not the stack is currently empty 
	bool stack::empty() const { 
		return(stack_size == 0); 
	} 

	// Destructor 
	stack::~stack() { 
		delete[] values; 
	}
