//  usa uma tabela itens X peso disponivel

// O(nM)

// para cada item tem duas escolhas
//    - colocar o item na mochila
//    - nao colocar o item

//  O(2^n)

#include <stdio.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int knapsack(int n, int M, int peso[], int valor[]){

    int k[n+1][M+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=M; j++){

            if(i==0 || j==0){
                k[i][j] = 0;
                printf("k[%d][%d] = 0\n", i, j);
            }else if(peso[i-1] <= j){
                int pegar = valor[i-1] + k[i-1][j-peso[i-1]];
                int naoPegar = k[i-1][j];

                k[i][j] = max(pegar, naoPegar);

                printf("k[%d][%d] = max(%d, %d) = %d\n",
                        i, j, pegar, naoPegar, k[i][j]);
            }else{
                k[i][j] = k[i-1][j];

                printf("k[%d][%d] = copia de cima = %d\n",
                        i, j, k[i][j]);
            }
        }
    }

    printf("\n=== TABELA FINAL ===\n");
    for(int i = 0; i <= n; i++){
        for(int m = 0; m <= M; m++){
            printf("%3d ", k[i][m]);
        }
        printf("\n");
    }

    return k[n][M];
}

int main(){

    int p[] = {1, 1, 1};
    int v[] = {10, 20, 30};

    int n = 3;
    int M = 2;

    printf("=== BOTTOM-UP ===\n\n");

    int resultado = knapsack(n, M, p, v);

    printf("\n=== RESULTADO FINAL ===\n");
    printf("Valor maximo: %d\n", resultado);

    return 0;
}