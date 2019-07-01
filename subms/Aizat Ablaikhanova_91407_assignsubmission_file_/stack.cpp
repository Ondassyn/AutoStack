#include <iostream>
#include <stdexcept>
#include "stack.h"
using namespace std;

stack::stack(const stack& stk) :
values(new int[stk.array_capacity]),
stack_size(stk.stack_size),
array_capacity(stk.array_capacity)
{
for (size_t i = 0; i < stk.stack_size; ++i) {
values[i] = stk.values[i];
}
}

stack::stack(std::initializer_list<int> ilist):
values(new int [ilist.size()]),
stack_size(ilist.size()),
array_capacity(ilist.size())
{

std::cout << "in list constructor"<< std::endl;
size_t i = 0;

for(int val : ilist) {
values[i] = val;
++i;
}

}


stack& stack::operator=(const stack& stk) {

if (array_capacity != stk.array_capacity) {

    delete [] values;
    values = new int[stk.array_capacity];
    stack_size = stk.stack_size;
    array_capacity = stk.array_capacity;

}

for(size_t i = 0; i < stk.stack_size; ++i) {
values[i] = stk.values [i];
}

return *this;

}

void stack::push(int val){

if (stack_size >= array_capacity) {

array_capacity = array_capacity * 2;
int* temp = new int[array_capacity];

for(size_t i = 0; i < stack_size; ++i) {
    temp[i] = values[i];
}

delete [] values;
values = new int[array_capacity];

for(size_t i = 0; i < stack_size; ++i) {
    values[i] = temp[i];
}

delete [] temp;

}

values[stack_size] = val;
++stack_size;

}


int stack::peek() const {

if (stack_size == 0) {
throw std::out_of_range ("Stack is currently empty");
}
return values[stack_size -1];

}


void stack::pop() {


if (stack_size == 0) {
throw std::out_of_range ("Stack is currently empty");
}
stack_size--;
}


void stack::clear() {
stack_size = 0;
}

size_t stack::size() const {
return stack_size;
}

bool stack::empty() const {
return (stack_size == 0);
}

stack::~stack() {
delete [] values;
stack_size = 0;
array_capacity = 0;
}
