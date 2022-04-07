// 3) Escreva um programa na linguagem C, que lê do teclado o seu nome completo e o ano de seu nascimento. Após a leitura dos dados ele deve imprimir o seu nome concatenado com a sua idade.

#include <stdio.h>

int main(void){
    char nome[50];
    int ano, anoAtual = 2022;
    printf("Digite seu nome: ");
    scanf("%[^\n]",nome);
    printf("Digite seu ano de nascimento: ");
    scanf("%d", &ano);
    printf("%s tem %d anos\n", nome, anoAtual - ano);
    return 0;
}


 