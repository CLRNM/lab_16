cmake_minimum_required(VERSION 3.28)
project(lab_16 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab_16 main.c
        data_structures/matrix/matrix.c
        data_structures/matrix/matrix.h
        algorithms/algorithms.c
        algorithms/algorithms.h)
