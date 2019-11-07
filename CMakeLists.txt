cmake_minimum_required(VERSION 3.0)

# project name
project(money VERSION 1.0.0)

# list of library sources
set(SOURCE_LIB currency.cpp initializers.cpp money.cpp)

 # build 'money' static library
add_library(money STATIC ${SOURCE_LIB})
