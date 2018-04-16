//
// Created by timoteo on 04/04/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "tabelaHash.h"
#include "utilidades.h"
#include "fila.h"


tabelaHash *criaTabelaHash(struct operacaoDados *ope, int tamanho) {
    tabelaHash *th = (tabelaHash*)malloc(tamanho * sizeof(tabelaHash));
    int i = 0;


    while(i < tamanho) {
        th[i].avl = NULL;

        th[i].tamanho = tamanho;
        if(!ope) {
            th[i].ope.cmp = comparaDados;
            th[i].ope.tipoDado = voidParaInteiro;
        } else {
            th[i].ope = *ope;
        }

        i++;
    }


    return th;
}

void adicionaTabelaHash(tabelaHash *th,void *dado){
    int index = voidParaInteiro(dado) % th->tamanho;
    arvoreAVL *arvAvl = th[index].avl;

    if(!arvAvl) arvAvl = criaArvoreAVL(&th->ope);

    adicionaAVL(arvAvl, dado);

    th[index].avl = arvAvl;
}

void deletaDaTabelaHash(tabelaHash *th, void *dado) {

}

void imprimeTabelaHash(tabelaHash *th) {
    for(int  i = 0; i < th->tamanho; i++) {
        printf("\n\nLista %d: ", i+1);
        imprimeArvoreAVL(th[i].avl);
    }
    printf("\n");
}
