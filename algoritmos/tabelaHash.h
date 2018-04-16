//
// Created by timoteo on 04/04/18.
//

#ifndef AED_HASHTABLE_H
#define AED_HASHTABLE_H

#include "utilidades.h"
#include "arvoreAVL.h"

struct tabelaHash {
    arvoreAVL *avl;
    int tamanho;
    struct operacaoDados ope;
};


typedef struct tabelaHash tabelaHash;

tabelaHash *criaTabelaHash(struct operacaoDados *ope, int tamanho);
void adicionaTabelaHash(tabelaHash *th, void *dado);


void imprimeTabelaHash(tabelaHash *th);
#endif //AED_HASHTABLE_H
