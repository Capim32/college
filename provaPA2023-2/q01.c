#include <stdio.h>

int main() {
    float precos[] = {150500.50, 70300.75, 77020.00, 220299.99, 79999.99};
    int n = 5;
    float temp;

    // Ordenação (Bubble Sort)
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (precos[j] > precos[j+1]) {
                temp = precos[j];
                precos[j] = precos[j+1];
                precos[j+1] = temp;
            }
        }
    }

    printf("Valor do carro mais barato: R$ %.2f\n", precos[0]);

    return 0;
}
