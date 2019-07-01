//============================================================================
// Name        : stack.cpp
// Author      : Aisulu Akmaliyeva
// Description : Assignment 3
//============================================================================

#include <iostream>
#include "stack.h"

using namespace std;

stack::stack(const stack& stk):
		values(new int[stk.array_capacity]),
		stack_size(stk.stack_size),
		array_capacity(stk.array_capacity)
	{
		size_t i=0;
		do
		{
			values[i]=stk.values[i];
			i=i+1;
		}while(i<stk.stack_size);
	}

stack::stack(std::initializer_list<int> ilist):
		values(new int[ilist.size()]),
		stack_size(ilist.size()),
		array_capacity(ilist.size())
	{
		size_t i=0;
		for(int val : ilist)
		{
			values[i] = val;
			++i;
		}
	}

stack& stack::operator=(const stack& stk){
	if (this == &stk)
		{
			return *this;
		}

	delete[] values;
	values=new int[stk.array_capacity];
	stack_size=stk.stack_size;
	array_capacity=stk.array_capacity;
	{
		size_t i=0;
		do
		{
			values[i]=stk.values[i];
			i=i+1;
		}while(i<stk.stack_size);
	}
	return *this;
}

void stack::push(int val){
	if(stack_size==array_capacity)
		{
			int *tmpArr = new int[2*array_capacity];
			size_t i=0;
			do
			{
				tmpArr[i]=values[i];
				i=i+1;
			}while(i<stack_size);

			delete[] values;
			values=tmpArr;
			array_capacity = 2*array_capacity;
		}
	values[stack_size++]=val;

}

int stack::peek() const{
	if (stack_size<=0)
		{
			throw std::invalid_argument("The stack is empty!");
		}
	return values[stack_size-1];
}

void stack::pop(){
	if (stack_size<=0)
		{
			throw std::invalid_argument("The stack is empty!");
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
	return (stack_size==0);
}

stack::~stack(){
	delete[] values;
}
