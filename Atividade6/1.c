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
   int n, valor = 2;
	 for (n = 0; n < valor; n++) {
      printf("%d ", fibonacci(n));
   }
   printf("\nexecutado %d vezes\n", cont);
}
