cmake_minimum_required( VERSION 3.5 )

project( unittest2 )

list(APPEND CMAKE_MODULE_PATH "/home/neverland/eos/libraries/fc/CMakeModules")
list(APPEND CMAKE_MODULE_PATH "/home/neverland/eos/CMakeModules")


set(CMAKE_CXX_STANDARD 14)
set(BOOST_ROOT /home/neverland/opt/boost)
set(Boost_INCLUDE_DIR /home/neverland/opt/boost/include)
set(Boost_LIBRARY_DIR /home/neverland/opt/boost/lib)
set(OPENSSL_ROOT_DIR /usr/include/openssl)

include_directories(${Boost_INCLUDE_DIR})
include_directories(/home/neverland/eos/libraries/testing/include)
include_directories(/home/neverland/eos/build/contracts)
include_directories(/home/neverland/eos/libraries/wasm-jit/Include)
include_directories(/home/neverland/eos/libraries/fc/include)
include_directories(/home/neverland/eos/libraries/chain/include)
include_directories(/home/neverland/eos/libraries/chainbase/include)
include_directories(/home/neverland/eos/build/libraries/chain/include)
include_directories(/home/neverland/eos/libraries/softfloat/source/include)

#link_libraries(/home/neverland/eos/build/libraries/chain/libeosio_chain.a)
#link_libraries(/home/neverland/eos/build/libraries/chainbase/libchainbase.a)
#link_libraries(/home/neverland/eos/build/libraries/testing/libeosio_testing.a)
#link_libraries(/home/neverland/eos/build/libraries/utilities/libeos_utilities.a)
#link_libraries(/home/neverland/eos/build/libraries/abi_generator/libabi_generator.a)
#link_libraries(/home/neverland/eos/build/libraries/fc/libfc.a)


add_executable(unittest2 multi_index_tests.cpp)

target_link_libraries( unittest2 /home/neverland/eos/build/libraries/chain/libeosio_chain.a
        /home/neverland/eos/build/libraries/chainbase/libchainbase.a
        /home/neverland/eos/build/libraries/testing/libeosio_testing.a
        /home/neverland/eos/build/libraries/utilities/libeos_utilities.a
        /home/neverland/eos/build/libraries/abi_generator/libabi_generator.a
        /home/neverland/eos/build/libraries/fc/libfc.a
        /home/neverland/opt/boost/lib/libboost_unit_test_framework.a
        /home/neverland/opt/boost/lib/libboost_filesystem.a
        /home/neverland/opt/boost/lib/libboost_system.a
        /home/neverland/opt/boost/lib/libboost_chrono.a
        /home/neverland/opt/boost/lib/libboost_date_time.a
        /usr/local/lib/libsecp256k1.a
        /usr/lib/x86_64-linux-gnu/libcrypto.a
        /usr/lib/x86_64-linux-gnu/libpthread.a
        /usr/lib/x86_64-linux-gnu/libc.a
        /usr/lib/x86_64-linux-gnu/libdl.a
        )