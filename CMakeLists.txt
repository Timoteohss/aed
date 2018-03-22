cmake_minimum_required(VERSION 3.9)
project(aed C)

set(CMAKE_C_STANDARD 99)

add_executable(aed main.c algoritmos/utilidades.h algoritmos/utilidades.c algoritmos/listaSimples.c algoritmos/listaSimples.h algoritmos/pilha.c algoritmos/pilha.h)