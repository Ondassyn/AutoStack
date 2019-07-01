
#include <iostream>
#include "stack.h"


stack::stack(const stack& stk): stack_size{stk.stack_size}, array_capacity{stk.array_capacity}, values{new int[stk.array_capacity]}{
    for(size_t i=0; i<stack_size; ++i){
        values[i]=stk.values[i];
    }
    
}

stack::stack(std::initializer_list<int> ilist):stack_size{ilist.size()},array_capacity{ilist.size()}, values{new int[ilist.size()]}
{
    size_t i=0;
    for(int a: ilist){
        values[i]=a;
        ++i;
    }
    
    
}
stack& stack::operator=(const stack& stk){
    if(this!=&stk){
        delete []values;
        array_capacity = stk.array_capacity;
        values = new int[array_capacity];
        stack_size = stk.stack_size;
        for(size_t i = 0; i<stack_size; ++i){
            values[i]=stk.values[i];
        }
    }
    return *this;
    
}

void stack::push(int val){
    if(stack_size == array_capacity){
        size_t new_capacity = array_capacity*2;
        int *newvalues = new int[new_capacity];
        for(size_t i=0; i<stack_size; ++i){
            newvalues[i]=values[i];
        }
        array_capacity = new_capacity;
        delete [] values;
        values = newvalues;
    }
    
    values[stack_size]=val;
    stack_size++;
    
}



int stack::peek() const{
    if(stack_size == 0){
        throw std::invalid_argument("the stack is empty");
    }
    else{
        
        return values[stack_size -1];
    }
}
void stack::pop(){
    if(stack_size ==0){
        throw std::invalid_argument("the stack is empty");
    }
    else{
        stack_size--;
    }
}
void stack::clear(){
    stack_size = 0;
}

size_t stack::size() const{
    return stack_size;
}
bool stack::empty() const{
    return stack_size == 0;
}
stack::~stack(){
    delete []values;
    values=0;
    
    
    
}
inline std::ostream& operator<<(std::ostream& out, const stack& stk);

