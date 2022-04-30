#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void){
    char nome[100];
    char ultimoNome[100];
    char primeiroNome[100];
    int length;

    printf("Insira seu nome: ");
    scanf("%[^\n]s", nome);

    length = strlen(nome);
    for(int i=0; i<=length; i++){
        if(nome[i] == ' '){
            for(int j=i+1; j<=length; j++){
                ultimoNome[j-i-1] = toupper(nome[j]);
            }
        }
    }

    for (int i = 0; i < strlen(nome); i++){
        if (nome[i] == ' '){
            primeiroNome[i] = '\0';
            break;
        }
        primeiroNome[i] = nome[i];
    }

    printf("%s, %s\n", ultimoNome, primeiroNome);

        
return 0;
}