//Madiyar Yergali
#include "stack.h"
#include <iostream>

//stack::stack():
        //values(new int[5]),
	//	stack_size(0),
		//array_capacity(5)
//{}

stack::stack(const stack& stk){
	values = new int[stk.array_capacity];
	stack_size = stk.stack_size;
	array_capacity = stk.array_capacity;
	for(size_t a = 0; a < stack_size; a++){
		values[a] = stk.values[a];
	}
}

stack::stack(std::initializer_list<int> ilist):
	stack_size(ilist.size())
{
		size_t a = 0;
		for(size_t val : ilist){
			values[a] = val;
			a++;
		}
}


stack&stack:: operator=(const stack& stk){
	values = new int[stk.array_capacity];
	stack_size = stk.stack_size;
	for(size_t a = 0; a < stack_size; a++){
		values[a] = stk.values[a];
	}
	array_capacity = stk.array_capacity;
	return *this;
}

void stack:: push (int val){
	if(stack_size == 5){
		stack new_stack;
		new_stack.array_capacity = array_capacity*2;
		new_stack.values = new int[array_capacity];
		for(size_t a = 0; a < stack_size; a++){
				new_stack.values[a] = values[a];
			}
		array_capacity = new_stack.array_capacity;
		for(size_t a = 0; a < stack_size; a++){
				values[a] = new_stack.values[a];
		}
	}
	values[stack_size] = val;
	stack_size++;
}

int stack::peek()const{
	return values[stack_size-1];
}

void stack::pop(){
	if(stack_size==0){
		throw std::invalid_argument("Empty stack\n");
	}
	else {stack_size--;}
}

void stack::clear(){
	stack_size = 0;
}

size_t stack::size() const{
	return stack_size;
}

bool stack:: empty() const {
	return (stack_size == 0);
}


stack::~stack(){delete[] values;
}









