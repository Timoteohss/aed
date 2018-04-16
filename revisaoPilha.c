//
// Created by timoteo on 05/04/18.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int numero;
    struct no *anterior;
    struct no *proximo;
    struct no *pai;
}no,*pno;

typedef struct no no,*pno;

struct pilha {
    pno topo;

};

typedef struct pilha pilha, *ppilha;

void push(ppilha p, int valor) {
    pno notemporario = (pno)malloc(sizeof(no));
    notemporario->numero = valor;
    notemporario->anterior = p->topo;
    p->topo = notemporario;
}

int pop(ppilha p) {
    if(!p->topo) return NULL;
    else {
        pno temp = p->topo;
        p->topo = temp->anterior;
        int numero = temp->numero;
        free(temp);
        return numero;
    }
}

void imprimePilha(ppilha p) {
    pno temp = p->topo;

    for(temp ; temp->anterior ; temp = temp->anterior) {
        printf("%i ",temp->numero);
    }
    printf("%i \n", temp->numero);
}

void imprimeHanoi(ppilha p1,ppilha p2,ppilha p3) {
    printf("\n---------\n");
    imprimePilha(p1);
    imprimePilha(p2);
    imprimePilha(p3);
    printf("\n---------");

}


ppilha criaPilha() {
    ppilha aux = (pilha*)malloc(sizeof(pilha));
    aux->topo = NULL;
    return aux;
}

int main() {
    ppilha p1 = criaPilha();
    ppilha p2 = criaPilha();
    ppilha p3 = criaPilha();

    push(p1,7);
    push(p1,6);
    push(p1,5);
    push(p1,4);
    push(p1,3);
    push(p2,pop(p1));
    push(p3,pop(p1));

    imprimeHanoi(p1,p2,p3);
    imprimeHanoi(p1,p2,p3);


}