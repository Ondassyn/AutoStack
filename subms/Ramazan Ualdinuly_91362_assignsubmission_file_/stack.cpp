//
//  stack.cpp
//  csci152ass3
//
//  Created by Рамазан Сакенов on 22.06.2019.
//  Copyright © 2019 Ramazan Ualdinuly. All rights reserved.
//
#include<ostream>
#include "stack.h"
using namespace std;
stack::stack(const stack& stk):
values(new int[stk.array_capacity]),
stack_size(stk.stack_size),
array_capacity(stk.array_capacity)
{
    for(size_t i=0; i<stk.stack_size; i++){
        values[i]=stk.values[i];
    }
}
stack::stack(std::initializer_list<int> ilist):
stack_size(ilist.size()),
values(new int[stack_size]), 
array_capacity(stack_size*2){
    size_t i=0;
    for(int val:ilist){
        values[i]=val;
        ++i;
    }
}
stack& stack::operator=(const stack& stk){
    stack_size=stk.stack_size;
    for(size_t i=0; i<stk.stack_size; i++){
        values[i]=stk.values[i];
    }
    return *this;
}
void stack::push(int val){
    if (stack_size==array_capacity) {
        int *new_values(new int[2*array_capacity]);
        array_capacity=2*array_capacity;
        for(size_t i=0;i<stack_size; i++){
            new_values[i]=values[i];
        }
        delete [] values;
        values=new_values;
    }
    values[stack_size]=val;
    stack_size++;
}
int stack::peek() const{
    if(stack_size==0){
        throw std::invalid_argument("Stack is empty");
    }
    return values[stack_size-1];
}
void stack::pop(){
    if(stack_size==0){
        throw std::invalid_argument("Stack is empty");
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
    else {return false;}
}
stack::~stack(){
    delete[] values;
}
