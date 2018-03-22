//
// Created by timoteo on 15/03/18.
//

#include <stdlib.h>
#include <stdio.h>
#include "listaSimples.h"

//Operações básicas

listaSimples *criaListaSimples(struct operacaoDados *ope) {
    listaSimples *lista = (listaSimples *)malloc(sizeof(listaSimples));

    lista->topo = NULL;

    if(ope == NULL) {
        lista->ope.cmp = comparaDados;
        lista->ope.tipoDado = voidParaInteiro;
    } else {
        lista->ope = *ope;
    }

    return lista;
}

void adicionaNovoNo(listaSimples *lista, void *dado) {
    listaSimplesNo *no = (listaSimplesNo*)malloc(sizeof(listaSimplesNo));
    no->dado = dado;
    no->proxima = lista->topo;
    lista->topo = no;
}

listaSimplesNo *buscaNo(listaSimples *lista, void *dado) {
    listaSimplesNo *inicio = lista->topo;
    while (inicio) {
        if (!lista->ope.cmp(inicio->dado, dado))
            return inicio;

        inicio = inicio->proxima;
    }
    return NULL;
}

void imprimeListaSimples(listaSimples *lista) {
    if (!lista) return;

    listaSimplesNo *no = lista->topo;
    while (no) {
        printf("%d ", lista->ope.tipoDado(no->dado));
        no = no->proxima;
    }
}


//Operações especiais


listaSimples *criaListaApartirDeArrayDeInteiros(int *A, int tamanho) {
    listaSimples *lista = criaListaSimples(NULL);

    for(int i = 0; i < tamanho; i++) {
        adicionaNovoNo(lista, &A[i]);
    }

    return lista;
}

listaSimplesNo *encontraMeio(listaSimples *lista) {
    listaSimplesNo *inteiro, *metade;

    inteiro = lista->topo;
    metade = lista->topo;

    while(inteiro && inteiro->proxima && inteiro->proxima->proxima) {
        metade = metade->proxima;
        inteiro = inteiro->proxima->proxima;
    }

    return metade;
}

int numeroDeNos(listaSimples *lista) {
    listaSimplesNo *inicio = lista->topo;
    int conta = 0;

    while(inicio) {
        conta++;
        inicio = inicio->proxima;
    }

    return conta;
}

int temLoop(listaSimples *lista) {
    struct listaSimplesNo *inteiro, *metade;

    inteiro = lista->topo;
    metade = lista->topo;

    while(inteiro) {
        if(inteiro->proxima == metade || (inteiro->proxima && (inteiro->proxima->proxima == metade)))
            return 1;

        inteiro = (inteiro->proxima && inteiro->proxima->proxima) ? inteiro->proxima : NULL;
        metade = metade->proxima;
    }

    return 0;
}

void inverteListaSimples(listaSimples *lista) {
    listaSimplesNo *p, *anterior, *temp;

    if(lista->topo == NULL) return;

    anterior = NULL;
    for(p = lista->topo; p!=NULL;) {
        temp = p->proxima;
        p->proxima = anterior;
        anterior = p;
        p = temp;
    }
    lista->topo = anterior;
}

//Deletar

void deletaListaSimplesNo(listaSimples *lista, listaSimplesNo *no) {
    listaSimplesNo **anterior, *atual;

    if(!no) return;

    anterior = &lista->topo;
    atual = lista->topo;

    while(atual) {
        if(no == atual) {
            *anterior = atual->proxima;
            free(atual);
            return;
        }
        anterior = &(atual->proxima);
        atual = atual->proxima;
    }
}

void deletaListaSimples(listaSimples *lista) {
    listaSimplesNo *no;

    no = lista->topo;
    while(no) {
        deletaListaSimplesNo(lista,no);
        no = no->proxima;
    }

    free(lista);
}
