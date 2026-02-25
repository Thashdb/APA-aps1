#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ================= INSERTION SORT ================= */

void insertionSort(int A[], int n) {
    int pivo, j;

    for (int i = 1; i < n; i++) {
        pivo = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > pivo) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = pivo;
    }
}

/* ================= MEDIÇÃO ================= */

double medirTempo(int A[], int n) {

    int *copia = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        copia[i] = A[i];

    clock_t inicio = clock();

    insertionSort(copia, n);

    clock_t fim = clock();

    free(copia);

    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

/* ================= MAIN ================= */

int main() {

    FILE *fp = fopen("entrada10k.txt", "r");

    if (fp == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    int n;
    fscanf(fp, "%d", &n);   // lê tamanho

    // Aloca 4 vetores
    int *aleatorio = malloc(n * sizeof(int));
    int *repetido  = malloc(n * sizeof(int));
    int *ordenado  = malloc(n * sizeof(int));
    int *inverso   = malloc(n * sizeof(int));

    // Lê os 4 vetores
    for (int i = 0; i < n; i++) fscanf(fp, "%d", &aleatorio[i]);
    for (int i = 0; i < n; i++) fscanf(fp, "%d", &repetido[i]);
    for (int i = 0; i < n; i++) fscanf(fp, "%d", &ordenado[i]);
    for (int i = 0; i < n; i++) fscanf(fp, "%d", &inverso[i]);

    fclose(fp);

    printf("===== Insertion Sort (%d elementos) =====\n", n);

    printf("Aleatorio: %f segundos\n", medirTempo(aleatorio, n));
    printf("Repetido:  %f segundos\n", medirTempo(repetido, n));
    printf("Ordenado:  %f segundos\n", medirTempo(ordenado, n));
    printf("Inverso:   %f segundos\n", medirTempo(inverso, n));

    free(aleatorio);
    free(repetido);
    free(ordenado);
    free(inverso);

    return 0;
}