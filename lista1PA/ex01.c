#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int d,m,a;
    printf("O programa escreve sua idade dada em dias, meses e anos em dias! \n");
    printf("digite o dia em que voce nasceu \n");
    scanf("%d", &d);
    printf("digite o mes em que voce nasceu \n");
    scanf("%d", &m);
    printf("digite o ano em que voce nasceu \n");
    scanf("%d",&a);
    printf("voce nasceu no dia %d/%d/%d \n", d,m,a);
    printf("essa data em dias e: %d \n", (a*365)+(m*30)+d);
    return 0;
}