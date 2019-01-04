cmake_minimum_required(VERSION 3.12)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)
add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googlebenchmark" "extern/googlebenchmark")

add_subdirectory("${PROJECT_SOURCE_DIR}/Fibonacci/benchmark")
