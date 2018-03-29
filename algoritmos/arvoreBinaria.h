//
// Created by timoteo on 28/03/18.
//

#ifndef AED_ARVOREBINARIA_H
#define AED_ARVOREBINARIA_H

#include "utilidades.h"

struct arvoreBinariaNo {
    void *dado;
    struct arvoreBinariaNo *esq;
    struct arvoreBinariaNo *dir;
    struct arvoreBinariaNo *pai;
    int altura;
};

struct arvoreBinaria {
    struct arvoreBinariaNo *raiz;
    struct operacaoDados ope;
};



typedef struct arvoreBinaria arvoreBinaria;
typedef struct arvoreBinariaNo arvoreBinariaNo;


arvoreBinaria *criaArvoreBinaria(struct operacaoDados *ope);
arvoreBinariaNo * adicionaNoNaArvore(arvoreBinaria *arvore, void *dado);

arvoreBinariaNo *achaMin(arvoreBinaria *arvore);
arvoreBinariaNo *achaMax(arvoreBinaria *arvore);
arvoreBinariaNo *achaNo(arvoreBinaria *arvore, void *dado);
void emOrdem(arvoreBinariaNo *raiz);
void preOrdem(arvoreBinariaNo *raiz);
void posOrdem(arvoreBinariaNo *raiz);

void processaNo(arvoreBinariaNo *no);
void imprimeArvore(arvoreBinaria *arvore);

void deletaNoDaArvore(arvoreBinaria *arvore, arvoreBinariaNo *no);
void deletaArvore(arvoreBinaria *arvore);

#endif //AED_ARVOREBINARIA_H
