cmake_minimum_required(VERSION 3.12)
project(unittest2)

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling tests with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

find_package(LLVM 4.0 REQUIRED CONFIG)
link_directories(${LLVM_LIBRARY_DIR})

set(CMAKE_CXX_STANDARD 14)

set(Boost_INCLUDE_DIR /home/neverland/opt/boost/include)
set(Boost_LIBRARY_DIR /home/neverland/opt/boost/lib)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIR})
include_directories(/home/neverland/eos/libraries/testing/include)
include_directories(/home/neverland/eos/build/contracts)
include_directories(/home/neverland/eos/libraries/wasm-jit/Include)
include_directories(/home/neverland/eos/libraries/fc/include)
include_directories(/home/neverland/eos/libraries/chain/include)
include_directories(/home/neverland/eos/libraries/chainbase/include)
include_directories(/home/neverland/eos/build/libraries/chain/include)
include_directories(/home/neverland/eos/libraries/softfloat/source/include)

link_libraries(/home/neverland/eos/build/libraries/chain/libeosio_chain.a)
link_libraries(/home/neverland/eos/build/libraries/chainbase/libchainbase.a)
link_libraries(/home/neverland/eos/build/libraries/testing/libeosio_testing.a)
link_libraries(/home/neverland/eos/build/libraries/utilities/libeos_utilities.a)
link_libraries(/home/neverland/eos/build/libraries/abi_generator/libabi_generator.a)
link_libraries(/home/neverland/eos/build/libraries/fc/libfc.a)


add_subdirectory(contracts)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/config.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/include/config.hpp ESCAPE_QUOTES)

add_executable(unittest2 multi_index_tests)

#target_link_libraries( unittest2 eosio_chain chainbase eosio_testing eos_utilities abi_generator fc ${PLATFORM_SPECIFIC_LIBS} )
#
#target_include_directories( unittest2 PUBLIC
#        ${CMAKE_SOURCE_DIR}/libraries/testing/include
#        ${CMAKE_SOURCE_DIR}/contracts
#        ${CMAKE_BINARY_DIR}/contracts
#        ${CMAKE_CURRENT_SOURCE_DIR}/contracts
#        ${CMAKE_CURRENT_BINARY_DIR}/contracts
#        ${CMAKE_CURRENT_BINARY_DIR}/include )