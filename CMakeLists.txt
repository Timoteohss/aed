cmake_minimum_required(VERSION 3.9)
project(aed C)

set(CMAKE_C_STANDARD 99)

add_executable(aed main.c algoritmos/utilidades.h algoritmos/utilidades.c algoritmos/listaSimples.c algoritmos/listaSimples.h algoritmos/pilha.c algoritmos/pilha.h algoritmos/fila.c algoritmos/fila.h algoritmos/buscaBinaria.c algoritmos/buscaBinaria.h algoritmos/listaDupla.c algoritmos/listaDupla.h algoritmos/metodosOrdenacao.c algoritmos/metodosOrdenacao.h algoritmos/arvoreBinaria.c algoritmos/arvoreBinaria.h algoritmos/arvoreAVL.c algoritmos/arvoreAVL.h algoritmos/tabelaHash.c algoritmos/tabelaHash.h)
add_executable(hanoi hanoi.c algoritmos/utilidades.h algoritmos/utilidades.c algoritmos/pilha.h algoritmos/pilha.c algoritmos/listaSimples.c algoritmos/listaSimples.h)
add_executable(trabalhoPAA trabalhoPAA.c algoritmos/utilidades.c algoritmos/utilidades.h algoritmos/metodosOrdenacao.c algoritmos/metodosOrdenacao.h algoritmos/fila.c algoritmos/fila.h algoritmos/listaDupla.c algoritmos/listaDupla.h)
