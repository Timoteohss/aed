//
// Created by timoteo on 26/03/18.
//

#include <stdlib.h>
#include <stdio.h>
#include "algoritmos/pilha.h"

void imprimeHannoi(Pilha *p1,Pilha *p2,Pilha *p3) {
    printf("\n----------\n");
    imprimeListaSimples(p1->lista);
    printf("\n");
    imprimeListaSimples(p2->lista);
    printf("\n");
    imprimeListaSimples(p3->lista);
    printf("\n----------\n");
}

int main() {

    int qtdDiscos = 3;
    int *vetorInteiro = (int*)malloc(qtdDiscos * sizeof(int));

    Pilha *p1 = criaPilha();
    Pilha *p2 = criaPilha();
    Pilha *p3 = criaPilha();


    for(int i = 0; i < qtdDiscos; i++) {
        vetorInteiro[i] = qtdDiscos - i;
        empilha(p1,&vetorInteiro[i]);
    }

    imprimeHannoi(p1,p2,p3);
    empilha(p2,desempilha(p1));

    imprimeHannoi(p1,p2,p3);
    empilha(p3,desempilha(p1));

    imprimeHannoi(p1,p2,p3);
    empilha(p3,desempilha(p2));

    imprimeHannoi(p1,p2,p3);
    empilha(p2,desempilha(p1));

    imprimeHannoi(p1,p2,p3);
    empilha(p1,desempilha(p3));

    imprimeHannoi(p1,p2,p3);
    empilha(p2,desempilha(p3));

    imprimeHannoi(p1,p2,p3);
    empilha(p2,desempilha(p1));

    imprimeHannoi(p1,p2,p3);



}