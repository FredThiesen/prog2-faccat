#include <stdio.h>

int main (void) {
    int i = 0;
    int numero;
    printf("insira um numero inteiro positivo: ");
    scanf("%d", &numero);

    while (i < numero){
        if(i % 2 == 1) {
            printf("%d\n", i);
        };
        i++;
    }
    return 0;
}