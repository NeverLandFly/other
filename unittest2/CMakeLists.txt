cmake_minimum_required( VERSION 3.5)
project(unittest2)

list(APPEND CMAKE_MODULE_PATH /home/neverland/eos/libraries/fc/CMakeModules)
list(APPEND CMAKE_MODULE_PATH /home/neverland/eos/CMakeModules)

find_package(Secp256k1 REQUIRED)