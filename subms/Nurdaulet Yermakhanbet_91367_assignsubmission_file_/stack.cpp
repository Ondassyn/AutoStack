#include "stack.h"
#include <iostream>


	// Copy constructor
	stack::stack(const stack& stk):
		values(new int[stk.array_capacity]),
		stack_size(stk.stack_size),
		array_capacity(stk.array_capacity)
{
	     for(size_t i = 0; i < stack_size; ++i)		values[i] = stk.values[i];
}

	// Initializer list constructor
	// = {a,v,d,s}		how it passes		ilist++ ?	

	stack::stack(std::initializer_list<int>ilist):
    stack_size(ilist.size()),
    values(new int[ilist.size() + ilist.size()]),
    array_capacity(ilist.size() + ilist.size())
{
     size_t i=0;
     for (int val:ilist){
        values[i]=val;
        ++i;
     }
}


	// Copy assignment
	stack& stack::operator=(const stack& stk) {
		if(stack_size == stk.stack_size) {
			for(size_t i = 0; i < stk.array_capacity; ++i) if(values[i] != stk.values[i]) break;
				if((i+1) == array_capacity)	throw std::invalid_argument("stacks are same");;		
				// throw an exception?	nothing to copy, same objects
		}
		else {	
			values = (new int[stk.array_capacity]);
			stack_size = stk.stack_size;
			array_capacity = stk.array_capacity;

			for(size_t i = 0; i < stack_size; ++i) values[i] = stk.values[i];		
			return *this;	}

	}

	// Insert an item at the top of the stack
	void stack::push(int val)
{
  if ((stack_size + 1) > array_capacity){
    
     int *newval = new int[array_capacity + array_capacity];
    
    for(size_t i = 0; i < stack_size; ++i)      newval[i] = values[i];
    
    array_capacity= array_capacity+array_capacity;
    delete[] values;
    values = newval;
  }
    values[stack_size]=val;
    ++stack_size;
}
		
		}

// but for real i don want that		but if u cannot solve this problems yup sekirme 	uaqyt keled ketesin



	// Returns the value of the topmost item of the stack;
	// throws an exception if the stack is empty
	int peek() stack::const {
		if(stack_size == 0) throw std::invalid_argument("stack is empty"); 
		else return values[--stack_size];
	}

	// Remove the topmost item from the stack
	// throws an exception if the stack is empty
	void stack::pop() {
		if(stack_size == 0) throw std::invalid_argument("stack is empty");
		--stack_size;

	}

	// Remove everything from the stack
	void stack::clear() {
		stack_size(0);
	}

	// Returns the number of items on the stack
	size_t stack::size() const {
		return stack_size;
	}

	// Returns whether or not the stack is currently empty
	bool stack::empty() const {
		if (stack_size == 0)       return true;
    	else        return false;
	}

	// Print out the contents of the stack
	/*void print(std::ostream& out) const {

		out << "[";
		for (size_t i = 0; i < stack_size; ++i) {
			if (i > 0) {
				out << ", ";
			}
			out << values[i];
		}
		out << "]";
	}*/

	// Destructor
	stack::~stack(){
 delete[] values;
}

