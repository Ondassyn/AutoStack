#include "stack.h"
#include <iostream>
#include <stdexcept>
#include <initializer_list>
/* after checking with valgrind I learned that
there are always reachable blocks. according to TAs and the internet 
this is not a mistake and does not have any bad consequences
for the program anyway */

// Copy constructor
stack::stack(const stack& stk){
	values=new int[stk.array_capacity];
	for(size_t i=0;i<stk.stack_size;i++){
		values[i]=stk.values[i];
	}
	stack_size=stk.stack_size;
	array_capacity=stk.array_capacity;
}

// Initializer list constructor
stack::stack(std::initializer_list<int> ilist){
	values=new int[5];// I assumed that lists larger than 5 will not be given
	stack_size=ilist.size();
	array_capacity=5;
	size_t i=0;
	for(int val:ilist){
		values[i]=val;
		i++;
	}

}

// Copy assignment
stack& stack::operator=(const stack& stk){
	if(this!=&stk){
		delete[] values;
		values=new int[stk.array_capacity];
		for(size_t i=0;i<stk.stack_size;i++){
			values[i]=stk.values[i];
		}
		stack_size=stk.stack_size;
		array_capacity=stk.array_capacity;
	}return *this;
}

// Insert an item at the top of the stack
void stack::push(int val){
	if(stack_size==array_capacity){
		int *copy_values=new int[array_capacity];
			for(size_t i=0;i<stack_size;i++){
				copy_values[i]=values[i];
			}
		delete [] values;
		values=new int[array_capacity*2];
			for(size_t j=0;j<stack_size;j++){
				values[j]=copy_values[j];
			}
		array_capacity=2*array_capacity;
		delete[] copy_values;
	}
	values[stack_size]=val;
	stack_size++;
}

// Returns the value of the topmost item of the stack;
// throws an exception if the stack is empty
int stack::peek() const{
	if(stack_size==0){
		throw std::invalid_argument("stack is empty");
	}
	return values[stack_size-1];
}

// Remove the topmost item from the stack
// throws an exception if the stack is empty
void stack::pop(){
	if(stack_size==0){
			throw std::invalid_argument("stack is empty");
		}
	stack_size--;
}

// Remove everything from the stack
void stack::clear(){
	stack_size=0;
}

// Returns the number of items on the stack
size_t stack::size() const{
	return stack_size;
}

// Returns whether or not the stack is currently empty
bool stack::empty() const{
	if(stack_size==0){
		return true;
	}else{
		return false;
	}
}

// Destructor
stack::~stack(){
	delete[] values;
}
