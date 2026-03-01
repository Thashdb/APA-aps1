#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// SELECTION SORT
void selectionSort(int A[], int n){
    int i_min, temp;

    for (int i = 0; i < n - 1; i++) {
        i_min = i;
        for(int j = i + 1; j < n; j++){
            if(A[j] < A[i_min]){
                i_min = j;
            }
        }
        if (i_min != i){
            temp = A[i];
            A[i] = A[i_min];
            A[i_min] = temp;
        }
    }
}

/* ================= MEDIÇÃO ================= */
// em segundos

double medirTempo(int A[], int n) {

    int *copia = malloc(n * sizeof(int)); // aloca memoria dinamicamente para a copia do vetor A

    for (int i = 0; i < n; i++)
        copia[i] = A[i];    // copia os elementos de A

    clock_t inicio = clock();   // inicia medição

    selectionSort(copia, n);    // ordena

    clock_t fim = clock();      // marca o fim da ordenação

    free(copia);

    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

/* ================= MAIN ================= */

int main() {

    FILE *arquivo = fopen("output/entrada20k.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    int n;
    fscanf(arquivo, "%d", &n);   // lê tamanho

    // Aloca 4 vetores
    int *aleatorio = malloc(n * sizeof(int));
    int *repetido  = malloc(n * sizeof(int));
    int *ordenado  = malloc(n * sizeof(int));
    int *inverso   = malloc(n * sizeof(int));

    // Lê os 4 vetores
    for (int i = 0; i < n; i++) fscanf(arquivo, "%d", &aleatorio[i]);
    for (int i = 0; i < n; i++) fscanf(arquivo, "%d", &repetido[i]);
    for (int i = 0; i < n; i++) fscanf(arquivo, "%d", &ordenado[i]);
    for (int i = 0; i < n; i++) fscanf(arquivo, "%d", &inverso[i]);

    fclose(arquivo);

    printf("===== Selection Sort (%d elementos) =====\n", n);

    printf("Aleatorio: %f segundos\n", medirTempo(aleatorio, n));
    printf("Repetido:  %f segundos\n", medirTempo(repetido, n));
    printf("Ordenado:  %f segundos\n", medirTempo(ordenado, n));
    printf("Inverso:   %f segundos\n", medirTempo(inverso, n));
    printf("sempre O(n^2)");

    free(aleatorio);
    free(repetido);
    free(ordenado);
    free(inverso);

    return 0;
}