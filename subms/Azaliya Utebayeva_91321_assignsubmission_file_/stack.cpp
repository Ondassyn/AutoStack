#include <stdexcept>
#include <ostream>
#include "stack.h"

//copy constructor 

stack::stack(const stack& stk){
    values=new int [stk.array_capacity];
    stack_size=stk.stack_size;
    array_capacity=stk.array_capacity;
    
    for(size_t i=0;i<stack_size;++i){
        values[i]=stk.values[i];
    }
    
}

// Initializer list constructor
stack::stack(std::initializer_list<int> ilist)
    {
        values=new int [ilist.size()];
        stack_size=ilist.size();
        array_capacity=ilist.size();
        size_t i=0;
        for (int val:ilist){
            values[i]=val;
            ++i;
        }
    }


// Copy assignment
stack& stack::operator=(const stack& stk){
        stack_size=stk.stack_size;
        array_capacity=stk.array_capacity;
        for(size_t i=0;i<stk.stack_size;++i){
    values[i]=stk.values[i];
        }


return *this;
}

// Insert an item at the top of the stack
void stack::push(int val){
    if (stack_size==array_capacity){
        size_t resize=array_capacity*2;
        int* oldstack = values;
        values=new int[resize];
        
        for(size_t i=0;i<stack_size;++i){
    values[i]=oldstack[i];
        }
        delete[] oldstack;
        array_capacity = resize;
    }
    values[stack_size]=val;
    stack_size++;
    
    }

// Returns the value of the topmost item of the stack;
// throws an exception if the stack is empty
int stack::peek() const{
    if (stack_size==0){
        throw "stack is empty";
        //return *this;
    }
    return values[stack_size-1];
}

// Remove the topmost item from the stack
// throws an exception if the stack is empty
void stack::pop(){
    
    
    if(stack_size==0){
        throw "Stack is empty";
    }
    stack_size--;
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
    return (stack_size==0);
}


stack::~stack(){
delete[] values;

}
