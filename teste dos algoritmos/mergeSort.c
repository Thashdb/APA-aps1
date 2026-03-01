#include <stdio.h>
#include <stdlib.h>

// Função para imprimir o vetor
void imprimirVetor(int A[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int p, int q, int r) {

    printf("\n--- Merge chamado para p=%d, q=%d, r=%d ---\n", p, q, r);

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

    printf("Metade esquerda: ");
    for(int i = 0; i < n1; i++) printf("%d ", L[i]);
    printf("\n");

    printf("Metade direita: ");
    for(int j = 0; j < n2; j++) printf("%d ", R[j]);
    printf("\n");

    int i = 0, j = 0, k = p;

    // intercala
    while (i < n1 && j < n2) {
        printf("\nComparando L[%d]=%d e R[%d]=%d\n", i, L[i], j, R[j]);

        if (L[i] <= R[j]) {
            printf("-> Colocando %d no vetor principal\n", L[i]);
            A[k] = L[i];
            i++;
        } else {
            printf("-> Colocando %d no vetor principal\n", R[j]);
            A[k] = R[j];
            j++;
        }
        k++;

        printf("Vetor atual: ");
        imprimirVetor(A, 6);
    }

    // copia o restante (se sobrar)
    while (i < n1) {
        printf("\nRestou L[%d]=%d, copiando...\n", i, L[i]);
        A[k++] = L[i++];
        imprimirVetor(A, 6);
    }

    while (j < n2) {
        printf("\nRestou R[%d]=%d, copiando...\n", j, R[j]);
        A[k++] = R[j++];
        imprimirVetor(A, 6);
    }

    free(L);
    free(R);

    printf("--- Merge finalizado ---\n");
}

// ================= MERGE SORT =================

void mergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;

        printf("\nDividindo vetor: p=%d, q=%d, r=%d\n", p, q, r);

        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

// ================= MAIN =================

int main() {

    int A[6] = {8, 3, 6, 2, 7, 1};

    printf("Vetor inicial:\n");
    imprimirVetor(A, 6);

    mergeSort(A, 0, 5);

    printf("\nVetor ordenado:\n");
    imprimirVetor(A, 6);

    return 0;
}