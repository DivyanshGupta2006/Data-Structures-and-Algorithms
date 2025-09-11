cmake_minimum_required(VERSION 3.31)
project(Data_Structure_and_Algorithm)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(Data_Structure_and_Algorithm_main
        main.cpp
)
add_executable(Data_Structure_and_Algorithm_test
        test/test.cpp
        test/test_Heaps.cpp
        test/test_LinkedLists.cpp
        test/test_Sorts.cpp
        test/test_Queues.cpp
        test/test_Stacks.cpp
        test/test_Trees.cpp
)
