#include "stack.h"
#include <ostream>

stack::stack(const stack& stk){
	stack_size = stk.stack_size;
	array_capacity = stk.array_capacity;
  values = new int[array_capacity];
	for (unsigned int i = 0; i!=stack_size; i++){
		values[i] = stk.values[i];
	}
}

stack::stack(std::initializer_list<int> ilist){
	array_capacity = ilist.size();
	stack_size = 0;
	values = new int[array_capacity];
	for (int d:ilist)
		push(d);
}

stack& stack::operator=(const stack& stk){
  stack_size = stk.stack_size;
	array_capacity = stk.array_capacity;
	delete[] values;
	values = new int[array_capacity];
	for (unsigned int i = 0; i!=stack_size; i++)
		values[i] = stk.values[i];
	return *this;
}

void stack::push(int val){
	if (array_capacity>stack_size){
		values[stack_size] = val;
		stack_size++;
	}
	else{
		int *temp = new int[array_capacity*2];
		for (unsigned int i = 0; i!=stack_size;i++){
			temp[i] = values[i];
		}
		delete[] values;
		values = new int[array_capacity*2];
		for (unsigned int i = 0; i!=stack_size; i++)
			values[i] = temp[i];
		delete[] temp;
		values[stack_size] = val;
    stack_size++;
    array_capacity = array_capacity * 2;
	}
}

int stack::peek() const{
	if (stack_size==0) throw std::invalid_argument("empty");
	else{
		return values[stack_size-1];
	}
}

void stack::pop(){
	if (stack_size==0) throw std::invalid_argument("empty");
	else{
		stack_size--;
	}
}

void stack::clear(){
	stack_size = 0;
}

size_t stack::size() const{
	return stack_size;
}

bool stack::empty() const{
	return stack_size==0;
}

stack::~stack(){
  array_capacity = 0;
  stack_size = 0;
	delete[] values;
}