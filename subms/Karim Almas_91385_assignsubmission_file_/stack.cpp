//
//  stack.cpp
//  Summer_Assignment3
//
//  Created by карим on 6/19/19.
//  Copyright © 2019 карим. All rights reserved.
//
#include <iostream>
#include "stack.h"
// Creates an empty stack
//stack::stack() :
//values(new int[5]),
//stack_size(0),
//array_capacity(5)


// Copy constructor
stack::stack(const stack& stk) :
values(new int[stk.array_capacity]),
stack_size(stk.stack_size),
array_capacity(stk.array_capacity)
{
    for(size_t i = 0; i < stk.stack_size; ++i) values[i] = stk.values[i];
}


stack::stack(std::initializer_list<int> ilist){
    values = new int[2*ilist.size()];
    array_capacity = 2*ilist.size();
    stack_size = ilist.size();
    int i=0;
    for (const auto& s : ilist){
        values[i]=s;
        ++i;
    }
}

// Copy assignment
stack& stack::operator=(const stack& stk){
    
    
    if(array_capacity != stk.array_capacity){
        delete[] values;
        values = new int[stk.array_capacity];
    }
    
    stack_size = stk.stack_size;
    array_capacity = stk.array_capacity;
    for(size_t i = 0; i < stk.stack_size; ++i) values[i] = stk.values[i];
    
    return *this;
}

// Insert an item at the top of the stack
void stack::push(int val){
    values[stack_size] = val;
    stack_size++;
    if(stack_size == array_capacity) {
        int *newvalues = new int[2*array_capacity];
        for(int i = 0; i < stack_size; ++i) newvalues[i] = values[i];
        delete[] values;
        values = newvalues;
        newvalues = nullptr;
        array_capacity *= 2;
    }
}
// Returns the value of the topmost item of the stack;
// throws an exception if the stack is empty
int stack::peek() const{
    if(empty()) throw std::invalid_argument("Stack is empty\n");
    return values[stack_size-1];
}

// Remove the topmost item from the stack
// throws an exception if the stack is empty
void stack::pop(){
    if(empty()) throw std::invalid_argument("Stack is empty\n");
    stack_size--;
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
    if(stack_size == 0) return true;
    return false;
}


// Destructor
stack::~stack(){
    delete[] values;
}
