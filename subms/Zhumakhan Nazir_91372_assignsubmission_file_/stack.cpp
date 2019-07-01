#include <ostream>
#include <stdexcept>
#include "stack.h"

stack::stack(const stack& stk):
	stack_size(stk.stack_size),
	array_capacity(stk.stack_size),
	values(new int[stk.stack_size])	
{
	for(size_t i = 0; i < stack_size; i++)
		values[i] = stk.values[i];
}
stack::stack(std::initializer_list<int> ilist):
	stack_size(ilist.size()),
	array_capacity(ilist.size()),
	values(new int[ilist.size()])
{
	size_t i = 0;
	for (int el : ilist){
		values[i++] = el;
	}
}
stack& stack::operator=(const stack& stk){
	if(this == &stk){
		return *this;
	}
	if(stack_size != stk.size()){
		delete [] values;
		values = new int[stk.array_capacity];
		stack_size = stk.stack_size;
		array_capacity = stk.array_capacity;
	}
	for(size_t i = 0; i < stack_size; i++){
		values[i] = stk.values[i];
	}
	return *this;
}
void stack::push(int val){
	if(stack_size == array_capacity){
		array_capacity *= 2;
		int *temp = new int[array_capacity];
		for(size_t i = 0; i < stack_size; i++)
			temp[i] = values[i];
		temp[stack_size] = val;
		delete[] values;
		values = temp;
	}else{
		values[stack_size] = val;
	}
	stack_size++;
}
int stack::peek()const{
	if(stack_size != 0)
		return values[stack_size-1];
	else throw "peeking empty stack";
}
void stack::pop(){
	if(stack_size == 0)throw "poping empty stack";
	stack_size--;
	/*if(stack_size*2 == array_capacity and array_capacity > 4){
		array_capacity = stack_size;
		int *temp = new int[array_capacity];
		for(size_t i = 0; i < stack_size; i++){
			temp[i] = values[i];
		}
		delete[] values;
		values = temp;
	}*/
}

void stack::clear(){
	stack_size = 0;	
}
size_t stack::size()const{
	return stack_size;
}
bool stack::empty()const{
	return (stack_size == 0);
}
stack::~stack(){
	delete[] values;
}