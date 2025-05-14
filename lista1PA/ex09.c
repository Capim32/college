#include <stdio.h>
#include <stdlib.h>
/*
9. Jos ́e precisa de uma  ́ultima ajuda em seu sistema escolar. Dados trˆes n ́umeros de matr ́ıcula diferentes,
ele precisa de um programa que compare esses n ́umeros e determine, e por fim, imprima:

• O menor n ́umero entre eles;
• O maior n ́umero entre eles.
*/

int main()
{
    int n1,n2,n3;

    printf("digite a primeira matricula: ");
    scanf("%d",&n1);
    printf("digite a segunda matricula: ");
    scanf("%d",&n2);
    printf("digite a terceira matricula: ");
    scanf("%d",&n3);

    if (n1 % 2 == 0)
    {
        printf("a primeira matricula e par\n");
    }

    if (n2 % 2 == 0) // se o else if fosse usado, ele so continuaria se n1 nao fosse par
    {
        printf("a segunda matricula e par\n");
    }

    if (n3 % 2 == 0)
    {
        printf("a terceiira matricula e par\n");
    }

    if (n1 > n2 && n1 > n3)
    {
        printf("%d e o maior numero",n1);
    }

    else if(n2 > n1 && n2 > n3)
    {
        printf("%d e o maior numero",n2);
    }

    else
    printf("%d e o maior numero",n3);

    
return 0;    
}