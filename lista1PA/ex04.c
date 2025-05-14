/*
Suzane, a m ́edica do hospital, precisa de um algoritmo que calcule automaticamente o peso ideal para
homens e mulheres, da seguinte forma:
• Para homens: (72.7 * altura) - 58
• Para mulheres: (62.1 * altura) - 44.7
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float altura, pesoIdeal;
    char sexo;

    printf("altura do paciente em metros: ");
    scanf("%f", &altura);
    printf("sexo do paciente (M ou F): ");
    scanf("%c", &sexo);
    scanf("%c", &sexo); // Corrigido para ler o caractere corretamente
    if (sexo == 'M' || sexo =='m')
    {
        pesoIdeal = (72.7 * altura) - 58;
        printf("peso ideal do paciente e %.2f\n",pesoIdeal);
    }
    else if (sexo == 'F' || sexo =='f')
    {
        pesoIdeal = (62.1 * altura) - 44.7;
        printf("peso ideal do paciente e %.2f\n",pesoIdeal);
    }

    else
    printf("sexo invalido\n");

return 0;    
}