#include "stack.h"

stack::stack(const stack& stk):
	stack_size( stk.stack_size ),
	array_capacity( stk.array_capacity ),
   values( new int[ stk.array_capacity ] )
{
    for( size_t j = 0; j < stack_size; ++j )
    {
        values[ j ] = stk.values[ j ];
    }
}

stack::stack(std::initializer_list<int> ilist):
	stack_size( ilist.size() ),
	array_capacity( ilist.size() ),
	values( new int[ ilist.size() ] )
{
    size_t j = 0;
    for( int value : ilist )
    {
        values[ j++ ] = value;
    }
}

stack& stack::operator=(const stack& stk)
{
   if( stack_size == stk.stack_size )
   {
      for( size_t j = 0; j < stack_size; ++j )
      {
       	values[ j ] = stk.values[ j ];
   	}
	}
   else
   {
      // reallocate memory for the values array
      delete[] values;
      values = new int[ array_capacity ];
      array_capacity = stk.array_capacity;
      stack_size = stk.stack_size;

   	for( size_t j = 0; j < stack_size; ++j )
      {
       	values[ j ] = stk.values[ j ];
   	}
   }

   return *this;
}

void stack::push(int val)
{

	if( array_capacity == stack_size )
   {
		array_capacity = 2 * array_capacity;
		int *temp_values = new int[ array_capacity ];

		for( size_t j = 0; j < stack_size; j++)
      {
			temp_values[ j ] = values[ j ];
		}

		delete[] values;
		values = temp_values;
	}
    values[ stack_size ] = val;
    ++stack_size;
}

int stack::peek() const
{
	if( empty() )
   {
      throw std::runtime_error( "peek_exception: stack is empty\n" );
   }
   return values[stack_size - 1];
}

void stack::pop()
{
	if( empty() )
   {
      throw std::runtime_error( "pop_exception: stack is empty\n" );
   }
   --stack_size;
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
    return (stack_size == 0);
}

stack::~stack() {
	delete[] values;
}
