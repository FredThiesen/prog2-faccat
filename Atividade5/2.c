#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int somar(int a, int b){
    return a+b;
}

int multiplicar(int a, int b){
    return a*b;
}

int dividir(int a, int b){
    if(b == 0){
        printf("Nao e possivel dividir por 0\n");
        return 0;
    }
    return a/b;
}

int subtrair(int a, int b){
    return a-b;
}

int restoDeDivisao(int a, int b){
    if(b == 0){
        printf("Nao e possivel dividir por 0\n");
        return 0;
    }
    return a%b;
}

int potencia(int a, int b){
    return pow(a,b);
}




int main(void){
    int valor1, valor2, operacao;
    char operacaoChar[100];

    do{
        fflush(stdin);
        printf("Insira o primeiro valor: ");
        scanf("%d", &valor1);
        printf("Insira o segundo valor: ");
        scanf("%d", &valor2);
        printf("1 - Soma\n2 - Multiplicacao\n3 - Divisao\n4 - Subtracao\n5 - Resto da divisao\n6 - Potencia\n");
        printf("Insira a operacao: ");
        scanf("%d", &operacao);

        switch(operacao){
            case 1:
                printf("%d\n", somar(valor1, valor2));
                break;
            case 2:
                printf("%d\n", multiplicar(valor1, valor2));
                break;
            case 3:
                printf("%d\n", dividir(valor1, valor2));
                break;
            case 4:
                printf("%d\n", subtrair(valor1, valor2));
                break;
            case 5:
                printf("%d\n", restoDeDivisao(valor1, valor2));
                break;
            case 6:
                printf("%d\n", potencia(valor1, valor2));
                break;
            default:
                printf("Operacao invalida\n");
                break;
        }
        fflush(stdin);
        printf("Escreva 'sair' para sair, ou qualquer letra para repetir:\n");
        scanf("%s", operacaoChar);
        
    }while(strcmp(operacaoChar, "sair") != 0);    
    
return 0;
}