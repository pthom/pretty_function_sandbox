cmake_minimum_required(VERSION 3.2)

project(PrettyFunctionSandbox LANGUAGES CXX)

message("CMAKE_CXX_COMPILER_ID is ${CMAKE_CXX_COMPILER_ID}")
message("CMAKE_CXX_COMPILER_VERSION is ${CMAKE_CXX_COMPILER_VERSION}")

# add_executable(type_name_stringliteral_test type_name_stringliteral_test.cpp)
# target_include_directories(type_name_stringliteral_test PRIVATE
#     ${CMAKE_SOURCE_DIR})
# set_property(TARGET type_name_stringliteral_test PROPERTY CXX_STANDARD 14)
# install(TARGETS type_name_stringliteral_test DESTINATION ${CMAKE_BINARY_DIR})

add_executable(xqms_test xqms_test.cpp)
target_include_directories(xqms_test PRIVATE ${CMAKE_SOURCE_DIR})
set_property(TARGET xqms_test PROPERTY CXX_STANDARD 14)
install(TARGETS xqms_test DESTINATION ${CMAKE_BINARY_DIR})
