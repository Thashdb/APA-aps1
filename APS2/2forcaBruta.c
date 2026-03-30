#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// para cada item tem duas escolhas
//    - colocar o item na mochila
//    - nao colocar o item

//  O(2^n)


int max(int a, int b){
    return (a > b) ? a : b;
}

// ================= FORÇA BRUTA =================
int knapsack(int n, int M, int peso[], int valor[]) {

    if (n == 0 || M == 0)
        return 0;

    if (peso[n-1] > M)
        return knapsack(n-1, M, peso, valor);

    return max(
        knapsack(n-1, M - peso[n-1], peso, valor) + valor[n-1],
        knapsack(n-1, M, peso, valor)
    );
}

// ================= TEMPO =================
double medirTempo(int peso[], int valor[], int n, int M) {

    clock_t inicio = clock();

    knapsack(n, M, peso, valor);

    clock_t fim = clock();

    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

// ================= MAIN =================
int main() {

    // SOMENTE ARQUIVOS PEQUENOS
char *arquivos[] = {
    "../arquivos/teste_20_10.txt",
    "../arquivos/teste_50_30.txt",
    "../arquivos/teste_100_30.txt",
    "../arquivos/teste_200_50.txt",
    "../arquivos/teste_500_10.txt",
    "../arquivos/teste_500_100.txt",
};

    int qtd = sizeof(arquivos) / sizeof(arquivos[0]);

    printf("=== FORCA BRUTA ===\n\n");

    for (int t = 0; t < qtd; t++) {

        FILE *f = fopen(arquivos[t], "r");

        if (f == NULL) {
            printf("Erro ao abrir %s\n", arquivos[t]);
            continue;
        }

        int n, M;
        fscanf(f, "%d %d", &n, &M);

        int *peso = malloc(n * sizeof(int));
        int *valor = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            fscanf(f, "%d %d", &peso[i], &valor[i]);
        }

        fclose(f);

        double tempo = medirTempo(peso, valor, n, M);

        printf("Arquivo: %s\n", arquivos[t]);
        printf("Itens: %d | Tempo: %f segundos\n\n", n, tempo);

        free(peso);
        free(valor);
    }

    return 0;
}