#include <iostream>
#include <array>
#include <utility>

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

template<size_t ... I>
int fib_impl(std::index_sequence<I...>, const int i)
{
    constexpr std::array<int, sizeof ...(I)> a =
    {Fib<I>::value... };

    return a[i];
}

int fib(const int i)
{
    return fib_impl(std::make_index_sequence<47>(), i);
}

int main()
{
    std::cout<<fib(46)<<"\n";
    return 0;
}

