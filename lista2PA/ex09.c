#include <stdio.h>
#include <stdlib.h>

/* ENUNCIADO
9. O IBGE (Instituto Brasileiro de Geografia e Estat ́ıstica) precisa de um novo algoritmo. Eles tˆem dados
sobre a idade das 3 cidades mais velhas de 3 estados diferentes, organizados em uma matriz 3x3. Agora,
eles solicitam que vocˆe desenvolva um algoritmo que realize as seguintes tarefas:
(a) Leia a matriz de idade das cidades;
(b) Solicite ao usu ́ario que informe o  ́ındice de uma linha da matriz;
(c) Calcule a m ́edia de idade das 3 cidades daquele estado correspondente `a linha escolhida.
*/

int main()
{
    int mat[3][3];
    int i, j, choice = 0;
    float sum_linhas[3];// um vetor para armazenar a soma dos elementos de cada linha

    // pedir os elementos da matriz
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("digite a idade da %d cidade do %d municipio: ", j+1, i+1);
            scanf("%d", & mat[i][j]);
        }
    }
    // decidir a linha especifica para pegar a soma
    printf("qual municipio deseja saber a media da idade das cidades? (1, 2 ou 3): ");
    scanf("%d", & choice);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            sum_linhas[i] += mat[i][j]; // faz a somatoria dos elementos de cada linha
        }
    }

    printf("a media da idade das cidades do %d municipio e: %.2f\n",choice, sum_linhas[choice - 1]/3); // -1 pq a matriz vai de 0 a 2 
    
    return 0;
}