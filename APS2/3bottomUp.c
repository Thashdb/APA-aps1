#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

// ================= BOTTOM-UP =================
int knapsack(int n, int M, int p[], int v[]) {

    int **k = malloc((n+1) * sizeof(int*));

    for(int i = 0; i <= n; i++){
        k[i] = malloc((M+1) * sizeof(int));
    }

    for(int i = 0; i <= n; i++){
        for(int m = 0; m <= M; m++){

            if(i == 0 || m == 0){
                k[i][m] = 0;
            }
            else if(p[i-1] <= m){
                k[i][m] = max(
                    v[i-1] + k[i-1][m - p[i-1]],
                    k[i-1][m]
                );
            }
            else{
                k[i][m] = k[i-1][m];
            }
        }
    }

    int resultado = k[n][M];

    // liberar memória
    for(int i = 0; i <= n; i++){
        free(k[i]);
    }
    free(k);

    return resultado;
}

// ================= TEMPO =================
double medirTempo(int p[], int v[], int n, int M){

    clock_t inicio = clock();

    knapsack(n, M, p, v);

    clock_t fim = clock();

    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

// ================= MAIN =================
int main(){

    char *arquivos[] = {
        "arquivos/teste_20_10.txt",
        "arquivos/teste_50_30.txt",
        "arquivos/teste_100_30.txt",
        "arquivos/teste_200_50.txt",
        "arquivos/teste_500_10.txt",
        "arquivos/teste_500_100.txt",
        "arquivos/teste_1000_50.txt",
        "arquivos/teste_10000_100.txt",
        "arquivos/teste_500000_100.txt"
    };

    int qtd = sizeof(arquivos) / sizeof(arquivos[0]);

    printf("=== BOTTOM-UP ===\n\n");

    for(int t = 0; t < qtd; t++){

        FILE *f = fopen(arquivos[t], "r");

        if(f == NULL){
            printf("Erro ao abrir %s\n", arquivos[t]);
            continue;
        }

        int n, M;
        fscanf(f, "%d %d", &n, &M);

        int *peso = malloc(n * sizeof(int));
        int *valor = malloc(n * sizeof(int));

        for(int i = 0; i < n; i++){
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