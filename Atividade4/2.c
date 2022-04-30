#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void){
    char nome[100];
    int quantidadePalavras = 1;
    int length;

    printf("Insira seu nome: ");
    scanf("%[^\n]s", nome);

    length = strlen(nome);
    for(int i=0; i<=length; i++){
        if(nome[i] == ' '){
            quantidadePalavras++;
        }
    }

    printf("o nome tem %d palavras\n", quantidadePalavras);

return 0;
}