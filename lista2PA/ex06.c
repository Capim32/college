#include <stdio.h>

/* ENUNCIADO
6. Roberto deseja adicionar mais uma funcionalidade ao seu programa. Ele possui uma lista de 10 IDs
de filiais. O algoritmo deve fazer o seguinte:
(a) Solicitar ao usu ́ario que insira um ID espec ́ıfico;
(b) Verificar se o ID inserido est ́a presente na lista de IDs das filiais;
(c) Se o ID estiver na lista, o programa deve informar que o ID pertence a uma filial da lista;
(d) Caso contr ́ario, o programa deve informar que o ID digitado n ̃ao corresponde a nenhuma filial da
lista.
*/

int main()
{
    int ID, encontrado = 0, ID_filiais[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;

    printf("digite o ID da filial que deseja encontrar: ");
    scanf("%d",& ID);

    for (i = 0; i < 10; i++)
    {
        if (ID == ID_filiais[i])
        {   
            printf("o ID digitado corresponde a %d filial\n", i + 1);
            encontrado ++; // define que o valor foi encontrado, setando o valor como diferente de zero para ser verdadeiro
        }
        
    }
    // caso o ID nao seja encontrado, o valor sera zero, logo nulo
    if (encontrado == 0)
    {
        printf("o ID digitado nao corresponde a nenhuma filial da lista\n");
    }
    

    return 0;
}