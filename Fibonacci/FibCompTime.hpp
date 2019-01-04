#ifndef FIBCOMPTIME__HPP_
#define FIBCOMPTIME__HPP_

#include <array>
#include <utility>

namespace fib {
namespace v1 {
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

template<size_t ... I>
unsigned long fib_impl(std::index_sequence<I...>, const unsigned long i)
{
    constexpr std::array<unsigned long, sizeof ...(I)> a =
    {Fib<I>::value... };

    return a[i];
}

unsigned long fib(const unsigned long i)
{
    return fib_impl(std::make_index_sequence<67>(), i);
}

} //namespace v1
} //namespace fib

#endif // FIBCOMPTIME__HPP_
