// 4) Utilizando switch/case, escreva um programa que leia 1 letra do teclado e diga se ela é vogal ou consoante.

#include <stdio.h>

int main(void){
    char letra;
    printf("Digite uma letra: ");
    scanf("%c", &letra);
    switch(letra){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("%c é uma vogal\n", letra);
            break;
        default:
            printf("%c é uma consoante\n", letra);
            break;
    }
    return 0;
}