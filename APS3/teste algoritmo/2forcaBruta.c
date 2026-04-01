// para cada item tem duas escolhas
//    - colocar o item na mochila
//    - nao colocar o item

//  O(2^n)

#include <stdio.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

// função para indentação (árvore)
void nivel(int n){
    for(int i = 0; i < n; i++){
        printf("   ");
    }
}

// força bruta com árvore visual
int knapsack(int n, int M, int peso[], int valor[], int prof) {

    nivel(prof);
    printf("n=%d | M=%d\n", n, M);

    // caso base
    if (n == 0 || M == 0) {
        nivel(prof);
        printf("-> retorna 0\n");
        return 0;
    }

    // não cabe
    if(peso[n-1] > M){
        nivel(prof);
        printf("Item %d NAO cabe (peso=%d)\n", n-1, peso[n-1]);
        return knapsack(n-1, M, peso, valor, prof+1);
    }

    // tenta pegar
    nivel(prof);
    printf("-> PEGAR item %d\n", n-1);
    int pegar = knapsack(n-1, M - peso[n-1], peso, valor, prof+1) + valor[n-1];

    // tenta não pegar
    nivel(prof);
    printf("-> NAO PEGAR item %d\n", n-1);
    int naoPegar = knapsack(n-1, M, peso, valor, prof+1);

    // decisão
    nivel(prof);
    if(pegar > naoPegar){
        printf("Escolheu PEGAR item %d (valor=%d)\n", n-1, pegar);
        return pegar;
    } else {
        printf("Escolheu NAO PEGAR item %d (valor=%d)\n", n-1, naoPegar);
        return naoPegar;
    }
}

int main() {

    int peso[] = {1, 1, 1};
    int valor[] = {10, 20, 30};

    int n = 3;
    int M = 50;

    printf("=== FORCA BRUTA (PASSO A PASSO) ===\n\n");

    int resultado = knapsack(n, M, peso, valor, 0);

    printf("\n=== RESULTADO FINAL ===\n");
    printf("Valor maximo: %d\n", resultado);

    return 0;
}