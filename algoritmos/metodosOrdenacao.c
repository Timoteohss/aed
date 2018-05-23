//
// Created by timoteo on 26/03/18.
//

#include <stdlib.h>
#include "fila.h"
#include "limits.h"
#include "metodosOrdenacao.h"
#include "utilidades.h"

void heapfica(int *A, int tamanho);

void bdown(int *A, int tamanho, int p);

int getFilhoEsq(int p);

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

void qSort(int *A, int baixo, int alto) {
    if(baixo >= alto) return;

    int esq, dir, pivo;
    pivo = A[baixo +(alto - baixo)/2];
    esq = baixo-1;
    dir = alto+1;

    while(esq <= dir) {
        while(A[++esq] < pivo);
        while(A[--dir] > pivo);
        if(esq >= dir) break;
        troca(&A[esq], &A[dir]);
    }

    qSort(A, baixo, dir);
    qSort(A, dir + 1, alto);
}

void quickSort(int *A, int baixo, int alto) {
    qSort(A, baixo, alto - 1);
}

void heapSort(int *A, int tamanho) {
    int i;

    heapfica(A,tamanho);


    for(i = 0; i < tamanho; i++) {
        troca(&A[0], &A[tamanho - 1 - i]);
        bdown(A, tamanho - i - 1, 0);
    }

}

void heapfica(int *A, int tamanho) {
    int pos = tamanho - 1;
    while (pos >= 0) {
        bdown(A,tamanho,pos);
        pos--;
    }
}

void bdown(int *A, int tamanho, int p) {
    int filho_esq = getFilhoEsq(p);
    int filho_dir = filho_esq + 1;
    int filho_max;

    if (filho_esq >= tamanho) return;

    if(filho_dir >= tamanho) filho_max = filho_esq;
    else filho_max = (A[filho_esq] >= A[filho_dir] ? filho_esq : filho_dir);

    if(A[p] < A[filho_max]) {
        troca(&A[p],&A[filho_max]);
        bdown(A,tamanho,filho_max);
    }
}

int getFilhoEsq(int p) {
    return 2*p + 1;
}


