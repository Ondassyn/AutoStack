#include <ostream>
#include"stack.h"
	// Copy constructor
stack::stack(const stack& stk): 
			  
		      array_capacity(stk.array_capacity),
		      stack_size(stk.stack_size),
		      values(new int[stk.array_capacity])	
			 
			{
		     for(size_t n=0; n < stk.stack_size; ++n){                      
			  values[n] = stk.values[n];
		}
		}


	// Initializer list constructor
stack::stack(std::initializer_list<int> ilist)   {            
				    stack_size=ilist.size();
		            array_capacity = 2*stack_size;
		            values=new int[array_capacity];  
		  
		  size_t n = 0;
		  for(int m : ilist){
			  values[n] = m;
			 n++;
		}
		}
		
	// Copy assignment
stack& stack::operator=(const stack& stk){
		
		  if(array_capacity != stk.array_capacity){
		             delete [] values;
		            array_capacity=stk.array_capacity;
		            stack_size = stk.stack_size;

		            values = new int[stk.array_capacity];
		            
		            for(size_t n=0; n < stk.stack_size; ++n){ 
				    values[n] = stk.values[n]; } }
		   else{ 
		           size_t n;
		           do{
		            values[n] = stk.values[n];
		            ++n;
		             }while(n<stk.stack_size); } 

		  if(this == &stk){
		       return *this;}

     return *this;}    
	
		
		
	// Insert an item at the top of the stack 
void stack::push(int val){
		    if(stack_size == array_capacity){
		       array_capacity *= 2; 
		       int* arr_new = new int[array_capacity];
		       
		
		   size_t n = 0;
		     do{
		        arr_new[n] = values[n];
		        ++n;
		       }while(n<stack_size);

		        delete[] values;
		        values = arr_new;
		        values[stack_size] = val;
		        ++stack_size;
	 }
		     else{
		            values[stack_size] = val;
		            ++stack_size;}	
                                              }
		
	// Returns the value of the topmost item of the stack;
	// throws an exception if the stack is empty
int stack::peek() const{
				if(stack_size==0){
				 throw std::invalid_argument("Stack given is empty!!!!"); }      
		         
			   return values[stack_size-1];
		}
		
	// Remove the topmost item from the stack
	// throws an exception if the stack is empty
void stack::pop(){
		         if(stack_size == 0){
		          throw std::invalid_argument("You can't pop from empty stack!!!!");}
		         
				 stack_size--; }
			 
	// Remove everything from the stack                                  
void stack::clear(){
				 stack_size = 0;}


		
	// Returns the number of items on the stack                        
size_t stack::size() const{
				   return stack_size; }


		
	// Returns whether or not the stack is currently empty
bool stack::empty() const{
				    if(stack_size==0){
		                return true; }  
		            else{
		                return false; }
		                              }
stack::~stack(){
		    delete[] values; 
	}
