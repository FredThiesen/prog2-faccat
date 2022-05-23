#include <stdio.h>

int fibonacciNaoRecursivo(int n){
    int fibminus2 = 0;
    int fibminus1 = 1;
    int fib = 0;
    int i;

    if (n == 0 || n == 1)
        return n;

    for (i = 2; i <= n; i++){
        fib = fibminus1 + fibminus2;
        fibminus2 = fibminus1;
        fibminus1 = fib;
    }

    return fib;
}

int main(){
    int number;
    printf("Insira um numero inteiro: ");
    scanf("%d", &number);

    for(int i = 0; i <= number; i++){
        printf("%d \n", fibonacciNaoRecursivo(i));
    }

    return 0;
}
