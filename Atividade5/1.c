#include <stdio.h>
#include <string.h>
#include <ctype.h>

int * vogais_consoantes(char *frase){
    static int quantidadeVogaisConsoantes[2] = {0, 0};
    int length = strlen(frase);
    for(int i=0; i<=length; i++){
        if(frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u'){
            quantidadeVogaisConsoantes[0]++;
        }
        else{
            if(frase[i] != ' ' && frase[i] != '\0'){
                quantidadeVogaisConsoantes[1]++;
            }
        }
    }
    return quantidadeVogaisConsoantes;
}

int main(void){
    char frase[100];
    int length;
    int *quantidadeVogaisConsoantes;

    printf("Insira uma frase: ");
    scanf("%[^\n]s", frase);

    quantidadeVogaisConsoantes = vogais_consoantes(frase);
    length = strlen(frase);

    printf("Quantidade de letras: %d \n", quantidadeVogaisConsoantes[0]+quantidadeVogaisConsoantes[1]);
    printf("Quantidade de vogais: %d \n", quantidadeVogaisConsoantes[0]);
    printf("Quantidade de consoantes: %d \n", quantidadeVogaisConsoantes[1]);
    printf("Primeiro e ultimo caracteres concatenados, e em maiusculo: %c%c", toupper(frase[0]), toupper(frase[length-1]));

     
return 0;
}