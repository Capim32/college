#include <stdio.h>
#include <stdlib.h>

/* ENUNCIADO
11. Clara est ́a com outra tarefa, que  ́e digitar os n ́umeros de 1 a 25 em uma matriz 5x5 da seguinte forma:

1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25

Ela pediu um algoritmo que fa ̧ca o seguinte:
(a) Gere e imprima essa matriz automaticamente;
(b) Imprima a soma dos elementos de cada uma das 5 linhas;
(c) Imprima um vetor com os elementos da diagonal principal (onde i  ́e igual a j).
*/

int main()
{
    int mat[5][5], sum_linha[5];
    int i, j, cont = 1;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            mat[i][j] = cont;
            cont ++;
        }
    }

    printf("a matriz gerada e: \n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf(" %2.d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // inicia o vetor de soma de linhas como zero
    for (i = 0; i < 5; i++)
    {
        sum_linha[i] = 0;
    }

    // faz a soma dos indices de cada linha
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            sum_linha[i] += mat[i][j];
        }
    }

    // imprime a soma dos indices de cada liha
    for (i = 0; i < 5; i++)
    {
        printf("soma da %d linha: %d\n",i+1, sum_linha[i]);
    }

    printf("\n");
    printf("os elementos da diagonal principal sao: \n");

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (i == j)
            {
                printf(" %d ",mat[i][j]);
            }
            else
            printf(" ");
        }
        printf("\n");
    }   




    return 0;
}