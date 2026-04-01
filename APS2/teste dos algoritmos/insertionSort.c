#include <stdio.h>

void imprimirVetor(int A[], int n, int limiteOrdenado) {
    for (int i = 0; i < n; i++) {
        if (i == limiteOrdenado)
            printf("| ");  // separa parte ordenada
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main (){

    int A[] = {5, 2, 1, 4, 3};
    int n = 5;

    printf("Vetor inicial:\n");
    imprimirVetor(A, n, 1); // no insertion o primeiro já começa ordenado
    printf("\n");

    for (int i = 1; i < n; i++) {

        printf("=== Iteracao %d ===\n", i);

        int chave = A[i];
        int j = i - 1;

        printf("Elemento a inserir: %d\n", chave);

        // deslocamento
        while (j >= 0 && A[j] > chave) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = chave;

        printf("Estado do vetor:\n");
        imprimirVetor(A, n, i + 1);
        printf("\n");
    }

    printf("Vetor ordenado final:\n");
    imprimirVetor(A, n, n);

    return 0;
}