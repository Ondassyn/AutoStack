#include "stack.h"

// Copy constructor
stack::stack(const stack& stk){
	stack_size = stk.stack_size;
	array_capacity = stk.array_capacity;	
	values = new int[array_capacity];
	for(size_t i = 0; i < stack_size; i++){
		values[i] = stk.values[i];
	}
}

// Initializer list constructor
stack::stack(std::initializer_list<int> ilist){
	stack_size = ilist.size();
	array_capacity = stack_size;
	values = new int[array_capacity];
	size_t i = 0;	
	for(int x: ilist){
		values[i] = x;
		i++;
	}
}

// Copy assignment
stack& stack::operator=(const stack& stk){
	if(array_capacity < stk.stack_size){
		while(array_capacity < stk.stack_size)
			array_capacity *= 2;
		delete [] values;
		values = new int[array_capacity];
	}
	for(size_t i = 0; i < stk.stack_size; i++)
		values[i] = stk.values[i];
	stack_size = stk.stack_size;
	return *this;
}

// Insert an item at the top of the stack
void stack::push(int val){
	if(stack_size == array_capacity){
		array_capacity *= 2;
		int *newvalues = new int[array_capacity];
		for(size_t i = 0; i < stack_size; i++){
			newvalues[i] = values[i];
		}
		delete [] values;
		values = newvalues;
	}
	values[stack_size++] = val;
}

// Returns the value of the topmost item of the stack;
// throws an exception if the stack is empty
int stack::peek() const {
	if(empty())
		throw std::runtime_error("Stack is empty!\n");
	return values[stack_size-1];
}

// Remove the topmost item from the stack
// throws an exception if the stack is empty
void stack::pop(){
	if(empty())
		throw std::runtime_error("Stack is empty!\n");
	stack_size--;
}

// Remove everything from the stack
void stack::clear(){
	stack_size = 0;
}

// Returns the number of items on the stack
size_t stack::size() const{
	return stack_size;
}

// Returns whether or not the stack is currently empty
bool stack::empty() const {
	return stack_size == 0;
}

// Destructor
stack::~stack() {
	delete[] values;
}


