#ifndef STACKARRAY_HPP
#define STACKARRAY_HPP

class StackArray
{
  private:
    int *array;
    int array_size;
    int top;      // define top index var

  public:
    StackArray();      // constructor
    ~StackArray();     // destructor
  
    void push(int k);
    void pop();
    int peek();

    bool isEmpty(); // helper function
    bool isFull(); // helper function

};

#endif
