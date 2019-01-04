#ifndef RUNTIME__HPP_
#define RUNTIME__HPP_

#include <iostream>
namespace fib {
namespace rt {

unsigned long fib(unsigned long index)
{
    volatile unsigned long Current = 0;
    unsigned long Prev1 = 1;
    unsigned long Prev2 = 0;

    for(unsigned long CurrentIndex = 1; index > CurrentIndex; ++CurrentIndex)
    {
        Current = Prev1 + Prev2;
        Prev2 = Prev1;
        Prev1 = Current;
    }
    return Current;
}

unsigned long fib_recursive(unsigned int index)
{
    const unsigned long Result = (3 > index)? 1 : fib_recursive(index-2) + fib_recursive(index-1);
    return Result;
}

} //namespace rt
} //namespace fib

#endif // RUNTIME__HPP_
