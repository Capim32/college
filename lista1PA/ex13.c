#include <stdio.h>
#include <stdlib.h>

/* ENUNCIADO
13. Jo ̃ao est ́a conduzindo uma pesquisa e precisa de um programa que controle quem pode sair. Ele tem
7 entrevistados com nomes de at ́e 10 letras. O crit ́erio  ́e que o primeiro a entrar deve ser o  ́ultimo a
sair. Portanto, desenvolva um programa que leia os nomes dos 7 entrevistados e imprima a ordem
*/
#define num_entrevistados 7
#define num_letras 11

int main()
{
    char nomes [7][11];
    int i;

    printf("digite o nome dos 7 entrevistados: \n");
    for (i = 0; i < num_entrevistados; i++)
    {
        printf("entrevistado %d: ", i+1);
        scanf("%10s", & nomes[i]); // %10s limita a 10 letras
    }

    printf("a ordem de saida sera: \n");
    for (i = num_entrevistados - 1; i >=0; i--)
    {
        printf("%10s\n", nomes[i]);
    }
    


    return 0;
}