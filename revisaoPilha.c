//
// Created by timoteo on 05/04/18.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct quarto {
    int numero;
    struct quarto *proximo;

};

typedef struct quarto quarto;

struct hotel {
    quarto *topo;

};

typedef struct hotel hotel;

void ocupa(hotel* h, int numero) {
    quarto* temp = (quarto*)malloc(sizeof(quarto));
    temp->numero = numero;
    //Detalhes de qum vai ocupar

    temp->proximo = h->topo;
    h->topo = temp;
}

quarto * busca(hotel *h,int numero) {
    quarto * aux = h->topo;

    aux = aux->proximo;
    do{
        if(!aux->proximo) return NULL;
        if(aux->proximo->numero == numero) return aux;
        aux = aux->proximo;
    }while(aux);


}

int desocupa(hotel * h, int numero) {
    if(!h) { printf("\nTodos os quartos estao desocupados!\n"); return -1;}

    quarto *ant = busca(h,numero);
    if(!ant) { printf("\nQuarto nao encontrado / ocupado!\n"); return -1; }

    printf("\nRemovendo quarto numero: %d\n",numero);
    quarto *desal = ant->proximo;
    ant->proximo = desal->proximo;
    free(desal);
}

void imprimeQuartosOcupados(hotel* h) {
    quarto * aux = h->topo;
    for(aux ; aux->proximo != NULL;aux=aux->proximo)
        printf("%d\t",aux->numero);
    printf("%d\n",aux->numero);

}


hotel * criaHotel() {
    hotel* aux = (hotel*)malloc(sizeof(hotel));
    aux->topo = NULL;
    return aux;
}

int main() {
    hotel* h1 = criaHotel();

    ocupa(h1,101);
    ocupa(h1,102);
    ocupa(h1,203);
    ocupa(h1,204);
    ocupa(h1,307);
    ocupa(h1,205);
    ocupa(h1,206);
    ocupa(h1,104);

    imprimeQuartosOcupados(h1);
    desocupa(h1,302);
    desocupa(h1,102);
    desocupa(h1,302);








}