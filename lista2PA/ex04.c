#include <stdio.h>
#include <stdlib.h>

/* ENUNCIADO
4. Um grupo de amigos est ́a debatendo sobre a ordem de altura entre eles. Para resolver essa discuss ̃ao,
eles pediram que vocˆe criasse um algoritmo que fizesse o seguinte:
(a) Leia a altura de 6 amigos;
(b) Imprima a maior e a menor altura, juntamente com a posi ̧c ̃ao (ou  ́ındice) do amigo mais baixo e
do mais alto;
(c) Em seguida, imprima as alturas dos amigos em ordem crescente, do mais baixo para o mais alto.
*/

/* TESTE FALHO
int main()
{
    float alturas[6], ma, mb;
    int i;

    for (i=0;i<6;i++)
    {
        printf("digite a altura do %d amigo: ",i+1);
        scanf("%f",&alturas[i]);
    }
    // define o mais alto e o mais baixo como sendo o primeiro para iniciar
    ma = alturas[0];
    mb = alturas[0];

    for (i=0;i<6;i++)
    {
        if (ma < alturas[i])
        {
            ma = alturas[i];
        }
    }
    for (i=0;i<6;i++)
    {
        if (mb > alturas[i])
        {
            mb = alturas[i];
        }
    }
    printf("mais alto: %.2f mais baixo: %.2f\n",ma,mb);
    

    return 0;
}
*/
/* TESTE FALHO 2 (BUBBLE SORT MAL EMPREGADO)
int main()
{
    float alturas[6];
    int indice_maior = 0, indice_menor=0;
    int i, aux, contador;

    for (i=0;i<6;i++)
    {
        printf("digite a altura do %d amigo: ",i+1);
        scanf("%f",&alturas[i]);

        if (alturas[i] > alturas[indice_maior])
        {
            indice_maior = i;
        }
        if (alturas[i] < alturas[indice_menor])
        {
            indice_menor = i;
        }
    }
    printf("maior altura: %.2f na posicao %d\n", alturas[indice_maior],indice_maior+1);
    printf("menor altura: %.2f na posicao %d\n",alturas[indice_menor],indice_menor+1);

    // bubble sort
    for (contador = 0; contador < 6 - 1; contador ++)
    {
        for (i = 0; i < 6 - 1; i++)
        {
            // ordenação
            if (alturas[i] > alturas[i+1])
            {
                aux = alturas[i];
                alturas[i] = alturas[i+1];
                alturas[i+1] = aux;
            }
        }
    }
    printf("alturas em forma crescente: ");
    for (i = 0; i < 6; i++)
    {
        printf("|%.2f|",alturas[i]);
    }
    printf("\n");
    
return 0;
}
*/

//codigo do gpt
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
        printf("|%.2f| ", alturas[i]);
    }
    printf("\n");

    return 0;
}
