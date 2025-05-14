#include <stdio.h>
#include <stdlib.h>

/*
7. Marcos lida bastante com o mercado financeiro e est ́a enfrentando problemas ao realizar diversas vezes,
de forma manual, a convers ̃ao de d ́olares para reais. Sendo assim, ele solicitou a vocˆe um algoritmo
que, dada a cota ̧c ̃ao atual do d ́olar, converta qualquer quantidade de d ́olares para reais.
*/

int main()
{
    float real,dol;
    printf("digite quantos dolares deseja converter para reais: ");
    scanf("%f",&dol);
    real = dol * 5.65;
    printf("essa quantidade de dolares da %.2f reais",real);

return 0;    
}