#include "stack.h"
#include <stdexcept>
#include <ostream>

stack::stack(const stack& stk)
{
    array_capacity = stk.stack_size * 3;
    int* newdata = new int[ array_capacity];
    for(size_t i = 0; i < stk.stack_size; i++)
    {
        newdata[i] = stk.values[i];
    }
    values = newdata;
    for(size_t i = 0; i < stk.stack_size; i++)
    {
        values[i] = stk.values[i];
    }
    stack_size = stk.stack_size;
}

stack::stack(std::initializer_list<int> ilist)
{
    array_capacity = ilist.size() * 3;
    int* newdata = new int[ array_capacity];
    size_t i = 0;
    for(int val : ilist)
    {
        newdata [i] = val;
        i++;
    }
    values = newdata;
    stack_size = ilist.size();
}
stack& stack::operator = (const stack& stk)
{
    array_capacity = stk.stack_size * 3;
    int* newdata = new int[ array_capacity];
    for(size_t i = 0; i < stack_size; i++)
    {
        newdata [i] = values [i];
    }
    delete[] values;
    values = newdata;

    for(size_t i = 0; i < stk.stack_size; i++)
    {
        values[i] = stk.values[i];
    }
    stack_size = stk.stack_size;
    return *this;
}
// Insert an item at the top of the stack
void stack::push(int val)
{
    int* newdata = new int[array_capacity++];
    for(size_t i = 0; i < stack_size; i++){
        newdata[i] = values[i];
    }
    delete[] values;
    values = newdata;
    values[stack_size] = val;
    stack_size++;

}

// Returns the value of the topmost item of the stack;
// throws an exception if the stack is empty
int stack::peek() const
{
    if(stack_size == 0)
    {
        throw std::invalid_argument("Stack is empty");
    }
    return values[stack_size - 1];
}

// Remove the topmost item from the stack
// throws an exception if the stack is empty
void stack::pop()
{
    if(stack_size == 0)
    {
        throw std::invalid_argument("Stack is empty");
    }
    stack_size--;
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
    if(stack_size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Destructor
stack::~stack()
{
    delete[] values;
}
