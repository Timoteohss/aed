#include <stdio.h>
#include <stdlib.h>
#include "algoritmos/utilidades.h"
#include "algoritmos/buscaBinaria.h"
#include "algoritmos/fila.h"
#include "algoritmos/listaDupla.h"
#include "algoritmos/listaSimples.h"
#include "algoritmos/pilha.h"


int main() {



//Testes com fila e utilidades

    int tamanho = 10;
    int *vetorInteiro = (int*)malloc(tamanho * sizeof(int));
    vetorInteiro = criaArrayInteiros(tamanho);

    imprimeArrayInteiros(vetorInteiro,tamanho);

    int achou = buscaBinaria(vetorInteiro,tamanho,3881);

    //printf("\n%d",achou);

    /*listaSimples *A = criaListaApartirDeArrayDeInteiros(vetorInteiro,tamanho);

    int *a = 966;

    if( A->ope.cmp(encontraMeio(A)->dado, &a) == 0) printf("O meio realmente eh 966!\n");

    if(buscaNo(A,&a)) { printf("Valor encontrado!\n"); }

    imprimeListaSimples(A);*/

//Testes com pilha
    /*Pilha *A = criaPilha();*/

//Teste com listDupla
    /*listaDupla *ld1 = criaListaDupla(NULL);

    adicionalistaDuplaNoFim(ld1,&vetorInteiro[0]);
    adicionalistaDuplaNoFim(ld1,&vetorInteiro[1]);
    adicionalistaDuplaNoFim(ld1,&vetorInteiro[2]);
    adicionalistaDuplaNoTopo(ld1,&vetorInteiro[3]);

    imprimeListaDupla(ld1);*/

//Testes com Fila
/*
    Fila *f1 = criaFila();

    enfilera(f1,&vetorInteiro[0]);
    enfilera(f1,&vetorInteiro[1]);
    enfilera(f1,&vetorInteiro[2]);

    imprimeListaDupla(f1->lista);

    desenfila(f1);

    imprimeListaDupla(f1->lista);
*/





}