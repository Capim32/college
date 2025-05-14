#include <stdio.h>
#include <stdlib.h>

/*

2. Jos ́e ainda precisa de ajuda em mais duas partes de seu sistema:

• Ele precisa de um algoritmo que leia as trˆes notas de um aluno e calcule sua m ́edia final, conside-
rando que  ́e uma m ́edia ponderada com pesos de 2, 3 e 5, respectivamente;

• Al ́em disso, ele deseja que o algoritmo exiba a mensagem ”Aprovado”, caso essa m ́edia seja maior
que 7, ou ”Reprovado”, caso contr ́ario.

*/



int main()
{
    float n1, n2, n3, media;
    printf("n1: ");
    scanf("%f", &n1);
    printf("n2: ");
    scanf("%f", &n2);
    printf("n3: ");
    scanf("%f", &n3);
    media = (n1*2 + n2*3 + n3*5) / (2+3+5);
    
    printf("a media do aluno e %.2f \n", media);
    
    if (media >=7)
    {
        printf("aprovado \n");
    }

    if (media <7 && media >=4)
    {
        printf("NEF \n");
    }
    if(media<4)
    {
        printf("reprovado \n");
    }

return 0;
}    