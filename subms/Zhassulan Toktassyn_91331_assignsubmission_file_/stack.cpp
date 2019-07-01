//
// Created by Zhassulan on 2019-06-21.
//

#include <iostream>
#include "stack.h"
using namespace std;


    // Copy constructor
    stack::stack(const stack &stk) {
        values = new int[stk.size()];
        stack_size = stk.size();
        array_capacity = stk.size();
        for(size_t i = 0; i < stack_size; i++){
            values[i] = stk.values[i];
        }


    }

    // Initializer list constructor
    stack::stack(std::initializer_list<int> ilist) {

        values = new int[ilist.size()];
        size_t j = 0;
        for(int i : ilist){
            values[j] = i;
            j++;
        }
        array_capacity = ilist.size();
        stack_size = ilist.size();

    }

    //  assignment
    stack& stack::operator=(const stack &stk) {
        if(stack_size != stk.stack_size){
            delete[] values;
            stack_size = stk.stack_size;
            values = new int[stack_size];
            array_capacity = stk.size();
        }
        for(size_t i = 0; i < stack_size; i++){
            values[i] = stk.values[i];
        }

        return *this; // meaning
    }

    // Insert an item at the top of the stack
    void stack::push(int val) {
        if(stack_size == array_capacity){
            array_capacity *= 2;
        int* newValues = new int[array_capacity];
            for(size_t i = 0 ; i < stack_size; i++){
            newValues[i] = values[i];
            }
            delete[] values;
            values = newValues;
        }
        values[stack_size] = val;
        stack_size++;


    }
    // Returns the value of the topmost item of the stack;
    // throws an exception if the stack is empty
    int stack::peek() const {
        if(stack_size == 0 ) throw std::invalid_argument( "Stack is empty" );
        return values[stack_size - 1];
    }

    // Remove the topmost item from the stack
    // throws an exception if the stack is empty
    void stack::pop(){
        if(stack_size == 0 ) throw std::invalid_argument( "Stack is empty" );
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
        if(stack_size == 0)
            return true;
        else
            return false;

    }


    // Destructor
    stack::~stack()
    {

            delete[] values;

    }

