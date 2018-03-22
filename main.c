#include <stdio.h>
#include <stdlib.h>
#include "algoritmos/utilidades.h"
#include "algoritmos/listaSimples.h"
#include "algoritmos/pilha.h"


int main() {



//Testes com fila e utilidades

    int tamanho = 49;
    int *vetorInteiro = (int*)malloc(tamanho * sizeof(int));
    vetorInteiro = criaArrayInteiros(tamanho);

    imprimeArrayInteiros(vetorInteiro,tamanho);

    /*listaSimples *A = criaListaApartirDeArrayDeInteiros(vetorInteiro,tamanho);

    int *a = 966;

    if( A->ope.cmp(encontraMeio(A)->dado, &a) == 0) printf("O meio realmente eh 966!\n");

    if(buscaNo(A,&a)) { printf("Valor encontrado!\n"); }

    imprimeListaSimples(A);*/

//Testes com pilha
    /*Pilha *A = criaPilha();*/



}