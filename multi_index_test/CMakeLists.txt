cmake_minimum_required(VERSION 3.12)
project(multi_index_test)

set(CMAKE_CXX_STANDARD 14)

set(Boost_INCLUDE_DIR /home/neverland/opt/boost/include)
set(Boost_LIBRARY_DIR /home/neverland/opt/boost/lib)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIR})
include_directories(/home/neverland/eos/libraries/testing/include)
include_directories(/home/neverland/eos/build/contracts)
include_directories(/home/neverland/eos/libraries/wasm-jit/Include)
include_directories(/home/neverland/eos/libraries/fc/include)

add_library(multi_index_test multi_index_tests.cpp)