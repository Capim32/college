#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEICULOS 100

typedef struct {
    int id;
    char tipo[20];
    float capacidade;
    char status[10];
} Veiculo;

Veiculo frota[MAX_VEICULOS];
int total_veiculos = 0;

void adicionarVeiculo() {
    if (total_veiculos >= MAX_VEICULOS) {
        printf("Limite de veiculos atingido!\n");
        return;
    }
    
    Veiculo v;
    printf("ID do veiculo: ");
    scanf("%d", &v.id);
    printf("Tipo do veiculo: ");
    scanf("%s", v.tipo);
    printf("Capacidade de carga (kg): ");
    scanf("%f", &v.capacidade);
    printf("Status (Livre/Ocupado): ");
    scanf("%s", v.status);
    
    frota[total_veiculos++] = v;
    printf("Veiculo adicionado com sucesso!\n");
}

void removerVeiculo() {
    int id, i, encontrado = 0;
    printf("Digite o ID do veiculo a ser removido: ");
    scanf("%d", &id);
    
    for (i = 0; i < total_veiculos; i++) {
        if (frota[i].id == id) {
            encontrado = 1;
            for (int j = i; j < total_veiculos - 1; j++) {
                frota[j] = frota[j + 1];
            }
            total_veiculos--;
            printf("Veiculo removido com sucesso!\n");
            break;
        }
    }
    
    if (!encontrado) {
        printf("Veiculo nao encontrado!\n");
    }
}

void listarVeiculos() {
    if (total_veiculos == 0) {
        printf("Nenhum veiculo cadastrado.\n");
        return;
    }
    
    printf("\nLista de veiculos:\n");
    for (int i = 0; i < total_veiculos; i++) {
        printf("ID: %d | Tipo: %s | Capacidade: %.2f kg | Status: %s\n", 
               frota[i].id, frota[i].tipo, frota[i].capacidade, frota[i].status);
    }
}

int main() {
    int opcao;
    
    do {
        printf("\n=== Gestao de Veiculos ===\n");
        printf("1. Adicionar veiculo\n");
        printf("2. Remover veiculo\n");
        printf("3. Listar veiculos\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                adicionarVeiculo();
                break;
            case 2:
                removerVeiculo();
                break;
            case 3:
                listarVeiculos();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);
    
    return 0;
}