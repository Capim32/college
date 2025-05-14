/*
Mariazinha tem uma lista enorme de exerc ́ıcios sobre m ́ultiplos para concluir, mas devido `a falta de
tempo, ela pediu que vocˆe crie um algoritmo que, ao ler dois n ́umeros inteiros, a e b, determine
automaticamente se eles s ̃ao m ́ultiplos ou n ̃ao.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    printf("digite o primeiro numero: ");
    scanf("%d", &a);
    printf("digite o segundo numero: ");
    scanf("%d",&b);


    if (a % b == 0 || b % a ==0)
    {
        printf("sao multiplos\n");
    }
    else
    {
        printf("nao sao multiplos\n");
    }
return 0;
}