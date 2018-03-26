//
// Created by timoteo on 16/03/18.
//


#include <stdlib.h>
#include <string.h>
#include "pilha.h"

/// Cria uma Pilha vazia
/// \return uma pilha vazia
struct Pilha *criaPilha(void) {
    struct Pilha *s = (struct Pilha *)malloc(sizeof(struct Pilha));
    s->lista = criaListaSimples(NULL);
    return s;
}

/// Empilha um dado em uma pilha dada
/// \param s - A pilha a receber o dado
/// \param dado - O dado a ser empilhado
void empilha(struct Pilha *s, void *dado) {
    adicionaNovoNo(s->lista, dado);
}

/// Desempilha da pilha dada, retorna o dado desempilhado
/// \param s - A pilha a ser desempilhada
/// \return - O dado desempilhado
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

/// Verifica se a pilha está vazia
/// \param s - A pilha  a ser verificada
/// \return - 0 se não estiver vazia, 1 se estiver
int estaVazia(struct Pilha *s) {
    return s->lista->topo ? 0 : 1;
}

/// Deleta uma pilha dada
/// \param s - A pilha a ser deletada
void deletaPilha(struct Pilha *s) {
    deletaListaSimples(s->lista);
    free(s);
}