//
// Created by timoteo on 15/03/18.
//

#ifndef AED_UTILIDADES_H
#define AED_UTILIDADES_H

#define RAND_MAX 2000000

struct operacaoDados {
    int (*cmp)(void *isso, void *aquilo);
    int (*tipoDado)(void *dado);
};


void troca(int *a, int *b);
int *criaArrayInteiros(int tamanho);
void imprimeArrayInteiros(int *vetor, int tamanho);
void deletaArrayInteiros(int *vetor);

int comparaDados(void *isso, void *aquilo);
int voidParaInteiro(void *valor);

unsigned long hash_djb2(unsigned char *str);



#endif //AED_UTILIDADES_H
