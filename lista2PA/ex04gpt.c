#include <stdio.h>

int main() {
    float alturas[6];
    int i, indice_maior = 0, indice_menor = 0;

    // (a) Leitura das alturas
    for (i = 0; i < 6; i++) {
        printf("Digite a altura do amigo %d: ", i + 1);
        scanf("%f", &alturas[i]);

        // Verifica se é a maior ou menor altura até agora
        if (alturas[i] > alturas[indice_maior]) {
            indice_maior = i;
        }
        if (alturas[i] < alturas[indice_menor]) {
            indice_menor = i;
        }
    }

    // (b) Exibir a maior e menor altura com as posições
    printf("\nMaior altura: %.2f (posicao %d)\n", alturas[indice_maior], indice_maior);
    printf("Menor altura: %.2f (posicao %d)\n", alturas[indice_menor], indice_menor);

    // (c) Ordenar as alturas em ordem crescente (usando bubble sort)
    for (i = 0; i < 6 - 1; i++) {
        for (int j = 0; j < 6 - 1 - i; j++) {
            if (alturas[j] > alturas[j + 1]) {
                float temp = alturas[j];
                alturas[j] = alturas[j + 1];
                alturas[j + 1] = temp;
            }
        }
    }

    // Exibir alturas em ordem crescente
    printf("\nAlturas em ordem crescente:\n");
    for (i = 0; i < 6; i++) {
        printf("%.2f ", alturas[i]);
    }
    printf("\n");

    return 0;
}
