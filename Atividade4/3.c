#include <stdio.h>
#include <string.h>


int main(void){
    char frase[100];
    char consoantes[100];
    char vogais[100];
    char opcao;
    int length;

    printf("Insira uma frase: ");
    scanf("%[^\n]s", frase);

    length = strlen(frase);
    for(int i=0, v=0, c=0; i<=length; i++){
        if(frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u'){
            vogais[v] = frase[i];
            v++;
        }
        else{
            if(frase[i] != ' ' && frase[i] != '\0'){
                consoantes[c] = frase[i];
                c++;
            }
        }
    }

    fflush(stdin); // limpa o buffer para não dar problema no próximo scanf 
    printf("c ou v? ");
    scanf("%c", &opcao);

    if(opcao == 'c'){
        printf("%s %s", consoantes, vogais);
    }
    else if (opcao == 'v'){
        printf("%s %s", vogais, consoantes);
    } else{
        printf("Opção inválida");
    }
        
return 0;
}