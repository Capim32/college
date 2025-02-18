#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEICULOS 100

typedef struct {
    int id;
    int tipo; // 0 = moto, 1 = carro, 2 = caminhao
    float capacidade;
    int status; // 0 = livre, 1 = ocupado
} Veiculo;

Veiculo frota[MAX_VEICULOS];
int total_veiculos = 0;
int ultimo_id = 0; // variável para armazenar o último ID utilizado

void salvar_veiculos() {
    FILE *arquivo_vei = fopen("veiculos.txt", "w");
    if (arquivo_vei == NULL) {
        printf("Erro ao abrir o arquivo de veículos.\n");
        return;
    }

    for (int i = 0; i < total_veiculos; i++) {
        fprintf(arquivo_vei, "ID: %d|TIPO:%d|CAPACIDADE: %.2f|STATUS: %d\n", frota[i].id, frota[i].tipo, frota[i].capacidade, frota[i].status);
    }

    fclose(arquivo_vei);
}

void carregar_veiculos() {
    FILE *arquivo_vei = fopen("veiculos.txt", "r");
    if (arquivo_vei == NULL) {
        printf("arquivo de veículos não encontrado.\n");
        return;
    }

    while (fscanf(arquivo_vei, "%d|%d|%f|%d\n", &frota[total_veiculos].id, &frota[total_veiculos].tipo, &frota[total_veiculos].capacidade, &frota[total_veiculos].status) != EOF) {
        if (frota[total_veiculos].id > ultimo_id) {
            ultimo_id = frota[total_veiculos].id; // atualiza o último ID (evita o problema de IDs repetidos)
        }
        total_veiculos++;
    }

    fclose(arquivo_vei);
}

void adicionar_veiculo() {
    if (total_veiculos >= MAX_VEICULOS) {
        printf("Limite de veiculos atingido!\n");
        return;
    }

    Veiculo v;
    v.id = ultimo_id + 1; // ID sequencial e único

    printf("Tipo de veículo (0 = moto, 1 = carro, 2 = caminhao): ");
    scanf("%d", &v.tipo);

    printf("Capacidade de carga (em kg): ");
    scanf("%f", &v.capacidade);

    v.status = 0; // veículo livre

    frota[total_veiculos] = v;
    total_veiculos++;
    ultimo_id++;

    salvar_veiculos();
    printf("Veiculo adicionado com sucesso!\n");
}

void visualizar_veiculos() {
    if (total_veiculos == 0) {
        printf("Nenhum veiculo cadastrado.\n");
        return;
    }

    for (int i = 0; i < total_veiculos; i++) {
        printf("----------------------------\n");
        printf("ID: %d\n", frota[i].id);
        printf("Tipo: %d\n", frota[i].tipo);
        printf("Capacidade: %.2f\n", frota[i].capacidade);
        printf("Status: %d\n", frota[i].status);
        printf("----------------------------\n");
    }
}

void editar_veiculo() {
    int id;
    printf("Digite o ID do veiculo que deseja editar: ");
    scanf("%d", &id);

    for (int i = 0; i < total_veiculos; i++) {
        if (frota[i].id == id) {
            printf("Tipo de veiculo (0 = moto, 1 = carro, 2 = caminhao): ");
            scanf("%d", &frota[i].tipo);

            printf("Capacidade de carga (em kg): ");
            scanf("%f", &frota[i].capacidade);

            salvar_veiculos();
            printf("Veiculo editado com sucesso!\n");
            return;
        }
    }

    printf("Veiculo com ID %d nao encontrado.\n", id);
}

void excluir_veiculo() {
    int id;
    printf("Digite o ID do veiculo que deseja excluir: ");
    scanf("%d", &id);

    for (int i = 0; i < total_veiculos; i++) {
        if (frota[i].id == id) {
            for (int j = i; j < total_veiculos - 1; j++) {
                frota[j] = frota[j + 1];
            }
            total_veiculos--;
            salvar_veiculos();
            printf("Veiculo excluido com sucesso!\n");
            return;
        }
    }

    printf("Veiculo com ID %d nao encontrado.\n", id);
}

int main()
{
    carregar_veiculos();

    int opcao;
    do {
        printf("\n=== Gestao de Veiculos ===\n");
        printf("1. Adicionar veiculo\n");
        printf("2. Remover veiculo\n");
        printf("3. Visualizar veiculos\n");
        printf("4. Editar veiculo\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_veiculo();
                break;
            case 2:
                excluir_veiculo();
                break;
            case 3:
                visualizar_veiculos();
                break;
            case 4:
                editar_veiculo();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}