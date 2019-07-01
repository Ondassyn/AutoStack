#include "stack.h"
#include <stdexcept>
#include <ostream>
	stack::stack(const stack& stk):
	values(new int[stk.stack_size]),
	stack_size(stk.stack_size),
	array_capacity(stk.array_capacity)
	{
		for(size_t i=0; i<stack_size; i++)
			values[i]=stk.values[i];
	}
	stack::stack(std::initializer_list<int> ilist):
		values(new int[ilist.size()]),
		stack_size(ilist.size()),
		array_capacity(ilist.size())
		{
		size_t i = 0;
		for (int val : ilist){
		values[i] = val;
		i++;
	}
	}
	stack& stack::operator=(const stack& stk){
		if(array_capacity!=stk.array_capacity)
		{
			delete[] values;
			values=new int[array_capacity];
		}
		array_capacity = stk.array_capacity;
		stack_size = stk.stack_size;
		for(size_t i=0; i<array_capacity; i++)
			values[i]=stk.values[i];
		return *this;
	}
	void stack::push(int val){
		if(stack_size==array_capacity)
		{
			int *value1 = new int[array_capacity*2];
			array_capacity = array_capacity * 2;
			for(size_t i = 0; i < stack_size; i++)
			{
				value1[i] = values[i];
			}
			delete[] values;
			values = value1;
		}
		values[stack_size]=val;
		stack_size++;
	}
	int stack::peek() const{
		if(stack_size==0)
			throw std::invalid_argument("Your stack is empty");
	else
		return values[stack_size-1];
	}

	void stack::pop(){
		if(stack_size==0)
			throw std::invalid_argument("Your stack is empty");
			else
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