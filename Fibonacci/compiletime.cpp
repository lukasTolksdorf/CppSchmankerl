#include <iostream>

template<int Index>
struct Fib
{
    static const int value = Fib<Index-1>::value + Fib<Index-2>::value;
};

template<>
struct Fib<0>
{
    static const int value = 0;
};

template<>
struct Fib<1>
{
    static const int value = 1;
};


int main()
{
    std::cout<<Fib<46>::value<<"\n";
    return 0;
}

