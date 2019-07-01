#include <stdexcept>
#include <ostream>
#include "stack.h"
// Creates an empty stack


	// Copy constructor
	stack::stack(const stack& stk):
		values(new int[stk.array_capacity]),
		stack_size(stk.stack_size),
		array_capacity(stk.array_capacity)
	{
		for(size_t i=0; i != stk.stack_size; ++i){
			values[i] = stk.values[i];
		}
	}

	// Initializer list constructor
	stack::stack(std::initializer_list<int> ilist):
  values(new int[ilist.size()]),
			stack_size(0),
      array_capacity(ilist.size())
	{
		size_t i = 0;

		for (int val : ilist){
			values[i] = val;
			++i;
      stack_size++;
		}
	}
	// Copy assignment
stack&	stack:: operator=(const stack& stk) {
        if (stack_size!=stk.stack_size){
            delete[] values;
            stack_size = stk.stack_size;
            array_capacity = stk.array_capacity;
            values = new int[stk.array_capacity];
            for(size_t i=0; i != stk.stack_size; ++i){
                values[i] = stk.values[i];
            }
        }
        else {
            array_capacity = stk.array_capacity;
        for(size_t i=0; i != stk.stack_size; ++i){
            values[i] = stk.values[i];
        }
        }
        return *this;
    }

	// Insert an item at the top of the stack
	void stack::push(int val){
        if (stack_size==array_capacity){
            int *temp = new int[2*array_capacity];
            for(size_t i=0; i != stack_size; ++i){
                temp[i] = values[i];
            }
            delete[] values;
            values  = new int[2*array_capacity];
            for(size_t i=0; i != stack_size; ++i){
                values[i] = temp[i];
            }
            values[stack_size] = val;
            delete[] temp;
            stack_size++;
            
        }
        else{
		values[stack_size] = val;
		++stack_size;
	}
    }

	// Returns the value of the topmost item of the stack;
	// throws an exception if the stack is empty
	int stack::peek() const{
        if (stack_size==0){
		throw std::invalid_argument("Stack is empty");
        }
		return values[stack_size -1];
	}

	// Remove the topmost item from the stack
	// throws an exception if the stack is empty
	void stack::pop(){
        if (stack_size == 0){
		throw std::invalid_argument("Stack is empty");
        }
        else{
		stack_size--;
        }
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
		return (stack_size==0);
	}

	// Print out the contents of the stack


	// Destructor
	stack::~stack(){
    delete [] values;
  }
