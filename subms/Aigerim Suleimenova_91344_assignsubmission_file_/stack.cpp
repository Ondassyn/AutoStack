#include <stdexcept>
#include <ostream>
#include "stack.h"
#include <iostream>

using namespace std;

//stack::stack() : //def
  //      values(new int[12]),
    //    stack_size(0),
      //  array_capacity(5)
//{

//}
stack::stack(const stack& stk):  //cpy const
stack_size(stk.stack_size),
array_capacity(stk.array_capacity),
values{new int[stk.array_capacity]}
{

    for(size_t i=0; i<stk.stack_size; i++){
        values[i] = stk.values[i];
    }
}

stack::stack(std::initializer_list<int> ilist):
stack_size(ilist.size()), array_capacity(ilist.size()){
   values = new int[array_capacity];
size_t i=0;
for(int val : ilist){
   values[i] = val;
    ++i;
}
}
stack& stack::operator=(const stack& stk)
{
//if(&stk!=this){
  //  return *this;
//}
if(stack_size !=stk.stack_size ) { // check for self-assignment : if x=x if so you deallocATE  program will crash
   delete [] values;
    stack_size = stk.stack_size; //resizing obj
    values=new int[stack_size];  // create new space
    array_capacity=stack_size;
}
    for (size_t i = 0; i < stack_size; ++i)
    {
        values[i] = stk.values[i];
    }
    return *this; //enables x=y=z
}


void stack::push(int val){
    if( array_capacity-1 <stack_size)
    {
        if( stack_size < 2 * array_capacity )
            array_capacity = 2 * array_capacity;

        int* newdata = new int[ array_capacity ];
        for( size_t i = 0; i < stack_size; ++ i )
            newdata[i] = values[i];
        delete[] values;
        values = newdata;
    }

        values[stack_size] = val;
        ++stack_size;
}


int stack::peek() const{

    if(!empty()){
        return values[stack_size-1];
    }else
        throw  invalid_argument("a");
}
void stack::pop() {
    if (!empty()) {
        stack_size--;
    } else {
        throw invalid_argument("a");
    }
}
void stack::clear() { //not allocate memory
    stack_size=0;
}

size_t stack::size() const {
    return  stack_size;
}

bool stack::empty()const{
    return (stack_size==0);


}


stack::~stack(){
    delete [] values;
}