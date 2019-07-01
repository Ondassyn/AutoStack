//
//  stack.cpp
//  adil_a3
//
//  Created by Adil on 6/23/19.
//  Copyright © 2019 Adil. All rights reserved.
//

#include "stack.h"

stack::stack(const stack& stk) {
    array_capacity = stk.array_capacity;
    stack_size = stk.stack_size;
    values = new int[array_capacity];
    for (size_t x = 0; x < stk.stack_size; x++)
        values[x] = stk.values[x];
}

stack::stack(std::initializer_list<int> ilist) {
    const int *it = ilist.begin();
    stack_size = ilist.size();
    values = new int[array_capacity];
    for (size_t x = 0; x < stack_size; x++)
        values[x] = *(it + x);
}

stack& stack::operator=(const stack& stk) {
    
    delete[] values;
    
    values = new int[ stk.array_capacity ];
    
    for( size_t i = 0; i < stk.stack_size; ++ i )
        values[i] = stk.values[i];
    
    array_capacity = stk.array_capacity;
    stack_size = stk.stack_size;
    
    return *this;
}

void stack::push(int val) {
    if (stack_size == array_capacity) {
        int* newvalues = new int[ array_capacity * 2 ];
        
        for( size_t i = 0; i < stack_size; ++ i )
            newvalues[i] = values[i];
        
        newvalues[stack_size] = val;
        
        delete[] values;
        
        values = newvalues;
        array_capacity = array_capacity * 2;
        stack_size++;
    } else {
        values[stack_size] = val;
        stack_size++;
    }
}

int stack::peek() const {
    if (stack_size == 0) {
        throw std::runtime_error("stack::pop() stack_size is 0");
    }
    return values[stack_size - 1];
}

void stack::pop() {
    if (stack_size == 0) {
        throw std::runtime_error("stack::pop() stack_size is 0");
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
    return stack_size == 0;
}

stack::~stack() {
    delete [] values;
    stack_size = 0;
    array_capacity = 1;
}
