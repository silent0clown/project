cmake_minimum_required(VERSION 3.12)
project(CMakeTemplate VERSION 1.0.0 LANGUAGES C CXX DESCRIPTION "A cmake  project")

# Specified the language standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)


##--------------------- Compile Options ------------------------------------##
# Configure compile options
# add_compile_options(-Wall -Wextra -pedantic -Werror)
add_compile_options(-Wall -Wextra -pedantic)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe -std=c99")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -std=c++11")

# Compile options for Debug variant
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
# Compile options for Release variant
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O2")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

message(STATUS "Compile options for c: ${CMAKE_C_FLAGS}")
message(STATUS "Compile options for c++: ${CMAKE_CXX_FLAGS}")

# Set build type
set(CMAKE_BUILD_TYPE Debug)
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

##--------------------- Include directories --------------------------------##
include_directories(src/)

##--------------------- Source files ---------------------------------------##
file(GLOB_RECURSE MEM_LIB_SRC
    src/memory/*.c
)
add_library(mempool STATIC ${MEM_LIB_SRC})
##--------------------- Build unit tests -----------------------------------##

add_executable(demo src/main.c)
target_link_libraries(demo mempool)
##--------------------- Build unit tests -----------------------------------##
# option(CMAKE_TEMPLATE_ENABLE_TEST "Whether to enable unit tests" OFF)
# if (CMAKE_TEMPLATE_ENABLE_TEST)
#     message(STATUS "Unit tests enabled")
#     enable_testing()
#     add_subdirectory(third_party/googletest-release-1.10.0 EXCLUDE_FROM_ALL)
#     include_directories(third_party/googletest-release-1.10.0/googletest/include)


#     add_executable(test_gtest_demo test/test_gtest_demo.cpp)

#     add_test(NAME test_gtest_demo COMMAND test_gtest_demo)
# endif()