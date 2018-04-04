//
// Created by timoteo on 28/03/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"

void ajustaAltura(arvoreAVLNo *no);

int calculaAltura(struct arvoreAVLNo *no);

int max(int altura, int calculaAltura);

arvoreAVLNo *balanceia(arvoreAVLNo *no);

arvoreAVLNo *rodaDir(arvoreAVLNo *no);

arvoreAVLNo *rodaEsq(arvoreAVLNo *no);

arvoreAVL *criaArvoreAVL(struct operacaoDados *ope) {
    arvoreAVL *arvore = (arvoreAVL*)malloc(sizeof(arvoreAVL));
    arvore->raiz = NULL;

    if(!ope) {
        arvore->ope.cmp = comparaDados;
        arvore->ope.tipoDado = voidParaInteiro;
    } else {
        arvore->ope = *ope;
    }

    return arvore;
}

void adicionaAVL(arvoreAVL *avl, void *dado) {
    arvoreAVLNo *no = avl->raiz;
    arvoreAVLNo *novo = (arvoreAVLNo*)malloc(sizeof(arvoreAVLNo));

    novo->dado = dado;
    novo->altura = 1;
    novo->esq = NULL;
    novo->dir = NULL;

    if(!no) {
        avl->raiz = novo;
        return;
    }

    while(avl->ope.cmp(no->dado,dado) != 0) {
        if(avl->ope.cmp(no->dado,dado) > 0) {
            if(no->esq) no = no->esq;
            else {
                novo->pai = no;
                no->esq = novo;
                no = no->esq;
            }
        } else if(avl->ope.cmp (no->dado,dado) < 0) {
            if(no->dir) no = no->dir;
            else {
                novo->pai = no;
                no->dir = novo;
                no = no->dir;
            }
        } else return;
    }

    do {
        no = no->pai;
        ajustaAltura(no);
        no = balanceia(no);
    }while(no->pai);

    avl->raiz = no;
}

arvoreAVLNo *balanceia(arvoreAVLNo *no) {
    if(calculaAltura(no->esq) - calculaAltura(no->dir) > 1) {
        if(calculaAltura(no->esq->esq) > calculaAltura(no->esq->dir))
            no = rodaDir(no);
        else {
            no->esq = rodaEsq(no->esq);
            return rodaDir(no);
        }
    } else if (calculaAltura(no->dir) - calculaAltura(no->esq) > 1) {
        if(calculaAltura(no->dir->dir) > calculaAltura(no->dir->esq))
            no = rodaEsq(no);
        else {
            no->dir = rodaDir(no->dir);
            return rodaEsq(no);
        }
    }
    return no;
}

arvoreAVLNo *rodaDir(arvoreAVLNo *no){
    arvoreAVLNo *novaraiz = no->esq;
    if(no->pai) {
        if(no->pai->esq == no) no->pai->esq = novaraiz;
        else no->pai->dir   = novaraiz;
    }
    novaraiz->pai = no->pai;
    no->pai = novaraiz;
    no->esq = novaraiz->dir;
    if(no->esq) no->esq->pai = no;
    novaraiz->dir = no;

    ajustaAltura(no);
    ajustaAltura(novaraiz);
    return novaraiz;
}

arvoreAVLNo *rodaEsq(arvoreAVLNo *no){
    arvoreAVLNo *novaraiz = no->dir;
    if(no->pai) {
        if(no->pai->dir == no) no->pai->dir = novaraiz;
        else no->pai->esq = novaraiz;
    }
    novaraiz->pai = no->pai;
    no->pai = novaraiz;
    no->dir = novaraiz->esq;
    if(no->dir) no->dir->pai = no;
    novaraiz->esq = no;

    ajustaAltura(no);
    ajustaAltura(novaraiz);
    return novaraiz;
}

void ajustaAltura(arvoreAVLNo *no) {
    no->altura = 1 + max(calculaAltura(no->esq), calculaAltura(no->dir));
}

int max(int a, int b) {
    return a > b ? a : b;
}

int calculaAltura(struct arvoreAVLNo *no) {
    return no ? no->altura : 0;
}

void processaNoAVL(arvoreAVLNo *no) {
    printf("%d ", voidParaInteiro(no->dado));
}

void preOrdemAVL(arvoreAVLNo *no) {
    if(no) {
        processaNoAVL(no);
        preOrdemAVL(no->esq);
        preOrdemAVL(no->dir);
    }
}

void emOrdemAVL(arvoreAVLNo *no) {
    if(no) {
        preOrdemAVL(no->esq);
        processaNoAVL(no);
        preOrdemAVL(no->dir);
    }
}

void posOrdemAVL(arvoreAVLNo *no) {
    if(no) {
        preOrdemAVL(no->esq);
        preOrdemAVL(no->dir);
        processaNoAVL(no);
    }
}

void imprimeArvoreAVL(arvoreAVL *arvore) {
    printf("\nEm ordem: "); emOrdemAVL(arvore->raiz);
    printf("\nPre ordem: "); preOrdemAVL(arvore->raiz);
    printf("\nPos ordem: "); posOrdemAVL(arvore->raiz);

}
