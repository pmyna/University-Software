cmake_minimum_required(VERSION 3.21)
project(Homework)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(fasta_io
        fasta_io.cpp
        Reads.h
        AsianElefant_CytochromeB.fasta)
