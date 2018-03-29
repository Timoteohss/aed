//
// Created by timoteo on 26/03/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "listaDupla.h"

/// Imprime uma lista Dupla, do topo para o fim
/// \param lista - A lista a ser impressa
void imprimeListaDupla(listaDupla *lista) {

    listaDuplaNo *no;

    for(no = lista->topo; no!=NULL; no = no->prox)
        printf("%d ", *(int *) no->dado);
    printf("\n");
}

/// Cria uma lista Dupla vazia, pode ser utilizada com outra operação de dados caso deseje
/// \param ope - A operação de dados desejada, NULL para inteiro
/// \return - Uma lista Dupla vazia
listaDupla *criaListaDupla(struct operacaoDados *ope) {

    listaDupla *lista = (listaDupla *)malloc (sizeof(listaDupla));

    lista->topo = NULL;
    lista->fim = NULL;

    if(!ope) {
        lista->ope.cmp = comparaDados;
        lista->ope.tipoDado = voidParaInteiro;
    } else {
        lista->ope = *ope;
    }

    return lista;
}

/// Deleta um NO de uma lista Dupla
/// \param lista - A lista a ter o NO deletado
/// \param no - O NO a ser deletado da lista
void deletaListaDuplaNo(listaDupla *lista, listaDuplaNo *no) {

    if(no == NULL)
        return;

    if(no == lista->topo)
        lista->topo = no->prox ? no->prox : no->ante ? no->ante : NULL;

    if(no == lista->fim)
        lista->fim = no->ante ? no->ante : no->prox ? no->prox : NULL;

    if(no->prox != NULL)
        no->prox->ante = no->ante;

    if(no->ante != NULL)
        no->ante->prox = no->prox;

    free(no);
}

/// Deleta uma lista inteira
/// \param lista - A lista a ser deletada
void deletaListaDupla(listaDupla *lista) {

    struct listaDuplaNo *no = lista->topo;

    while(no) {
        deletaListaDuplaNo(lista, no);
        no = no->prox;
    }

    free(lista);
}

/// Adiciona um dado no topo da lista Dupla
/// \param lista - A lista a receber o dado
/// \param dado - O dado a ser inserido na lista
void adicionalistaDuplaNoTopo(listaDupla *lista, void *dado) {

    listaDuplaNo *no = (listaDuplaNo *)malloc(sizeof(listaDuplaNo));

    no->dado = dado;
    no->prox = NULL;
    no->ante = NULL;

    if(lista->topo) {
        no->prox = lista->topo;
        lista->topo->ante = no;
    } else {
        lista->fim = no;
    }


    lista->topo = no;
}

/// Adiciona um dado no fim da lista Dupla
/// \param lista - A lista a receber o dado
/// \param dado - O dado a ser inserido na lista
void adicionalistaDuplaNoFim(listaDupla *lista, void *dado) {

    listaDuplaNo *no = (listaDuplaNo *)malloc(sizeof(listaDuplaNo));

    no->dado = dado;
    no->prox = NULL;
    no->ante = NULL;

    if(lista->fim) {
        no->ante = lista->fim;
        lista->fim->prox = no;
    } else {
        lista->topo = no;
    }


    lista->fim = no;
}

/// Realiza uma busca por um dado na lista
/// \param lista - A lista a ser realizada a busca
/// \param dado - O dado a ser buscado
/// \return - O dado encontrado, ou NULL caso não encontre
listaDuplaNo *buscaListaDuplaNo(listaDupla *lista, void *dado) {

    listaDuplaNo *topo = lista->topo;

    while(topo) {
        if(lista->ope.cmp(topo->dado, dado))
            return topo;

        topo = topo->prox;
    }

    return NULL;
}







