#include <iostream>
#include <stdexcept>
#include "stack.h"

using namespace std;

stack::stack(const stack& stk):
        values(new int[stk.array_capacity]),
        stack_size(stk.stack_size),
        array_capacity(stk.array_capacity)
        {
                size_t i = 0;
                for(i=0;i<stk.stack_size;i++){
                        values[i]=stk.values[i];
                }
        }

stack::stack(std::initializer_list<int> ilist):
        stack_size(ilist.size())
        {
                int *newval = new int[ilist.size()];
                stack_size = ilist.size();
                array_capacity = ilist.size();
                delete [] values;
                values = newval;
                size_t i = 0;
                for(int val : ilist) {
                        values[i] = val;
                        i++;
                }
        }

stack& stack::operator = (const stack& stk)
        {
                if(this != &stk){
                        if(array_capacity<=stack_size){
                                int *newval=new int[array_capacity+1];
                                for(size_t i =0;i<stack_size;++i){
                                        newval[i]=values[i];
                                }
                                delete [] values;
                                array_capacity=array_capacity+1;
                                values=newval;
                        }
                }
                for(size_t i =0;i<stk.stack_size;i++){
                        values[i]=stk.values[i];
                }
                stack_size=stk.stack_size;
                return *this;
        }

void stack::push(int val)
        {
                if(array_capacity<=stack_size){
                        int *newval=new int[array_capacity+1];
                        for(size_t i=0;i<stack_size;++i){
                                newval[i]=values[i];
                        }
                        array_capacity=array_capacity+1;
                        delete [] values;
                        values=newval;
                }
                values[stack_size++]=val;
        }

int stack::peek() const
        {
                if(stack_size==0){
                        throw std::invalid_argument("The stack is empty.");
                } else {
                        return values[stack_size-1];
                }
        }

void stack::pop()
        {
                if(stack_size==0){
                        throw std::invalid_argument("The stack is empty.");
                } else {
                        stack_size--;
                }
        }

void stack::clear()
        {
                stack_size = 0;
        }

size_t stack::size() const
        {
                return stack_size;
        }
bool stack::empty() const
        {
                if(stack_size == 0) {
                        return true;
                } else
                        return false;
        }

stack::~stack(){
        delete [] values;
}