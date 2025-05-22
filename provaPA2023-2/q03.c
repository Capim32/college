#include <stdio.h>

int ehPrimo(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Digite um número n: ");
    scanf("%d", &n);

    printf("Números primos de 0 até %d:\n", n);
    for (int i = 0; i <= n; i++) {
        if (ehPrimo(i))
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}
