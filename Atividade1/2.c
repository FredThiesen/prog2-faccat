// 2) Escreva um programa na linguagem C, que lê do teclado o ano de seu nascimento e imprime em tela a sua idade.

#include <stdio.h>

int main(void){
    int anoNascimento, anoAtual = 2022;
    printf("escreva seu ano de nascimento: ");
    scanf("%d", &anoNascimento);
    printf("voce tem %d anos\n", anoAtual - anoNascimento);
}