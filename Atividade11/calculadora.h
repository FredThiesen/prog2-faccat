#ifndef CALCULADORA_H
#define CALCULADORA_H
// soma
// subtração
// divisão
// multiplicação
// resto de divisão
// potência na base
// raiz quadrada
// raiz cúbica

#include <math.h>

int somar(int a, int b) {
    return a + b;
};
float subtrair(int a, int b) {
    return (float)a - b;
};

float dividir(int a, int b) {
    return (float)a / b;
};
int multiplicar(int a, int b) {
    return a * b;
};

int resto(int a, int b) {
    return a % b;
};

int potenciar(int a) {
    return pow(a, 2);
};

float raizq(int a) {
    return (float)sqrt(a);
};

float raizc(int a) {
    return (float)cbrt(a);
};

#endif  // CALCULADORA_H