#include <stdio.h>
#include <stdlib.h>


/*
5. Fabio est ́a tendo aulas em rela ̧c ̃ao `as propriedades de triˆangulos, mas precisa de uma forma de checar
se os c ́alculos feitos em seus exerc ́ıcios est ̃ao corretos. Fabio precisa, portanto, de um algoritmo para
verificar se trˆes comprimentos de segmentos positivos formam um triˆangulo. Se formarem um triˆangulo,
o algoritmo deve realizar o seguinte:
• Calcular e mostrar a  ́area do triˆangulo;
• Determinar e informar se o triˆangulo  ́e equil ́atero, is ́osceles ou escaleno, com base nos lados
fornecidos.
*/


int main()
{
    float l1,l2,l3;

    printf("digite em cm o tamanho do primeiro lado: ");
    scanf("%f",&l1);
    printf("digite em cm o tamanho do segundo lado: ");
    scanf("%f",&l2);
    printf("digite em cm o tamanho do terceiro lado: ");
    scanf("%f",&l3);
    if(l1 + l2 >l3 || l1 + l3 > l2 || l2 + l3 > l1 )
    {
        printf("o triangulo e valido\n");

    }
    if(l1 == l2 && l1 == l3 && l2 == l3 )
    {
        printf("o triangulo e equilatero");
    }

    else if (l1 != l2 && l1 != l3 && l2 !=l3)
    {
        printf("o triangulo e escaleno");
    }
    else
    printf("o triangulo e isoceles");



return 0;
}