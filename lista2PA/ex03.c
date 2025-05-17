#include <stdio.h>
#include <stdlib.h>

/* ENUNCIADO
3. Roberto  ́e o dono de uma empresa com 20 filiais e precisa de ajuda para criar um algoritmo. Ele possui
um vetor com 20 valores reais, onde valores positivos representam filiais lucrativas e valores negativos
representam filiais que d ̃ao preju ́ızo. Vocˆe deve desenvolver um algoritmo que fa ̧ca o seguinte:
(a) Imprima o  ́ındice no vetor de todas as empresas que d ̃ao lucro;
(b) Calcule a m ́edia dos lucros, desconsiderando todas as filiais que d ̃ao preju ́ızo.
*/

int main()
{
    float lucro = 0, prejuizo = 0, filiais[20];
    int i, j = 0;

    for (i=0;i<20;i++)
    {
        printf("digite o valor da filial de numero %d: ",i+1);
        scanf("%f",&filiais[i]);
        if (filiais[i]>=0)
        {
            lucro = lucro + filiais[i];
        }
        else
        prejuizo = prejuizo + filiais[i];
    }

    for (i=0;i<20;i++)
    {
        if (filiais[i]>=0)
        {
            printf("a filial %d da LUCRO\n",i+1);
            j++;
        }
    }

    printf("media dos lucros: %.2f \n",lucro/j);

    return 0;
}