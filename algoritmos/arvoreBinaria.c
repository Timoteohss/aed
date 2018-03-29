//
// Created by timoteo on 28/03/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"


arvoreBinaria *criaArvoreBinaria(struct operacaoDados *ope) {
    arvoreBinaria *arvore = (arvoreBinaria*)malloc(sizeof(arvoreBinaria));
    arvore->raiz = NULL;

    if(!ope) {
        arvore->ope.cmp = comparaDados;
        arvore->ope.tipoDado = voidParaInteiro;
    } else {
        arvore->ope = *ope;
    }

    return arvore;
}

arvoreBinariaNo * adicionaNoNaArvore(arvoreBinaria *arvore, void *dado) {
    arvoreBinariaNo **ptr_pai;
    arvoreBinariaNo *pai;
    arvoreBinariaNo *no = (arvoreBinariaNo*)malloc(sizeof(arvoreBinariaNo));

    ptr_pai = &arvore->raiz;
    pai = NULL;
    while(*ptr_pai) {
        pai = *ptr_pai;
        if(arvore->ope.cmp(dado, (*ptr_pai)->dado) < 0)
            ptr_pai = &((*ptr_pai)->esq);
        else
            ptr_pai = &((*ptr_pai)->dir);
    }

    no->pai = pai;
    no->dado = dado;
    no->dir = NULL;
    no->esq = NULL;

    *ptr_pai = no;

    return no;
}

void imprimeArvore(arvoreBinaria *arvore) {
    printf("\nEm ordem: "); emOrdem(arvore->raiz);
    printf("\nPre ordem: "); preOrdem(arvore->raiz);
    printf("\nPos ordem: "); posOrdem(arvore->raiz);

}

void processaNo(arvoreBinariaNo *no) {
    printf("%d ", voidParaInteiro(no->dado));
}

void emOrdem(arvoreBinariaNo *raiz) {
    if(raiz) {
        emOrdem(raiz->esq);
        processaNo(raiz);
        emOrdem(raiz->dir);
    }
}

void preOrdem(arvoreBinariaNo *raiz) {
    if(raiz) {
        processaNo(raiz);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void posOrdem(arvoreBinariaNo *raiz) {
    if(raiz) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        processaNo(raiz);
    }
}

void deletaNoDaArvore(arvoreBinaria *arvore, arvoreBinariaNo *no) {
    arvoreBinariaNo **ptr_pai;
    arvoreBinariaNo *pai;
    arvoreBinariaNo *min;

    if(!no || !no->dado) return;

    pai = no->pai;

    if(!pai)
        ptr_pai = &(arvore->raiz);
    else
        ptr_pai = arvore->ope.cmp(no->dado, pai->dado) < 0 ? &(pai->esq) : &(pai->dir);

    if(no->dir && no->esq) {
        arvoreBinariaNo **ptr_pai_min;
        arvoreBinaria *temp = criaArvoreBinaria(&arvore->ope);

        temp->raiz = no->dir;
        min = achaMin(temp);

        ptr_pai_min = min->pai->esq == min ? &(min->pai->esq) : &(min->pai->dir);

        *ptr_pai_min = NULL;

        min->pai = no->pai;
        min->esq = no->esq;
        min->dir = no->dir == min ? NULL : no->dir;

        *ptr_pai = min;
    } else if(no->dir || no->esq) {
        arvoreBinariaNo *filho;
        filho = no->dir ? no->dir : no->esq;
        *ptr_pai = filho;
        filho->pai = no->pai;
    } else {
        *ptr_pai = NULL;
    }

    free(no);
}

arvoreBinariaNo *achaMin(arvoreBinaria *arvore) {
    arvoreBinariaNo *min = arvore->raiz;
    while(min && min->esq)
        min = min->esq;
    return min;
}

arvoreBinariaNo *achaMax(arvoreBinaria *arvore) {
    arvoreBinariaNo *max = arvore->raiz;
    while(max && max->dir)
        max = max->dir;
    return max;
}

arvoreBinariaNo *achaNo(arvoreBinaria *arvore, void *dado) {
    arvoreBinariaNo *no = arvore->raiz;

    while(no) {
        if(arvore->ope.cmp(dado, no->dado) < 0)
            no = no->esq;
        else if (arvore->ope.cmp(dado, no->dado) > 0)
            no = no->dir;
        else
            return no;
    }
    return NULL;
}

void deletaArvore(arvoreBinaria *arvore) {
    while(arvore->raiz)
        deletaNoDaArvore(arvore,arvore->raiz);
    free(arvore);
}


