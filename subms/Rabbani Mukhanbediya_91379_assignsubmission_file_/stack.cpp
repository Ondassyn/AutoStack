#include"stack.h"
#include<stdexcept>
//---Constructor---
//stack::stack();
//---Copy constructor---
stack::stack(const stack& stk){
		stack_size=stk.stack_size;
		array_capacity=stk.array_capacity;
		values=new int[array_capacity];
	for(size_t i=0;i<stack_size;i++){
		values[i]=stk.values[i];
	}//Circular???
}
//---Initializer list constructor---
stack::stack(std::initializer_list<int> ilist){
		array_capacity=ilist.size();
		int i=0;
		values=new int[array_capacity];
	for(int it:ilist){
		values[i]=it;
		i++;
	}
		
}
//---Copy assignment---
stack& stack::operator=(const stack& stk){
		stack_size=stk.stack_size;
		array_capacity=stk.array_capacity;
		delete[] values;
		values=new int[array_capacity];
	for(size_t i=0;i<stack_size;i++){
		values[i]=stk.values[i];
	}//Circular???
		return *this;
}
//---Push function---
void stack::push(int val){
	if(stack_size==array_capacity){
		//Ensure capacity(Wrong*NEED CHECK)
		//try to use pointer to values instead of creating new stack
		array_capacity*=2;	
		stack temp;
		temp.array_capacity=array_capacity;
		temp.stack_size=stack_size;
		temp.values=new int[array_capacity];
	for(size_t i=0;i<stack_size;i++){
		temp.values[i]=values[i];
	}//Circular???
	
		delete[] values;
		values=new int[array_capacity];
	
	for(size_t i=0;i<stack_size;i++){
		values[i]=temp.values[i];
	}//Circular???
		delete[] temp.values;
	} 
		values[stack_size]=val;
		stack_size++;

}
//---Show top---
int stack::peek() const{
if(stack_size==0){
throw std::invalid_argument("Stack is empty");
}else {
	return values[stack_size-1];
	}
}
//---Remove top---
void stack::pop(){
	if(stack_size==0){
	throw std::invalid_argument("Stack is empty");
	} else {
	stack_size--;
	}
}
//---Empty stack---
void stack::clear(){
	stack_size=0;
}
//------
size_t stack::size() const{
	return stack_size;
}
//------
bool stack::empty() const{
	if(stack_size==0){
		return true;
	} else {
		return false;
	}
	return true;
}
//------
stack::~stack(){
	delete[] values;
}

