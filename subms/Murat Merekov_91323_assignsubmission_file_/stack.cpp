#include "stack.h"
#include <stdexcept>
#include <iostream>

//stack::stack();

// Copy constructor
stack::stack(const stack& stk):
    values(new int[stk.array_capacity]),
    stack_size(stk.stack_size),
    array_capacity(stk.array_capacity)
{
    for(int i=0; i<stk.stack_size; i++)
    {
        values[i]=stk.values[i];
    }
}

// Initializer list constructor
stack::stack(std::initializer_list<int> ilist)
{
    stack_size = 0;
    array_capacity = ilist.size();
    values = new int[ilist.size()*2];
    for( int val : ilist )
    {
        values[stack_size] = val;
        stack_size++;
    }
}

// Copy assignment
stack& stack::operator=(const stack& stk)
{
    stack_size = stk.stack_size;
    for(int j=0; j<stk.stack_size; j++)
    {
        values[j]=stk.values[j];
    }
    return *this;
}

// Insert an item at the top of the stack
void stack::push(int val)
{
    if(stack_size == array_capacity)
    {

        int *new_data = new int [array_capacity*2];
        for(int i = 0; i < stack_size; i++)
        {
            new_data[i] = values[i];
        }
        delete []values;
        values = new_data;
        array_capacity *=2;
    }
    values[stack_size] = val;
    stack_size++;
}

// Returns the value of the topmost item of the stack;
// throws an exception if the stack is empty
int stack::peek() const
{
    if(stack_size<1){
        throw std::invalid_argument("PEEK");
    }else
        return values[stack_size-1];
}

// Remove the topmost item from the stack
// throws an exception if the stack is empty
void stack::pop()
{
    if(!stack_size){
        throw std::invalid_argument("POP");
    }else
        stack_size--;

}

// Remove everything from the stack
void stack::clear()
{
    stack_size=0;
}

// Returns the number of items on the stack
size_t stack::size() const
{
    return stack_size;
}

// Returns whether or not the stack is currently empty
bool stack::empty() const
{
    return (stack_size==0);
}

//       Print out the contents of the stack
//void stackprint(std::ostream& out) const ;

stack::~stack()
{
    delete [] values;
}
