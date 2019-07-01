#include <iostream>
#include <stdexcept>
#include "stack.h"

	stack::stack(const stack& stk):
		stack_size(stk.stack_size),
		array_capacity(stk.array_capacity),
		values(new int[stk.array_capacity])
	{

		for(size_t i = 0; i < stk.stack_size; ++i) {
			values[i] = stk.values[i];
		}

	}

	stack::stack(std::initializer_list<int> ilist):
		values(new int[ilist.size()]),
		array_capacity(ilist.size()),
		stack_size(ilist.size())
	{

		int index = 0;
		for (int ilist_value : ilist) {
			values[index] = ilist_value;
			++index;
		}

	}

	stack& stack::operator=(const stack& stk) {

		if (this != &stk) {
			delete[] values;
			int new_capacity = stk.array_capacity;
			values = new int[new_capacity];
			for (size_t i = 0; i < stk.stack_size; ++i){
				values[i] = stk.values[i];
			}
			array_capacity = new_capacity;
			stack_size = stk.stack_size;
		} else {
			for (size_t i = 0; i < stk.stack_size; ++i){
				values[i] = stk.values[i];
			}
			stack_size = stk.stack_size;
			array_capacity = stk.array_capacity;
		}
			
		return *this;

	}

	void stack::push(int val) {

		if(stack_size == array_capacity) {
			int new_capacity = 2*array_capacity;
			int* new_arr = new int[new_capacity];
			for (size_t i = 0; i < stack_size; ++i) {
				new_arr[i] = values[i];
			}
			delete[] values;
			values = new_arr;
			array_capacity = new_capacity;
			values[stack_size] = val;
		} else {
			values[stack_size] = val;
		}

		++stack_size;

	}

	int stack::peek() const {

		if (stack_size == 0){
			throw std::invalid_argument("There is no peek, because stack is empty\n");
		} else {
			int peek_index = stack_size - 1;
			return values[peek_index];
		}

	}

	void stack::pop() {

		if (stack_size == 0){
			throw std::invalid_argument("Stack is empty. So, you can't pop!\n");
		} else {
			stack_size--;
		}

	}

	void stack::clear() {

		stack_size = 0;

	}

	size_t stack::size() const {

		size_t return_size = stack_size;
		return return_size;

	}

	bool stack::empty() const {

		if (stack_size == 0){
			return true;
		} else {
			return false;
		}

	}

	stack::~stack() {

		delete[] values;

	}