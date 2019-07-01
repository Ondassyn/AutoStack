//
//  stack.cpp
//  assignment_4_tanbol
//
//  Created by Tanbol Salyk on 6/20/19.
//  Copyright © 2019 Tanbol Salyk. All rights reserved.
//

#include <stdio.h>
#include "stack.h"
#include <iostream>
#include <initializer_list>
#include <ostream>
#include <vector>
using namespace std;

// Copy constructor
stack::stack(const stack& stk){
    values=new int [stk.array_capacity];
    stack_size=stk.stack_size;
    array_capacity=stk.array_capacity;
    size_t x=0;
    do{
        values[x] = stk.values[x];
        x++;
    }while(x < stack_size);
}

// Initializer list constructor
stack::stack(std::initializer_list<int> ilist){
    stack_size=ilist.size();
    array_capacity=ilist.size();
    values=new int[ilist.size()];
    size_t i=0;
    for(int vals:ilist){
        values[i]=vals;
        ++i;
    }
}

// Copy assignment
stack& stack::operator=(const stack& stk)
{
    if (this == &stk){
        return *this;
    }
    array_capacity = stk.array_capacity;
    stack_size = stk.stack_size;
    delete[] values;
    values = new int [array_capacity];
    size_t i=0;
    do{
        values[i] = stk.values[i];
        i++;
    }while(i<stack_size);
    return *this;
}

// Insert an item at the top of the stack
void stack::push(int val){
    if(stack_size >=array_capacity){
        array_capacity = array_capacity*3;
        int* newval = new int [array_capacity];
        size_t i=0;
        for(i=0;i < stack_size;i++){
            newval[i] = values[i];
        }
        delete[] values;
        newval[stack_size] = val;
        values = newval;
        stack_size=stack_size+1;
    }else{
        values[stack_size] = val;
        stack_size=stack_size+1;
    }
}

// Returns the value of the topmost item of the stack;
// throws an exception if the stack is empty
int stack:: peek() const{
    if(stack_size != 0){
        return values[stack_size - 1];
    }else{
        throw std::invalid_argument("error-the stack empty");
    }
}

// Remove the topmost item from the stack
// throws an exception if the stack is empty
void stack::pop(){
    if(stack_size >0){
        stack_size--;
    }else{
        throw std::invalid_argument("error-the stack empty");
    }
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
    return (stack_size==0);
}

stack::~stack(){
    delete[] values;
}

