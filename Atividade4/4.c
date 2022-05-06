#include <stdio.h>
#include <string.h>


int main(void){
    char frase[100];
    char fraseSemEspacos[100];
    int length, lengthSemEspaco;

    printf("Insira uma frase: ");
    scanf("%[^\n]s", frase);

    length = strlen(frase);

    for(int i=0, j=0; i<=length; i++){
        if(frase[i] != ' '){
            fraseSemEspacos[j] = frase[i];
            j++;
        }
    }

    lengthSemEspaco = strlen(fraseSemEspacos);

    //check if the string is a palindrome
    for(int i=0; i<lengthSemEspaco/2; i++){
        if(fraseSemEspacos[i] != ' '){
            if(fraseSemEspacos[i] != fraseSemEspacos[lengthSemEspaco-i-1]){
            printf("Nao e palindromo");
            return 0;
            }
        }
    }
    printf("%s\n", frase);
    printf("E palindromo!!");
    
        
return 0;
}