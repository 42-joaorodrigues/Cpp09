cmake_minimum_required(VERSION 3.31)
project(09)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex00 CPP_Module_09/ex00/main.cpp
		CPP_Module_09/ex00/BitcoinExchange.cpp
		CPP_Module_09/ex00/BitcoinExchange.hpp
		CPP_Module_09/ex00/Makefile)
