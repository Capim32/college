#include <stdio.h>
#include <stdlib.h>
/*
10. Elize  ́e dona de um restaurante e est ́a enfrentando um problema com o termostato de seu freezer, que
possui apenas uma configura ̧c ̃ao em graus Celsius. No entanto, todo o seu estoque de mantimentos
est ́a etiquetado com uma temperatura recomendada em Fahrenheit, e fazer a convers ̃ao a cada vez que
ela vai armazenar um novo item,  ́e bastante trabalhoso. Portanto, ela precisa de um algoritmo que,
dada uma temperatura em Fahrenheit, diga seu equivalente em Celsius. Observe que a convers ̃ao de
graus Fahrenheit para Celsius  ́e obtida por C = (5/9)(F - 32).
*/

int main()
{
    float f,c;

    printf("digite a temperatura em fahrenheit que deseja converter para celcius: ");
    scanf("%f", &f);

    c = (f-32)*5/9;

    printf("a temperatura em celcius e %.2f",c);

return 0;    
}