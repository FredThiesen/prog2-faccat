#include <stdio.h>

int cont = 0;

int buscaBinaria(int *vetor, int inicio, int fim, int valor){
    cont++;
    int meio = (inicio + fim) / 2;
    printf("%d meio\n ", meio);
    printf("%d inicio\n",inicio);
    printf("%d fim\n",fim);

    if (inicio > fim){
        return -1;
    }
    else if (vetor[meio] == valor){
        return meio;
    }
    else if (vetor[meio] > valor){
        return buscaBinaria(vetor, inicio, meio - 1, valor);
    }

    return buscaBinaria(vetor, meio + 1, fim, valor);
}

int main(){
    int vetor[] = {1, 2, 4, 6, 9, 11, 23, 42, 100, 232, 254, 987, 1234, 5678, 9999};
    int valor;

    printf("Insira um valor inteiro: ");
    scanf("%d", &valor);

    int fim = sizeof(vetor) / sizeof(int) - 1;

    int posicao = buscaBinaria(vetor, 0,fim, valor);

    if (posicao == -1){
        printf("Valor nao encontrado no vetor");
    }
    else{
        printf("Valor encontrado na posicao %d (indice %d do vetor)", posicao + 1, posicao);
    }
    printf("\nA funcao de busca binaria foi chamada %d vezes", cont);

    return 0;
}
