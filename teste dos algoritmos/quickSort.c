#include <stdio.h>

// Função para imprimir vetor
void imprimir(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// troca
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// hoare com impressão
int partition(int A[], int inicio, int fim, int n){

    int pivo = A[inicio];
    int i = inicio - 1;
    int j = fim + 1;

    printf("\n--- Nova Particao ---\n");
    printf("Subvetor: ");
    imprimir(A, n);
    printf("Pivo: %d (indice %d)\n", pivo, inicio);

    while(1){
        do{
            i++;
        } while(A[i] < pivo);

        do{
            j--;
        } while(A[j] > pivo);

        printf("i = %d, j = %d\n", i, j);

        if(i >= j){
            printf("Particao terminou. Retorna %d\n", j);
            return j;
        }

        printf("Trocando %d e %d\n", A[i], A[j]);
        swap(&A[i], &A[j]);

        printf("Vetor apos troca: ");
        imprimir(A, n);
    }
}

void quickSort(int A[], int left, int right, int n){

    if(left < right){
        int q = partition(A, left, right, n);
        quickSort(A, left, q, n);
        quickSort(A, q+1, right, n);
    }
}

int main(){

    int A[] = {3, 2, 4, 5, 1, 6};
    int n = 6;

    printf("Vetor inicial: ");
    imprimir(A, n);

    quickSort(A, 0, n - 1, n);

    printf("\nVetor ordenado final: ");
    imprimir(A, n);

    return 0;
}