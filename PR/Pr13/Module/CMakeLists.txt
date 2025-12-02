cmake_minimum_required(VERSION 3.28)
project(Pr13Module VERSION 0.1.0 LANGUAGES CXX)

# Enable the C++ module dependency scanner for Clang.
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "cxx_modules")
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)

add_executable(Pr13Module)
target_compile_features(Pr13Module PRIVATE cxx_std_20)

target_sources(Pr13Module
    PRIVATE
        main.cpp
        math.cpp
        Class.cpp
    PRIVATE
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
            math.ixx
            Class.ixx
)
