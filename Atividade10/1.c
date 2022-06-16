#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++) {
        printf("valor do elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    for (int i = 0; i < tamanho; i++) {
        printf("elemento %d = %d | endereco = %d\n", i + 1, vetor[i], &vetor[i]);
    }
    free(vetor);

    return 0;
}