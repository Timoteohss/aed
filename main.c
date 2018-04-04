#include <stdio.h>
#include <stdlib.h>
#include "algoritmos/utilidades.h"
#include "algoritmos/arvoreAVL.h"
#include "algoritmos/metodosOrdenacao.h"
#include "algoritmos/arvoreBinaria.h"
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

    /*Fila *f1 = criaFila();
    printf("%d\n",filaEstaVazia(f1));


    enfilera(f1,&vetorInteiro[66]);
    imprimeListaDupla(f1->lista);
    printf("%d\n",filaEstaVazia(f1));
    desenfila(f1);



    printf("%d",filaEstaVazia(f1));*/
/*

    imprimeArrayInteiros(vetorInteiro,tamanho);
    quickSort(vetorInteiro,0,tamanho);
    selectionSort(vetorInteiro,tamanho);
    imprimeArrayInteiros(vetorInteiro,tamanho);
*/

    arvoreAVL *A = criaArvoreAVL(NULL);
    int *V = (int*)malloc(3*sizeof(int));
    V[0] = 1;
    V[1] = 2;
    V[2] = 3;
    V[3] = 4;
    V[4] = 5;


    //imprimeArrayInteiros(V,11);

    adicionaAVL(A,&vetorInteiro[0]);
    adicionaAVL(A,&vetorInteiro[1]);
    adicionaAVL(A,&vetorInteiro[2]);
    adicionaAVL(A,&vetorInteiro[3]);
    adicionaAVL(A,&vetorInteiro[4]);



    imprimeArvoreAVL(A);


    printf("\n%lu",hash_djb2((unsigned char *) "timoteo"));




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