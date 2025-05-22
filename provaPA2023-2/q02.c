#include <stdio.h>

int main() {
    int matriz[4][7] = {
        {10, 12, 11, 13, 14, 15, 16},
        {9, 10, 11, 12, 13, 14, 15},
        {20, 18, 17, 16, 15, 14, 13},
        {8, 9, 10, 11, 12, 13, 14}
    };
    int consumo[4] = {0};
    int ordem[4] = {0, 1, 2, 3};

    // Imprime a matriz original
    printf("Matriz original:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%2.d ", matriz[i][j]);
            consumo[i] += matriz[i][j];
        }
        printf("\n");
    }

    // Ordenação dos consumos (Bubble Sort)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (consumo[j] > consumo[j+1]) 
            {
                int temp = consumo[j];
                consumo[j] = consumo[j+1];
                int temp_ord = ordem[j];
                ordem[j] = ordem[j+1];
                ordem[j+1] = temp_ord;
            }
        }
    }

    // Imprime consumo ordenado
    printf("\nConsumo por semana em ordem crescente:\n");
    for (int i = 0; i < 4; i++) {
        printf("Semana %d: %d kWh\n", ordem[i]+1, consumo[i]);
    }

    // Determina a semana de maior consumo
    int maior_consumo = consumo[3];
    int semana_maior = ordem[3]+1;

    printf("\nSemana com maior consumo: %dª semana\n", semana_maior);

    return 0;
}
