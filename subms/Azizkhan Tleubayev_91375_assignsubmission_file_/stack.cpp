#include "stack.h"

stack::stack(const stack & stk):
		stack_size {stk.stack_size},
		array_capacity {stk.array_capacity},
		values{new int[array_capacity]}
		{
			for (size_t i=0; i < stack_size; i++) {
				values[i]=stk.values[i]; } }

stack& stack::operator =(const stack& stk)
{
	stack* a;
	size_t i=0;

	if(a->stack_size!=stk.stack_size) {
		delete[] values;
		a->stack_size=stk.stack_size;
		a->array_capacity=stk.array_capacity;
		a->values=new int[array_capacity];}

	for(i=0; i<stack_size; i++)
		a->values[i]=stk.values[i];
	return *a;
}

stack::stack(std::initializer_list <int> ilist)
{
   size_t i=0;
   stack_size=ilist.size();
   values=new int[array_capacity];
   for (double s:ilist) {
		values[i]=s;
		i++;}
   array_capacity=(stack_size*2);

}

int stack::peek() const
{
  if (stack_size==0) throw std::invalid_argument("Stack is empty"); else
  return values[stack_size-1];
}

void stack::push(int val)
{
	if( stack::stack_size == array_capacity )
	   {
	      int* newvalues = new int[stack_size*2 ];
	      for( size_t i = 0; i < stack::stack_size; ++ i )
	         newvalues[i] = stack::values[i];

	      stack::array_capacity = stack_size*2;
	      delete[] stack::values;
	      stack::values = newvalues;
	   }

	values[stack_size]=val;
	stack_size++;
}

void stack::pop()
{
  if (stack_size==0) throw std::invalid_argument("Stack is empty"); else
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


bool stack::empty( ) const
{
	if (stack_size!=0) {
		return false; } else
		return true;
}


stack::~stack()
{
 delete[] values;
}
