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

    int A[] = {3, 2, 4, 5, 1};
    int n = 5;
    int i_min, temp;

    printf("Vetor inicial:\n");
    imprimirVetor(A, n, 0);
    printf("\n");

    for (int i = 0; i < n - 1; i++) {

        printf("=== Iteracao %d ===\n", i + 1);

        i_min = i;

        for(int j = i + 1; j < n; j++){
            if(A[j] < A[i_min]){
                i_min = j;
            }
        }

        printf("Menor elemento encontrado: %d (indice %d)\n", A[i_min], i_min);

        if (i_min != i){
            printf("Trocando %d com %d\n", A[i], A[i_min]);
            temp = A[i];
            A[i] = A[i_min];
            A[i_min] = temp;
        } else {
            printf("Nenhuma troca necessaria\n");
        }

        printf("Estado do vetor:\n");
        imprimirVetor(A, n, i + 1);
        printf("\n");
    }

    printf("Vetor ordenado final:\n");
    imprimirVetor(A, n, n);

    return 0;
}