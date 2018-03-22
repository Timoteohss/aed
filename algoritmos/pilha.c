//
// Created by timoteo on 16/03/18.
//


#include <stdlib.h>
#include <string.h>
#include "pilha.h"

struct Pilha *criaPilha(void) {
    struct Pilha *s = (struct Pilha *)malloc(sizeof(struct Pilha));
    s->lista = criaListaSimples(NULL);
    return s;
}

void empilha(struct Pilha *s, void *dado) {
    adicionaNovoNo(s->lista, dado);
}

void *desempilha(struct Pilha *s) {
    listaSimplesNo *item;
    void *item_dado;

    item = s->lista->topo;
    item_dado = (s->lista->topo) ? s->lista->topo->dado : NULL;

    if (item)
        deletaListaSimplesNo(s->lista, item);

    return item_dado;
}

void *verificaTopo(struct Pilha *s) {
    return s->lista->topo ? s->lista->topo->dado: NULL;
}

int estaVazia(struct Pilha *s) {
    return s->lista->topo ? 0 : 1;
}

void deletaPilha(struct Pilha *s) {
    deletaListaSimples(s->lista);
    free(s);
}