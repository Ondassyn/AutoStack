//
//  stack.cpp
//  akadilKalimoldayevAssignment3
//
//  Created by Akadil Kalimoldayev on 6/22/19.
//  Copyright © 2019 Akadil Kalimoldayev. All rights reserved.
//

#include "stack.h"

/*
 int *values;
 size_t stack_size;
 size_t array_capacity;
 */

// Copy constructor
stack::stack(const stack& stk):
values(new int[stk.stack_size]),
stack_size(stk.stack_size),
array_capacity(stk.array_capacity)
{
    for(int i=0; i<stk.stack_size; i++){
        values[i]=stk.values[i];
    }
}

// Initializer list constructor
stack::stack(std::initializer_list<int> ilist){
    
    values=new int[ilist.size()];
    stack_size=ilist.size();
    array_capacity=ilist.size();
    
    size_t i=0;
    for(int val : ilist){
        values[i] = val;
        i++;
    }
}

// Copy assignment
stack& stack::operator=(const stack& stk){
    delete[] values;
    values=new int[stk.stack_size];
    
    for(int j=0; j<stk.stack_size; j++){
        values[j]=stk.values[j];
    }
    stack_size=stk.stack_size;
    array_capacity=stk.array_capacity;
    
    return *this;
}

// Insert an item at the top of the stack
void stack::push(int val){
    
    if(stack_size==array_capacity){
        array_capacity=array_capacity*2;
        int *new_values = new int[array_capacity];
        
        for(int a=0; a<stack_size; a++){
            new_values[a]=values[a];
        }
        
        delete [] values;
        values=new_values;
        values[stack_size]=val;
        stack_size++;
        
    }else{
        values[stack_size]=val;
        stack_size++;
    }
    
}

// Returns the value of the topmost item of the stack;
// throws an exception if the stack is empty
int stack::peek() const{
    
    if(stack_size!=0){
        return values[stack_size-1];
    }else{
        throw std::invalid_argument("The stack is empty");
    }
}

// Remove the topmost item from the stack
// throws an exception if the stack is empty
void stack::pop(){
    
    if(stack_size!=0){
        stack_size--;
    }else{
        throw std::invalid_argument("The stack is empty");
    }
}

// Remove everything from the stack
void stack::clear(){
    stack_size=0;
}

// Returns the number of items on the stack
size_t stack::size() const{
    return stack_size;
}

// Returns whether or not the stack is currently empty
bool stack::empty() const{
    if(stack_size==0){
        return 1;
    }else{
        return 0;
    }
}

// Print out the contents of the stack


// Destructor
stack::~stack(){
    delete[] values;
}
