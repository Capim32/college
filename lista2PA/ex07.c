#include <stdio.h>
#include <stdlib.h>

/* ENUNCIADO
7. Por fim, Roberto deseja que o programa, ao ler o faturamento de 8 filiais, realize as seguintes tarefas:
(a) Armazene os faturamentos em um  ́unico vetor;
(b) Calcule a soma de todos os elementos desse vetor;
(c) Conte quantos deles representam lucro (valores positivos).
*/

int main()
{
    float faturamento = 0, filiais[8];
    int i, lucrativos = 0;

    for (i = 0; i < 8; i++)
    {
        printf("digite o faturamento da %d filial: ", i + 1);
        scanf("%f",&filiais[i]);
        faturamento = faturamento + filiais[i];
        if (filiais[i] > 0)
        {
            lucrativos ++;
        }
    }
    printf("o faturamento total foi de : %.2f\n", faturamento);
    printf("no total, %d filiais sao lucrativas\n", lucrativos);






    return 0;
}