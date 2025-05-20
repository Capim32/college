#include <stdio.h>
#include <stdlib.h>
/* ENUNCIADO
12. Clara mais uma vez pediu ajuda com uma tarefa de casa. Ela precisa de um programa que realize a
seguinte tarefa:
(a) Dadas duas matrizes A e B, ambas 2x3, o programa deve calcular a soma das duas matrizes e
criar uma matriz C com os resultados;
(b) Em seguida, o programa deve imprimir as matrizes A, B e C.*/

int main()
{
    float A[2][3], B[2][3], C[2][3];
    int i, j;

    printf("matriz A: \n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("elemento %d/%d: ",i+1, j+1);
            scanf("%f",& A[i][j]);
        }
    }

    printf("matriz B: \n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("elemento %d/%d: ", i+1, j+1);
            scanf("%f", & B[i][j]);
        }
    }

    // define a mat C
    for (i = 0; i < 2; i++)
    {
        for(j = 0; j < 3; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // imprime as matrizes
    printf("matriz A: \n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %.2f ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("matriz B: \n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %.2f ", B[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("matriz C: \n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %.2f ", C[i][j]);
        }
        printf("\n");
    }
    printf("\n");



    return 0;
}