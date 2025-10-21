cmake_minimum_required(VERSION 3.10.0)
project(Pr08Function VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Pr08Function
    main.cpp
    Complex.cpp
    functions.cpp
)
