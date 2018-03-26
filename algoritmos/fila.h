//
// Created by timoteo on 26/03/18.
//

#ifndef AED_FILA_H
#define AED_FILA_H

#include "listaDupla.h"

struct Fila {
    struct listaDupla *lista;
};

typedef struct Fila Fila;

Fila *criaFila(void);
void enfilera(Fila *fila, void *dado);
void *desenfila(Fila *fila);
void *verFinalDaFila(Fila *fila);
int filaEstaVazia(Fila *fila);
void deletaFila(Fila *fila);

#endif //AED_FILA_H
