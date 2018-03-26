//
// Created by timoteo on 15/03/18.
//

#ifndef AED_LISTASIMPLES_H
#define AED_LISTASIMPLES_H

#include "utilidades.h"


struct listaSimplesNo {
    void *dado;
    struct listaSimplesNo *proxima;
};

struct listaSimples {
    struct listaSimplesNo *topo;
    struct operacaoDados ope;
};

typedef struct listaSimplesNo listaSimplesNo;
typedef struct listaSimples listaSimples;

listaSimples *criaListaSimples(struct operacaoDados *ope);
void adicionaNovoNo(listaSimples *lista, void *dado);
listaSimplesNo *buscaNo(listaSimples *lista, void *dado);
void imprimeListaSimples(listaSimples *lista);

listaSimples *criaListaApartirDeArrayDeInteiros(int *A, int tamanho);
listaSimplesNo *encontraMeio(listaSimples *lista);
int temLoop(listaSimples *lista);
void inverteListaSimples(listaSimples *lista);
int numeroDeNos(listaSimples *lista);

void deletaListaSimplesNo(listaSimples *lista, listaSimplesNo *no);
void deletaListaSimples(listaSimples *lista);




#endif //AED_LISTASIMPLES_H
