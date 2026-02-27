#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// troca
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// QUICK SORT (Hoare)

int partition(int A[], int inicio, int fim){
    //  pivo fixo no inicio

    int pivo = A[inicio];
    int i = inicio - 1;
    int j = fim + 1;

    while(1){
        do{
            i++;
        } while(A[i] < pivo);
        do{
            j--;
        } while(A[j] > pivo);
        if(i >= j){
            return j;
        }
        swap(&A[i], &A[j]);
    }
}

void quickSort(int A[], int left, int right){

    if(left < right){
        int q = partition(A, left, right);
        quickSort(A, left, q);
        quickSort(A, q + 1, right);
    }
}

/* ================= MEDIÇÃO ================= */

double medirTempo(int A[], int n) {

    int *copia = malloc(n * sizeof(int));
    if (copia == NULL) return 0;

    for (int i = 0; i < n; i++)
        copia[i] = A[i];

    clock_t inicio = clock();

    quickSort(copia, 0, n - 1);  // ✅ agora está correto

    clock_t fim = clock();

    free(copia);

    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

/* ================= MAIN ================= */

int main() {

    FILE *arquivo = fopen("entrada100k.txt", "r");

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

    printf("===== Quick Sort (Hoare) (%d elementos) =====\n", n);

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