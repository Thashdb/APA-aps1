#include <stdio.h>
#include <stdlib.h>

//  estrutura para cada item

typedef struct {
    int peso;
    int valor;
    float razao;
} Item;


// ordenação
//     devido ao tempo de execução a melhor escolha é 

// ================= MERGE =================

void merge(Item A[], int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    Item *L = malloc(n1 * sizeof(Item));
    Item *R = malloc(n2 * sizeof(Item));

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];

    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    int i = 0, j = 0, k = p;

    // 🔥 aqui está a diferença: comparar pela razão
    while (i < n1 && j < n2) {
        if (L[i].razao >= R[j].razao) { // ordem decrescente
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

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
void mergeSort(Item A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main() {
    int n = 3;
    int capacidade = 50;

    Item itens[3] = {
        {10, 60, 0},
        {20, 100, 0},
        {30, 120, 0}
    };

    // Calcula razão valor/peso
    for (int i = 0; i < n; i++) {
        itens[i].razao = (float)itens[i].valor / itens[i].peso;
    }

    // Ordena os itens
    mergeSort(itens, 0, n - 1);

    int pesoAtual = 0;
    int valorTotal = 0;

    printf("Itens escolhidos:\n");

    // Algoritmo guloso
    for (int i = 0; i < n; i++) {
        if (pesoAtual + itens[i].peso <= capacidade) {
            pesoAtual += itens[i].peso;
            valorTotal += itens[i].valor;

            printf("Peso: %d | Valor: %d\n", itens[i].peso, itens[i].valor);
        }
    }

    printf("\nPeso total: %d\n", pesoAtual);
    printf("Valor total: %d\n", valorTotal);

    return 0;
}