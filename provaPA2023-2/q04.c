#include <stdio.h>

int main() {
    float precos[] = {5.50, 6.25, 3.30, 4.00, 5.00};
    int vetor[5];
    float total = 0;

    printf("Digite o vetor de compra (5 valores, separados por espaço):\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &vetor[i]);
        total += vetor[i] * precos[i];
    }

    printf("Preço total da compra: R$ %.2f\n", total);

    return 0;
}
