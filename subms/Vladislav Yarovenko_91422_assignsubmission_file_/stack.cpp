#include "stack.h"
#include <ostream>
#include <iostream>
#include <stdexcept>


// Copy constructor
stack::stack(const stack& stk):
    values(new int[stk.array_capacity]),
    stack_size(stk.stack_size),
    array_capacity(stk.array_capacity)
{

    for (size_t i = 0; i < stk.stack_size; i++)
    {
        values[i] = stk.values[i];
    }

}


// Initializer list constructor
stack::stack(std::initializer_list<int> ilist)
{
    array_capacity = ilist.size();
    values = new int[ilist.size()];
    stack_size = ilist.size();
    size_t i = 0;
    for (int val : ilist)
    {
        values[i] = val;
        ++i;
    }
}

// Copy assignment
stack& stack::operator=(const stack& stk)
{
    if (array_capacity != stk.array_capacity)
    {
	array_capacity = stk.array_capacity;
        
        delete[] values;
        values = new int [stk.array_capacity];
    }

    for (size_t i = 0; i < stk.stack_size; i++)
    {
        values[i] = stk.values[i];

    }

    
    stack_size = stk.stack_size;

    return *this;
}

// Insert an item at the top of the stack
void stack::push(int val)
{
    if (stack_size >= array_capacity)
    {
    array_capacity *=2;
        int *new_values = new int [array_capacity];
        for (size_t i = 0; i < stack_size; i++)
    {
        new_values[i] = values[i];
        }
        delete[] values;
        values = new_values;
    }

    values[stack_size] = val;
        stack_size++;
    }


// Returns the value of the topmost item of the stack;
// throws an exception if the stack is empty
int stack::peek() const
{
    if (stack_size == 0)
    {
        throw std::invalid_argument("The Stack is Empty\n");
    } else {
    return values[stack_size-1];
}
}

// Remove the topmost item from the stack
// throws an exception if the stack is empty
void stack::pop()
{
    if (stack_size == 0)
    {
        throw std::invalid_argument("The Stack is Empty\n");
    }

else
{
    stack_size--;
}
}

// Remove everything from the stack
void stack::clear()
{
    stack_size = 0;
}

// Returns the number of items on the stack
size_t stack::size() const
{
    return stack_size;
}

// Returns whether or not the stack is currently empty
bool stack::empty() const
{
    return (stack_size == 0);
}



// Destructor
stack::~stack()
{
    delete[] values;
}



