#include <iostream>
#include "stack.h"

using namespace std;
// Did not include Default constructor and Print function as they are in .h file already.
// Copy constructor
	stack::stack(const stack& stk):
		values(new int[stk.array_capacity]),
		stack_size(stk.stack_size),
		array_capacity(stk.array_capacity)
		{
			for (size_t i=0; i < stk.stack_size; i++ ) {
				values[i] = stk.values[i];
			}
			std::cout << "copy constructor\n";
		}

	// Initializer list constructor
	stack::stack(std::initializer_list<int> ilist):
		stack_size(ilist.size()),
		array_capacity(ilist.size()),
		values(new int[ilist.size()])
		{
			size_t i = 0;
			for (int val : ilist) {
				values[i] = val;
				i++;
			}
			std::cout << "Initializer\n";
		}

	// Copy assignment
	stack& stack::operator=(const stack& stk){
		std::cout << "assignment->";
		if (this == &stk) {
			std::cout << "self assignment\n";
			return *this;
		}
		if (this->stack_size == stk.stack_size && this->array_capacity == stk.array_capacity) {
			std::cout << "equal size assignment\n";
			for (size_t i=0; i < this->stack_size; i++) {
				this->values[i] = stk.values[i];
			}
			return *this;
		}
		std::cout << "simple assignment\n";
		delete [] values;
		values = new int[stk.array_capacity];
		stack_size = stk.stack_size;
		array_capacity = stk.array_capacity;
		for (size_t i=0; i < stk.stack_size; i++) {
			values[i] = stk.values[i];
		}
		return *this;
	}

	// Insert an item at the top of the stack
	void stack::push(int val){
		if (stack_size == array_capacity){
			int *new_values;
			new_values = new int[array_capacity*2];
			for (size_t i=0; i < stack_size; i++) {
				new_values[i] = values [i];
			}
			delete [] values;
			values = new_values;
			values[stack_size] = val;
			stack_size++;
			array_capacity = array_capacity*2;			
		} else {
			values[stack_size] = val;
			stack_size++;
		}

	}

	// Returns the value of the topmost item of the stack;
	// throws an exception if the stack is empty
	int stack::peek() const{
		if (stack_size == 0) {
			throw invalid_argument("Stack is empty! Sorry, there is no peek");
		}
		return values[stack_size - 1];
	}
	// Remove the topmost item from the stack
	// throws an exception if the stack is empty
	void stack::pop(){
		if (stack_size == 0) {
			throw invalid_argument("Stack is empty! Sorry, you can not pop\n");
		}
		stack_size--;
	}

	// Remove everything from the stack
	void stack::clear(){
		stack_size = 0;
	}

	// Returns the number of items on the stack
	size_t stack::size() const{
		return stack_size;
	}

	// Returns whether or not the stack is currently empty
	bool stack::empty() const{
		return (stack_size == 0);
	}

	// Destructor
	stack::~stack(){
		std::cout << "destructor\n";
		delete [] values;
	}