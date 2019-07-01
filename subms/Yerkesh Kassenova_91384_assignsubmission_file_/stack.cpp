#include <ostream>
#include "stack.h"
#include <iostream>
using namespace std;
stack:: stack() :
            values (new int[5]),
            stack_size (0),
            array_capacity (5)
    
            {}

 
  stack::  stack(const stack& stk) :
        values(new int[stk.array_capacity]),
        stack_size (stk.stack_size),
        array_capacity (stk.array_capacity)
        {
            for (int i= 0; i<5; ++i) {
                values[i]= stk.values[i];
            
            }
            
        }

    stack:: stack(std::initializer_list<int> ilist) :
    
        stack_size {ilist.size()}
        {
            size_t j;
            for (int val: ilist) {
            
                values[j]= val;
                ++j;
            }
        }
    
    
    stack& stack:: operator=(const stack& stk) {
    stack_size = stk.stack_size;
        array_capacity = stk.array_capacity;
        
            for (int i= 0; i<5; ++i) {
                values[i]= stk.values[i];
            
            }
    
        return *this;
    }
   

    void  stack:: push(int val) {
    if (stack_size==array_capacity) {
    
        array_capacity=2*stack_size;
    }
        values[stack_size]=val;
        stack_size++;
        
    }

    int stack:: peek() const {
    if (stack_size==0) {
    
        throw std::invalid_argument("Impossible");
    }
        return values[stack_size-1];
    }

   
    void stack:: pop() {
    if (stack_size==0) {
    
        throw std::invalid_argument("Impossible");
    }
        stack_size--;
    }

    void stack:: clear() {
        stack_size=0;
    }

   size_t  stack::  size() const {
    
        return stack_size;
    }

    bool  stack:: empty() const {
    
        if (stack_size==0) {
        
            return true;
        }
        return false;
    }

    void stack:: print(std::ostream& out) const {

        out << "[";
        for (size_t i = 0; i < stack_size; ++i) {
            if (i > 0) {
                out << ", ";
            }
            out << values[i];
        }
        out << "]";
    }

    stack:: ~stack() {
        delete[] values;
    }      

inline std::ostream& operator<<(std::ostream& out, const stack& stk);

