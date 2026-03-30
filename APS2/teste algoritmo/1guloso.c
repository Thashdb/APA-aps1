#include <stdio.h>
#include <stdlib.h>

// estrutura
typedef struct {
    int peso;
    int valor;
    float razao;
} Item;

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

    while (i < n1 && j < n2) {
        if (L[i].razao >= R[j].razao) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
        A[k++] = L[i++];

    while (j < n2)
        A[k++] = R[j++];

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
    int capacidade = 2;

    Item itens[3] = {
        {1, 10, 0},
        {1, 20, 0},
        {1, 30, 0}
    };

    // calcula razão
    for (int i = 0; i < n; i++) {
        itens[i].razao = (float)itens[i].valor / itens[i].peso;
    }

    // ordenação (sem prints)
    mergeSort(itens, 0, n - 1);

    int pesoAtual = 0;
    int valorTotal = 0;

    printf("=== EXECUTANDO ALGORITMO GULOSO ===\n");

    for (int i = 0; i < n; i++) {

        printf("\nAnalisando item %d:\n", i);
        printf("Peso = %d | Valor = %d | Razao = %.2f\n",
                itens[i].peso, itens[i].valor, itens[i].razao);

        printf("Peso atual da mochila: %d / %d\n", pesoAtual, capacidade);

        if (pesoAtual + itens[i].peso <= capacidade) {
            printf("-> Cabe! Item ADICIONADO\n");

            pesoAtual += itens[i].peso;
            valorTotal += itens[i].valor;

            printf("Novo peso: %d | Novo valor: %d\n",
                    pesoAtual, valorTotal);
        } else {
            printf("-> Nao cabe! Item IGNORADO\n");
        }
    }

    printf("\n=== RESULTADO FINAL ===\n");
    printf("Peso total na mochila: %d\n", pesoAtual);
    printf("Valor total obtido: %d\n", valorTotal);

    return 0;
}