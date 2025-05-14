#include <stdio.h>
#include <stdlib.h>
/*
6. J ́ulio  ́e dono de um local de armazenamento de materiais, e acabou de ter um problema com o espa ̧co e
a quantidade de caixas recebidas. Determinado a n ̃ao passar pela mesma situa ̧c ̃ao, ele contratou vocˆe
para criar um algoritmo que, lendo a altura, a largura e o comprimento de uma caixa, diga o volume
da mesma. Se atente que a f ́ormula de volume  ́e Altura × Largura × Comprimento.
*/

int main()
{
    float alt,larg,comp,vol;

    printf("digite a altura da caixa em m: ");
    scanf("%f",&alt);
    printf("digite a largura da caixa em m: ");
    scanf("%f",&larg);
    printf("digite o comprimento da caixa em m: ");
    scanf("%f",&comp);

    vol = alt * larg * comp;

    printf("o volume da caixa e: %.2f",vol);


return 0;    
}