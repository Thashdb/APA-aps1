#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// O(nlogn) por conta do merge sort


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

    for (int i = 0; i < n1; i++) L[i] = A[p + i];
    for (int j = 0; j < n2; j++) R[j] = A[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if (L[i].razao >= R[j].razao)
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while (i < n1) A[k++] = L[i++];
    while (j < n2) A[k++] = R[j++];

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

// ================= GULOSO =================
int guloso(Item itens[], int n, int capacidade) {

    for (int i = 0; i < n; i++)
        itens[i].razao = (float)itens[i].valor / itens[i].peso;

    mergeSort(itens, 0, n - 1);

    int pesoAtual = 0, valorTotal = 0;

    for (int i = 0; i < n; i++) {
        if (pesoAtual + itens[i].peso <= capacidade) {
            pesoAtual += itens[i].peso;
            valorTotal += itens[i].valor;
        }
    }

    return valorTotal;
}

// ================= TEMPO =================
double medirTempo(Item itens[], int n, int capacidade) {

    Item *copia = malloc(n * sizeof(Item));

    for (int i = 0; i < n; i++)
        copia[i] = itens[i];

    clock_t inicio = clock();

    guloso(copia, n, capacidade);

    clock_t fim = clock();

    free(copia);

    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

// ================= MAIN =================
int main() {

    // lista de arquivos
char *arquivos[] = {
    "../arquivos/teste_20_10.txt",
    "../arquivos/teste_50_30.txt",
    "../arquivos/teste_100_30.txt",
    "../arquivos/teste_200_50.txt",
    "../arquivos/teste_500_10.txt",
    "../arquivos/teste_500_100.txt",
    "../arquivos/teste_1000_50.txt",
    "../arquivos/teste_10000_100.txt",
    "../arquivos/teste_500000_100.txt"
};

    int qtd = sizeof(arquivos) / sizeof(arquivos[0]);

    printf("=== TESTES AUTOMATICOS ===\n\n");

    for (int t = 0; t < qtd; t++) {

        FILE *f = fopen(arquivos[t], "r");

        if (f == NULL) {
            printf("Erro ao abrir %s\n", arquivos[t]);
            continue;
        }

        int n, capacidade;
        fscanf(f, "%d %d", &n, &capacidade);

        Item *itens = malloc(n * sizeof(Item));

        for (int i = 0; i < n; i++) {
            fscanf(f, "%d %d", &itens[i].peso, &itens[i].valor);
        }

        fclose(f);

        double tempo = medirTempo(itens, n, capacidade);

        printf("Arquivo: %s\n", arquivos[t]);
        printf("Itens: %d | Tempo: %f segundos\n\n", n, tempo);

        free(itens);
    }

    return 0;
}