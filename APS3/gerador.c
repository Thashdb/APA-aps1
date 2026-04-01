#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int n;
    int Q;
    int peso_min;
    int peso_max;
    int valor_min;
    int valor_max;
} Teste;

int main() {
    

    srand(time(NULL));

    Teste testes[] = {
        {20, 10, 1, 10, 1, 1000},
        {50, 30, 1, 30, 1, 1000},
        {100, 30, 1, 30, 1, 1000},
        {200, 50, 1, 50, 1, 1000},
        {500, 10, 1, 10, 1, 1000},
        {500, 100, 1, 100, 1, 1000},
        {1000, 50, 1, 50, 1, 1000},
        {10000, 100, 1, 100, 1, 1000},
        {500000, 100, 1, 100, 1, 1000}
    };

    int qtd = sizeof(testes) / sizeof(testes[0]);

    for(int t = 0; t < qtd; t++) {

        int n = testes[t].n;
        int Q = testes[t].Q;

        char nome[50];
        sprintf(nome, "../arquivos/teste_%d_%d.txt", n, Q);

        FILE *f = fopen(nome, "w");

        if(f == NULL){
            printf("Erro ao criar arquivo\n");
            return 1;
        }


        // escreve n e capacidade
        fprintf(f, "%d %d\n", n, Q);

        // gera os itens
        for(int i = 0; i < n; i++) {

            int peso = rand() % (testes[t].peso_max - testes[t].peso_min + 1)
                        + testes[t].peso_min;

            int valor = rand() % (testes[t].valor_max - testes[t].valor_min + 1)
                        + testes[t].valor_min;

            fprintf(f, "%d %d\n", peso, valor);
        }

        fclose(f);

        printf("Arquivo %s gerado!\n", nome);
    }

    return 0;
}