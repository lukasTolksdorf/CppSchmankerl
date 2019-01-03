#include <iostream>

unsigned long Fib(unsigned long Index)
{
    volatile unsigned long current = 0;
    unsigned long prev1 = 1;
    unsigned long prev2 = 0;

    for(unsigned long currentIndex = 1; Index > currentIndex; ++currentIndex)
    {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

int main()
{
    for(size_t i = 0; 66>= i; ++i)
    {
        std::cout<<Fib(i)<<"\n";
        std::cout<<Fib(66-i)<<"\n";
    }
    return 0;
}
