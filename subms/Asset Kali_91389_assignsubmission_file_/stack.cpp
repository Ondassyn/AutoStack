#include "stack.h"
#include <exception>
#include <iostream>

//        int *values;
//        size_t stack_size;
//        size_t array_capacity;


// Copy constructor
stack::stack(const stack& stk): values(stk.values), stack_size(stk.stack_size), array_capacity(stk.array_capacity)
{
};

// Initializer list constructor
stack::stack(std::initializer_list<int> ilist): stack_size(ilist.size()), array_capacity(ilist.size()*2), values(new int(ilist.size())) 
{
};

// Copy assignment
stack& stack::operator=(const stack& stk)
{
	this->values=stk.values;
	this->stack_size=stk.stack_size;
	this->array_capacity=stk.array_capacity;
	return *this;
};

// Insert an item at the top of the stack
void stack::push(int val)
{
	// if we cant add items
	if (this->array_capacity > this->stack_size)
	{
		int index=this->stack_size;
		this->values[index]=val;
		this->stack_size++;
	} else 
	{
		int doubleindex = this->stack_size*2;
		int* bigger_array=new int[doubleindex];
		int i = 0;
		while(i != this->stack_size)
		{
			bigger_array[i]=values[i];
			i++;
		}
		bigger_array[i]=val;
		delete values;
		values = bigger_array;
		this->stack_size++;
	}
};

// Returns the value of the topmost item of the stack;
// throws an exception if the stack is empty
int stack::peek() const
{
	int index = this->stack_size;
	if (index != 0)
	{
		index--;
		return this->values[index];
	} else 
	{
		throw std::invalid_argument("Exception! EMPTY STACK");
	}
};

// Remove the topmost item from the stack
// throws an exception if the stack is empty
void stack::pop()
{
	int index=this->stack_size;
	if (index != 0)
	{
		this->values[index]=0;
		this->stack_size--;
	} else 
	{
		throw std::invalid_argument("Exception! EMPTY STACK");
	}
};

// Remove everything from the stack
void stack::clear()
{
	int index=this->stack_size;
	while(index>=0)
	{
		this->values[index]=0;
		index--;
	}
	this->stack_size=0;
};

// Returns the number of items on the stack
size_t stack::size() const
{
	return this->stack_size;
};

// Returns whether or not the stack is currently empty
bool stack::empty() const
{
	int index=this->stack_size;
	bool equal_to_zero=index==0;
	return equal_to_zero;
};

// Destructor
stack::~stack()
{
	delete values;
};
