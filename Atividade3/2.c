#include <stdio.h>

int main(void){

    int matrix1[3][3];
    int matrix2[3][3];
    int matrixMulti[3][3];

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("insira o valor da posicao %d, %d da matriz 1: ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("insira o valor da posicao %d, %d da matriz 2: ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            matrixMulti[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }

    printf("Matriz resultante (matriz 1 * matriz 2): \n");

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(j == 0){
                printf(" | ");
            }
            printf("%d ", matrixMulti[i][j]);
            if(j==2){
                printf("| \n");
            }
        }
    }

        return 0;
}
