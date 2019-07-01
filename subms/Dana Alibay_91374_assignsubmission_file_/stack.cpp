#include <iostream>
#include<stdexcept>
#include "stack.h"
#include <initializer_list>

	// Copy constructor
stack::stack(const stack& stk):
	values(new int[stk.array_capacity]),
	stack_size(stk.stack_size),
	array_capacity(stk.array_capacity)
{
	for(size_t i=0;i<stk.stack_size;++i){
		values[i]=stk.values[i];
	}
}

	// Initializer list constructor
stack::stack(std::initializer_list<int> ilist){
	stack_size=ilist.size();
	array_capacity=stack_size*2;
	values=new int[array_capacity];
	size_t i=0;
	for(int val: ilist){
		values[i]=val;
		i++;
	}
}

	// Copy assignment
stack& stack::operator=(const stack& stk)
{
	if(array_capacity!=stk.array_capacity){
		delete[] values;
		values=new int[stk.array_capacity];
		stack_size=stk.stack_size;
		array_capacity=stk.array_capacity;
		for(size_t i=0;i<stk.stack_size;++i){
			values[i]=stk.values[i];
		}
	}
	if(this == &stk){      // self assignment-- need to checkk!!
		return *this;
	}

	for(size_t i=0;i<stk.stack_size;++i){
		values[i]=stk.values[i];
	}
	return *this;
}


void stack::push(int val){
	if(stack_size>=array_capacity){
		array_capacity=array_capacity*2;
		int* new_values=new int[array_capacity];
		for(size_t i=0;i<stack_size;++i){
			new_values[i]=values[i];
		}
		delete[] values;
		values=new_values;
	}
	values[stack_size]=val;
	stack_size++;
}

	
int stack::peek() const{
	if(empty()){ //check if it's right 
		throw std::invalid_argument("stack is empty, nothing to peek!!");
	}
	return values[stack_size-1];
}


void stack::pop(){
	if(empty()){ //check if it's right
		throw std::invalid_argument("stack is empty, nothing to pop!!");
	}
	stack_size--;
}

void stack::clear(){
	stack_size=0;
}


size_t stack::size() const{
	return stack_size;
}

bool stack::empty() const{
	if(stack_size==0){
		return true;
	}
	return false;
}


stack::~stack(){
	delete[] values;
}
