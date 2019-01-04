#include <benchmark/benchmark.h>

#include "../FibCompTime.hpp"
#include "../FibCompTimeConstexpr.hpp"
#include "../runtime.hpp"

static void BM_GetFibNumber(benchmark::State& state)
{
    unsigned long Result = 0;
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(Result = fib::v1::fib(47));
    }

}

static void BM_GetFibNumberConstexpr(benchmark::State& state)
{
    unsigned long Result = 0;
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(Result = fib::v2::fib(47));
    }

}

static void BM_GetFibNumberConstexpr_static(benchmark::State& state)
{
    unsigned long Result = 0;
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(Result = fib::v2::fib_static(47));
    }

}

static void BM_GetFibNumberRtLoop(benchmark::State& state)
{
    unsigned long Result = 0;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(Result = fib::rt::fib(47));
    }
}

static void BM_GetFibNumberRtRecursive(benchmark::State& state)
{
    unsigned long Result = 0;

    for (auto _ : state)
    {
        benchmark::DoNotOptimize(Result = fib::rt::fib_recursive(27));
    }
}

BENCHMARK(BM_GetFibNumber);
BENCHMARK(BM_GetFibNumberConstexpr);
BENCHMARK(BM_GetFibNumberConstexpr_static);
BENCHMARK(BM_GetFibNumberRtLoop);
BENCHMARK(BM_GetFibNumberRtRecursive);

BENCHMARK_MAIN();
