//
// Created by timoteo on 06/04/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritmos/utilidades.h"
#include "algoritmos/metodosOrdenacao.h"

#define MAX 12




int main() {
    int numeroTestes = MAX;
    int tamanhos[MAX] = {100,500,1000,2000,4000,8000,16000,32000,64000,128000,256000,512000};



/*
    //bubble sort
    FILE *f = fopen("bubblesort.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando bubble sort com %i elementos: \n", tamanhos[i]);

        vetorInteiro = criaArrayInteiros(tamanhos[i]);
        //printf("Pré: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);

        clock_t begin = clock();
        bubbleSort(vetorInteiro,tamanhos[i]);
        clock_t end = clock();

        //printf("Pós: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);

    //insertion sort
    f = fopen("insertionsort.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando insertion sort com %i elementos: \n", tamanhos[i]);

        vetorInteiro = criaArrayInteiros(tamanhos[i]);
        //printf("Pré: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);

        clock_t begin = clock();
        insertionSort(vetorInteiro,tamanhos[i]);
        clock_t end = clock();

        //printf("Pós: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);

    //selection sort
    f = fopen("selectionsort.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando selection sort com %i elementos: \n", tamanhos[i]);

        vetorInteiro = criaArrayInteiros(tamanhos[i]);
        //printf("Pré: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);

        clock_t begin = clock();
        selectionSort(vetorInteiro,tamanhos[i]);
        clock_t end = clock();

        //printf("Pós: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);

    //merge sort
    f = fopen("mergesort.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando merge sort com %i elementos: \n", tamanhos[i]);

        vetorInteiro = criaArrayInteiros(tamanhos[i]);
        //printf("Pré: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);

        clock_t begin = clock();
        mergeSort(vetorInteiro,0,tamanhos[i]);
        clock_t end = clock();

        //printf("Pós: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);

    //quick sort
    f = fopen("quicksort.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando quick sort com %i elementos: \n", tamanhos[i]);

        vetorInteiro = criaArrayInteiros(tamanhos[i]);
        //printf("Pré: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);

        clock_t begin = clock();
        quickSort(vetorInteiro,0,tamanhos[i]);
        clock_t end = clock();

        //printf("Pós: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);

 */

    /*
     *
     *
     *
     * Agora os testes são com um vetor já ordenado.
     *
     *
     *
     *
     */

    int * vetorInteiro = (int*)malloc(tamanhos[MAX] * sizeof(int));
    for(int i = 0; i < tamanhos[MAX]; i++)
        vetorInteiro[i] = i+1;


    //bubble sort
    FILE *f = fopen("bubblesort_ordenado.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando bubble sort com %i elementos: \n", tamanhos[i]);

        //printf("Pré: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);

        clock_t begin = clock();
        bubbleSort(vetorInteiro,tamanhos[i]);
        clock_t end = clock();

        //printf("Pós: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);

    //insertion sort
    f = fopen("insertionsort_ordenado.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando insertion sort com %i elementos: \n", tamanhos[i]);

        //printf("Pré: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);

        clock_t begin = clock();
        insertionSort(vetorInteiro,tamanhos[i]);
        clock_t end = clock();

        //printf("Pós: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);

    //selection sort
    f = fopen("selectionsort_ordenado.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando selection sort com %i elementos: \n", tamanhos[i]);

        //printf("Pré: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);

        clock_t begin = clock();
        selectionSort(vetorInteiro,tamanhos[i]);
        clock_t end = clock();

        //printf("Pós: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);

    //merge sort
    f = fopen("mergesort_ordenado.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando merge sort com %i elementos: \n", tamanhos[i]);

        //printf("Pré: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);

        clock_t begin = clock();
        mergeSort(vetorInteiro,0,tamanhos[i]);
        clock_t end = clock();

        //printf("Pós: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);

    //quick sort
    f = fopen("quicksort_ordenado.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando quick sort com %i elementos: \n", tamanhos[i]);

        //printf("Pré: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);

        clock_t begin = clock();
        quickSort(vetorInteiro,0,tamanhos[i]);
        clock_t end = clock();

        //printf("Pós: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);

    /*
   *
   *
   *
   * Agora os testes são com um vetor inversamente ordenado.
   *
   *
   *
   *
   */

    for(int i = 0; i < tamanhos[MAX]; i++)
        vetorInteiro[i] = tamanhos[MAX] - i;

    int * coisa = vetorInteiro;

    //bubble sort
    f = fopen("bubblesort_inverso.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando bubble sort com %i elementos: \n", tamanhos[i]);

        //printf("Pré: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);

        clock_t begin = clock();
        bubbleSort(coisa,tamanhos[i]);
        clock_t end = clock();

        coisa = vetorInteiro;
        //printf("Pós: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);

    //insertion sort
    f = fopen("insertionsort_inverso.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando insertion sort com %i elementos: \n", tamanhos[i]);

        //printf("Pré: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);

        clock_t begin = clock();
        insertionSort(coisa,tamanhos[i]);
        clock_t end = clock();

        coisa = vetorInteiro;
        //printf("Pós: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);

    //selection sort
    f = fopen("selectionsort_inverso.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando selection sort com %i elementos: \n", tamanhos[i]);

        //printf("Pré: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);

        clock_t begin = clock();
        selectionSort(coisa,tamanhos[i]);
        clock_t end = clock();

        coisa = vetorInteiro;
        //printf("Pós: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);

    //merge sort
    f = fopen("mergesort_inverso.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando merge sort com %i elementos: \n", tamanhos[i]);

        //printf("Pré: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);

        clock_t begin = clock();
        mergeSort(coisa,0,tamanhos[i]);
        clock_t end = clock();

        coisa = vetorInteiro;
        //printf("Pós: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);

    //quick sort
    f = fopen("quicksort_inverso.dat","w");
    for(int i = 0; i < numeroTestes; i++) {
        printf("\nIniciando quick sort com %i elementos: \n", tamanhos[i]);

        //printf("Pré: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);

        clock_t begin = clock();
        quickSort(coisa,0,tamanhos[i]);
        clock_t end = clock();

        coisa = vetorInteiro;
        //printf("Pós: "); imprimeArrayInteiros(vetorInteiro, tamanhos[i]);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo para %i elementos: %lf segundos: \n", tamanhos[i],time_spent);
        fprintf(f,"%i,%lf\n",tamanhos[i],time_spent);
        printf("\n");
    }
    fclose(f);





}