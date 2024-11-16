#include <iostream>
#include "StackARR.h"
#include "StackLL.h"


int main()
{
    StackLL stack;
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.PrintStack();
    stack.Pop();
    stack.PrintStack();

}
