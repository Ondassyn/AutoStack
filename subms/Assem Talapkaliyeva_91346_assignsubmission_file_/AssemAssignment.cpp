#include "stack.h"
    // Copy constructor
    stack:: stack(const stack& stk)
 {
    values=new int [stk.array_capacity];
    stack_size=stk.stack_size;
    array_capacity=stk.array_capacity;
    for (size_t a=0; a<stk.stack_size; ++a) 
{
        values[a]=stk.values[a];
    }
}
    // Initializer list constructor
    stack:: stack(std::initializer_list<int> ilist)
{
    stack_size = ilist.size();
    array_capacity = 2*stack_size;
    values = new int [array_capacity];
    int a = 0;
    for (double b :ilist)                                                                              {
        values[a] = b;
        a=a+1;
    }
}
    // Copy assignment
    stack& stack:: operator = (const stack& stk){
    if (this == &stk) {
        return *this;
    }
    if (array_capacity==stk.array_capacity) {
	for( size_t a = 0; a<stack_size; ++a){
            values[a] = stk.values[a];
        }
    } else{
        delete [] values;
        array_capacity = stk.array_capacity;
        stack_size = stk.stack_size;
        values = new int [array_capacity];
        for( size_t a = 0; a<stack_size; ++a ){
            values[a] = stk.values[a];
        }
    }
    return *this;
}
    
    // Insert an item at the top of the stack
    void stack:: push(int val){
    if (stack_size != array_capacity) {
	 values[stack_size]=val;
        ++stack_size;
    } else{
       array_capacity = 2 * array_capacity;
        int* newValues = new int[array_capacity];
        for (size_t a = 0; a < stack_size; ++a){
            newValues[a] = values[a];
        }
        delete[] values;
        values = newValues;
        values[stack_size]=val;
        ++stack_size;
    }
}
    
    // Returns the value of the topmost item of the stack;
    // throws an exception if the stack is empty
    int stack:: peek() const{
    if (stack_size == 0) {
        throw std::invalid_argument("Stack is empty. Can not return the value of the topmost item");
    }
    return values[stack_size-1];
}


// Remove the topmost item from the stack
// throws an exception if the stack is empty
void stack:: pop(){
    if (stack_size == 0) {
	throw std::invalid_argument("Stack is empty. Can not remove the topmost item");
    }
    stack_size = stack_size - 1;
}

    // Remove everything from the stack
    void stack:: clear() {
    stack_size = 0;
}

    // Returns the number of items on the stack
    size_t stack:: size() const{
    return stack_size;
}
    // Returns whether or not the stack is currently empty
    bool stack:: empty() const{
    if(stack_size == 0){
        return true;
    } else{
        return false;
    }
}
    
    
    // Destructor
    stack:: ~stack(){
    delete [] values;
}

