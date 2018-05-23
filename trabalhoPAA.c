//
// Created by timoteo on 06/04/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritmos/utilidades.h"
#include "algoritmos/metodosOrdenacao.h"

void testesAleatorios() {
    int numeroTestes = 11;
    int tamanhos[11] = {100,500,1000,2000,4000,8000,16000,32000,64000,128000,256000};
    int *vetorInteiro;


    //quick sort
    FILE *f = fopen("qA.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando quick sort com %i elementos: \n", tamanhos[i]);
        vetorInteiro = criaArrayInteiros(tamanhos[i]);


        clock_t begin = clock();
        quickSort(vetorInteiro,0,tamanhos[i]);
        clock_t end = clock();

        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);
}

void testesOrdenados() {
    int numeroTestes = 11;
    int tamanhos[11] = {100,500,1000,2000,4000,8000,16000,32000,64000,128000,256000};
    int *vetorInteiro = (int*)malloc( tamanhos[10] * sizeof(int));

    for(int i = 0; i < tamanhos[10]; i++) vetorInteiro[i] = i;


    //quick sort
    FILE *f = fopen("qO.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando quick sort com %i elementos: \n", tamanhos[i]);

        clock_t begin = clock();
        quickSort(vetorInteiro,0,tamanhos[i]);
        clock_t end = clock();

        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);
}

void testesInversos() {
    int numeroTestes = 11;
    int tamanhos[11] = {100,500,1000,2000,4000,8000,16000,32000,64000,128000,256000};
    int *vetorInteiro = (int*)malloc( tamanhos[10] * sizeof(int));

    for(int j = 0; j < tamanhos[10]; j++) vetorInteiro[j] = tamanhos[10] - j;

    //bubble sort
    FILE *f = fopen("bI.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando bubble sort com %i elementos: \n", tamanhos[i]);

        clock_t begin = clock();
        bubbleSort(vetorInteiro,tamanhos[i]);
        clock_t end = clock();

        for(int j = 0; j < tamanhos[i]; j++) vetorInteiro[j] = tamanhos[i] - j;

        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);

    //insertion sort
    f = fopen("iI.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando insertion sort com %i elementos: \n", tamanhos[i]);

        clock_t begin = clock();
        insertionSort(vetorInteiro,tamanhos[i]);
        clock_t end = clock();

        for(int j = 0; j < tamanhos[i]; j++) vetorInteiro[j] = tamanhos[i] - j;


        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);

    //selection sort
    f = fopen("sI.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando selection sort com %i elementos: \n", tamanhos[i]);

        clock_t begin = clock();
        selectionSort(vetorInteiro,tamanhos[i]);
        clock_t end = clock();

        for(int j = 0; j < tamanhos[i]; j++) vetorInteiro[j] = tamanhos[i] - j;


        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);

    //merge sort
    f = fopen("mI.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando merge sort com %i elementos: \n", tamanhos[i]);

        clock_t begin = clock();
        mergeSort(vetorInteiro,0,tamanhos[i]-1);
        clock_t end = clock();

        for(int j = 0; j < tamanhos[i]; j++) vetorInteiro[j] = tamanhos[i] - j;


        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);

    //quick sort
    f = fopen("qI.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando quick sort com %i elementos: \n", tamanhos[i]);

        clock_t begin = clock();
        quickSort(vetorInteiro,0,tamanhos[i]);
        clock_t end = clock();

        for(int j = 0; j < tamanhos[i]; j++) vetorInteiro[j] = tamanhos[i] - j;

        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);
}

int main() {
    //testesAleatorios();
    //testesOrdenados();
    testesInversos();
}