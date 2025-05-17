/*EXEMPLO INTERNET
#include <stdio.h>

int main()
{
    int i;
    int j;
    int valor[10];
    int contador;

    for(i=0; i<10; i++)
    {
        printf("Digite um valor: ");
        scanf("%d",&valor[i]);
    }
    for(i=0; i<10; i++)
    {
        for(j=i+1; j<10; j++)
        {
            if(valor[i]>valor[j])
            { 
                contador=valor[i];
                valor[i]=valor[j];
                valor[j]=contador;
            }
        }
    }

    printf("\n");
    for(i=0; i<10; i++)
    {
        printf("%d\n",valor[i]);
    }
    return 0;
}
*/

#include <stdio.h>
#define tamanho_vetor 5

int main()
{
    int vet[tamanho_vetor];
    int i, aux, contador;

    // pega os numeros dados aos indices do array
    for (i=0; i<tamanho_vetor; i++)
    {
        printf("digite o %d numero:",i+1);
        scanf("%d",&vet[i]);
    }

    // escreve o array
    printf("elementos do array desordenados: \n");
    for (i=0; i < tamanho_vetor; i++)
    {
        printf("|%d|",vet[i]);
    }
    printf("\n");

    // algoritmo de ordenação bubble sort
    for (contador = 1; contador < tamanho_vetor; contador++)
    {
        for (i=0; i < tamanho_vetor; i++)
        {
            if (vet[i] > vet[i+1])
            {
                // algoritmo de troca 
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
            }
        }
    }

    printf("elementos do array em ordem crescente: \n ");

    for (i=0; i< tamanho_vetor; i++)
    {
        printf("|%d|",vet[i]);
    }
    printf("\n");
    
return 0;
}