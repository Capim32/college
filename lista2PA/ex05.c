#include <stdio.h>
#include <stdlib.h>

/* ENUNCIADO
5. Roberto precisa adicionar mais uma funcionalidade ao seu programa. Ele possui outra empresa com 10
filiais e necessita de um algoritmo que, tendo um vetor com os valores reais representando lucro (valores
positivos) ou preju ́ızo (valores negativos) das 10 filiais, informe quantas delas est ̃ao dando preju ́ızo.
*/

int main()
{
    float vet[10];
    int i, contador = 0;

    for (i = 0; i< 10; i++)
    {
        printf("digite o valor da %d filial: ",i+1);
        scanf("%f",&vet[i]);
    }

    printf("as filiais que estão dando prejuizo sao: \n");
    for (i = 0; i < 10; i++)
    {
        if (vet[i] < 0)
        {
            printf("filial %d com %.2f de prejuizo\n", i + 1, vet[i]);
            contador ++;
        }
    }

    printf("no total, %d filiais estão dando prejuizo\n", contador);



return 0;
}