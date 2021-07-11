cmake_minimum_required(VERSION 3.13)
project(Greeters)

add_executable(main greeter.cpp person.cpp main.cpp)
add_executable(greeter-ut test/greeter.ut.cpp person.cpp greeter.cpp)