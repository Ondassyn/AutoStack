#include "stack.h"
#include <stdexcept>

stack::stack(const stack & stk)
{
	stack_size = stk.stack_size;
	array_capacity = stk.array_capacity;
	values = new int[stk.array_capacity];
	for (int q = 0; q < stk.stack_size; q++) {
		values[q] = stk.values[q];
	}
}

stack::stack(std::initializer_list<int> ilist)
{
	stack_size = ilist.size();
	array_capacity = ilist.size();;
	values = new int[ilist.size()];
	int a = 0;
	for (int val : ilist) {
		values[a] = val;
		a++;
	}
}

stack & stack::operator=(const stack & stk)
{
	// TODO: insert return statement here
	if (stk.stack_size > array_capacity) {
		delete[] values;
		values = new int[5];
	}
	for (int q = 0; q < stk.stack_size; q++) {
		values[q] = stk.values[q];
	}
	stack_size = stk.stack_size;
	array_capacity = stk.array_capacity;
	return *this;
}

void stack::push(int val)
{
	if (stack_size == array_capacity)
	{
		array_capacity = array_capacity * 2;
		int *t = new int[array_capacity];
		for (size_t it = 0; it < stack_size; it++)
			t[it] = values[it];
		delete[] values;
		values = t;
	}
	values[stack_size] = val;
	stack_size++;
}

int stack::peek() const
{
	if (size() > 0)
		return values[size() - 1];
	throw std::invalid_argument("stack is empty");
}

void stack::pop()
{
	if (size() == 0)
		throw std::invalid_argument("stack is empty");
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
	if (stack_size == 0)
		return true;
	return false;
}

stack::~stack()
{
	delete[] values;
}