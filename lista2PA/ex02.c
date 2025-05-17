#include <stdio.h>
#include <stdlib.h>
/* ENUNCIADO
2. Jos ́e precisa de ajuda em outra funcionalidade: o c ́alculo da ”m ́edia perfeita”da turma. A m ́edia
perfeita  ́e a m ́edia aritm ́etica simples das notas da turma, mas caso o resultado final seja maior que 8,
ela ser ́a igual a 10. Para isso, considere as notas dos 15 alunos da turma como um vetor de 15 valores
reais e desenvolva um algoritmo que resolva esse problema.
*/

int main()
{
    float med, sum, notas[15];
    int i, j=0; // uma variavel nao iniciada não tem seu valor setado como 0, por isso j deve ser declarado 0

    for (i=0;i<15;i++)
    {
        printf("digite a nota do %d aluno: ",i+1);
        scanf("%f",&notas[i]);

        sum = sum + notas[i];
        j++; // caso j não fosse declarado 0, o valor aqui não seria o numero de alunos, mas sim um numero qualquer + num de alunos
    }
    printf("a soma total das notas foi: %.2f\n",sum);
    med = sum/j;
    if (med>=8)
    {
        printf("a média perfeita da turma é 10!");
    }

    else
    printf("a media perfeita da turma e : %.2f\n",med);

    return 0;
}