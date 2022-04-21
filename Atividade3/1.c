#include <stdio.h>

int main(void){
    int numero;
    int matrix[10][10];

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            matrix[i][j] = (i+1) * (j+1);
        }
    }

    do{
        printf("Insira um numero de 1 ate 10: ");
        scanf("%d", &numero);
    } while (numero < 1 || numero > 10 || numero != (int)numero);

    for (int i = 0; i < 10; i++){
        printf("%d x %d = %d\n", numero, i + 1, matrix[numero - 1][i]);
    }

    return 0;
}
