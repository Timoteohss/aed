//
// Created by timoteo on 27/03/18.
//

#include <stdio.h>
#include <stdlib.h>

struct disco {
    int raio;
    struct disco *anterior;
};

struct base {
    struct disco *topo;
    int qtdDiscos;
};

typedef struct disco disco;
typedef struct base base;

base *criaBase() {
    base *bt = (base*)malloc(sizeof(base));
    bt->topo = NULL;
    bt->qtdDiscos = 0;
    return bt;
}

void push(base *b, int val) {
    if(val < 0)
        return;

    disco *dt = (disco*)malloc(sizeof(disco));
    dt->raio = val;
    dt->anterior = b->topo;
    b->topo = dt;
}

int pop(base *b) {
    if(!b->topo)
        return -1;
    else {
        disco *antigo;
        int n;

        antigo = b->topo;
        n = antigo->raio;

        b->topo = antigo->anterior;
        free(antigo);
        return n;
    }
}

void imprimeBase(base *b) {
    disco *tb = b->topo;

    for( tb ; tb->anterior != NULL ; tb = tb->anterior)
        printf("%d ",tb->raio);
    printf("%d \n",tb->raio);

}


int main () {
    base *b1 = criaBase();
    base *b2 = criaBase();

    push(b2,pop(b1));

    push(b1,3);
    push(b1,2);
    push(b1,1);

    imprimeBase(b1);

    push(b2,pop(b1));
    push(b1,4);
    push(b2,pop(b1));
    push(b2,pop(b1));
    push(b2,pop(b1));

    imprimeBase(b2);



}