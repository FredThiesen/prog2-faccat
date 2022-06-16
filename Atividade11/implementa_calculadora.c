// programa em c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculadora.h"

//  primeiro (indice 1) argumento = operacao:
//  "somar" = somar dois numeros
//  "subtrair" = subtrair dois numeros
//  "dividir" = dividir dois numeros
//  "multiplicar" = multiplicar dois numeros
//  "resto" = resto da divisao de dois numeros
//  "potenciar" = potenciar um numero na base 2
//  "raizq" = raiz quadrada de um numero
//  "raizc" = raiz cubica de um numero

int comparaString(char *string1, char *string2) {
    if (strcmp(string1, string2) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void printaOperacoes() {
    printf("Operacoes disponiveis:\n");
    printf("somar\n");
    printf("subtrair\n");
    printf("dividir\n");
    printf("multiplicar\n");
    printf("resto\n");
    printf("potenciar\n");
    printf("raizq\n");
    printf("raizc\n\n");
    printf("exemplo: somar 2 2\n\n");
}

int main(int argc, char **argv) {
    if (argc <= 1) {
        printf("Insira os argumentos para executar.\n");
        printaOperacoes();
        return 0;
    }

    if (comparaString(argv[1], "somar")) {
        printf("Somando: %d!\n", somar(atoi(argv[2]), atoi(argv[3])));

    } else if (comparaString(argv[1], "subtrair")) {
        printf("Subtraindo... Resultado: %.2f!\n", subtrair(atoi(argv[2]), atoi(argv[3])));
    } else if (comparaString(argv[1], "dividir")) {
        printf("Dividindo... Resultado: %.2f!\n", dividir(atoi(argv[2]), atoi(argv[3])));
    } else if (comparaString(argv[1], "multiplicar")) {
        printf("Multiplicando... Resultado: %d!\n", multiplicar(atoi(argv[2]), atoi(argv[3])));
    } else if (comparaString(argv[1], "resto")) {
        printf("Resto da divisao... Resultado: %d!\n", resto(atoi(argv[2]), atoi(argv[3])));
    } else if (comparaString(argv[1], "potenciar")) {
        printf("Potenciando... Resultado: %d!\n", potenciar(atoi(argv[2])));
    } else if (comparaString(argv[1], "raizq")) {
        printf("Raiz quadrada... Resultado: %.2f!\n", raizq(atoi(argv[2])));
    } else if (comparaString(argv[1], "raizc")) {
        printf("Raiz cubica... Resultado: %.2f!\n", raizc(atoi(argv[2])));
    } else {
        printf("Operacao invalida!\n");
        printaOperacoes();
    }
    return 0;
}