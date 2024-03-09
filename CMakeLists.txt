cmake_minimum_required(VERSION 3.10)
project(SimCity VERSION 1.0)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(SimCity 
    main.cpp 
    commercial.cpp 
    file_reader.cpp 
    Goods.cpp 
    Grid.cpp 
    industrial.cpp 
    pollution.cpp 
    residential.cpp
) 
