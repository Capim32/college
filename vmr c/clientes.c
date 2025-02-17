#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 100
#define TAM_NOME 100
#define TAM_ENDERECO 200
#define TAM_SERVICO 20

typedef struct {
    int id;
    char nome[TAM_NOME];
    char endereco[TAM_ENDERECO];
    char tipo_servico[TAM_SERVICO];
} Cliente;

Cliente clientes[MAX_CLIENTES];
int total_clientes = 0;
int ultimo_id = 0; // variável para armazenar o último ID utilizado (era tão simples...)

void salvar_clientes() {
    FILE *arquivo = fopen("clientes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < total_clientes; i++) {
        fprintf(arquivo, "|ID: %d |NOME: %s |ENDERECO: %s |SERVICO: %s|\n", clientes[i].id, clientes[i].nome, clientes[i].endereco, clientes[i].tipo_servico);
    }

    fclose(arquivo);
}

void carregar_clientes() {
    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de clientes nao encontrado.\n");
        return;
    }

    while (fscanf(arquivo, "%d|%[^|]|%[^|]|%[^\n]\n", &clientes[total_clientes].id, clientes[total_clientes].nome, clientes[total_clientes].endereco, clientes[total_clientes].tipo_servico) != EOF) {
        if (clientes[total_clientes].id > ultimo_id) {
            ultimo_id = clientes[total_clientes].id; // atualiza o último ID (evita o problema de IDs repetidos)
        }
        total_clientes++;
    }

    fclose(arquivo);
}

void adicionar_cliente() {
    if (total_clientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido.\n");
        return;
    }

    Cliente novo_cliente;
    novo_cliente.id = ultimo_id + 1; // atribui o próximo ID
    ultimo_id = novo_cliente.id; // atualiza o último ID

    printf("Nome completo: ");
    getchar(); // limpa o buffer do teclado (não sei direito o que isso faz, mas é necessário pro fgets funcionar corretamente)
    fgets(novo_cliente.nome, TAM_NOME, stdin);
    novo_cliente.nome[strcspn(novo_cliente.nome, "\n")] = 0; // Remove a nova linha

    printf("Endereco completo: ");
    fgets(novo_cliente.endereco, TAM_ENDERECO, stdin);
    novo_cliente.endereco[strcspn(novo_cliente.endereco, "\n")] = 0;

    printf("Tipo de servico (economico, padrao, premium): ");
    fgets(novo_cliente.tipo_servico, TAM_SERVICO, stdin);
    novo_cliente.tipo_servico[strcspn(novo_cliente.tipo_servico, "\n")] = 0;

    clientes[total_clientes] = novo_cliente;
    total_clientes++;

    salvar_clientes();
    printf("Cliente adicionado com sucesso! ID: %d\n", novo_cliente.id);
}

void visualizar_clientes() {
    if (total_clientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    for (int i = 0; i < total_clientes; i++) { // alterei o nome da variável numClientes para total_clientes
        printf("----------------------------\n");
        printf("ID: %d\n", clientes[i].id);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Endereco: %s\n", clientes[i].endereco);
        printf("Tipo de servico: %s\n", clientes[i].tipo_servico);
        printf("----------------------------\n");
    }
}

void editar_cliente() {
    int id;
    printf("Digite o ID do cliente que deseja editar: ");
    scanf("%d", &id);

    for (int i = 0; i < total_clientes; i++) {
        if (clientes[i].id == id) {
            printf("Nome (atual: %s): ", clientes[i].nome);
            getchar();
            fgets(clientes[i].nome, TAM_NOME, stdin);
            clientes[i].nome[strcspn(clientes[i].nome, "\n")] = 0;

            printf("Endereco (atual: %s): ", clientes[i].endereco);
            fgets(clientes[i].endereco, TAM_ENDERECO, stdin);
            clientes[i].endereco[strcspn(clientes[i].endereco, "\n")] = 0;

            printf("Tipo de servico (atual: %s): ", clientes[i].tipo_servico);
            fgets(clientes[i].tipo_servico, TAM_SERVICO, stdin);
            clientes[i].tipo_servico[strcspn(clientes[i].tipo_servico, "\n")] = 0;

            salvar_clientes();
            printf("Cliente editado com sucesso!\n");
            return;
        }
    }

    printf("Cliente com ID %d nao encontrado.\n", id);
}

void excluir_cliente() {
    int id;
    printf("Digite o ID do cliente que deseja excluir: ");
    scanf("%d", &id);

    for (int i = 0; i < total_clientes; i++) {
        if (clientes[i].id == id) {
            for (int j = i; j < total_clientes - 1; j++) {
                clientes[j] = clientes[j + 1];
            }
            total_clientes--;
            salvar_clientes();
            printf("Cliente excluido com sucesso!\n");
            return;
        }
    }

    printf("Cliente com ID %d nao encontrado.\n", id);
}

int main() {
    carregar_clientes();

    int opcao;
    do {
        printf("\n==Sistema de Gestao de Correios==\n");
        printf("=== Menu de Clientes ===\n");
        printf("1. Adicionar Cliente\n");
        printf("2. Visualizar Clientes\n");
        printf("3. Editar Cliente\n");
        printf("4. Excluir Cliente\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_cliente();
                break;
            case 2:
                visualizar_clientes();
                break;
            case 3:
                editar_cliente();
                break;
            case 4:
                excluir_cliente();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
