#include <stdio.h>
#include <stdlib.h>
/* ENUNCIADO
8. Gabriel estava desenvolvendo um minigame, mas encontrou dificuldades no seu algoritmo. A ideia do
minigame  ́e a seguinte: haveria uma matriz 3x3 onde cada elemento seria atribu ́ıdo um valor inteiro.
Se o valor fosse par, ele deveria ser substitu ́ıdo por 1; se fosse  ́ımpar, por -1. Ap ́os essa substitui ̧c ̃ao, o
programa deveria exibir a nova matriz atualizada. Gabriel solicitou sua ajuda para realizar essa tarefa.
*/

int main()
{
    int mat[3][3];
    int i, j;
    // ler a matriz
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("elemento %d/%d: ",i+1, j+1);
            scanf("%d",&mat[i][j]);
        }
    }
    // escrever a matriz
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %d ",mat[i][j]);
        }
        printf("\n");
    }

    // realocar a matriz
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (mat[i][j] % 2 == 0) // se for par
            {
                mat[i][j] = +1; // apenas 1 = pq está igualando eles, se fossem 2 == estaria comparando
            }
            else
            mat[i][j] = -1;
        }
    }

    printf("a matriz reescrita e: \n");
    // escrever a nova matriz
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %d ", mat[i][j]);
        }
        printf("\n");
    }


    return 0;
}