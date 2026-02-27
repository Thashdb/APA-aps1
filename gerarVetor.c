#include <stdio.h>
#include <stdlib.h>

// Para análise precisa-se de 4 tipos diferentes de entrada
// - aleatorio, Arrays com poucos valores únicos, já ordenado e ordenado ao contrário

void gerarAleatorio(int A[], int n) {
    for (int i = 0; i < n; i++)
        A[i] = rand();  
        // gera números pseudo aleatórios
}

void gerarPoucosValores(int A[], int n) {
    for (int i = 0; i < n; i++)
        A[i] = rand() % 10;  
        // limita a esolha dos valores até a cte x; x=10
            // gera alta repeticao de valores baixos
}

void gerarOrdenado(int A[], int n) {
    for (int i = 0; i < n; i++)
        A[i] = i+1;          
        // ordenado igual a  i+1 (de 1 a n)
}

void gerarInverso(int A[], int n) {
    for (int i = 0; i < n; i++)
        A[i] = n - i;          
        // ordenado ao contrário (de n a 1)
}

void salvarVetor(FILE *arquivo, int A[], int n) {
    for (int i = 0; i < n; i++)
        fprintf(arquivo, "%d ", A[i]);
    fprintf(arquivo, "\n");
}

int main() {

    int n = 100000;   // tamanho do vetor

    FILE *arquivo = fopen("entrada100k.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar arquivo.\n");
        return 1;
    }

    fprintf(arquivo, "%d\n", n);   // primeira linha salva o tamanho

    int *A = malloc(n * sizeof(int));

    // Aleatório
    gerarAleatorio(A, n);
    salvarVetor(arquivo, A, n);

    // Muitos repetidos
    gerarPoucosValores(A, n);
    salvarVetor(arquivo, A, n);

    // Ordenado
    gerarOrdenado(A, n);
    salvarVetor(arquivo, A, n);

    // Inverso
    gerarInverso(A, n);
    salvarVetor(arquivo, A, n);


    free(A);
    fclose(arquivo);

    printf("Arquivo entrada.txt gerado com sucesso!\n");

    return 0;
}