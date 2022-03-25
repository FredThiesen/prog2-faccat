#include <stdio.h>

//Escreva um programa que imprime em tela os números (de 1 à 1000) cuja raiz quadrada são números ímpares.

int main(void){
    int numero, quadrado, resto;
    for(numero = 1; numero <= 1000; numero++){
        quadrado = numero * numero;
        resto = quadrado % 2;
        //se resto for diferente de 0 => ele é ímpar, então imprime o número
        if(resto != 0){
            printf("%d\n", numero);
        }
    }
    return 0;
}