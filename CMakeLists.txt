cmake_minimum_required(VERSION 3.15)

# project name
project(money VERSION 1.0.0 LANGUAGES CXX)

# set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Conan integration
find_package(PkgConfig QUIET)

# list of library sources
set(SOURCE_LIB currency.cpp initializers.cpp money.cpp)

# build 'money' library
add_library(money ${SOURCE_LIB})

# Set library properties
target_include_directories(money 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(money PUBLIC cxx_std_17)

# Add alias for namespaced target
add_library(money::money ALIAS money)

# Installation
include(GNUInstallDirs)
install(TARGETS money
    EXPORT money-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES money.hpp currency.hpp
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT money-targets
    FILE money-targets.cmake
    NAMESPACE money::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/money
)

# Generate config files
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    money-config-version.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/money-config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/money-config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/money
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/money-config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/money-config-version.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/money
)

# Testing
option(BUILD_TESTING "Build tests" ON)
if(BUILD_TESTING)
    # Try to find Catch2, if not found, fetch it
    find_package(Catch2 QUIET)
    
    if(NOT Catch2_FOUND)
        include(FetchContent)
        FetchContent_Declare(
            catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG v3.11.0
        )
        FetchContent_MakeAvailable(catch2)
    endif()
    
    add_executable(money_tests
        tests/money_tests.cpp
        tests/currency_tests.cpp
    )
    
    if(TARGET Catch2::Catch2WithMain)
        target_link_libraries(money_tests PRIVATE Catch2::Catch2WithMain money)
    else()
        target_link_libraries(money_tests PRIVATE catch2::catch2_with_main money)
    endif()
    
    target_compile_features(money_tests PRIVATE cxx_std_17)
    
    include(CTest)
    add_test(NAME money_tests COMMAND money_tests)
endif()
