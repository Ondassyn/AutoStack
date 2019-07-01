#include "stack.h"
#include <iostream>

stack::stack(const stack& stk):
	values(new int[stk.stack_size]),
	stack_size(stk.stack_size),
	array_capacity(stk.array_capacity)
{
	for (size_t i = 0; i < stack_size; ++i)
		values[i] = stk.values[i];
}

stack::stack(std::initializer_list<int> ilist):
	values(new int[ilist.size()]),
	stack_size(ilist.size()),
	array_capacity(ilist.size())
{
	values = new int[ilist.size()];
	size_t i = 0;
	for (int val : ilist)
	{
		if (val == 0)
			break;
		values[i] = val;
		i++;
	}
}

stack& stack::operator=(const stack& stk)
{
	delete[] values;
	values = new int[stk.stack_size];
	stack_size = stk.stack_size;
	array_capacity = stk.array_capacity;
	for (size_t i = 0; i < stack_size; ++i)
		values[i] = stk.values[i];
	return *this;
}

void stack::push(int val)
{
	++stack_size;
	values[stack_size - 1] = val;
}

int stack::peek() const
{
    if(stack_size == 0) {
        throw "Empty stack!";
    }
    return values[stack_size - 1];
}

void stack::pop()
{
    if(stack_size == 0) {
        throw "Empty Stack!";
    }
    else {
        --stack_size;
    }
}

void stack::clear()
{
	stack_size = 0;
}

size_t stack::size() const
{
	return stack_size;
}

bool stack::empty() const
{
	if (stack_size == 0)
		return true;
	return false;
}

stack::~stack()
{
	delete[] values;
}
