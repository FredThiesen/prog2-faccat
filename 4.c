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