//
// Created by timoteo on 15/03/18.
//
#include <stdlib.h>
#include <stdio.h>
#include "utilidades.h"

/// Função para troca de inteiros, envie dois ponteiros para dois inteiros e os troque de posição
/// \param a - Ponteiro de inteiro 1
/// \param b - Ponteiro de inteiro 2
void troca(int *a, int *b) {
    if(a == b) return;

    int temp = *a;
    *a = *b;
    *b = temp;
}

/// Função para imprimir um vetor de inteiros, envie o ponteiro para o vetor e o tamanho do mesmo. Opcionalmente envie até qual posição quer que imprima.
/// \param vetor - Ponteiro para o vetor
/// \param tamanho - Tamanho do vetor, ou até que posição quer imprimir
void imprimeArrayInteiros(int *vetor, int tamanho) {


    for(int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

/// Função para criar um vetor de inteiros aleatórios, envie apenas o tamanho do vetor e ele será preenchido e retornado
/// \param tamanho - O tamanho do vetor a ser criado
/// \return - O vetor, receba-o em um ponteiro!
int *criaArrayInteiros(int tamanho) {
    int i;
    int *A = (int *)malloc(tamanho * sizeof(int));

    for (i = 0; i < tamanho; i++)
        A[i] = rand() % RAND_MAX;

    return A;
}

/// Função para deletar um vetor, envie um ponteiro para o vetor
/// \param vetor - O vetor a ser deletado
void deletaArrayInteiros(int *vetor) {
    if(vetor) free(vetor);

}

/// Comparador de dados da struct operacaoDados, envie dois ponteiros genéricos e receba o resultado da comparação deles.
/// \param isso - Ponteiro generico 1
/// \param aquilo - Ponteiro generico 2
/// \return - retorna -1 se isso < aquilo, 0 se isso > aquilo e 1 se isso == aquilo
int comparaDados(void *isso, void *aquilo) {
    if (*(int *)isso == *(int *)aquilo) {
        return 0;
    } else if (*(int *)isso > *(int *)aquilo) {
        return 1;
    } else {
        return -1;
    }
}

/// Tranforma um ponteiro genérico em um valor inteiro
/// \param valor - O ponteiro genérico
/// \return - Seu valor inteiro
int voidParaInteiro(void *valor) {
    return *(int *) valor;
}
