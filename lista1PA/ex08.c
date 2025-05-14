#include <stdio.h>
#include <stdlib.h>
#include <math.h> // raiz quadrada

/*
8. Mariazinha novamente recebeu uma lista muito extensa e est ́a sem tempo para resolvˆe-la. Desta vez,
trata-se de uma lista de equa ̧c ̃oes do segundo grau, e novamente ela precisa da sua ajuda para conclu ́ı-la
a tempo. Ela precisa de um algoritmo que, lendo os 3 coeficientes a, b e c, determine, com base no
delta, o seguinte:
• Caso o delta seja maior que 0: Informe que existem duas ra ́ızes reais e diferentes e apresente as
duas ra ́ızes reais da equa ̧c ̃ao;
• Caso o delta seja igual a 0: Informe que existe uma raiz real repetida e apresente qual  ́e essa raiz;
• Caso o delta seja menor que 0: Informe que n ̃ao existem ra ́ızes reais para aquela equa ̧c ̃ao.
*/

int main()
{
    float delta,a,b,c,x1,x2;
    printf("digite a:");
    scanf("%f",&a);
    printf("digite b: ");
    scanf("%f", &b);
    printf("digite c: ");
    scanf("%f",&c);

    delta = pow(b,2) - 4*a*c;

    x1 = (-b + sqrt(delta))/2*a;
    x2 = (-b -sqrt(delta))/2*a;

    if(delta == 0)
    {
        printf("existe apenas uma raiz real para a equacao, que e: %.2f",x1);
    }

    else if(delta >0)
    {
        printf("existem duas raizes reais para essa equacao, sao elas x': %.2f e x'': %.2f",x1,x2);
    }

    else
    {
        printf("nao existem raizes reais para esta equacao");
    }







return 0;    
}