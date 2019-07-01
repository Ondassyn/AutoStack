#include <iostream>
#include <stdexcept>
#include "stack.h"

	stack::stack(const stack& stk):
		values(new int[stk.array_capacity]),
		stack_size(stk.stack_size),
		array_capacity(stk.array_capacity)
	{

		for(size_t i = 0; i < stk.stack_size; ++i) {
			values[i] = stk.values[i];
		}

	}

	stack::stack(std::initializer_list<int> ilist):
		stack_size(ilist.size()),
		array_capacity(ilist.size()),
		values(new int[ilist.size()])

	{

		size_t i = 0;
		for (int val : ilist) {
			values[i] = val;
			++i;
		}

	}

	stack& stack::operator=(const stack& stk) {

		if(this != &stk){

			delete[] values;
			values = new int[stk.array_capacity];

		}

		stack_size = stk.stack_size;
		array_capacity = stk.array_capacity;

		for (size_t i = 0; i < stk.stack_size; ++i){
			values[i] = stk.values[i];
		}

		return *this;

	}

	void stack::push(int val) {

		if(stack_size == array_capacity) {
			int* new_values = new int[array_capacity*2];
			
			for (size_t i = 0; i < stack_size; ++i) {
				new_values[i] = values[i];
			}

			delete[] values;
			values = new_values;
			array_capacity = array_capacity*2;
		}

		values[stack_size] = val;
		++stack_size;

	}

	int stack::peek() const {

		if (stack_size == 0){
			throw std::invalid_argument("Stack is empty!");
			// std::cout<<"Stack is empty! Therefore, there is nothing to peek!\n";
		} else {
			return values[stack_size - 1];
		}

	}

	void stack::pop() {

		if (stack_size == 0){
			throw std::invalid_argument("Cannot pop from empty stack!");
			// std::cout<<"Cannot pop from empty stack!\n";
		} else {
			stack_size--;
		}

	}

	void stack::clear() {

		stack_size = 0;

	}

	size_t stack::size() const {

		return stack_size;

	}

	bool stack::empty() const {

		return stack_size == 0;

	}

	stack::~stack() {

		delete[] values;

	}