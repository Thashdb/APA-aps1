#include <stdio.h>
#include <stdlib.h>

void gerarAleatorio(int A[], int n) {
    for (int i = 0; i < n; i++)
        A[i] = rand();
}

void gerarPoucosValores(int A[], int n) {
    for (int i = 0; i < n; i++)
        A[i] = rand() % 5;
}

void gerarOrdenado(int A[], int n) {
    for (int i = 0; i < n; i++)
        A[i] = i;
}

void gerarInverso(int A[], int n) {
    for (int i = 0; i < n; i++)
        A[i] = n - i;
}

void salvarVetor(FILE *fp, int A[], int n) {
    for (int i = 0; i < n; i++)
        fprintf(fp, "%d ", A[i]);
    fprintf(fp, "\n");
}

int main() {

    int n = 10000;   // 🔹 tamanho fixo (você pode alterar aqui)

    FILE *fp = fopen("entrada10k.txt", "w");

    if (fp == NULL) {
        printf("Erro ao criar arquivo.\n");
        return 1;
    }

    fprintf(fp, "%d\n", n);  // primeira linha salva o tamanho

    int *A = malloc(n * sizeof(int));

    // 1️⃣ Aleatório
    gerarAleatorio(A, n);
    salvarVetor(fp, A, n);

    // 2️⃣ Muitos repetidos
    gerarPoucosValores(A, n);
    salvarVetor(fp, A, n);

    // 3️⃣ Ordenado
    gerarOrdenado(A, n);
    salvarVetor(fp, A, n);

    // 4️⃣ Inverso
    gerarInverso(A, n);
    salvarVetor(fp, A, n);


    free(A);
    fclose(fp);

    printf("Arquivo entrada.txt gerado com sucesso!\n");

    return 0;
}