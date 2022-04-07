#include <stdio.h>

int main (void) {
    int numero;
    printf("insira um numero inteiro positivo: ");
    scanf("%d", &numero);

    for (int i = 0; i < numero; i++){
        if(i % 2 == 1) {
            printf("%d\n", i);
        };
    }
    return 0;
}