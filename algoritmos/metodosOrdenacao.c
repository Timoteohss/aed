//
// Created by timoteo on 26/03/18.
//

#include <stdlib.h>
#include "fila.h"
#include "limits.h"
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

void bubbleSort(int *A, int tamanho) {
    int i, j;

    for(i = 0; i < tamanho - 1; i++) {
        for(j = 0; j < tamanho - 1 - i; j++) {
            if (A[j] > A[j+1]) troca(&A[j], &A[j+1]);
        }
    }
}

void selectionSort(int *A, int tamanho) {

    for(int i = 0; i < tamanho - 1; i ++) {
        int index_minimo = i;

        for(int j = i + 1; j < tamanho; j++)
            if(A[j] < A[index_minimo]) index_minimo = j;

        troca(&A[index_minimo], &A[i]);
    }
}

void mergeA(int *A, int baixo, int meio, int alto) {
    int i;
    int *tmp;

    Fila *f1 = criaFila();
    Fila *f2 = criaFila();

    for(i = baixo; i <= meio; i++) {
        tmp = (int *)malloc(sizeof(int));
        *tmp = A[i];
        enfilera(f1, tmp);
    }

    for(i = meio + 1; i <= alto; i++) {
        tmp = (int *)malloc(sizeof(int));
        *tmp = A[i];
        enfilera(f2, tmp);
    }

    i = baixo;
    while(!filaEstaVazia(f1) && !filaEstaVazia(f2)) {

        int val1 = verFinalDaFila(f1) ? *(int*)verFinalDaFila(f1) : INT_MAX;
        int val2 = verFinalDaFila(f2) ? *(int*)verFinalDaFila(f2) : INT_MAX;

        if(val1 <= val2) {
            A[i++] = *(int *)desenfila(f1);
        } else {
            A[i++] = *(int *)desenfila(f2);
        }
    }

    while(!filaEstaVazia(f1)) A[i++] = *(int *)desenfila(f1);
    while(!filaEstaVazia(f2)) A[i++] = *(int *)desenfila(f2);

    deletaFila(f1);
    deletaFila(f2);
}

void mergeSort(int *A, int baixo, int alto) {
    int meio;

    if( baixo < alto ) {
        meio = (int)((baixo+alto)/2);
        mergeSort(A, baixo, meio);
        mergeSort(A, meio+1,alto);

        mergeA(A,baixo,meio,alto);
    }
}

int escolhePivo (int baixo, int alto) { return alto; }

int particiona(int *A, int baixo, int alto) {
    int i;
    int indexPivo = escolhePivo(baixo,alto);
    int valorPivo = A[indexPivo];
    int posicao = baixo;

    troca(&A[alto], &A[indexPivo]);

    for(i = baixo; i < alto; i++) {
        if(A[i] < valorPivo) {
            troca(&A[i], &A[posicao]);
            posicao++;
        }
    }

    troca(&A[posicao], &A[indexPivo]);
    return posicao;



}

void quickSort(int *A, int baixo, int alto) {
    if(baixo < alto) {
        int p = particiona(A,baixo,alto);
        quickSort(A, baixo, p - 1);
        quickSort(A, p + 1, alto);
    }
}



