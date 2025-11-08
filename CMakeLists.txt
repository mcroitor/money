cmake_minimum_required(VERSION 3.10)

# project name
project(money VERSION 1.0.0)

# set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include directories
include_directories(${PROJECT_SOURCE_DIR})

# list of library sources
set(SOURCE_LIB currency.cpp initializers.cpp money.cpp)

# build 'money' static library
add_library(money STATIC ${SOURCE_LIB})

# unit tests
# catch2 is required
include(FetchContent)
FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(catch2)

add_executable(money_tests
    tests/money_tests.cpp
)

target_link_libraries(money_tests PRIVATE Catch2::Catch2WithMain money)
target_compile_features(money_tests PRIVATE cxx_std_11)

include(CTest)
add_test(NAME money_tests COMMAND money_tests)
