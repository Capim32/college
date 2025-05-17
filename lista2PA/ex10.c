#include <stdio.h>
#include <stdlib.h>

/* ENUNCIADO
10. Clara  ́e uma estudante que possui uma tarefa tediosa de criar uma matriz 3x3, onde o valor de cada
elemento na linha ”i”e na coluna ”j” ́e igual `a soma de ”i”e ”j”. Ela est ́a sem tempo e pediu que vocˆe
desenvolva um algoritmo que crie e imprima essa matriz automaticamente.
*/

int main()
{
    int mat[3][3];
    int i, j;

    for(i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j ++)
        {
            mat[i][j] = (i+1) + (j+1); // adicionar +1 a i e a j para que a soma dos elementos funcione corretamente
        }
    }

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