#include <stdio.h>
#include <stdlib.h>

//Calcular o volume de uma esfera (V =4/3 πr¨3)
int main()
{
    const float pi = 3.1415;
    float vol,raio;

    printf("digite o raio da esfera cujo qual deseja calcular o volume: ");
    scanf("%f", & raio);

    vol = (4/3) * pi * pow(raio, 3);
    printf("o volume da esfera e: %.2f",vol);

return 0;
}

