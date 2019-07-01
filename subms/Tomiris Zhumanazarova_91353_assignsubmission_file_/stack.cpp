#include "stack.h"
#include <stdexcept>


stack::stack(const stack& stk) :
    values(new int[stk.array_capacity]),
    stack_size(stk.stack_size),
    array_capacity(stk.array_capacity)
{
    for (size_t i = 0; i < stk.stack_size; ++i) {
        values[i] = stk.values[i];
    }
}

stack::stack(std::initializer_list<int> ilist) :
    values(new int[ilist.size()*2]),
    array_capacity(ilist.size()*2),
    stack_size(ilist.size())
    {
        size_t i = 0;
        for (int val : ilist) {
            values[i] = val;
            ++i;
        }
    }

stack& stack::operator=(const stack& stk) {
    if (stack_size != stk.stack_size) {
        delete[] values;
        values = new int[stk.array_capacity];
        stack_size = stk.stack_size;
        array_capacity = stk.array_capacity;
    }
    for (size_t i = 0; i < stk.stack_size; ++i) {
        values[i] = stk.values[i];
    }
    return *this;
}

void stack::push(int val) {
    if (stack_size == array_capacity) {
        int *new_values = new int[array_capacity*2];
        for (size_t i = 0; i < stack_size; ++i) {
            new_values[i] = values[i];
        }
        delete[] values;
        values = new_values;
        array_capacity*=2;
    }
    values[stack_size] = val;
    ++stack_size;
}

int stack::peek() const {
    if (stack_size == 0) {
        throw std::invalid_argument(
        "Cannot peek as the stack is empty!!!");
    }
    return values[stack_size - 1];
}

void stack::pop() {
    if (stack_size == 0) {
        throw std::invalid_argument(
        "Cannot pop as the stack is empty!!!");
    }
    stack_size--;
}

void stack::clear() {
    stack_size = 0;
}

size_t stack::size() const {
    return stack_size;
}

bool stack::empty() const {
    return (stack_size == 0);
}

stack::~stack() {
    delete[] values;
}
