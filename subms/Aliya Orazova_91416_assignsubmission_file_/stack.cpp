//
// Created by User on 26.06.2019.
//
#include <stdexcept>
#include <ostream>
#include "stack.h"
using namespace std;


stack::stack(const stack& stk) :

    values(new int[stk.size()]),
    stack_size(stk.size()),
    array_capacity(stk.size())
    {
    for(size_t i =0; i<stk.stack_size; ++i) {
        values[i] = stk.values[i];
    }
    }


stack::stack(std::initializer_list<int> ilist):

values(new int[ilist.size()])
{
    size_t i = 0;
    for(int val : ilist) {
        values[i] = val;
        i++;
    }
    array_capacity=ilist.size();
    stack_size=ilist.size();
}

stack& stack::operator=(const stack& stk) {

if(stack_size==stk.stack_size){
    for(size_t i=0; i<stack_size; ++i) {
        values[i]=stk.values[i];
    }

}
    delete[]values;
    array_capacity=stk.size();
    values = new int[stack_size];
    stack_size = stk.stack_size;

    return *this;
}

void stack::push(int val) {
    if(stack_size==array_capacity) {
  int* val_new = new int[array_capacity*2];
  for(size_t i=0; i<stack_size; i++){
      val_new[i]=values[i];}
      delete[] values;
      values = val_new;
      val_new[stack_size] = val;
      ++stack_size;

    } else {
        values[stack_size] = val;
        ++stack_size;
    }
}

int stack::peek() const {
    if(stack_size==0) {
        throw std::invalid_argument("error");
    } else {
        return values[stack_size - 1];
    }
}

void stack::pop() {
    if(stack_size==0) {
        throw std::invalid_argument("error");
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
    return (stack_size==0);
}

stack::~stack() {
    delete[] values;
}