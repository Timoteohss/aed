//
// Created by timoteo on 16/03/18.
//

#ifndef AED_PILHA_H
#define AED_PILHA_H

#include "listaSimples.h"

struct Pilha {
    listaSimples *lista;
};

typedef struct Pilha Pilha;

Pilha *criaPilha(void);
void empilha(Pilha *s, void *dado);
void *desempilha(Pilha *s);
void *verificaTopo(Pilha *s);
int estaVazia(Pilha *s);
void deletaPilha(Pilha *s);

#endif //AED_PILHA_H
