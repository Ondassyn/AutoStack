#include <iostream>
#include "stack.h"


stack::stack(const stack& stk):
values(new int [stk.array_capacity]),
stack_size(stk.stack_size),
array_capacity(stk.array_capacity)
	{
	for(size_t i=0;i<stk.stack_size;i++){
		values[i]=stk.values[i];
	}
}
stack::stack(std::initializer_list<int> ilist):
		values(new int [ilist.size()]),
	stack_size(ilist.size()),
array_capacity(ilist.size())
{
	size_t i=0;
for(int array:ilist){
	values[i]=array;
	i++;
}
}
stack & stack::operator=(const stack& stk){
if(stack_size!=stk.stack_size){
	delete[] values;
	values=new int[stk.array_capacity];
	stack_size=stk.stack_size;
	array_capacity=stk.array_capacity;
	for(size_t i=0;i<stk.stack_size;i++){
		values[i]=stk.values[i];
	}
}
if(stack_size==stk.stack_size){
	for(size_t i=0;i<stk.stack_size;i++){
		values[i]=stk.values[i];
	}
}


return*this;
}
void stack::push(int val){
	int* arr1=new int[stack_size];
	for(size_t i=0;i<stack_size;i++){
			arr1[i]=values[i];
	}
if(array_capacity==stack_size){

		delete[] values;
		array_capacity*=2;
		values=new int[array_capacity];
		for(size_t i=0;i<stack_size;i++){
		values[i]=arr1[i];

		}


}

delete[] arr1;

values[stack_size]=val;
++stack_size;
}
int stack::peek() const{
	if(stack_size==0){
		throw std::invalid_argument("stack is empty");
	}
return values[stack_size-1];
}
void stack::pop(){
	if(stack_size==0){
			throw std::invalid_argument("stack is empty");
	}
	stack_size--;

}
void stack::clear(){
stack_size=0;
}
size_t stack::size() const{
return stack_size;
}
bool stack::empty() const{
if(stack_size==0){
	return true;
}
return false;
}
stack::~stack(){
delete[] values;
values=nullptr;
}




