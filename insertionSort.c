#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ================= INSERTION SORT ================= */
// função que realiza o insertion sort e ordena o vetor

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
// em segundos

double medirTempo(int A[], int n) {

    int *copia = malloc(n * sizeof(int)); // aloca memoria dinamicamente para a copia do vetor A

    for (int i = 0; i < n; i++)
        copia[i] = A[i];    // copia os elementos de A

    clock_t inicio = clock();   // inicia medição

    insertionSort(copia, n);    // ordena

    clock_t fim = clock();      // marca o fim da ordenação

    free(copia);

    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

/* ================= MAIN ================= */

int main() {

    FILE *arquivo = fopen("output/entrada100k.txt", "r");

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

    printf("===== Insertion Sort (%d elementos) =====\n", n);

    printf("Aleatorio: %f segundos\n", medirTempo(aleatorio, n));
    printf("Repetido:  %f segundos\n", medirTempo(repetido, n));
    printf("Ordenado:  %f segundos (melhor caso Omega(n))\n", medirTempo(ordenado, n));
    printf("Inverso:   %f segundos (pior caso O(n^2))\n", medirTempo(inverso, n));

    free(aleatorio);
    free(repetido);
    free(ordenado);
    free(inverso);

    return 0;
}