cmake_minimum_required(VERSION 3.26)
project(lab2_sorting_algorithms)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

add_executable(
        lab2_sorting_algorithms
        main.cpp
        data/DataGenerator.cpp
        utility/SortUtils.h
        utility/GUI.h
        tests/TestSorts.h
        tests/TestSorts.cpp
        utility/Console.h
        utility/Console.cpp
)

target_link_libraries(lab2_sorting_algorithms PRIVATE Qt6::Core Qt6::Widgets)