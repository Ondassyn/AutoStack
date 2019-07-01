#include "stack.h"
#include <iostream>

stack::stack(const stack& stk):
    values(new int[stk.array_capacity]),
    stack_size(stk.stack_size),
    array_capacity(stk.array_capacity)
{
    for(size_t i=0;i<stk.stack_size;++i){
        values[i]=stk.values[i];
    }
}

stack::stack(std::initializer_list<int>ilist):
    stack_size(ilist.size()),
    values(new int[ilist.size() * 2]),
    array_capacity(ilist.size() * 2)
{
     size_t i=0;
     for (int val:ilist){
        values[i]=val;
        ++i;
     }
}

stack& stack::operator=(const stack& stk){
    if (stack_size!=stk.stack_size){
    stack_size=stk.stack_size;
    delete[] values;
    values=new int[stk.array_capacity];
    array_capacity=stk.array_capacity;
    }
    for(size_t i=0;i<stk.stack_size;++i){
        values[i]=stk.values[i];
    }
    return *this;
}
//Allocating new values[]
//Copying values over
//Deallocating old values array
//Resetting pointers for values to the new values
void stack::push(int val)
{
  if (stack_size + 1 > array_capacity){
     int *newval=new int[array_capacity*2];
    for(size_t i=0;i<stack_size;++i){
        newval[i]=values[i];
    } 
    array_capacity=2*array_capacity;
    delete[] values;
    values = newval;
  }
    values[stack_size]=val;
    stack_size++;
}

int stack::peek() const
{
 if (stack_size==0)
    throw std::invalid_argument("Stack is empty");
 else  
    return values[stack_size-1];
}

void stack::pop()
{
  if (stack_size==0)
    throw std::invalid_argument("Stack is empty");
  stack_size--;
}

void stack::clear()
{
  stack_size=0;
}

size_t stack::size() const
{
  return stack_size;
}

bool stack::empty() const
{
    if (stack_size==0)
        return true;
    else
        return false;

}

stack::~stack(){
 delete[] values;
}
