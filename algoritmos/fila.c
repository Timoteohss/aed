//
// Created by timoteo on 26/03/18.
//

#include <stdlib.h>
#include <string.h>
#include "fila.h"

/// Cria uma Fila vazia
/// \return - Uma fila, vazia
Fila *criaFila(void) {
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->lista = criaListaDupla(NULL);
    return fila;
}

/// Enfilera um dado na fila
/// \param fila - A fila  a receber o dado
/// \param dado - O dado a ser enfileirado
void enfilera(Fila *fila, void *dado) {
    adicionalistaDuplaNoTopo(fila->lista, dado);
}

/// Tira um elemento da fila
/// \param fila - A fila a ser desinfileirada
/// \return - O dado que saiu da fila
void *desenfila(Fila *fila) {

    struct listaDuplaNo *fim;
    void *dado;

    fim = fila->lista->fim;
    dado = fim ? fim->dado : NULL;

    deletaListaDuplaNo(fila->lista, fim);
    return dado;
}

/// Vê o dado da última posição da fila
/// \param fila - A fila a ser verificada
/// \return - O item na última posição da fila
void *verFinalDaFila(Fila *fila) {
    return fila->lista->fim ? fila->lista->fim->dado : NULL;
}

/// Verifica se a fila está vazia
/// \param fila - A fila a ser verificada
/// \return - 0 se não, 1 se sim
int filaEstaVazia(Fila *fila) {
    return fila->lista->fim ? 0 : 1;
}

/// Deleta uma fila e todos seus elementos
/// \param fila - A fila a ser deletada
void deletaFila(Fila *fila) {
    deletaListaDupla(fila->lista);
    free(fila);
}

