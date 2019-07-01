#include <iostream>
#include <stdexcept>

#include "stack.h"

stack::stack(
	const stack& stk
):
	values(stk.values),
	stack_size(stk.stack_size),
	array_capacity(stk.array_capacity)
{
};

stack::stack(
	std::initializer_list<int> ilist
)
{
	stack_size=(size_t)ilist.size();
	array_capacity=(size_t)ilist.size();
	values = new int[array_capacity];
	const int *first=ilist.begin();
	const int *end=ilist.end();
	int i=0;
	while(first!=end){
		values[i]=*first;
		first+=1;
		i+=1;
	}
};

stack& stack::operator=(const stack& stk){
	values=stk.values;
	stack_size=stk.stack_size;
	array_capacity=stk.array_capacity;
	return *this;
};

void stack::push(int val){
	if (array_capacity == stack_size){
		int* new_values = new int[2*array_capacity];
		for(int i = 0; i < stack_size; i++){
			new_values[i]=values[i];
		}
		delete[] values;
		values=new_values;
		array_capacity*=2;
	}

	values[stack_size] = val;
	stack_size+=1;
};

int stack::peek() const{
	if( stack_size == 0){
		throw std::invalid_argument("Stack is empty");
	} else {
		return values[stack_size-1];
	}
};

void stack::pop(){
	if (stack_size == 0){
		throw std::invalid_argument("Stack is empty");
	} else {
		stack_size-=1;
	}
};

void stack::clear(){
	stack_size=0;
};

size_t stack::size() const{
	return stack_size;
};

bool stack::empty() const{
	return stack_size == 0;
};

stack::~stack(){
	delete[] values;
};
