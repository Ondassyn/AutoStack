#include <iostream>
#include <deque>
#include "stack.h"
#include <math.h>
#include<stdexcept>
#include <ostream>


stack::stack():
    array_capacity(5),
    values(new int[5]),
    stack_size(0)
    {

    }



 stack::stack(const stack& stk):
   values(new int[stk.array_capacity]),
   stack_size(stk.stack_size),
   array_capacity(stk.array_capacity)
{
   for(size_t i=0; i<stk.stack_size; ++i){
    values[i]=stk.values[i];
   }
 }


stack::stack(std::initializer_list<int> ilist):
     stack_size(ilist.size()),
     values(new int[ilist.size()])

{
         size_t i=0;
         for(int val: ilist){
            values[i]=val;
            i++;
         }
}

stack& stack::operator=(const stack& stk){
    if(array_capacity!= stk.array_capacity){
        delete[]values;
        values=new int[array_capacity];
        array_capacity=stk.array_capacity;
    }
     stack_size=stk.stack_size;
     for(size_t i=0; i<stk.stack_size; i++){
         values[i]=stk.values[i];
     }

   return *this;
}

 void stack::push(int val){
     if(array_capacity<=stack_size)
        {
        int *newval =new int [2*array_capacity];
        array_capacity=2*array_capacity;
        for(size_t i=0; i<stack_size; i++){
         newval[i]=values[i];
     }
     delete[]values;
     values=newval;
     }
   values[stack_size]=val;
   stack_size++;
 }

 int stack::peek() const
 {
     if(empty()){
                throw std:: invalid_argument("The stack is currently empty!!!");
     }

            return values[stack_size - 1];

 }

 void stack::pop()
 {
     if(empty()){
                throw std:: invalid_argument("The stack is currently empty!!!");
     }

          stack_size--;

 }

void stack::clear()
{
    stack_size=0;
}

size_t stack::size() const
{
    return stack_size;
}


bool stack::empty() const
{
    return(stack_size==0);
}

void stack::print(std::ostream& out) const
{

        out << "[";
        for (size_t i = 0; i < stack_size; ++i) {
            if (i > 0) {
                out << ", ";
            }
            out << values[i];
        }
        out << "]";
    }

 stack::~stack()
{
  delete[]values;
}
