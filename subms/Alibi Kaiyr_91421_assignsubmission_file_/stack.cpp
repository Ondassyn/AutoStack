#include <ostream>
#include "stack.h"


	// Creates an empty stack
//g++ main.cpp stack.cpp stack.h -o main -std=c++11

	// Copy constructor
	//stack stk;
	//stk.push(2);
	//stack st = stk;
	stack::stack(const stack& stk):
	    values(new int [stk.array_capacity]),
	    stack_size(stk.stack_size),
        array_capacity(stk.array_capacity)
        {
            for (size_t i=0; i<stk.stack_size;++i){
                values[i]=stk.values[i];
            }


        }//stack news;
        //news = st
        //stack st = {2.3.456}
        //stack st({2.3.456})
	// Initializer list constructor
	stack::stack(std::initializer_list<int> ilist):
    values(new int [ilist.size()]),
	    stack_size(ilist.size()),
        array_capacity(ilist.size())
	    {
    size_t i = 0;
    for(int el : ilist){
        values[i] = el;
        i++;
	}

}
	// Copy assignment
	//st = stk = stk1
	stack& stack::operator=(const stack& stk){
        if(&stk!= this){
            delete[] values;
            array_capacity=stk.array_capacity;
            stack_size=stk.stack_size;
            values= new int[array_capacity];
        }
        for (size_t i=0; i<stack_size; ++i){
            values[i]=stk.values[i];
        }
        return *this;
	}

	// Insert an item at the top of the stack
	void stack::push(int val){
        if (stack_size == array_capacity){

            array_capacity=array_capacity*2;
            int *new_values=new int[array_capacity];
            for (size_t i=0;i<stack_size;++i){
                new_values[i]=values[i];

            }
            delete[]values;
            values=new_values;

        }
        values[stack_size]=val;
        ++stack_size;
	}




	// Returns the value of the topmost item of the stack;
	// throws an exception if the stack is empty
	int stack::peek() const{
        if(stack_size!=0){
            return values[stack_size-1];
        }else{
            throw "empty";
        }

	}

	// Remove the topmost item from the stack
	// throws an exception if the stack is empty
	void stack::pop(){
	    if(stack_size!=0){
            --stack_size;
	    } else{
	        throw "empty";
	    }


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

	// Print out the contents of the stack


	// Destructor
	stack::~stack(){
	delete[] values;
	}
