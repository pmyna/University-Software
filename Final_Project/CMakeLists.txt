cmake_minimum_required(VERSION 3.21)
project(Final_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Final_Project
        main.cpp Person.cpp Person.h Student.cpp Student.h Vorlesung.cpp Vorlesung.h Professor.cpp Professor.h Studium.cpp Studium.h)
