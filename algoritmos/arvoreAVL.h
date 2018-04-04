//
// Created by timoteo on 28/03/18.
//

#ifndef AED_ARVOREAVL_H
#define AED_ARVOREAVL_H

#include "utilidades.h"
#include "arvoreBinaria.h"

struct arvoreAVLNo {
    void *dado;
    int altura;
    struct arvoreAVLNo *esq;
    struct arvoreAVLNo *dir;
    struct arvoreAVLNo *pai;
};

struct arvoreAVL {
    struct arvoreAVLNo *raiz;
    struct operacaoDados ope;

};

typedef struct arvoreAVL arvoreAVL;
typedef struct arvoreAVLNo arvoreAVLNo;


arvoreAVL *criaArvoreAVL(struct operacaoDados *ope);
void adicionaAVL(arvoreAVL *avl, void *dado);
void preOrdemAVL(arvoreAVLNo *no);



#endif //AED_ARVOREAVL_H
