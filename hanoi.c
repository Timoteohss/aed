#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define clear() printf("\033[H\033[J")

typedef struct no{
    char *nome;
    struct no *anterior;
}no;

typedef struct fila{
    struct no *inicio;
    struct no *fim;
}fila;

void enqueue(char *nome, fila *f1){
    no *pessoas = (no*)malloc(sizeof(no));
    pessoas->nome = nome;
    if(!f1->fim && !f1->inicio){
        f1->inicio=pessoas;
        f1->fim=pessoas;
    }else{
        pessoas->anterior=f1->fim;
        f1->fim=pessoas;
    }
}

char * dequeue(fila *f1){

    if(!f1->fim && !f1->inicio){
        return NULL;
    }

    if(f1->inicio==f1->fim){
        no *excluir = f1->fim;
        char *nome= f1->inicio->nome;
        free(excluir);
        f1->fim=f1->inicio=NULL;
        return nome;
    }

    no *temp=f1->fim;
    for(temp; temp->anterior!=f1->inicio;temp=temp->anterior);
    char *nome=temp->anterior->nome;
    no *excluir = temp->anterior;
    temp->anterior=f1->inicio->anterior;
    free(excluir);
    f1->inicio=temp;

    return nome;
}

fila *criar(){
    fila *temp= (fila*)malloc(sizeof(fila));
    temp->inicio=temp->fim=NULL;
    return temp;
}


int main()
{
    char * nome1 = "Timoteo";
    char * nome2 = "Jeferson";
    char * nome3 = "Teste";

    fila * f1 = criar();

    enqueue(nome1,f1);
    enqueue(nome2,f1);
    printf("\n%s",dequeue(f1));

    printf("\n%s",dequeue(f1));
    enqueue(nome3,f1);
    printf("\n%s",dequeue(f1));

    exit(1);


}