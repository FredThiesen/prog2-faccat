Com o propósito de exercitar a programação por meio de recursão, adapte o algoritmo de fibonacci apresentado em aula para que seja possível contabilizar, para um determinado número, quantas vezes a função fibonacci recursiva é chamada. Escrever essa quantidade em tela.

```c
int fibonacci(int n) {
   if (n <= 0) {
      return 0;
   } else if (n == 1) {
      return 1;
   } else {
      return fibonacci(n-1) + fibonacci(n-2);
   }
}

void main() {
   int n, valor = 10;
	 for (n = 0; n < valor; n++) {
      printf("%d ", fibonacci(n));
   }
}

```
