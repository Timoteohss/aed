//
// Created by timoteo on 26/03/18.
//

#include "metodosOrdenacao.h"
#include "utilidades.h"

void insertionSort(int *A, int tamanho) {
    int i, j;

    for(i = 1; i < tamanho; i++) {
        j = i;
        while(A[j] < A[j - 1] && j > 0) {
            troca(&A[j], &A[j-1]);
            j = j - 1;
        }
    }
}