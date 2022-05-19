#include <stdio.h>

int cont;

int fibonacci(int n) {
    cont++;
   if (n <= 0) {
      return 0;
   } else if (n == 1) {
      return 1;
   } else {
      return fibonacci(n-1) + fibonacci(n-2);
   }
}

void main() {
   int n, valor = 8;
fibonacci(valor);
   
   printf("\nPara o Fibonacci de 8, a funcao foi executada %d vezes.\n", cont);
}
