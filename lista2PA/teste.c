#include <stdio.h>
/* EX01
int main()
{
    int i, j, sum = 0, mat[3][3];

    for(i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("digite o elemento %d|%d: ",i+1,j+1);
            scanf("%d",& mat[i][j]);
            sum = sum + mat[i][j];
        }
    }
    printf("sum: %d\n",sum);


    return 0;
}
*/

// soma de matrizes
int main()
{   
    float A[2][3], B[2][3], sum[2][3];
    int i, j;
    // leitura da matriz A
    printf("matriz A: \n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("digitite o elemento %d|%d: ",i+1, j+1);
            scanf("%f",& A[i][j]);
        }
    }
    // leitura da matriz B
    printf("matriz B:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("digite o elemento %d|%d: ",i+1, j+1);
            scanf("%f",& B[i][j]);
        }
    }

    // escrever a soma das matrizes
    printf("a matriz resultante da soma das matrizes A e B e: \n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
            printf("|%.2f|", sum[i][j]);
        }
    printf("\n");
    }
}