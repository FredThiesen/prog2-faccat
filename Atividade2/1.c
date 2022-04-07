#include <stdio.h>

int main (void){
    int numero;
    printf("insira um numero de 1 ate 10: ");
    scanf("%d", &numero);

    for (int i = 1; i <= 10; i++){
        printf("%d x %d = %d\n", numero, i, numero * i);
    }

    return 0;
}