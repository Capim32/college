#include <stdio.h>

int main()
{
    int i, j, mat[4][4];

    // loop para pedir a matriz
    for (i =0; i< 4; i++)
    {
        for(j = 0; j<4; j++)
        {
            printf("digite o elemento %d| %d: ",i+1, j+1);
            scanf("%d",&mat[i][j]);
        }
    }
    printf("a matriz e: \n");
    // loop para escrever a matriz
    for(i = 0; i < 4; i++) // linhas
    {
        for (j = 0; j < 4; j++) // colunas
        {
            printf("|%d|", mat[i][j]);
        }
    printf("\n"); // quebra a linha depois de cada coluna completa
    }
}