//
// Created by timoteo on 28/03/18.
//

#ifndef AED_ARVOREAVL_H
#define AED_ARVOREAVL_H

#include "utilidades.h"

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
arvoreAVLNo *buscaAVL(arvoreAVL *avl, void *dado);


void processaNoAVL(arvoreAVLNo *no);
void preOrdemAVL(arvoreAVLNo *no);
void emOrdemAVL(arvoreAVLNo *no);
void posOrdemAVL(arvoreAVLNo *no);
void imprimeArvoreAVL(arvoreAVL *arvore);



#endif //AED_ARVOREAVL_H
