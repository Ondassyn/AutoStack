#include <ostream>
#include <stdexcept>
#include "stack.h"

stack::stack(const stack& stk):
	values(new int[stk.stack_size]),
	stack_size(stk.stack_size),
	array_capacity(stk.array_capacity)
{
	for(size_t i = 0; i < stk.stack_size; i++) {
		values[i] = stk.values[i];
	}
}

stack::stack(std::initializer_list<int> ilist):
	values(new int[ilist.size()]),
	stack_size(ilist.size()),
	array_capacity(ilist.size())
{
	size_t i = 0;
	for(int val : ilist) {
		values[i] = val;
		i++;
	}
}

stack& stack::operator=(const stack& stk) {
	if(stack_size != stk.stack_size) {
		stack_size = stk.stack_size;
		delete[] values;
		values = new int[stack_size];
	}

	array_capacity = stk.array_capacity;

	for(size_t i = 0; i < stk.stack_size; i++) {
		values[i] = stk.values[i];
	}

	return *this;
}

void stack::push(int val) {
	if(stack_size == array_capacity) {
		size_t temp_cap = array_capacity * 2;
		int* temp = new int[temp_cap];
		for(int x = 0; x < stack_size; x++) {
			temp[x] = values[x];
		}
		array_capacity = temp_cap;
		delete[] values;
		values = temp;
	}
	values[stack_size] = val;
	stack_size++;
}

int stack::peek() const {
	if(stack_size != 0) {
		return values[stack_size];
	} else {
		throw std::invalid_argument("Stack is empty!");
	}
}

void stack::pop() {
	if(stack_size != 0) {
		stack_size--;
	} else {
		throw std::invalid_argument("Stack is empty!");
	}
}

void stack::clear() {
	stack_size = 0;
}

size_t stack::size() const {
	return stack_size;
}

bool stack::empty() const {
	return (stack_size == 0);
}

stack::~stack() {
	delete[] values;
}




