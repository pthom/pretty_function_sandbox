cmake_minimum_required(VERSION 3.2)

project(PrettyFunctionSandbox LANGUAGES CXX)

add_executable(type_name_stringliteral_test type_name_stringliteral_test.cpp)
target_include_directories(type_name_stringliteral_test PRIVATE
    ${CMAKE_SOURCE_DIR})
set_property(TARGET type_name_stringliteral_test PROPERTY CXX_STANDARD 14)
