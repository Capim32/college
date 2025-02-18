#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100
#define ARQUIVO "clientes.txt"

typedef struct {
    int id;
    char nome[max];
    char cidade[max];
    char endereco[max];
} Cliente;

// Função para adicionar um novo cliente
void adicionar_cliente() {
    FILE *arquivo = fopen(ARQUIVO, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Cliente cliente;
    int id_atual = 0; 

    cliente.id = id_atual++;
    printf("Digite o nome do cliente: ");
    fgets(cliente.nome, max, stdin);
    cliente.nome[strcspn(cliente.nome, "\n")] = '\0';  // strcpsn Remove o \n do final

    printf("Digite a cidade do cliente: ");
    fgets(cliente.cidade, max, stdin);
    cliente.cidade[strcspn(cliente.cidade, "\n")] = '\0';

    printf("Digite o endereco do cliente: ");
    fgets(cliente.endereco, max, stdin);
    cliente.endereco[strcspn(cliente.endereco, "\n")] = '\0';

    
    fclose(arquivo);
    printf("Cliente adicionado com sucesso! ID: %d\n", cliente.id);
    fprintf(arquivo, "ID:%d\nNOME:%s\nCIDADE:%s\nENDERECO:%s\n", cliente.id, cliente.nome, cliente.cidade, cliente.endereco);
}

// Função para listar todos os clientes
void listar_clientes() {
    FILE *arquivo = fopen(ARQUIVO, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Cliente cliente;
    printf("\nLista de Clientes:\n");
    while (fscanf(arquivo, "%d;%99[^;];%49[^;];%199[^\n]\n", &cliente.id, cliente.nome, cliente.cidade, cliente.endereco) != EOF) 
    {
        printf("ID: %d\n", cliente.id);
        printf("Nome: %s\n", cliente.nome);
        printf("Cidade: %s\n", cliente.cidade);
        printf("Endereco: %s\n\n", cliente.endereco);
    }

    fclose(arquivo);
}

// Função para editar um cliente com base no ID
void editar_cliente() {
    int id_procurado;
    printf("Digite o ID do cliente para editar: ");
    scanf("%d", &id_procurado);
    getchar(); // Consumir o '\n' restante no buffer de entrada

    FILE *arquivo = fopen(ARQUIVO, "r+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Cliente cliente;
    int encontrado = 0;
    while (fscanf(arquivo, "%d;%99[^;];%49[^;];%199[^\n]\n", &cliente.id, cliente.nome, cliente.cidade, cliente.endereco) != EOF) {
        if (cliente.id == id_procurado) {
            encontrado = 1;
            printf("Cliente encontrado! Digite os novos dados.\n");
            printf("Nome: ");
            fgets(cliente.nome, max, stdin);
            cliente.nome[strcspn(cliente.nome, "\n")] = '\0';

            printf("Cidade: ");
            fgets(cliente.cidade, max, stdin);
            cliente.cidade[strcspn(cliente.cidade, "\n")] = '\0';

            printf("Endereco: ");
            fgets(cliente.endereco, max, stdin);
            cliente.endereco[strcspn(cliente.endereco, "\n")] = '\0';

            fseek(arquivo, -((long)sizeof(cliente)), SEEK_CUR);  // Voltar para o ponto anterior
            fprintf(arquivo, "%d;%s;%s;%s\n", cliente.id, cliente.nome, cliente.cidade, cliente.endereco);
            printf("Cliente editado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente com ID %d nao encontrado.\n", id_procurado);
    }

    fclose(arquivo);
}

// Função para excluir um cliente baseado no ID
void excluir_cliente() {
    int id_procurado;
    printf("Digite o ID do cliente para excluir: ");
    scanf("%d", &id_procurado);
    getchar(); // Consumir o '\n' restante no buffer de entrada

    FILE *arquivo = fopen(ARQUIVO, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Cliente cliente;
    int encontrado = 0;
    while (fscanf(arquivo, "%d;%99[^;];%49[^;];%199[^\n]\n", &cliente.id, cliente.nome, cliente.cidade, cliente.endereco) != EOF) {
        if (cliente.id == id_procurado) {
            encontrado = 1;
            printf("Cliente com ID %d excluido com sucesso!\n", cliente.id);
        } else {
            fprintf(temp, "%d;%s;%s;%s\n", cliente.id, cliente.nome, cliente.cidade, cliente.endereco);
        }
    }

    if (!encontrado) {
        printf("Cliente com ID %d nao encontrado.\n", id_procurado);
    }

    fclose(arquivo);
    fclose(temp);

    // Substituir o arquivo original pelo arquivo temporário
    remove(ARQUIVO);
    rename("temp.txt", ARQUIVO);
}

int main() {
    int escolha;
    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Cliente\n");
        printf("2. Listar Clientes\n");
        printf("3. Editar Cliente\n");
        printf("4. Excluir Cliente\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        getchar(); // Consumir o '\n' restante no buffer de entrada

        switch (escolha) {
            case 1:
                adicionar_cliente();
                break;
            case 2:
                listar_clientes();
                break;
            case 3:
                editar_cliente();
                break;
            case 4:
                excluir_cliente();
                break;
            case 5:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (escolha != 5);

    return 0;
}