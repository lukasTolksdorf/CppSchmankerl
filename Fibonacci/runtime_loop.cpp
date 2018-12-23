#include <iostream>

int Fib(int Index)
{
    int current = 0;
    int prev1 = 1;
    int prev2 = 0;

    for(int currentIndex = 1; Index > currentIndex; ++currentIndex)
    {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

int main()
{
    std::cout<<Fib(46)<<"\n";
    return 0;
}
