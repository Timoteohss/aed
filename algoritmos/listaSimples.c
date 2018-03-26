//
// Created by timoteo on 15/03/18.
//

#include <stdlib.h>
#include <stdio.h>
#include "listaSimples.h"

//Operações básicas

/// Cria uma lista Simples, pode receber outra operaçao de dados desejada.
/// \param ope - NULL caso seja inteiro, ou crie sua operação de dados
/// \return - uma lista Simples vazia
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

/// Adiciona um novo dado na lista dada
/// \param lista - A lista a receber o dado
/// \param dado - O dado a ser recebido
void adicionaNovoNo(listaSimples *lista, void *dado) {
    listaSimplesNo *no = (listaSimplesNo*)malloc(sizeof(listaSimplesNo));
    no->dado = dado;
    no->proxima = lista->topo;
    lista->topo = no;
}

/// Busca um dado na lista, retornando o dado caso seja encontrado
/// \param lista - A lista a ser utilizada na busca
/// \param dado - O dado a ser procurado
/// \return - O dado encontrado, ou NULL caso não encontre
listaSimplesNo *buscaNo(listaSimples *lista, void *dado) {
    listaSimplesNo *inicio = lista->topo;
    while (inicio) {
        if (!lista->ope.cmp(inicio->dado, dado))
            return inicio;

        inicio = inicio->proxima;
    }
    return NULL;
}

/// Imprime uma lista
/// \param lista - A lista a ser impressa
void imprimeListaSimples(listaSimples *lista) {
    if (!lista) return;

    listaSimplesNo *no = lista->topo;
    while (no) {
        printf("%d ", lista->ope.tipoDado(no->dado));
        no = no->proxima;
    }
}


//Operações especiais

/// Cria uma lista simples a partir de um vetor de inteiros dado
/// \param A - O vetor de inteiros
/// \param tamanho - O tamanho do vetor
/// \return - A lista populada com os dados do vetor
listaSimples *criaListaApartirDeArrayDeInteiros(int *A, int tamanho) {
    listaSimples *lista = criaListaSimples(NULL);

    for(int i = 0; i < tamanho; i++) {
        adicionaNovoNo(lista, &A[i]);
    }

    return lista;
}

/// Encontra o meio de uma lista
/// \param lista - A lista a ser utilizada
/// \return - O dado no meio da lista
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

/// Conta a quantidade de itens na lista
/// \param lista - A lista a ser contada
/// \return - A quantidade de itens na lista
int numeroDeNos(listaSimples *lista) {
    listaSimplesNo *inicio = lista->topo;
    int conta = 0;

    while(inicio) {
        conta++;
        inicio = inicio->proxima;
    }

    return conta;
}


/// Verifica se existe um loop dentro da lista, caso já tenha referenciado um valor de dentro da lista
/// \param lista - A lista a ser buscada
/// \return - 1 caso exista o loop, 0 caso não
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

/// Inverte a lista
/// \param lista - A lista a ser invertida
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

/// Deleta um NO da lista
/// \param lista - A lista a ter um NO deletado
/// \param no - O no a ser deletado
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

/// Deleta a lista inteira
/// \param lista - lista a ser deletada
void deletaListaSimples(listaSimples *lista) {
    listaSimplesNo *no;

    no = lista->topo;
    while(no) {
        deletaListaSimplesNo(lista,no);
        no = no->proxima;
    }

    free(lista);
}
