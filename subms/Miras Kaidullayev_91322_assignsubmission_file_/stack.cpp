#include <iostream>
#include "stack.h"
#include <stdexcept>

stack::stack(const stack& stk) :
	values(new int[stk.array_capacity]),
	stack_size(stk.stack_size),
	array_capacity(stk.array_capacity)
{
	for (size_t i = 0; i < stack_size; i++)
	{
		values[i] = stk.values[i];
	}
}

stack::stack(std::initializer_list<int> ilist) :
	values(new int[2 * ilist.size()]),
	stack_size(ilist.size()),
	array_capacity(2 * ilist.size())
{
	size_t i = 0;
	for (int val : ilist)
	{
		values[i] = val;
		++i;
	}
}

stack& stack::operator=(const stack& stk)
{
	if (this->array_capacity < stk.stack_size)
	{
		delete[] this;
		values = new int[stk.array_capacity];
	}

	stack_size = stk.stack_size;
	array_capacity = stk.array_capacity;

	for (size_t i = 0; i < stack_size; i++)
	{
		values[i] = stk.values[i];
	}

	return *this;
}

void stack::push(int val)
{
	if (stack_size == array_capacity)
	{
		array_capacity *= 2;
		int* a = new int[array_capacity];
		for (size_t i = 0; i < stack_size; i++)
			a[i] = values[i];
		delete[] values;
		values = a;
	}
	values[stack_size] = val;
	++stack_size;
}

int stack::peek() const
{
	if (empty())
		throw std::invalid_argument("Stack is currently empty");
	return values[stack_size - 1];
}

void stack::pop()
{
	if (empty())
		throw std::invalid_argument("Stack is currently empty");
	stack_size--;
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
	return (stack_size == 0);
}

stack::~stack()
{
	delete[] values;
}