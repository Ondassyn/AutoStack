#include "stack.h"
#include <iostream>
stack::stack(const stack &stk) {
    values = new int[stk.size()];
    for(int i = 0; i < stk.size(); i++){
        values[i] = stk.values[i];
    }
    stack_size = stk.stack_size;
    array_capacity = stk.array_capacity;
//    std::cout<<"copy constructor\n";
}

stack::stack(std::initializer_list<int> ilist) {
    int *newvals = new int[ilist.size()*2];
    int j = 0;
    for(std::initializer_list<int>::iterator it = ilist.begin(); it != ilist.end(); it++, j++){
        newvals[j] = *it;
    }
    values = newvals;
    stack_size = ilist.size();
    array_capacity = 2 * stack_size;
//    std::cout<<"init constructor\n";
}

stack& stack::operator=(const stack &stk) {
    values = new int[stk.size()];
    for(int i = 0; i < stk.size(); i++){
        values[i] = stk.values[i];
    }
    stack_size = stk.stack_size;
    array_capacity = stk.array_capacity;
//    std::cout<<"assignment operator\n";
    return  *this;
}

stack::~stack() {
    delete[] values;
//    std::cout<<"destructor\n";
}

void stack::push(int val) {
    if(size()==array_capacity){
        int *newvals = new int[2*array_capacity];
        for(int i = 0; i < size(); i++){
            newvals[i] = values[i];
        }
    }
    values[size()] = val;
    stack_size++;

}

void stack::pop() {
    if (empty()) {
        throw std::exception();
    } else {
        stack_size--;
    }
}
int stack::peek() const {
    if (size() != 0) {
        return values[size() - 1];
    } else {
        throw std::exception();
    }
}
void stack::clear() {
    delete[] values;
    values = new int[5];
    stack_size = 0;
    array_capacity = 5;
}

size_t stack::size() const {
    return stack_size;
}

bool stack::empty() const {
    return size() == 0;
}