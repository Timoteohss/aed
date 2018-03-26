//
// Created by timoteo on 26/03/18.
//

#ifndef AED_LISTADUPLA_H
#define AED_LISTADUPLA_H

#include "listaSimples.h"
#include "utilidades.h"

struct listaDuplaNo {
    void *dado;
    struct listaDuplaNo *prox;
    struct listaDuplaNo *ante;
};

struct listaDupla {
    struct listaDuplaNo *topo;
    struct listaDuplaNo *fim;
    struct operacaoDados ope;
};

typedef struct listaDuplaNo listaDuplaNo;
typedef struct listaDupla listaDupla;

listaDupla *criaListaDupla(struct operacaoDados *ops);
void deletaListaDuplaNo(listaDupla *lista, listaDuplaNo *no);
void deletaListaDupla(listaDupla *lista);
void adicionalistaDuplaNoTopo(listaDupla *lista, void *dado);
void adicionalistaDuplaNoFim(listaDupla *lista, void *dado);
listaDuplaNo *buscaListaDuplaNo(listaDupla *lista, void *dado);
void imprimeListaDupla(listaDupla *lista);

#endif //AED_LISTADUPLA_H
