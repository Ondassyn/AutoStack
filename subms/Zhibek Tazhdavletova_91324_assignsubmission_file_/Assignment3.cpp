#include "stack.h"

stack::stack(const stack& stk):
    values(new int[stk.array_capacity]),
    stack_size(stk.stack_size),
    array_capacity(stk.array_capacity)
{
    for(size_t i = 0; i != array_capacity; ++ i)
    {
        values[i] = stk.values[i];
    }
}
stack::stack(std::initializer_list<int> ilist):
    stack_size(ilist.size())
{
    size_t i = 0;
    for(int d: ilist)
    {
        values[i] = d;
        ++ i;
    }
}
void stack::push(int val)
{
    size_t i = 0;
    values[i] = val;
}
stack& stack::operator=(const stack& stk)
{
    if(array_capacity != stk.array_capacity)
    {
        delete [] values;
        array_capacity = stk.array_capacity;
        values = new int[stk.array_capacity];
    }

    for(size_t i = 0; i != array_capacity; ++ i)
    {
        values[i] = stk.values[i];
    }
}
int stack::peek() const
{
    return values[0];
}
void stack::pop()
{
    stack_size = stack_size-1;
}
void stack::clear()
{
    values = 0;
}
size_t stack::size() const
{
    return stack_size;
}
bool stack::empty() const
{
    if(stack_size)
        return true;
    return false;
}
