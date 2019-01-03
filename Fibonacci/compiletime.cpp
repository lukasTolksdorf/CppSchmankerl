#include <iostream>

template<unsigned long Index>
struct Fib
{
    static const unsigned long value = Fib<Index-1>::value + Fib<Index-2>::value;
};

template<>
struct Fib<0>
{
    static const unsigned long value = 0;
};

template<>
struct Fib<1>
{
    static const unsigned long value = 1;
};


int main()
{
    std::cout<<Fib<66>::value<<"\n";
    return 0;
}

