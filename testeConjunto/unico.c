#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ================= TROCA ================= */
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* ================= INSERTION SORT ================= */
void insertionSort(int A[], int n){
    int pivo, j;

    for(int i = 1; i < n; i++){
        pivo = A[i];
        j = i - 1;

        while(j >= 0 && A[j] > pivo){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = pivo;
    }
}

/* ================= SELECTION SORT ================= */
void selectionSort(int A[], int n){
    int i_min;

    for(int i = 0; i < n - 1; i++){
        i_min = i;
        for(int j = i + 1; j < n; j++){
            if(A[j] < A[i_min])
                i_min = j;
        }
        if(i_min != i)
            swap(&A[i], &A[i_min]);
    }
}

/* ================= MERGE SORT ================= */

void merge(int A[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for(int i = 0; i < n1; i++)
        L[i] = A[p + i];

    for(int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    int i = 0, j = 0, k = p;

    while(i < n1 && j < n2){
        if(L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while(i < n1)
        A[k++] = L[i++];

    while(j < n2)
        A[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int A[], int p, int r){
    if(p < r){
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

/* ================= QUICK SORT (HOARE) ================= */

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

/* ================= MEDIÇÃO GENÉRICA ================= */

double medirTempoInsertion(int A[], int n){
    int *copia = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) copia[i] = A[i];

    clock_t inicio = clock();
    insertionSort(copia, n);
    clock_t fim = clock();

    free(copia);
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

double medirTempoSelection(int A[], int n){
    int *copia = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) copia[i] = A[i];

    clock_t inicio = clock();
    selectionSort(copia, n);
    clock_t fim = clock();

    free(copia);
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

double medirTempoMerge(int A[], int n){
    int *copia = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) copia[i] = A[i];

    clock_t inicio = clock();
    mergeSort(copia, 0, n - 1);
    clock_t fim = clock();

    free(copia);
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

double medirTempoQuick(int A[], int n){
    int *copia = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) copia[i] = A[i];

    clock_t inicio = clock();
    quickSort(copia, 0, n - 1);
    clock_t fim = clock();

    free(copia);
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

/* ================= MAIN ================= */

int main(){

    srand(time(NULL));

    FILE *arquivo = fopen("../entrada500k.txt", "r");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    int n;
    fscanf(arquivo, "%d", &n);

    int *aleatorio = malloc(n * sizeof(int));
    int *repetido  = malloc(n * sizeof(int));
    int *ordenado  = malloc(n * sizeof(int));
    int *inverso   = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) fscanf(arquivo, "%d", &aleatorio[i]);
    for(int i = 0; i < n; i++) fscanf(arquivo, "%d", &repetido[i]);
    for(int i = 0; i < n; i++) fscanf(arquivo, "%d", &ordenado[i]);
    for(int i = 0; i < n; i++) fscanf(arquivo, "%d", &inverso[i]);

    fclose(arquivo);

    printf("\n===== RESULTADOS (%d elementos) =====\n\n", n);

    printf("---- Insertion Sort ----\n");
    printf("Aleatorio: %f\n", medirTempoInsertion(aleatorio, n));
    printf("Repetido:  %f\n", medirTempoInsertion(repetido, n));
    printf("Ordenado:  %f\n", medirTempoInsertion(ordenado, n));
    printf("Inverso:   %f\n\n", medirTempoInsertion(inverso, n));

    printf("---- Selection Sort ----\n");
    printf("Aleatorio: %f\n", medirTempoSelection(aleatorio, n));
    printf("Repetido:  %f\n", medirTempoSelection(repetido, n));
    printf("Ordenado:  %f\n", medirTempoSelection(ordenado, n));
    printf("Inverso:   %f\n\n", medirTempoSelection(inverso, n));

    printf("---- Merge Sort ----\n");
    printf("Aleatorio: %f\n", medirTempoMerge(aleatorio, n));
    printf("Repetido:  %f\n", medirTempoMerge(repetido, n));
    printf("Ordenado:  %f\n", medirTempoMerge(ordenado, n));
    printf("Inverso:   %f\n\n", medirTempoMerge(inverso, n));

    printf("---- Quick Sort (Hoare) ----\n");
    printf("Aleatorio: %f\n", medirTempoQuick(aleatorio, n));
    printf("Repetido:  %f\n", medirTempoQuick(repetido, n));
    printf("Ordenado:  %f\n", medirTempoQuick(ordenado, n));
    printf("Inverso:   %f\n\n", medirTempoQuick(inverso, n));


    free(aleatorio);
    free(repetido);
    free(ordenado);
    free(inverso);

    return 0;
}