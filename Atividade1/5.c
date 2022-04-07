#include <stdio.h>
#include <math.h>

//Escreva um programa que imprime em tela os números (de 1 à 1000) cuja raiz quadrada são números ímpares.

//checa se a raiz quadrada do número é inteiro (para ser ímpar, precisa ser inteiro)
int isRootInteger(int numero){
    if(numero == sqrt(numero) * (int)sqrt(numero)){
        return 1;
    }
    return 0;
}

//checa se o número é ímpar
int isOdd(int numero){
    if(numero % 2 == 1){
        return 1;
    }
    return 0;
}

int main(void){
    int numero;
    for(numero = 1; numero <= 1000; numero++){
        if(isRootInteger(numero) && isOdd(numero)){
            printf("%d\n", numero);
        }
    }
    return 0;
}
