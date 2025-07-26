cmake_minimum_required(VERSION 3.31)
project(09)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex00 CPP_Module_09/ex00/main.cpp
		CPP_Module_09/ex00/BitcoinExchange.cpp
		CPP_Module_09/ex00/BitcoinExchange.hpp
		CPP_Module_09/ex00/Makefile)
add_executable(ex01 CPP_Module_09/ex01/RPN.cpp CPP_Module_09/ex01/RPN.hpp
		CPP_Module_09/ex01/main.cpp)
add_executable(ex02 CPP_Module_09/ex02/main.cpp CPP_Module_09/ex02/Makefile
		CPP_Module_09/ex02/PmergeMe.cpp
		CPP_Module_09/ex02/PmergeMe.hpp)
