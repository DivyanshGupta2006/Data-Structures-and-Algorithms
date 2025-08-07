cmake_minimum_required(VERSION 3.31)
project(Data_Structure_and_Algorithm)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(Data_Structure_and_Algorithm main.cpp
        main.cpp
        src/LinkedList.cpp)
