#ifndef FIBCOMPTIMECONSTEXPR_HPP_
#define FIBCOMPTIMECONSTEXPR_HPP_

#include <array>
#include <utility>

namespace fib {
namespace v2 {

constexpr unsigned long fib_impl(unsigned int index)
{
    const unsigned long Result = (3 > index)? 1 : fib_impl(index-2) + fib_impl(index-1);

    return Result;
}

template <size_t ...I>
constexpr std::array<unsigned long, sizeof...(I)> generateFibArray(std::index_sequence<I...>)
{
    const std::array<unsigned long, sizeof...(I)> Result = {fib_impl(I)...};
    return Result;
}

const unsigned long fib(unsigned int index)
{
    constexpr std::array<unsigned long, 47> Values = generateFibArray(std::make_index_sequence<47>());
    return Values[index];
}

const unsigned long fib_static(unsigned int index)
{
    constexpr std::array<unsigned long, 47> Values = generateFibArray(std::make_index_sequence<47>());
    return Values[index];
}

} //namespace v2
} //namespace fib

#endif // FIBCOMPTIMECONSTEXPR__HPP_
