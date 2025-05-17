#include <stdio.h>
#include <stdlib.h>

/* ENUNCIADO
1. Jos ́e est ́a enfrentando dificuldades em uma outra funcionalidade de seu sistema escolar. Ele precisa
calcular a ”m ́edia funcional”da turma, composta por 10 alunos. A m ́edia funcional  ́e a m ́edia das notas
de todos os alunos que n ̃ao foram reprovados, ou seja, os alunos que obtiveram nota maior que 4. Para
isso, considere as notas dos 10 alunos da turma como um vetor de 10 valores reais e desenvolva um
algoritmo que resolva esse problema.
*/

int main()
{
    float sum, notas[10];
    int i,j;

    for (i=0; i<=2; i++)
    {
        printf("digite a nota do %d aluno: ",i+1);
        scanf("%f",&notas[i]);

        if (notas[i]>=4)
        {
            sum = sum + notas[i];
            j++; // j funciona como um contador para os alunos que tiveram nota > 4
        }

    }
    printf("a media funcional dos alunos e: %.2f\n",sum/j); // sum / j pega a soma das notas > 4  e divide pelo numero de alunos que teve nota > 4



    return 0;
}