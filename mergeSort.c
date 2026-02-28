#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ================= MERGE =================

void merge(int A[], int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    // copia metade esquerda
    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];

    // copia metade direita
    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    int i = 0, j = 0, k = p;

    // intercala
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // copia o restante (se sobrar)
    while (i < n1) {
        A[k++] = L[i++];
    }

    while (j < n2) {
        A[k++] = R[j++];
    }

    free(L);
    free(R);
}

// ================= MERGE SORT =================

void mergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

// ================= MEDIÇÃO =================
// em segundos

double medirTempo(int A[], int n) {

    int *copia = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        copia[i] = A[i];

    clock_t inicio = clock();

    mergeSort(copia, 0, n - 1);

    clock_t fim = clock();

    free(copia);

    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

// ================= MAIN =================

int main() {

    FILE *arquivo = fopen("output/entrada1000k.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    int n;
    fscanf(arquivo, "%d", &n);

    int *aleatorio = malloc(n * sizeof(int));
    int *repetido  = malloc(n * sizeof(int));
    int *ordenado  = malloc(n * sizeof(int));
    int *inverso   = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) fscanf(arquivo, "%d", &aleatorio[i]);
    for (int i = 0; i < n; i++) fscanf(arquivo, "%d", &repetido[i]);
    for (int i = 0; i < n; i++) fscanf(arquivo, "%d", &ordenado[i]);
    for (int i = 0; i < n; i++) fscanf(arquivo, "%d", &inverso[i]);

    fclose(arquivo);

    printf("===== Merge Sort (%d elementos) =====\n", n);

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