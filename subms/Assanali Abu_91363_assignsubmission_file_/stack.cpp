#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;
#include "stack.h"
#include <stdexcept>


stack::stack(const stack& stk){
	values = new int[stk.array_capacity];
	stack_size = stk.stack_size;
    array_capacity = stk.array_capacity;

for(size_t i = 0; i < stk.stack_size; ++i)
{
	values[i] = stk.values[i];
}
}

stack::stack(std::initializer_list<int> ilist):stack()
{
	stack_size = ilist.size();
	 if(array_capacity < stack_size){
			 array_capacity = stack_size;
			 int *new_values = new int[array_capacity];
				size_t i = 0;
				for(int val : ilist){
					new_values[i] = val;
					++i;
				}
			 delete[] values;
			 values = new_values;
	 }
	 else{
			size_t i = 0;
			for(int val : ilist){
				values[i] = val;
				++i;
	 }

	}
}




 stack& stack:: operator=(const stack& stk){

	 if(stack_size!=stk.stack_size){
	 		stack_size = stk.stack_size;
	 		array_capacity = stk.array_capacity;
	 		delete[] values;
	 		values = new int[stk.array_capacity];
	 }
	 		for(size_t i = 0; i < stk.stack_size; ++i)
	 		{
	 			values[i] = stk.values[i];
	 		}
	 		return *this;
	 	}
 void stack::push(int val){
	 if(array_capacity == stack_size){
		 array_capacity = array_capacity*2;
		 int *new_values = new int[array_capacity];
		 size_t i;
		for(i = 0; i < stack_size; ++i){
			new_values[i] = values[i];
		}
		 delete[] values;
		 values = new_values;

	 }

		 values[stack_size] = val;
		 ++stack_size;


 }

 int stack:: peek() const{
if(stack_size==0){
	throw std::out_of_range("stack is empty");
}
else{

	return values[stack_size-1];
}
}
 void stack:: pop(){
	 if(stack_size==0){
	 	throw std::out_of_range("stack is empty");
	 }
	 else{
		 stack_size--;
	 }
 }
 	// Remove everything from the stack
 void stack:: clear(){
 		stack_size = 0;
 }

 	// Returns the number of items on the stack
 	size_t stack:: size() const{
 		return stack_size;
 	}

 	// Returns whether or not the stack is currently empty
 	bool stack:: empty() const{
 		return (stack_size == 0);
 	}
 	stack::~stack(){
 		delete [] values;
 	}
